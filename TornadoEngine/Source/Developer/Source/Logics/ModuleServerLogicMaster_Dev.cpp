/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include <boost/asio/ip/impl/address_v4.ipp>

#include "ModuleServerLogicMaster_Dev.h"
#include "ListModules.h"
#include "GlobalParam.h"
#include "NetSystem.h"
#include "Logger.h"

#include "ModuleMMOEngineMaster.h"
#include "Events.h"

TModuleServerLogicMaster_Dev::TModuleServerLogicMaster_Dev()
{
  SetCycleTime(100);//###

  mMasterForm = NULL;
  // значения по-умолчанию для параметров командной строки
  TInputCmdDevTool::TInput input;
  input.ip_dst   = boost::asio::ip::address_v4::from_string(ns_getSelfIP(0)).to_ulong();
  input.port_self = MASTER_PORT;
  input.port_dst  = SUPER_SERVER_PORT;

  mInputCmd.SetDefParam(input);
}
//------------------------------------------------------------------------------
bool TModuleServerLogicMaster_Dev::WorkServer()
{
  return true;
}
//------------------------------------------------------------------------------
void TModuleServerLogicMaster_Dev::EndWork()
{

}
//------------------------------------------------------------------------------
void TModuleServerLogicMaster_Dev::Input(int id, void* p, int size)
{
  switch(id)
  {
    case nsListModules::AloneGUI:
      break;
    case nsListModules::MMOEngineMaster:
      HandleFromMMOEngine((nsMMOEngine::TBaseEvent*)p);
      break;
    case nsListModules::DataBase:
      break;
    case nsListModules::Timer:
    {
      // события от таймера
      int a = 0;
    }
      break;
  }
}
//------------------------------------------------------------------------------
void TModuleServerLogicMaster_Dev::InitForms()
{
  mMasterForm = new TMasterForm;
  mMasterForm->show();
}
//------------------------------------------------------------------------------
void TModuleServerLogicMaster_Dev::StartEvent()
{
  CallBackModule(nsListModules::AloneGUI, &TModuleServerLogicMaster_Dev::InitForms);
  CallBackModule(nsListModules::MMOEngineMaster, &TModuleServerLogicMaster_Dev::ConnectToSuperServer);
}
//----------------------------------------------------------
void TModuleServerLogicMaster_Dev::StopEvent()
{

}
//----------------------------------------------------------
void TModuleServerLogicMaster_Dev::ConnectToSuperServer()
{
  TInputCmdDevTool::TInput input;
  mInputCmd.Get(input);

  nsMMOEngine::TDescOpen descOpen;
  descOpen.port = input.port_self;
  bool resOpen = mComp.pMMOEngineMaster->Get()->Open(&descOpen);
  mComp.pMMOEngineMaster->Get()->ConnectUp(input.ip_dst, input.port_dst, "1", 1, "1", 1);
}
//----------------------------------------------------------
void TModuleServerLogicMaster_Dev::HandleFromMMOEngine(nsMMOEngine::TBaseEvent* pBE)
{
  std::string sEvent;  
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
void TModuleServerLogicMaster_Dev::InitLog()
{
  GetLogger()->Register("Inner");// для логирования внутренних событий
  GetLogger()->Init("Master");
}
//---------------------------------------------------------------------------------------------
void TModuleServerLogicMaster_Dev::ConnectDown(nsMMOEngine::TEventConnectDown* pEvent)
{
  unsigned int* pID = new unsigned int;
  *pID = pEvent->id_session;
  mListSessionAdd.Add(pID);

  CallBackModule(nsListModules::MMOEngineMaster, &TModuleServerLogicMaster_Dev::ConnectDownMMOEngine);
}
//---------------------------------------------------------------------------------------------
void TModuleServerLogicMaster_Dev::ConnectDownMMOEngine()
{
  unsigned int** ppFirst = mListSessionAdd.GetFirst();
  while(ppFirst)
  {
    unsigned int* pID_session = *ppFirst;

    TMasterForm::TDesc* pDesc = new TMasterForm::TDesc;
    pDesc->id_session = *pID_session;
    bool resInfoSession = mComp.pMMOEngineMaster->Get()->GetInfoSession(pDesc->id_session, pDesc->ip_port);
    BL_ASSERT(resInfoSession);
    mListID_SessionAdd.Add(pDesc);
    // следующий ID
    mListSessionAdd.Remove(ppFirst);
    ppFirst = mListSessionAdd.GetFirst();
  }
  
  CallBackModule(nsListModules::AloneGUI, &TModuleServerLogicMaster_Dev::AddSlaveQt);
}
//---------------------------------------------------------------------------------------------
void TModuleServerLogicMaster_Dev::DisconnectDown(nsMMOEngine::TEventDisconnectDown* pEvent)
{
  TMasterForm::TDesc* pDesc = new TMasterForm::TDesc;
  pDesc->id_session = pEvent->id_session;
  mListID_SessionDelete.Add(pDesc);

  CallBackModule(nsListModules::AloneGUI, &TModuleServerLogicMaster_Dev::DeleteSlaveQt);
}
//---------------------------------------------------------------------------------------------
void TModuleServerLogicMaster_Dev::TryLogin(nsMMOEngine::TEventTryLogin* pEvent)
{
  unsigned int* pID = new unsigned int;
  *pID = pEvent->id_session;
  mListTryLogic.Add(pID);

  CallBackModule(nsListModules::MMOEngineMaster, &TModuleServerLogicMaster_Dev::TryLoginMMOEngine);
}
//---------------------------------------------------------------------------------------------
void TModuleServerLogicMaster_Dev::TryLoginMMOEngine()
{
  bool resAccept = true;

  unsigned int** ppFirst = mListTryLogic.GetFirst();
  while(ppFirst)
  {
    unsigned int ID = *(*ppFirst);

    mCounterClient ++;
    char result[100];
    sprintf(result,"hello, Client %u",mCounterClient);
    mComp.pMMOEngineMaster->Get()->SetResultLogin(resAccept, ID, mCounterClient,
      (void*)&result[0], strlen(result));

    mListKeyAllClient.push_back(mCounterClient);

    // следующий ID
    mListTryLogic.Remove(ppFirst);
    ppFirst = mListTryLogic.GetFirst();
  }
}
//---------------------------------------------------------------------------------------------
void TModuleServerLogicMaster_Dev::ConnectUp(nsMMOEngine::TEventConnectUp* pBE)
{
  CallBackModule(nsListModules::AloneGUI, &TModuleServerLogicMaster_Dev::ConnectUpQt);
}
//---------------------------------------------------------------------------------------------
void TModuleServerLogicMaster_Dev::DisconnectUp(nsMMOEngine::TEventDisconnectUp* pBE)
{
  CallBackModule(nsListModules::AloneGUI, &TModuleServerLogicMaster_Dev::DisconnectUpQt);
}
//---------------------------------------------------------------------------------------------
void TModuleServerLogicMaster_Dev::ConnectUpQt()
{
  if(mMasterForm)
    mMasterForm->SetConnect(true);
}
//---------------------------------------------------------------------------------------------
void TModuleServerLogicMaster_Dev::DisconnectUpQt()
{
  if(mMasterForm)
    mMasterForm->SetConnect(false);
}
//---------------------------------------------------------------------------------------------
void TModuleServerLogicMaster_Dev::AddSlaveQt()
{
  TMasterForm::TDesc** ppFirst = mListID_SessionAdd.GetFirst();
  while(ppFirst)
  {
    TMasterForm::TDesc* pDesc = *ppFirst;

    if(mMasterForm)
      mMasterForm->Add(*pDesc);
    // следующий ID
    mListID_SessionAdd.Remove(ppFirst);
    ppFirst = mListID_SessionAdd.GetFirst();
  }
}
//---------------------------------------------------------------------------------------------
void TModuleServerLogicMaster_Dev::DeleteSlaveQt()
{
  TMasterForm::TDesc** ppFirst = mListID_SessionDelete.GetFirst();
  while(ppFirst)
  {
    TMasterForm::TDesc* pDesc = *ppFirst;
    if(mMasterForm)
      mMasterForm->Delete(pDesc->id_session);
    // следующий ID
    mListID_SessionDelete.Remove(ppFirst);
    ppFirst = mListID_SessionDelete.GetFirst();
  }
}
//---------------------------------------------------------------------------------------------
void TModuleServerLogicMaster_Dev::CreateGroup()
{
  unsigned int id_group;
  bool res = mComp.pMMOEngineMaster->Get()->TryCreateGroup(mListKeyAllClient, id_group);
  BL_ASSERT(res);
}
//---------------------------------------------------------------------------------------------
