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
  const char* sMap            = "Map";
}

using namespace nsSerializerMapItem_XML;

TSerializerMapItem_XML::TSerializerMapItem_XML():
TBaseSerializerItem_XML(sMap)
{
  mMap = NULL;
}
//-------------------------------------------------------------------------------------------------------
TSerializerMapItem_XML::~TSerializerMapItem_XML()
{

}
//-------------------------------------------------------------------------------------------------------
bool TSerializerMapItem_XML::Load(TBaseItem* pItem)
{
  mMap = (TMapItem*)pItem;

  bool resEnter = EnterByType(mMap->mName);
  if(resEnter==false)
    return false;

  return true;
}
//-------------------------------------------------------------------------------------------------------
bool TSerializerMapItem_XML::Save(TBaseItem* pItem)
{
  mMap = (TMapItem*)pItem;
  RemoveSection(mMap->mName);// грохнуть всю запись, связанную с данным item

  bool resEnter = EnterByType(mMap->mName);
  if(resEnter==false)
    return false;

  return mXML->Save();
}
//-------------------------------------------------------------------------------------------------------

