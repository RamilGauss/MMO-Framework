/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "IScenario.h"
#include "ContextScSynchroSlave.h"
#include "MakerScenario.h"
#include "ScenarioBaseHeader.h"

#pragma pack(push, 1)

namespace nsMMOEngine
{
    class TScenarioSynchroSlave : public IScenario
    {
        enum { eFromSlave, };
        struct THeaderSynchroSlave : public TScenarioBaseHeader
        {
            float loadProcent;
            THeaderSynchroSlave() { type = TMakerScenario::eSynchroSlave; subType = eFromSlave; }
        };
        //-------------------------------------------------
    public:
        TScenarioSynchroSlave();
        virtual ~TScenarioSynchroSlave();
        virtual void Recv(TDescRecvSession* pDesc);

        void SendSynchro(float loadProcent);
    protected:
        void RecvFromSlave(TDescRecvSession* pDesc);

        TContextScSynchroSlave* Context() { return (TContextScSynchroSlave*) mCurContext; }
    };
}

#pragma pack(pop)
