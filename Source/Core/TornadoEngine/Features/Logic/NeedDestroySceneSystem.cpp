/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "NeedDestroySceneSystem.h"

#include "SceneInstanceGuidComponent.h"

using namespace nsLogicWrapper;

void TNeedDestroySceneSystem::Reactive(nsECSFramework::TEntityID eid, 
    const nsCommonWrapper::TNeedDestroySceneComponent* pNeedDestroySceneComponent)
{
    nsCommonWrapper::TSceneInstanceGuidComponent sceneInstanceGuidComponent;

    sceneInstanceGuidComponent.value = pNeedDestroySceneComponent->sceneInstanceGuid;

    auto sceneInstanceGuidList = GetEntMng()->GetByValueCopy(sceneInstanceGuidComponent);
    for (auto& sceneEid : sceneInstanceGuidList) {
        GetEntMng()->DestroyEntity(sceneEid);
    }

    GetEntMng()->DestroyEntity(eid);
}
