/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ModuleServerLogicSuperServer_Dev.h"
#include "ListModules.h"
#include "GlobalParam.h"
#include "NetSystem.h"
#include "Logger.h"

#include "ModuleMMOEngineSuperServer.h"
#include "Events.h"


TModuleServerLogicSuperServer_Dev::TModuleServerLogicSuperServer_Dev()
{
  SetCycleTime(100);//###

  mSuperServerForm = NULL;
  // значения по-умолчанию для параметров командной строки
  TInputCmdDevTool::TInput input;
  input.port_self = SUPER_SERVER_PORT;

  mInputCmd.SetDefParam(input);
}
//------------------------------------------------------------------------------
bool TModuleServerLogicSuperServer_Dev::WorkServer()
{
  return true;
}
//------------------------------------------------------------------------------
void TModuleServerLogicSuperServer_Dev::EndWork()
{

}
//------------------------------------------------------------------------------
void TModuleServerLogicSuperServer_Dev::Input(int id, void* p, int size)
{
  switch(id)
  {
    case nsListModules::AloneGUI:
      break;
    case nsListModules::MMOEngineSuperServer:
      HandleFromMMOEngine((nsMMOEngine::TBaseEvent*)p);
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
void TModuleServerLogicSuperServer_Dev::InitForms()
{
  mSuperServerForm = new TSuperServerForm;
  mSuperServerForm->show();
}
//------------------------------------------------------------------------------
void TModuleServerLogicSuperServer_Dev::StartEvent()
{
  CallBackModule(nsListModules::AloneGUI, &TModuleServerLogicSuperServer_Dev::InitForms);
  CallBackModule(nsListModules::MMOEngineSuperServer, &TModuleServerLogicSuperServer_Dev::OpenPort);
}
//----------------------------------------------------------
void TModuleServerLogicSuperServer_Dev::StopEvent()
{

}
//----------------------------------------------------------
void TModuleServerLogicSuperServer_Dev::OpenPort()
{
  TInputCmdDevTool::TInput input;
  mInputCmd.Get(input);

  nsMMOEngine::TDescOpen descOpen;
  descOpen.port = input.port_self;
  bool resOpen = mComp.pMMOEngineSuperServer->Get()->Open(&descOpen);
}
//----------------------------------------------------------
void TModuleServerLogicSuperServer_Dev::HandleFromMMOEngine(nsMMOEngine::TBaseEvent* pBE)
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
      break;
    case nsMMOEngine::eDisconnectUp:
      sEvent = "DisconnectUp";
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
      {
        // ###
        //unsigned int id_session = ((TEventRecvFromDown*)pBE)->id_session;
        //char s = 's';
        //TBreakPacket bp;
        //bp.PushBack(&s, sizeof(s));
        //mComponent.mNet.SuperServer->SendDown(id_session,bp);
      }
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
void TModuleServerLogicSuperServer_Dev::InitLog()
{
  GetLogger()->Register("Inner");// для логирования внутренних событий
  GetLogger()->Init("SuperServer");
}
//---------------------------------------------------------------------------------------------
void TModuleServerLogicSuperServer_Dev::ConnectDown(nsMMOEngine::TEventConnectDown* pEvent)
{
  unsigned int* pID = new unsigned int;
  *pID = pEvent->id_session;
  mListSessionAdd.Add(pID);

  CallBackModule(nsListModules::MMOEngineSuperServer, &TModuleServerLogicSuperServer_Dev::ConnectDownMMOEngine);
}
//---------------------------------------------------------------------------------------------
void TModuleServerLogicSuperServer_Dev::ConnectDownMMOEngine()
{
  unsigned int** ppFirst = mListSessionAdd.GetFirst();
  while(ppFirst)
  {
    unsigned int* pID_session = *ppFirst;

    TSuperServerForm::TDesc* pDesc = new TSuperServerForm::TDesc;
    pDesc->id_session = *pID_session;
    bool resInfoSession = mComp.pMMOEngineSuperServer->Get()->GetInfoSession(pDesc->id_session, pDesc->ip_port);
    BL_ASSERT(resInfoSession);
    mListID_SessionAdd.Add(pDesc);
    // следующий ID
    mListSessionAdd.Remove(ppFirst);
    ppFirst = mListSessionAdd.GetFirst();
  }

  CallBackModule(nsListModules::AloneGUI, &TModuleServerLogicSuperServer_Dev::AddMasterQt);
}
//---------------------------------------------------------------------------------------------
void TModuleServerLogicSuperServer_Dev::DisconnectDown(nsMMOEngine::TEventDisconnectDown* pEvent)
{
  TSuperServerForm::TDesc* pDesc = new TSuperServerForm::TDesc;
  pDesc->id_session = pEvent->id_session;
  mListID_SessionDelete.Add(pDesc);

  CallBackModule(nsListModules::AloneGUI, &TModuleServerLogicSuperServer_Dev::DeleteMasterQt);
}
//---------------------------------------------------------------------------------------------
void TModuleServerLogicSuperServer_Dev::AddMasterQt()
{
  TSuperServerForm::TDesc** ppFirst = mListID_SessionAdd.GetFirst();
  while(ppFirst)
  {
    TSuperServerForm::TDesc* pDesc = *ppFirst;

    if(mSuperServerForm)
      mSuperServerForm->Add(*pDesc);
    // следующий ID
    mListID_SessionAdd.Remove(ppFirst);
    ppFirst = mListID_SessionAdd.GetFirst();
  }
}
//---------------------------------------------------------------------------------------------
void TModuleServerLogicSuperServer_Dev::DeleteMasterQt()
{
  TSuperServerForm::TDesc** ppFirst = mListID_SessionDelete.GetFirst();
  while(ppFirst)
  {
    TSuperServerForm::TDesc* pDesc = *ppFirst;

    if(mSuperServerForm)
      mSuperServerForm->Delete(pDesc->id_session);
    // следующий ID
    mListID_SessionDelete.Remove(ppFirst);
    ppFirst = mListID_SessionDelete.GetFirst();
  }
}
//---------------------------------------------------------------------------------------------
