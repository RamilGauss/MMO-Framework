/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "DevTool_MasterTank.h"

#include <boost/asio/ip/impl/address_v4.ipp>

#include "PrototypeMMOMaster.h"
#include "NetSystem.h"
#include "GlobalParam.h"
#include "MasterForm.h"
#include "../QtLib/IQtLib.h"
#include "DevProtocol.h"

using namespace std;

TDevTool_MasterTank::TDevTool_MasterTank()
{
  mCounterClient = 0;

  mMasterForm = NULL;
}
//---------------------------------------------------------------------------------
TDevTool_MasterTank::~TDevTool_MasterTank()
{

}
//---------------------------------------------------------------------------------
void TDevTool_MasterTank::Init(vector<string>& arg)
{
  InitLog();
  ParseCmd(arg);

  TInputCmdDevTool::TInput input;
  mInputCmd.Get(input);

  bool resOpen = mComponent.mNet.Master->Open(&PrototypeMMODescOpen(input.port));
  BL_ASSERT(resOpen);

  mComponent.mNet.Master->ConnectUp(input.ip, SUPERSERVER_PORT);

  mComponent.mQtGUI->CallFromQtThreadByFunc(&TDevTool_MasterTank::InitQtForm,this);
}
//---------------------------------------------------------------------------------
void TDevTool_MasterTank::Done()
{

}
//---------------------------------------------------------------------------------------------
void TDevTool_MasterTank::Event(nsEvent::TEvent* pEvent)
{
  switch(pEvent->type_object)
  {
    case PROTOTYPE_TYPE_MMO_ENGINE_MASTER:
      HandleFromMMOEngine((PrototypeMMOBaseEvent*)pEvent->pContainer->GetPtr());
      break;
    case PROTOTYPE_TYPE_PHYSIC_ENGINE:
      break;
    case PROTOTYPE_TYPE_MANAGER_OBJECT_GENERAL:
      break;
    case PROTOTYPE_TYPE_ALONE_GUI:
      HandleFromQt(pEvent);
      break;
  }
}
//---------------------------------------------------------------------------------------------
void TDevTool_MasterTank::HandleFromMMOEngine(PrototypeMMOBaseEvent* pBE)
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
      ConnectUp((PrototypeMMOEventConnectUp*)pBE);
      break;
    case eDisconnectUp:
      sEvent = "DisconnectUp";
      DisconnectUp((PrototypeMMOEventDisconnectUp*)pBE);
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
      TryLogin((PrototypeMMOEventTryLogin*)pBE);
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
void TDevTool_MasterTank::InitLog()
{
  GetLogger()->Register("Inner");// для логирования внутренних событий
  GetLogger()->Init("MasterTank");
}
//---------------------------------------------------------------------------------------------
void TDevTool_MasterTank::ConnectDown(PrototypeMMOEventConnectDown* pEvent)
{
  unsigned int* pID = new unsigned int(pEvent->id_session);
  mListID_SessionAdd.Add(pID);

  mComponent.mQtGUI->CallFromQtThreadByFunc(&TDevTool_MasterTank::AddSlaveQt,this);
}
//---------------------------------------------------------------------------------------------
void TDevTool_MasterTank::DisconnectDown(PrototypeMMOEventDisconnectDown* pEvent)
{
  unsigned int* pID = new unsigned int(pEvent->id_session);
  mListID_SessionDelete.Add(pID);

  mComponent.mQtGUI->CallFromQtThreadByFunc(&TDevTool_MasterTank::DeleteSlaveQt,this);
}
//---------------------------------------------------------------------------------------------
void TDevTool_MasterTank::TryLogin(PrototypeMMOEventTryLogin* pEvent)
{
  bool resAccept = true;
  mCounterClient ++;
  char result[100];
  sprintf(result,"hello, Client %u",mCounterClient);
  mComponent.mNet.Master->SetResultLogin(resAccept, 
    pEvent->id_session, mCounterClient,
    (void*)&result[0], strlen(result));

	mListKeyAllClient.push_back(mCounterClient);
}
//---------------------------------------------------------------------------------------------
void TDevTool_MasterTank::InitQtForm()
{
  mMasterForm = new MasterForm;
  mMasterForm->show();
}
//---------------------------------------------------------------------------------------------
void TDevTool_MasterTank::HandleFromQt(nsEvent::TEvent* pEvent)
{
  nsDevProtocol::TBase* pH = (nsDevProtocol::TBase*)pEvent->pContainer->GetPtr();
  switch(pH->type)
  {
    case nsDevProtocol::Exit:
      mMasterForm = NULL;
      Exit();
      break;
    case nsDevProtocol::CreateGroup:
      CreateGroup();
      break;
    default:;
  }
}
//---------------------------------------------------------------------------------------------
void TDevTool_MasterTank::ConnectUp(PrototypeMMOEventConnectUp* pBE)
{
  mComponent.mQtGUI->CallFromQtThreadByFunc(&TDevTool_MasterTank::ConnectUpQt,this);
}
//---------------------------------------------------------------------------------------------
void TDevTool_MasterTank::DisconnectUp(PrototypeMMOEventDisconnectUp* pBE)
{
  mComponent.mQtGUI->CallFromQtThreadByFunc(&TDevTool_MasterTank::DisconnectUpQt,this);
}
//---------------------------------------------------------------------------------------------
void TDevTool_MasterTank::ConnectUpQt()
{
  if(mMasterForm)
    mMasterForm->SetConnect(true);
}
//---------------------------------------------------------------------------------------------
void TDevTool_MasterTank::DisconnectUpQt()
{
  if(mMasterForm)
    mMasterForm->SetConnect(false);
}
//---------------------------------------------------------------------------------------------
void TDevTool_MasterTank::ParseCmd(std::vector<std::string>& arg)
{
  TInputCmdDevTool::TInput input;
  input.ip = boost::asio::ip::address_v4::from_string(ns_getSelfIP(0)).to_ulong();
  input.port = MASTER_PORT;
 
  mInputCmd.SetDefParam(input);
  mInputCmd.SetArg(arg);
}
//---------------------------------------------------------------------------------------------
void TDevTool_MasterTank::AddSlaveQt()
{
  unsigned int** ppFirst = mListID_SessionAdd.GetFirst();
  while(ppFirst)
  {
    unsigned int ID = *(*ppFirst);

    MasterForm::TDesc desc;
    desc.id_session = ID;
    bool resInfoSession = mComponent.mNet.Master->GetInfoSession(ID, desc.ip_port);
    BL_ASSERT(resInfoSession);
    if(mMasterForm)
      mMasterForm->Add(desc);
    // следующий ID
    mListID_SessionAdd.Remove(ppFirst);
    ppFirst = mListID_SessionAdd.GetFirst();
  }
}
//---------------------------------------------------------------------------------------------
void TDevTool_MasterTank::DeleteSlaveQt()
{
  unsigned int** ppFirst = mListID_SessionDelete.GetFirst();
  while(ppFirst)
  {
    unsigned int ID = *(*ppFirst);
    if(mMasterForm)
      mMasterForm->Delete(ID);
    // следующий ID
    mListID_SessionDelete.Remove(ppFirst);
    ppFirst = mListID_SessionDelete.GetFirst();
  }
}
//---------------------------------------------------------------------------------------------
void TDevTool_MasterTank::CreateGroup()
{
  unsigned int id_group;
  bool res = mComponent.mNet.Master->TryCreateGroup(mListKeyAllClient, id_group);
  BL_ASSERT(res);
}
//---------------------------------------------------------------------------------------------
