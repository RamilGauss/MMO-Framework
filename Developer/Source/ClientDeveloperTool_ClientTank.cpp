/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ClientDeveloperTool_ClientTank.h"
#include <string.h>

#include "Logger.h"
#include "HiTimer.h"
#include "IControlCamera.h"
#include "IXML.h"

#include "MakerObjectCommon.h"

#include "../GameLib/IClientDeveloperTool.h"
#include "../GameLib/IManagerObjectCommon.h"
#include "../GameLib/IBaseObjectCommon.h"
#include "../GameLib/NameSrcEventID.h"
#include "../GameLib/IManagerStateMachine.h"
#include "../GraphicEngine/IGraphicEngine.h"
#include "../GUI/IGUI.h"
#include "Client.h"
#include "GlobalParam.h"
#include "ShareMisc.h"
#include "NetSystem.h"
#include "BaseEvent.h"
#include "file_operation.h"
#include "StorePathResources.h"
#include "MapXML_Field.h"
#include "Master.h"
#include "Events.h"
#include "../../GameLib/ITimer.h"


using namespace std;
using namespace nsStruct3D;
using namespace nsEvent;
using namespace nsMMOEngine;
using namespace nsKey;

#define LOG_TIME_LOAD_EDITOR_MODEL

#define DELTA_MOVE     0.2f //0.4f
#define DELTA_ROTATE   0.01f
#define ASPECT_MOUSE_X 0.002f
#define ASPECT_MOUSE_Y 0.002f

#define UP 1000000

TClientDeveloperTool_ClientTank::TClientDeveloperTool_ClientTank()
{
  flgDragCamera = false;

  mMakerObjectCommon = new TMakerObjectCommon;
  
  mIndexCurObj = 0;

  mClientMain      = new TClientMain;
  mGameRoomPrepare = new TGameRoomPrepare;
  mWaitForm        = new TWaitForm;

  mCurrentForm     = NULL;

  mTank   = NULL;
  mHangar = NULL;
}
//------------------------------------------------------------------------------------
TClientDeveloperTool_ClientTank::~TClientDeveloperTool_ClientTank()
{
  delete mMakerObjectCommon;
}
//------------------------------------------------------------------------------------
void TClientDeveloperTool_ClientTank::MouseEvent(TMouseEvent* pEvent)
{
  switch(pEvent->state)
  {
    case nsEvent::eButtonUp:
      flgDragCamera = false;
      break;
    case nsEvent::eButtonDown:
      flgDragCamera = true;
      mOldX = pEvent->x;
      mOldY = pEvent->y;
      break;
    case nsEvent::eButtonDblClick:
      break;
    case nsEvent::eWheel:
      mComponent.mControlCamera->AddDistObj(float(pEvent->delta_wheel)/100.0f);
      break;
    case nsEvent::eMove:
      if(flgDragCamera)
      {
        float dRight = float(pEvent->x - mOldX)*ASPECT_MOUSE_X;
        float dDown  = float(pEvent->y - mOldY)*ASPECT_MOUSE_Y;
        mComponent.mControlCamera->RotateRight(dRight);
        mComponent.mControlCamera->RotateDown(dDown);
        
        mOldX = pEvent->x;
        mOldY = pEvent->y;
      }
			break;
  }
}
//------------------------------------------------------------------------------------
void TClientDeveloperTool_ClientTank::KeyEvent(TKeyEvent* pEvent)
{
  unsigned int v;
  bool res = mComponent.mMStateMachine->GetValue(mIDkey,pEvent->key,v);
  v |= (pEvent->pressed?0:UP);
  if(res)
  switch(v)
  {
    // клавиатура
    case e_W://W
      mComponent.mControlCamera->SetSpeedForward(DELTA_MOVE);
      break;
    case e_W|UP://W
      mComponent.mControlCamera->SetSpeedForward(0);
      break;
    case e_S://S
      mComponent.mControlCamera->SetSpeedForward(-DELTA_MOVE);
      break;
    case e_S|UP://S
      mComponent.mControlCamera->SetSpeedForward(0);
      break;
    case e_A://A
      mComponent.mControlCamera->SetSpeedRight(-DELTA_MOVE);
      break;
    case e_A|UP://A
      mComponent.mControlCamera->SetSpeedRight(0);
      break;
    case e_D://D
      mComponent.mControlCamera->SetSpeedRight(DELTA_MOVE);
      break;
    case e_D|UP://D
      mComponent.mControlCamera->SetSpeedRight(0);
      break;
    case e_Q://Q
      mComponent.mControlCamera->SetSpeedUp(DELTA_MOVE);
      break;
    case e_Q|UP://Q
      mComponent.mControlCamera->SetSpeedUp(0);
      break;
    case e_E://E
      mComponent.mControlCamera->SetSpeedUp(-DELTA_MOVE);
      break;
    case e_E|UP://E
      mComponent.mControlCamera->SetSpeedUp(0);
      break;
    // мышь
    case e_Numpad4:// влево 4
      mComponent.mControlCamera->RotateRight(-DELTA_ROTATE);
      break;
    case e_Numpad6:// вправо 6
      mComponent.mControlCamera->RotateRight(DELTA_ROTATE);
      break;
    case e_Numpad8:// вверх 8
      mComponent.mControlCamera->RotateDown(-DELTA_ROTATE);
      break;
    case e_Numpad2:// вниз 2
      mComponent.mControlCamera->RotateDown(DELTA_ROTATE);
      break;
    case e_Numpad7:// вращаться влево 7
      mComponent.mControlCamera->Roll(DELTA_ROTATE);
      break;
    case e_Numpad9:// вращаться вправо 9
      mComponent.mControlCamera->Roll(-DELTA_ROTATE);
      break;
    case e_C:// сбросить ориентацию камеры C
      mComponent.mControlCamera->ClearRotate();
      break;
    case e_V:// сбросить ориентацию камеры V
    {
      TVector3 v;
      v.x = 0.0f;
      v.y = 0.0f;
      v.z = 0.0f;
      mComponent.mControlCamera->SetPositionLookAt(&v);
      break;
    }
    case e_B: // B 
    {
      IBaseObject* pBO = mComponent.mMOC->Get(mIndexCurObj);
      mComponent.mControlCamera->Link(pBO,IControlCamera::eCoord);
      mIndexCurObj++;
      mIndexCurObj %= mComponent.mMOC->GetCountObject();
      break;
    }
    case e_N: 
      mComponent.mControlCamera->Unlink();
      break;
    case e_O: 
      break;
  }
}
//--------------------------------------------------------------------
IMakerObjectCommon* TClientDeveloperTool_ClientTank::GetMakerObjectCommon()
{
  return mMakerObjectCommon;
}
//------------------------------------------------------------------------------------
string TClientDeveloperTool_ClientTank::GetTitleWindow()
{
  return "Клиент танков";
}
//------------------------------------------------------------------------------------
void TClientDeveloperTool_ClientTank::Init(TComponentClient* pComponent, vector<string>& arg )
{
  InitLog();
  mComponent = *pComponent; 

  ParseCmd(arg);

  TInputCmdDevTool::TInput input;
  mInputCmd.Get(input);
  // GUI
  mComponent.mGUI->Add(string("mClientMain"),mClientMain);
  mComponent.mGUI->Add(string("mGameRoomPrepare"),mGameRoomPrepare);
  mComponent.mGUI->Add(string("mWaitForm"),mWaitForm);
  // показать форму
  SetCurrentForm(mClientMain);
  // подстроиться
  mComponent.mGUI->Resize();
  // HotKey
	if(GetStorePathResources()->GetCount("game_param")>0)
	{
		string sGameParam = GetStorePathResources()->GetSecond("game_param");
		bool resLoadMSM = mComponent.mMStateMachine->Load(sGameParam.data(), mIDkey);
		BL_ASSERT(resLoadMSM);
	}
	else
		BL_FIX_BUG();

  CreateObjects();

  mComponent.mTimerFirstEvent->New(0);
}
//------------------------------------------------------------------------------------
void TClientDeveloperTool_ClientTank::Done()
{
  delete mClientMain;
  mClientMain = NULL;
  delete mGameRoomPrepare;
  mGameRoomPrepare = NULL;
  delete mWaitForm;
  mWaitForm = NULL;
}        
//---------------------------------------------------------------------------------------------
void TClientDeveloperTool_ClientTank::InitLog()
{
  GetLogger()->Register("Inner");// для логирования внутренних событий
  GetLogger()->Init("ClientTank");
}
//---------------------------------------------------------------------------------------------
string TClientDeveloperTool_ClientTank::GetPathXMLFile()
{
  return "resources.xml";
}
//---------------------------------------------------------------------------------------------
void TClientDeveloperTool_ClientTank::Event(nsEvent::TEvent* pEvent)
{
  switch(pEvent->from)
  {
		case ID_SRC_EVENT_GRAPHIC_ENGINE:
      HandleFromGUI((nsEvent::TBaseEvent*)pEvent->pContainer->GetPtr());
      break;
		case ID_SRC_EVENT_NETWORK_ENGINE:
      HandleFromMMOEngine((nsMMOEngine::TBaseEvent*)pEvent->pContainer->GetPtr());
      break;
    case ID_SRC_EVENT_PHYSIC_ENGINE:
      break;
    case ID_SRC_EVENT_MANAGER_OBJECT_COMMON:
      break;
    case ID_SRC_EVENT_TIMER_FIRST_EVENT:
			mTestControlTank.SetupParamForNow();
      break;
    case ID_SRC_EVENT_TIMER_LAST_EVENT:
      break;
    case ID_SRC_EVENT_DEV:
      HandleFromDev((nsDevProtocol::TBase*)pEvent->pContainer->GetPtr());
      break;
  }
}
//---------------------------------------------------------------------------------------------
void TClientDeveloperTool_ClientTank::HandleFromMMOEngine(nsMMOEngine::TBaseEvent* pBE)
{
  string sEvent;  
  switch(pBE->mType)
  {
    case TBase::eConnectDown:
      sEvent = "ConnectDown";
      break;
    case TBase::eDisconnectDown:
      sEvent = "DisconnectDown";
      break;
    case TBase::eConnectUp:
      sEvent = "ConnectUp";
      break;
    case TBase::eDisconnectUp:
      sEvent = "DisconnectUp";
      DisconnectUp();
      break;
    case TBase::eError:
		{
			char sError[300];
			TEventError* pEr = (TEventError*)pBE;
			sprintf(sError, "Error code=%u", pEr->code);
			sEvent = sError;
		}
      break;
    case TBase::eRecvFromDown:
      sEvent = "RecvFromDown";
      break;
    case TBase::eRecvFromUp:
	  {
		  sEvent = "RecvFromUp";
		  TEventRecvFromUp* pRU = (TEventRecvFromUp*)pBE;
		  mTestControlTank.Recv(pRU->data, pRU->sizeData);
	  }
      break;
    case TBase::eSaveContext:
      sEvent = "SaveContext";
      break;
    case TBase::eRestoreContext:
      sEvent = "RestoreContext";
      break;
    case TBase::eTryLogin:
      sEvent = "TryLogin";
      break;
    case TBase::eResultLogin:
      sEvent = "ResultLogin";
      Connect(pBE);
      break;
    case TBase::eDestroyGroup:
      sEvent = "DestroyGroup";
      break;
    case TBase::eEnterInQueue:
      sEvent = "InQueueLoginClient";
      break;
  }
  GetLogger("Inner")->WriteF_time("MMOEngine: %s.\n",sEvent.data());
}
//---------------------------------------------------------------------------------------------
void TClientDeveloperTool_ClientTank::ParseCmd(std::vector<std::string>& arg)
{
  TInputCmdDevTool::TInput input;
  input.ip = boost::asio::ip::address_v4::from_string(ns_getSelfIP(0)).to_ulong();
  input.port = CLIENT_PORT;

  mInputCmd.SetDefParam(input);
  mInputCmd.SetArg(arg);
}
//---------------------------------------------------------------------------------------------
void TClientDeveloperTool_ClientTank::HandleFromGUI(nsEvent::TBaseEvent* pData)
{
  switch(pData->type)
  {
    case eKeyBoard:
    {
      TKeyEvent* pKey = (TKeyEvent*)pData;
      KeyEvent(pKey);
      break;
    }
    case eMouse:
    {
      TMouseEvent* pMouse = (TMouseEvent*)pData;
      MouseEvent(pMouse);
      break;
    }
    default:;
  }
}
//---------------------------------------------------------------------------------------------
void TClientDeveloperTool_ClientTank::ConnectUp()
{
  SetCurrentForm(mGameRoomPrepare);
  mTank  ->SetShow(true);
  mHangar->SetShow(true);
}
//---------------------------------------------------------------------------------------------
void TClientDeveloperTool_ClientTank::DisconnectUp()
{
  SetCurrentForm(mClientMain);
  mTank  ->SetShow(false);
  mHangar->SetShow(false);
}
//---------------------------------------------------------------------------------------------
void TClientDeveloperTool_ClientTank::SetCurrentForm(TBaseGUI* p)
{
  if(mCurrentForm)
    mCurrentForm->Hide();
  mCurrentForm = p;
  if(mCurrentForm)
    mCurrentForm->Show();
}
//---------------------------------------------------------------------------------------------
void TClientDeveloperTool_ClientTank::Connect(nsMMOEngine::TBaseEvent* pBE)
{
  nsMMOEngine::TEventResultLogin* pResult = (TEventResultLogin*)pBE;
  switch(pResult->res)
  {
    case nsMMOEngine::TMaster::eAccept:
      ConnectUp();
      break;
    case nsMMOEngine::TMaster::eReject:
      break;
  }
}
//---------------------------------------------------------------------------------------------
void TClientDeveloperTool_ClientTank::CreateObjects()
{
  CreateHangar();
  CreateTank();

  int cntObj = mComponent.mMOC->GetCountObject();
  for( int i = 0 ; i < cntObj ; i++ )
  {
    IBaseObject* pBO = mComponent.mMOC->Get(i);
    if(pBO==mTank)
      mIndexCurObj = i;
  }
  mComponent.mControlCamera->Link(mTank,IControlCamera::eCoord);
  mComponent.mControlCamera->SetDistObj(-10.0f);

  mComponent.mControlCamera->RotateRight(0.5f);
  mComponent.mControlCamera->RotateDown(0.5f);
}
//------------------------------------------------------------------------------------
void TClientDeveloperTool_ClientTank::CreateHangar()
{
  TMatrix16 w;
  SetMatrixIdentity(&w);
  w._43 -= 1.0f;
  mHangar = mComponent.mMOC->CreateObject(1);
  mHangar->SetWorld(&w);
  mComponent.mGraphicEngine->AddObject(mHangar);
  mHangar->SetShow(false);
}
//------------------------------------------------------------------------------------
void TClientDeveloperTool_ClientTank::CreateTank()
{
  TMatrix16 w;
  SetMatrixIdentity(&w);
  mTank = mComponent.mMOC->CreateObject(0);
  mTank->SetWorld(&w);
  mComponent.mGraphicEngine->AddObject(mTank);
  mTank->SetShow(false);

	mTestControlTank.SetTank((TTankTower*)mTank);
}
//---------------------------------------------------------------------------------------------
void TClientDeveloperTool_ClientTank::HandleFromDev(nsDevProtocol::TBase* pData)
{
  switch(pData->type)
  {
    case nsDevProtocol::DisconnectUp_Client:
      DisconnectUp();
      break;
  }
}
//---------------------------------------------------------------------------------------------
