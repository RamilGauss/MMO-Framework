/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "CreaterTerrain.h"

TCreaterTerrain::TCreaterTerrain()
{
	mTerrainGroup   = NULL;
	mTerrainOptions = NULL;
}
//------------------------------------------------------------------------
void TCreaterTerrain::Create(TDescTarget& descTarget, 
						Ogre::TerrainGroup* pTG, Ogre::TerrainGlobalOptions* pTGO)
{
	mTerrainGroup   = pTG;
	mTerrainOptions = pTGO;

}
//------------------------------------------------------------------------
void TCreaterTerrain::setupContent()
{
}
	/*
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
*/