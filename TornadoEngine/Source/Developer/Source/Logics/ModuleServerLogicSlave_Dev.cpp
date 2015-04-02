/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include <boost/asio/ip/impl/address_v4.ipp>

#include "ModuleServerLogicSlave_Dev.h"
#include "ListModules.h"
#include "GlobalParam.h"
#include "NetSystem.h"
#include "Logger.h"

#include "ModuleMMOEngineSlave.h"
#include "Events.h"

TModuleServerLogicSlave_Dev::TModuleServerLogicSlave_Dev()
{
  SetCycleTime(eCycleTime);

  mSlaveForm = NULL;

  // значения по-умолчанию для параметров командной строки
  TInputCmdDevTool::TInput input;
  input.ip_dst   = boost::asio::ip::address_v4::from_string(ns_getSelfIP(0)).to_ulong();
  input.port_self = SLAVE_PORT;
  input.port_dst  = MASTER_PORT;

  mInputCmd.SetDefParam(input);
}
//------------------------------------------------------------------------------
bool TModuleServerLogicSlave_Dev::WorkServer()
{
  return true;
}
//------------------------------------------------------------------------------
void TModuleServerLogicSlave_Dev::EndWork()
{

}
//------------------------------------------------------------------------------
void TModuleServerLogicSlave_Dev::Input(int id, void* p, int size)
{
  switch(id)
  {
    case nsListModules::AloneGUI:
      break;
    case nsListModules::MMOEngineSlave:
      HandleFromMMOEngine((nsMMOEngine::TBaseEvent*)p);
      break;
    case nsListModules::PhysicEngine:
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
void TModuleServerLogicSlave_Dev::InitForms()
{
  mSlaveForm = new TSlaveForm;
  mSlaveForm->show();
}
//------------------------------------------------------------------------------
void TModuleServerLogicSlave_Dev::StartEvent()
{
  CallBackModule(nsListModules::AloneGUI, &TModuleServerLogicSlave_Dev::InitForms);
  CallBackModule(nsListModules::MMOEngineSlave, &TModuleServerLogicSlave_Dev::ConnectToMaster);
}
//----------------------------------------------------------
void TModuleServerLogicSlave_Dev::StopEvent()
{

}
//----------------------------------------------------------
void TModuleServerLogicSlave_Dev::ConnectToMaster()
{
  TInputCmdDevTool::TInput input;
  mInputCmd.Get(input);

  nsMMOEngine::TDescOpen descOpen;
  descOpen.port = input.port_self;
  bool resOpen = mComp.pMMOEngineSlave->Get()->Open(&descOpen);
  mComp.pMMOEngineSlave->Get()->ConnectUp(input.ip_dst, input.port_dst, "1", 1, "1", 1);
}
//----------------------------------------------------------
void TModuleServerLogicSlave_Dev::HandleFromMMOEngine(nsMMOEngine::TBaseEvent* pBE)
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
      // типа Сохранить данные нашего Клиента и отдать другому Slave
      SaveContextClient((nsMMOEngine::TEventSaveContext*)pBE);
      break;
    case nsMMOEngine::eRestoreContext:
      sEvent = "RestoreContext";
      RestoreContextClient((nsMMOEngine::TEventRestoreContext*)pBE);
      break;
    case nsMMOEngine::eTryLogin:
      sEvent = "TryLogin";
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
void TModuleServerLogicSlave_Dev::InitLog()
{
  GetLogger()->Register("Inner");// для логирования внутренних событий
  GetLogger()->Init("Slave");
}
//---------------------------------------------------------------------------------------------
void TModuleServerLogicSlave_Dev::ConnectUp(nsMMOEngine::TEventConnectUp* pBE)
{
  CallBackModule(nsListModules::AloneGUI, &TModuleServerLogicSlave_Dev::ConnectUpQt);
}
//---------------------------------------------------------------------------------------------
void TModuleServerLogicSlave_Dev::DisconnectUp(nsMMOEngine::TEventDisconnectUp* pBE)
{
  CallBackModule(nsListModules::AloneGUI, &TModuleServerLogicSlave_Dev::DisconnectUpQt);
}
//---------------------------------------------------------------------------------------------
void TModuleServerLogicSlave_Dev::ConnectUpQt()
{
  if(mSlaveForm)
    mSlaveForm->SetConnect(true);
}
//---------------------------------------------------------------------------------------------
void TModuleServerLogicSlave_Dev::DisconnectUpQt()
{
  if(mSlaveForm)
    mSlaveForm->SetConnect(false);
}
//---------------------------------------------------------------------------------------------
void TModuleServerLogicSlave_Dev::ConnectDown(nsMMOEngine::TEventConnectDown* pEvent)
{
  unsigned int* pID = new unsigned int;
  *pID = pEvent->id_session;
  mListSessionAdd.Add(pID);

  CallBackModule(nsListModules::MMOEngineSlave, &TModuleServerLogicSlave_Dev::ConnectDownMMOEngine);
}
//---------------------------------------------------------------------------------------------
void TModuleServerLogicSlave_Dev::ConnectDownMMOEngine()
{
  unsigned int** ppFirst = mListSessionAdd.GetFirst();
  while(ppFirst)
  {
    unsigned int* pID_session = *ppFirst;

    TSlaveForm::TDesc* pDesc = new TSlaveForm::TDesc;
    pDesc->id_session = *pID_session;
    bool resInfoSession = mComp.pMMOEngineSlave->Get()->GetInfoSession(pDesc->id_session, pDesc->ip_port);
    BL_ASSERT(resInfoSession);
    mListID_SessionAdd.Add(pDesc);
    // следующий ID
    mListSessionAdd.Remove(ppFirst);
    ppFirst = mListSessionAdd.GetFirst();
  }

  CallBackModule(nsListModules::AloneGUI, &TModuleServerLogicSlave_Dev::AddClientQt);
}
//---------------------------------------------------------------------------------------------
void TModuleServerLogicSlave_Dev::DisconnectDown(nsMMOEngine::TEventDisconnectDown* pEvent)
{
  TSlaveForm::TDesc* pDesc = new TSlaveForm::TDesc;
  pDesc->id_session = pEvent->id_session;
  mListID_SessionDelete.Add(pDesc);

  CallBackModule(nsListModules::AloneGUI, &TModuleServerLogicSlave_Dev::DeleteClientQt);
}
//---------------------------------------------------------------------------------------------
void TModuleServerLogicSlave_Dev::AddClientQt()
{
  TSlaveForm::TDesc** ppFirst = mListID_SessionAdd.GetFirst();
  while(ppFirst)
  {
    TSlaveForm::TDesc* pDesc = *ppFirst;
    if(mSlaveForm)
      mSlaveForm->Add(*pDesc);
    // следующий ID
    mListID_SessionAdd.Remove(ppFirst);
    ppFirst = mListID_SessionAdd.GetFirst();
  }
}
//---------------------------------------------------------------------------------------------
void TModuleServerLogicSlave_Dev::DeleteClientQt()
{
  TSlaveForm::TDesc** ppFirst = mListID_SessionDelete.GetFirst();
  while(ppFirst)
  {
    TSlaveForm::TDesc* pDesc = *ppFirst;

    if(mSlaveForm)
      mSlaveForm->Delete(pDesc->id_session);
    // следующий ID
    mListID_SessionDelete.Remove(ppFirst);
    ppFirst = mListID_SessionDelete.GetFirst();
  }
}
//---------------------------------------------------------------------------------------------
void TModuleServerLogicSlave_Dev::SaveContextClient(nsMMOEngine::TEventSaveContext* pEvent)
{
  unsigned int* pID = new unsigned int(pEvent->id_session);
  mListSessionSave.Add(pID);
  CallBackModule(nsListModules::MMOEngineSlave, &TModuleServerLogicSlave_Dev::SaveContextClientMMOEngine);
}
//---------------------------------------------------------------------------------------------
void TModuleServerLogicSlave_Dev::SaveContextClientMMOEngine()
{
  unsigned int** ppFirst = mListSessionSave.GetFirst();
  while(ppFirst)
  {
    unsigned int ID = *(*ppFirst);

    mComp.pMMOEngineSlave->Get()->SaveContext(ID, NULL, 0);    // следующий ID
    // удалить из списка этого Клиента
    TSlaveForm::TDesc* pDesc = new TSlaveForm::TDesc;
    pDesc->id_session = ID;
    mListID_SessionDelete.Add(pDesc);

    mListSessionSave.Remove(ppFirst);
    ppFirst = mListSessionSave.GetFirst();
  }
  CallBackModule(nsListModules::AloneGUI, &TModuleServerLogicSlave_Dev::DeleteClientQt);
}
//---------------------------------------------------------------------------------------------
void TModuleServerLogicSlave_Dev::RestoreContextClient(nsMMOEngine::TEventRestoreContext* pEvent)
{
  unsigned int* pID = new unsigned int;
  *pID = pEvent->id_session;
  mListSessionAdd.Add(pID);

  CallBackModule(nsListModules::MMOEngineSlave, &TModuleServerLogicSlave_Dev::ConnectDownMMOEngine);
}
//---------------------------------------------------------------------------------------------