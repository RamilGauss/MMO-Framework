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
  const char* sNameTableSound = "name";
	const char* sFog         		= "Fog";
	const char* sMode				 		= "mode";
	const char* sColourRed   		= "colourRed";
	const char* sColourGreen 		= "colourGreen";
	const char* sColourBlue  		= "colourBlue";
	const char* sExpDensity	 		= "expDensity";
	const char* sLinearStart 		= "linearStart";
	const char* sLinearEnd	 		= "linearEnd";
  const char* sBackgroundColour = "BackgroundColour";
	const char* sAmbientLight   = "AmbientLight";
	const char* sSet					  = "Set";
	const char* sObject				  = "Object";
	const char* sBaseProperty	  = "BaseProperty";
	const char* sIdentity			  = "Identity";
	const char* sID  					  = "ID";
  const char* sPattern        = "Pattern";
	const char* sPosition			  = "Position";
	const char* sRotationQuaternion = "RotationQuaternion";
	const char* sParameterMap   = "ParameterMap";
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
	LoadFog();
  LoadBackgroundColour();
  LoadAmbientLight();
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
	SaveFog();
  SaveBackgroundColour();
	SaveAmbientLight();
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
void TSerializerMapItem_XML::LoadBackgroundColour()
{
  if(mXML->EnterSection(sBackgroundColour, 0))
  {
    LoadColour(mMapItem->mBackgroundColour);
    mXML->LeaveSection();
  }
}
//-------------------------------------------------------------------------------------------------------
void TSerializerMapItem_XML::LoadAmbientLight()
{
	if(mXML->EnterSection(sAmbientLight, 0))
	{
		LoadColour(mMapItem->mAmbientLight);
		mXML->LeaveSection();
	}
}
//-------------------------------------------------------------------------------------------------------
void TSerializerMapItem_XML::LoadFog()
{
	if(mXML->EnterSection(sFog, 0))
	{
		int cntProperty = GetCountProperty();
		for( int i = 0 ; i < cntProperty ; i++ )
		{
			std::string key, value;
			if( LoadProperty(i,key, value)==false )
				continue;
			if( key==sMode )
				mMapItem->mFog.mode = boost::lexical_cast<int>(value);
			if( key==sColourRed)
				mMapItem->mFog.colour.x = boost::lexical_cast<float>(value);
			if( key==sColourGreen)
				mMapItem->mFog.colour.y = boost::lexical_cast<float>(value);
			if( key==sColourBlue)
				mMapItem->mFog.colour.z = boost::lexical_cast<float>(value);
			if( key==sExpDensity)
				mMapItem->mFog.expDensity = boost::lexical_cast<float>(value);
			if( key==sLinearStart)
				mMapItem->mFog.linearStart = boost::lexical_cast<float>(value);
			if( key==sLinearEnd)
				mMapItem->mFog.linearEnd = boost::lexical_cast<float>(value);
		}
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
void TSerializerMapItem_XML::SaveBackgroundColour()
{
  if(mXML->AddSectionAndEnter(sBackgroundColour))
  {
    SaveVector3ByProperty(mMapItem->mBackgroundColour);
    mXML->LeaveSection();
  }
}
//-------------------------------------------------------------------------------------------------------
void TSerializerMapItem_XML::SaveAmbientLight()
{
	if(mXML->AddSectionAndEnter(sAmbientLight))
	{
		SaveVector3ByProperty(mMapItem->mAmbientLight);
		mXML->LeaveSection();
	}
}
//-------------------------------------------------------------------------------------------------------
void TSerializerMapItem_XML::SaveFog()
{
	if(mXML->AddSectionAndEnter(sFog))
	{
		std::string key, value;
		key   = sMode;
		value = boost::lexical_cast<std::string>(mMapItem->mFog.mode);
		SaveProperty(key, value);
		key   = sColourRed;
		value = boost::lexical_cast<std::string>(mMapItem->mFog.colour.x);
		SaveProperty(key, value);
		key   = sColourGreen;
		value = boost::lexical_cast<std::string>(mMapItem->mFog.colour.y);
		SaveProperty(key, value);
		key   = sColourBlue;
		value = boost::lexical_cast<std::string>(mMapItem->mFog.colour.z);
		SaveProperty(key, value);
		key   = sExpDensity;
		value = boost::lexical_cast<std::string>(mMapItem->mFog.expDensity);
		SaveProperty(key, value);
		key   = sLinearStart;
		value = boost::lexical_cast<std::string>(mMapItem->mFog.linearStart);
		SaveProperty(key, value);
		key   = sLinearEnd;
		value = boost::lexical_cast<std::string>(mMapItem->mFog.linearEnd);
		SaveProperty(key, value);

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
    if(mXML->EnterSection(sRotationQuaternion,0))
    {
      nsMathTools::TVector4 rot;
      if(LoadVector4ByProperty(rot))
        object.rotationQuaternion = rot;

      mXML->LeaveSection();
    }
		mXML->LeaveSection();
	}

  // внутренние состояние
  if(mXML->EnterSection(sParameterMap,0))
  {
    int cntProperty = GetCountProperty();
    for( int iProperty = 0 ; iProperty < cntProperty ; iProperty++ )
    {
      std::string key, value;
      if(LoadProperty(iProperty, key, value))
        object.parameterMap.insert(TMapItem::TMapStrStrVT(key,value));
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
    if(mXML->AddSectionAndEnter(sRotationQuaternion))
    {
      SaveVector4ByProperty(object.rotationQuaternion);
      mXML->LeaveSection();
    }
    mXML->LeaveSection();
  }

  // внутренние свойства
  if(mXML->AddSectionAndEnter(sParameterMap))
  {
    BOOST_FOREACH(TMapItem::TMapStrStrVT& KeyValue, object.parameterMap)
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

