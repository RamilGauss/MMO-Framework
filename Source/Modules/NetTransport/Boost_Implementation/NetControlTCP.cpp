/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <boost/asio/placeholders.hpp>
#include <boost/smart_ptr/shared_array.hpp>
#include <boost/asio/socket_base.hpp>
#include <boost/bind.hpp>

#include "NetControlTCP.h"
#include "BL_Debug.h"

#include "Logger.h"
#include "HistoryPacketTCP.h"
#include "HeaderTCP.h"
#include "HiTimer.h"
#include "NetTransport_Boost.h"
#include "MMOEngine/include/EnumMMO.h"

using namespace std;

TNetControlTCP::TNetControlTCP( TNetTransport_Boost* pNTB, boost::asio::io_context* context ) :
  INetControl( pNTB ),
  mDevice( context )
{
  mReadSize = 0;
}
//------------------------------------------------------------------------------
TNetControlTCP::~TNetControlTCP()
{
  Close();
}
//------------------------------------------------------------------------------
bool TNetControlTCP::Open( unsigned short port, unsigned char numNetWork )
{
  return mDevice.Open( port, numNetWork );
}
//----------------------------------------------------------------------------------
bool TNetControlTCP::Connect( unsigned int ip, unsigned short port )
{
  flgWaitConnect = true;
  flgResConnect = false;
  TIP_Port ip_port( ip, port );
  RequestConnect( ip_port );

  while ( flgWaitConnect )
    ht_msleep( eWaitConnect );

  return flgResConnect;
}
//----------------------------------------------------------------------------------
void TNetControlTCP::Send( unsigned int ip, unsigned short port, TBreakPacket& bp )
{
  THistoryPacketTCP::PackForSend( bp );
  bp.Collect();

  char* data = (char*)bp.GetCollectPtr();
  int size = bp.GetSize();

  RequestSend( data, size );
}
//----------------------------------------------------------------------------------
void TNetControlTCP::Close()
{
  mDevice.Close();
}
//----------------------------------------------------------------------------------
void TNetControlTCP::RecvEvent( const boost::system::error_code& error, size_t bytes_transferred )
{
  if ( error || bytes_transferred <= 0 )
  {
    GetLogger( STR_NAME_NET_TRANSPORT )->
      WriteF_time( "RecvEvent TCP disconnect error=%s.\n", error.message().data() );

    DeleteSelf();
    return;
  }
  int beginPos = 0;
  mReadSize = bytes_transferred;
  while ( beginPos < mReadSize )
  {
    THistoryPacketTCP::TResult res;
    mHistory.Analiz( beginPos, res, mReadSize, mBuffer );
    // если ошибка парсинга - удалить и выйти
    if ( res.parse_error )
    {
      DeleteSelf();
      return;
    }
    // завершен ли пакет
    if ( res.complete )
    {
      nsMMOEngine::INetTransport::TDescRecv descRecv;
      descRecv.ip_port = *( mDevice.GetIP_Port() );
      descRecv.type = nsMMOEngine::INetTransport::eTcp;
      descRecv.data = res.buffer;
      descRecv.dataSize = res.size;
      NotifyRecv( &descRecv );
    }
  }
  ReadyRecv();
}
//----------------------------------------------------------------------------------
void TNetControlTCP::SendEvent( const boost::system::error_code& error, size_t bytes_transferred )
{
  if ( error )
    GetLogger( STR_NAME_NET_TRANSPORT )->
    WriteF_time( "SendEvent TCP error=%s.\n", error.message().data() );
}
//----------------------------------------------------------------------------------
void TNetControlTCP::ConnectEvent( const boost::system::error_code& error )
{
  flgResConnect = ( error.failed() == false );
  flgWaitConnect = false;

  if ( error.failed() )
    GetLogger( STR_NAME_NET_TRANSPORT )->
    WriteF_time( "ConnectEvent TCP error=%s.\n", error.message().data() );
}
//----------------------------------------------------------------------------------
void TNetControlTCP::ReadyRecv()
{
  try
  {
    mDevice.GetSocket()->async_receive( boost::asio::buffer( &mBuffer[0], eSizeBuffer ),
      boost::bind( &TNetControlTCP::RecvEvent, this,
        boost::asio::placeholders::error,
        boost::asio::placeholders::bytes_transferred ) );
  }
  catch ( std::exception & e )
  {
    GetLogger( STR_NAME_NET_TRANSPORT )->
      WriteF_time( "ReadyRecv TCP error=%s.\n", e.what() );
  }
}
//----------------------------------------------------------------------------------
//#define USE_ASYNC_SEND
void TNetControlTCP::RequestSend( char* data, int size )
{
#ifdef USE_ASYNC_SEND
  mDevice.GetSocket()->async_send( boost::asio::buffer( data, size ),
    []( const boost::system::error_code& ec, std::size_t bytes_transferred )
  {
    if ( ec )
    {
      int ass = 0;
    }
  } );
#else
l_repeat:
  boost::asio::socket_base::message_flags flags = 0;
  boost::system::error_code ec;
  int resSend = mDevice.GetSocket()->send( boost::asio::buffer( data, size ), flags, ec );
  if ( ec )
  {
    GetLogger( STR_NAME_NET_TRANSPORT )->
      WriteF_time( "RequestSend TCP error=%s.\n", ec.message().data() );
    return;
  }
  if ( resSend < size )
  {
    ht_msleep( eTimeRepeatSend );
    size -= resSend;
    data += resSend;
    goto l_repeat;
  }
#endif
}
//----------------------------------------------------------------------------------
void TNetControlTCP::RequestConnect( TIP_Port& ip_port )
{
  try
  {
    mConnectEndpoint = boost::asio::ip::tcp::endpoint
    ( boost::asio::ip::address_v4( ip_port.ip ), ip_port.port );
    mDevice.GetSocket()->connect( mConnectEndpoint );
    flgWaitConnect = false;
    flgResConnect = true;
  }
  catch ( std::exception & e )
  {
    GetLogger( STR_NAME_NET_TRANSPORT )->
      WriteF_time( "RequestConnect TCP error=%s, ip_port=%s.\n", e.what(), ip_port.ToString() );

    flgWaitConnect = false;
    flgResConnect = false;
  }
}
//----------------------------------------------------------------------------------
void TNetControlTCP::Init()
{
  ReadyRecv();
}
//--------------------------------------------------------------------------------
void TNetControlTCP::DeleteSelf()
{
  TIP_Port ip_port = *( mDevice.GetIP_Port() );
  TNetTransport_Boost* pNetTransport_Boost = GetNetBoost();
  pNetTransport_Boost->RemoveFromMapTCP( &ip_port, this );
  // передать стековый объект, т.к. mDevice уже уничтожен, а pNetTransport_Boost - указатель на хозяина (он еще существует)
  NotifyDisconnect( &ip_port, pNetTransport_Boost );
}
//--------------------------------------------------------------------------------
