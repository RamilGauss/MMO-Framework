/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "SerializerPatternItem_XML.h"
#include "IXML.h"
#include <boost/foreach.hpp>

namespace nsSerializerPatternItem_XML
{
  const char* sPattern      = "Pattern";
  const char* sName         = "name";
  const char* sVariant      = "Variant";
}

using namespace nsSerializerPatternItem_XML;

TSerializerPatternItem_XML::TSerializerPatternItem_XML():
TBaseSerializerItem_XML(sPattern)
{
  mPattern = NULL;
}
//-------------------------------------------------------------------------------------------------------
TSerializerPatternItem_XML::~TSerializerPatternItem_XML()
{

}
//-------------------------------------------------------------------------------------------------------
bool TSerializerPatternItem_XML::Load(TBaseItem* pItem)
{
  mPattern = (TPatternItem*)pItem;

  bool resEnter = EnterByType(mPattern->mName);
  if(resEnter==false)
    return false;

  LoadPropertyPattern();
  return true;
}
//-------------------------------------------------------------------------------------------------------
bool TSerializerPatternItem_XML::Save(TBaseItem* pItem)
{
  mPattern = (TPatternItem*)pItem;
  RemoveSection(mPattern->mName);// грохнуть всю запись, связанную с данным item

  bool resEnter = AddAndEnterByType(mPattern->mName);
  if(resEnter==false)
    return false;

  SavePropertyPattern();
  return mXML->Save();
}
//-------------------------------------------------------------------------------------------------------
void TSerializerPatternItem_XML::LoadPropertyPattern()
{
  int cntVariant = mXML->GetCountSection(sVariant);
  for( int iVariant = 0 ; iVariant < cntVariant ; iVariant++ )
  {
    TPatternItem::TMapStrStr mapStrStr;
    LoadVariant(mapStrStr, iVariant);

    std::string nameVariant = mXML->ReadSectionAttr(sVariant, iVariant, sName);
    mPattern->mMapVariant.insert(TPatternItem::TMapStrMapVT(nameVariant, mapStrStr));
  }
}
//-------------------------------------------------------------------------------------------------------
void TSerializerPatternItem_XML::LoadVariant(TPatternItem::TMapStrStr& mapStrStr, int iVariant )
{
  mapStrStr.clear();
  if(mXML->EnterSection(sVariant, iVariant))
  {
    int cnt = GetCountProperty();
    for( int i = 0 ; i < cnt ; i++ )
    {
      std::string key, value;
      if( LoadProperty(i, key, value) )
        mapStrStr.insert(TPatternItem::TMapStrStrVT(key, value));
    }
    mXML->LeaveSection();
  }
}
//-------------------------------------------------------------------------------------------------------
void TSerializerPatternItem_XML::SavePropertyPattern()
{
  BOOST_FOREACH(TPatternItem::TMapStrMapVT& bit, mPattern->mMapVariant)
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
void TSerializerPatternItem_XML::SaveVariant(TPatternItem::TMapStrStr& mapStrStr )
{
  BOOST_FOREACH(TPatternItem::TMapStrStrVT& bit, mapStrStr )
  {
    std::string key   = bit.first;
    std::string value = bit.second;
    SaveProperty(key, value);
  }
}
//-------------------------------------------------------------------------------------------------------
