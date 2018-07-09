/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "SerializerMapItem_Binary.h"
#include "FactoryGameItem.h"
#include "MapItem.h"
#include "boost/foreach.hpp"
#include "ShareMisc.h"

TSerializerMapItem_Binary::TSerializerMapItem_Binary():
TBaseSerializerItem_Binary(TFactoryGameItem::Map)
{

}
//-------------------------------------------------------------------------------------------------------
TSerializerMapItem_Binary::~TSerializerMapItem_Binary()
{

}
//-------------------------------------------------------------------------------------------------------
void TSerializerMapItem_Binary::PackItem(TBaseItem* pItem, TContainerRise& cBinOut)
{
  TMapItem* pMapItem = (TMapItem*)pItem;
  Reset();

  PushType();
  PushStr(pMapItem->mName);

  Push(pMapItem->mListObject.size());
  for( auto& object : pMapItem->mListObject )
  {
    PushStr(object.namePattern);
    Push(object.id);

    Push(object.position.x);
    Push(object.position.y);
    Push(object.position.z);

    for( int i = 0 ; i < 3 ; i++ )
    {
      for( int j = 0 ; j < 3 ; j++ )
      {
        Push(object.orientation.m[i][j]);
      }
    }

    PushStr(object.patternConfig.name);
    PushStr(object.patternConfig.nameVariant);
  }
  Collect(cBinOut);
}
//-------------------------------------------------------------------------------------------------------
bool TSerializerMapItem_Binary::UnpackItem(TBaseItem* pItem, void* pIn, int sizeIn)
{
  TMapItem* pMapItem = (TMapItem*)pItem;

  BeginUnpack((char*)pIn, sizeIn);

  RET_FALSE( PopType() )
  RET_FALSE( PopStr(pMapItem->mName) )

  TMapItem::TListObject::size_type cntObject;
  RET_FALSE( Pop(cntObject) )
  for( int iObject = 0 ; iObject < int(cntObject) ; iObject++ )
  {
    TMapItem::TObject object;
    RET_FALSE( PopStr(object.namePattern) )
    RET_FALSE( Pop(object.id) )

    RET_FALSE( Pop(object.position.x) )
    RET_FALSE( Pop(object.position.y) )
    RET_FALSE( Pop(object.position.z) )

    for( int i = 0 ; i < 3 ; i++ )
    {
      for( int j = 0 ; j < 3 ; j++ )
      {
        RET_FALSE( Pop(object.orientation.m[i][j]) )
      }
    }

    RET_FALSE( Pop(object.patternConfig.name) )
    RET_FALSE( Pop(object.patternConfig.nameVariant) )

    pMapItem->mListObject.push_back(object);
  }
  return true;
}
//-------------------------------------------------------------------------------------------------------
