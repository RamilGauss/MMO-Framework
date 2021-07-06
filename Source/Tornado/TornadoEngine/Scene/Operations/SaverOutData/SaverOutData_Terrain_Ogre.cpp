/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "SaverOutData_Terrain_Ogre.h"

#include "ModuleLogic.h"
#include "GraphicEngine/GraphicEngine_Ogre_ImGui.h"
#include "ModuleGraphicEngine.h"

#include <Ogre.h>
#include <OgreTerrain.h>

using namespace nsGraphicEngine;

TSaverOutData_Terrain_Ogre::TSaverOutData_Terrain_Ogre()
{

}
//---------------------------------------------------------------------
TSaverOutData_Terrain_Ogre::~TSaverOutData_Terrain_Ogre()
{

}
//---------------------------------------------------------------------
void TSaverOutData_Terrain_Ogre::Save(TFactoryGameItem::TypeGameItem type)
{
  if( type==TFactoryGameItem::Terrain )
  {
    TGraphicEngine_Ogre_ImGui* pGE = TModuleLogic::Get()->GetC()->pGraphicEngine->GetGE();
    Ogre::TerrainGroup* pTerrainGlobals = pGE->GetTerrainGroup();

    if( pTerrainGlobals==NULL )
      return;

    if( pTerrainGlobals->isDerivedDataUpdateInProgress() )
    {
      BL_FIX_BUG();
      return;
    }

    pTerrainGlobals->saveAllTerrains(true);
  }
}
//---------------------------------------------------------------------
