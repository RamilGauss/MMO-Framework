/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "SerializerPatternConfigItem_Binary.h"
#include "FactoryGameItem.h"
#include "PatternConfigItem.h"
#include "ShareMisc.h"

TSerializerPatternConfigItem_Binary::TSerializerPatternConfigItem_Binary():
TBaseSerializerItem_Binary(TFactoryGameItem::PatternConfig)
{

}
//-------------------------------------------------------------------------------------------------------
TSerializerPatternConfigItem_Binary::~TSerializerPatternConfigItem_Binary()
{

}
//-------------------------------------------------------------------------------------------------------
void TSerializerPatternConfigItem_Binary::PackItem(TBaseItem* pItem, TContainerRise& cBinOut)
{
  TPatternConfigItem* pPatternConfigItem = (TPatternConfigItem*)pItem;
  Reset();

  PushType();
  PushStr(pPatternConfigItem->mName);
  PushStr(pPatternConfigItem->mComment);
  Push(pPatternConfigItem->mMapVariant.size());
  for( auto& mapVariant : pPatternConfigItem->mMapVariant )
  {
    std::string nameVariant = mapVariant.first;
    PushStr(nameVariant);
    Push(mapVariant.second.size());
    for( auto& nameValue : mapVariant.second)
    {
      std::string name = nameValue.first;
      PushStr(name);
      std::string value = nameValue.second;
      PushStr(value);
    }
  }

  Collect(cBinOut);
}
//-------------------------------------------------------------------------------------------------------
bool TSerializerPatternConfigItem_Binary::UnpackItem(TBaseItem* pItem, void* pIn, int sizeIn)
{
  TPatternConfigItem* pPatternConfigItem = (TPatternConfigItem*)pItem;
  BeginUnpack((char*)pIn, sizeIn);

  RET_FALSE( PopType() )
  RET_FALSE( PopStr(pPatternConfigItem->mName) )

  RET_FALSE( PopStr(pPatternConfigItem->mComment) )

  TPatternConfigItem::TMapStrMap::size_type cntVariant;
  RET_FALSE( Pop(cntVariant) )
  for( int iVariant = 0 ; iVariant < int(cntVariant) ; iVariant++ )
  {
    std::string nameVariant;
    RET_FALSE( PopStr(nameVariant) )
    TPatternConfigItem::TMapStrStr mapNameValue;
    TPatternConfigItem::TMapStrStr::size_type cntValue;
    RET_FALSE( Pop(cntValue) )
    for( int iValue = 0 ; iValue < int(cntValue) ; iValue++ )
    {
      std::string name;
      RET_FALSE( PopStr(name) )
      std::string value;
      RET_FALSE( PopStr(value) )

      mapNameValue.insert(TPatternConfigItem::TMapStrStrVT(name,value));
    }
    pPatternConfigItem->mMapVariant.
      insert(TPatternConfigItem::TMapStrMapVT(nameVariant,mapNameValue));
  }
  return true;
}
//-------------------------------------------------------------------------------------------------------
