/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "Builder_Terrain_Bullet.h"
#include "Pattern_Terrain.h"

TBuilder_Terrain_Bullet::TBuilder_Terrain_Bullet()
{

}
//--------------------------------------------------------------------
TBuilder_Terrain_Bullet::~TBuilder_Terrain_Bullet()
{

}
//--------------------------------------------------------------------
void TBuilder_Terrain_Bullet::Begin()
{
	TMapItem*     pMapItem     = mPatternTerrain->GetMapItem();
	TTerrainItem* pTerrainItem = mPatternTerrain->GetTerrainItem();
	
	mBuilder.SetID_PhysicWorld(mPatternTerrain->GetPhysicWorld());
	mBuilder.Begin(pMapItem,pTerrainItem);
}
//--------------------------------------------------------------------
void TBuilder_Terrain_Bullet::Load( int x, int y )
{
	mBuilder.Load(x,y);
}
//--------------------------------------------------------------------
void TBuilder_Terrain_Bullet::End()
{
	// поместить загруженные данные в паттерн

}
//--------------------------------------------------------------------
