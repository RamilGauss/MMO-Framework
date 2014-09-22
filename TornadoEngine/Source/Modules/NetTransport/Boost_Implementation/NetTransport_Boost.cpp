/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "NetTransport_Boost.h"

#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/placeholders.hpp>
#include <boost/foreach.hpp>

#include "common_defs.h"
#include "HiTimer.h"
#include "NetSystem.h"
#include "Logger.h"


using namespace std;
using namespace boost::asio;

//----------------------------------------------------------------------------
TNetTransport_Boost::TNetTransport_Boost():
mNetWorkThread()
{
  mUDP.reset(new TNetControlUDP(this, *(mNetWorkThread.GetIO_Service())));
  mAcceptor.reset(new TNetControlAcceptor(this,*(mNetWorkThread.GetIO_Service())));

  mLocalPort  = 0;
  mNumNetWork = 0;

  CreateControlTcpUp();
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
bool TNetTransport_Boost::Open(unsigned short port, unsigned char numNetWork)
{
  mLocalPort  = port;
  mNumNetWork = numNetWork;

  bool res = true;
  res &= mUDP->Open(port, numNetWork);
  if(res) mUDP->Init();
  res &= mAcceptor->Open(port, numNetWork);
  if(res) mAcceptor->Init();

  return res;
}
//----------------------------------------------------------------------------------
void TNetTransport_Boost::Send(unsigned int ip, unsigned short port, 
							                   TBreakPacket packet, bool check)
{
  mMutexSend.lock();
  if(check)
  {
    mMutexMapIP_TCP.lock();
    //---------------------
		TIP_Port ip_port(ip,port);
    TNetControlTCP* pControl = GetTCP_ByIP(ip_port);
    if(pControl)
      pControl->Send(ip,port,packet);
    //---------------------
    mMutexMapIP_TCP.unlock();
  }
  else
    mUDP->Send(ip, port, packet);
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
bool TNetTransport_Boost::Connect(unsigned int ip, unsigned short port)
{
  if(pTCP_Up==NULL)
    CreateControlTcpUp();

  bool res = true;
  res &= pTCP_Up->Open(mLocalPort, mNumNetWork);
  if(res)
    res &= pTCP_Up->Connect(ip, port);
  if(res)
  {
    TIP_Port ip_port(ip, port);
		pTCP_Up->GetDevice()->SetIP_Port(ip_port);
    pTCP_Up->Init();
    // в boost другой порядок байт в описании порта и ip, поэтому пользоваться GetIP
    AddInMapTCP(ip_port,pTCP_Up);
  }
  return res;
}
//----------------------------------------------------------------------------------
void TNetTransport_Boost::Close(unsigned int ip, unsigned short port)
{
  mMutexMapIP_TCP.lock();
  //---------------------
	TIP_Port ip_port(ip,port);
  TNetControlTCP* pControl = GetTCP_ByIP(ip_port);
  if(pControl)
    pControl->Close();
  if(pTCP_Up==pControl)
    pTCP_Up = NULL;
  // delete pControl НЕ вызывать, т.к. при вызове pControl->Close()
  // boost создаст событие RecvEvent(0), на что отреагируем удалением
  //---------------------
  mMutexMapIP_TCP.unlock();
}
//----------------------------------------------------------------------------------
TNetControlTCP* TNetTransport_Boost::GetTCP_ByIP(TIP_Port &ip_port)
{
  TMapIP_PtrIt fit = mMapIP_TCP.find(ip_port);
  if(fit==mMapIP_TCP.end())
    return NULL;
  return fit->second;
}
//----------------------------------------------------------------------------------
void TNetTransport_Boost::AddInMapTCP(TIP_Port& ip_port, TNetControlTCP* pNetControl)
{
  mMutexMapIP_TCP.lock();
  //---------------------
    mMapIP_TCP.insert(TMapIP_Ptr::value_type(ip_port, pNetControl));
  //---------------------
  mMutexMapIP_TCP.unlock();
}
//----------------------------------------------------------------------------------
void TNetTransport_Boost::RemoveFromMapTCP(TIP_Port* ip_port, TNetControlTCP* pControl)
{
  mMutexMapIP_TCP.lock();
  //---------------------
    mMapIP_TCP.erase(*ip_port);
    DeleteControlTCP(pControl);
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
	BOOST_FOREACH( TMapIP_Ptr::value_type &bit, mMapIP_TCP )
    bit.second->Close();
  //---------------------
  mMutexMapIP_TCP.unlock();
}
//----------------------------------------------------------------------------------
void TNetTransport_Boost::DeleteMapControlTCP()
{
  BOOST_FOREACH( TMapIP_Ptr::value_type &bit, mMapIP_TCP )
    DeleteControlTCP(bit.second);
  
  mMapIP_TCP.clear();
}
//----------------------------------------------------------------------------------
void TNetTransport_Boost::CreateControlTcpUp()
{
  pTCP_Up = new TNetControlTCP(this, *(mNetWorkThread.GetIO_Service()));
}
//----------------------------------------------------------------------------------
void TNetTransport_Boost::DeleteControlTCP(TNetControlTCP* pControl)
{
  delete pControl;
  if(pTCP_Up==pControl)
    pTCP_Up = NULL;
}
//----------------------------------------------------------------------------------
