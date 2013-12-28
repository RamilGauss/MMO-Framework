/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "NetControlAcceptor.h"
#include "BL_Debug.h"

#include "Logger.h"
#include "NetTransport_Boost.h"
#include "NetControlTCP.h"
#include <boost/asio/placeholders.hpp>
#include <boost/system/error_code.hpp>

using namespace std;

TNetControlAcceptor::TNetControlAcceptor(boost::asio::io_service& io_service):
mDevice(io_service)
{
  pNewControlTCP = NULL;
}
//------------------------------------------------------------------------------
TNetControlAcceptor::~TNetControlAcceptor()
{
}
//------------------------------------------------------------------------------
bool TNetControlAcceptor::Open( unsigned short port, unsigned char numNetWork)
{
  return mDevice.Open(port,numNetWork);
}
//------------------------------------------------------------------------------
bool TNetControlAcceptor::Connect(unsigned int ip, unsigned short port)
{
  return false;
}
//------------------------------------------------------------------------------
void TNetControlAcceptor::Send(unsigned int ip, unsigned short port, TBreakPacket bp)
{

}
//------------------------------------------------------------------------------
void TNetControlAcceptor::Close()
{
  mDevice.Close();
}
//------------------------------------------------------------------------------
void TNetControlAcceptor::AcceptEvent(const boost::system::error_code& error)
{
  if(error==0)
  {
    TIP_Port ip_port;
    ip_port.port = pNewControlTCP->GetDevice()->GetSocket()->remote_endpoint().port();
    ip_port.ip   = pNewControlTCP->GetDevice()->GetSocket()->remote_endpoint().address().to_v4().to_ulong();
    pNewControlTCP->GetDevice()->SetIP_Port(ip_port);
    GetNetBoost()->AddInMapTCP(ip_port,pNewControlTCP);
    pNewControlTCP->Init();// готов к чтению
  }
  else
	{
		delete pNewControlTCP;
		pNewControlTCP = NULL;
		GetLogger(STR_NAME_NET_TRANSPORT)->
      WriteF_time("Acceptor AcceptEvent FAIL: %s.\n", error.message().data());
		return;
	}

  ReadyAccept();
}
//------------------------------------------------------------------------------
void TNetControlAcceptor::Done()
{

}
//------------------------------------------------------------------------------
void TNetControlAcceptor::ReadyAccept()
{
  pNewControlTCP = new TNetControlTCP(mDevice.GetSocket()->get_io_service());
  mDevice.GetSocket()->async_accept(*(pNewControlTCP->GetDevice()->GetSocket()),
    boost::bind(&TNetControlAcceptor::AcceptEvent, this, 
    boost::asio::placeholders::error));
}
//------------------------------------------------------------------------------
void TNetControlAcceptor::Init()
{
  ReadyAccept();
}
//------------------------------------------------------------------------------
