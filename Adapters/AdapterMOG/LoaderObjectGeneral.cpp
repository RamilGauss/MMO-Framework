/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "LoaderObjectGeneral.h"

#include <stddef.h>
#include <boost/foreach.hpp>

#include "LoaderListPathID.h"
#include "file_operation.h"
#include "Logger.h"
#include "BL_Debug.h"
#include "MapXML_Field.h"
#include "StorePathResources.h"
#include "PrototypeMakerObjectGeneral.h"

using namespace std;

const char* sNameSettingMap = "main.xml";

TLoaderObjectGeneral::TLoaderObjectGeneral()
{
  LoadListMap();
}
//-------------------------------------------------------------
TLoaderObjectGeneral::~TLoaderObjectGeneral()
{
  Done();
}
//-------------------------------------------------------------
IBaseObjectGeneral* TLoaderObjectGeneral::LoadObject(unsigned int id_model)
{
  return mMakerObjectGeneral->New(id_model);
}
//-------------------------------------------------------------
void TLoaderObjectGeneral::LoadMap(unsigned int id_map)
{
  string sPath = mMapID[id_map];
  if(sPath.length()==0) return;

  Done();
  // собственно загрузка
}
//-------------------------------------------------------------
void TLoaderObjectGeneral::LoadListMap()
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
int TLoaderObjectGeneral::GetCountObject()
{
  return mVectorObject.size();
}
//-------------------------------------------------------------
IBaseObjectGeneral* TLoaderObjectGeneral::Get(int i)
{
  return mVectorObject[i];
}
//-------------------------------------------------------------
void TLoaderObjectGeneral::Done()
{
  mVectorObject.clear();
}
//-------------------------------------------------------------
void TLoaderObjectGeneral::PrepareMapPath()
{
  BOOST_FOREACH(TMapIDName::value_type& bit, mMapID)
    bit.second += sNameSettingMap;
}
//-------------------------------------------------------------
void TLoaderObjectGeneral::Delete(IBaseObjectGeneral* pObject)
{
  mMakerObjectGeneral->Delete(pObject);
}
//-------------------------------------------------------------
void TLoaderObjectGeneral::SetMakerObjectGeneral(PrototypeMakerObjectGeneral* pMakerObjectGeneral)
{
  mMakerObjectGeneral = pMakerObjectGeneral;
}
//-------------------------------------------------------------
