/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "SerializerMapItem_XML.h"
#include "MapItem.h"
#include "IXML.h"

#include <boost/foreach.hpp>
#include <boost/lexical_cast.hpp>

namespace nsSerializerMapItem_XML
{
  const char* sMap                  = "Map";
  const char* sNameTableSound       = "name";
  const char* sSet                  = "Set";
  const char* sObject                = "Object";
  const char* sIdentity              = "Identity";
  const char* sID                    = "ID";
  const char* sPattern              = "Pattern";
  const char* sPosition              = "Position";
  const char* sPatternConfig         = "PatternConfig";
  const char* sNamePattern           = "Name";
  const char* sVariantPatternConfig  = "Variant";
  const char* sOrientation           = "Orientation";
  // reserve
  const char* sScenario             = "Scenario";
}

using namespace nsSerializerMapItem_XML;

TSerializerMapItem_XML::TSerializerMapItem_XML():
TBaseSerializerItem_XML(sMap)
{
  mMapItem = NULL;
}
//-------------------------------------------------------------------------------------------------------
TSerializerMapItem_XML::~TSerializerMapItem_XML()
{

}
//-------------------------------------------------------------------------------------------------------
bool TSerializerMapItem_XML::Load(TBaseItem* pItem)
{
  mMapItem = (TMapItem*)pItem;

  bool resEnter = EnterByType(mMapItem->mName);
  if(resEnter==false)
    return false;

  LoadSet();
  LoadScenario();
  return true;
}
//-------------------------------------------------------------------------------------------------------
bool TSerializerMapItem_XML::Save(TBaseItem* pItem)
{
  mMapItem = (TMapItem*)pItem;
  RemoveSection(mMapItem->mName);// грохнуть всю запись, связанную с данным item

  bool resEnter = AddAndEnterByType(mMapItem->mName);
  if(resEnter==false)
    return false;

  SaveSet();
  SaveScenario();
  return mXML->Save();
}
//-------------------------------------------------------------------------------------------------------
void TSerializerMapItem_XML::LoadSet()
{
  if(mXML->EnterSection(sSet,0))
  {
    int cntObject = mXML->GetCountSection(sObject);
    for( int iObject = 0 ; iObject < cntObject ; iObject++ )
    {
      if(mXML->EnterSection(sObject, iObject))
      {
        TMapItem::TObject object;
        LoadObject(object);
        mMapItem->mListObject.push_back(object);

        mXML->LeaveSection();
      }
    }
    mXML->LeaveSection();
  }
}
//-------------------------------------------------------------------------------------------------------
void TSerializerMapItem_XML::LoadScenario()
{
  if(mXML->EnterSection(sScenario,0))
  {
    // reserve
    mXML->LeaveSection();
  }
}
//-------------------------------------------------------------------------------------------------------
void TSerializerMapItem_XML::SaveSet()
{
  if(mXML->AddSectionAndEnter(sSet))
  {
    BOOST_FOREACH( TMapItem::TObject& object, mMapItem->mListObject )
    {
      if(mXML->AddSectionAndEnter(sObject))
      {
        SaveObject(object);
        mXML->LeaveSection();
      }
    }
    mXML->LeaveSection();
  }
}
//-------------------------------------------------------------------------------------------------------
void TSerializerMapItem_XML::SaveScenario()
{
  if(mXML->AddSectionAndEnter(sScenario))
  {
    // reserve
    mXML->LeaveSection();
  }
}
//-------------------------------------------------------------------------------------------------------
void TSerializerMapItem_XML::LoadObject(TMapItem::TObject& object)
{
  if(mXML->EnterSection(sIdentity,0)) 
  {
    int cntProperty = GetCountProperty();
    for( int iProperty = 0 ; iProperty < cntProperty ; iProperty++ )
    {
      std::string key, value;
      if(LoadProperty(iProperty, key, value))
      {
        if(key==sPattern)
          object.namePattern = value;
        if(key==sID)
          object.id = boost::lexical_cast<int>(value.data());
      }
    }
    mXML->LeaveSection();
  }
  // позиция и ориентация
  if(mXML->EnterSection(sPosition,0))
  {
    nsMathTools::TVector3 pos;
    if(LoadVector3ByProperty(pos))
      object.position = pos;

    mXML->LeaveSection();
  }
  if(mXML->EnterSection(sOrientation,0))
  {
    LoadOrientationByProperty(object.orientation);
    mXML->LeaveSection();
  }

  // patternConfig
  if(mXML->EnterSection(sPatternConfig,0))
  {
    int cntProperty = GetCountProperty();
    for( int iProperty = 0 ; iProperty < cntProperty ; iProperty++ )
    {
      std::string key, value;
      LoadProperty(iProperty, key, value);
      if( key==sNamePattern )
        object.patternConfig.name = value;
      if( key==sVariantPatternConfig )
        object.patternConfig.nameVariant = value;
    }
    mXML->LeaveSection();
  }
}
//-------------------------------------------------------------------------------------------------------
void TSerializerMapItem_XML::SaveObject(TMapItem::TObject& object)
{
  if(mXML->AddSectionAndEnter(sIdentity)) 
  {
    std::string key, value;
    key   = sPattern;
    value = object.namePattern;
    SaveProperty(key, value);

    key   = sID;
    value = boost::lexical_cast<std::string>(object.id);
    SaveProperty(key, value);
    mXML->LeaveSection();
  }
  // позиция и ориентация
  if(mXML->AddSectionAndEnter(sPosition))
  {
    SaveVector3ByProperty(object.position);
    mXML->LeaveSection();
  }
  if(mXML->AddSectionAndEnter(sOrientation))
  {
    SaveOrientationByProperty(object.orientation);
    mXML->LeaveSection();
  }

  // внутренние свойства
  if(mXML->AddSectionAndEnter(sPatternConfig))
  {
    std::string key, value;
    key   = sNamePattern;
    value = object.patternConfig.name;
    SaveProperty(key, value);

    key   = sVariantPatternConfig;
    value = object.patternConfig.nameVariant;
    SaveProperty(key, value);

    mXML->LeaveSection();
  }
}
//-------------------------------------------------------------------------------------------------------

