/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "NetDeviceUDP.h"
#include "BL_Debug.h"
#include "HiTimer.h"
#include "Logger.h"
#include "INetTransport.h"
#include "NetSystem.h"
#include <boost/asio/buffer.hpp>
#include <boost/asio/socket_base.hpp>

using namespace boost::asio;

TNetDeviceUDP::TNetDeviceUDP(boost::asio::io_service& io_service):
mSocket(io_service)
{

}
//--------------------------------------------------------------------------------
TNetDeviceUDP::~TNetDeviceUDP()
{

}
//--------------------------------------------------------------------------------
bool TNetDeviceUDP::Open( unsigned short port, unsigned char numNetWork )
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
    ip::udp::endpoint endpoint_Local(addr_Local,port);
    mSocket.open(endpoint_Local.protocol());
    mSocket.bind(endpoint_Local);

    mIP_Port.Set( ns_inet_addr(sLocalHost), port); 
    res = true;
  }
  catch(std::exception& e)
  {
    GetLogger(STR_NAME_NET_TRANSPORT)->
      WriteF_time("Open UDP (%d,%d) FAIL: %s.\n", port, numNetWork, e.what());
  }
  return res;
}
//--------------------------------------------------------------------------------
void TNetDeviceUDP::Close()
{
	if(mSocket.is_open()==false) return;
	try
	{
		//mSocket.shutdown(boost::asio::socket_base::shutdown_type::shutdown_both);
		mSocket.close();
	}
	catch(std::exception& e)
	{
		GetLogger(STR_NAME_NET_TRANSPORT)->
			WriteF_time("Close UDP FAIL: %s.\n", e.what());
	}
}
//--------------------------------------------------------------------------------
bool TNetDeviceUDP::SetRecvBuffer(unsigned int size)
{
  boost::system::error_code ec;
  boost::asio::socket_base::receive_buffer_size option(size);
  mSocket.set_option(option,ec);
  return (ec==0);
}
//--------------------------------------------------------------------------------
bool TNetDeviceUDP::SetSendBuffer(unsigned int size)
{
  boost::system::error_code ec;
  boost::asio::socket_base::send_buffer_size option(size);
  mSocket.set_option(option,ec);
  return (ec==0);
}
//--------------------------------------------------------------------------------
