/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Builder_Terrain_Bullet.h"
#include "Pattern_Terrain.h"
#include "TerrainItem.h"

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
  BL_ASSERT(mPatternTerrain->mX_Y_PartPhysic.size()==0);

  TMapItem*     pMapItem     = mPatternTerrain->GetMapItem();
  TTerrainItem* pTerrainItem = mPatternTerrain->GetTerrainItem();

  for( int iX = pTerrainItem->mX.min ; iX <= pTerrainItem->mX.max ; iX++ )
  {
    TPattern_Terrain::TMapIntPartPhysic mapY_Part;
    for( int iY = pTerrainItem->mY.min ; iY <= pTerrainItem->mY.max ; iY++ )
    {
      nsStructPattern_Terrain::TTerrainPart_Physic part;
      mapY_Part.insert(TPattern_Terrain::TMapIntPartPhysicVT(iY,part));
    }
    mPatternTerrain->mX_Y_PartPhysic.
      insert(TPattern_Terrain::TMapIntMapPartPhysicVT(iX,mapY_Part));
  }

  mBuilder.SetID_PhysicWorld(mPatternTerrain->GetPhysicWorld());
  mBuilder.Begin(pTerrainItem);
}
//--------------------------------------------------------------------
void TBuilder_Terrain_Bullet::Load( int x, int y )
{
  TPattern_Terrain::TMapIntMapPartPhysicIt fitX = mPatternTerrain->mX_Y_PartPhysic.find(x);
  if( fitX==mPatternTerrain->mX_Y_PartPhysic.end() )
  {
    BL_FIX_BUG();
    return;
  }
  TPattern_Terrain::TMapIntPartPhysicIt fitY = fitX->second.find(y);
  if( fitY==fitX->second.end() )
  {
    BL_FIX_BUG();
    return;
  }

  nsStructPattern_Terrain::TTerrainPart_Physic* pPart = &(fitY->second);
  mBuilder.Load(x,y,pPart);
}
//--------------------------------------------------------------------
void TBuilder_Terrain_Bullet::End()
{

}
//--------------------------------------------------------------------
