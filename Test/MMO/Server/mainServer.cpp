/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <boost/asio/ip/impl/address_v4.ipp>
#include <string>
#include <iostream>
#include <stdio.h>
#include <thread>
#include <format>

#include "Base/Common/BL_Debug.h"
#include "CommonParam.h"
#include "NetTransport/MakerNetTransport.h"
#include "MMOEngine/include/Slave.h"
#include "MMOEngine/include/Master.h"
#include "MMOEngine/include/SuperServer.h"
#include "Base/Common/HiTimer.h"
#include "Base/Common/ResolverSelf_IP_v4.h"
#include "Base/Common/GlobalEventHub.h"

#include "HandlerMMO_Slave.h"
#include "HandlerMMO_Master.h"
#include "HandlerMMO_SuperServer.h"
#include "Base/Common/ReversedContainerRise.h"
#include "InputCmdTestMMO_Server.h"
#include "ClusterMonitorServerHandler.h"
#include "Base/Common/SrcEvent_ex.h"

#define COUNT_SLAVE 3

void StartServer(int argc, char** argv);

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");

#ifdef WIN32
    std::string title = "Title Server ";
    for (int i = 1; i < argc; i++) {
        char s[1000];
        sprintf(s, "%s ", argv[i]);
        title += s;
    }
    system(title.data());
#endif
#ifdef _DEBUG
    StartServer(argc, argv);
#else
    try {
        StartServer(argc, argv);
    } catch (std::exception& e) {
        printf("exception!!! %s\n", e.what());
        getchar();
    }
#endif
    return 0;
}

void StartServer(int argc, char** argv)
{
    TInputCmdTestMMO_Server cmi;
    cmi.Init();
    cmi.SetArg(argc, argv);

    // обязательно инициализировать лог
    std::string sLocalHost;
    TResolverSelf_IP_v4 resolver;

    //InitLogger(ServerLog);
    {
        int countIP_v4 = resolver.GetCount();
        nsBase::nsCommon::GetEventHub()->
            AddWarningEvent("ip count = {}", countIP_v4);
        for (int i = 0; i < countIP_v4; i++) {
            if (resolver.Get(sLocalHost, i) == false) {
                continue;
            }
            nsBase::nsCommon::GetEventHub()->
                AddWarningEvent("ip = {}", sLocalHost);
        }
    }

    if (resolver.Get(sLocalHost, cmi.mInput.subnet)) {
        nsBase::nsCommon::GetEventHub()->
            AddWarningEvent("use ip = {}", sLocalHost);
    } else {
        nsBase::nsCommon::GetEventHub()->
            AddWarningEvent("FAIL subnet = {}", cmi.mInput.subnet);
        return;
    }

    std::vector<THandlerMMO_Slave*> arrHandlerSlave;

    TMakerNetTransport makerTransport;

    nsMMOEngine::TDescOpen descOpen;
    descOpen.subNet = cmi.mInput.subnet;
    typedef std::shared_ptr<nsMMOEngine::TSlave> TShared_Ptr_Slave;
    std::vector<TShared_Ptr_Slave> arrSlave;
    for (int i = 0; i < COUNT_SLAVE; i++) {
        TShared_Ptr_Slave pSlave = TShared_Ptr_Slave(new nsMMOEngine::TSlave);
        THandlerMMO_Slave* pHandlerSlave = new THandlerMMO_Slave(pSlave.get());
        pSlave->Init(&makerTransport);
        descOpen.port = SLAVE_PORT + i;
        pSlave->Open(&descOpen);
        pSlave->SetLoad(0);// всегда в начале нет нагрузки
        pSlave->SetDstObject(pHandlerSlave);
        pSlave->SetSelfID(descOpen.port);
        arrSlave.push_back(pSlave);
        arrHandlerSlave.push_back(pHandlerSlave);
    }

    std::shared_ptr<nsMMOEngine::TMaster>      pMaster(new nsMMOEngine::TMaster);
    std::shared_ptr<nsMMOEngine::TSuperServer> pSuperServer(new nsMMOEngine::TSuperServer);
    std::shared_ptr<THandlerMMO>               handlerMaster(new THandlerMMO_Master(pMaster.get()));
    std::shared_ptr<THandlerMMO>               handlerSuperServer(new THandlerMMO_SuperServer(pSuperServer.get()));

    TClusterMonitorServerHandler cmsTransport(cmi.mInput.subnet, pMaster.get());

    descOpen.port = MASTER_PORT;
    pMaster->Init(&makerTransport);
    pMaster->Open(&descOpen);
    pMaster->SetDstObject(handlerMaster.get());
    pMaster->SetSelfID(descOpen.port);

    descOpen.port = SUPER_SERVER_PORT;
    pSuperServer->Init(&makerTransport);
    pSuperServer->Open(&descOpen);
    pSuperServer->SetDstObject(handlerSuperServer.get());
    pSuperServer->SetSelfID(descOpen.port);

    // сначала мастер цепляется к суперсерверу,
    // потом slave-ы
    TIP_Port ssIP_Port;
    ssIP_Port.ip = boost::asio::ip::address_v4::from_string(sLocalHost).to_ulong();
    ssIP_Port.port = SUPER_SERVER_PORT;
    std::string login = MASTER_LOGIN;
    std::string password = MASTER_PASSWORD;
    pMaster->ConnectUp(ssIP_Port, login, password, cmi.mInput.subnet);
    TIP_Port masterIP_Port;
    masterIP_Port.ip = boost::asio::ip::address_v4::from_string(sLocalHost).to_ulong();
    masterIP_Port.port = MASTER_PORT;
    password = SLAVE_PASSWORD;
    for (int i = 0; i < COUNT_SLAVE; i++) {
        char sLogin[100];
        sprintf(sLogin, "%d", i);
        login = SLAVE_LOGIN;// sLogin;
        arrSlave[i]->ConnectUp(masterIP_Port, login, password, cmi.mInput.subnet);
    }

    const unsigned int printInterval = 6000;
    auto printTime = ht_GetMSCount() + printInterval;

    unsigned int start = 0;
    unsigned int limitDeltaTime = 6000;// ms
    int iCycle = 0;

    while (true) {
        auto now = ht_GetMSCount();

        if (iCycle == 0) {// начало расчета скорости работы
            start = now;
        }

        if (printTime < now) {
            //THandlerMMO::PrintCC(ServerLog);
            printTime = now + printInterval;
        }

        // Work - реакции мастера и суперсервера
        pSuperServer->Work();
        pMaster->Work();
        for (auto pSlave : arrSlave) {
            pSlave->Work();
        }
        // Handle
        handlerMaster->Work();
        handlerSuperServer->Work();
        for (auto pHandlerSlave : arrHandlerSlave)
            pHandlerSlave->Work();

        cmsTransport.Work();

        iCycle++;
        auto delta = ht_GetMSCount() - start;
        if (delta >= limitDeltaTime) {
            auto speed_ms = delta * 1.0f / iCycle;
            nsBase::nsCommon::GetEventHub()->
                AddWarningEvent("time of cycle = {} ms", speed_ms);
            iCycle = 0;
        }
    }
}
//-----------------------------------------------------------------------
