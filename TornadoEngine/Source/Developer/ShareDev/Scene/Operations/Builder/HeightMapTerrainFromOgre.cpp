/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "HeightMapTerrainFromOgre.h"
#include "ContainerTypes.h"
#include "BL_Debug.h"
#include "ShareMisc.h"
#include "LoadFromFile.h"

#include <OgreTerrainQuadTreeNode.h>
#include <OgreTerrainMaterialGeneratorA.h>
#include <OgreResourceGroupManager.h>
#include <OgreStreamSerialiser.h>
#include <OgreFileSystem.h>

namespace nsHeightMapTerrainFromOgre
{
	const char* sParameters  = "TGIN";
	const char* sHeightDelta = "TLDA";
	const char* sID_Terrain  = "TERR";
}

using namespace nsHeightMapTerrainFromOgre;

THeightMapTerrainFromOgre::THeightMapTerrainFromOgre()
{
	TERRAIN_CHUNK_ID = Ogre::StreamSerialiser::makeIdentifier(sID_Terrain);
	TERRAIN_CHUNK_VERSION = 2;
	TERRAINGENERALINFO_CHUNK_ID = Ogre::StreamSerialiser::makeIdentifier(sParameters);
	TERRAINGENERALINFO_CHUNK_VERSION = 1;
	TERRAINLODDATA_CHUNK_ID = Ogre::StreamSerialiser::makeIdentifier(sHeightDelta);
	TERRAINLODDATA_CHUNK_VERSION = 1;

	mHighestLodPrepared = -1;
	mHighestLodLoaded   = -1;
	mDataStream.setNull();
}
//---------------------------------------------------------------------
THeightMapTerrainFromOgre::~THeightMapTerrainFromOgre()
{
	Done();
}
//---------------------------------------------------------------------
void THeightMapTerrainFromOgre::Done()
{
	delete mDataStream.get();
	mDataStream.setNull();
}
//---------------------------------------------------------------------
bool THeightMapTerrainFromOgre::Setup(std::string& filename, 
	nsStructPattern_Terrain::THeightMapTerrain* pHMT)
{
	mFileName = filename;

	Done();
	RET_FALSE(Prepare())

  PrepareForBullet(mTerrainProperty.mHeightData, mTerrainProperty.mSize);

	pHMT->pos.x     = mTerrainProperty.mPos.x;
	pHMT->pos.y     = mTerrainProperty.mPos.y;
	pHMT->pos.z     = mTerrainProperty.mPos.z;
	pHMT->worldSize = mTerrainProperty.mWorldSize;
	pHMT->size      = mTerrainProperty.mSize;
	pHMT->cHeight.EntrustByCount( (char*)mTerrainProperty.mHeightData, pHMT->size*pHMT->size);
	mTerrainProperty.mHeightData = NULL;
	return true;
}
//---------------------------------------------------------------------
bool THeightMapTerrainFromOgre::Prepare()
{
	TLoadFromFile loaderCheckSizeFile;
	RET_FALSE(loaderCheckSizeFile.ReOpen((char*)mFileName.data()))
	size_t sizeFile =	(size_t)loaderCheckSizeFile.Size();
	loaderCheckSizeFile.Close();

	std::ios::openmode mode = std::ios::in | std::ios::binary;
	std::ifstream* roStream = OGRE_NEW_T(std::ifstream,Ogre::MEMCATEGORY_GENERAL);
	roStream->open(mFileName.data(), mode);

	mDataStream =(Ogre::DataStreamPtr)
		new Ogre::FileStreamDataStream(mFileName,	roStream, sizeFile, true);

	Ogre::StreamSerialiser stream(mDataStream);
	const Ogre::StreamSerialiser::Chunk *mainChunk = stream.readChunkBegin(TERRAIN_CHUNK_ID, TERRAIN_CHUNK_VERSION);
	if( !mainChunk )
		return false;

	if( mainChunk->version > 1 )
		stream.readChunkBegin(TERRAINGENERALINFO_CHUNK_ID, TERRAINGENERALINFO_CHUNK_VERSION);

	stream.read(&mTerrainProperty.mAlign);
	stream.read(&mTerrainProperty.mSize);
	stream.read(&mTerrainProperty.mWorldSize);

	stream.read(&mTerrainProperty.mMaxBatchSize);
	stream.read(&mTerrainProperty.mMinBatchSize);
	stream.read(&mTerrainProperty.mPos);

	mTerrainProperty.determineLodLevels();

	if( mainChunk->version > 1 )
		stream.readChunkEnd(TERRAINGENERALINFO_CHUNK_ID);

	size_t numVertices = mTerrainProperty.mSize * mTerrainProperty.mSize;
	mTerrainProperty.mHeightData = new float[numVertices];
	//mTerrainProperty.mDeltaData  = new float[numVertices];

	memset(mTerrainProperty.mHeightData, 0, sizeof(float)*numVertices);
	//memset(mTerrainProperty.mDeltaData,  0, sizeof(float)*numVertices);
	if( mainChunk->version > 1 )// есть ли компрессия?
	{
		for( int i = 0; i < mTerrainProperty.mNumLodLevels; i++ )
		{
			stream.readChunkBegin(TERRAINLODDATA_CHUNK_ID, TERRAINLODDATA_CHUNK_VERSION);
			stream.readChunkEnd(TERRAINLODDATA_CHUNK_ID);
		}
		// start uncompressing
		stream.startDeflate( mainChunk->length - stream.getOffsetFromChunkStart() );
		// stop uncompressing
		stream.stopDeflate();
	}
	else
	{
		stream.read(mTerrainProperty.mHeightData, numVertices);
	}
	stream.readChunkEnd(TERRAIN_CHUNK_ID);

	if( mHighestLodPrepared==-1 )
		mHighestLodPrepared = mTerrainProperty.mNumLodLevels;
	if( mHighestLodLoaded==-1 )
		mHighestLodLoaded = mTerrainProperty.mNumLodLevels;

	int lodLevel = 0;
	mTargetLodLevel = mTerrainProperty.getPositiveLodLevel(lodLevel);
	readLodData(mHighestLodPrepared-1, mTargetLodLevel);
	return true;
}
//---------------------------------------------------------------------
void THeightMapTerrainFromOgre::readLodData(unsigned short lowerLodBound, unsigned short higherLodBound)
{
	size_t mStreamOffset = 0;
	unsigned short numLodLevels = mTerrainProperty.mNumLodLevels;
	mDataStream->seek(mStreamOffset);
	Ogre::StreamSerialiser stream(mDataStream);

	const Ogre::StreamSerialiser::Chunk *mainChunk = 
		stream.readChunkBegin(TERRAIN_CHUNK_ID, TERRAIN_CHUNK_VERSION);

	if( mainChunk->version > 1 )
	{
		// skip the general information
		stream.readChunkBegin(TERRAINGENERALINFO_CHUNK_ID, TERRAINGENERALINFO_CHUNK_VERSION);
		stream.readChunkEnd(TERRAINGENERALINFO_CHUNK_ID);

		// skip the previous lod data
		for( int skip = numLodLevels - 1 - lowerLodBound ; skip > 0 ; skip-- )
		{
			stream.readChunkBegin(TERRAINLODDATA_CHUNK_ID, TERRAINLODDATA_CHUNK_VERSION);
			stream.readChunkEnd(TERRAINLODDATA_CHUNK_ID);
		}

		// uncompress
		unsigned int maxSize = 2 * mTerrainProperty.getGeoDataSizeAtLod(higherLodBound);
		float* lodData = new float[maxSize];

		for( int level = lowerLodBound; level >= higherLodBound ; level-- )
		{
			// both height data// and delta data
			unsigned int dataSize = /*2 * */mTerrainProperty.getGeoDataSizeAtLod(level);

			// reach and read the target lod data
			const Ogre::StreamSerialiser::Chunk *c = stream.readChunkBegin(TERRAINLODDATA_CHUNK_ID,
				TERRAINLODDATA_CHUNK_VERSION);
			stream.startDeflate(c->length);
			stream.read(lodData, dataSize);
			stream.stopDeflate();
			stream.readChunkEnd(TERRAINLODDATA_CHUNK_ID);

			fillBufferAtLod(level, lodData, dataSize);
		}
		stream.readChunkEnd(TERRAIN_CHUNK_ID);
		delete[]lodData;
	}
}
//---------------------------------------------------------------------
void THeightMapTerrainFromOgre::fillBufferAtLod(unsigned int lodLevel, const float* data, unsigned int dataSize )
{
	unsigned int inc = 1 << lodLevel;
	unsigned int prev = 1 << (lodLevel + 1);
	unsigned short numLodLevels = mTerrainProperty.mNumLodLevels;
	unsigned short size = mTerrainProperty.mSize;

	const float* heightDataPtr = data;
	//const float* deltaDataPtr = data+dataSize/2;
	for( unsigned short y = 0; y < size; y += inc )
	{
		for( unsigned short x = 0; x < size-1; x += inc)
		{
			if( (lodLevel == numLodLevels - static_cast<unsigned int>(1)) || (x % prev) || (y % prev))
			{
				mTerrainProperty.mHeightData[y*size + x] = *(heightDataPtr++);
				//mTerrainProperty.mDeltaData[y*size + x] = *(deltaDataPtr++);
			}
		}
		if( (lodLevel == numLodLevels - static_cast<unsigned int>(1)) || (y % prev))
		{
			mTerrainProperty.mHeightData[y*size + size-1] = *(heightDataPtr++);
			//mTerrainProperty.mDeltaData[y*size + size-1] = *(deltaDataPtr++);
		}
		if( y+inc > size )
			break;
	}
}
//---------------------------------------------------------------------
// первая линия [0..mTerrainProperty.mSize]
// и последняя  [cnt - mTerrainProperty.mSize - 1..cnt-1],
// где cnt = mTerrainProperty.mSize*mTerrainProperty.mSize
// и так далее в направлении середины
void THeightMapTerrainFromOgre::PrepareForBullet(float* pData, int extent)
{
	int cnt = extent*extent;
	int cntRow = extent/2;// 2/2 = 1, 3/2 = 1
	for( int iRow = 0 ; iRow < cntRow ; iRow++ )
	{
		for( int i = 0 ; i < extent ; i++ )
		{
			int indexBegin = iRow*extent + i;
			int indexEnd   = cnt - (iRow+1)*extent + i;
			float temp = pData[indexBegin];
			pData[indexBegin] = pData[indexEnd];
			pData[indexEnd]   = temp;
		}
	}
}
//---------------------------------------------------------------------
unsigned int THeightMapTerrainFromOgre::TTerrainProperty::getGeoDataSizeAtLod(unsigned short lodLevel) const
{
	unsigned int size = getResolutionAtLod(lodLevel);
	unsigned int prevSize = (lodLevel<mNumLodLevels-1) ? getResolutionAtLod(lodLevel+1) : 0;
	return size*size - prevSize*prevSize;
}
//---------------------------------------------------------------------
unsigned short THeightMapTerrainFromOgre::TTerrainProperty::getResolutionAtLod(unsigned short lodLevel) const
{
	return ((mSize - 1) >> lodLevel) + 1;
}
//---------------------------------------------------------------------
int THeightMapTerrainFromOgre::TTerrainProperty::getPositiveLodLevel( int lodLevel ) const
{
	return (lodLevel>=0) ? lodLevel : mNumLodLevels+lodLevel;
}
//---------------------------------------------------------------------
THeightMapTerrainFromOgre::TTerrainProperty::TTerrainProperty()
{
	mAlign     		= 0;
	mSize      		= 0;	mWorldSize 		= 0;	mMaxBatchSize = 0;	mMinBatchSize = 0;	mPos          = Ogre::Vector3(0,0,0);
}
//---------------------------------------------------------------------
void THeightMapTerrainFromOgre::TTerrainProperty::determineLodLevels()
{
	mNumLodLevelsPerLeafNode = (unsigned short)(Ogre::Math::Log2(mMaxBatchSize - 1.0f) - Ogre::Math::Log2(mMinBatchSize - 1.0f) + 1.0f);
	mNumLodLevels =         	 (unsigned short)(Ogre::Math::Log2(mSize - 1.0f) - Ogre::Math::Log2(mMinBatchSize - 1.0f) + 1.0f);
	mTreeDepth    = mNumLodLevels - mNumLodLevelsPerLeafNode + 1;
}
//---------------------------------------------------------------------
