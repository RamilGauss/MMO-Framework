/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "INetDevice.h"
#include <boost/asio/ip/udp.hpp>
#include <boost/asio/io_service.hpp>

class TNetDeviceUDP : public INetDevice
{
    boost::asio::ip::udp::socket mSocket;

public:
    TNetDeviceUDP(boost::asio::io_context* io_context);
    virtual ~TNetDeviceUDP();

    virtual bool Open(unsigned short port, unsigned char numNetWork = 0);
    virtual void Close();

    virtual bool SetRecvBuffer(unsigned int size);
    virtual bool SetSendBuffer(unsigned int size);

    boost::asio::ip::udp::socket* GetSocket()
    {
        return &mSocket;
    }
};