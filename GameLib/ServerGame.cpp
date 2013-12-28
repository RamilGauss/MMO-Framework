/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ServerGame.h"

#include <string>
#include <functional>

#include "IPhysicEngine.h"
#include "IManagerTime.h"
#include "IManagerObjectCommon.h"
#include "IManagerScene.h"
#include "IXML.h"
#include "IQtLib.h"
#include "ITimer.h"

#include "MakerPhysicEngine.h"
#include "MakerManagerObjectCommon.h"
#include "MakerManagerTime.h"
#include "MakerManagerStateMachine.h"
#include "MakerManagerScene.h"
#include "MakerManagerConnectClient.h"
#include "MakerQtLib.h"
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

TServerGame::TServerGame(eTypeRealize type):mStatLoad(30)
{
	mLogLoad.ReOpen(".\\serverLoad.xls");

	mType = type;
}
//------------------------------------------------------------------------
TServerGame::~TServerGame()
{

}
//------------------------------------------------------------------------
bool TServerGame::Work()
{
	mStartTime = ht_GetMSCount();// запомнить время старта
	// опросить модули движка для генерации событий
  RET_FALSE(MakeEventFromModule())
  // обработать события
  HandleEventByDeveloper();
  
  if(mServerDeveloperTool->NeedExit())
    return false;
	// расчет нагрузки
	CalcAndWaitRestTime();
  return true;
}
//------------------------------------------------------------------------
bool TServerGame::Init(int variant_use, const char* sNameDLL, vector<string>& arg)
{
  // загрузка DLL
  RET_FALSE(LoadDLL(variant_use,sNameDLL))
  if(mServerDeveloperTool==NULL)// политика: нет DLL - нет движка.
    return false;
  // подготовить пути для ресурсов
  string sRelPathXML = mServerDeveloperTool->GetPathXMLFile();
  char sAbsPath[300];
  FindAbsPath((char*)sRelPathXML.data(),sAbsPath,sizeof(sAbsPath));
  if(GetStorePathResources()->Load(sAbsPath)==false)
    return false;
  //------------------------------------------
  TMakerQtLib makerQtLib;
  mCServer.mQtGUI = makerQtLib.New();
  mCServer.mQtGUI->Init(0,NULL);
  mCServer.mQtGUI->SetSelfID(ID_SRC_EVENT_QT_LIB);
  mCServer.mQtGUI->SetDstObject(this);
  //------------------------------------------
  TMakerManagerScene makerManagerScene;
  mCServer.mManagerScene = makerManagerScene.New();
  //------------------------------------------
  TMakerManagerConnectClient makerManagerConnectClient;
  mCServer.mManagerCClient = makerManagerConnectClient.New();
  //------------------------------------------
	switch(mType)
	{
		case eSlave:
			mCServer.mNet.Base = new nsMMOEngine::TSlave;
			break;
		case eMaster:
			mCServer.mNet.Base = new nsMMOEngine::TMaster;
			break;
		case eSuperServer:
			mCServer.mNet.Base = new nsMMOEngine::TSuperServer;
			break;
	}	
	SetupNetComponent(mCServer.mNet.Base);
  //------------------------------------------
  TMakerTimer makerTimer;
  mCServer.mTimerFirstEvent = makerTimer.New();
  mCServer.mTimerFirstEvent->SetDstObject(this);
  mCServer.mTimerFirstEvent->SetSelfID(ID_SRC_EVENT_TIMER_FIRST_EVENT);
  //------------------------------------------
  mCServer.mTimerLastEvent = makerTimer.New();
  mCServer.mTimerLastEvent->SetDstObject(this);
  mCServer.mTimerLastEvent->SetSelfID(ID_SRC_EVENT_TIMER_LAST_EVENT);
  //------------------------------------------
  //------------------------------------------
  mServerDeveloperTool->Init(&mCServer,arg);

  return true;
}
//------------------------------------------------------------------------
void TServerGame::Done()
{
  mServerDeveloperTool->Done();// освободить ресурсы DevTool
  // а теперь модули
  delete mCServer.mNet.Base;
  mCServer.mNet.Base = NULL;
  //------------------------------------------
  TMakerQtLib makerQtLib;
  makerQtLib.Delete(mCServer.mQtGUI);
  mCServer.mQtGUI = NULL;
  //------------------------------------------
  TMakerManagerScene makerManagerScene;
  makerManagerScene.Delete(mCServer.mManagerScene);
  mCServer.mManagerScene = NULL;
  //------------------------------------------
  TMakerManagerConnectClient makerManagerConnectClient;
  makerManagerConnectClient.Delete(mCServer.mManagerCClient);
  mCServer.mManagerCClient = NULL;
  //------------------------------------------
	TMakerTimer makerTimer;
	makerTimer.Delete(mCServer.mTimerFirstEvent);
	mCServer.mTimerFirstEvent = NULL;
	//------------------------------------------
	makerTimer.Delete(mCServer.mTimerLastEvent);
	mCServer.mTimerLastEvent = NULL;
	//------------------------------------------
}
//------------------------------------------------------------------------
bool TServerGame::HandleNetEngineEvent()
{
  mCServer.mNet.Base->Work();
  return true;
}
//------------------------------------------------------------------------
bool TServerGame::HandleSceneEvent()
{
  mCServer.mManagerScene->Work();
  return true;
}
//------------------------------------------------------------------------
void TServerGame::CollectEvent()
{

}
//------------------------------------------------------------------------
void TServerGame::HandleEvent(TEvent* pEvent)
{
  mServerDeveloperTool->Event(pEvent);
}
//------------------------------------------------------------------------
void TServerGame::MakeVectorModule()
{
  // таймер перед всеми событиями - должен быть добавлен самым первым
  FuncHandleEvent fTimerFirstEvent = boost::bind(&TServerGame::HandleTimerFirstEvent, this);
  mMainThreadVecModule.push_back(fTimerFirstEvent);

  // сетевой движок
  FuncHandleEvent fNetEngineEvent = boost::bind(&TServerGame::HandleNetEngineEvent, this);
  mMainThreadVecModule.push_back(fNetEngineEvent);
  // обработка событий сцены
  switch(mType)
  {
    case eSlave:
      {
        FuncHandleEvent fSceneEvent = boost::bind(&TServerGame::HandleSceneEvent, this);
        mMainThreadVecModule.push_back(fSceneEvent);
      }
      break;
    case eMaster:
    case eSuperServer:
      break;
  }	
  //------------------------------------------------------------------------------
  // таймер после всех событий - должен быть добавлен самым последним
  FuncHandleEvent fTimerLastEvent = boost::bind(&TServerGame::HandleTimerLastEvent, this);
  mMainThreadVecModule.push_back(fTimerLastEvent);
}
//------------------------------------------------------------------------
void TServerGame::SetLoad()
{
	mCServer.mNet.Base->SetLoad(int(mStatLoad.aver()));
}
//------------------------------------------------------------------------
void TServerGame::CalcAndWaitRestTime()
{
	unsigned int now = ht_GetMSCount();
	unsigned int refresh_time = mServerDeveloperTool->GetTimeRefreshMS();// сколько можно потратить

	unsigned int work_time = now - mStartTime;// потрачено времени
	double loadProcent = (work_time*100.0)/refresh_time;// расчет нагрузки
	mStatLoad.add(loadProcent);// занести в статистику
	SetLoad();                 // задать в сетевой модуль

	mLogLoad.WriteF("%d\n",int(mStatLoad.aver()));
	// спать остаток времени
	if(now>refresh_time+mStartTime) return;
	unsigned int time_sleep = mStartTime + refresh_time - now;
	ht_msleep(time_sleep);
}
//------------------------------------------------------------------------
bool TServerGame::HandleTimerFirstEvent()
{
  mCServer.mTimerFirstEvent->Work();
  return true;
}
//------------------------------------------------------------------------
bool TServerGame::HandleTimerLastEvent()
{
  mCServer.mTimerLastEvent->Work();
  return true;
}
//------------------------------------------------------------------------
