/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "MMOEngine/include/INetTransport.h"
#include "Base/Common/Mutex.h"
#include "NetWorkThread.h"

#include "NetControlTCP.h"
#include "NetControlAcceptor.h"
#include "NetControlUDP.h"

// Thread safe - Send поддерживает.

class TNetTransport_Boost : public nsMMOEngine::INetTransport
{
    unsigned short mLocalPort;
    unsigned char  mNumNetWork;

    TMutex mMutexSend;
    TMutex mMutexMapIP_TCP;

    TNetWorkThread mNetWorkThread;

    std::shared_ptr<TNetControlUDP>      mUDP;
    std::shared_ptr<TNetControlAcceptor> mAcceptor;
    std::shared_ptr<TNetControlTCP>      mTCP_Up;

    std::unordered_map<TIP_Port, TNetControlTCP*> mMapIP_TCP;

    TCallbackPool<nsMMOEngine::INetTransport::TDescRecv*> mCallBackRecv;
    TCallbackPool<TIP_Port*>                              mCallBackConnectFrom;
    TCallbackPool<TIP_Port*>                              mCallBackDisconnect;

public:
    TNetTransport_Boost();
    virtual ~TNetTransport_Boost();

    bool Open(unsigned short port, unsigned char numNetWork = 0) override;
    unsigned short GetLocalPort() override;
    unsigned char GetNumNetWork() override;

    void Send(unsigned int ip, unsigned short port, TBreakPacket& packet, bool check = true) override;

    TCallbackPool<TDescRecv*>* GetCallbackRecv() override;
    TCallbackPool<TIP_Port* >* GetCallbackConnectFrom() override;
    TCallbackPool<TIP_Port* >* GetCallbackDisconnect() override;

    void Start() override;
    void Stop() override;
    bool IsActive() override;

    // синхронная функция
    bool Connect(unsigned int ip, unsigned short port) override; // вызов только для клиента

    void Close(unsigned int ip, unsigned short port) override;
public:

    void AddInMapTCP(TIP_Port& ip_port, TNetControlTCP* pNetControl);
    void RemoveFromMapTCP(TIP_Port* ip_port, TNetControlTCP* pControl);

    TNetWorkThread* GetNetWorkThread();

protected:
    void CloseAll();
    void DeleteMapControlTCP();

    void DeleteControlTCP(TNetControlTCP* pControl);

    TNetControlTCP* GetTCP_ByIP(TIP_Port& ip_port);
};
