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
  const char* sMap            = "Map";
	const char* sTableSound     = "TableSound";
  const char* sGravity        = "Gravity";
  const char* sCameraUp       = "CameraUp";
  const char* sNameTableSound = "name";
	const char* sSet					  = "Set";
	const char* sObject				  = "Object";
	const char* sBaseProperty	  = "BaseProperty";
	const char* sIdentity			  = "Identity";
	const char* sType					  = "Type";
	const char* sID  					  = "ID";
	const char* sPosition			  = "Position";
	const char* sRotation			  = "Rotation";
	const char* sInternalState  = "InternalState";
  // reserve
	const char* sScenario       = "Scenario";
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

	LoadTableSound();
  LoadGravity();
  LoadCameraUp();
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

	SaveTableSound();
  SaveGravity();
  SaveCameraUp();
	SaveSet();
	SaveScenario();
  return mXML->Save();
}
//-------------------------------------------------------------------------------------------------------
void TSerializerMapItem_XML::LoadTableSound()
{
  mMapItem->mNameTableSound = mXML->ReadSectionAttr(sTableSound, 0, sNameTableSound);
}
//-------------------------------------------------------------------------------------------------------
void TSerializerMapItem_XML::LoadGravity()
{
  if(mXML->EnterSection(sGravity, 0))
  {
    LoadVector3ByProperty(mMapItem->mGravity);
    mXML->LeaveSection();
  }
}
//-------------------------------------------------------------------------------------------------------
void TSerializerMapItem_XML::LoadCameraUp()
{
  if(mXML->EnterSection(sCameraUp, 0))
  {
    LoadVector3ByProperty(mMapItem->mCameraUp);
    mXML->LeaveSection();
  }
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
void TSerializerMapItem_XML::SaveTableSound()
{
  TAttrInfo attr;
  attr.Name  = sNameTableSound;
  attr.Value = mMapItem->mNameTableSound;

  mXML->AddSection(sTableSound, 1, &attr);
}
//-------------------------------------------------------------------------------------------------------
void TSerializerMapItem_XML::SaveGravity()
{
  if(mXML->AddSectionAndEnter(sGravity))
  {
    SaveVector3ByProperty(mMapItem->mGravity);
    mXML->LeaveSection();
  }
}
//-------------------------------------------------------------------------------------------------------
void TSerializerMapItem_XML::SaveCameraUp()
{
  if(mXML->AddSectionAndEnter(sCameraUp))
  {
    SaveVector3ByProperty(mMapItem->mCameraUp);
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
	if(mXML->EnterSection(sBaseProperty,0))
	{
    // базовые свойства
    if(mXML->EnterSection(sIdentity,0)) 
    {
      int cntProperty = GetCountProperty();
      for( int iProperty = 0 ; iProperty < cntProperty ; iProperty++ )
      {
        std::string key, value;
        if(LoadProperty(iProperty, key, value))
        {
          if(key==sType)
            object.type = value;
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
    if(mXML->EnterSection(sRotation,0))
    {
      nsMathTools::TVector3 rot;
      if(LoadVector3ByProperty(rot))
        object.rotation = rot;

      mXML->LeaveSection();
    }
		mXML->LeaveSection();
	}

  // внутренние состояние
  if(mXML->EnterSection(sInternalState,0))
  {
    int cntProperty = GetCountProperty();
    for( int iProperty = 0 ; iProperty < cntProperty ; iProperty++ )
    {
      std::string key, value;
      if(LoadProperty(iProperty, key, value))
        object.internalState.insert(TMapItem::TMapStrStrVT(key,value));
    }
    mXML->LeaveSection();
  }
}
//-------------------------------------------------------------------------------------------------------
void TSerializerMapItem_XML::SaveObject(TMapItem::TObject& object)
{
  if(mXML->AddSectionAndEnter(sBaseProperty))
  {
    // базовые свойства
    if(mXML->AddSectionAndEnter(sIdentity)) 
    {
      std::string key, value;
      key   = sType;
      value = object.type;
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
    if(mXML->AddSectionAndEnter(sRotation))
    {
      SaveVector3ByProperty(object.rotation);
      mXML->LeaveSection();
    }
    mXML->LeaveSection();
  }

  // внутренние свойства
  if(mXML->AddSectionAndEnter(sInternalState))
  {
    BOOST_FOREACH(TMapItem::TMapStrStrVT& KeyValue, object.internalState)
    {
      std::string key, value;
      key   = KeyValue.first;
      value = KeyValue.second;
      SaveProperty(key, value);
    }
    mXML->LeaveSection();
  }
}
//-------------------------------------------------------------------------------------------------------

