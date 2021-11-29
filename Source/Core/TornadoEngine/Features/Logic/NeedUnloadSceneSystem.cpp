/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "NeedUnloadSceneSystem.h"

#include "SceneGuidComponent.h"

using namespace nsLogicWrapper;

void TNeedUnloadSceneSystem::Reactive(nsECSFramework::TEntityID eid, nsECSFramework::IComponent* pC)
{
    nsCommonWrapper::TSceneGuidComponent sceneGuidComponent;

    auto pNeedUnloadSceneComponent = (nsCommonWrapper::TNeedUnloadSceneComponent*)pC;
    sceneGuidComponent.value = pNeedUnloadSceneComponent->sceneGuid;

    auto pSceneGuidList = GetEntMng()->GetByValue(sceneGuidComponent);
    if (pSceneGuidList == nullptr) {
        return;
    }

    auto sceneGuidList = *pSceneGuidList;
    for (auto& sceneEid : sceneGuidList) {
        GetEntMng()->DestroyEntity(sceneEid);
    }
}
