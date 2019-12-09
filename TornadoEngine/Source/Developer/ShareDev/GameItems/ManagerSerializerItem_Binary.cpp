/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ManagerSerializerItem_Binary.h"
#include "FactoryGameItem.h"

#include "BaseItem.h"

TManagerSerializerItem_Binary::TManagerSerializerItem_Binary()
{
  mSerializerPatternConfig.reset(new TSerializerPatternConfigItem_Binary);
  mSerializerShape.reset(        new TSerializerShapeItem_Binary);
  mSerializerModel.reset(        new TSerializerModelItem_Binary);
  mSerializerMaterial.reset(     new TSerializerMaterialItem_Binary);
  mSerializerTerrain.reset(      new TSerializerTerrainItem_Binary);
  mSerializerMap.reset(          new TSerializerMapItem_Binary);
  mSerializerTableSound.reset(   new TSerializerTableSoundItem_Binary);

  mMapTypeSerializer.insert(TMapIntPtrSerilizerVT(TFactoryGameItem::PatternConfig,mSerializerPatternConfig.get()));
  mMapTypeSerializer.insert(TMapIntPtrSerilizerVT(TFactoryGameItem::Material,     mSerializerMaterial.get()));
  mMapTypeSerializer.insert(TMapIntPtrSerilizerVT(TFactoryGameItem::Shape,        mSerializerShape.get()));
  mMapTypeSerializer.insert(TMapIntPtrSerilizerVT(TFactoryGameItem::Model,        mSerializerModel.get()));
  mMapTypeSerializer.insert(TMapIntPtrSerilizerVT(TFactoryGameItem::Terrain,      mSerializerTerrain.get()));
  mMapTypeSerializer.insert(TMapIntPtrSerilizerVT(TFactoryGameItem::Map,          mSerializerMap.get()));
  mMapTypeSerializer.insert(TMapIntPtrSerilizerVT(TFactoryGameItem::TableSound,   mSerializerTableSound.get()));
}
//--------------------------------------------------------------------------------------
void TManagerSerializerItem_Binary::Pack(TBaseItem* pItem, TContainerRise& cBinOut)
{
  TBaseSerializerItem_Binary* pMap = FindMap(pItem->mType);
  if( pMap==NULL ) 
    return;
  pMap->PackItem(pItem, cBinOut);
}
//--------------------------------------------------------------------------------------
bool TManagerSerializerItem_Binary::Unpack(TBaseItem* pItem, void* pIn, int sizeIn)
{
  TBaseSerializerItem_Binary* pMap = FindMap(pItem->mType);
  if( pMap==NULL ) 
    return false;
  return pMap->UnpackItem(pItem, pIn, sizeIn);
}
//--------------------------------------------------------------------------------------
TBaseSerializerItem_Binary* TManagerSerializerItem_Binary::FindMap(int type)
{
  TMapIntPtrSerilizerIt fit = mMapTypeSerializer.find(type);
  if( fit==mMapTypeSerializer.end() ) 
    return false;
  return fit->second;
}
//--------------------------------------------------------------------------------------
