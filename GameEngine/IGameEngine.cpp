/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include <stddef.h>

#include "IGameEngine.h"

#include "MakerLoaderDLL.h"
#include "BL_Debug.h"
#include "ShareMisc.h"
#include "HiTimer.h"
#include "Logger.h"
#include "ILoaderDLL.h"
#include "NetSystem.h"
#include "StorePathResources.h"
#include "MapXML_Field.h"
#include "file_operation.h"
#include "IModule.h"

#include "PrototypeList.h"

using namespace std;
using namespace nsEvent;

#define STR_GAME "GameEngine"

IGameEngine::IGameEngine():mStatLoad(30)
{
	mLogLoad.ReOpen(".\\serverLoad.xls");

  TMakerLoaderDLL maker;
  mLoaderDLL = maker.New();

  mGetDevTool  = NULL;
  mFreeDevTool = NULL;
  mDevTool     = NULL;

  InitLog();
  Init();
}
//----------------------------------------------------------------------
IGameEngine::~IGameEngine()
{
  if(mFreeDevTool)
    mFreeDevTool(mDevTool);

  TMakerLoaderDLL maker;
  maker.Delete(mLoaderDLL);

	GetLogger()->Done();
}
//----------------------------------------------------------------------
bool IGameEngine::LoadDLL(int variant_use, const char* sNameDLL)
{
  if(mDevTool!=NULL)
  {
    GetLogger(STR_GAME)->WriteF_time("LoadDLL() warning, object was loaded.\n");
    BL_FIX_BUG();
    return true;
  }
  if(mLoaderDLL->Init(sNameDLL)==false)
  {
    GetLogger(STR_GAME)->WriteF_time("LoadDLL() FAIL init.\n");
    BL_FIX_BUG();
    return false;
  }
  mFreeDevTool = (FuncFreeDevTool)mLoaderDLL->Get(StrFreeDevTool);
  if(mFreeDevTool==NULL)
  {
    GetLogger(STR_GAME)->WriteF_time("LoadDLL() FAIL load FuncFree.\n");
    BL_FIX_BUG();
    return false;
  }
  mGetDevTool = (FuncGetDevTool)mLoaderDLL->Get(StrGetDevTool);
  if(mGetDevTool==NULL)
  {
    GetLogger(STR_GAME)->WriteF_time("LoadDLL() FAIL load FuncGetdevTool.\n");
    BL_FIX_BUG();
    return false;
  }
  mDevTool = mGetDevTool(variant_use);
  if(mDevTool==NULL)// политика: нет DLL - нет движка.
    return false;
  return true;
}
//----------------------------------------------------------------------
void IGameEngine::Init()
{
  if(ns_Init()==false)
  {
    GetLogger(STR_GAME)->WriteF_time("Error ns_Init().\n");
    BL_FIX_BUG();
  }
}
//----------------------------------------------------------------------
void IGameEngine::InitLog()
{
	GetLogger()->Done();
	GetLogger()->Register(STR_GAME);
}
//------------------------------------------------------------------------
void IGameEngine::Work(int variant_use, const char* sNameDLL, vector<string>& arg)// начало работы
{
  if(Init(variant_use,sNameDLL,arg)==false)
    return;

  flgNeedStop = false;
  flgActive   = true;
  //------------------------------------------------------
  while(flgNeedStop==false)
  {
    mStartTime = ht_GetMSCount();// запомнить время старта
    // опросить модули движка для генерации событий
    if(MakeEventFromModule()==false)
      break;
    // обработать события
    HandleEventByDeveloper();

    if(mDevTool->NeedExit())
      break;
    // расчет нагрузки
    CalcAndWaitRestTime();
  }
  //------------------------------------------------------
  flgActive = false;
  Done();
}
//------------------------------------------------------------------------
bool IGameEngine::MakeEventFromModule()
{
  int cnt = mMainThreadVecModule.size();
  for( int i = 0 ; i < cnt ; i++ )
  {
    // обработка событий модулей
    // некоторые модули могут вернуть false
    if(mMainThreadVecModule[i]->UseInConveyer())
      RET_FALSE(mMainThreadVecModule[i]->Work())
  }
  return true;
}
//------------------------------------------------------------------------
void IGameEngine::HandleEventByDeveloper()
{
  TEvent* pEvent = GetEvent();
  while(pEvent)
  {
    // обработка события
    mDevTool->Event(pEvent);
    delete pEvent;
    pEvent = GetEvent();
  }
}
//------------------------------------------------------------------------
bool IGameEngine::Init(int variant_use, const char* sNameDLL, vector<string>& arg)
{
  // загрузка DLL
  RET_FALSE(LoadDLL(variant_use,sNameDLL))
  // подготовить пути для ресурсов
  string sRelPathXML = mDevTool->GetPathXMLFile();
  char sAbsPath[300];
  FindAbsPath((char*)sRelPathXML.data(),sAbsPath,sizeof(sAbsPath));
  RET_FALSE(GetStorePathResources()->Load(sAbsPath))

  // в конструкторе вызывать нельзя, надо вызвать здесь
  SetupDevModule();

  mDevTool->Init(arg);
  return true;
}
//------------------------------------------------------------------------
void IGameEngine::CalcAndWaitRestTime()
{
  unsigned int refresh_time = mDevTool->GetTimeRefresh_ms();// сколько можно потратить
  if(refresh_time==0)
    return;

  unsigned int now = ht_GetMSCount();

  unsigned int work_time = now - mStartTime;// потрачено времени
  double loadProcent = (work_time*100.0)/refresh_time;// расчет нагрузки
  mStatLoad.add(loadProcent);                         // занести в статистику
  mDevTool->SetLoadConveyer(int(mStatLoad.aver()));              

  mLogLoad.WriteF("%d\n",int(mStatLoad.aver()));
  // спать остаток времени
  if(now>refresh_time+mStartTime) return;
  unsigned int time_sleep = mStartTime + refresh_time - now;
  ht_msleep(time_sleep);
}
//------------------------------------------------------------------------
void IGameEngine::Done()
{
  mDevTool->Done();// освободить ресурсы DevTool
  FreeDevModule();
}
//------------------------------------------------------------------------
void IGameEngine::PushModule(IModule* pModule)
{
  mMainThreadVecModule.push_back(pModule);

  pModule->SetDstObject(this);
  pModule->SetSelfID(pModule->GetID());
}
//------------------------------------------------------------------------
IModule* IGameEngine::GetModulePtr(int index)
{
  return mMainThreadVecModule[index];
}
//------------------------------------------------------------------------
int IGameEngine::GetVersion()
{
	return 4;
}
//------------------------------------------------------------------------
