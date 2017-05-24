/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "Modifier_Terrain_Ogre.h"

TModifier_Terrain_Ogre::TModifier_Terrain_Ogre()
{

}
//-------------------------------------------------------------------------
void TModifier_Terrain_Ogre::SetFormat(TDescTarget& descTarget)
{

}
//------------------------------------------------------------------------
void TModifier_Terrain_Ogre::setupContent()
{
	// если все новые параметры совпадают со старыми, то не делать апдейт и выйти.

	// грохнуть все старые данные

	// создать заново
	

}
//------------------------------------------------------------------------
#if 0
	bool blankTerrain = false;
	//blankTerrain = true;

	Ogre::ResourceGroupManager::getSingleton().createResourceGroup("Terrain");
	Ogre::ResourceGroupManager::getSingleton().addResourceLocation(mFSLayer->getWritablePath(""), "FileSystem", "Terrain", false, false);

	MaterialManager::getSingleton().setDefaultTextureFiltering(TFO_ANISOTROPIC);
	MaterialManager::getSingleton().setDefaultAnisotropy(7);

	mTerrainGroup = OGRE_NEW TerrainGroup(mSceneMgr, Terrain::ALIGN_X_Z, TERRAIN_SIZE, TERRAIN_WORLD_SIZE);
	mTerrainGroup->setFilenameConvention(TERRAIN_FILE_PREFIX, TERRAIN_FILE_SUFFIX);
	mTerrainGroup->setOrigin(mTerrainPos);
	mTerrainGroup->setResourceGroup("Terrain");

	configureTerrainDefaults(l);
	#ifdef PAGING
	// Paging setup
	mPageManager = OGRE_NEW PageManager();
	// Since we're not loading any pages from .page files, we need a way just 
	// to say we've loaded them without them actually being loaded
	mPageManager->setPageProvider(&mDummyPageProvider);
	mPageManager->addCamera(mCamera);
	mTerrainPaging = OGRE_NEW TerrainPaging(mPageManager);
	PagedWorld* world = mPageManager->createWorld();
	mTerrainPaging->createWorldSection(world, mTerrainGroup, 2000, 3000, 
	TERRAIN_PAGE_MIN_X, TERRAIN_PAGE_MIN_Y, 
	TERRAIN_PAGE_MAX_X, TERRAIN_PAGE_MAX_Y);
	#else
	for (long x = TERRAIN_PAGE_MIN_X; x <= TERRAIN_PAGE_MAX_X; ++x)
	for (long y = TERRAIN_PAGE_MIN_Y; y <= TERRAIN_PAGE_MAX_Y; ++y)
	defineTerrain(x, y, blankTerrain);
	// sync load since we want everything in place when we start
	mTerrainGroup->loadAllTerrains(true);
	#endif

	if (mTerrainsImported)
	{
	TerrainGroup::TerrainIterator ti = mTerrainGroup->getTerrainIterator();
	while(ti.hasMoreElements())
	{
	Terrain* t = ti.getNext()->instance;
	initBlendMaps(t);
	}
	}

	mTerrainGroup->freeTemporaryResources();



	// create a few entities on the terrain
	Entity* e = mSceneMgr->createEntity("tudorhouse.mesh");
	Vector3 entPos(mTerrainPos.x + 2043, 0, mTerrainPos.z + 1715);
	Quaternion rot;
	entPos.y = mTerrainGroup->getHeightAtWorldPosition(entPos) + 65.5 + mTerrainPos.y;
	rot.FromAngleAxis(Degree(Math::RangeRandom(-180, 180)), Vector3::UNIT_Y);
	SceneNode* sn = mSceneMgr->getRootSceneNode()->createChildSceneNode(entPos, rot);
	sn->setScale(Vector3(0.12, 0.12, 0.12));
	sn->attachObject(e);
	mHouseList.push_back(e);

	e = mSceneMgr->createEntity("tudorhouse.mesh");
	entPos = Vector3(mTerrainPos.x + 1850, 0, mTerrainPos.z + 1478);
	entPos.y = mTerrainGroup->getHeightAtWorldPosition(entPos) + 65.5 + mTerrainPos.y;
	rot.FromAngleAxis(Degree(Math::RangeRandom(-180, 180)), Vector3::UNIT_Y);
	sn = mSceneMgr->getRootSceneNode()->createChildSceneNode(entPos, rot);
	sn->setScale(Vector3(0.12, 0.12, 0.12));
	sn->attachObject(e);
	mHouseList.push_back(e);

	e = mSceneMgr->createEntity("tudorhouse.mesh");
	entPos = Vector3(mTerrainPos.x + 1970, 0, mTerrainPos.z + 2180);
	entPos.y = mTerrainGroup->getHeightAtWorldPosition(entPos) + 65.5 + mTerrainPos.y;
	rot.FromAngleAxis(Degree(Math::RangeRandom(-180, 180)), Vector3::UNIT_Y);
	sn = mSceneMgr->getRootSceneNode()->createChildSceneNode(entPos, rot);
	sn->setScale(Vector3(0.12, 0.12, 0.12));
	sn->attachObject(e);
	mHouseList.push_back(e);

	mSceneMgr->setSkyBox(true, "Examples/CloudyNoonSkyBox");


}

void defineTerrain(long x, long y, bool flat = false)
{
// if a file is available, use it
// if not, generate file from import

// Usually in a real project you'll know whether the compact terrain data is
// available or not; I'm doing it this way to save distribution size

if (flat)
{
mTerrainGroup->defineTerrain(x, y, 0.0f);
}
else
{
String filename = mTerrainGroup->generateFilename(x, y);
if (ResourceGroupManager::getSingleton().resourceExists(mTerrainGroup->getResourceGroup(), filename))
{
mTerrainGroup->defineTerrain(x, y);
}
else
{
Image img;
getTerrainImage(x % 2 != 0, y % 2 != 0, img);
mTerrainGroup->defineTerrain(x, y, &img);
mTerrainsImported = true;
}

}
}

void configureTerrainDefaults(Light* l)
{
// Configure global
mTerrainGlobals->setMaxPixelError(8);
// testing composite map
mTerrainGlobals->setCompositeMapDistance(3000);
//mTerrainGlobals->setUseRayBoxDistanceCalculation(true);
//mTerrainGlobals->getDefaultMaterialGenerator()->setDebugLevel(1);
//mTerrainGlobals->setLightMapSize(256);

#if OGRE_NO_GLES3_SUPPORT == 1
// Disable the lightmap for OpenGL ES 2.0. The minimum number of samplers allowed is 8(as opposed to 16 on desktop).
// Otherwise we will run over the limit by just one. The minimum was raised to 16 in GL ES 3.0.
if (Ogre::Root::getSingletonPtr()->getRenderSystem()->getName().find("OpenGL ES 2") != String::npos)
{
TerrainMaterialGeneratorA::SM2Profile* matProfile =
static_cast<TerrainMaterialGeneratorA::SM2Profile*>(mTerrainGlobals->getDefaultMaterialGenerator()->getActiveProfile());
matProfile->setLightmapEnabled(false);
}
#endif
// Important to set these so that the terrain knows what to use for derived (non-realtime) data
mTerrainGlobals->setLightMapDirection(l->getDerivedDirection());
mTerrainGlobals->setCompositeMapAmbient(mSceneMgr->getAmbientLight());
//mTerrainGlobals->setCompositeMapAmbient(ColourValue::Red);
mTerrainGlobals->setCompositeMapDiffuse(l->getDiffuseColour());

// Configure default import settings for if we use imported image
Terrain::ImportData& defaultimp = mTerrainGroup->getDefaultImportSettings();
defaultimp.terrainSize = TERRAIN_SIZE;
defaultimp.worldSize = TERRAIN_WORLD_SIZE;
defaultimp.inputScale = 600;
defaultimp.minBatchSize = 33;
defaultimp.maxBatchSize = 65;
// textures
defaultimp.layerList.resize(3);
defaultimp.layerList[0].worldSize = 100;
defaultimp.layerList[0].textureNames.push_back("dirt_grayrocky_diffusespecular.dds");
defaultimp.layerList[0].textureNames.push_back("dirt_grayrocky_normalheight.dds");
defaultimp.layerList[1].worldSize = 30;
defaultimp.layerList[1].textureNames.push_back("grass_green-01_diffusespecular.dds");
defaultimp.layerList[1].textureNames.push_back("grass_green-01_normalheight.dds");
defaultimp.layerList[2].worldSize = 200;
defaultimp.layerList[2].textureNames.push_back("growth_weirdfungus-03_diffusespecular.dds");
defaultimp.layerList[2].textureNames.push_back("growth_weirdfungus-03_normalheight.dds");


}
#endif