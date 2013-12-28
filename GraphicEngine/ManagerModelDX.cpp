/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ManagerModelDX.h"
#include <d3d9.h>
#include "ModelDX.h"
#include "GlobalParams.h"
#include "LoadFromHDD.h"
#include "Logger.h"
#include "BL_Debug.h"
#include "LoaderListPathID.h"
#include <atlconv.h>
#include "file_operation.h"
#include "StorePathResources.h"
#include "MapXML_Field.h"
#include "IGraphicEngine.h"

#include <boost/foreach.hpp>

using namespace std;

TManagerModelDX::TManagerModelDX()
{
  mManagerResourceDX = NULL;
  mD3dDevice = NULL;
  LoadListPath();
}
//--------------------------------------------------------------------------------------
TManagerModelDX::~TManagerModelDX()
{
  Done();
}
//--------------------------------------------------------------------------------------
TModelDX* TManagerModelDX::Load(unsigned int id)
{
  GetLogger(STR_NAME_GE)->WriteF_time("Начало загрузки модели ID=%u\n",id);

  string sPath = mMapPathModel[id];
  TModelDX* pModel = NULL;
  if(sPath.length())
  {
    pModel = new TModelDX(mManagerResourceDX);
    pModel->SetID(id);
    USES_CONVERSION;
    if(pModel->Init(mD3dDevice,A2W(sPath.data()))==false)
    {
      GetLogger(STR_NAME_GE)->WriteF_time("Не удалось загрузить модель sPath=%s, id=%u\n",sPath.data(),id);
      delete pModel;
      return NULL;
    }
    pModel->ResetDevice();
    pModel->SortPartByAlphabetic();// сортировать
    mMapLoadedModel[id] = pModel;
  }
  else
  {
    GetLogger(STR_NAME_GE)->WriteF_time("Не удалось найти модель sPath=%s, id=%u\n",sPath.data(),id);
    BL_FIX_BUG();
  }
  
  GetLogger(STR_NAME_GE)->WriteF_time("Конец загрузки модели ID=%u\n",id);
  return pModel;
}
//--------------------------------------------------------------------------------------
void TManagerModelDX::DestroyModel()
{
  BOOST_FOREACH(TMapUintPtr::value_type& bit,mMapLoadedModel)
  {
    if(bit.second)// TModelDX*
      bit.second->Destroy();
    delete bit.second;
  }
  mMapLoadedModel.clear();
}
//--------------------------------------------------------------------------------------
void TManagerModelDX::LostDevice()
{
  BOOST_FOREACH(TMapUintPtr::value_type& bit,mMapLoadedModel)
  {
    if(bit.second)// TModelDX*
      bit.second->LostDevice();
  }
}
//--------------------------------------------------------------------------------------
void TManagerModelDX::ResetDevice()
{
  BOOST_FOREACH(TMapUintPtr::value_type& bit,mMapLoadedModel)
  {
    if(bit.second)// TModelDX*
      bit.second->ResetDevice();
  }
}
//--------------------------------------------------------------------------------------
bool TManagerModelDX::LoadListPath()
{
  TLoaderListPathID loader;
  char sAbsPath[300];
  FindAbsPath((char*)GetStorePathResources()->GetSecond("model"),sAbsPath,sizeof(sAbsPath));
  if(loader.Load(sAbsPath,&mMapPathModel)==false)
  {
    GetLogger(STR_NAME_GE)->WriteF_time("Не удалось загрузить список моделей.\n");
    BL_FIX_BUG();
    return false;
  }
  
  PrepareForDX();

  GetLogger(STR_NAME_GE)->WriteF_time("Список моделей загружен успешно.\n");
  return true;
}
//--------------------------------------------------------------------------------------
void TManagerModelDX::Done()
{
  mMapPathModel.clear();
  DestroyModel();
}
//--------------------------------------------------------------------------------------
TModelDX* TManagerModelDX::Find(unsigned int id)
{
  // 1. либо ищем в списке загруженных
  TModelDX* pFindModel = mMapLoadedModel[id];
  if(pFindModel)
    return pFindModel;
  // 2. либо загружаем
  TModelDX* pLoadedModel = Load(id);
    return pLoadedModel;
}
//--------------------------------------------------------------------------------------
void TManagerModelDX::PrepareForDX()
{
  BOOST_FOREACH(TMapUintStr::value_type& bit,mMapPathModel)
    bit.second += "DX\\main.ini";
}
//--------------------------------------------------------------------------------------
