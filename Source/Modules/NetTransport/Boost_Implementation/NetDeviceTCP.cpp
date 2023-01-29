/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "NetDeviceTCP.h"
#include "MMOEngine/include/INetTransport.h"
#include "MMOEngine/include/EnumMMO.h"
#include "BL_Debug.h"
#include "HiTimer.h"

#include "Logger.h"
#include "ResolverSelf_IP_v4.h"
#include <boost/asio/socket_base.hpp>

using namespace boost::asio;
using namespace std;


TNetDeviceTCP::TNetDeviceTCP(boost::asio::io_context* context) :
    mSocket(*context)
{

}
//--------------------------------------------------------------------------------
TNetDeviceTCP::~TNetDeviceTCP()
{

}
//--------------------------------------------------------------------------------
bool TNetDeviceTCP::Open(unsigned short port, unsigned char numNetWork)
{
    bool res = false;
    std::string sLocalHost;
    TResolverSelf_IP_v4 resolver;
    if (resolver.Get(sLocalHost, numNetWork) == false) {
        return false;
    }
    try {
        mSocket.open(boost::asio::ip::tcp::v4());

        SetReUse();
        OffNagl();
        Set_HardClose();

        mSocket.bind(boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port));

        res = true;
    } catch (std::exception& e) {
        GetLogger(STR_NAME_NET_TRANSPORT)->
            WriteF_time("Open TCP (%d,%d) FAIL: %s.\n", port, numNetWork, e.what());
    }
    return res;
}
//--------------------------------------------------------------------------------
void TNetDeviceTCP::Close()
{
    if (mSocket.is_open() == false) {
        return;
    }
    try {
        mSocket.close();
    } catch (std::exception& e) {
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
void TNetDeviceTCP::SetNonBlockingMode(bool value)
{
    boost::system::error_code ec;
    //mSocket.native_non_blocking( value, ec );
    mSocket.non_blocking(value, ec);
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
    mSocket.set_option(option, ec);
    //return (ec == 0);
    return (ec.failed() == false);
}
//--------------------------------------------------------------------------------
bool TNetDeviceTCP::SetSendBuffer(unsigned int size)
{
    boost::system::error_code ec;
    boost::asio::socket_base::send_buffer_size option(size);
    mSocket.set_option(option, ec);
    //return (ec == 0);
    return (ec.failed() == false);
}
//--------------------------------------------------------------------------------
