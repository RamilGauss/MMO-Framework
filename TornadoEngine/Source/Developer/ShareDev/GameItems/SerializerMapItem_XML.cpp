/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "SerializerMapItem_XML.h"
#include "MapItem.h"
#include "IXML.h"


namespace nsSerializerMapItem_XML
{
  const char* sMap           = "Map";
	const char* sTableSound    = "TableSound";
	const char* sSet					 = "Set";
	const char* sObject				 = "Object";
	const char* sBaseProperty	 = "BaseProperty";
	const char* sIdentity			 = "Identity";
	const char* sType					 = "Type";
	const char* sName					 = "Name";
	const char* sPosition			 = "Position";
	const char* sRotation			 = "Rotation";
	const char* sInternalState = "InternalState";
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
	SaveSet();
	SaveScenario();
  return mXML->Save();
}
//-------------------------------------------------------------------------------------------------------
void TSerializerMapItem_XML::LoadTableSound()
{
  mMapItem->mNameTableSound = mXML->ReadSectionAttr(sTableSound, 0, sName);
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
				LoadObject();
				mXML->LeaveSection();
			}
		}
		mXML->LeaveSection();
	}
}
//-------------------------------------------------------------------------------------------------------
void TSerializerMapItem_XML::LoadScenario()
{

}
//-------------------------------------------------------------------------------------------------------
void TSerializerMapItem_XML::SaveTableSound()
{

}
//-------------------------------------------------------------------------------------------------------
void TSerializerMapItem_XML::SaveSet()
{

}
//-------------------------------------------------------------------------------------------------------
void TSerializerMapItem_XML::SaveScenario()
{

}
//-------------------------------------------------------------------------------------------------------
void TSerializerMapItem_XML::LoadObject()
{
	if(mXML->EnterSection(sBaseProperty,0))
	{

		mXML->LeaveSection();
	}
}
//-------------------------------------------------------------------------------------------------------
