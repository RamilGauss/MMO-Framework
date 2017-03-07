/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "BuilderTerrain_Ogre.h"
#include "TerrainItem.h"
#include "ModuleLogic.h"
#include "GraphicEngine_Ogre_MyGUI.h"
#include "ModuleGraphicEngine.h"

#include <OgreTerrainQuadTreeNode.h>
#include <OgreTerrainMaterialGeneratorA.h>
#include <OgreResourceGroupManager.h>
#include <OgreStreamSerialiser.h>

//---------------------------------------------------------------------
TBuilderTerrain_Ogre::TBuilderTerrain_Ogre()
{
	mRoot     = NULL;
	mSceneMgr = NULL;
	mWindow   = NULL;

	mTerrainGroup     = NULL;
	mTerrainGlobals   = NULL;
	mTerrainsImported = false;

	std::string s = "";
	TTerrainItem tItem(s);
	//tItem.mGraphic[0].
}
//--------------------------------------------------------------------
TBuilderTerrain_Ogre::~TBuilderTerrain_Ogre()
{

}
//--------------------------------------------------------------------
void TBuilderTerrain_Ogre::Show()
{
	mRoot     = TModuleLogic::Get()->GetC()->pGraphicEngine->GetGE()->GetRoot();
	mSceneMgr = TModuleLogic::Get()->GetC()->pGraphicEngine->GetGE()->GetSceneManager();
	mWindow   = TModuleLogic::Get()->GetC()->pGraphicEngine->GetGE()->GetWindow();

	Ogre::ColourValue fadeColour(0.8f, 0.8f, 0.8f);
	mSceneMgr->setFog(Ogre::FOG_LINEAR, fadeColour, 0.0, 4000, 10000);
	mWindow->getViewport(0)->setBackgroundColour(fadeColour);

	Ogre::Plane plane;
	plane.d = 1000;
	plane.normal = Ogre::Vector3::NEGATIVE_UNIT_Y;

	mSceneMgr->setSkyPlane(true, plane, "Examples/CloudySky", 500, 20, true, 0.5, 150, 150);

	Init();
	//SetupShadow();
	//mTerrainGroup->saveAllTerrains(true);

	// достать карту высот для физики TODO оформить в виде класса
	//AnalizHeightMap();
}
//--------------------------------------------------------------------
void TBuilderTerrain_Ogre::Init()
{
	// Terrain
	mTerrainGlobals = TModuleLogic::Get()->GetC()->pGraphicEngine->GetGE()->GetTerrainGlobals();
  mTerrainGroup   = TModuleLogic::Get()->GetC()->pGraphicEngine->GetGE()->GetTerrainGroup();

	mTerrainGroup->setTerrainSize(129);//513
	mTerrainGroup->setTerrainWorldSize(1000.0);//12000

	Ogre::String prefixterrainPath = TModuleLogic::Get()->GetC()->pGraphicEngine->GetGE()->GetTerrainLightMapPath();
	prefixterrainPath += "/mapFlat";
	mTerrainGroup->setFilenameConvention(prefixterrainPath, Ogre::String("dat"));
	mTerrainGroup->setOrigin(Ogre::Vector3::ZERO);

	configureTerrainDefaults();

	for( long x = 0; x <= 0; ++x )
		for( long y = 0; y <= 0; ++y )
			defineTerrain(x, y);

	mTerrainGroup->loadAllTerrains(true);
	//HeightMapTerrainGroup();//###

	if( mTerrainsImported )
	{
		Ogre::TerrainGroup::TerrainIterator ti = mTerrainGroup->getTerrainIterator();
		while( ti.hasMoreElements() )
		{
			Ogre::Terrain* t = ti.getNext()->instance;
			initBlendMaps(t);
		}
	}
	mTerrainGroup->freeTemporaryResources();
}
//--------------------------------------------------------------------
void TBuilderTerrain_Ogre::defineTerrain(long x, long y)
{
	Ogre::String filename = mTerrainGroup->generateFilename(x, y);
	bool exists =
		Ogre::ResourceGroupManager::getSingleton().resourceExists(
		mTerrainGroup->getResourceGroup(),
		filename);

	if( exists )
		mTerrainGroup->defineTerrain(x, y);
	else
	{
		unsigned short terrainSize = mTerrainGroup->getTerrainSize();
		float* pHeight = new float[terrainSize*terrainSize];
		float h_max = 10;
		float h_min = 0;
		int index = 0;
		for(int i = 0 ; i < terrainSize ; i++ )
		{
			for(int j = 0 ; j < terrainSize ; j++ )
			{
				pHeight[index+j] = j%2 ? h_min : h_max;
			}
			index += terrainSize;
		}
		mTerrainGroup->defineTerrain(x, y, pHeight);
		mTerrainsImported = true;
	}
}
//--------------------------------------------------------------------
void TBuilderTerrain_Ogre::initBlendMaps(Ogre::Terrain* terrain)
{
	Ogre::Real minHeight0 = 70;
	Ogre::Real fadeDist0 = 40;
	Ogre::Real minHeight1 = 70;
	Ogre::Real fadeDist1 = 15;

	Ogre::TerrainLayerBlendMap* blendMap0 = terrain->getLayerBlendMap(1);
	Ogre::TerrainLayerBlendMap* blendMap1 = terrain->getLayerBlendMap(2);

	float* pBlend0 = blendMap0->getBlendPointer();
	float* pBlend1 = blendMap1->getBlendPointer();

	for( Ogre::uint16 y = 0; y < terrain->getLayerBlendMapSize(); ++y)
	{
		for( Ogre::uint16 x = 0; x < terrain->getLayerBlendMapSize(); ++x)
		{
			Ogre::Real tx, ty;

			blendMap0->convertImageToTerrainSpace(x, y, &tx, &ty);
			Ogre::Real height = terrain->getHeightAtTerrainPosition(tx, ty);
			Ogre::Real val = (height - minHeight0) / fadeDist0;
			val = Ogre::Math::Clamp(val, (Ogre::Real)0, (Ogre::Real)1);
			*pBlend0++ = val;

			val = (height - minHeight1) / fadeDist1;
			val = Ogre::Math::Clamp(val, (Ogre::Real)0, (Ogre::Real)1);
			*pBlend1++ = val;
		}
	}

	blendMap0->dirty();
	blendMap1->dirty();
	blendMap0->update();
	blendMap1->update();
}
//--------------------------------------------------------------------
void TBuilderTerrain_Ogre::configureTerrainDefaults()
{
	Ogre::Light* light = mSceneMgr->getLight("mainLight");
	if( light==NULL )
		return;

	mTerrainGlobals->setMaxPixelError(8);
	mTerrainGlobals->setCompositeMapDistance(3000);

#if OGRE_NO_GLES3_SUPPORT == 1
	// Disable the lightmap for OpenGL ES 2.0. The minimum number of samplers allowed is 8(as opposed to 16 on desktop).
	// Otherwise we will run over the limit by just one. The minimum was raised to 16 in GL ES 3.0.
	if( mRoot->getRenderSystem()->getName().find("OpenGL ES 2")!=Ogre::String::npos)
	{
		Ogre::TerrainMaterialGeneratorA::SM2Profile* matProfile =
			static_cast<Ogre::TerrainMaterialGeneratorA::SM2Profile*>
			(mTerrainGlobals->getDefaultMaterialGenerator()->getActiveProfile());
		matProfile->setLightmapEnabled(false);
	}
#endif

	mTerrainGlobals->setLightMapDirection(light->getDerivedDirection());
	mTerrainGlobals->setCompositeMapAmbient(mSceneMgr->getAmbientLight());
	mTerrainGlobals->setCompositeMapDiffuse(light->getDiffuseColour());

	Ogre::Terrain::ImportData& importData = mTerrainGroup->getDefaultImportSettings();
	importData.terrainSize = 129;
	importData.worldSize = 500;//12000;
	importData.inputScale = 1;//600;
	importData.minBatchSize = 33;
	importData.maxBatchSize = 65;

	importData.layerList.resize(3);
	importData.layerList[0].worldSize = 100;
	importData.layerList[0].textureNames.push_back(
		"dirt_grayrocky_diffusespecular.dds");
	importData.layerList[0].textureNames.push_back(
		"dirt_grayrocky_normalheight.dds");
	importData.layerList[1].worldSize = 30;
	importData.layerList[1].textureNames.push_back(
		"grass_green-01_diffusespecular.dds");
	importData.layerList[1].textureNames.push_back(
		"grass_green-01_normalheight.dds");
	importData.layerList[2].worldSize = 200;
	importData.layerList[2].textureNames.push_back(
		"growth_weirdfungus-03_diffusespecular.dds");
	importData.layerList[2].textureNames.push_back(
		"growth_weirdfungus-03_normalheight.dds");
}
//--------------------------------------------------------------------
void TBuilderTerrain_Ogre::SetupShadow()
{
	// General scene setup
	mSceneMgr->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_ADDITIVE);
	mSceneMgr->setShadowFarDistance(3000);

	// 3 textures per directional light (PSSM)
	mSceneMgr->setShadowTextureCountPerLightType(Ogre::Light::LT_DIRECTIONAL, 3);

	//if (mPSSMSetup.isNull())
	//{
	//	// shadow camera setup
	//	PSSMShadowCameraSetup* pssmSetup = new PSSMShadowCameraSetup();
	//	pssmSetup->setSplitPadding(mCamera->getNearClipDistance());
	//	pssmSetup->calculateSplitPoints(3, mCamera->getNearClipDistance(), mSceneMgr->getShadowFarDistance());
	//	pssmSetup->setOptimalAdjustFactor(0, 2);
	//	pssmSetup->setOptimalAdjustFactor(1, 1);
	//	pssmSetup->setOptimalAdjustFactor(2, 0.5);

	//	mPSSMSetup.bind(pssmSetup);

	//}
	//mSceneMgr->setShadowCameraSetup(mPSSMSetup);

	//if (depthShadows)
	/*{
		mSceneMgr->setShadowTextureCount(3);
		mSceneMgr->setShadowTextureConfig(0, 2048, 2048, PF_FLOAT32_R);
		mSceneMgr->setShadowTextureConfig(1, 1024, 1024, PF_FLOAT32_R);
		mSceneMgr->setShadowTextureConfig(2, 1024, 1024, PF_FLOAT32_R);
		mSceneMgr->setShadowTextureSelfShadow(true);
		mSceneMgr->setShadowCasterRenderBackFaces(true);

		MaterialPtr houseMat = buildDepthShadowMaterial("fw12b.jpg");
		for (EntityList::iterator i = mHouseList.begin(); i != mHouseList.end(); ++i)
		{
			(*i)->setMaterial(houseMat);
		}

	}
	else*/
	{
		mSceneMgr->setShadowTextureCount(3);
		mSceneMgr->setShadowTextureConfig(0, 2048, 2048, Ogre::PF_X8B8G8R8);
		mSceneMgr->setShadowTextureConfig(1, 1024, 1024, Ogre::PF_X8B8G8R8);
		mSceneMgr->setShadowTextureConfig(2, 1024, 1024, Ogre::PF_X8B8G8R8);
		mSceneMgr->setShadowTextureSelfShadow(false);
		mSceneMgr->setShadowCasterRenderBackFaces(false);
		mSceneMgr->setShadowTextureCasterMaterial(Ogre::StringUtil::BLANK);
	}

	//matProfile->setReceiveDynamicShadowsDepth(depthShadows);
	//matProfile->setReceiveDynamicShadowsPSSM(static_cast<PSSMShadowCameraSetup*>(mPSSMSetup.get()));

	//addTextureShadowDebugOverlay(TL_RIGHT, 3);
}
//--------------------------------------------------------------------
void TBuilderTerrain_Ogre::AnalizHeightMap()
{
	Ogre::String filename = "../../Resources/Graphic/terrainLightMap/mapFlat_00000000.dat";
	Ogre::String groupResource = "General";
	Ogre::DataStreamPtr dataStream = 
		Ogre::ResourceGroupManager::getSingleton().openResource(filename, groupResource);

	Ogre::StreamSerialiser stream(dataStream);

	unsigned short WORKQUEUE_LOAD_LOD_DATA_REQUEST = 1;
	unsigned int   TERRAINLODDATA_CHUNK_ID = Ogre::StreamSerialiser::makeIdentifier("TLDA");
	unsigned short TERRAINLODDATA_CHUNK_VERSION = 1;

	// reach and read the target lod data
	const Ogre::StreamSerialiser::Chunk *c = 
		stream.readChunkBegin(TERRAINLODDATA_CHUNK_ID, TERRAINLODDATA_CHUNK_VERSION);
	stream.startDeflate(c->length);
	//stream.read(lodData, dataSize);
	stream.stopDeflate();
	stream.readChunkEnd(TERRAINLODDATA_CHUNK_ID);


	unsigned int   TERRAIN_CHUNK_ID = Ogre::StreamSerialiser::makeIdentifier("TERR");
  unsigned short TERRAIN_CHUNK_VERSION = 2;
	unsigned int   TERRAINGENERALINFO_CHUNK_ID = Ogre::StreamSerialiser::makeIdentifier("TGIN");
	unsigned short TERRAINGENERALINFO_CHUNK_VERSION = 1;
	const Ogre::StreamSerialiser::Chunk *mainChunk = stream.readChunkBegin(TERRAIN_CHUNK_ID, TERRAIN_CHUNK_VERSION);
	if( !mainChunk )
		return;

	if(mainChunk->version > 1)
		stream.readChunkBegin(TERRAINGENERALINFO_CHUNK_ID, TERRAINGENERALINFO_CHUNK_VERSION);

	unsigned char align = 0;
	unsigned short mSize = 0;
	unsigned short mMaxBatchSize = 0;
	unsigned short mMinBatchSize = 0;
	Ogre::Real mWorldSize = 0;
	Ogre::Vector3 mPos(0,0,0);

	stream.read(&align);
	stream.read(&mSize);
	stream.read(&mWorldSize);

	stream.read(&mMaxBatchSize);
	stream.read(&mMinBatchSize);
	stream.read(&mPos);

	if( mainChunk->version > 1 )
		stream.readChunkEnd(TERRAINGENERALINFO_CHUNK_ID);

	size_t numVertices = mSize * mSize;
	float* mHeightData = new float[numVertices];
	memset(mHeightData, 0, sizeof(float)*numVertices);
	if(mainChunk->version > 1)
	{
	}
	else
		stream.read(mHeightData, numVertices);

	int abc = 0;
}
//--------------------------------------------------------------------
void TBuilderTerrain_Ogre::HeightMapTerrainGroup()
{
	Ogre::TerrainGroup::TerrainIterator tit = mTerrainGroup->getTerrainIterator();
	Ogre::TerrainGroup::TerrainIterator::iterator cit = tit.current();
	cit = tit.begin();
	const Ogre::TerrainGroup::TerrainIterator::iterator& eit = tit.end();
	while( cit!=eit )
	{
		Ogre::Terrain* pTerrain = cit->second->instance;
		unsigned short size  = pTerrain->getWorldSize();
		unsigned short wSize = pTerrain->getSize();

		float* pHeight = pTerrain->getHeightData();
		tit.moveNext();
	}
}
//--------------------------------------------------------------------
