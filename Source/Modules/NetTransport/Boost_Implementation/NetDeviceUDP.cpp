/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "NetDeviceUDP.h"
#include "Base/Common/BL_Debug.h"
#include "Base/Common/HiTimer.h"
#include "Base/Common/Logger.h"
#include "MMOEngine/include/INetTransport.h"
#include "MMOEngine/include/EnumMMO.h"
#include "Base/Common/ResolverSelf_IP_v4.h"
#include <boost/asio/buffer.hpp>
#include <boost/asio/socket_base.hpp>

using namespace boost::asio;

TNetDeviceUDP::TNetDeviceUDP(boost::asio::io_context* io_context) :
    mSocket(*io_context)
{

}
//--------------------------------------------------------------------------------
TNetDeviceUDP::~TNetDeviceUDP()
{

}
//--------------------------------------------------------------------------------
bool TNetDeviceUDP::Open(unsigned short port, unsigned char numNetWork)
{
    bool res = false;
    std::string sLocalHost;
    TResolverSelf_IP_v4 resolver;
    if (resolver.Get(sLocalHost, numNetWork) == false) {
        return false;
    }
    try {
        const ip::address_v4 ipv4_address_Local = ip::address_v4::from_string(sLocalHost);
        const ip::address addr_Local(ipv4_address_Local);
        ip::udp::endpoint endpoint_Local(addr_Local, port);
        mSocket.open(endpoint_Local.protocol());
        mSocket.bind(endpoint_Local);

        mIP_Port.Set(ipv4_address_Local.to_ulong(), port);
        res = true;
    } catch (std::exception& e) {
        GetLogger(STR_NAME_NET_TRANSPORT)->
            WriteF_time("Open UDP (%d,%d) FAIL: %s.\n", port, numNetWork, e.what());
    }
    return res;
}
//--------------------------------------------------------------------------------
void TNetDeviceUDP::Close()
{
    if (mSocket.is_open() == false) {
        return;
    }
    try {
        mSocket.close();
    } catch (std::exception& e) {
        GetLogger(STR_NAME_NET_TRANSPORT)->
            WriteF_time("Close UDP FAIL: %s.\n", e.what());
    }
}
//--------------------------------------------------------------------------------
bool TNetDeviceUDP::SetRecvBuffer(unsigned int size)
{
    boost::system::error_code ec;
    boost::asio::socket_base::receive_buffer_size option(size);
    mSocket.set_option(option, ec);
    //return ( ec == 0 );
    return (ec.failed() == false);
}
//--------------------------------------------------------------------------------
bool TNetDeviceUDP::SetSendBuffer(unsigned int size)
{
    boost::system::error_code ec;
    boost::asio::socket_base::send_buffer_size option(size);
    mSocket.set_option(option, ec);
    //return ( ec == 0 );
    return (ec.failed() == false);
}
//--------------------------------------------------------------------------------
