/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "LoaderObjectCommon.h"

#include <stddef.h>
#include <boost/foreach.hpp>

#include "LoaderListPathID.h"
#include "file_operation.h"
#include "GlobalParams.h"
#include "Logger.h"
#include "BL_Debug.h"
#include "MapXML_Field.h"
#include "StorePathResources.h"

using namespace std;

const char* sNameSettingMap = "main.xml";

TLoaderMap::TLoaderMap()
{
  LoadListMap();
}
//-------------------------------------------------------------
TLoaderMap::~TLoaderMap()
{
  Done();
}
//-------------------------------------------------------------
IBaseObjectCommon* TLoaderMap::LoadObject(unsigned int id_model)
{
  return mMakerObjectCommon->New(id_model);
}
//-------------------------------------------------------------
void TLoaderMap::LoadMap(unsigned int id_map)
{
  string sPath = mMapID[id_map];
  if(sPath.length()==0) return;

  Done();
  // собственно загрузка
}
//-------------------------------------------------------------
void TLoaderMap::LoadListMap()
{
  // открыть файл, содержащий список путей к картам и запомнить в ассоциативный список
  TLoaderListPathID loader;
  char sAbsPath[300];
  FindAbsPath((char*)GetStorePathResources()->GetSecond("map"),sAbsPath,sizeof(sAbsPath));
  if(loader.Load(sAbsPath,&mMapID)==false)
    BL_FIX_BUG();

  PrepareMapPath();
}
//-------------------------------------------------------------
int TLoaderMap::GetCountObject()
{
  return mVectorObject.size();
}
//-------------------------------------------------------------
IBaseObjectCommon* TLoaderMap::Get(int i)
{
  return mVectorObject[i];
}
//-------------------------------------------------------------
void TLoaderMap::Done()
{
  mVectorObject.clear();
}
//-------------------------------------------------------------
void TLoaderMap::PrepareMapPath()
{
  BOOST_FOREACH(TMapIDName::value_type& bit, mMapID)
    bit.second += sNameSettingMap;
}
//-------------------------------------------------------------
void TLoaderMap::Delete(IBaseObjectCommon* pObject)
{
  mMakerObjectCommon->Delete(pObject);
}
//-------------------------------------------------------------
void TLoaderMap::SetMakerObjectCommon(IMakerObjectCommon* pMakerObjectCommon)
{
  mMakerObjectCommon = pMakerObjectCommon;
}
//-------------------------------------------------------------
