/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "SerializerMaterialItem_Binary.h"
#include "MaterialItem.h"
#include <boost/foreach.hpp>
#include "ShareMisc.h"

TSerializerMaterialItem_Binary::TSerializerMaterialItem_Binary():
TBaseSerializerItem_Binary(TFactoryGameItem::Material)
{

}
//-------------------------------------------------------------------------------------------------------
TSerializerMaterialItem_Binary::~TSerializerMaterialItem_Binary()
{

}
//-------------------------------------------------------------------------------------------------------
void TSerializerMaterialItem_Binary::PackItem(TBaseItem* pItem, TContainer& cBinOut)
{
  TMaterialItem* pMaterialItem = (TMaterialItem*)pItem;
  UnlinkCollect();

  PushType();
  PushStr(pMaterialItem->mName);
  Push(pMaterialItem->mGraphic.size());
  BOOST_FOREACH( TMaterialItem::TVecLOD& vecLod, pMaterialItem->mGraphic )
  {
    Push(vecLod.size());
    BOOST_FOREACH( TMaterialItem::TLOD& lod, vecLod)
    {
      Push(lod.distance);
      Push(lod.length);
      Push(lod.width);
      PushStr(lod.normal);
      PushStr(lod.color);
    }
  }

  Push(pMaterialItem->mPhysic);

  Collect(cBinOut);
}
//-------------------------------------------------------------------------------------------------------
bool TSerializerMaterialItem_Binary::UnpackItem(TBaseItem* pItem, void* pIn, int sizeIn)
{
  TMaterialItem* pMaterialItem = (TMaterialItem*)pItem;
  
  BeginUnpack((char*)pIn, sizeIn);

  RET_FALSE( PopType() )
  RET_FALSE( PopStr(pMaterialItem->mName) )

  pMaterialItem->mGraphic.clear();
  TMaterialItem::TVecVariant::size_type cntVecLod;
  RET_FALSE( Pop(cntVecLod) )
  for( int iVecLod = 0 ; iVecLod < int(cntVecLod) ; iVecLod++ )
  {
    TMaterialItem::TVecLOD::size_type cntLod;
    TMaterialItem::TVecLOD vecLod;
    RET_FALSE( Pop(cntLod) )
    for( int iLod = 0 ; iLod < int(cntLod) ; iLod++ )
    {
      TMaterialItem::TLOD lod;
      RET_FALSE( Pop(lod.distance) )
      RET_FALSE( Pop(lod.length) )
      RET_FALSE( Pop(lod.width) )
      RET_FALSE( PopStr(lod.normal) )
      RET_FALSE( PopStr(lod.color) )
      vecLod.push_back(lod);
    }
    pMaterialItem->mGraphic.push_back(vecLod);
  }
  
  RET_FALSE( Pop(pMaterialItem->mPhysic) )
  return true;
}
//-------------------------------------------------------------------------------------------------------
