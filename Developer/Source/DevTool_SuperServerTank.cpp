/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "DevTool_SuperServerTank.h"

#include <boost/asio/ip/impl/address_v4.ipp>

#include "SuperServerForm.h"
#include "../QtLib/IQtLib.h"
#include "GlobalParam.h"
#include "NetSystem.h"
#include "BL_Debug.h"
#include "PrototypeTimer.h"

#include "DevProtocol.h"
#include "PrototypeMMOStructs.h"
#include "PrototypeMMOSuperServer.h"

using namespace std;

TDevTool_SuperServerTank::TDevTool_SuperServerTank()
{
  mSuperServerForm = NULL;
}
//---------------------------------------------------------------------------------
TDevTool_SuperServerTank::~TDevTool_SuperServerTank()
{

}
//---------------------------------------------------------------------------------
void TDevTool_SuperServerTank::Init(std::vector<std::string>& arg)
{
  InitLog();
  ParseCmd(arg);

  TInputCmdDevTool::TInput input;
  mInputCmd.Get(input);

  bool resOpen = mComponent.mNet.SuperServer->Open(&PrototypeMMODescOpen(input.port));
  BL_ASSERT(resOpen);

  mComponent.mQtGUI->CallFromQtThreadByFunc(&TDevTool_SuperServerTank::InitQtForm,this);
  
  // для вызова каждый цикл, время выставить в 0
  //mComponent.mTimerFirstEvent->New(0);
  //mComponent.mTimerLastEvent->New(0);
}
//---------------------------------------------------------------------------------
void TDevTool_SuperServerTank::Done()
{

}
//---------------------------------------------------------------------------------------------
void TDevTool_SuperServerTank::Event(nsEvent::TEvent* pEvent)
{
  switch(pEvent->type_object)
  {
    case PROTOTYPE_TYPE_MMO_ENGINE_SUPER_SERVER:
      HandleFromMMOEngine((PrototypeMMOBaseEvent*)pEvent->pContainer->GetPtr());
      break;
    case PROTOTYPE_TYPE_PHYSIC_ENGINE:
      break;
    case PROTOTYPE_TYPE_MANAGER_OBJECT_GENERAL:
      break;
    case PROTOTYPE_TYPE_ALONE_GUI:
      HandleFromQt(pEvent);
      break;
    case PROTOTYPE_TYPE_TIMER:
      break;
  }
}
//---------------------------------------------------------------------------------------------
void TDevTool_SuperServerTank::InitLog()
{
  GetLogger()->Register("Inner");// для логирования внутренних событий
  GetLogger()->Init("SuperServerTank");
}
//---------------------------------------------------------------------------------------------
void TDevTool_SuperServerTank::InitQtForm()
{
  mSuperServerForm = new SuperServerForm;
  mSuperServerForm->show();
}
//---------------------------------------------------------------------------------------------
void TDevTool_SuperServerTank::HandleFromQt(nsEvent::TEvent* pEvent)
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
void TDevTool_SuperServerTank::HandleFromMMOEngine(PrototypeMMOBaseEvent* pBE)
{
  string sEvent;  
  switch(pBE->mType)
  {
    case eConnectDown:
      sEvent = "ConnectDown";
      ConnectDown((PrototypeMMOEventConnectDown*)pBE);
      break;
    case eDisconnectDown:
      sEvent = "DisconnectDown";
      DisconnectDown((PrototypeMMOEventDisconnectDown*)pBE);
      break;
    case eConnectUp:
      sEvent = "ConnectUp";
      break;
    case eDisconnectUp:
      sEvent = "DisconnectUp";
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
      {
        // ###
        //unsigned int id_session = ((TEventRecvFromDown*)pBE)->id_session;
        //char s = 's';
        //TBreakPacket bp;
        //bp.PushBack(&s, sizeof(s));
        //mComponent.mNet.SuperServer->SendDown(id_session,bp);
      }
      break;
    case eRecvFromUp:
      sEvent = "RecvFromUp";
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
      break;
    case eDestroyGroup:
      sEvent = "DestroyGroup";
      break;
  }
  GetLogger("Inner")->WriteF_time("MMOEngine: %s.\n",sEvent.data());
}
//---------------------------------------------------------------------------------------------
void TDevTool_SuperServerTank::ConnectDown(PrototypeMMOEventConnectDown* pEvent)
{
  unsigned int* pID = new unsigned int(pEvent->id_session);
  mListID_SessionAdd.Add(pID);

  mComponent.mQtGUI->CallFromQtThreadByFunc(&TDevTool_SuperServerTank::AddMasterQt,this);
}
//---------------------------------------------------------------------------------------------
void TDevTool_SuperServerTank::DisconnectDown(PrototypeMMOEventDisconnectDown* pEvent)
{
  unsigned int* pID = new unsigned int(pEvent->id_session);
  mListID_SessionDelete.Add(pID);

  mComponent.mQtGUI->CallFromQtThreadByFunc(&TDevTool_SuperServerTank::DeleteMasterQt,this);
}
//---------------------------------------------------------------------------------------------
void TDevTool_SuperServerTank::ParseCmd(std::vector<std::string>& arg)
{
  TInputCmdDevTool::TInput input;
  input.ip = boost::asio::ip::address_v4::from_string(ns_getSelfIP(0)).to_ulong();
  input.port = SUPERSERVER_PORT;

  mInputCmd.SetDefParam(input);
  mInputCmd.SetArg(arg);
}
//---------------------------------------------------------------------------------------------
void TDevTool_SuperServerTank::AddMasterQt()
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
void TDevTool_SuperServerTank::DeleteMasterQt()
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