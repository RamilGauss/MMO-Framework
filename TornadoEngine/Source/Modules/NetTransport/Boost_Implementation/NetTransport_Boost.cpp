/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "NetTransport_Boost.h"

#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/placeholders.hpp>

#include "HiTimer.h"
#include "ResolverSelf_IP_v4.h"
#include "Logger.h"
#include <memory>


using namespace std;
using namespace boost::asio;

//----------------------------------------------------------------------------
TNetTransport_Boost::TNetTransport_Boost() :
  mNetWorkThread()
{
  mUDP.reset( new TNetControlUDP( this, mNetWorkThread.GetIO_Context() ) );
  mAcceptor.reset( new TNetControlAcceptor( this, mNetWorkThread.GetIO_Context() ) );
  mTCP_Up.reset( new TNetControlTCP( this, mNetWorkThread.GetIO_Context() ) );

  mLocalPort = 0;
  mNumNetWork = 0;
}
//----------------------------------------------------------------------------------
TNetTransport_Boost::~TNetTransport_Boost()
{
  Done();
}
//----------------------------------------------------------------------------------
void TNetTransport_Boost::Done()
{

}
//----------------------------------------------------------------------------------
bool TNetTransport_Boost::Open( unsigned short port, unsigned char numNetWork )
{
  mLocalPort = port;
  mNumNetWork = numNetWork;

  bool res = true;
  res &= mUDP->Open( port, numNetWork );
  if ( res )
    mUDP->Init();
  res &= mTCP_Up->Open( mLocalPort, mNumNetWork );
  res &= mAcceptor->Open( port, numNetWork );
  if ( res )
    mAcceptor->Init();

  return res;
}
//----------------------------------------------------------------------------------
unsigned short TNetTransport_Boost::GetLocalPort()
{
  return mLocalPort;
}
//----------------------------------------------------------------------------------
unsigned char TNetTransport_Boost::GetNumNetWork()
{
  return mNumNetWork;
}
//----------------------------------------------------------------------------------
void TNetTransport_Boost::Send( unsigned int ip, unsigned short port, TBreakPacket& packet, bool check )
{
  mMutexSend.lock();
  if ( check )
  {
    mMutexMapIP_TCP.lock();
    //---------------------
    TIP_Port ip_port( ip, port );
    TNetControlTCP* pControl = GetTCP_ByIP( ip_port );
    if ( pControl )
      pControl->Send( ip, port, packet );
    //---------------------
    mMutexMapIP_TCP.unlock();
  }
  else
    mUDP->Send( ip, port, packet );
  mMutexSend.unlock();
}
//----------------------------------------------------------------------------------
void TNetTransport_Boost::Start()
{
  mNetWorkThread.Start();
}
//----------------------------------------------------------------------------------
void TNetTransport_Boost::Stop()
{
  CloseAll();

  mNetWorkThread.Stop();

  DeleteMapControlTCP();
}
//----------------------------------------------------------------------------------
bool TNetTransport_Boost::IsActive()
{
  return mNetWorkThread.IsActive();
}
//--------------------------------------------------------------------------
bool TNetTransport_Boost::Connect( unsigned int ip, unsigned short port )
{
  if ( mTCP_Up.get() == nullptr )
  {
    // порядок открытия портов (сначала TCP_Up, потом Acceptor) под Ubuntu - строгий
    mAcceptor->Close();
    // ждать пока Получатель соединений избавится от сокета, который готов к приему.
    while ( mAcceptor->IsReadyAccept() )
      ht_msleep( 0 );
    mAcceptor.reset( new TNetControlAcceptor( this, mNetWorkThread.GetIO_Context() ) );

    mTCP_Up.reset( new TNetControlTCP( this, mNetWorkThread.GetIO_Context() ) );
    bool resOpen = mTCP_Up->Open( mLocalPort, mNumNetWork );

    resOpen &= mAcceptor->Open( mLocalPort, mNumNetWork );
    if ( resOpen ) mAcceptor->Init();
  }
  bool res = mTCP_Up->Connect( ip, port );
  if ( res )
  {
    TIP_Port ip_port( ip, port );
    mTCP_Up->GetDevice()->SetIP_Port( ip_port );
    mTCP_Up->Init();
    // в boost другой порядок байт в описании порта и ip, поэтому пользоваться GetIP
    AddInMapTCP( ip_port, mTCP_Up.get() );
  }
  return res;
}
//----------------------------------------------------------------------------------
void TNetTransport_Boost::Close( unsigned int ip, unsigned short port )
{
  mMutexMapIP_TCP.lock();
  //---------------------
  TIP_Port ip_port( ip, port );
  TNetControlTCP* pControl = GetTCP_ByIP( ip_port );
  if ( pControl )
    pControl->Close();
  // delete pControl НЕ вызывать, т.к. при вызове pControl->Close()
  // boost создаст событие RecvEvent(0), на что отреагируем удалением
  //---------------------
  mMutexMapIP_TCP.unlock();
}
//----------------------------------------------------------------------------------
TNetControlTCP* TNetTransport_Boost::GetTCP_ByIP( TIP_Port& ip_port )
{
  TMapIP_PtrIt fit = mMapIP_TCP.find( ip_port );
  if ( fit == mMapIP_TCP.end() )
    return nullptr;
  return fit->second;
}
//----------------------------------------------------------------------------------
void TNetTransport_Boost::AddInMapTCP( TIP_Port& ip_port, TNetControlTCP* pNetControl )
{
  mMutexMapIP_TCP.lock();
  //---------------------
  mMapIP_TCP.insert( TMapIP_Ptr::value_type( ip_port, pNetControl ) );
  //---------------------
  mMutexMapIP_TCP.unlock();
}
//----------------------------------------------------------------------------------
void TNetTransport_Boost::RemoveFromMapTCP( TIP_Port* ip_port, TNetControlTCP* pControl )
{
  mMutexMapIP_TCP.lock();
  //---------------------
  mMapIP_TCP.erase( *ip_port );
  DeleteControlTCP( pControl );
  //---------------------
  mMutexMapIP_TCP.unlock();
}
//----------------------------------------------------------------------------------
void TNetTransport_Boost::CloseAll()
{
  mUDP->Close();
  mAcceptor->Close();

  mMutexMapIP_TCP.lock();
  //---------------------
  for ( auto& bit : mMapIP_TCP )
    bit.second->Close();
  //---------------------
  mMutexMapIP_TCP.unlock();
}
//----------------------------------------------------------------------------------
void TNetTransport_Boost::DeleteMapControlTCP()
{
  for ( auto& bit : mMapIP_TCP )
    DeleteControlTCP( bit.second );

  mMapIP_TCP.clear();
}
//----------------------------------------------------------------------------------
void TNetTransport_Boost::DeleteControlTCP( TNetControlTCP* pControl )
{
  if ( mTCP_Up.get() == pControl )
  {
    mTCP_Up.reset();
    return;
  }
  delete pControl;
}
//----------------------------------------------------------------------------------
TNetWorkThread* TNetTransport_Boost::GetNetWorkThread()
{
  return &mNetWorkThread;
}
//----------------------------------------------------------------------------------