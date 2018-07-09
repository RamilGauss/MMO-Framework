/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "Session.h"
#include "HiTimer.h"

#include <time.h>
#include "ContainerTypes.h"
#include "BL_Debug.h"

using namespace nsMMOEngine;

TSession::TSession( State state, unsigned int time_live_ms )
{
  mTimeLive = time_live_ms;

  mLastTimeActive = ht_GetMSCount();
  mTransport = nullptr;

  SetState( state );
}
//---------------------------------------------------------------------
TSession::~TSession()
{
  Close();
}
//---------------------------------------------------------------------
void TSession::Work()
{
  unsigned int now_ms = ht_GetMSCount();

  switch( GetState() )
  {
    case TSession::eConnectTo:
      break;
    case TSession::eConnectFrom:
      if( mStateChangeTime + WaitConnectFrom < now_ms )
        Close();
      break;
    case TSession::eWaitKeyAES:
      if( mStateChangeTime + WaitKeyAES < now_ms )
      {
        BL_FIX_BUG();
      }
      break;
    case TSession::eWaitConirmation:
      if( mStateChangeTime + WaitConfirmation < now_ms )
        Close();
      break;
    case TSession::eWork:
      if( mLastTimeActive + mTimeLive < now_ms )
      {
        SendEcho();
        RefreshLastTime();
      }
      break;
  }
}
//---------------------------------------------------------------------
void TSession::Send( TBreakPacket& bp, bool check )
{
  if( check )
  {
    // Data + crc8(Data) => Encrypt
    bp.CopyInBuffer( mBuffer );
    unsigned char crc8;
    mCalcCRC8.Calc( mBuffer.GetPtr(), mBuffer.GetSize(), crc8 );

    bp.PushBack( (char*) &crc8, sizeof( crc8 ) );
    bp.CopyInBuffer( mBuffer );

    mSendAES.Encrypt( mBuffer.GetPtr(), mBuffer.GetSize(), mEncrypt );
    bp.Reset();
    bp.PushBack( (char*) mEncrypt.GetPtr(), mEncrypt.GetSize() );
  }

  SendData( eData, bp, check );
  // гарантия того что пакет дойдет
  // иначе сессия на той стороне не освежит время
  if( check )
    RefreshLastTime();
}
//---------------------------------------------------------------------
void TSession::SetTransport( INetTransport* pTransport )
{
  mTransport = pTransport;
}
//---------------------------------------------------------------------
void TSession::GetInfo( TIP_Port& pDesc )
{
  pDesc = mIP_Port;
}
//---------------------------------------------------------------------
void TSession::SetInfo( TIP_Port& pDesc )
{
  mIP_Port = pDesc;
}
//---------------------------------------------------------------------
void TSession::UpdateLastTime()
{
  RefreshLastTime();
}
//---------------------------------------------------------------------
bool TSession::RecvData( void* data, int dataSize, TContainerPtr& result )
{
  // Encrypt => Data + crc8(Data)
  mRecvAES.Decrypt( data, dataSize, mRecvDataContainer );
  auto p = (unsigned char*) mRecvDataContainer.GetPtr();
  auto size = mRecvDataContainer.GetSize();
  auto indexCRC8 = size - sizeof( unsigned char );
  auto sizeWithoutCRC8 = indexCRC8;

  unsigned char recvCRC8 = p[indexCRC8];// последний байт - crc8

  unsigned char crc8;
  mCalcCRC8.Calc( p, sizeWithoutCRC8, crc8 );
  if( crc8 != recvCRC8 )
    return false;

  result.SetData( mRecvDataContainer.GetPtr(), sizeWithoutCRC8 );
  return true;
}
//---------------------------------------------------------------------
bool TSession::RecvKeyAES( void* pKey, int keySize )// Client
{
  unsigned char recvCRC8 = ((unsigned char*) pKey)[keySize - 1];

  mPasswordAES.Decrypt( pKey, keySize - sizeof( unsigned char ), mDecrypt );

  unsigned char crc8;
  mCalcCRC8.Calc( mDecrypt.GetPtr(), mDecrypt.GetSize(), crc8 );
  if( crc8 != recvCRC8 )
    return false;

  // запомнить пароль для работы
  SetKeyAES( mDecrypt.GetPtr(), mDecrypt.GetSize() );
  return true;
}
//---------------------------------------------------------------------
bool TSession::RecvIDconfirmation( void* pConfirm, int confirmSize )// Server
{
  if( mRecvAES.Decrypt( pConfirm, confirmSize - sizeof( unsigned char ), mDecrypt ) == false )
    return false;

  unsigned char recvCRC8 = ((unsigned char*) pConfirm)[confirmSize - 1];
  unsigned char crc8;
  mCalcCRC8.Calc( mDecrypt.GetPtr(), mDecrypt.GetSize(), crc8 );
  if( crc8 != recvCRC8 )
    return false;

  return true;
}
//---------------------------------------------------------------------
void TSession::SendEcho()
{
  mBP.Reset();
  SendData( eEcho, mBP );
}
//---------------------------------------------------------------------
void TSession::RefreshLastTime()
{
  mLastTimeActive = ht_GetMSCount();
}
//---------------------------------------------------------------------
void TSession::SendData( char type, TBreakPacket& bp, bool check )
{
  THeader h( type );
  bp.PushFront( (char*) &h, sizeof( THeader ) );
  mTransport->Send( mIP_Port.ip, mIP_Port.port, bp, check );
}
//---------------------------------------------------------------------
void TSession::Close()
{
  mTransport->Close( mIP_Port.ip, mIP_Port.port );
}
//---------------------------------------------------------------------
void TSession::SetState( State state )
{
  mState = state;
  mStateChangeTime = ht_GetMSCount();
}
//---------------------------------------------------------------------
TSession::State TSession::GetState()
{
  return mState;
}
//---------------------------------------------------------------------
unsigned int TSession::GetStateChangeTime()
{
  return mStateChangeTime;
}
//---------------------------------------------------------------------
void TSession::SendLogin()// Client
{
  mBP.Reset();
  mBP.PushFront( mLoginHash.GetPtr(), mLoginHash.GetSize() );
  SendData( eLogin, mBP, true );
}
//---------------------------------------------------------------------
void TSession::SendIDconfirmation()// Client
{
  mPasswordAES.GetKey( mBuffer );
  mSendAES.Encrypt( mBuffer.GetPtr(), mBuffer.GetSize(), mEncrypt );

  unsigned char crc8;
  mCalcCRC8.Calc( mBuffer.GetPtr(), mBuffer.GetSize(), crc8 );

  mBP.Reset();
  mBP.PushBack( (char*) mEncrypt.GetPtr(), mEncrypt.GetSize() );
  mBP.PushBack( (char*) &crc8, sizeof( crc8 ) );

  SendData( eIDconfirmation, mBP, true );
}
//---------------------------------------------------------------------
void TSession::SendKeyAES()// Server
{
  mSendAES.GenerateKey();

  mSendAES.GetKey( mBuffer );
  mRecvAES.SetKey( mBuffer.GetPtr(), mBuffer.GetSize() );
  mPasswordAES.Encrypt( mBuffer.GetPtr(), mBuffer.GetSize(), mEncrypt );// шифруем рабочий ключ паролем 
  unsigned char crc8;
  mCalcCRC8.Calc( mBuffer.GetPtr(), mBuffer.GetSize(), crc8 );

  mBP.Reset();
  mBP.PushBack( (char*) mEncrypt.GetPtr(), mEncrypt.GetSize() );
  mBP.PushBack( (char*) &crc8, sizeof( crc8 ) );

  SendData( eKeyAES, mBP, true );
}
//---------------------------------------------------------------------
void TSession::SetLogin( std::string& login )
{
  mLogin = login;
  mSHA256.FastCalc( (char*) mLogin.data(), mLogin.size(), mLoginHash );
}
//---------------------------------------------------------------------
void TSession::SetLoginHash( char* loginHash, int loginHashSize )
{
  mLoginHash.SetData( loginHash, loginHashSize );
}
//---------------------------------------------------------------------
std::string TSession::GetLoginHashStr()
{
  std::string hash;
  int size = mLoginHash.GetSize();
  auto p = (unsigned char*) mLoginHash.GetPtr();
  for( int i = 0; i < size; i++ )
  {
    char append[100];
    sprintf( append, "0x%02X", p[i] );
    hash += append;
    if( i != size - 1 )
      hash += ",";
  }
  return hash;
}
//---------------------------------------------------------------------
void TSession::SetPassword( std::string& password )
{
  mPassword = password;
  mSHA256.FastCalc( (char*) mPassword.data(), mPassword.size(), mPasswordHash );
  mPasswordAES.SetKey( mPasswordHash.GetPtr(), mPasswordHash.GetSize() );
}
//---------------------------------------------------------------------
void TSession::SetKeyAES( void* p, int size )
{
  mSendAES.SetKey( p, size );
  mRecvAES.SetKey( p, size );
}
//---------------------------------------------------------------------
