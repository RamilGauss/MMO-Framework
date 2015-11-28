/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "SerializerModelItem_XML.h"
#include "ModelItem.h"
#include "IXML.h"

namespace nsSerializerModelItem_XML
{
  const char* sModel            = "Model";
}

using namespace nsSerializerModelItem_XML;

TSerializerModelItem_XML::TSerializerModelItem_XML():
TBaseSerializerItem_XML(sModel)
{
  mModel = NULL;
}
//-------------------------------------------------------------------------------------------------------
TSerializerModelItem_XML::~TSerializerModelItem_XML()
{

}
//-------------------------------------------------------------------------------------------------------
bool TSerializerModelItem_XML::Load(TBaseItem* pItem)
{
  mModel = (TModelItem*)pItem;

  bool resEnter = EnterByType(mModel->mName);
  if(resEnter==false)
    return false;

  return true;
}
//-------------------------------------------------------------------------------------------------------
bool TSerializerModelItem_XML::Save(TBaseItem* pItem)
{
  mModel = (TModelItem*)pItem;
  RemoveSection(mModel->mName);// грохнуть всю запись, связанную с данным item

  bool resEnter = EnterByType(mModel->mName);
  if(resEnter==false)
    return false;

  return mXML->Save();
}
//-------------------------------------------------------------------------------------------------------

