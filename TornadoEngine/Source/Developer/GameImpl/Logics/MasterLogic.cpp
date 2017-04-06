/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include <boost/asio/ip/impl/address_v4.ipp>

#include "MasterLogic.h"
#include "ListModules.h"
#include "GlobalParam.h"
#include "ResolverSelf_IP_v4.h"
#include "Logger.h"
#include "ModuleMMOEngineMaster.h"

TMasterLogic::TMasterLogic()
{
  SetCycleTime(100);

  //mMasterForm = NULL;
  // значения по-умолчанию для параметров командной строки
  std::string sLocalHost;
  TResolverSelf_IP_v4 resolver;
  resolver.Get(sLocalHost, 0);

  TInputCmdDevTool::TInput input;
  input.ip_dst   = boost::asio::ip::address_v4::from_string(sLocalHost).to_ulong();
  input.port_self = MASTER_PORT;
  input.port_dst  = SUPER_SERVER_PORT;

  mInputCmd.SetDefParam(input);
}
//------------------------------------------------------------------------------
bool TMasterLogic::WorkServer()
{
  return true;
}
//------------------------------------------------------------------------------
void TMasterLogic::EndWork()
{

}
//------------------------------------------------------------------------------
void TMasterLogic::Input(int id, void* p, int size)
{
  switch(id)
  {
    //case nsListModules::AloneGUI:
      //break;
    case nsListModules::MMOEngineMaster:
      HandleFromMMOEngine((nsMMOEngine::TBaseEvent*)p);
      break;
    case nsListModules::DataBase:
      break;
    case nsListModules::Timer:
      break;
    default:BL_FIX_BUG();
  }
}
//------------------------------------------------------------------------------
void TMasterLogic::InitForms()
{
  //mMasterForm = new TMasterForm;
  //mMasterForm->show();
}
//------------------------------------------------------------------------------
void TMasterLogic::StartEvent()
{
  //CallBackModule(nsListModules::AloneGUI, &TMasterLogic::InitForms);
  ConnectToSuperServer();
}
//----------------------------------------------------------
void TMasterLogic::StopEvent()
{

}
//----------------------------------------------------------
void TMasterLogic::ConnectToSuperServer()
{
  TInputCmdDevTool::TInput input;
  mInputCmd.Get(input);

  nsMMOEngine::TDescOpen descOpen;
  descOpen.port = input.port_self;
  bool resOpen = mComp.pMMOEngineMaster->Get()->Open(&descOpen);
  mComp.pMMOEngineMaster->Get()->ConnectUp(input.ip_dst, input.port_dst, "1", 1, "1", 1);
}
//----------------------------------------------------------
void TMasterLogic::HandleFromMMOEngine(nsMMOEngine::TBaseEvent* pBE)
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
    case nsMMOEngine::eTryLogin:
      sEvent = "TryLogin";
      TryLogin((nsMMOEngine::TEventTryLogin*)pBE);
      break;
    case nsMMOEngine::eDestroyGroup:
      sEvent = "DestroyGroup";
      break;
    default:BL_FIX_BUG();
  }
  GetLogger("Inner")->WriteF_time("MMOEngine: %s.\n",sEvent.data());
}
//---------------------------------------------------------------------------------------------
void TMasterLogic::InitLog()
{
  GetLogger()->Register("Inner");// для логирования внутренних событий
  GetLogger()->Init("Master");
}
//---------------------------------------------------------------------------------------------
void TMasterLogic::ConnectDown(nsMMOEngine::TEventConnectDown* pEvent)
{
  //TSessionOperation* pSO = new TSessionOperation;
  //pSO->desc.id_session = pEvent->id_session;
  //pSO->typeEvent = eAdd;
  //mListSlaveSessionOperation.Add(pSO);

  //CallBackModule(nsListModules::AloneGUI, &TMasterLogic::OperationSessionQt);
}
//---------------------------------------------------------------------------------------------
void TMasterLogic::DisconnectDown(nsMMOEngine::TEventDisconnectDown* pEvent)
{
  //TSessionOperation* pSO = new TSessionOperation;
  //pSO->desc.id_session = pEvent->id_session;
  //pSO->typeEvent = eDelete;
  //mListSlaveSessionOperation.Add(pSO);

  //CallBackModule(nsListModules::AloneGUI, &TMasterLogic::OperationSessionQt);
}
//---------------------------------------------------------------------------------------------
void TMasterLogic::TryLogin(nsMMOEngine::TEventTryLogin* pEvent)
{
  unsigned int* pID = new unsigned int(pEvent->id_session);
  TryLoginMMOEngine(pID);
}
//---------------------------------------------------------------------------------------------
void TMasterLogic::TryLoginMMOEngine(unsigned int* pID)
{
  bool resAccept = true;

  mCounterClient++;
  char result[100];
  sprintf(result,"hello, Client %u",mCounterClient);
  mComp.pMMOEngineMaster->Get()->SetResultLogin(resAccept, *pID, mCounterClient,
    (void*)&result[0], strlen(result));

  mListKeyAllClient.push_back(mCounterClient);
}
//---------------------------------------------------------------------------------------------
void TMasterLogic::ConnectUp(nsMMOEngine::TEventConnectUp* pBE)
{
  //CallBackModule(nsListModules::AloneGUI, &TMasterLogic::ConnectUpQt);
}
//---------------------------------------------------------------------------------------------
void TMasterLogic::DisconnectUp(nsMMOEngine::TEventDisconnectUp* pBE)
{
  //CallBackModule(nsListModules::AloneGUI, &TMasterLogic::DisconnectUpQt);
}
//---------------------------------------------------------------------------------------------
void TMasterLogic::ConnectUpQt()
{
  //if(mMasterForm)
  //  mMasterForm->SetConnect(true);
}
//---------------------------------------------------------------------------------------------
void TMasterLogic::DisconnectUpQt()
{
  //if(mMasterForm)
  //  mMasterForm->SetConnect(false);
}
//---------------------------------------------------------------------------------------------
void TMasterLogic::CreateGroup()
{
  unsigned int id_group;
  bool res = mComp.pMMOEngineMaster->Get()->TryCreateGroup(mListKeyAllClient, id_group);
  BL_ASSERT(res);
}
//---------------------------------------------------------------------------------------------
void TMasterLogic::OperationSessionQt()
{
  TSessionOperation** ppOperation = mListSlaveSessionOperation.GetFirst();
  while(ppOperation)
  {
    TSessionOperation* pOperation = *ppOperation;
    //switch(pOperation->typeEvent)
    //{
    //case eAdd:
    //  if(mMasterForm)
    //    mMasterForm->Add(pOperation->desc);
    //  break;
    //case eDelete:
    //  if(mMasterForm)
    //    mMasterForm->Delete(pOperation->desc.id_session);
    //  break;
    //}
    // следующий ID
    mListSlaveSessionOperation.RemoveFirst();
    ppOperation = mListSlaveSessionOperation.GetFirst();
  }
}
//---------------------------------------------------------------------------------------------
