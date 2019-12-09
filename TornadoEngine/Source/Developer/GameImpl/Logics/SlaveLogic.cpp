/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <boost/asio/ip/impl/address_v4.ipp>

#include "SlaveLogic.h"
#include "ListModules.h"
#include "GlobalParam.h"
#include "ResolverSelf_IP_v4.h"
#include "Logger.h"

#include "ModuleMMOEngineSlave.h"
//#include "MMOEngine/include/Events.h"

#include <boost/lexical_cast.hpp>

TSlaveLogic::TSlaveLogic()
{
  SetCycleTime( eCycleTime );

  //mSlaveForm = NULL;

  // значения по-умолчанию для параметров командной строки
  std::string sLocalHost;
  TResolverSelf_IP_v4 resolver;
  resolver.Get( sLocalHost, 0 );

  TInputCmdDevTool::TInput input;
  input.dst_ip = boost::asio::ip::address_v4::from_string( sLocalHost ).to_ulong();
  input.self_port = SLAVE_PORT;
  input.dst_port = MASTER_PORT;

  mInputCmd.mInput = input;
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
void TSlaveLogic::Input( int id, void* p, int size )
{
  switch( id )
  {
    //case nsListModules::AloneGUI:
      //break;
    case nsListModules::MMOEngineSlave:
      HandleFromMMOEngine( (nsMMOEngine::TBaseEvent*)p );
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
  //mSlaveForm = new TSlaveForm;
  //mSlaveForm->show();
}
//------------------------------------------------------------------------------
void TSlaveLogic::StartEvent()
{
  //CallBackModule(nsListModules::AloneGUI, &TSlaveLogic::InitForms);
  ConnectToMaster();
  InitMMOSlave();
}
//----------------------------------------------------------
void TSlaveLogic::StopEvent()
{

}
//----------------------------------------------------------
void TSlaveLogic::ConnectToMaster()
{
  nsMMOEngine::TDescOpen descOpen;
  descOpen.port = mInputCmd.mInput.self_port;
  bool resOpen = mComp.pMMOEngineSlave->Get()->Open( &descOpen );
  std::string login = "1";
  std::string password = "1";
  mComp.pMMOEngineSlave->Get()->ConnectUp( TIP_Port( mInputCmd.mInput.dst_ip, mInputCmd.mInput.dst_port ), login, password );
}
//----------------------------------------------------------
void TSlaveLogic::HandleFromMMOEngine( nsMMOEngine::TBaseEvent* pBE )
{
  std::string sEvent;
  switch( pBE->mType )
  {
    case nsMMOEngine::eConnectDown:
      sEvent = "ConnectDown";
      ConnectDown( (nsMMOEngine::TConnectDownEvent*)pBE );
      break;
    case nsMMOEngine::eDisconnectDown:
      sEvent = "DisconnectDown";
      DisconnectDown( (nsMMOEngine::TDisconnectDownEvent*)pBE );
      break;
    case nsMMOEngine::eConnectUp:
      sEvent = "ConnectUp";
      ConnectUp( (nsMMOEngine::TConnectUpEvent*)pBE );
      break;
    case nsMMOEngine::eDisconnectUp:
      sEvent = "DisconnectUp";
      DisconnectUp( (nsMMOEngine::TDisconnectUpEvent*)pBE );
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
      break;
    case nsMMOEngine::eRecvFromUp:
      sEvent = "RecvFromUp";
      break;
    case nsMMOEngine::eSaveContext:
      sEvent = "SaveContext";
      // типа Сохранить данные нашего Клиента и отдать другому Slave
      SaveContextClient( (nsMMOEngine::TSaveContextEvent*)pBE );
      break;
    case nsMMOEngine::eRestoreContext:
      sEvent = "RestoreContext";
      RestoreContextClient( (nsMMOEngine::TRestoreContextEvent*)pBE );
      break;
    default:BL_FIX_BUG();
  }
  GetLogger( "Inner" )->WriteF_time( "MMOEngine: %s.\n", sEvent.data() );
}
//---------------------------------------------------------------------------------------------
void TSlaveLogic::InitLog()
{
  GetLogger()->Register( "Inner" );// для логирования внутренних событий
  GetLogger()->Init( "Slave" );
}
//---------------------------------------------------------------------------------------------
void TSlaveLogic::ConnectUp( nsMMOEngine::TConnectUpEvent* pBE )
{
  //CallBackModule(nsListModules::AloneGUI, &TSlaveLogic::ConnectUpQt);
}
//---------------------------------------------------------------------------------------------
void TSlaveLogic::DisconnectUp( nsMMOEngine::TDisconnectUpEvent* pBE )
{
  //CallBackModule(nsListModules::AloneGUI, &TSlaveLogic::DisconnectUpQt);
}
//---------------------------------------------------------------------------------------------
void TSlaveLogic::ConnectUpQt()
{
  //if(mSlaveForm)
    //mSlaveForm->SetConnect(true);
}
//---------------------------------------------------------------------------------------------
void TSlaveLogic::DisconnectUpQt()
{
  //if(mSlaveForm)
    //mSlaveForm->SetConnect(false);
}
//---------------------------------------------------------------------------------------------
void TSlaveLogic::ConnectDown( nsMMOEngine::TConnectDownEvent* pEvent )
{
  //TSessionOperation* pSO = new TSessionOperation;
  //pSO->typeEvent = eAdd;
  //pSO->desc.sessionID = pEvent->sessionID;
  //mListClientSessionOperation.Add(pSO);

  //CallBackModule(nsListModules::AloneGUI, &TSlaveLogic::OperationSessionQt);
}
//---------------------------------------------------------------------------------------------
void TSlaveLogic::DisconnectDown( nsMMOEngine::TDisconnectDownEvent* pEvent )
{
  //TSessionOperation* pSO = new TSessionOperation;
  //pSO->typeEvent = eDelete;
  //pSO->desc.sessionID = pEvent->sessionID;
  //mListClientSessionOperation.Add(pSO);

  //CallBackModule(nsListModules::AloneGUI, &TSlaveLogic::OperationSessionQt);
}
//---------------------------------------------------------------------------------------------
void TSlaveLogic::OperationSessionQt()
{
  TSessionOperation** ppOperation = mListClientSessionOperation.GetFirst();
  while( ppOperation )
  {
    TSessionOperation* pOperation = *ppOperation;
    //switch(pOperation->typeEvent)
    //{
    //  case eAdd:
    //    if(mSlaveForm)
    //      mSlaveForm->Add(pOperation->desc);
    //    break;
    //  case eDelete:
    //    if(mSlaveForm)
    //      mSlaveForm->Delete(pOperation->desc.sessionID);
    //    break;
    //}
    // следующий ID
    mListClientSessionOperation.RemoveFirst();
    ppOperation = mListClientSessionOperation.GetFirst();
  }
}
//---------------------------------------------------------------------------------------------
void TSlaveLogic::SaveContextClient( nsMMOEngine::TSaveContextEvent* pEvent )
{
  unsigned int* pID = new unsigned int( pEvent->sessionID );
  SaveContextClientMMOEngine( pID );

  // удалить из списка этого Клиента
  //TSessionOperation* pSO = new TSessionOperation;
  //pSO->typeEvent = eDelete;
  //pSO->desc.sessionID = pEvent->sessionID;
  //mListClientSessionOperation.Add(pSO);

  //CallBackModule(nsListModules::AloneGUI, &TSlaveLogic::OperationSessionQt);
}
//---------------------------------------------------------------------------------------------
void TSlaveLogic::SaveContextClientMMOEngine( unsigned int* pID )
{
  mComp.pMMOEngineSlave->Get()->SaveContext( *pID, NULL, 0 );    // следующий ID
}
//---------------------------------------------------------------------------------------------
void TSlaveLogic::RestoreContextClient( nsMMOEngine::TRestoreContextEvent* pEvent )
{
  //TSessionOperation* pSO = new TSessionOperation;
  //pSO->typeEvent = eAdd;
  //pSO->desc.sessionID = pEvent->sessionID;
  //mListClientSessionOperation.Add(pSO);

  //CallBackModule(nsListModules::AloneGUI, &TSlaveLogic::OperationSessionQt);
}
//---------------------------------------------------------------------------------------------
void TSlaveLogic::InitMMOSlave()
{
  BeginWorkMMOSlave();
}
//---------------------------------------------------------------------------------------------
void TSlaveLogic::BeginWorkMMOSlave()
{
  mComp.pMMOEngineSlave->Get()->SetLoad( GetLastLoad() );
}
//---------------------------------------------------------------------------------------------
