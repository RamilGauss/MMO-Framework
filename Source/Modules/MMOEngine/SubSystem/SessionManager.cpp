/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "SessionManager.h"
#include "Logger.h"
#include "Base.h"

using namespace std;
using namespace nsMMOEngine;

TSessionManager::TSessionManager()
{
  mNavigateSession = new TSessionNavigator;
  mMngTransport = new TTransportManager( this );
}
//--------------------------------------------------------------------------------------------
TSessionManager::~TSessionManager()
{
  // сначала уничтожить сессии, важно вызвать до уничтожения Менеджера транспорта
  delete mNavigateSession;
  mNavigateSession = nullptr;// не готов к приему пакетов

  delete mMngTransport;
}
//--------------------------------------------------------------------------------------------
void TSessionManager::SetMakerTransport( IMakerTransport* pMakerTransport )
{
  mMngTransport->SetTransport( pMakerTransport );
}
//--------------------------------------------------------------------------------------------
bool TSessionManager::Start( TDescOpen* pDesc, int count )
{
  if( flgStart )
  {
    GetLogger( STR_NAME_MMO_ENGINE )->WriteF_time( "TSessionManager::Start() restart.\n" );
    BL_FIX_BUG();
    return false;
  }
  flgStart = true;

  for( int i = 0; i < count; i++ )
    if( StartTransport( pDesc[i].port, pDesc[i].subNet ) == false )
      return false;
  return true;
}
//--------------------------------------------------------------------------------------------
bool TSessionManager::StartTransport( unsigned short port, unsigned char subNet )
{
  INetTransport* pTransport = mMngTransport->Add( subNet );
  bool resOpen = pTransport->Open( port, subNet );
  if( resOpen == false )
  {
    char s[100];
    sprintf( s, "TSessionManager::Start() open port %u FAIL.\n", port );
    GetLogger( STR_NAME_MMO_ENGINE )->WriteF_time( s );
    BL_MessageBug( s );
    return false;
  }
  // старт потока чтения
  pTransport->Start();
  return resOpen;
}
//--------------------------------------------------------------------------------------------
void TSessionManager::Work()
{
  if( mNavigateSession == nullptr )
    return;
  //===================================================================
  TransportEventHandler();

  mSessionListOnDelete.clear();
  mNavigateSession->Work( mSessionListOnDelete );
  for( auto pSession : mSessionListOnDelete )
    mNavigateSession->Delete( pSession );

  if( flgNeedAnswerFromUp )// ждем ответа
  {
    if( flgReceiveAnswerFromUp )// ответ получен
    {
      CleanWaitConnectUp();// больше не ждем
      mConnectResult( mSessionID_UP );// оповестить
    }
    else
    {
      auto now = ht_GetMSCount();// таймер на соединение на верх
      if( now > mBeinWaitConnectUpTime + eLimitWaitTimeAnswerFromUp )// вышло время ожидания
      {
        CleanWaitConnectUp();// больше не ждем
        CloseSession( mSessionID_UP );
        mSessionID_UP = INVALID_HANDLE_SESSION;
        mConnectResult( mSessionID_UP );// оповестить
      }
    }
  }
}
//--------------------------------------------------------------------------------------------
void TSessionManager::Send( unsigned int sessionID, TBreakPacket& bp, bool check )
{
  if( mNavigateSession == nullptr )
    return;
  TSession* pSession = mNavigateSession->FindSessionByID( sessionID );
  if( pSession )
    Send( pSession, bp, check );
}
//--------------------------------------------------------------------------------------------
void TSessionManager::ConnectAsync( TIP_Port& ip_port, std::string& login, std::string& password, unsigned char subNet, ConnectResultCallback onResult )
{
  BL_ASSERT( flgNeedAnswerFromUp == false );

  mConnectResult = onResult;
  BeginWaitConnectUp();
  lockConnectUp();

  INetTransport* pTransport = mMngTransport->FindBySubNet( subNet );
  if( pTransport == nullptr )
  {
    unlockConnectUp();
    return mConnectResult( INVALID_HANDLE_SESSION );
  }

  if( mNavigateSession == nullptr )
  {
    unlockConnectUp();
    return mConnectResult( INVALID_HANDLE_SESSION );
  }
  //===================================================================
  // соединиться с сервером (верхнее соединение)
  if( pTransport->Connect( ip_port.ip, ip_port.port ) == false )
  {
    unlockConnectUp();
    return mConnectResult( INVALID_HANDLE_SESSION );// нет такого прослушивающего порта
  }// connect to event
  mIP_PortUp = ip_port; // запомнить параметры верхнего соединения

  TSession* pSession = mNavigateSession->FindSessionByIP( mIP_PortUp );
  if( pSession == nullptr )
    pSession = NewSession( mIP_PortUp, pTransport, true/*connect to*/ );
  else
  {
    unlockConnectUp();
    GetLogger( STR_NAME_MMO_ENGINE )->
      WriteF_time( "TSessionManager::Send(%s) sending to IP with exist session.\n", ip_port.ToString() );
    BL_FIX_BUG();
    return mConnectResult( INVALID_HANDLE_SESSION );
  }
  mSessionID_UP = pSession->GetID();
  pSession->SetLogin( login );
  pSession->SetPassword( password );
  pSession->SetState( TSession::StateWaitKeyAES );
  pSession->SendLogin();

  unlockConnectUp();
  // waiting recv...
}
//--------------------------------------------------------------------------------------------
unsigned int TSessionManager::GetSessionID( unsigned int ip, unsigned short port )
{
  unsigned int id = INVALID_HANDLE_SESSION;
  if( mNavigateSession == nullptr )
    return id;
  TIP_Port ip_port( ip, port );
  TSession* pSession = mNavigateSession->FindSessionByIP( ip_port );
  if( pSession )
    id = pSession->GetID();
  return id;
}
//--------------------------------------------------------------------------------------------
void TSessionManager::CloseSession( unsigned int ID_Session )
{
  if( ID_Session == INVALID_HANDLE_SESSION )
    return;

  if( mNavigateSession == nullptr )
    return;
  TSession* pSession = mNavigateSession->FindSessionByID( ID_Session );
  if( pSession )
    mNavigateSession->Delete( pSession );
}
//--------------------------------------------------------------------------------------------
void TSessionManager::Recv( INetTransport::TDescRecv* pDescRecv )
{
  auto transportEvent = new TRecvTransportEvent();
  transportEvent->ip_port = pDescRecv->ip_port;
  transportEvent->typeRecv = pDescRecv->type;
  transportEvent->data.SetData( pDescRecv->data, pDescRecv->dataSize );
  mTransportEventList.Add( transportEvent );
}
//--------------------------------------------------------------------------------------------
void TSessionManager::RecvHandler( TRecvTransportEvent* pEvent )
{
  if( mNavigateSession == nullptr )
    return;
  //===================================================================
  // данные, пришедшие от сессии содержат заголовок, учесть при формировании
  auto pHeader = (TSession::THeader*)pEvent->data.GetPtr();
  // определить новая сессия или нет
  TSession* pSession = mNavigateSession->FindSessionByIP( pEvent->ip_port );
  if( pSession == nullptr )
    return;

  TDescRecvSession descRecvSession;
  descRecvSession.c        = pEvent->data;// данные пакета
  descRecvSession.data     = descRecvSession.c.GetPtr();
  descRecvSession.dataSize = descRecvSession.c.GetSize();

  descRecvSession.ip_port   = pEvent->ip_port;
  descRecvSession.type      = pEvent->typeRecv;
  descRecvSession.sessionID = pSession->GetID();
  // данные, пришедшие от сессии содержат заголовок, учесть при формировании
  switch( pHeader->type )
  {
    case TSession::eEcho:
      break;
    case TSession::eData:
      RecvData( descRecvSession, pSession );
      break;
    case TSession::eLogin:
      RecvLogin( descRecvSession, pSession );
      break;
    case TSession::eKeyAES:
      RecvKeyAES( descRecvSession, pSession );
      break;
    case TSession::eIDconfirmation:
      RecvIDconfirmation( descRecvSession, pSession );
      break;
    default:
    {
      BL_FIX_BUG();
      FixHack( "Undefined type packet" );
    }
  }
}
//--------------------------------------------------------------------------------------------
void TSessionManager::Disconnect( TIP_Port* ip_port )
{
  auto disconnectEvent = new TDisconnectTransportEvent();
  disconnectEvent->ip_port = *ip_port;
  mTransportEventList.Add( disconnectEvent );
}
//--------------------------------------------------------------------------------------------
void TSessionManager::DisconnectHandler( TDisconnectTransportEvent* pEvent )
{
  if( mNavigateSession == nullptr )
    return;

  TSession* pSession = mNavigateSession->FindSessionByIP( pEvent->ip_port );
  if( pSession )
  {
    unsigned int id = pSession->GetID();
    mCallBackDiconnect.Notify( id );
    mNavigateSession->Delete( pSession );
  }
}
//--------------------------------------------------------------------------------------------
void TSessionManager::ConnectFrom( TIP_Port* ip_port, INetTransport* pTransport )
{
  auto connectFromEvent = new TConnectFromTransportEvent();
  connectFromEvent->ip_port = *ip_port;
  connectFromEvent->pTransport = pTransport;
  mTransportEventList.Add( connectFromEvent );
}
//-------------------------------------------------------------------------------------------
void TSessionManager::ConnectFromHandler( TConnectFromTransportEvent* pEvent )
{
  NewSession( pEvent->ip_port, pEvent->pTransport, false );
}
//--------------------------------------------------------------------------------------------
TSession* TSessionManager::NewSession( TIP_Port& ip_port, INetTransport* pTransport, bool connectTo_elseFrom )
{
  auto state = connectTo_elseFrom ? TSession::StateWaitConnectTo : TSession::StateWaitLogin;

  mLastID_Session++;// нет проверки на совпадение, unsigned int 4 млрд - слишком много
  TSession* pSession = new TSession( state, mTimeLiveSession );
  pSession->SetTransport( pTransport );
  pSession->SetInfo( ip_port );
  pSession->SetID( mLastID_Session );

  mNavigateSession->Add( pSession );
  return pSession;
}
//--------------------------------------------------------------------------------------------
bool TSessionManager::IsExist( unsigned int ID_Session )
{
  if( mNavigateSession == nullptr )
    return false;
  //===================================================================
  TSession* pSession = mNavigateSession->FindSessionByID( ID_Session );
  return (pSession != nullptr);
}
//--------------------------------------------------------------------------------------------
void TSessionManager::SetTimeLiveSession( unsigned int time_ms )
{
  mTimeLiveSession = time_ms;
}
//-------------------------------------------------------------------------
bool TSessionManager::GetInfo( unsigned int ID_Session, TIP_Port& ip_port_out )
{
  bool res = false;
  if( mNavigateSession == nullptr )
    return false;
  //===================================================================
  TSession* pSession = mNavigateSession->FindSessionByID( ID_Session );
  if( pSession )
  {
    res = true;
    pSession->GetInfo( ip_port_out );
  }
  return res;
}
//-------------------------------------------------------------------------
void TSessionManager::RecvData( TDescRecvSession& descRecvSession, TSession* pSession )
{
  // проверка размера
  if( descRecvSession.dataSize <= sizeof( TSession::THeader ) )
  {
    FixHack( "Size less Header" );
    return;
  }
  // под расшифрованные данные
  TContainerPtr c_decrypt;

  descRecvSession.data += sizeof( TSession::THeader );
  descRecvSession.dataSize -= sizeof( TSession::THeader );

  if( descRecvSession.type == INetTransport::eTcp )
  {
    if( descRecvSession.dataSize <= sizeof( unsigned char ) )// crc8, 1 байт
    {
      FixHack( "Size less CRC8" );
      return;
    }
    // попытка расшифровать
    if( pSession->RecvData( descRecvSession.data, descRecvSession.dataSize, c_decrypt ) == false )
    {
      FixHack( "Can't decrypt packet" );
      BL_FIX_BUG();
      return;
    }
    // поместить результат
    descRecvSession.data = (char*) c_decrypt.GetPtr();
    descRecvSession.dataSize = c_decrypt.GetSize();
  }
  mCallBackRecv.Notify( &descRecvSession );
}
//-------------------------------------------------------------------------
void TSessionManager::RecvLogin( TDescRecvSession& descRecvSession, TSession* pSession )
{
  auto loginHash = descRecvSession.data + sizeof( TSession::THeader );
  int loginHashSize = descRecvSession.dataSize - sizeof( TSession::THeader );

  // запомнить хэш логина
  pSession->SetLoginHash( loginHash, loginHashSize );
  pSession->SetState( TSession::StateWaitDeveloper );

  TTryConnectDown tryConnectDown;
  tryConnectDown.loginHash.SetData( loginHash, loginHashSize );
  tryConnectDown.sessionID = pSession->GetID();
  GetCallbackTryConnectDown()->Notify( &tryConnectDown );
}
//-------------------------------------------------------------------------
void TSessionManager::RecvKeyAES( TDescRecvSession& descRecvSession, TSession* pSession )
{
  char* pKey = descRecvSession.data + sizeof( TSession::THeader );
  int keySize = descRecvSession.dataSize - sizeof( TSession::THeader );

  if( pSession->RecvKeyAES( pKey, keySize ) )
  {
    pSession->SetState( TSession::StateWork );
    pSession->SendIDconfirmation();
  }
  else
  {
    CloseSession( pSession->GetID() );
    mSessionID_UP = INVALID_HANDLE_SESSION;
  }
  flgReceiveAnswerFromUp = true;
}
//-------------------------------------------------------------------------
void TSessionManager::RecvIDconfirmation( TDescRecvSession& descRecvSession, TSession* pSession )
{
  char* pConfirm = descRecvSession.data + sizeof( TSession::THeader );
  int confirmSize = descRecvSession.dataSize - sizeof( TSession::THeader );

  if( pSession->RecvIDconfirmation( pConfirm, confirmSize ) )
    pSession->SetState( TSession::StateWork );
  else
    CloseSession( pSession->GetID() );
}
//-------------------------------------------------------------------------
void TSessionManager::FixHack( char* sMsg )
{
  GetLogger( STR_NAME_MMO_ENGINE )->WriteF_time( "Try hack: %s.\n", sMsg );
}
//-------------------------------------------------------------------------
void TSessionManager::BeginWaitConnectUp()
{
  flgNeedAnswerFromUp = true;// начали ждать
  flgReceiveAnswerFromUp = false;
  mBeinWaitConnectUpTime = ht_GetMSCount();
}
//-------------------------------------------------------------------------
void TSessionManager::CleanWaitConnectUp()
{
  flgNeedAnswerFromUp = false;
  flgReceiveAnswerFromUp = false;
}
//-------------------------------------------------------------------------
void TSessionManager::Send( TSession* pSession, TBreakPacket& bp, bool check )
{
  pSession->Send( bp, check );
}
//-------------------------------------------------------------------------
void TSessionManager::Accept( unsigned int sessionID, std::string& password )
{
  if( mNavigateSession == nullptr )
  {
    BL_FIX_BUG();
    return;
  }
  TSession* pSession = mNavigateSession->FindSessionByID( sessionID );
  if( pSession == nullptr )
  {
    BL_FIX_BUG();
    return;
  }

  pSession->SetPassword( password );
  pSession->SetState( TSession::StateWaitConfirmation );
  pSession->SendKeyAES();
}
//-------------------------------------------------------------------------
void TSessionManager::Reject( unsigned int sessionID )
{
  CloseSession( sessionID );
}
//-------------------------------------------------------------------------
void TSessionManager::TransportEventHandler()
{
  auto ppFirst = mTransportEventList.GetFirst();
  while( ppFirst )
  {
    auto pFirst = *ppFirst;
    switch( pFirst->type )
    {
      case TBaseTransportEvent::Recv:
        RecvHandler( (TRecvTransportEvent*)pFirst );
        break;
      case TBaseTransportEvent::Disconnect:
        DisconnectHandler( (TDisconnectTransportEvent*) pFirst );
        break;
      case TBaseTransportEvent::ConnectFrom:
        ConnectFromHandler( (TConnectFromTransportEvent*) pFirst );
        break;
    }

    mTransportEventList.RemoveFirst();
    ppFirst = mTransportEventList.GetFirst();
  }
}
//-------------------------------------------------------------------------
