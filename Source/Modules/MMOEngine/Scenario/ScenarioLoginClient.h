/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "IScenario.h"
#include "ContextScLoginClient.h"
#include "MakerScenario.h"
#include "Base/Common/ShareMisc.h"
#include "Base/Common/CallBackRegistrator.h"

#include "ScLoginClient_ClientImpl.h"
#include "ScLoginClient_MasterImpl.h"
#include "ScLoginClient_SlaveImpl.h"
#include "ScLoginClient_SuperServerImpl.h"

namespace nsMMOEngine
{
    class TScenarioLoginClient : public IScenario
    {
        // выдать контекст по сессии Мастера и ключу Клиента
        TCallBackRegistrator2<unsigned int, unsigned int> mCBContextByMasterSessionByClientKey;
        // запрос к мастеру о номере клиента в очереди
        TCallBackRegistrator1<unsigned int>              mCBNumInQueueByClientKey;
        // уведомить о назначении клиенту ключа Мастером
        TCallBackRegistrator1<unsigned int>              mCBSetClientKey;
        // запрос на контекст по сессии и ключу клиента
        TCallBackRegistrator2<unsigned int, unsigned int> mCBContextByClientSessionByClientKey;
        // запрос на контекст по сессии клиента после авторизации
        TCallBackRegistrator1<unsigned int>              mCBContextByClientSessionAfterAuthorised;
        // запрос на контекст по сессии клиента при желании выхода из очереди на ожидание авторизации
        TCallBackRegistrator1<unsigned int>              mCBContextByClientSessionLeaveQueue;
        // запрос на контекст по ключу клиента от Slave
        TCallBackRegistrator1<unsigned int>              mCBContextByClientKey_SecondCallSlave;

        TScLoginClient_ClientImpl      mClient;
        TScLoginClient_SlaveImpl       mSlave;
        TScLoginClient_MasterImpl      mMaster;
        TScLoginClient_SuperServerImpl mSS;

        TBaseScLoginClient* mCurBehavior;

    public:
        enum eTypeCallBack
        {
            eContextByMasterSessionByClientKey = IScenario::eCountCallBack,
            eNumInQueueByClientKey,
            eSetClientKey,
            eContextByClientSessionByClientKey,
            eContextByClientSessionAfterAuthorised,
            eContextByClientSessionLeaveQueue,
            eContextByClientKey_SecondCallSlave,
            eCountCallBack,
        };
    public:
        enum eBehavior
        {
            eClient,
            eSlave,
            eMaster,
            eSuperServer,
        };

        TScenarioLoginClient();
        virtual ~TScenarioLoginClient();

        void SetBehavior(eBehavior v);
        virtual void Recv(TDescRecvSession* pDesc);
    public:
        // от клиента, попытка авторизации
        void TryLogin(TIP_Port& ip_port, const std::string& login, const std::string& password, unsigned char subNet);

        void LeaveQueue();
        // решение Мастера
        void Reject(void* resForClient, int sizeResClient);
        void Accept(unsigned int key, void* resForClient, int sizeResClient,
            unsigned int id_session_slave, unsigned int id_superserver);
        void Queue(int num, void* resForClient, int sizeResClient);

        void DisconnectFromMaster();
        void DisconnectFromClient();

        void SetFakeClient(bool val);
    protected:
        virtual void Work();
    };
}
