/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "Builder_Terrain_Ogre.h"
#include "Pattern_Terrain.h"

TBuilder_Terrain_Ogre::TBuilder_Terrain_Ogre()
{

}
//--------------------------------------------------------------------
TBuilder_Terrain_Ogre::~TBuilder_Terrain_Ogre()
{

}
//--------------------------------------------------------------------
void TBuilder_Terrain_Ogre::Begin()
{
	TMapItem*     pMapItem     = mPatternTerrain->GetMapItem();
	TTerrainItem* pTerrainItem = mPatternTerrain->GetTerrainItem();
	Ogre::Vector3 origin       = mPatternTerrain->GetOrigin();

	mBuilder.Begin(pMapItem,pTerrainItem,origin);
}
//--------------------------------------------------------------------
void TBuilder_Terrain_Ogre::Load( int x, int y )
{
	mBuilder.Load(x,y);
	// поместить загруженные данные в паттерн

}
//--------------------------------------------------------------------
void TBuilder_Terrain_Ogre::End()
{
	mBuilder.End();
}
//--------------------------------------------------------------------
