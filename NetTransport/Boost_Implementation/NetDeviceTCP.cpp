/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "NetDeviceTCP.h"
#include "BL_Debug.h"
#include "HiTimer.h"

#include "Logger.h"
#include "INetTransport.h"
#include "NetSystem.h"
#include <boost/asio/socket_base.hpp>

using namespace boost::asio;
using namespace std;


TNetDeviceTCP::TNetDeviceTCP(boost::asio::io_service& io_service):
mSocket(io_service)
{

}
//--------------------------------------------------------------------------------
TNetDeviceTCP::~TNetDeviceTCP()
{

}
//--------------------------------------------------------------------------------
bool TNetDeviceTCP::Open( unsigned short port, unsigned char numNetWork )
{
  bool res = false;
#ifdef WIN32
  char* sLocalHost = ns_getSelfIP(numNetWork);
#else
  char sLocalHost[100];
  get_ip_first_eth(sLocalHost);
#endif
  try
  {
    const ip::address_v4 ipv4_address_Local = ip::address_v4::from_string(sLocalHost);
    const ip::address addr_Local(ipv4_address_Local);
    ip::tcp::endpoint endpoint_Local(addr_Local,port);
    mSocket.open(endpoint_Local.protocol());

    SetReUse();
    OffNagl();
    Set_HardClose();
   
    mSocket.bind(endpoint_Local);
    res = true;
  }
  catch(std::exception& e)
  {
    GetLogger(STR_NAME_NET_TRANSPORT)->
      WriteF_time("Open TCP (%d,%d) FAIL: %s.\n", port, numNetWork, e.what());
  }
  return res;
}
//--------------------------------------------------------------------------------
void TNetDeviceTCP::Close()
{
	if(mSocket.is_open()==false) return;
	try
	{
		mSocket.close();
	}
	catch(std::exception& e)
	{
		GetLogger(STR_NAME_NET_TRANSPORT)->
			WriteF_time("Close TCP FAIL: %s.\n", e.what());
	}
}
//--------------------------------------------------------------------------------
void TNetDeviceTCP::OffNagl()
{
  boost::system::error_code ec;
  ip::tcp::no_delay option(true);
  mSocket.set_option(option);
}
//--------------------------------------------------------------------------------
void TNetDeviceTCP::SetReUse()
{
  mSocket.set_option(ip::tcp::socket::reuse_address(true));
}
//--------------------------------------------------------------------------------
void TNetDeviceTCP::Set_HardClose()
{
  boost::asio::socket_base::linger option(true, 0);
  mSocket.set_option(option);
}
//--------------------------------------------------------------------------------
bool TNetDeviceTCP::SetRecvBuffer(unsigned int size)
{
  boost::system::error_code ec;
  boost::asio::socket_base::receive_buffer_size option(size);
  mSocket.set_option(option,ec);
  return (ec==0);
}
//--------------------------------------------------------------------------------
bool TNetDeviceTCP::SetSendBuffer(unsigned int size)
{
  boost::system::error_code ec;
  boost::asio::socket_base::send_buffer_size option(size);
  mSocket.set_option(option,ec);
  return (ec==0);
}
//--------------------------------------------------------------------------------
