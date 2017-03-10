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

#include <OgreTerrainMaterialGeneratorA.h>
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
	InitOgrePtr();

	// BackGroundColour
	Ogre::ColourValue fadeColour(0.8f, 0.8f, 0.8f);
	mWindow->getViewport(0)->setBackgroundColour(fadeColour);
	// Fog
	mSceneMgr->setFog(Ogre::FOG_LINEAR, fadeColour, 0.0, 4000, 10000);
	// SkyPlane
	Ogre::Plane plane;
	plane.d = 1000;
	plane.normal = Ogre::Vector3::NEGATIVE_UNIT_Y;
	mSceneMgr->setSkyPlane(true, plane, "Examples/CloudySky", 500, 20, true, 0.5, 150, 150);

	Init();
}
//--------------------------------------------------------------------
void TBuilderTerrain_Ogre::Init()
{
	Ogre::String filename = "/mapFlat";
	Ogre::String prefixterrainPath = TModuleLogic::Get()->GetTerrainPath() + filename;
	Ogre::String suffix = "dat";
	mTerrainGroup->setFilenameConvention(prefixterrainPath, suffix);

	configureTerrainDefaults();

	defineTerrain(0, 0);

	mTerrainGroup->loadAllTerrains(true);
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
}
//--------------------------------------------------------------------
void TBuilderTerrain_Ogre::configureTerrainDefaults()
{
	mTerrainGlobals->setMaxPixelError(8);          // from XML
	mTerrainGlobals->setCompositeMapDistance(3000);// from XML
	mTerrainGroup->setOrigin(Ogre::Vector3::ZERO); // from XML
	
	Ogre::Light* light = mSceneMgr->getLight("mainLight");
	if( light==NULL )
		return;
	mTerrainGlobals->setLightMapDirection(light->getDerivedDirection());
	mTerrainGlobals->setCompositeMapAmbient(mSceneMgr->getAmbientLight());
	mTerrainGlobals->setCompositeMapDiffuse(light->getDiffuseColour());

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
}
//--------------------------------------------------------------------
//	std::string path = TModuleLogic::Get()->GetTerrainPath() + "/mapFlat_00000000.dat";
//	THeightMapFromOgre::TDataOut data;
//	mHMF_Ogre.Setup(path, data);
//--------------------------------------------------------------------
void TBuilderTerrain_Ogre::InitOgrePtr()
{
	TGraphicEngine_Ogre_MyGUI* pGE = TModuleLogic::Get()->GetC()->pGraphicEngine->GetGE();
	mRoot     = pGE->GetRoot();
	mSceneMgr = pGE->GetSceneManager();
	mWindow   = pGE->GetWindow();
	// Terrain
	mTerrainGlobals = pGE->GetTerrainGlobals();
	mTerrainGroup   = pGE->GetTerrainGroup();
}
//--------------------------------------------------------------------
