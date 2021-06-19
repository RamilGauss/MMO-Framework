/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "SetOrderElement.h"
#include "ECS/include/EntityManager.h"
#include "BaseLogic.h"
#include "EnumMMO.h"

namespace nsMMOEngine
{
    class TBase;
    class TBaseMasterLogic : public TBaseLogic
    {
    protected:
        // если на Slave нет клиентов, то считать нагрузку на одного клиента равным этому значению
        const float DefaultLoadPerClientIfClientCountZero = 1.0f;

        const float LimitLoadPercentOnSlaveForAdd = 70.0f;
        // для Клиента, состоящего в Группе процент другой
        const float LimitLoadPercentOnSlaveForAdd_ClientInGroup = 75.0f;
        // максимальный размер очереди ожидающих
        const int LimitCountClientWaitFreeSpace = 10000;

        const unsigned char LimitLoadProcentOnSlaveForAdd = 70;
        const unsigned char LimitLoadProcentOnSlaveForAdd_ClientInGroup = 75; // для Клиента, состоящего в Группе процент другой

        // ID клиентов, которые ожидают в очереди, по причине загруженности Slave
        std::shared_ptr<TSetOrderElement> mSetClientKeyInQueue;

    public:
        TBaseMasterLogic(TBase* p);
    protected:

        void AddError(nsMMOEngine::ErrorCode err);

        void OnRemoveContextContainer(nsECSFramework::TEntityID entity, nsECSFramework::IComponent* pC);

        float CalculateFutureLoadOnSlave(nsECSFramework::TEntityID slaveEntity, int addedClientCount);

        void GetClientWithoutGroup(unsigned int slaveSession,
            std::list<nsECSFramework::TEntityID>& clientEntityList);

        bool FindMinimumLoad(unsigned int& slaveSessionID, unsigned char& load_procent);
        unsigned char GetLimitLoadProcentByKey(unsigned int clientKey);

        unsigned char GetLimitLoadProcent(bool InGroupOrSimple);
    };
}
