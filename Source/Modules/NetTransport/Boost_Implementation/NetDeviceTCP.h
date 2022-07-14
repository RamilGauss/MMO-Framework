/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "INetDevice.h"
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/io_service.hpp>

class TNetDeviceTCP : public INetDevice
{
    boost::asio::ip::tcp::socket mSocket;
public:
    TNetDeviceTCP(boost::asio::io_context* context);
    virtual ~TNetDeviceTCP();

    virtual bool Open(unsigned short port, unsigned char numNetWork = 0); // ret local sock
    virtual void Close();

    virtual bool SetRecvBuffer(unsigned int size);
    virtual bool SetSendBuffer(unsigned int size);

    boost::asio::ip::tcp::socket* GetSocket()
    {
        return &mSocket;
    }
protected:
    void OffNagl();
    void SetReUse();
    void Set_HardClose();
    void SetNonBlockingMode(bool value);
};
