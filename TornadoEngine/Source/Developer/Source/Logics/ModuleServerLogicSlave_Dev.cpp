/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include <boost/asio/ip/impl/address_v4.ipp>

#include "ModuleServerLogicSlave_Dev.h"
#include "ListModules.h"
#include "SlaveForm.h"
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
  input.ip_src   = boost::asio::ip::address_v4::from_string(ns_getSelfIP(0)).to_ulong();
  input.port_self = SLAVE_PORT;
  input.port_src  = MASTER_PORT;

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
  mComp.pMMOEngineSlave->Get()->ConnectUp(input.ip_src, input.port_src, "1", 1, "1", 1);
}
//----------------------------------------------------------
void TModuleServerLogicSlave_Dev::HandleFromMMOEngine(nsMMOEngine::TBaseEvent* pBE)
{
  std::string sEvent;  
  switch(pBE->mType)
  {
    case nsMMOEngine::eConnectDown:
      sEvent = "ConnectDown";
      //ConnectDown((nsMMOEngine::TEventConnectDown*)pBE);
      break;
    case nsMMOEngine::eDisconnectDown:
      sEvent = "DisconnectDown";
      //DisconnectDown((nsMMOEngine::TEventDisconnectDown*)pBE);
      break;
    case nsMMOEngine::eConnectUp:
      sEvent = "ConnectUp";
      //ConnectUp((nsMMOEngine::TEventConnectUp*)pBE);
      break;
    case nsMMOEngine::eDisconnectUp:
      sEvent = "DisconnectUp";
      //DisconnectUp((nsMMOEngine::TEventDisconnectUp*)pBE);
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
      //SaveContextClient((nsMMOEngine::TEventSaveContext*)pBE);
      break;
    case nsMMOEngine::eRestoreContext:
      sEvent = "RestoreContext";
      //RestoreContextClient((nsMMOEngine::TEventRestoreContext*)pBE);
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