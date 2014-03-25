/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ManagerObjectGeneral.h"
#include <stddef.h>
#include "Logger.h"
#include "HiTimer.h"

//-----------------------------------------------------------------------------
TManagerObjectGeneral::TManagerObjectGeneral()
{
  flgLoadMap               = false;
  flgActiveLoadThread      = false;
}
//--------------------------------------------------------------------
TManagerObjectGeneral::~TManagerObjectGeneral()
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
void TManagerObjectGeneral::LoadMap(unsigned int id_map)
{
  //flgNeedStopThreadLoadMap = false;
  //flgLoadMap               = true;
  //mID_map = id_map;
  //thread = g_thread_create(Thread, this, true, NULL);
}
//--------------------------------------------------------------------
int TManagerObjectGeneral::GetProgressLoadMap()
{
  return 100;
}
//--------------------------------------------------------------------
void TManagerObjectGeneral::Done()
{
  Clear();
}
//--------------------------------------------------------------------
void TManagerObjectGeneral::EndLoadMap()
{
  GetLogger("MOC")->WriteF_time("Загрузка карты завершена (поток Form).\n");
  mProcentLoadMap          = 100;
  flgLoadMap               = false;
}
//--------------------------------------------------------------
void TManagerObjectGeneral::StopLoadMap()// синхронно, придется подождать маленько
{
  GetLogger("MOC")->WriteF_time("Приказ остановить загрузку карты.\n");
  flgNeedStopThreadLoadMap = true;
}
//-------------------------------------------------------------------------------------------------------------  
void TManagerObjectGeneral::Init(IMakerObjectGeneral* pMakerObjectGeneral)
{
  mLoaderObjectGeneral.SetMakerObjectGeneral(pMakerObjectGeneral);
}
//--------------------------------------------------------------------------------------------------------
void TManagerObjectGeneral::Clear()
{
  int cnt = mVectorObject.size();
  for(int i = 0 ; i < cnt ; i++ )
    mLoaderObjectGeneral.Delete(mVectorObject[i]);

  mVectorObject.clear();
}
//--------------------------------------------------------------------------------------------------------
IBaseObjectGeneral* TManagerObjectGeneral::CreateObject(unsigned int id_model)
{
  IBaseObjectGeneral* pObject = mLoaderObjectGeneral.LoadObject(id_model);
  AddObject(pObject);
  return pObject;
}
//--------------------------------------------------------------------------------------------------------
