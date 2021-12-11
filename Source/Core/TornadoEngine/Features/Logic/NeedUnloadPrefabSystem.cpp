/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "NeedUnloadPrefabSystem.h"

#include "PrefabGuidComponent.h"

using namespace nsLogicWrapper;

void TNeedUnloadPrefabSystem::Reactive(nsECSFramework::TEntityID eid, const nsCommonWrapper::TNeedUnloadPrefabComponent* pNeedUnloadPrefabComponent)
{
    nsCommonWrapper::TPrefabGuidComponent prefabGuidComponent;

    prefabGuidComponent.value = pNeedUnloadPrefabComponent->prefabGuid;

    auto prefabGuidList = GetEntMng()->GetByValueCopy(prefabGuidComponent);
    for (auto& prefabEid : prefabGuidList) {
        GetEntMng()->DestroyEntity(prefabEid);
    }

    GetEntMng()->DestroyEntity(eid);
}
