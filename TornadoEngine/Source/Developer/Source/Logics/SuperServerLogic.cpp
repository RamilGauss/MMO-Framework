/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "SuperServerLogic.h"
#include "ListModules.h"
#include "GlobalParam.h"
#include "NetSystem.h"
#include "Logger.h"

#include "ModuleMMOEngineSuperServer.h"
#include "Events.h"


TSuperServerLogic::TSuperServerLogic()
{
  SetCycleTime(100);//###

  mSuperServerForm = NULL;
  // значения по-умолчанию для параметров командной строки
  TInputCmdDevTool::TInput input;
  input.port_self = SUPER_SERVER_PORT;

  mInputCmd.SetDefParam(input);
}
//------------------------------------------------------------------------------
bool TSuperServerLogic::WorkServer()
{
  return true;
}
//------------------------------------------------------------------------------
void TSuperServerLogic::EndWork()
{

}
//------------------------------------------------------------------------------
void TSuperServerLogic::Input(int id, void* p, int size)
{
  switch(id)
  {
    case nsListModules::AloneGUI:
      break;
    case nsListModules::MMOEngineSuperServer:
      HandleFromMMOEngine((nsMMOEngine::TBaseEvent*)p);
      break;
    case nsListModules::Timer:
      break;
    default:BL_FIX_BUG();
  }
}
//------------------------------------------------------------------------------
void TSuperServerLogic::InitForms()
{
  mSuperServerForm = new TSuperServerForm;
  mSuperServerForm->show();
}
//------------------------------------------------------------------------------
void TSuperServerLogic::StartEvent()
{
  CallBackModule(nsListModules::AloneGUI, &TSuperServerLogic::InitForms);
  CallBackModule(nsListModules::MMOEngineSuperServer, &TSuperServerLogic::OpenPort);
}
//----------------------------------------------------------
void TSuperServerLogic::StopEvent()
{

}
//----------------------------------------------------------
void TSuperServerLogic::OpenPort()
{
  TInputCmdDevTool::TInput input;
  mInputCmd.Get(input);

  nsMMOEngine::TDescOpen descOpen;
  descOpen.port = input.port_self;
  bool resOpen = mComp.pMMOEngineSuperServer->Get()->Open(&descOpen);
}
//----------------------------------------------------------
void TSuperServerLogic::HandleFromMMOEngine(nsMMOEngine::TBaseEvent* pBE)
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
    default:BL_FIX_BUG();
  }
  GetLogger("Inner")->WriteF_time("MMOEngine: %s.\n",sEvent.data());
}
//---------------------------------------------------------------------------------------------
void TSuperServerLogic::InitLog()
{
  GetLogger()->Register("Inner");// для логирования внутренних событий
  GetLogger()->Init("SuperServer");
}
//---------------------------------------------------------------------------------------------
void TSuperServerLogic::ConnectDown(nsMMOEngine::TEventConnectDown* pEvent)
{
  unsigned int* pID = new unsigned int;
  *pID = pEvent->id_session;
  mListSessionAdd.Add(pID);

  CallBackModule(nsListModules::MMOEngineSuperServer, &TSuperServerLogic::ConnectDownMMOEngine);
}
//---------------------------------------------------------------------------------------------
void TSuperServerLogic::ConnectDownMMOEngine()
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

  CallBackModule(nsListModules::AloneGUI, &TSuperServerLogic::AddMasterQt);
}
//---------------------------------------------------------------------------------------------
void TSuperServerLogic::DisconnectDown(nsMMOEngine::TEventDisconnectDown* pEvent)
{
  TSuperServerForm::TDesc* pDesc = new TSuperServerForm::TDesc;
  pDesc->id_session = pEvent->id_session;
  mListID_SessionDelete.Add(pDesc);

  CallBackModule(nsListModules::AloneGUI, &TSuperServerLogic::DeleteMasterQt);
}
//---------------------------------------------------------------------------------------------
void TSuperServerLogic::AddMasterQt()
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
void TSuperServerLogic::DeleteMasterQt()
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
