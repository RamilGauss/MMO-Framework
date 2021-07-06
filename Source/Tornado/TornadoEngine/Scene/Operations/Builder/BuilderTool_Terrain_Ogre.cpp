/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "BuilderTool_Terrain_Ogre.h"
#include "ModuleLogic.h"
#include "GraphicEngine/GraphicEngine_Ogre_ImGui.h"
#include "ModuleGraphicEngine.h"

#include "MapItem.h"
#include "TerrainItem.h"
#include <boost/lexical_cast.hpp>

using namespace nsGraphicEngine;

TBuilderTool_Terrain_Ogre::TBuilderTool_Terrain_Ogre()
{
  mTerrainItem = NULL;

  mSceneMgr = NULL;

  mTerrainGroup     = NULL;
  mTerrainGlobals   = NULL;
}
//--------------------------------------------------------------------
TBuilderTool_Terrain_Ogre::~TBuilderTool_Terrain_Ogre()
{

}
//--------------------------------------------------------------------
void TBuilderTool_Terrain_Ogre::Begin(TTerrainItem* pTerrainItem, Ogre::Vector3& terrainOrigin)
{
  mTerrainItem    = pTerrainItem;
  mTerrainOrigin = terrainOrigin;

  InitOgrePtr();

  Ogre::String filename = mTerrainItem->mNameHeightData;
  Ogre::String prefixterrainPath = TModuleLogic::Get()->GetTerrainPath() + "/" + filename;
  Ogre::String suffix = "";
  mTerrainGroup->setFilenameConvention(prefixterrainPath, suffix);

  configureTerrainDefaults();

  for( int iX = mTerrainItem->mX.min ; iX <= mTerrainItem->mX.max ; iX++ )
    for( int iY = mTerrainItem->mY.min ; iY <= mTerrainItem->mY.max ; iY++ )
      defineTerrain(iX, iY);
}
//--------------------------------------------------------------------
void TBuilderTool_Terrain_Ogre::Load( int x, int y )
{
  mTerrainGroup->loadTerrain(x,y, true);// false?
}
//--------------------------------------------------------------------
void TBuilderTool_Terrain_Ogre::End()
{
  mTerrainGroup->freeTemporaryResources();
}
//--------------------------------------------------------------------
void TBuilderTool_Terrain_Ogre::defineTerrain(long x, long y)
{
  Ogre::String filename = mTerrainGroup->generateFilename(x, y);
  bool exists =
    Ogre::ResourceGroupManager::getSingleton().resourceExists(
    mTerrainGroup->getResourceGroup(),
    filename);

  // если нет файла, то ничего не делать, возможно, Terrain только что добавили.

  if( exists )
    mTerrainGroup->defineTerrain(x, y);
}
//--------------------------------------------------------------------
void TBuilderTool_Terrain_Ogre::configureTerrainDefaults()
{
  mTerrainGlobals->setMaxPixelError(mTerrainItem->mGraphic.maxPixelError);
  mTerrainGlobals->setCompositeMapDistance(mTerrainItem->mGraphic.compositeMapDistance);

  mTerrainGroup->setOrigin(mTerrainOrigin);
}
//--------------------------------------------------------------------
void TBuilderTool_Terrain_Ogre::InitOgrePtr()
{
  TGraphicEngine_Ogre_ImGui* pGE = TModuleLogic::Get()->GetC()->pGraphicEngine->GetGE();
  mSceneMgr = pGE->GetSceneManager();
  // Terrain
  mTerrainGlobals = pGE->GetTerrainGlobals();
  mTerrainGroup   = pGE->GetTerrainGroup();
}
//--------------------------------------------------------------------
