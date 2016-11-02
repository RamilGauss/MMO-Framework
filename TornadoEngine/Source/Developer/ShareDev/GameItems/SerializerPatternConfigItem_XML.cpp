/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "SerializerPatternConfigItem_XML.h"
#include "IXML.h"
#include <boost/foreach.hpp>

namespace nsSerializerPatternItem_XML
{
  const char* sPatternConfig = "PatternConfig";
  const char* sName          = "name";
  const char* sVariant       = "Variant";
}

using namespace nsSerializerPatternItem_XML;

TSerializerPatternConfigItem_XML::TSerializerPatternConfigItem_XML():
TBaseSerializerItem_XML(sPatternConfig)
{
  mPattern = NULL;
}
//-------------------------------------------------------------------------------------------------------
TSerializerPatternConfigItem_XML::~TSerializerPatternConfigItem_XML()
{

}
//-------------------------------------------------------------------------------------------------------
bool TSerializerPatternConfigItem_XML::Load(TBaseItem* pItem)
{
  mPattern = (TPatternConfigItem*)pItem;

  bool resEnter = EnterByType(mPattern->mName);
  if( resEnter==false )
    return false;

  LoadPropertyPattern();
  return true;
}
//-------------------------------------------------------------------------------------------------------
bool TSerializerPatternConfigItem_XML::Save(TBaseItem* pItem)
{
  mPattern = (TPatternConfigItem*)pItem;
  RemoveSection(mPattern->mName);// грохнуть всю запись, связанную с данным item

  bool resEnter = AddAndEnterByType(mPattern->mName);
  if( resEnter==false )
    return false;

  SavePropertyPattern();
  return mXML->Save();
}
//-------------------------------------------------------------------------------------------------------
void TSerializerPatternConfigItem_XML::LoadPropertyPattern()
{
  int cntVariant = mXML->GetCountSection(sVariant);
  for( int iVariant = 0 ; iVariant < cntVariant ; iVariant++ )
  {
    TPatternConfigItem::TMapStrStr mapStrStr;
    LoadVariant(mapStrStr, iVariant);

    std::string nameVariant = mXML->ReadSectionAttr(sVariant, iVariant, sName);
    mPattern->mMapVariant.insert(TPatternConfigItem::TMapStrMapVT(nameVariant, mapStrStr));
  }
}
//-------------------------------------------------------------------------------------------------------
void TSerializerPatternConfigItem_XML::LoadVariant(TPatternConfigItem::TMapStrStr& mapStrStr, int iVariant )
{
  mapStrStr.clear();
  if( mXML->EnterSection(sVariant, iVariant) )
  {
    int cnt = GetCountProperty();
    for( int i = 0 ; i < cnt ; i++ )
    {
      std::string key, value;
      if( LoadProperty(i, key, value) )
        mapStrStr.insert(TPatternConfigItem::TMapStrStrVT(key, value));
    }
    mXML->LeaveSection();
  }
}
//-------------------------------------------------------------------------------------------------------
void TSerializerPatternConfigItem_XML::SavePropertyPattern()
{
  BOOST_FOREACH(TPatternConfigItem::TMapStrMapVT& bit, mPattern->mMapVariant)
  {
    TAttrInfo attr;
    attr.Name  = sName;
    attr.Value = bit.first;
    if( mXML->AddSectionAndEnter(sVariant, 1, &attr) )
    {
      SaveVariant(bit.second);
      mXML->LeaveSection();
    }
  }
}
//-------------------------------------------------------------------------------------------------------
void TSerializerPatternConfigItem_XML::SaveVariant(TPatternConfigItem::TMapStrStr& mapStrStr )
{
  BOOST_FOREACH(TPatternConfigItem::TMapStrStrVT& bit, mapStrStr )
  {
    std::string key   = bit.first;
    std::string value = bit.second;
    SaveProperty(key, value);
  }
}
//-------------------------------------------------------------------------------------------------------
