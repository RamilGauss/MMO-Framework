/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "SuperServerLogic.h"
#include "ListModules.h"
#include "GlobalParam.h"
#include "ResolverSelf_IP_v4.h"
#include "Logger.h"

#include "ModuleMMOEngineSuperServer.h"
#include "Events.h"

#include <boost/lexical_cast.hpp>

TSuperServerLogic::TSuperServerLogic()
{
  SetCycleTime(100);

  //mSuperServerForm = NULL;
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
    //case nsListModules::AloneGUI:
      //break;
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
  //mSuperServerForm = new TSuperServerForm;
  //mSuperServerForm->show();
}
//------------------------------------------------------------------------------
void TSuperServerLogic::StartEvent()
{
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
      nsMMOEngine::TEventError* pEr = (nsMMOEngine::TEventError*)pBE;
			sEvent = "Error code=";
			sEvent = boost::lexical_cast<std::string>(pEr->code);
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
  //TSessionOperation* pSO = new TSessionOperation;
  //pSO->typeEvent = eAdd;
  //pSO->desc.id_session = pEvent->id_session;
  //mListMasterSessionOperation.Add(pSO);

  //CallBackModule(nsListModules::AloneGUI, &TSuperServerLogic::OperationSessionQt);
}
//---------------------------------------------------------------------------------------------
void TSuperServerLogic::DisconnectDown(nsMMOEngine::TEventDisconnectDown* pEvent)
{
  //TSessionOperation* pSO = new TSessionOperation;
  //pSO->typeEvent = eDelete;
  //pSO->desc.id_session = pEvent->id_session;
  //mListMasterSessionOperation.Add(pSO);

  //CallBackModule(nsListModules::AloneGUI, &TSuperServerLogic::OperationSessionQt);
}
//---------------------------------------------------------------------------------------------
void TSuperServerLogic::OperationSessionQt()
{
  TSessionOperation** ppOperation = mListMasterSessionOperation.GetFirst();
  while(ppOperation)
  {
    TSessionOperation* pOperation = *ppOperation;
    //switch(pOperation->typeEvent)
    //{
    //case eAdd:
    //  if(mSuperServerForm)
    //    mSuperServerForm->Add(pOperation->desc);
    //  break;
    //case eDelete:
    //  if(mSuperServerForm)
    //    mSuperServerForm->Delete(pOperation->desc.id_session);
    //  break;
    //}
    // следующий ID
    mListMasterSessionOperation.RemoveFirst();
    ppOperation = mListMasterSessionOperation.GetFirst();
  }
}
//---------------------------------------------------------------------------------------------
