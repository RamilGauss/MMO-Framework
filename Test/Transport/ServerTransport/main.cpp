/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <string.h>
#include <errno.h>
#include <boost/asio/ip/impl/address_v4.ipp>
#include "Base/Common/BL_Debug.h"
#include "InputCmdServerTransport.h"
#include "Base/Common/HiTimer.h"
#include "Base/Common/Logger.h"
#include "Base/Common/ShareMisc.h"
#include "NetTransport/MakerNetTransport.h"
#include "MMOEngine/include/INetTransport.h"

#include "Handler.h"

TInputCmdServerTransport::TInput g_InputArg;
nsMMOEngine::INetTransport* g_pServerTransport = nullptr;
std::set<TIP_Port> g_Clients;

unsigned short g_ServerPort = 30000;
bool g_isTesting;
THandler g_Handler;

TInfoPacket g_InfoPacket;
TBreakPacket g_BP;
TDataPacket g_Packet;

const int kPacketCount = 100000;

template <typename T>
void Handle(TDataExchange2Thread<T>& list, std::function<void(T*)> handlerFunc)
{
    auto pp = list.GetFirst();
    while (pp)
    {
        auto p = *pp;
        handlerFunc(p);
        list.RemoveFirst();
        pp = list.GetFirst();
    }
}
//---------------------------------------------------------------------------------------
void TryStartTest()
{
    if (g_isTesting)
        return;

    g_isTesting = true;
}
//---------------------------------------------------------------------------------------
void TryStopTest()
{
    g_isTesting = false;
}
//---------------------------------------------------------------------------------------
void TrySendInfo()
{
    if (g_Clients.size() == 0)
        return;

    g_BP.Reset();
    g_BP.PushBack((char*)&g_InfoPacket, sizeof(g_InfoPacket));
    auto ip_port = *(g_Clients.begin());
    g_pServerTransport->Send(ip_port.ip, ip_port.port, g_BP);
}
//---------------------------------------------------------------------------------------
void Test()
{
    int cnt = kPacketCount / g_Clients.size();
    int packetCount = 0;
    unsigned int start = ht_GetMSCount();
l_Repeat:
    for (int i = 0; i < cnt; i++)
    {
        for (auto& ip_port : g_Clients)
        {
            g_BP.Reset();
            g_BP.PushBack((char*)&g_Packet, sizeof(g_Packet));

            g_pServerTransport->Send(ip_port.ip, ip_port.port, g_BP);
            packetCount++;
        }
    }
    unsigned int now_ms = ht_GetMSCount();

    auto delta = now_ms - start;
    if (delta < 1000)
        goto l_Repeat;

    g_InfoPacket.timerPerSend = (delta * 1000.0f) / packetCount;
}
//---------------------------------------------------------------------------------------
void HandleConnect()
{
    Handle<TIP_Port>(g_Handler.mConnectedList, [](TIP_Port* pIp_port)
        {
            g_Clients.insert(*pIp_port);
        });
}
//---------------------------------------------------------------------------------------
void HandleDisconnect()
{
    Handle<TIP_Port>(g_Handler.mDisconnectedList, [](TIP_Port* pIp_port)
        {
            g_Clients.erase(*pIp_port);
        });

    if (g_isTesting)
    {
        if (g_Clients.size() == 0)
            g_isTesting = false;
    }
}
//---------------------------------------------------------------------------------------
void HandleRecv()
{
    Handle<TContainer>(g_Handler.mRecvList, [](TContainer* p)
        {
            auto pPacket = (TBasePacket*)(p->GetPtr());
            switch (pPacket->type)
            {
            case TBasePacket::eStart:
                TryStartTest();
                break;
            case TBasePacket::eStop:
                TryStopTest();
                break;
            case TBasePacket::eGet:
                TrySendInfo();
                break;
            default:
                BL_FIX_BUG();
                break;
            }
        });
}
//---------------------------------------------------------------------------------------
int main(int argc, char** argv)
{
    TInputCmdServerTransport inputCmd;
    bool res = inputCmd.SetArg(argc, argv);
    BL_ASSERT(res);

    inputCmd.Get(g_InputArg);

    // обязательно инициализировать лог
    std::string sLocalHost;
    TResolverSelf_IP_v4 resolver;
    int countIP_v4 = resolver.GetCount();
    printf("ip count = %d\n", countIP_v4);
    for (int i = 0; i < countIP_v4; i++)
    {
        if (resolver.Get(sLocalHost, i) == false)
            continue;
        printf("ip = %s\n", sLocalHost.data());
    }

    if (resolver.Get(sLocalHost, g_InputArg.sub_net))
        printf("use ip = %s\n", sLocalHost.data());
    else
    {
        printf("FAIL subnet = %u\n", g_InputArg.sub_net);
        return -1;
    }


    // обязательно инициализировать лог
    GetLogger()->Register("TestTransport");
    GetLogger()->Init("TestTransport");
    GetLogger()->SetPrintf(false);

    TMakerNetTransport makerTransport;
    g_pServerTransport = makerTransport.New();

    g_pServerTransport->GetCallbackRecv()->Register(&g_Handler, &THandler::Recv);
    g_pServerTransport->GetCallbackDisconnect()->Register(&g_Handler, &THandler::Disconnect);
    g_pServerTransport->GetCallbackConnectFrom()->Register(&g_Handler, &THandler::ConnectFrom);

    g_pServerTransport->Open(g_ServerPort, g_InputArg.sub_net);
    g_pServerTransport->Start();

    while (true)
    {
        HandleConnect();
        HandleDisconnect();
        if (g_isTesting)
            Test();
        else
            ht_msleep(100);
        HandleRecv();
    }
    return 0;
}
//-----------------------------------------------------------------------
