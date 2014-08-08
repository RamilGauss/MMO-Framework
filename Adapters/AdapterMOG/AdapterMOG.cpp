/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "LoaderObjectGeneral.h"
#include "AdapterMOG.h"
#include <stddef.h>
#include "Logger.h"
#include "HiTimer.h"

//-----------------------------------------------------------------------------
AdapterMOG::AdapterMOG():
mLoaderObjectGeneral(new TLoaderObjectGeneral)
{
  flgLoadMap               = false;
  flgActiveLoadThread      = false;
}
//--------------------------------------------------------------------
AdapterMOG::~AdapterMOG()
{
  Done();
}
//--------------------------------------------------------------------
//void* Thread(void* p)
//{
  //((TManagerObjectGeneral*)p)->ThreadLoadMap();
  //return NULL;
//}
//--------------------------------------------------------------------
//void TManagerObjectGeneral::ThreadLoadMap()
//{
  /*GlobalLoggerMOC.WriteF_time("Началась загрузка карты.\n");
  flgActiveLoadThread = true;

  mProcentLoadMap = 0;
  CHECK_END
  mLoaderObjectGeneral.LoadMap(mID_map);
  mProcentLoadMap = 15;
  CHECK_END
  AddFromLoaderObjectInCommonList();
  mProcentLoadMap = 55;
  CHECK_END
  AddFromLoaderObjectInMDX();
  mProcentLoadMap = 70;
  CHECK_END
  AddFromLoaderObjectInPrediction();
  mProcentLoadMap = 80;

  CHECK_END
  //---------------------------------------
  NotifyLoadMapEndEvent();
  //---------------------------------------
  flgActiveLoadThread = false;
  
  GlobalLoggerMOC.WriteF_time("Загрузка карты завершена (поток MOC).\n");
  GlobalLoggerMOC.WriteF_time("Ожидание корректирующего пакета.\n");*/
//}
//--------------------------------------------------------------------
void AdapterMOG::LoadMap(unsigned int id_map)
{
  //flgNeedStopThreadLoadMap = false;
  //flgLoadMap               = true;
  //mID_map = id_map;
  //thread = g_thread_create(Thread, this, true, NULL);
}
//--------------------------------------------------------------------
int AdapterMOG::GetProgressLoadMap()
{
  return 100;
}
//--------------------------------------------------------------------
void AdapterMOG::Done()
{
  Clear();
}
//--------------------------------------------------------------------
void AdapterMOG::EndLoadMap()
{
  GetLogger(STR_NAME_MOG)->WriteF_time("Загрузка карты завершена (поток Form).\n");
  mProcentLoadMap          = 100;
  flgLoadMap               = false;
}
//--------------------------------------------------------------
void AdapterMOG::StopLoadMap()// синхронно, придется подождать маленько
{
  GetLogger(STR_NAME_MOG)->WriteF_time("Приказ остановить загрузку карты.\n");
  flgNeedStopThreadLoadMap = true;
}
//-------------------------------------------------------------------------------------------------------------  
void AdapterMOG::Init(PrototypeMakerObjectGeneral* pMakerObjectGeneral)
{
  mLoaderObjectGeneral->SetMakerObjectGeneral(pMakerObjectGeneral);
}
//--------------------------------------------------------------------------------------------------------
void AdapterMOG::Clear()
{
  int cnt = mVectorObject.size();
  for(int i = 0 ; i < cnt ; i++ )
    mLoaderObjectGeneral->Delete(mVectorObject[i]);

  mVectorObject.clear();
}
//--------------------------------------------------------------------------------------------------------
IBaseObjectGeneral* AdapterMOG::CreateObject(unsigned int id_model)
{
  IBaseObjectGeneral* pObject = mLoaderObjectGeneral->LoadObject(id_model);
  AddObject(pObject);
  return pObject;
}
//--------------------------------------------------------------------------------------------------------
void AdapterMOG::AddObject(IBaseObjectGeneral* pObject)
{
  mVectorObject.push_back(pObject);
}
//--------------------------------------------------------
// отдать объект на изменение свойств объекта
IBaseObjectGeneral* AdapterMOG::Get(int index)
{
  BL_ASSERT(mVectorObject.size() > (unsigned int)index);
  IBaseObjectGeneral* pObject = mVectorObject.at(index);
  return pObject;
}
//--------------------------------------------------------
int AdapterMOG::GetCountObject()
{
  return mVectorObject.size();
}
//--------------------------------------------------------
PrototypeBaseModule* AdapterMOG::NewExample()
{
  return new AdapterMOG;
}
//--------------------------------------------------------
void AdapterMOG::DeleteExample(PrototypeBaseModule* ptr)
{
  delete ptr;
}
//--------------------------------------------------------
int AdapterMOG::GetVersionAdapter()
{
  return 1;
}
//--------------------------------------------------------
bool AdapterMOG::Work()
{
  return true;
}
//--------------------------------------------------------
