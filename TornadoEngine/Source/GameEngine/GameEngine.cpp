/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include <stddef.h>
#include <stdarg.h>

#include "GameEngine.h"

#include "MakerLoaderDLL.h"
#include "BL_Debug.h"
#include "ShareMisc.h"
#include "HiTimer.h"
#include "Logger.h"
#include "ILoaderDLL.h"
#include "NetSystem.h"
#include "IModule.h"
#include "FileOperation.h"
#include "IDevTool.h"
#include "ThreadModules.h"
#include "EventGameEngine.h"
#include "ParserXMLConveyer.h"

using namespace std;

#define STR_GAME "GameEngine"

TGameEngine::TGameEngine()
{
  mCB_Stop.Register(&TGameEngine::StopThreadByModule, this);

  mSynchroPoint.reset(new TSynchroPoint);

  TMakerLoaderDLL maker;
  mLoaderDLL = maker.New();

  mGetDevTool  = NULL;
  mFreeDevTool = NULL;
  mDevTool     = NULL;

  Init();
}
//----------------------------------------------------------------------
void TGameEngine::Done()
{
  if(mFreeDevTool)
    mFreeDevTool(mDevTool);

  TMakerLoaderDLL maker;
  maker.Delete(mLoaderDLL);

	GetLogger()->Done();
}
//----------------------------------------------------------------------
bool TGameEngine::LoadDLL(int variant_use, const char* sNameDLL)
{
  if(mLoaderDLL->Init(sNameDLL)==false)
  {
    GetLogger(STR_GAME)->WriteF_time("LoadDLL() FAIL init.\n");
    return false;
  }
  mFreeDevTool = (FuncFreeDevTool)mLoaderDLL->Get(StrFreeDevTool);
  if(mFreeDevTool==NULL)
  {
    GetLogger(STR_GAME)->WriteF_time("LoadDLL() FAIL load FuncFree.\n");
    return false;
  }
  mGetDevTool = (FuncGetDevTool)mLoaderDLL->Get(StrGetDevTool);
  if(mGetDevTool==NULL)
  {
    GetLogger(STR_GAME)->WriteF_time("LoadDLL() FAIL load FuncGetdevTool.\n");
    return false;
  }
  if(mDevTool!=NULL)
  {
    GetLogger(STR_GAME)->WriteF_time("LoadDLL() warning, object was loaded.\n");
    return true;
  }
  mDevTool = mGetDevTool(variant_use);
  if(mDevTool==NULL)// нет DLL - нет движка.
    return false;
  return true;
}
//----------------------------------------------------------------------
void TGameEngine::Init()
{
  GetLogger()->Done();
  GetLogger()->Register(STR_GAME);
  if(ns_Init()==false)
  {
    GetLogger(STR_GAME)->WriteF_time("Error ns_Init().\n");
    BL_FIX_BUG();
  }
}
//------------------------------------------------------------------------
void TGameEngine::Work(int variant_use, const char* sNameDLL, vector<string>& arg)// начало работы
{
  if(LoadDLL(variant_use,sNameDLL)==false)
    return;
  mDevTool->Init(arg);
  // подготовка конвейера
  if(PrepareConveyer()==false)
    return;
  if(CreateModules()==false)
    return;
  LinkModulesToSynchroPoint();
  // создать поток, который создает потоки модулей
  StartThread_StartThreads();
  // засыпаем, проснемся только если нас разбудят потоки с модулями
  Suspend();
  // останавливаем потоки с модулями
  StopThreadsWithModules();
  // чистка
  Done();
}
//------------------------------------------------------------------------
string TGameEngine::GetVersion()
{
	return "Version 7, Tornado Game Engine";
}
//------------------------------------------------------------------------
void TGameEngine::StopThreadByModule(std::string sNameModule)
{
  // создать событие
  Event(nsGameEngine::eStopThreads, sNameModule.data());

  // проснуться
  Resume();
}
//------------------------------------------------------------------------
bool TGameEngine::PrepareConveyer()
{
  string sFileDescConveyer = mDevTool->GetFileDescConveyer();
  string sVariantConveyer  = mDevTool->GetVariantConveyer();
  //int countCore = GetCountCoreCPU();
  TParserXMLConveyer parser;
  if(parser.Work(sFileDescConveyer, sVariantConveyer)==false)
  {
    string sError = parser.GetStrError();
    Event(nsGameEngine::eParseFileConveyerError, sError.data());
    return false;
  }
  parser.GetResult(mVecVecStrModule, mMapDst_SrcModule);

  return true;
}
//------------------------------------------------------------------------
void TGameEngine::StartThread_StartThreads()
{
  boost::thread work_thread(boost::bind(&TGameEngine::StartThreadsWithModules, this));
}
//------------------------------------------------------------------------
void TGameEngine::Suspend()
{
  boost::mutex::scoped_lock lock(mMutex);
  mConditionVariable.wait(lock);
}
//------------------------------------------------------------------------
void TGameEngine::Resume()
{
  mConditionVariable.notify_all();
}
//------------------------------------------------------------------------
void TGameEngine::StartThreadsWithModules()
{
  // ждать пока главный поток уснет
  boost::mutex::scoped_lock lock(mMutex);
  while(lock.owns_lock()==false) 
    ht_msleep(50);

  int cntThread = mVecVecModule.size();
  for( int iThread = 0; iThread < cntThread ; iThread++ )
  {
    // создать поток и поместить в него модули
    TThreadModules* pThread = new TThreadModules;
    mVecThread.push_back(pThread);
    int cntModule = mVecVecModule[iThread].size();
    TVecPtrModule& vecModule = mVecVecModule[iThread];
    for( int iModule = 0 ; iModule < cntModule ; iModule++ )
      pThread->AddModule(vecModule[iModule]);
    pThread->SetCallbackStop(&mCB_Stop);
    pThread->Start();
  }
  // разблокировать главный поток, что бы созданные потоки с модулями могли уведомить его.
  lock.unlock();
}
//------------------------------------------------------------------------
void TGameEngine::StopThreadsWithModules()
{
  int cntThread = mVecThread.size();
  for( int iThread = 0; iThread < cntThread ; iThread++ )
  {
    mVecThread[iThread]->Stop();
    delete mVecThread[iThread];
  }
  mVecThread.clear();

  Event(nsGameEngine::eStopThreadsEnd);
}
//------------------------------------------------------------------------
bool TGameEngine::CreateModules()
{
  int cntThread = mVecVecStrModule.size();
  for( int iThread = 0; iThread < cntThread ; iThread++ )
  {
    // создать поток и поместить в него модули
    int cntModule = mVecVecStrModule[iThread].size();
    TVecStr& vecStrModule = mVecVecStrModule[iThread];

    TVecPtrModule vecPtrModule;
    for( int iModule = 0 ; iModule < cntModule ; iModule++ )
    {
      IModule* pModule = mDevTool->GetModuleByName(vecStrModule[iModule].data());
      if(pModule!=NULL)
      {
        vecPtrModule.push_back(pModule);
        mMapName_IDModule.insert(TMapStrIntVT(pModule->GetName(), pModule->GetID()));
      }
      else
        Event(nsGameEngine::eModuleNotMade, vecStrModule[iModule].data());
    }
    if(vecPtrModule.size())
      mVecVecModule.push_back(vecPtrModule);
  }

  if(mVecVecStrModule.size()==0)
    return false;

  return true;
}
//------------------------------------------------------------------------
void TGameEngine::Event(int id, ...)
{
  string sEvent;
  if(nsGameEngine::GetStrEventsByID(id, sEvent))
  {
    const char* ptrEvent = sEvent.data();

    va_list list;
    va_start(list, ptrEvent);

    char sError[10000]; 
    int res = vsprintf(sError, ptrEvent, list); 

    va_end(list);

    mDevTool->EventGameEngine(id, sError);
  }
}
//------------------------------------------------------------------------
void TGameEngine::LinkModulesToSynchroPoint()
{
  int cntThread = mVecVecModule.size();
  for( int iThread = 0; iThread < cntThread ; iThread++ )
  {
    int cntModule = mVecVecModule[iThread].size();
    TVecPtrModule& vecModule = mVecVecModule[iThread];
    for( int iModule = 0 ; iModule < cntModule ; iModule++ )
    {
      vecModule[iModule]->SetSynchroPoint(mSynchroPoint.get());
      vecModule[iModule]->SetSelfID(vecModule[iModule]->GetID());
      // ищем вектор имен источников для данного модуля (на кого он хочет зарегистрироваться)
      TMapStrVecStrIt fit = mMapDst_SrcModule.find(vecModule[iModule]->GetName());
      if(fit!=mMapDst_SrcModule.end())
      {
        BOOST_FOREACH(string& nameSrc ,fit->second)
        {
          int id_src;// находим по имени ID
          if(FindIDByNameModule(nameSrc, id_src))
            vecModule[iModule]->Register(id_src);
        }
      }
    }
  }
}
//------------------------------------------------------------------------
bool TGameEngine::FindIDByNameModule(string& nameSrc, int& id)
{
  TMapStrIntIt fit = mMapName_IDModule.find(nameSrc);
  if(fit==mMapName_IDModule.end())
    return false;

  id = fit->second;
  return true;
}
//------------------------------------------------------------------------
