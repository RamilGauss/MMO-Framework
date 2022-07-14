/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <vector>

#include "IScenario.h"
#include "ContextScDisconnectClient.h"
#include "MakerScenario.h"
#include "CallBackRegistrator.h"
#include "ScenarioBaseHeader.h"

#pragma pack(push, 1)

namespace nsMMOEngine
{
    class TScenarioDisconnectClient : public IScenario
    {
        enum
        {
            eFromMaster,
            eFromSlave,
        };

        struct THeaderDisconnectClient : public TScenarioBaseHeader
        {
            THeaderDisconnectClient() { type = TMakerScenario::eDisconnectClient; }
        };
        //-------------------------------------------------
        struct THeaderFromMaster : public THeaderDisconnectClient
        {
            THeaderFromMaster() { subType = eFromMaster; }
            int countID;// далее массив unsigned int
        };
        //-------------------------------------------------
        struct THeaderFromSlave : public THeaderDisconnectClient
        {
            THeaderFromSlave() { subType = eFromSlave; }
            unsigned int clientKey;
        };
        //-------------------------------------------------
    public:
        TScenarioDisconnectClient();

        virtual void Recv(TDescRecvSession* pDesc);

        void DisconnectFromSlave(unsigned int clientKey);
        void DisconnectFromMaster(std::vector<unsigned int>& vecID_client);

    protected:
        virtual void Work();
    private:
        void RecvFromMaster(TDescRecvSession* pDesc);
        void RecvFromSlave(TDescRecvSession* pDesc);

    private:
        TContextScDisconnectClient* Context() { return (TContextScDisconnectClient*)mCurContext; }
    };
}

#pragma pack(pop)
