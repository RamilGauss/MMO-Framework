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
#include "MMOEngine/include/Events.h"

#include <boost/lexical_cast.hpp>

TSuperServerLogic::TSuperServerLogic()
{
  SetCycleTime(100);

  //mSuperServerForm = NULL;
  // значения по-умолчанию для параметров командной строки
  TInputCmdDevTool::TInput input;
  input.self_port = SUPER_SERVER_PORT;

  mInputCmd.mInput = input;
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
  OpenPort();
}
//----------------------------------------------------------
void TSuperServerLogic::StopEvent()
{

}
//----------------------------------------------------------
void TSuperServerLogic::OpenPort()
{
  nsMMOEngine::TDescOpen descOpen;
  descOpen.port = mInputCmd.mInput.self_port;
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
      ConnectDown((nsMMOEngine::TConnectDownEvent*)pBE);
      break;
    case nsMMOEngine::eDisconnectDown:
      sEvent = "DisconnectDown";
      DisconnectDown((nsMMOEngine::TDisconnectDownEvent*)pBE);
      break;
    case nsMMOEngine::eError:
    {
      nsMMOEngine::TErrorEvent* pEr = (nsMMOEngine::TErrorEvent*)pBE;
      sEvent = "Error code=";
      sEvent = boost::lexical_cast<std::string>(pEr->code);
    }
      break;
    case nsMMOEngine::eRecvFromDown:
      sEvent = "RecvFromDown";
      {
        // ###
        //unsigned int sessionID = ((TRecvFromDownEvent*)pBE)->sessionID;
        //char s = 's';
        //TBreakPacket bp;
        //bp.PushBack(&s, sizeof(s));
        //mComponent.mNet.SuperServer->SendDown(sessionID,bp);
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
void TSuperServerLogic::ConnectDown(nsMMOEngine::TConnectDownEvent* pEvent)
{
  //TSessionOperation* pSO = new TSessionOperation;
  //pSO->typeEvent = eAdd;
  //pSO->desc.sessionID = pEvent->sessionID;
  //mListMasterSessionOperation.Add(pSO);

  //CallBackModule(nsListModules::AloneGUI, &TSuperServerLogic::OperationSessionQt);
}
//---------------------------------------------------------------------------------------------
void TSuperServerLogic::DisconnectDown(nsMMOEngine::TDisconnectDownEvent* pEvent)
{
  //TSessionOperation* pSO = new TSessionOperation;
  //pSO->typeEvent = eDelete;
  //pSO->desc.sessionID = pEvent->sessionID;
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
    //    mSuperServerForm->Delete(pOperation->desc.sessionID);
    //  break;
    //}
    // следующий ID
    mListMasterSessionOperation.RemoveFirst();
    ppOperation = mListMasterSessionOperation.GetFirst();
  }
}
//---------------------------------------------------------------------------------------------
