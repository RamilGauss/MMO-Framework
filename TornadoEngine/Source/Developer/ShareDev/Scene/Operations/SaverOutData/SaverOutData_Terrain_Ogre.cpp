/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "SaverOutData_Terrain_Ogre.h"

#include "ModuleLogic.h"
#include "GraphicEngine_Ogre_MyGUI.h"
#include "ModuleGraphicEngine.h"

#include <Ogre.h>
#include <OgreTerrain.h>

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
		TGraphicEngine_Ogre_MyGUI* pGE = TModuleLogic::Get()->GetC()->pGraphicEngine->GetGE();
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
