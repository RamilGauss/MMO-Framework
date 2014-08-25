/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include <boost/asio/ip/impl/address_v4.ipp>

#include "DevTool_MasterTank.h"

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

  bool resOpen = mComponent.mMaster->Get()->Open(&nsMMOEngine::TDescOpen(input.port));
  BL_ASSERT(resOpen);

  mComponent.mMaster->Get()->ConnectUp(input.ip, SUPERSERVER_PORT);

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
    case MODULE_MMO_ENGINE_MASTER:
      HandleFromMMOEngine((nsMMOEngine::TBaseEvent*)pEvent->pContainer->GetPtr());
      break;
    case MODULE_PHYSIC_ENGINE:
      break;
    case MODULE_ALONE_GUI:
      HandleFromQt(pEvent);
      break;
  }
}
//---------------------------------------------------------------------------------------------
void TDevTool_MasterTank::HandleFromMMOEngine(nsMMOEngine::TBaseEvent* pBE)
{
  string sEvent;  
  switch(pBE->mType)
  {
    case nsMMOEngine::eConnectDown:
      sEvent = "ConnectDown";
      ConnectDown((nsMMOEngine::TEventConnectDown*)pBE);
      break;
    case nsMMOEngine::eDisconnectDown:
      sEvent = "DisconnectDown";
      DisconnectDown((nsMMOEngine::TEventDisconnectDown*)pBE);
      break;
    case nsMMOEngine::eConnectUp:
      sEvent = "ConnectUp";
      ConnectUp((nsMMOEngine::TEventConnectUp*)pBE);
      break;
    case nsMMOEngine::eDisconnectUp:
      sEvent = "DisconnectUp";
      DisconnectUp((nsMMOEngine::TEventDisconnectUp*)pBE);
      break;
    case nsMMOEngine::eError:
    {
      char sError[300];
      nsMMOEngine::TEventError* pEr = (nsMMOEngine::TEventError*)pBE;
      sprintf(sError, "Error code=%u", pEr->code);
      sEvent = sError;
    }
      break;
    case nsMMOEngine::eRecvFromDown:
      sEvent = "RecvFromDown";
      break;
    case nsMMOEngine::eRecvFromUp:
      sEvent = "RecvFromUp";
      break;
    case nsMMOEngine::eSaveContext:
      sEvent = "SaveContext";
      break;
    case nsMMOEngine::eRestoreContext:
      sEvent = "RestoreContext";
      break;
    case nsMMOEngine::eTryLogin:
      sEvent = "TryLogin";
      TryLogin((nsMMOEngine::TEventTryLogin*)pBE);
      break;
    case nsMMOEngine::eResultLogin:
      sEvent = "ResultLogin";
      break;
    case nsMMOEngine::eDestroyGroup:
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
void TDevTool_MasterTank::ConnectDown(nsMMOEngine::TEventConnectDown* pEvent)
{
  unsigned int* pID = new unsigned int(pEvent->id_session);
  mListID_SessionAdd.Add(pID);

  mComponent.mQtGUI->CallFromQtThreadByFunc(&TDevTool_MasterTank::AddSlaveQt,this);
}
//---------------------------------------------------------------------------------------------
void TDevTool_MasterTank::DisconnectDown(nsMMOEngine::TEventDisconnectDown* pEvent)
{
  unsigned int* pID = new unsigned int(pEvent->id_session);
  mListID_SessionDelete.Add(pID);

  mComponent.mQtGUI->CallFromQtThreadByFunc(&TDevTool_MasterTank::DeleteSlaveQt,this);
}
//---------------------------------------------------------------------------------------------
void TDevTool_MasterTank::TryLogin(nsMMOEngine::TEventTryLogin* pEvent)
{
  bool resAccept = true;
  mCounterClient ++;
  char result[100];
  sprintf(result,"hello, Client %u",mCounterClient);
  mComponent.mMaster->Get()->SetResultLogin(resAccept, 
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
void TDevTool_MasterTank::ConnectUp(nsMMOEngine::TEventConnectUp* pBE)
{
  mComponent.mQtGUI->CallFromQtThreadByFunc(&TDevTool_MasterTank::ConnectUpQt,this);
}
//---------------------------------------------------------------------------------------------
void TDevTool_MasterTank::DisconnectUp(nsMMOEngine::TEventDisconnectUp* pBE)
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
    bool resInfoSession = mComponent.mMaster->Get()->GetInfoSession(ID, desc.ip_port);
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
  bool res = mComponent.mMaster->Get()->TryCreateGroup(mListKeyAllClient, id_group);
  BL_ASSERT(res);
}
//---------------------------------------------------------------------------------------------
