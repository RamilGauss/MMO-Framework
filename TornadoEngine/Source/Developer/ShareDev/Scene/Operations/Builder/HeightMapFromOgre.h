/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef HeightMapFromOgreH
#define HeightMapFromOgreH

#include "TypeDef.h"
#include <OgreVector3.h>
#include <OgreDataStream.h>
#include "ContainerArrObj.h"
#include "MathTools.h"

#if defined( WIN32 )
#pragma pack(push, 1)
#endif

class DllExport THeightMapFromOgre
{
	Ogre::DataStreamPtr mDataStream;

	unsigned int   TERRAIN_CHUNK_ID;
	unsigned short TERRAIN_CHUNK_VERSION;
	unsigned int   TERRAINGENERALINFO_CHUNK_ID;
	unsigned short TERRAINGENERALINFO_CHUNK_VERSION;

	unsigned int   TERRAINLODDATA_CHUNK_ID;
	unsigned short TERRAINLODDATA_CHUNK_VERSION;

	int mTargetLodLevel;    // Which LOD level is demanded
	int mHighestLodPrepared;// Highest LOD level stored in memory i.e. mHeightData/mDeltaData
	int mHighestLodLoaded;  // Highest LOD level loaded in GPU

	std::string mFileName;

	struct TTerrainProperty
	{
		TTerrainProperty();
		void determineLodLevels();
		unsigned int getGeoDataSizeAtLod(unsigned short lodLevel) const;
		unsigned short getResolutionAtLod(unsigned short lodLevel) const;
		int getPositiveLodLevel( int lodLevel ) const;

		unsigned char  mAlign;
		unsigned short mSize;
		Ogre::Real     mWorldSize;
		unsigned short mMaxBatchSize;
		unsigned short mMinBatchSize;
		Ogre::Vector3  mPos;

		unsigned short mNumLodLevels;
		unsigned short mNumLodLevelsPerLeafNode;
		unsigned short mTreeDepth;

		float* mHeightData;
		//float* mDeltaData;
	}_PACKED;
public:
	THeightMapFromOgre();
	~THeightMapFromOgre();

	struct TDataOut
	{
		TContainerArrObj<float> cHeight;
		unsigned short size;
		float worldSize;
		float inputScale;
		float inputBias;
		nsMathTools::TVector3 pos;
	}_PACKED;
	bool Setup(std::string& pathFile, TDataOut& data);
protected:
	void readLodData(unsigned short lowerLodBound, unsigned short higherLodBound);
	void fillBufferAtLod(unsigned int lodLevel, const float* data, unsigned int dataSize );
	bool Prepare();
	void Done();
protected:
	TTerrainProperty mTerrainProperty;
};

#if defined( WIN32 )
#pragma pack(pop)
#endif

#endif
