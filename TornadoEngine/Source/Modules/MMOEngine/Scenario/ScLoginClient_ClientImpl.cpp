/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ScLoginClient_ClientImpl.h"
#include "ContextScLoginClient.h"
#include "SessionManager.h"
#include "Base.h"
#include "Logger.h"
#include "Events.h"
#include "EnumMMO.h"
#include "SrcEvent_ex.h"
#include "MD5.h"
#include "IScenario.h"

using namespace nsMMOEngine;
using namespace nsLoginClientStruct;

TScLoginClient_ClientImpl::TScLoginClient_ClientImpl( IScenario* pSc ) :
  TBaseScLoginClient( pSc )
{

}
//-----------------------------------------------------------------------------
void TScLoginClient_ClientImpl::RecvInherit( TDescRecvSession* pDesc )
{
  THeader* pHeader = (THeader*) pDesc->data;
  switch( pHeader->from )
  {
    case eSlave:
      RecvFromSlave( pDesc );
      break;
    case eMaster:
      RecvFromMaster( pDesc );
      break;
    default:BL_FIX_BUG();
  }
}
//-----------------------------------------------------------------------------
void TScLoginClient_ClientImpl::Work( unsigned int time_ms )
{
  // если нет связи с верхним соединением, ждем соединения, если не дождемся нам об этом сообщит SessionManager
  if( Context()->IsConnectUp() == false )
    return;

  if( Context()->IsStateTimeExpired( time_ms ) == false )
    return;

  auto errorType = Context()->GetCurrentStateErrorCode();
  // ошибка на той стороне
  TErrorEvent event;
  event.code = (nsMMOEngine::ErrorCode)errorType;
  Context()->GetSE()->AddEventCopy( &event, sizeof( event ) );
  End();
}
//-----------------------------------------------------------------------------
void TScLoginClient_ClientImpl::TryLogin( TIP_Port& ip_port, std::string& login, std::string& password, unsigned char subNet )
{
  if( Begin() == false )
  {
    // генерация ошибки
    GetLogger( STR_NAME_MMO_ENGINE )->
      WriteF_time( "TScenarioLoginClient::TryLogin() scenario is not active.\n" );
    BL_FIX_BUG();
    return;
  }
  Context()->SetNeedLeaveQueue( false );
  Context()->SetSubNet( subNet );

  Context()->SetLogin( login );
  Context()->SetPassword( password );
  // отправить пакет для попытки авторизации
  auto context = Context();
  auto scenario = this;
  Context()->GetMS()->ConnectAsync( ip_port, login, password, subNet, [context, scenario]( int sessionID )
  {
    scenario->SetContext( context );
    scenario->TryLoginAfterConnect( sessionID );
  } );
}
//-----------------------------------------------------------------------------
void TScLoginClient_ClientImpl::TryLoginAfterConnect( int sessionID )
{
  SetClientSessionID_Master( sessionID );
  if( sessionID == INVALID_HANDLE_SESSION )
  {
    // Генерация ошибки
    TErrorEvent event;
    event.code = LoginClient_ClientMasterNotReady;
    Context()->GetSE()->AddEventCopy( &event, sizeof( event ) );
    End();
    return;
  }

  auto login = Context()->GetLogin();
  // контейнер для всего пакета
  mBP.Reset();
  // иначе просто отправить данные:
  // формирование пакета
  mBP.PushFront( (char*) login.data(), login.size() );
  unsigned char loginLen = login.size();
  mBP.PushFront( (char*) &loginLen, sizeof( loginLen ) );

  THeaderTryLoginC2M h;
  mBP.PushFront( (char*) &h, sizeof( h ) );
  Context()->GetMS()->Send( sessionID, mBP, true );
  
  Context()->SetCurrentStateWait( TContextScLoginClient::ClientWaitMasterAnswer );
}
//-----------------------------------------------------------------------------
void TScLoginClient_ClientImpl::RecvFromSlave( TDescRecvSession* pDesc )
{
  THeader* pHeader = (THeader*) pDesc->data;
  switch( pHeader->subType )
  {
    case eCheckConnectToSlaveS2C:
      CheckConnectToSlaveS2C( pDesc );
      break;
    default:BL_FIX_BUG();
  }
}
//--------------------------------------------------------------
void TScLoginClient_ClientImpl::RecvFromMaster( TDescRecvSession* pDesc )
{
  THeader* pHeader = (THeader*) pDesc->data;
  switch( pHeader->subType )
  {
    case eResultLoginM2C:
      ResultLoginM2C( pDesc );
      break;
    case eInfoSlaveM2C:
      InfoSlaveM2C( pDesc );
      break;
    default:BL_FIX_BUG();
  }
}
//--------------------------------------------------------------
void TScLoginClient_ClientImpl::CheckConnectToSlaveS2C( TDescRecvSession* pDesc )
{
  TResultLoginEvent* pEvent = new TResultLoginEvent;
  pEvent->res = TMaster::eAccept;
  // поместить данные, которые шлет сервер в качестве приветствия
  char* pDataResClient = (char*) Context()->GetSaveAcceptDataPtr();
  int sizeResClient = Context()->GetSaveAcceptDataSize();
  pEvent->c.SetDataByCount( pDataResClient, sizeResClient );
  Context()->GetSE()->AddEventWithoutCopy<TResultLoginEvent>( pEvent );

  ((IScenarioContext*) Context())->SetSessionID( pDesc->sessionID );
  Context()->SetCurrentStateWait( TContextScLoginClient::NoWait );// хотя в End тоже самое
  End();
}
//--------------------------------------------------------------
void TScLoginClient_ClientImpl::ResultLoginM2C( TDescRecvSession* pDesc )
{
  THeaderResultLoginM2C* pH = (THeaderResultLoginM2C*) pDesc->data;
  switch( pH->result )
  {
    case THeaderResultLoginM2C::eAccept:
    {
      // обновить время таймера
      Context()->SetCurrentStateWait( TContextScLoginClient::ClientWaitSlaveInfo );

      // сохранить свой ключ и данные авторизации
      Context()->SetClientKey( pH->clientID );
      char* p = ((char*) (pH)) + sizeof( THeaderResultLoginM2C );
      int size = pH->sizeResClient;
      Context()->SaveAcceptData( p, size );
      EventSetClientKey( pH->clientID );
    }
    break;
    case THeaderResultLoginM2C::eReject:
    {
      // обновить время таймера
      Context()->SetCurrentStateWait( TContextScLoginClient::NoWait );

      CloseSessionMaster();

      TResultLoginEvent* pEvent = new TResultLoginEvent;
      pEvent->res = TMaster::eReject;
      // поместить данные, которые поясняют причину отказа
      char* pDataResClient = pDesc->data + sizeof( THeaderResultLoginM2C );
      pEvent->c.SetDataByCount( pDataResClient, pH->sizeResClient );
      Context()->GetSE()->AddEventWithoutCopy<TResultLoginEvent>( pEvent );
      End();
    }
    break;
    case THeaderResultLoginM2C::eQueue:
    {
      // обновить время таймера
      Context()->SetCurrentStateWait( TContextScLoginClient::ClientWaitInQueue );

      Context()->SetClientKey( pH->clientID );
      EventSetClientKey( pH->clientID );

      Context()->SetNumInQueue( pH->numInQueue );

      TEnterInQueueEvent event;
      event.numInQueue = pH->numInQueue;
      Context()->GetSE()->AddEventCopy( &event, sizeof( event ) );
    }
    break;
    default:BL_FIX_BUG();
  }
}
//--------------------------------------------------------------
void TScLoginClient_ClientImpl::InfoSlaveM2C( TDescRecvSession* pDesc )
{
  Context()->SetNeedLeaveQueue( false );
  // смотрим что нам прислали
  THeaderInfoSlaveM2C* pInfoSlave = (THeaderInfoSlaveM2C*) pDesc->data;
  Context()->SetSlaveIP_Port( pInfoSlave->ip_port_slave );
  // чисто для отладки, что бы удостовериться что назначили
  // в будущем можно будет удалить
  Context()->SetClientKey( pInfoSlave->clientID );
  EventSetClientKey( pInfoSlave->clientID );

  // формируем пакет для Master
  mBP.Reset();
  THeaderCheckInfoSlaveC2M h;
  h.clientID = Context()->GetClientKey();// равнозначно - pInfoSlave->clientID;
  mBP.PushFront( (char*) &h, sizeof( h ) );

  Context()->GetMS()->Send( GetID_SessionClientMaster(), mBP );

  Context()->SetCurrentStateWait( TContextScLoginClient::ClientWaitDisconnectFromMaster );
}
//--------------------------------------------------------------
void TScLoginClient_ClientImpl::LeaveQueue()
{
  // спросить у контекста состоит ли клиент в очереди
  if( Context()->GetNumInQueue() == 0 )
    return;

  mBP.Reset();
  THeaderLeaveQueueC2M h;
  mBP.PushFront( (char*) &h, sizeof( h ) );

  unsigned int id_master = GetID_SessionClientMaster();
  if( id_master == INVALID_HANDLE_SESSION )
    return;

  Context()->SetNeedLeaveQueue( true );
  Context()->GetMS()->Send( id_master, mBP );
}
//--------------------------------------------------------------
void TScLoginClient_ClientImpl::CloseSessionMaster()
{
  Context()->GetMS()->CloseSession( GetID_SessionClientMaster() );
  SetClientSessionID_Master( INVALID_HANDLE_SESSION );
}
//--------------------------------------------------------------
void TScLoginClient_ClientImpl::Disconnect()
{
  // ждет ли в очереди и хочет ли выйти из нее
  if( Context()->NeedLeaveQueue() )
  {
    TLeaveQueueEvent event;
    Context()->GetSE()->AddEventCopy( &event, sizeof( event ) );
    End();
    return;
  }
  // переподключить транспорт с мастера на Slave
  // открыть сессию по IP:port
  TIP_Port ip_port_slave = Context()->GetSlaveIP_Port();
  auto scenario = this;
  auto context = Context();
  auto login = Context()->GetLogin();
  auto password = Context()->GetPassword();
  auto subNet = Context()->GetSubNet();
  Context()->GetMS()->ConnectAsync( ip_port_slave, login, password, subNet, [context, scenario]( int sessionID )
  {
    scenario->SetContext( context );
    scenario->ConnectAfterDisconnect( sessionID );
  } );
}
//--------------------------------------------------------------
void TScLoginClient_ClientImpl::ConnectAfterDisconnect( int sessionID )
{
  // проверка на наличие готовности Slave
  if( sessionID == INVALID_HANDLE_SESSION )
  {
    // Генерация ошибки
    TErrorEvent event;
    event.code = LoginClient_ClientNotExistSlave;
    Context()->GetSE()->AddEventCopy( &event, sizeof( event ) );
    End();
    return;
  }
  // формируем пакет для Slave
  mBP.Reset();
  THeaderConnectToSlaveC2S h;
  // для Slave отдать свой ID, он по нему нас зарегистрирует  
  h.clientID = Context()->GetClientKey();
  mBP.PushFront( (char*) &h, sizeof( h ) );
  Context()->GetMS()->Send( sessionID, mBP, true );

  SetID_SessionClientSlave( sessionID );

  Context()->SetCurrentStateWait( TContextScLoginClient::ClientWaitSlaveAnswer );
}
//--------------------------------------------------------------
