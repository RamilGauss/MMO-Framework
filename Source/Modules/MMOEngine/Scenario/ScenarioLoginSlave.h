/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "IScenario.h"
#include "ContextScLoginSlave.h"
#include "MakerScenario.h"
#include "ScenarioBaseHeader.h"

#pragma pack(push, 1)

namespace nsMMOEngine
{
    class TScenarioLoginSlave : public IScenario
    {
        enum { eFromSlave, eAnswerMaster, };
        struct THeaderLoginSlave : public TScenarioBaseHeader
        {
            THeaderLoginSlave() { type = TMakerScenario::eLoginSlave; }
        };
        //-------------------------------------------------
        struct THeaderFromSlave : public THeaderLoginSlave
        {
            THeaderFromSlave() { subType = eFromSlave; }
        };
        //-------------------------------------------------
        struct THeaderAnswerMaster : public THeaderLoginSlave
        {
            THeaderAnswerMaster() { subType = eAnswerMaster; }
        };
        //-------------------------------------------------
        enum
        {
            eTimeoutWait_ms = 20000,
        };

    public:
        TScenarioLoginSlave();

        virtual void Recv(TDescRecvSession* pDesc);

        void ConnectToMaster(TIP_Port& ip_port, std::string& login, std::string& password, unsigned char subNet);
    protected:
        virtual void Work();

        void RecvFromMaster(TDescRecvSession* pDesc);
        void RecvFromSlave(TDescRecvSession* pDesc);
    private:
        TContextScLoginSlave* Context() { return (TContextScLoginSlave*) mCurContext; }

        void ConnectToMasterAfterConnect(int sessionID);
    };
}

#pragma pack(pop)
