/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include <boost/asio/ip/impl/address_v4.ipp>

#include "SlaveLogic.h"
#include "ListModules.h"
#include "GlobalParam.h"
#include "ResolverSelf_IP_v4.h"
#include "Logger.h"

#include "ModuleMMOEngineSlave.h"
#include "Events.h"

TSlaveLogic::TSlaveLogic()
{
  SetCycleTime(eCycleTime);

  mSlaveForm = NULL;

  // значения по-умолчанию для параметров командной строки
  std::string sLocalHost;
  TResolverSelf_IP_v4 resolver;
  resolver.Get(sLocalHost, 0);

  TInputCmdDevTool::TInput input;
  input.ip_dst   = boost::asio::ip::address_v4::from_string(sLocalHost).to_ulong();
  input.port_self = SLAVE_PORT;
  input.port_dst  = MASTER_PORT;

  mInputCmd.SetDefParam(input);
}
//------------------------------------------------------------------------------
bool TSlaveLogic::WorkServer()
{
  return true;
}
//------------------------------------------------------------------------------
void TSlaveLogic::EndWork()
{

}
//------------------------------------------------------------------------------
void TSlaveLogic::Input(int id, void* p, int size)
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
      break;
    default:BL_FIX_BUG();
  }
}
//------------------------------------------------------------------------------
void TSlaveLogic::InitForms()
{
  mSlaveForm = new TSlaveForm;
  mSlaveForm->show();
}
//------------------------------------------------------------------------------
void TSlaveLogic::StartEvent()
{
  CallBackModule(nsListModules::AloneGUI, &TSlaveLogic::InitForms);
  CallBackModule(nsListModules::MMOEngineSlave, &TSlaveLogic::ConnectToMaster);
  CallBackModule(nsListModules::MMOEngineSlave, &TSlaveLogic::InitMMOSlave);
}
//----------------------------------------------------------
void TSlaveLogic::StopEvent()
{

}
//----------------------------------------------------------
void TSlaveLogic::ConnectToMaster()
{
  TInputCmdDevTool::TInput input;
  mInputCmd.Get(input);

  nsMMOEngine::TDescOpen descOpen;
  descOpen.port = input.port_self;
  bool resOpen = mComp.pMMOEngineSlave->Get()->Open(&descOpen);
  mComp.pMMOEngineSlave->Get()->ConnectUp(input.ip_dst, input.port_dst, "1", 1, "1", 1);
}
//----------------------------------------------------------
void TSlaveLogic::HandleFromMMOEngine(nsMMOEngine::TBaseEvent* pBE)
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
    default:BL_FIX_BUG();
  }
  GetLogger("Inner")->WriteF_time("MMOEngine: %s.\n",sEvent.data());
}
//---------------------------------------------------------------------------------------------
void TSlaveLogic::InitLog()
{
  GetLogger()->Register("Inner");// для логирования внутренних событий
  GetLogger()->Init("Slave");
}
//---------------------------------------------------------------------------------------------
void TSlaveLogic::ConnectUp(nsMMOEngine::TEventConnectUp* pBE)
{
  CallBackModule(nsListModules::AloneGUI, &TSlaveLogic::ConnectUpQt);
}
//---------------------------------------------------------------------------------------------
void TSlaveLogic::DisconnectUp(nsMMOEngine::TEventDisconnectUp* pBE)
{
  CallBackModule(nsListModules::AloneGUI, &TSlaveLogic::DisconnectUpQt);
}
//---------------------------------------------------------------------------------------------
void TSlaveLogic::ConnectUpQt()
{
  if(mSlaveForm)
    mSlaveForm->SetConnect(true);
}
//---------------------------------------------------------------------------------------------
void TSlaveLogic::DisconnectUpQt()
{
  if(mSlaveForm)
    mSlaveForm->SetConnect(false);
}
//---------------------------------------------------------------------------------------------
void TSlaveLogic::ConnectDown(nsMMOEngine::TEventConnectDown* pEvent)
{
  unsigned int* pID = new unsigned int;
  *pID = pEvent->id_session;
  mListSessionAdd.Add(pID);

  CallBackModule(nsListModules::MMOEngineSlave, &TSlaveLogic::ConnectDownMMOEngine);
}
//---------------------------------------------------------------------------------------------
void TSlaveLogic::ConnectDownMMOEngine()
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
    mListSessionAdd.RemoveFirst();
    ppFirst = mListSessionAdd.GetFirst();
  }

  CallBackModule(nsListModules::AloneGUI, &TSlaveLogic::AddClientQt);
}
//---------------------------------------------------------------------------------------------
void TSlaveLogic::DisconnectDown(nsMMOEngine::TEventDisconnectDown* pEvent)
{
  TSlaveForm::TDesc* pDesc = new TSlaveForm::TDesc;
  pDesc->id_session = pEvent->id_session;
  mListID_SessionDelete.Add(pDesc);

  CallBackModule(nsListModules::AloneGUI, &TSlaveLogic::DeleteClientQt);
}
//---------------------------------------------------------------------------------------------
void TSlaveLogic::AddClientQt()
{
  TSlaveForm::TDesc** ppFirst = mListID_SessionAdd.GetFirst();
  while(ppFirst)
  {
    TSlaveForm::TDesc* pDesc = *ppFirst;
    if(mSlaveForm)
      mSlaveForm->Add(*pDesc);
    // следующий ID
    mListID_SessionAdd.RemoveFirst();
    ppFirst = mListID_SessionAdd.GetFirst();
  }
}
//---------------------------------------------------------------------------------------------
void TSlaveLogic::DeleteClientQt()
{
  TSlaveForm::TDesc** ppFirst = mListID_SessionDelete.GetFirst();
  while(ppFirst)
  {
    TSlaveForm::TDesc* pDesc = *ppFirst;

    if(mSlaveForm)
      mSlaveForm->Delete(pDesc->id_session);
    // следующий ID
    mListID_SessionDelete.RemoveFirst();
    ppFirst = mListID_SessionDelete.GetFirst();
  }
}
//---------------------------------------------------------------------------------------------
void TSlaveLogic::SaveContextClient(nsMMOEngine::TEventSaveContext* pEvent)
{
  unsigned int* pID = new unsigned int(pEvent->id_session);
  mListSessionSave.Add(pID);
  CallBackModule(nsListModules::MMOEngineSlave, &TSlaveLogic::SaveContextClientMMOEngine);
}
//---------------------------------------------------------------------------------------------
void TSlaveLogic::SaveContextClientMMOEngine()
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

    mListSessionSave.RemoveFirst();
    ppFirst = mListSessionSave.GetFirst();
  }
  CallBackModule(nsListModules::AloneGUI, &TSlaveLogic::DeleteClientQt);
}
//---------------------------------------------------------------------------------------------
void TSlaveLogic::RestoreContextClient(nsMMOEngine::TEventRestoreContext* pEvent)
{
  unsigned int* pID = new unsigned int;
  *pID = pEvent->id_session;
  mListSessionAdd.Add(pID);

  CallBackModule(nsListModules::MMOEngineSlave, &TSlaveLogic::ConnectDownMMOEngine);
}
//---------------------------------------------------------------------------------------------
void TSlaveLogic::InitMMOSlave()
{
  mComp.pMMOEngineSlave->GetCBBeginWork()->Register( &TSlaveLogic::BeginWorkMMOSlave, this );
}
//---------------------------------------------------------------------------------------------
void TSlaveLogic::BeginWorkMMOSlave()
{
  mComp.pMMOEngineSlave->Get()->SetLoad( GetLastLoad() );
}
//---------------------------------------------------------------------------------------------
