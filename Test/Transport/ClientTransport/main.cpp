/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <errno.h>
#include <iostream>

#include <boost/asio/ip/impl/address_v4.ipp>
#include "Base/Common/BL_Debug.h"
#include <string.h>
#include "InputCmdClientTransport.h"
#include "Base/Common/HiTimer.h"
#include "Base/Common/ResolverSelf_IP_v4.h"
#include "Base/Common/Logger.h"
#include "Base/Common/ShareMisc.h"
#include "NetTransport/MakerNetTransport.h"
#include "MMOEngine/include/INetTransport.h"
#include "Base/Common/DataExchange2Thread.h"

#include "Packets.h"

std::list<nsMMOEngine::INetTransport*> g_pClientTransportList;
TInputCmdClientTransport::TInput g_InputArg;
unsigned int g_Server_ip;
TBreakPacket g_BP;

nsMMOEngine::INetTransport* GetFirstTransport()
{
    if (g_pClientTransportList.size() == 0)
        return nullptr;
    auto bit = g_pClientTransportList.begin();
    return *bit;
}
//---------------------------------------------------------------------------------
void Send(void* p, int size)
{
    g_BP.Reset();
    g_BP.PushBack((char*)p, size);

    GetFirstTransport()->Send(g_Server_ip, g_InputArg.server_port, g_BP);
}
//---------------------------------------------------------------------------------
struct TArgumentDesc
{
    std::string cmd;
    std::string desc;
    std::function<void()> func;
};
//---------------------------------------------------------------------------------
void ShowHelp();
//---------------------------------------------------------------------------------
TArgumentDesc g_Arguments[] =
{
  { "start", "start testing", []()
    {
      TStartPacket packet;
      Send(&packet, sizeof(packet));
    }
  },
  { "stop", "stop testing", []()
    {
      TStopPacket packet;
      Send(&packet, sizeof(packet));
    }
  },
  { "get", "get test results", []()
    {
      TGetPacket packet;
      Send(&packet, sizeof(packet));
    }
  },
  { "help", "show this help info", []()
    {
      ShowHelp();
    }
  },
  { "exit", "exit from the application", []()
    {
      _exit(0);
    }
  },
};
//---------------------------------------------------------------------------------
void ShowHelp()
{
    printf("Commands:\n");
    for (auto& arg : g_Arguments) {
        printf("\t%s -> %s\n", arg.cmd.data(), arg.desc.data());
    }
}
//---------------------------------------------------------------------------------
bool TryDo(std::string& cmd)
{
    for (auto& arg : g_Arguments) {
        if (arg.cmd == cmd) {
            arg.func();
            return true;
        }
    }
    return false;
}
//---------------------------------------------------------------------------------
struct TInfoDisplay
{
    void Recv(nsMMOEngine::INetTransport::TDescRecv* p)
    {
        auto pPacket = (TBasePacket*)p->data;
        if (pPacket->type != TBasePacket::eInfo)
            return;
        auto pInfo = (TInfoPacket*)pPacket;
        printf("info: timerPerSend = %f us\n", pInfo->timerPerSend);
    }
};
//---------------------------------------------------------------------------------
int main(int argc, char** argv)
{
    ShowHelp();

    TInputCmdClientTransport inputCmd;
    bool res = inputCmd.SetArg(argc, argv);
    BL_ASSERT(res);

    inputCmd.Get(g_InputArg);

    GetLogger()->Register("TestTransport");
    GetLogger()->Init("TestTransport");
    GetLogger()->SetPrintf(false);

    TMakerNetTransport makerTransport;

    // обязательно инициализировать лог
    std::string sLocalHost;
    TResolverSelf_IP_v4 resolver;
    resolver.Get(sLocalHost, g_InputArg.sub_net);
    g_Server_ip = boost::asio::ip::address_v4::from_string(g_InputArg.server_ip).to_ulong();

    TInfoDisplay infoDisplay;
    for (int i = 0; i < g_InputArg.client_count; i++) {
        auto pClient = makerTransport.New();

        auto port = 40000 + i;
        pClient->Open(port, g_InputArg.sub_net);
        pClient->Start();

        pClient->GetCallbackRecv()->Register(&infoDisplay, &TInfoDisplay::Recv);

        bool resConnect = pClient->Connect(g_Server_ip, g_InputArg.server_port);
        if (resConnect == false)
            printf("Connect fails port = %u\n", port);

        g_pClientTransportList.push_back(pClient);
    }

    printf("Please, enter cmd:\n");
    while (true) {
        std::string cmd;
        std::getline(std::cin, cmd);
        if (!TryDo(cmd)) {
            printf("Wrong command.\n");
        }
    }

    return 0;
}
//-----------------------------------------------------------------------
