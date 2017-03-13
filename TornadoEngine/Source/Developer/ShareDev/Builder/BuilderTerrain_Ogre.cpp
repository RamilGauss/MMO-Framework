/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "BuilderTerrain_Ogre.h"
#include "ModuleLogic.h"
#include "GraphicEngine_Ogre_MyGUI.h"
#include "ModuleGraphicEngine.h"

#include "MapItem.h"
#include "TerrainItem.h"
#include <boost/lexical_cast.hpp>

namespace nsBuilderTerrain_Ogre
{
	const char* sMaxPixelError        = "MaxPixelError";
	const char* sCompositeMapDistance = "CompositeMapDistance";
}

using namespace nsBuilderTerrain_Ogre;
//---------------------------------------------------------------------
TBuilderTerrain_Ogre::TBuilderTerrain_Ogre()
{
	mMapItem     = NULL;
	mTerrainItem = NULL;

	mSceneMgr = NULL;

	mTerrainGroup     = NULL;
	mTerrainGlobals   = NULL;
	mTerrainsImported = false;
}
//--------------------------------------------------------------------
TBuilderTerrain_Ogre::~TBuilderTerrain_Ogre()
{

}
//--------------------------------------------------------------------
void TBuilderTerrain_Ogre::Begin(TMapItem* pMapItem, TTerrainItem* pTerrainItem, Ogre::Vector3& terrainOrigin)
{
	mMapItem     	 = pMapItem;
	mTerrainItem 	 = pTerrainItem;
	mTerrainOrigin = terrainOrigin;

	InitOgrePtr();

	Ogre::String filename = mMapItem->mName;
	Ogre::String prefixterrainPath = TModuleLogic::Get()->GetTerrainPath() + "/" + filename;
	Ogre::String suffix = "";
	mTerrainGroup->setFilenameConvention(prefixterrainPath, suffix);

	configureTerrainDefaults();

	for( int iX = mTerrainItem->mX.min ; iX <= mTerrainItem->mX.max ; iX++ )
		for( int iY = mTerrainItem->mY.min ; iY <= mTerrainItem->mY.max ; iY++ )
			defineTerrain(iX, iY);
}
//--------------------------------------------------------------------
void TBuilderTerrain_Ogre::Load( int x, int y )
{
	mTerrainGroup->loadTerrain(x,y, true);// false?
}
//--------------------------------------------------------------------
void TBuilderTerrain_Ogre::End()
{
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
	TTerrainItem::TMapStrStrIt fit = mTerrainItem->mMapProperty.find(sMaxPixelError);
	if( fit!=mTerrainItem->mMapProperty.end() )
	{
		float maxPixelError = boost::lexical_cast<float>(fit->second);
		mTerrainGlobals->setMaxPixelError(maxPixelError);
	}
	fit = mTerrainItem->mMapProperty.find(sCompositeMapDistance);
	if( fit!=mTerrainItem->mMapProperty.end() )
	{
		float compositeMapDistance = boost::lexical_cast<float>(fit->second);
		mTerrainGlobals->setCompositeMapDistance(compositeMapDistance);
	}

	mTerrainGroup->setOrigin(mTerrainOrigin);

	Ogre::Light* light = mSceneMgr->getLight("mainLight");
	if( light==NULL )
		return;
	mTerrainGlobals->setLightMapDirection(light->getDerivedDirection());
	mTerrainGlobals->setCompositeMapAmbient(mSceneMgr->getAmbientLight());
	mTerrainGlobals->setCompositeMapDiffuse(light->getDiffuseColour());
}
//--------------------------------------------------------------------
void TBuilderTerrain_Ogre::InitOgrePtr()
{
	TGraphicEngine_Ogre_MyGUI* pGE = TModuleLogic::Get()->GetC()->pGraphicEngine->GetGE();
	mSceneMgr = pGE->GetSceneManager();
	// Terrain
	mTerrainGlobals = pGE->GetTerrainGlobals();
	mTerrainGroup   = pGE->GetTerrainGroup();
}
//--------------------------------------------------------------------
