/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "IScenario.h"
#include "DescRecvSession.h"
#include "BaseScRecommutationClient_Struct.h"
#include "Base/Common/DescCallBack.h"
#include "Base/Common/MapCallBack.h"

namespace nsMMOEngine
{
    class  TContextScRecommutationClient;
    struct TDescRequestConnectForRecipient;
    class TBaseScRecommutationClient
    {
    protected:
        IScenario* mScenario;

        TBreakPacket mBP;
    public:
        TBaseScRecommutationClient(IScenario* pSc);
        virtual ~TBaseScRecommutationClient();

        void Recv(TDescRecvSession* pDesc);
        virtual void Work(unsigned int time_ms) = 0;

    protected:
        TContextScRecommutationClient* Context();
        void SetContext(TContextScRecommutationClient* pContext);

        unsigned int GetID_SessionClientSlave();
        void SetID_SessionClientSlave(unsigned int id);
        unsigned int GetID_SessionMasterSlave();
        void SetID_SessionMasterSlave(unsigned int id);
    protected:
        virtual void RecvInherit(TDescRecvSession* pDesc) = 0;
    protected:
        void SetTimeWaitForNow();
    protected:
        // от Scenario
        bool Begin();
        void End();
    protected:
        void NeedContextByClientKey(unsigned int key);
        void NeedContextByClientSessionForSlave(unsigned int sessionID, bool donor);
        void NeedContextByClientKeyForSlave(unsigned int key, bool donor);
        void NeedSessionDonorByClientKey(IScenario* pScenario);
        void EventActivate();
        void EventDisconnectClient(unsigned int key);
        void EventTimeClientElapsed(unsigned int key);// вышло время ожидания ответа от Клиента на Slave

        void NeedContextByRequestForRecipient(TDescRequestConnectForRecipient* pDesc);
    };
}
