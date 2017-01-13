/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "StorageGameItem_XML.h"
#include "BaseItem.h"
#include "ManagerSerializerItem_XML.h"
#include "ManagerCacheItem_XML.h"
#include "MakerXML.h"
#include "IXML.h"
#include "BL_Debug.h"

TStorageGameItem_XML::TStorageGameItem_XML()
{
  TMakerXML makerXML;
  mXML = makerXML.New();
}
//---------------------------------------------------------------
TStorageGameItem_XML::~TStorageGameItem_XML()
{
  TMakerXML makerXML;
  makerXML.Delete(mXML);
}
//---------------------------------------------------------------
bool TStorageGameItem_XML::Init(std::string& name_file_xml)
{
  bool resLoad = mXML->Load(name_file_xml.data());
  BL_ASSERT(resLoad);

  mMngSerializer.reset(new TManagerSerializerItem_XML);
  mMngCache.reset(new TManagerCacheItem_XML);

  mMngSerializer->Init(mXML);
  mMngCache->Init(mXML);
  return resLoad;
}
//---------------------------------------------------------------
bool TStorageGameItem_XML::Save(TBaseItem* pItem)
{
  if( pItem==NULL )
    return false;

  std::string strType;
  if( mMngSerializer->Type2Str(pItem->mType, strType)==false )
    return false;
  bool isExist = mMngCache->IsExist(strType, pItem->mName);
  bool res = mMngSerializer->Save(pItem);
  // если удалось сохранить и итэма раньше не было, то значит произошло добавление
  // нужно перекешировать заново
  if( res && (isExist==false) )
    mMngCache->Init(mXML);
  return res;
}
//---------------------------------------------------------------
bool TStorageGameItem_XML::Delete(int type, std::string& name)
{
  bool res = mMngSerializer->Remove(type, name);
  if( res )
  {
    res = mMngSerializer->Save();
    mMngCache->Init(mXML);
  }
  return res;
}
//---------------------------------------------------------------
bool TStorageGameItem_XML::Delete(TBaseItem* pItem)
{
  if( pItem==NULL )
    return false;
  return Delete(pItem->mType, pItem->mName);
}
//---------------------------------------------------------------
bool TStorageGameItem_XML::Load(TBaseItem* pItem)
{
  if( pItem==NULL )
    return false;
  return mMngSerializer->Load(pItem);
}
//---------------------------------------------------------------
bool TStorageGameItem_XML::IsExist(int type, std::string& name)
{
  std::string strType;
  if( mMngSerializer->Type2Str(type, strType)==false )
    return false;
  return mMngCache->IsExist(strType, name);
}
//---------------------------------------------------------------
int TStorageGameItem_XML::GetCountByType( int type )
{
  std::string strType;
  if( mMngSerializer->Type2Str(type, strType)==false )
    return 0;
  return mMngCache->GetCountByStrType(strType);
}
//---------------------------------------------------------------
bool TStorageGameItem_XML::GetNameByType( int type, int index, std::string& name )
{
  std::string strType;
  if( mMngSerializer->Type2Str(type, strType)==false )
    return false;
  return mMngCache->GetNameByIndex(strType, index, name);
}
//---------------------------------------------------------------
