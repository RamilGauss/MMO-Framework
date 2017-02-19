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
  BOOST_FOREACH( TMaterialItem::TVariant& variant, pMaterialItem->mGraphic )
  {
    Push(variant.length);
    Push(variant.width);
    PushStr(variant.normal);
    PushStr(variant.color);
		PushStr(variant.ogreMaterial);
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
  TMaterialItem::TVecVariant::size_type cntVariant;
  RET_FALSE( Pop(cntVariant) )
  for( int iVariant = 0 ; iVariant < int(cntVariant) ; iVariant++ )
  {
    TMaterialItem::TVariant variant;
    RET_FALSE( Pop(variant.length) )
    RET_FALSE( Pop(variant.width) )
    RET_FALSE( PopStr(variant.normal) )
    RET_FALSE( PopStr(variant.color) )
		RET_FALSE( PopStr(variant.ogreMaterial) )
    pMaterialItem->mGraphic.push_back(variant);
  }
  
  RET_FALSE( Pop(pMaterialItem->mPhysic) )
  return true;
}
//-------------------------------------------------------------------------------------------------------
