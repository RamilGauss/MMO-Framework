/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
√удаков –амиль —ергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ClientGame.h"

#include <string>
#include <boost/thread/thread.hpp>

#include "IControlCamera.h"
#include "IGraphicEngine.h"
#include "IPhysicEngine.h"
#include "IManagerTime.h"
#include "IManagerObjectCommon.h"
#include "IGUI.h"
#include "IXML.h"
#include "ITimer.h"

#include "MakerPhysicEngine.h"
#include "MakerGraphicEngine.h"
#include "MakerManagerObjectCommon.h"
#include "MakerManagerTime.h"
#include "MakerGUI.h"
#include "MakerControlCamera.h"
#include "MakerManagerStateMachine.h"
#include "MakerTimer.h"

#include "common_defs.h"
#include "BL_Debug.h"
#include "HiTimer.h"
#include "Logger.h"
#include "NameSrcEventID.h"
#include "file_operation.h"
#include "StorePathResources.h"
#include "MapXML_Field.h"
#include "ShareMisc.h"

using namespace std;
using namespace nsEvent;

TClientGame::TClientGame()
{
  mType = eClient;
}
//------------------------------------------------------------------------
TClientGame::~TClientGame()
{

}
//------------------------------------------------------------------------
bool TClientGame::Work()
{
  // опросить модули движка дл€ генерации событий
  RET_FALSE(MakeEventFromModule())
  // обработать событи€
  HandleEventByDeveloper();
  // расчеты, необходимые дл€ рендера, в зависимости от времени предыдущего расчета
  Render();
  if(mClientDeveloperTool->NeedExit())
    return false;

  return true;
}
//------------------------------------------------------------------------
bool TClientGame::Init(int variant_use, const char* sNameDLL, vector<string>& arg)
{
  // загрузка DLL
  RET_FALSE(LoadDLL(variant_use, sNameDLL))
  if(mClientDeveloperTool==NULL)// политика: нет DLL - нет движка.
    return false;
  
  // подготовить пути дл€ ресурсов
  string sRelPathXML = mClientDeveloperTool->GetPathXMLFile();
  char sAbsPath[300];
  FindAbsPath((char*)sRelPathXML.data(),sAbsPath,sizeof(sAbsPath));
  if(GetStorePathResources()->Load(sAbsPath)==false)
    return false;

  // камера
  TMakerControlCamera makerControlCamera;
  mCClient.mControlCamera = makerControlCamera.New();

  // создатель объектов
  IMakerObjectCommon* pMakerObjectCommon = mClientDeveloperTool->GetMakerObjectCommon();

  // дл€ внутреннего обмена
  mCClient.mDev.SetDstObject(this);
  mCClient.mDev.SetSelfID(ID_SRC_EVENT_DEV);
  // создать двигатели и проинициализировать менеджеры
  TMakerGraphicEngine makerGraphicEngine;
  mCClient.mGraphicEngine = makerGraphicEngine.New(mCClient.mControlCamera);
  mCClient.mGraphicEngine->Init();// создали окно
  mCClient.mGraphicEngine->SetSelfID(ID_SRC_EVENT_GRAPHIC_ENGINE);
  mCClient.mGraphicEngine->SetDstObject(this);
  mCClient.mGraphicEngine->SetTitleWindow(mClientDeveloperTool->GetTitleWindow().data());
  //------------------------------------------
  TMakerPhysicEngine makerPhysicEngine;
  mCClient.mPhysicEngine = makerPhysicEngine.New();
  mCClient.mPhysicEngine->SetSelfID(ID_SRC_EVENT_PHYSIC_ENGINE);
  mCClient.mPhysicEngine->SetDstObject(this);
  //------------------------------------------
  TMakerManagerStateMachine makerMStateManager;
  mCClient.mMStateMachine = makerMStateManager.New();
  //------------------------------------------
  mCClient.mNetClient = new nsMMOEngine::TClient;
	SetupNetComponent(mCClient.mNetClient);
  //------------------------------------------
  TMakerManagerObjectCommon makerMOC;
  mCClient.mMOC = makerMOC.New();
  mCClient.mMOC->Init(pMakerObjectCommon);
  mCClient.mMOC->SetSelfID(ID_SRC_EVENT_MANAGER_OBJECT_COMMON);
  mCClient.mMOC->SetDstObject(this);
  //------------------------------------------
  TMakerManagerTime makerMTime;
  mCClient.mMTime = makerMTime.New();
  //------------------------------------------
  TMakerGUI makerGUI;
  mCClient.mGUI = makerGUI.New();
  mCClient.mGraphicEngine->SetGUI(mCClient.mGUI);
  //------------------------------------------
  TMakerTimer makerTimer;
  mCClient.mTimerFirstEvent = makerTimer.New();
  mCClient.mTimerFirstEvent->SetDstObject(this);
  mCClient.mTimerFirstEvent->SetSelfID(ID_SRC_EVENT_TIMER_FIRST_EVENT);
  //------------------------------------------
  mCClient.mTimerLastEvent = makerTimer.New();
  mCClient.mTimerLastEvent->SetDstObject(this);
  mCClient.mTimerLastEvent->SetSelfID(ID_SRC_EVENT_TIMER_LAST_EVENT);
  //------------------------------------------
  //------------------------------------------
  // запустить потоки, в которых будут работать модули
  StartThreadModule();
  //------------------------------------------
  mClientDeveloperTool->Init(&mCClient,arg);

  return true;
}
//------------------------------------------------------------------------
void TClientGame::Done()
{
  mClientDeveloperTool->Done();// освободить ресурсы DevTool
  StopThreadModule();
  // а теперь модули
  TMakerManagerStateMachine makerMStateManager;
  makerMStateManager.Delete(mCClient.mMStateMachine);
  mCClient.mMStateMachine = NULL;

  TMakerGUI makerGUI;
  makerGUI.Delete(mCClient.mGUI);
  mCClient.mGUI = NULL;
  mCClient.mGraphicEngine->ZeroGUI();

  TMakerGraphicEngine makerGE;
  makerGE.Delete(mCClient.mGraphicEngine);
  mCClient.mGraphicEngine = NULL;

  TMakerPhysicEngine makerPE;
  makerPE.Delete(mCClient.mPhysicEngine);
  mCClient.mPhysicEngine = NULL;

  delete mCClient.mNetClient;
  mCClient.mNetClient = NULL;

  TMakerManagerObjectCommon makerMOC;
  makerMOC.Delete(mCClient.mMOC);
  mCClient.mMOC = NULL;

  TMakerManagerTime makerMTimer;
  makerMTimer.Delete(mCClient.mMTime);
  mCClient.mMTime = NULL;
  // камера
  TMakerControlCamera makerControlCamera;
  makerControlCamera.Delete(mCClient.mControlCamera);
  mCClient.mControlCamera = NULL;
	//------------------------------------------
	TMakerTimer makerTimer;
	makerTimer.Delete(mCClient.mTimerFirstEvent);
	mCClient.mTimerFirstEvent = NULL;
	//------------------------------------------
	makerTimer.Delete(mCClient.mTimerLastEvent);
	mCClient.mTimerLastEvent = NULL;
	//------------------------------------------
}
//------------------------------------------------------------------------
void TClientGame::Render()
{
  mCClient.mGraphicEngine->Work(mCClient.mMTime->GetTime());
}
//------------------------------------------------------------------------
bool TClientGame::HandleGraphicEngineEvent()
{
  return mCClient.mGraphicEngine->HandleInternalEvent();
}
//------------------------------------------------------------------------
bool TClientGame::HandleNetEngineEvent()
{
  mCClient.mNetClient->Work();
  return true;
}
//------------------------------------------------------------------------
void TClientGame::CollectEvent()
{

}
//------------------------------------------------------------------------
void TClientGame::HandleEvent(TEvent* pEvent)
{
  mClientDeveloperTool->Event(pEvent);
}
//------------------------------------------------------------------------
//  ƒл€ клиента кол-во потоков определ€етс€ кол-вом €дер CPU
void TClientGame::MakeVectorModule()
{
  int countCore = GetCountCoreCPU();

  // таймер перед всеми событи€ми - должен быть добавлен самым первым
  FuncHandleEvent fTimerFirstEvent = boost::bind(&TClientGame::HandleTimerFirstEvent, this);
  mMainThreadVecModule.push_back(fTimerFirstEvent);

  // обработать событи€ графического €дра - Key+Mouse, GUI, внутренние событи€ GE.
  FuncHandleEvent fGraphicEngineEvent = boost::bind(&TClientGame::HandleGraphicEngineEvent, this);
  mMainThreadVecModule.push_back(fGraphicEngineEvent);
  // сетевой движок
  FuncHandleEvent fNetEngineEvent = boost::bind(&TClientGame::HandleNetEngineEvent, this);
  mMainThreadVecModule.push_back(fNetEngineEvent);
	// эксперимент с несколькими потоками
  //if(countCore==1)
    //mMainThreadVecModule.push_back(fNetEngineEvent);
  //else
  //{
    //TDescThread dt;
    //dt.pFunc       = fNetEngineEvent;
    //dt.sleep_ms    = eSleepNE;
    //mOtherThreadVecModule.push_back(dt);
  //}
  // физика
  // звук
  //------------------------------------------------------------------------------
  // таймер после всех событий - должен быть добавлен самым последним
  FuncHandleEvent fTimerLastEvent = boost::bind(&TClientGame::HandleTimerLastEvent, this);
  mMainThreadVecModule.push_back(fTimerLastEvent);
}
//------------------------------------------------------------------------
void TClientGame::StartThreadModule()
{
  int cnt = mOtherThreadVecModule.size();
  for( int i = 0 ; i < cnt ; i++ )
  {
    boost::thread thread_module( &TDescThread::Work, &mOtherThreadVecModule[i]);

    while(mOtherThreadVecModule[i].flgActive==false)
      ht_msleep(eWaitFeedBack);
  }
}
//------------------------------------------------------------------------
void TClientGame::StopThreadModule()
{
  int cnt = mOtherThreadVecModule.size();
  for( int i = 0 ; i < cnt ; i++ )
  {
    mOtherThreadVecModule[i].flgNeedStop = true;
    while(mOtherThreadVecModule[i].flgActive==true)
      ht_msleep(eWaitFeedBack);
  }
}
//------------------------------------------------------------------------
bool TClientGame::HandleTimerFirstEvent()
{
  mCClient.mTimerFirstEvent->Work();
  return true;
}
//------------------------------------------------------------------------
bool TClientGame::HandleTimerLastEvent()
{
  mCClient.mTimerLastEvent->Work();
  return true;
}
//------------------------------------------------------------------------
