/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "NetTransport/Include/INetControl.h"
#include "NetTransport/Include/NetDeviceAcceptor.h"

class TNetControlTCP;

class TNetControlAcceptor : public INetControl
{
    volatile bool flgReadyAccept;

    TNetDeviceAcceptor mDevice;// слушающий сокет, ждет подключения от клиентов

public:

    TNetControlAcceptor(TNetTransport_Boost* pNTB, boost::asio::io_context* io_context);
    virtual ~TNetControlAcceptor();
    // TNetTransport_XXX
    virtual void Init();
    virtual bool Open(unsigned short port, unsigned char numNetWork = 0);
    virtual bool Connect(unsigned int ip, unsigned short port);              // blocking
    virtual void Send(unsigned int ip, unsigned short port, TBreakPacket& bp);
    virtual void Close();

    virtual TNetDeviceAcceptor* GetDevice()
    {
        return &mDevice;
    }

    bool IsReadyAccept();
protected:
    void Done();

    // asio event
    void AcceptEvent(const boost::system::error_code& error);

    void ReadyAccept();

    TNetControlTCP* pNewControlTCP;
};
