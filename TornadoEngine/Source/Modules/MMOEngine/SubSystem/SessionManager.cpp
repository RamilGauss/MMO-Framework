/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "SessionManager.h"
#include "Logger.h"
#include "Base.h"

#include <boost/foreach.hpp>

//#define NOT_USE_CRYPT_TCP

using namespace std;
using namespace nsMMOEngine;

TSessionManager::TSessionManager()
{
  CleanFlagsForWaitUp();

#ifndef NOT_USE_CRYPT_TCP
  SetUseCryptTCP( true );
#else
  SetUseCryptTCP( false );
#endif
  mNavigateSession = new TSessionNavigator;
  mMngTransport = new TTransportManager( this );

  flgStart = false;
  mTimeLiveSession = eDefTimeLive;
  mLastID_Session = 0;
}
//--------------------------------------------------------------------------------------------
TSessionManager::~TSessionManager()
{
  // сначала уничтожить сессии, важно вызвать до уничтожения Менеджера транспорта
  lockAccessSession();
  delete mNavigateSession;
  mNavigateSession = NULL;// не готов к приему пакетов
  unlockAccessSession();

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
  lockAccessSession();
  if( mNavigateSession == NULL )
  {
    unlockAccessSession();
    return;
  }
  //===================================================================
  mNavigateSession->Work();
  unlockAccessSession();
}
//--------------------------------------------------------------------------------------------
void TSessionManager::Send( unsigned int id_session, TBreakPacket& bp, bool check )
{
  lockAccessSession();
  if( mNavigateSession == NULL )
  {
    unlockAccessSession();
    return;
  }
  //===================================================================
  TSession* pSession = mNavigateSession->FindSessionByID( id_session );
  if( pSession )
    Send( pSession, bp, check );

  unlockAccessSession();
}
//--------------------------------------------------------------------------------------------
unsigned int TSessionManager::Connect( unsigned int ip, unsigned short port, TBreakPacket& bp, unsigned char subNet, bool check )
{
  lockConnectUp();

  INetTransport* pTransport = mMngTransport->FindBySubNet( subNet );
  if( pTransport == NULL )
  {
    unlockConnectUp();
    return INVALID_HANDLE_SESSION;
  }

  lockAccessSession();
  if( mNavigateSession == NULL )
  {
    unlockAccessSession();
    unlockConnectUp();
    return INVALID_HANDLE_SESSION;
  }
  //===================================================================
  // соединиться с сервером
  if( pTransport->Connect( ip, port ) == false )
  {
    unlockAccessSession();
    unlockConnectUp();
    //BL_FIX_BUG();
    return INVALID_HANDLE_SESSION;// нет такого прослушивающего порта
  }
  mIP_PortUp.Set( ip, port );  // запомнить параметры верхнего соединения

  TSession* pSession = mNavigateSession->FindSessionByIP( mIP_PortUp );
  if( pSession == NULL )
    pSession = NewSession( mIP_PortUp, pTransport );
  else
  {
    unlockAccessSession();
    unlockConnectUp();
    GetLogger( STR_NAME_MMO_ENGINE )->
      WriteF_time( "TSessionManager::Send(0x%X,%u) sending to IP with exist session.\n", ip, port );
    BL_FIX_BUG();
    return INVALID_HANDLE_SESSION;
  }
  unsigned int id_session = pSession->GetID();
  // отсылка запроса на AES ключ
  SendKeyRSA_Up( pSession );

  unlockAccessSession();
  //===================================================================
  // ждем ответа
  bool res = WaitAnswerFromUp();
  CleanFlagsForWaitUp();
  if( res == false )
  {
    unlockConnectUp();
    GetLogger( STR_NAME_MMO_ENGINE )->
      WriteF_time( "Wait Answer From Up don't recv answer.\n" );
    return INVALID_HANDLE_SESSION;
  }
  //===================================================================
  lockAccessSession();
  if( mNavigateSession == NULL )
  {
    // произошел разрыв соединения
    unlockAccessSession();
    unlockConnectUp();
    return INVALID_HANDLE_SESSION;
  }
  // возможно сессия была удалена, пока ждали ответа
  pSession = mNavigateSession->FindSessionByID( id_session );
  if( pSession )
    Send( pSession, bp, check );
  else
    id_session = INVALID_HANDLE_SESSION;

  unlockConnectUp();
  unlockAccessSession();
  return id_session;
}
//--------------------------------------------------------------------------------------------
unsigned int TSessionManager::GetSessionID( unsigned int ip, unsigned short port )
{
  unsigned int id = INVALID_HANDLE_SESSION;
  lockAccessSession();
  if( mNavigateSession == NULL )
  {
    unlockAccessSession();
    return id;
  }
  //===================================================================
  TIP_Port ip_port( ip, port );
  TSession* pSession = mNavigateSession->FindSessionByIP( ip_port );
  if( pSession )
    id = pSession->GetID();
  unlockAccessSession();
  return id;
}
//--------------------------------------------------------------------------------------------
void TSessionManager::CloseSession( unsigned int ID_Session )
{
  if( ID_Session == INVALID_HANDLE_SESSION )
    return;

  lockAccessSession();
  if( mNavigateSession == NULL )
  {
    unlockAccessSession();
    return;
  }
  //===================================================================
  TSession* pSession = mNavigateSession->FindSessionByID( ID_Session );
  if( pSession )
  {
    TIP_Port ip_port;
    pSession->GetInfo( ip_port );
    mMngCtxCrypto.Close( ip_port );

    mNavigateSession->Delete( pSession );
  }
  unlockAccessSession();
}
//--------------------------------------------------------------------------------------------
void TSessionManager::Recv( INetTransport::TDescRecv* pDescRecv, INetTransport* pTransport )
{
  lockAccessSession();
  if( mNavigateSession == NULL )
  {
    unlockAccessSession();
    return;
  }
  //===================================================================
  // данные, пришедшие от сессии содержат заголовок, учесть при формировании
  TSession::THeader* pHeader = (TSession::THeader*)pDescRecv->data;
  // определить новая сессия или нет
  TSession* pSession = mNavigateSession->FindSessionByIP( pDescRecv->ip_port );
  if( pSession == NULL )
  {
    // новую сессию создавать, только если получен RSA ключ
    if( pHeader->type != TSession::eKeyRSA )
    {
      unlockAccessSession();
      return;
    }
    pSession = NewSession( pDescRecv->ip_port, pTransport );
  }
  else
    pSession->Recv();// уведомить сессию о приеме
  unsigned int id = pSession->GetID();
  //-----------------------------------------------
  TDescRecvSession descRecvSession;
  *((INetTransport::TDescRecv*)&descRecvSession) = *pDescRecv;
  descRecvSession.id_session = id;
  // данные, пришедшие от сессии содержат заголовок, учесть при формировании
  descRecvSession.use_crypt = pHeader->use_crypt;
  switch( pHeader->type )
  {
    case TSession::eEcho:
      break;
    case TSession::ePacket:
      RecvPacket( descRecvSession, pSession );
      break;
    case TSession::eKeyRSA:
      RecvKeyRSA( descRecvSession, pSession );
      break;
    case TSession::eKeyAES:
      RecvKeyAES( descRecvSession );
      break;
    default:
      FixHack( "Undefined type packet" );
  }
  unlockAccessSession();
}
//--------------------------------------------------------------------------------------------
void TSessionManager::Disconnect( TIP_Port* ip_port )
{
  lockAccessSession();
  if( mNavigateSession == NULL )
  {
    unlockAccessSession();
    return;
  }
  //===================================================================
  mMngCtxCrypto.Close( *ip_port );

  TSession* pSession = mNavigateSession->FindSessionByIP( *ip_port );
  if( pSession )
  {
    unsigned int id = pSession->GetID();
    mCallBackDiconnect.Notify( id );
    mNavigateSession->Delete( pSession );
  }
  unlockAccessSession();
}
//--------------------------------------------------------------------------------------------
TSession* TSessionManager::NewSession( TIP_Port& ip_port, INetTransport* pTransport )
{
  mLastID_Session++;// нет проверки на совпадение, unsigned int 4 млрд - слишком много
  TSession* pSession = new TSession( mTimeLiveSession );
  pSession->SetTransport( pTransport );
  pSession->SetInfo( ip_port );
  pSession->SetID( mLastID_Session );

  mNavigateSession->Add( pSession );
  return pSession;
}
//--------------------------------------------------------------------------------------------
bool TSessionManager::IsExist( unsigned int ID_Session )
{
  lockAccessSession();
  if( mNavigateSession == NULL )
  {
    unlockAccessSession();
    return false;
  }
  //===================================================================
  TSession* pSession = mNavigateSession->FindSessionByID( ID_Session );
  unlockAccessSession();
  return (pSession != NULL);
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
  lockAccessSession();
  if( mNavigateSession == NULL )
  {
    unlockAccessSession();
    return false;
  }
  //===================================================================
  TSession* pSession = mNavigateSession->FindSessionByID( ID_Session );
  if( pSession )
  {
    res = true;
    pSession->GetInfo( ip_port_out );
  }
  unlockAccessSession();
  return res;
}
//-------------------------------------------------------------------------
void TSessionManager::SetUseCryptTCP( bool v )
{
  flgUseCryptTCP = v;
}
//-------------------------------------------------------------------------
bool TSessionManager::GetUseCryptTCP()
{
  return flgUseCryptTCP;
}
//-------------------------------------------------------------------------
void TSessionManager::RecvPacket( TDescRecvSession& descRecvSession, TSession* pSession )
{
  // вся система должна обмениваться либо шифрованными либо не шифрованными пакетами
  if( GetUseCryptTCP() )
  {
    // все компоненты шифруют, а вот получили мы не шифрованный. Игнорируем пакет.
    if( descRecvSession.use_crypt == false )
    {
      FixHack( "System use crypt, but recv not crypt" );
      return;
    }
  }
  // проверка размера
  if( descRecvSession.sizeData <= sizeof( TSession::THeader ) )
  {
    FixHack( "Size less Header" );
    return;
  }
  // под расшифрованные данные
  TContainerPtr c_decrypt;

  descRecvSession.data += sizeof( TSession::THeader );
  descRecvSession.sizeData -= sizeof( TSession::THeader );

  if( descRecvSession.use_crypt )
  {
    if( descRecvSession.sizeData <= sizeof( unsigned int )  // counter 4 байта
      + sizeof( unsigned char ) )// crc8, 1 байт
    {
      FixHack( "Size less Counter + CRC8" );
      return;
    }
    // зашифрованным может быть только TCP
    if( descRecvSession.type == INetTransport::eUdp )
    {
      FixHack( "Using crypt for UDP" );
      BL_FIX_BUG();
      return;
    }
    // попытка расшифровать
    if( mMngCtxCrypto.Recv( descRecvSession.ip_port, descRecvSession.data,
      descRecvSession.sizeData, c_decrypt ) == false )
    {
      FixHack( "Can't decrypt packet" );
      BL_FIX_BUG();
      return;
    }
    // поместить результат
    descRecvSession.data = (char*) c_decrypt.GetPtr();
    descRecvSession.sizeData = c_decrypt.GetSize();
    // внутренний счетчик сессии должен быть меньше чем полученный
    if( pSession->GetCounterIn() >= ((unsigned int*) descRecvSession.data)[0] )
    {
      FixHack( "Fail counter in" );
      return;
    }
    // смещаемся на длину счетчика
    descRecvSession.data += sizeof( unsigned int );
    descRecvSession.sizeData -= sizeof( unsigned int );
  }
  mCallBackRecv.Notify( &descRecvSession );
}
//-------------------------------------------------------------------------
void TSessionManager::RecvKeyRSA( TDescRecvSession& descRecvSession, TSession* pSession )
{
  char* pKey = descRecvSession.data + sizeof( TSession::THeader );
  int sizeKey = descRecvSession.sizeData - sizeof( TSession::THeader );

  if( mMngCtxCrypto.RecvRSA_PublicKey( descRecvSession.ip_port, pKey, sizeKey ) == false )
  {
    FixHack( "Incorrect RSA public key" );
    return;
  }

  TContainer c_AESkey;
  mMngCtxCrypto.SendAES_Key( descRecvSession.ip_port, c_AESkey );
  pSession->SendKeyAES( c_AESkey );
}
//-------------------------------------------------------------------------
void TSessionManager::RecvKeyAES( TDescRecvSession& descRecvSession )
{
  char* pKey = descRecvSession.data + sizeof( TSession::THeader );
  int sizeKey = descRecvSession.sizeData - sizeof( TSession::THeader );

  if( mMngCtxCrypto.RecvAES_Key( descRecvSession.ip_port, pKey, sizeKey ) == false )
  {
    FixHack( "Incorrect AES public key" );
    return;
  }

  flgGetAnswerFromUp = true;
}
//-------------------------------------------------------------------------
void TSessionManager::FixHack( char* sMsg )
{
  GetLogger( STR_NAME_MMO_ENGINE )->WriteF_time( "Try hack: %s.\n", sMsg );
}
//-------------------------------------------------------------------------
bool TSessionManager::WaitAnswerFromUp()
{
  unsigned int start_ms = ht_GetMSCount();
  unsigned int delta = 0;

  while( delta < eLimitWaitTimeAnswerFromUp )
  {
    if( flgGetAnswerFromUp )
      return true;
    ht_msleep( eSleepForWaitUp );
    unsigned int now_ms = ht_GetMSCount();
    delta = now_ms - start_ms;
  }
  return false;
}
//-------------------------------------------------------------------------
void TSessionManager::SetupFlagsForWaitUp()
{
  flgNeedAnswerFromUp = true;
  flgGetAnswerFromUp = false;
}
//-------------------------------------------------------------------------
void TSessionManager::CleanFlagsForWaitUp()
{
  flgNeedAnswerFromUp = false;
  flgGetAnswerFromUp = false;
}
//-------------------------------------------------------------------------
void TSessionManager::SendKeyRSA_Up( TSession* pSession )
{
  SetupFlagsForWaitUp();

  TContainer c_RSAkey;
  mMngCtxCrypto.SendRSA_PublicKey( mIP_PortUp, c_RSAkey );

  pSession->SendKeyRSA( c_RSAkey );
}
//-------------------------------------------------------------------------
void TSessionManager::Send( TSession* pSession, TBreakPacket& bp, bool check )
{
  if( check == true )// TCP
    if( GetUseCryptTCP() )
    {
      // достать ip и порт
      TIP_Port ip_port;
      pSession->GetInfo( ip_port );
      pSession->IncrementCounterOut();
      unsigned int counter_out = pSession->GetCounterOut();
      bp.PushFront( (char*) &counter_out, sizeof( counter_out ) );
      // зашифровать
      TContainer c_encrypt;
      mMngCtxCrypto.Send( ip_port, bp, c_encrypt );
      // создать новый пакет
      mEncryptBP.Reset();
      mEncryptBP.PushFront( (char*) c_encrypt.GetPtr(), c_encrypt.GetSize() );
      // отправить с параметром "шифруется"
      pSession->Send( mEncryptBP, true, true );
      return;
    }
  // либо UDP, либо не шифрованный TCP
  pSession->Send( bp, check );
}
//-------------------------------------------------------------------------
bool TSessionManager::GetRSAPublicKeyForUp( TContainer& cRSA )
{
  return mMngCtxCrypto.GetRSAkeyForUp( cRSA );
}
//-------------------------------------------------------------------------
bool TSessionManager::GetRSAPublicKey( unsigned int id_session, TContainer& cRSA )
{
  bool res = false;
  TIP_Port ip_port;
  lockAccessSession();
  if( mNavigateSession == NULL )
  {
    unlockAccessSession();
    return res;
  }
  //===================================================================
  TSession* pSession = mNavigateSession->FindSessionByID( id_session );
  if( pSession )
  {
    pSession->GetInfo( ip_port );
    res = mMngCtxCrypto.GetRSAkeyByIP( ip_port, cRSA );
  }

  unlockAccessSession();
  return res;
}
//-------------------------------------------------------------------------
