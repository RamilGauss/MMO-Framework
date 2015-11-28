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
#include "NetSystem.h"
#include "Logger.h"
#include "ModuleMMOEngineMaster.h"

TMasterLogic::TMasterLogic()
{
  SetCycleTime(100);

  mMasterForm = NULL;
  // значения по-умолчанию для параметров командной строки
  TInputCmdDevTool::TInput input;
  input.ip_dst   = boost::asio::ip::address_v4::from_string(ns_getSelfIP(0)).to_ulong();
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
    case nsListModules::AloneGUI:
      break;
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
  mMasterForm = new TMasterForm;
  mMasterForm->show();
}
//------------------------------------------------------------------------------
void TMasterLogic::StartEvent()
{
  CallBackModule(nsListModules::AloneGUI, &TMasterLogic::InitForms);
  CallBackModule(nsListModules::MMOEngineMaster, &TMasterLogic::ConnectToSuperServer);
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
  unsigned int* pID = new unsigned int;
  *pID = pEvent->id_session;
  mListSessionAdd.Add(pID);

  CallBackModule(nsListModules::MMOEngineMaster, &TMasterLogic::ConnectDownMMOEngine);
}
//---------------------------------------------------------------------------------------------
void TMasterLogic::ConnectDownMMOEngine()
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
  
  CallBackModule(nsListModules::AloneGUI, &TMasterLogic::AddSlaveQt);
}
//---------------------------------------------------------------------------------------------
void TMasterLogic::DisconnectDown(nsMMOEngine::TEventDisconnectDown* pEvent)
{
  TMasterForm::TDesc* pDesc = new TMasterForm::TDesc;
  pDesc->id_session = pEvent->id_session;
  mListID_SessionDelete.Add(pDesc);

  CallBackModule(nsListModules::AloneGUI, &TMasterLogic::DeleteSlaveQt);
}
//---------------------------------------------------------------------------------------------
void TMasterLogic::TryLogin(nsMMOEngine::TEventTryLogin* pEvent)
{
  unsigned int* pID = new unsigned int;
  *pID = pEvent->id_session;
  mListTryLogic.Add(pID);

  CallBackModule(nsListModules::MMOEngineMaster, &TMasterLogic::TryLoginMMOEngine);
}
//---------------------------------------------------------------------------------------------
void TMasterLogic::TryLoginMMOEngine()
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
void TMasterLogic::ConnectUp(nsMMOEngine::TEventConnectUp* pBE)
{
  CallBackModule(nsListModules::AloneGUI, &TMasterLogic::ConnectUpQt);
}
//---------------------------------------------------------------------------------------------
void TMasterLogic::DisconnectUp(nsMMOEngine::TEventDisconnectUp* pBE)
{
  CallBackModule(nsListModules::AloneGUI, &TMasterLogic::DisconnectUpQt);
}
//---------------------------------------------------------------------------------------------
void TMasterLogic::ConnectUpQt()
{
  if(mMasterForm)
    mMasterForm->SetConnect(true);
}
//---------------------------------------------------------------------------------------------
void TMasterLogic::DisconnectUpQt()
{
  if(mMasterForm)
    mMasterForm->SetConnect(false);
}
//---------------------------------------------------------------------------------------------
void TMasterLogic::AddSlaveQt()
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
void TMasterLogic::DeleteSlaveQt()
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
void TMasterLogic::CreateGroup()
{
  unsigned int id_group;
  bool res = mComp.pMMOEngineMaster->Get()->TryCreateGroup(mListKeyAllClient, id_group);
  BL_ASSERT(res);
}
//---------------------------------------------------------------------------------------------
