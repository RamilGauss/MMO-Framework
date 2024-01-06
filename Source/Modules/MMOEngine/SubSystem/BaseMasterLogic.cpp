/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "BaseMasterLogic.h"
#include "Master.h"
#include "ECS/include/EntityManager.h"
#include "Events.h"
#include "Base/Common/Logger.h"
#include "Components.h"

using namespace nsMMOEngine;
using namespace nsECSFramework;

// Components RoadMap
// Client:
/*
  TContextContainerComponent      C
  TClientIdentityComponent        U
  TClientSessionIdentityComponent U
  TClientStateComponent           G, M
  TGroupIDComponent               M      Join to State
  TSlaveSessionByClientComponent  M      Join to State
  TDonorSessionComponent          M      only for RCM state
*/
// Slave
/*
  TContextContainerComponent     C
  TSlaveSessionIdentityComponent U
  TSlaveLoadInfoComponent        С
*/
// Group
/*
  TGroupIdentityComponent       U
  TSlaveSessionByGroupComponent M
*/


TBaseMasterLogic::TBaseMasterLogic(TBase* p) : TBaseLogic(p)
{
    mSetClientKeyInQueue.reset(new TSetOrderElement());
    mEntMng->RegisterOnRemoveComponent<TContextContainerComponent>()->Register(this, &TBaseMasterLogic::OnRemoveContextContainer);
}
//-----------------------------------------------------------------------------------
void TBaseMasterLogic::OnRemoveContextContainer(TEntityID entity, const IComponent* pC)
{
    auto pContextContainerComponent = (const TContextContainerComponent*)pC;
    DeleteContainer(pContextContainerComponent->v);
}
//-----------------------------------------------------------------------------------
float TBaseMasterLogic::CalculateFutureLoadOnSlave(TEntityID slaveEntity, int addedClientCount)
{
    auto load = mEntMng->ViewComponent<TSlaveLoadInfoComponent>(slaveEntity)->v;

    TSlaveSessionByClientComponent slaveSessionByClientComponent;
    slaveSessionByClientComponent.v = mEntMng->ViewComponent<TSlaveSessionIdentityComponent>(slaveEntity)->v;

    TClientStateComponent clientStateComponent;
    clientStateComponent.v = TClientStateComponent::OnSlave;

    auto onSlaves = mEntMng->GetByValueCopy(slaveSessionByClientComponent, clientStateComponent);
    int onSlaveCount = 1;

    if (onSlaves.size() == 0) {
        load = DefaultLoadPerClientIfClientCountZero;
    } else {
        onSlaveCount = onSlaves.size();
    }

    clientStateComponent.v = TClientStateComponent::RCM;
    // все, для кого мы - реципиент
    int rcmCount = 0;
    auto rcmClients = mEntMng->GetByValueCopy(slaveSessionByClientComponent, clientStateComponent);
    rcmCount = rcmClients.size();

    clientStateComponent.v = TClientStateComponent::Logining;

    int loginingCount = 0;
    auto loginingClients = mEntMng->GetByValueCopy(slaveSessionByClientComponent, clientStateComponent);
    loginingCount = loginingClients.size();

    auto futureLoad = (load * (onSlaveCount + rcmCount + loginingCount + addedClientCount)) / onSlaveCount;
    return futureLoad;
}
//-----------------------------------------------------------------------------------
void TBaseMasterLogic::GetClientWithoutGroup(unsigned int slaveSession,
    std::list<TEntityID>& clientEntityList)
{
    clientEntityList.clear();

    TSlaveSessionByClientComponent slaveSessionByClientComponent;
    slaveSessionByClientComponent.v = slaveSession;
    TClientStateComponent clientStateComponent;
    clientStateComponent.v = TClientStateComponent::OnSlave;
    auto clientOnSlaves = mEntMng->GetByValueCopy(slaveSessionByClientComponent, clientStateComponent);
    for (auto& clientEntity : clientOnSlaves) {
        if (mEntMng->ViewComponent<TGroupIDComponent>(clientEntity)->v != 0)
            continue;
        // не в группе
        clientEntityList.push_back(clientEntity);
    }
}
//-----------------------------------------------------------------------------------
void TBaseMasterLogic::AddError(nsMMOEngine::ErrorCode err)
{
    TErrorEvent event;
    event.code = err;
    mBase->AddEventCopy(&event, sizeof(event));
}
//-------------------------------------------------------------------------------------------
bool TBaseMasterLogic::FindMinimumLoad(unsigned int& slaveSessionID, unsigned char& load_procent)
{
    auto slaves = mEntMng->GetByHasCopy<TSlaveSessionIdentityComponent>();
    if (slaves.size() == 0) {
        return false;
    }

    load_procent = 101;
    for (auto slaveEntity : slaves) {
        auto load = mEntMng->ViewComponent<TSlaveLoadInfoComponent>(slaveEntity)->v;
        if (load < load_procent) {
            load_procent = (unsigned char)load;
            slaveSessionID = mEntMng->ViewComponent<TSlaveSessionIdentityComponent>(slaveEntity)->v;
        }
    }
    return true;
}
//-------------------------------------------------------------------------
unsigned char TBaseMasterLogic::GetLimitLoadProcentByKey(unsigned int clientKey)
{
    TClientIdentityComponent clientIdentity;
    clientIdentity.v = clientKey;
    auto clientEntity = mEntMng->GetByUnique(clientIdentity);
    if (clientEntity == nsECSFramework::NONE) {
        // генерация ошибки
        nsBase::nsCommon::GetLogger(STR_NAME_MMO_ENGINE)->
            WriteF_time("GetLimitLoadProcentByKey() not found client.\n");
        BL_FIX_BUG();
    }

    auto groupId = mEntMng->ViewComponent<TGroupIDComponent>(clientEntity)->v;

    auto InGroup = groupId != 0;
    return GetLimitLoadProcent(InGroup);
}
//-------------------------------------------------------------------------
unsigned char TBaseMasterLogic::GetLimitLoadProcent(bool InGroupOrSimple)
{
    // Решение проблемы: если клиент состоит в группе и у него произошел
    // дисконнект, то он должен войти в систему по запросу в любом случае,
    // т.е. его приоритет выше чем у других клиентов
    return InGroupOrSimple ?
        LimitLoadProcentOnSlaveForAdd_ClientInGroup :
        LimitLoadProcentOnSlaveForAdd;
}
//-------------------------------------------------------------------------