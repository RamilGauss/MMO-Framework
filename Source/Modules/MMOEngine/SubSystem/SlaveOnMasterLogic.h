/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "MMOEngine/SubSystem/BaseMasterLogic.h"

namespace nsMMOEngine
{
    class IScenario;
    class TSlaveOnMasterLogic : public TBaseMasterLogic
    {
    public:
        TSlaveOnMasterLogic(TBase* p);

        void GetDescDown(std::list<unsigned int>& sessionIDList);

        void EndLoginSlave(IScenario* pSc);
        void SendDown(unsigned int sessionID, char* p, int size, bool check);

        void NeedContextLoginSlave(unsigned int sessionID);
        void NeedContextSynchroSlave(unsigned int sessionID);
        void EndSynchroSlave(IScenario* pSc);

        bool DisconnectSlave(unsigned int sessionID);

    private:
        void TryAddClientFromQueue(nsECSFramework::TEntityID slaveEntity);

        void DestroyAllLostClientsBySlaveSession(unsigned int sessionID);

        void GetAllClientsBySlaveSession(unsigned int sessionID, std::vector<unsigned int>& clientKeyVector);
        void SendSuperServer(std::vector<unsigned int>& clientKeyVector);
        void SendRecipient(unsigned int sessionID);

        void DestroyAllClientsBySlaveSession(unsigned int sessionID);
        void DestroyAllGroupsBySlaveSession(unsigned int sessionID);

        void TryAddFromQueueGroupClients(nsECSFramework::TEntityID slaveEntity, unsigned int sessionID);
        void TryAddFromQueue(nsECSFramework::TEntityID slaveEntity, unsigned int sessionID);

        void AddClientBySlave(nsECSFramework::TEntityList* pClientEntitySet,
            unsigned int slaveSessionID, nsECSFramework::TEntityID slaveEntity, float limit);

        void AddClientBySlaveSession(nsECSFramework::TEntityID clientEntity, unsigned int slaveSessionID);
    };
}
