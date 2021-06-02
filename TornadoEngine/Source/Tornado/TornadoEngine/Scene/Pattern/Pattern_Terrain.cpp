/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Pattern_Terrain.h"
#include "BL_Debug.h"
#include "TerrainItem.h"

#include "FactoryGameItem.h"
#include "ModuleLogic.h"

namespace nsPattern_Terrain
{
  const char* sNameGameItem = "NameGameItem";

  static TPatternConfigItem::TMapStrStr g_DefaultParameterMap;
}

using namespace nsPattern_Terrain;

TPattern_Terrain::TPattern_Terrain() :
  TBehaviourPattern(&g_DefaultParameterMap)
{
  g_DefaultParameterMap.insert(TPatternConfigItem::TMapStrStrVT(sNameGameItem,""));

  mBuilderBullet.SetPattern(this);
  mBuilderOgre  .SetPattern(this);

  mModifierBullet.SetPattern(this);
  mModifierOgre   .SetPattern(this);

  //mUpdaterGameItemBullet.SetPattern(this);
  //mUpdaterGameItemOgre  .SetPattern(this);

  //mUpdaterByGameItemBullet.SetPattern(this);
  //mUpdaterByGameItemOgre  .SetPattern(this);

  //mSaverGameItemBullet.SetPattern(this);
  //mSaverGameItemOgre  .SetPattern(this);

  //mSaverOutDataBullet.SetPattern(this);
  //mSaverOutDataOgre  .SetPattern(this);

  mDestructorBullet.SetPattern(this);
  mDestructorOgre   .SetPattern(this);
}
//---------------------------------------------------------------------------
TPattern_Terrain::~TPattern_Terrain()
{

}
//---------------------------------------------------------------------------
bool TPattern_Terrain::BuildByModule_Graphic(bool fast)
{
  if( mProgressOgre.flgIsBuild==false )
    BeginBuild_Ogre();

  return TryBuild_Ogre();
}
//---------------------------------------------------------------------------
bool TPattern_Terrain::BuildByModule_Physic(bool fast)
{
  if( mProgressBullet.flgIsBuild==false )
    BeginBuild_Bullet();

  return TryBuild_Bullet();
}
//---------------------------------------------------------------------------
void TPattern_Terrain::BeginBuild_Bullet()
{
  BeginBuild( &mBuilderBullet, &mProgressBullet);
}
//---------------------------------------------------------------------------
void TPattern_Terrain::BeginBuild_Ogre()
{
  BeginBuild( &mBuilderOgre, &mProgressOgre);
}
//---------------------------------------------------------------------------
void TPattern_Terrain::BeginBuild( TBuilder_Terrain* pBuilder, TProgressBuild* pProgress)
{
  pBuilder->Begin();

  TTerrainItem* pTerrainItem = GetTerrainItem();
  pProgress->flgIsBuild = true;
  pProgress->mNeedBuildX = pTerrainItem->mX.min;
  pProgress->mNeedBuildY = pTerrainItem->mY.min;
}
//---------------------------------------------------------------------------
bool TPattern_Terrain::TryBuild_Bullet()
{
  return TryBuild( &mBuilderBullet, &mProgressBullet);
}
//---------------------------------------------------------------------------
bool TPattern_Terrain::TryBuild_Ogre()
{
  return TryBuild( &mBuilderOgre, &mProgressOgre);
}
//---------------------------------------------------------------------------
bool TPattern_Terrain::TryBuild(TBuilder_Terrain* pBuilder, TProgressBuild* pProgress)
{
  TTerrainItem* pTerrainItem = GetTerrainItem();

  int minX = pTerrainItem->mX.min;
  int maxX = pTerrainItem->mX.max;
  int minY = pTerrainItem->mY.min;
  int maxY = pTerrainItem->mY.max;

  int x = pProgress->mNeedBuildX;
  int y = pProgress->mNeedBuildY;

  pBuilder->Load(x,y);
  x++;
  if( x > maxX)
  {
    x = minX;
    y++;
  }
  if( y > maxY )
  {
    pBuilder->End();
    pProgress->flgIsBuild = false;
    return true;
  }
  pProgress->mNeedBuildX = x;
  pProgress->mNeedBuildY = y;
  return false;
}
//---------------------------------------------------------------------------
std::string TPattern_Terrain::GetNameTerrainItem()
{
  return GetFromParameterMap<std::string>(sNameGameItem);
}
//---------------------------------------------------------------------------
Ogre::Vector3 TPattern_Terrain::GetOrigin()
{
  Ogre::Vector3 originOgre = Ogre::Vector3::ZERO;

  nsMathTools::TVector3 pos;
  if( GetPosition(pos)==false )
  {
    BL_FIX_BUG();
    return originOgre;
  }

  originOgre.x = pos.x;
  originOgre.y = pos.y;
  originOgre.z = pos.z;
  return originOgre;
}
//---------------------------------------------------------------------------
void TPattern_Terrain::ModifyExtent(TModifier_Terrain::TDescTarget& descTarget)
{
  mModifierBullet.SetFormat(descTarget);
  mModifierOgre.SetFormat(descTarget);
}
//---------------------------------------------------------------------------
void TPattern_Terrain::ModifyBlend()
{

}
//---------------------------------------------------------------------------
void TPattern_Terrain::ModifyPaint()
{

}
//---------------------------------------------------------------------------
TPatternNameManager::eBaseType TPattern_Terrain::GetBaseType()
{
  return TPatternNameManager::eTerrain;
}
//------------------------------------------------------------------------
TMapItem* TPattern_Terrain::GetMapItem()
{
  std::string nameMapItem = GetNameMapItem();
  TMapItem* pMapItem = 
    (TMapItem*)TModuleLogic::Get()->GetFGI()->Get(TFactoryGameItem::Map, nameMapItem);
  return pMapItem;
}
//---------------------------------------------------------------------------
TTerrainItem* TPattern_Terrain::GetTerrainItem()
{
  std::string nameTerrainItem = GetNameTerrainItem();
  TTerrainItem* pTerrainItem = 
    (TTerrainItem*)TModuleLogic::Get()->GetFGI()->Get(TFactoryGameItem::Terrain, nameTerrainItem);
  return pTerrainItem;
}
//---------------------------------------------------------------------------
bool TPattern_Terrain::UpdateGameItem(TFactoryGameItem::TypeGameItem type)
{
  return mUpdaterGameItemBullet.Update(type) || mUpdaterGameItemOgre.Update(type);
}
//---------------------------------------------------------------------------
void TPattern_Terrain::SaveGameItemOnHDD(TFactoryGameItem::TypeGameItem type)
{
  mSaverGameItemBullet.Save(type);
  mSaverGameItemOgre.Save(type);
}
//---------------------------------------------------------------------------
void TPattern_Terrain::SaveOutDataOnHDD(TFactoryGameItem::TypeGameItem type)
{
  mSaverOutDataBullet.Save(type);
  mSaverOutDataOgre.Save(type);
}
//---------------------------------------------------------------------------
