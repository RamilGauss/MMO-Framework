/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/


#pragma once

#include <map>

#include "INetControl.h"
#include "NetDeviceTCP.h"
#include "Mutex.h"
#include "HistoryPacketTCP.h"

class TNetControlTCP : public INetControl
{
    TNetDeviceTCP mDevice;// для соединения с сервером
    THistoryPacketTCP mHistory;

    enum
    {
        eSizeBuffer = 64000,
        eWaitConnect = 40,// мс
        eTimeRepeatSend = 0,//20,// мс
    };

    char mBuffer[eSizeBuffer];
    int mReadSize;

    volatile bool flgWaitConnect;
    volatile bool flgResConnect;
public:

    TNetControlTCP(TNetTransport_Boost* pNTB, boost::asio::io_context* context);
    virtual ~TNetControlTCP();

    // TNetTransport_XXX
    virtual void Init();
    virtual bool Open(unsigned short port, unsigned char numNetWork = 0);
    virtual bool Connect(unsigned int ip, unsigned short port);
    virtual void Send(unsigned int ip, unsigned short port, TBreakPacket& bp);
    virtual void Close();
    virtual TNetDeviceTCP* GetDevice()
    {
        return &mDevice;
    }

    virtual char* GetBuffer()
    {
        return &mBuffer[0];
    }
    virtual int   GetSize()
    {
        return eSizeBuffer;
    }
protected:
    void DeleteSelf();

    // asio event
    void RecvEvent(const boost::system::error_code& error, size_t bytes_transferred);
    void SendEvent(const boost::system::error_code& error, size_t bytes_transferred);
    void ConnectEvent(const boost::system::error_code& error);

    void ReadyRecv();
    void RequestSend(char* data, int size);
    void RequestConnect(TIP_Port& ip_port);

    boost::asio::ip::tcp::endpoint mConnectEndpoint;
};