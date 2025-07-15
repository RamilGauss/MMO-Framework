/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "MMOEngine/Include/EnumMMO.h"
#include "MMOEngine/SubSystem/BaseMasterLogic.h"

namespace nsMMOEngine
{
    class TContextScRecommutationClient;
    class TGroupLogic : public TBaseMasterLogic
    {
    public:
        TGroupLogic(TBase* p);

        bool TryCreateGroup(std::list<unsigned int>& clientKeyList, unsigned int& groupID);
        void DestroyGroup(unsigned int groupID);
        void LeaveGroup(unsigned int clientKey);
        void GetListForGroup(unsigned int groupID, std::list<unsigned int>& clientKeyList);

        bool FindSlaveSessionByGroup(unsigned int groupID, unsigned int& sessionID);

    private:
        bool EvalCreateGroupNow(std::list<unsigned int>& clientKeyList, unsigned int& groupID);

        void CalculateLoadMap(std::map<int, nsECSFramework::TEntityID>& loadSlaveEntityMap);

        int CalculateClientCountNotOnSlave(unsigned int slaveSession, std::list<unsigned int>& clientKeyList);

        unsigned int CreateGroup(unsigned int slaveSession, std::list<unsigned int>& clientKeyList);

        void AddClientsInGroup(unsigned int groupID, std::list<unsigned int>& clientKeyList);

        void ExchangeClients(unsigned int slaveSession, std::list<unsigned int>& clientKeyList,
            std::list<nsECSFramework::TEntityID>& clientEntityWithoutGroupList);

        void StartRcm(nsECSFramework::TEntityID clientEntity, unsigned int slaveSession);
        void RcmByClientKeyContextSlaveSessionRecipient(unsigned int clientKey,
            TContextScRecommutationClient* pCRCM, unsigned int recipientSessionID);
    };
}
