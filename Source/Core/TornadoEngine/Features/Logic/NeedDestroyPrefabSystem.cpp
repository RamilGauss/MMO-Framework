/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "NeedDestroyPrefabSystem.h"

#include "PrefabInstanceGuidComponent.h"

using namespace nsLogicWrapper;

void TNeedDestroyPrefabSystem::Reactive(nsECSFramework::TEntityID eid,
    const nsCommonWrapper::TNeedDestroyPrefabComponent* pNeedDestroyPrefabComponent)
{
    nsCommonWrapper::TPrefabInstanceGuidComponent prefabInstanceGuidComponent;

    prefabInstanceGuidComponent.value = pNeedDestroyPrefabComponent->prefabInstanceGuid;

    auto prefabInstanceGuidList = GetEntMng()->GetByValueCopy(prefabInstanceGuidComponent);
    for (auto& prefabEid : prefabInstanceGuidList) {
        GetEntMng()->DestroyEntity(prefabEid);
    }

    GetEntMng()->DestroyEntity(eid);
}
