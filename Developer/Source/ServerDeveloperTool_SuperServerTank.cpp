/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ServerDeveloperTool_SuperServerTank.h"

#include <boost/asio/ip/impl/address_v4.ipp>

#include "MakerObjectGeneral.h"
#include "SuperServerForm.h"
#include "../GameLib/NameSrcEventID.h"
#include "../QtLib/IQtLib.h"
#include "GlobalParam.h"
#include "NetSystem.h"
#include "BL_Debug.h"
#include "../GameLib/ITimer.h"

#include "DevProtocol.h"

using namespace std;
using namespace nsMMOEngine;

TServerDeveloperTool_SuperServerTank::TServerDeveloperTool_SuperServerTank()
{
	mMakerObjectGeneral = new TMakerObjectGeneral;
  mSuperServerForm   = NULL;
}
//---------------------------------------------------------------------------------
TServerDeveloperTool_SuperServerTank::~TServerDeveloperTool_SuperServerTank()
{
  delete mMakerObjectGeneral;
}
//---------------------------------------------------------------------------------
void TServerDeveloperTool_SuperServerTank::Init(TComponentServer* pComponent, std::vector<std::string>& arg)
{
  InitLog();
  mComponent = *pComponent;

  ParseCmd(arg);

  TInputCmdDevTool::TInput input;
  mInputCmd.Get(input);

  bool resOpen = mComponent.mNet.SuperServer->Open(&TDescOpen(input.port));
  BL_ASSERT(resOpen);

  mComponent.mQtGUI->CallFromQtThreadByFunc(&TServerDeveloperTool_SuperServerTank::InitQtForm,this);
  
  // для вызова каждый цикл, время выставить в 0
  //mComponent.mTimerFirstEvent->New(0);
  //mComponent.mTimerLastEvent->New(0);
}
//---------------------------------------------------------------------------------
int TServerDeveloperTool_SuperServerTank::GetTimeRefreshMS()
{
	return 100;
}
//---------------------------------------------------------------------------------
IMakerObjectGeneral* TServerDeveloperTool_SuperServerTank::GetMakerObjectGeneral()
{
	return mMakerObjectGeneral;
}
//------------------------------------------------------------------------------------
string TServerDeveloperTool_SuperServerTank::GetPathXMLFile()
{
	return "resources.xml";
}
//---------------------------------------------------------------------------------------------
void TServerDeveloperTool_SuperServerTank::Done()
{

}
//---------------------------------------------------------------------------------------------
void TServerDeveloperTool_SuperServerTank::Event(nsEvent::TEvent* pEvent)
{
  switch(pEvent->from)
  {
    case ID_SRC_EVENT_NETWORK_ENGINE:
      HandleFromMMOEngine((TBaseEvent*)pEvent->pContainer->GetPtr());
      break;
    case ID_SRC_EVENT_PHYSIC_ENGINE:
      break;
    case ID_SRC_EVENT_MANAGER_OBJECT_GENERAL:
      break;
    case ID_SRC_EVENT_QT_LIB:
      HandleFromQt(pEvent);
      break;
    case ID_SRC_EVENT_TIMER_FIRST_EVENT:
      break;
    case ID_SRC_EVENT_TIMER_LAST_EVENT:
      break;
  }
}
//---------------------------------------------------------------------------------------------
void TServerDeveloperTool_SuperServerTank::InitLog()
{
  GetLogger()->Register("Inner");// для логирования внутренних событий
  GetLogger()->Init("SuperServerTank");
}
//---------------------------------------------------------------------------------------------
void TServerDeveloperTool_SuperServerTank::InitQtForm()
{
  mSuperServerForm = new SuperServerForm;
  mSuperServerForm->show();
}
//---------------------------------------------------------------------------------------------
void TServerDeveloperTool_SuperServerTank::HandleFromQt(nsEvent::TEvent* pEvent)
{
  nsDevProtocol::TBase* pH = (nsDevProtocol::TBase*)pEvent->pContainer->GetPtr();
  switch(pH->type)
  {
    case nsDevProtocol::Exit:
      mSuperServerForm = NULL;
      Exit();
      break;
    default:;
  }
}
//---------------------------------------------------------------------------------------------
void TServerDeveloperTool_SuperServerTank::HandleFromMMOEngine(TBaseEvent* pBE)
{
  string sEvent;  
  switch(pBE->mType)
  {
    case TBase::eConnectDown:
      sEvent = "ConnectDown";
      ConnectDown((TEventConnectDown*)pBE);
      break;
    case TBase::eDisconnectDown:
      sEvent = "DisconnectDown";
      DisconnectDown((TEventDisconnectDown*)pBE);
      break;
    case TBase::eConnectUp:
      sEvent = "ConnectUp";
      break;
    case TBase::eDisconnectUp:
      sEvent = "DisconnectUp";
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
      {
        // ###
        //unsigned int id_session = ((TEventRecvFromDown*)pBE)->id_session;
        //char s = 's';
        //TBreakPacket bp;
        //bp.PushBack(&s, sizeof(s));
        //mComponent.mNet.SuperServer->SendDown(id_session,bp);
      }
      break;
    case TBase::eRecvFromUp:
      sEvent = "RecvFromUp";
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
      break;
    case TBase::eDestroyGroup:
      sEvent = "DestroyGroup";
      break;
  }
  GetLogger("Inner")->WriteF_time("MMOEngine: %s.\n",sEvent.data());
}
//---------------------------------------------------------------------------------------------
void TServerDeveloperTool_SuperServerTank::ConnectDown(TEventConnectDown* pEvent)
{
  unsigned int* pID = new unsigned int(pEvent->id_session);
  mListID_SessionAdd.Add(pID);

  mComponent.mQtGUI->CallFromQtThreadByFunc(&TServerDeveloperTool_SuperServerTank::AddMasterQt,this);
}
//---------------------------------------------------------------------------------------------
void TServerDeveloperTool_SuperServerTank::DisconnectDown(TEventDisconnectDown* pEvent)
{
  unsigned int* pID = new unsigned int(pEvent->id_session);
  mListID_SessionDelete.Add(pID);

  mComponent.mQtGUI->CallFromQtThreadByFunc(&TServerDeveloperTool_SuperServerTank::DeleteMasterQt,this);
}
//---------------------------------------------------------------------------------------------
void TServerDeveloperTool_SuperServerTank::ParseCmd(std::vector<std::string>& arg)
{
  TInputCmdDevTool::TInput input;
  input.ip = boost::asio::ip::address_v4::from_string(ns_getSelfIP(0)).to_ulong();
  input.port = SUPERSERVER_PORT;

  mInputCmd.SetDefParam(input);
  mInputCmd.SetArg(arg);
}
//---------------------------------------------------------------------------------------------
void TServerDeveloperTool_SuperServerTank::AddMasterQt()
{
  unsigned int** ppFirst = mListID_SessionAdd.GetFirst();
  while(ppFirst)
  {
    unsigned int ID = *(*ppFirst);
    
    SuperServerForm::TDesc desc;
    desc.id_session = ID;
    bool resInfoSession = mComponent.mNet.SuperServer->GetInfoSession(ID, desc.ip_port);
    BL_ASSERT(resInfoSession);
    if(mSuperServerForm)
      mSuperServerForm->Add(desc);
    // следующий ID
    mListID_SessionAdd.Remove(ppFirst);
    ppFirst = mListID_SessionAdd.GetFirst();
  }
}
//---------------------------------------------------------------------------------------------
void TServerDeveloperTool_SuperServerTank::DeleteMasterQt()
{
  unsigned int** ppFirst = mListID_SessionDelete.GetFirst();
  while(ppFirst)
  {
    unsigned int ID = *(*ppFirst);

    if(mSuperServerForm)
      mSuperServerForm->Delete(ID);
    // следующий ID
    mListID_SessionDelete.Remove(ppFirst);
    ppFirst = mListID_SessionDelete.GetFirst();
  }
}
//---------------------------------------------------------------------------------------------