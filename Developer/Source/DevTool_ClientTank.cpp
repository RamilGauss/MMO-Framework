/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
√удаков –амиль —ергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "DevTool_ClientTank.h"
#include <string.h>

#include "Logger.h"
#include "HiTimer.h"
#include "PrototypeControlCamera.h"
#include "IXML.h"

#include "MakerObjectGeneral.h"

#include "PrototypeMOG.h"
#include "IBaseObjectGeneral.h"
#include "ManagerStateMachine.h"
#include "PrototypeGraphicEngine.h"
#include "PrototypeMMOClient.h"
#include "ShareMisc.h"
#include "NetSystem.h"
#include "PrototypeMMOBaseEvent.h"
#include "file_operation.h"
#include "StorePathResources.h"
#include "MapXML_Field.h"
#include "PrototypeMMOMaster.h"
#include "PrototypeMMOEvents.h"
#include "PrototypeTimer.h"
#include "PrototypeMMOEnum.h"
#include "GlobalParam.h"


using namespace std;
using namespace nsMathTools;
using namespace nsEvent;
using namespace nsKey;

#define LOG_TIME_LOAD_EDITOR_MODEL

#define DELTA_MOVE     0.2f //0.4f
#define DELTA_ROTATE   0.01f
#define ASPECT_MOUSE_X 0.002f
#define ASPECT_MOUSE_Y 0.002f

#define UP 1000000

TDevTool_ClientTank::TDevTool_ClientTank()
{
  flgDragCamera = false;

  mIndexCurObj = 0;

  mClientMain      = new TClientMain;
  mGameRoomPrepare = new TGameRoomPrepare;
  mWaitForm        = new TWaitForm;

  mCurrentForm     = NULL;

  mTank   = NULL;
  mHangar = NULL;
}
//------------------------------------------------------------------------------------
TDevTool_ClientTank::~TDevTool_ClientTank()
{

}
//------------------------------------------------------------------------------------
void TDevTool_ClientTank::MouseEvent(TMouseEvent* pEvent)
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
      mComponent.mGraphicEngine->GetControlCamera()->AddDistObj(float(pEvent->delta_wheel)/100.0f);
      break;
    case nsEvent::eMove:
      if(flgDragCamera)
      {
        float dRight = float(pEvent->x - mOldX)*ASPECT_MOUSE_X;
        float dDown  = float(pEvent->y - mOldY)*ASPECT_MOUSE_Y;
        mComponent.mGraphicEngine->GetControlCamera()->RotateRight(dRight);
        mComponent.mGraphicEngine->GetControlCamera()->RotateDown(dDown);
        
        mOldX = pEvent->x;
        mOldY = pEvent->y;
      }
			break;
  }
}
//------------------------------------------------------------------------------------
void TDevTool_ClientTank::KeyEvent(TKeyEvent* pEvent)
{
  unsigned int v;
  bool res = mComponent.mMStateMachine.GetValue(mIDkey,pEvent->key,v);
  v |= (pEvent->pressed?0:UP);
  if(res)
  switch(v)
  {
    // клавиатура
    case e_W://W
      mComponent.mGraphicEngine->GetControlCamera()->SetSpeedForward(DELTA_MOVE);
      break;
    case e_W|UP://W
      mComponent.mGraphicEngine->GetControlCamera()->SetSpeedForward(0);
      break;
    case e_S://S
      mComponent.mGraphicEngine->GetControlCamera()->SetSpeedForward(-DELTA_MOVE);
      break;
    case e_S|UP://S
      mComponent.mGraphicEngine->GetControlCamera()->SetSpeedForward(0);
      break;
    case e_A://A
      mComponent.mGraphicEngine->GetControlCamera()->SetSpeedRight(-DELTA_MOVE);
      break;
    case e_A|UP://A
      mComponent.mGraphicEngine->GetControlCamera()->SetSpeedRight(0);
      break;
    case e_D://D
      mComponent.mGraphicEngine->GetControlCamera()->SetSpeedRight(DELTA_MOVE);
      break;
    case e_D|UP://D
      mComponent.mGraphicEngine->GetControlCamera()->SetSpeedRight(0);
      break;
    case e_Q://Q
      mComponent.mGraphicEngine->GetControlCamera()->SetSpeedUp(DELTA_MOVE);
      break;
    case e_Q|UP://Q
      mComponent.mGraphicEngine->GetControlCamera()->SetSpeedUp(0);
      break;
    case e_E://E
      mComponent.mGraphicEngine->GetControlCamera()->SetSpeedUp(-DELTA_MOVE);
      break;
    case e_E|UP://E
      mComponent.mGraphicEngine->GetControlCamera()->SetSpeedUp(0);
      break;
    // мышь
    case e_Numpad4:// влево 4
      mComponent.mGraphicEngine->GetControlCamera()->RotateRight(-DELTA_ROTATE);
      break;
    case e_Numpad6:// вправо 6
      mComponent.mGraphicEngine->GetControlCamera()->RotateRight(DELTA_ROTATE);
      break;
    case e_Numpad8:// вверх 8
      mComponent.mGraphicEngine->GetControlCamera()->RotateDown(-DELTA_ROTATE);
      break;
    case e_Numpad2:// вниз 2
      mComponent.mGraphicEngine->GetControlCamera()->RotateDown(DELTA_ROTATE);
      break;
    case e_Numpad7:// вращатьс€ влево 7
      mComponent.mGraphicEngine->GetControlCamera()->Roll(DELTA_ROTATE);
      break;
    case e_Numpad9:// вращатьс€ вправо 9
      mComponent.mGraphicEngine->GetControlCamera()->Roll(-DELTA_ROTATE);
      break;
    case e_C:// сбросить ориентацию камеры C
      mComponent.mGraphicEngine->GetControlCamera()->ClearRotate();
      break;
    case e_V:// сбросить ориентацию камеры V
    {
      TVector3 v;
      v.x = 0.0f;
      v.y = 0.0f;
      v.z = 0.0f;
      mComponent.mGraphicEngine->GetControlCamera()->SetPositionLookAt(&v);
      break;
    }
    case e_B: // B 
    {
      IBaseObject* pBO = mComponent.mMOG->Get(mIndexCurObj);
      mComponent.mGraphicEngine->GetControlCamera()->Link(pBO,PrototypeControlCamera::eCoord);
      mIndexCurObj++;
      mIndexCurObj %= mComponent.mMOG->GetCountObject();
      break;
    }
    case e_N: 
      mComponent.mGraphicEngine->GetControlCamera()->Unlink();
      break;
    case e_O: 
      break;
  }
}
//--------------------------------------------------------------------
void TDevTool_ClientTank::Init(vector<string>& arg )
{
  InitLog();
  ParseCmd(arg);

  TInputCmdDevTool::TInput input;
  mInputCmd.Get(input);
  // GUI
  mComponent.mGUI.Add(string("mClientMain"),mClientMain);
  mComponent.mGUI.Add(string("mGameRoomPrepare"),mGameRoomPrepare);
  mComponent.mGUI.Add(string("mWaitForm"),mWaitForm);
  // показать форму
  SetCurrentForm(mClientMain);
  // подстроитьс€
  mComponent.mGraphicEngine->Resize();
  // HotKey
	if(GetStorePathResources()->GetCount("game_param")>0)
	{
		string sGameParam = GetStorePathResources()->GetSecond("game_param");
		bool resLoadMSM = mComponent.mMStateMachine.Load(sGameParam.data(), mIDkey);
		BL_ASSERT(resLoadMSM);
	}
	else
		BL_FIX_BUG();

  CreateObjects();

  mComponent.mTimer->New(0);
}
//------------------------------------------------------------------------------------
void TDevTool_ClientTank::Done()
{
  delete mClientMain;
  mClientMain = NULL;
  delete mGameRoomPrepare;
  mGameRoomPrepare = NULL;
  delete mWaitForm;
  mWaitForm = NULL;
}        
//---------------------------------------------------------------------------------------------
void TDevTool_ClientTank::InitLog()
{
  GetLogger()->Register("Inner");// дл€ логировани€ внутренних событий
  GetLogger()->Init("ClientTank");
}
//---------------------------------------------------------------------------------------------
void TDevTool_ClientTank::Event(nsEvent::TEvent* pEvent)
{
  switch(pEvent->type_object)
  {
		case PROTOTYPE_TYPE_GRAPHIC_ENGINE:
      HandleFromGUI((nsEvent::TBaseEvent*)pEvent->pContainer->GetPtr());
      break;
		case PROTOTYPE_TYPE_MMO_ENGINE_CLIENT:
      HandleFromMMOEngine((PrototypeMMOBaseEvent*)pEvent->pContainer->GetPtr());
      break;
    case PROTOTYPE_TYPE_PHYSIC_ENGINE:
      break;
    case PROTOTYPE_TYPE_MANAGER_OBJECT_GENERAL:
      break;
    case PROTOTYPE_TYPE_TIMER:
			mTestControlTank.SetupParamForNow();
      break;
    case PROTOTYPE_TYPE_DEV_TOOL:
      HandleFromDev((nsDevProtocol::TBase*)pEvent->pContainer->GetPtr());
      break;
  }
}
//---------------------------------------------------------------------------------------------
void TDevTool_ClientTank::HandleFromMMOEngine(PrototypeMMOBaseEvent* pBE)
{
  string sEvent;  
  switch(pBE->mType)
  {
    case eConnectDown:
      sEvent = "ConnectDown";
      break;
    case eDisconnectDown:
      sEvent = "DisconnectDown";
      break;
    case eConnectUp:
      sEvent = "ConnectUp";
      break;
    case eDisconnectUp:
      sEvent = "DisconnectUp";
      DisconnectUp();
      break;
    case eError:
		{
			char sError[300];
			PrototypeMMOEventError* pEr = (PrototypeMMOEventError*)pBE;
			sprintf(sError, "Error code=%u", pEr->code);
			sEvent = sError;
		}
      break;
    case eRecvFromDown:
      sEvent = "RecvFromDown";
      break;
    case eRecvFromUp:
	  {
		  sEvent = "RecvFromUp";
		  PrototypeMMOEventRecvFromUp* pRU = (PrototypeMMOEventRecvFromUp*)pBE;
		  mTestControlTank.Recv(pRU->data, pRU->sizeData);
	  }
      break;
    case eSaveContext:
      sEvent = "SaveContext";
      break;
    case eRestoreContext:
      sEvent = "RestoreContext";
      break;
    case eTryLogin:
      sEvent = "TryLogin";
      break;
    case eResultLogin:
      sEvent = "ResultLogin";
      Connect(pBE);
      break;
    case eDestroyGroup:
      sEvent = "DestroyGroup";
      break;
    case eEnterInQueue:
      sEvent = "InQueueLoginClient";
      break;
  }
  GetLogger("Inner")->WriteF_time("MMOEngine: %s.\n",sEvent.data());
}
//---------------------------------------------------------------------------------------------
void TDevTool_ClientTank::ParseCmd(std::vector<std::string>& arg)
{
  TInputCmdDevTool::TInput input;
  input.ip = boost::asio::ip::address_v4::from_string(ns_getSelfIP(0)).to_ulong();
  input.port = CLIENT_PORT;

  mInputCmd.SetDefParam(input);
  mInputCmd.SetArg(arg);
}
//---------------------------------------------------------------------------------------------
void TDevTool_ClientTank::HandleFromGUI(nsEvent::TBaseEvent* pData)
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
void TDevTool_ClientTank::ConnectUp()
{
  SetCurrentForm(mGameRoomPrepare);
  mTank  ->SetShow(true);
  mHangar->SetShow(true);
}
//---------------------------------------------------------------------------------------------
void TDevTool_ClientTank::DisconnectUp()
{
  SetCurrentForm(mClientMain);
  mTank  ->SetShow(false);
  mHangar->SetShow(false);
}
//---------------------------------------------------------------------------------------------
void TDevTool_ClientTank::SetCurrentForm(TBaseGUI* p)
{
  if(mCurrentForm)
    mCurrentForm->Hide();
  mCurrentForm = p;
  if(mCurrentForm)
    mCurrentForm->Show();
}
//---------------------------------------------------------------------------------------------
void TDevTool_ClientTank::Connect(PrototypeMMOBaseEvent* pBE)
{
  PrototypeMMOEventResultLogin* pResult = (PrototypeMMOEventResultLogin*)pBE;
  switch(pResult->res)
  {
    case PrototypeMMOMaster::eAccept:
      ConnectUp();
      break;
    case PrototypeMMOMaster::eReject:
      break;
  }
}
//---------------------------------------------------------------------------------------------
void TDevTool_ClientTank::CreateObjects()
{
  CreateHangar();
  CreateTank();

  int cntObj = mComponent.mMOG->GetCountObject();
  for( int i = 0 ; i < cntObj ; i++ )
  {
    IBaseObject* pBO = mComponent.mMOG->Get(i);
    if(pBO==mTank)
      mIndexCurObj = i;
  }
  mComponent.mGraphicEngine->GetControlCamera()->Link(mTank,PrototypeControlCamera::eCoord);
  mComponent.mGraphicEngine->GetControlCamera()->SetDistObj(-10.0f);

  mComponent.mGraphicEngine->GetControlCamera()->RotateRight(0.5f);
  mComponent.mGraphicEngine->GetControlCamera()->RotateDown(0.5f);
}
//------------------------------------------------------------------------------------
void TDevTool_ClientTank::CreateHangar()
{
  TMatrix16 w;
  SetMatrixIdentity(&w);
  w.s._43 -= 1.0f;
  mHangar = mComponent.mMOG->CreateObject(1);
  mHangar->SetWorld(&w);
  mComponent.mGraphicEngine->AddObject(mHangar);
  mHangar->SetShow(false);
}
//------------------------------------------------------------------------------------
void TDevTool_ClientTank::CreateTank()
{
  TMatrix16 w;
  SetMatrixIdentity(&w);
  mTank = mComponent.mMOG->CreateObject(0);
  mTank->SetWorld(&w);
  mComponent.mGraphicEngine->AddObject(mTank);
  mTank->SetShow(false);

	mTestControlTank.SetTank((TTankTower*)mTank);
}
//---------------------------------------------------------------------------------------------
void TDevTool_ClientTank::HandleFromDev(nsDevProtocol::TBase* pData)
{
  switch(pData->type)
  {
    case nsDevProtocol::DisconnectUp_Client:
      DisconnectUp();
      break;
  }
}
//---------------------------------------------------------------------------------------------
