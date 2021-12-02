/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/OnAddCollectReactiveSystem.h>
#include "NeedDestroySceneComponent.h"

namespace nsLogicWrapper
{
    class DllExport TNeedDestroySceneSystem :
        public nsECSFramework::TOnAddCollectReactiveSystem<nsCommonWrapper::TNeedDestroySceneComponent, TNeedDestroySceneSystem>
    {
    public:
        // Search all entities with sceneGuid and destroy'em all
        void Reactive(nsECSFramework::TEntityID eid, const nsCommonWrapper::TNeedDestroySceneComponent* pC);
    };
}