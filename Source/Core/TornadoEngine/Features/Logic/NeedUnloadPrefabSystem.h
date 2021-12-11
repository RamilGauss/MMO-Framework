/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/OnAddCollectReactiveSystem.h>
#include "NeedUnloadPrefabComponent.h"

namespace nsLogicWrapper
{
    class DllExport TNeedUnloadPrefabSystem : 
        public nsECSFramework::TOnAddCollectReactiveSystem<nsCommonWrapper::TNeedUnloadPrefabComponent, TNeedUnloadPrefabSystem>
    {
    public:
        // Search all entities with sceneGuid and destroy'em all
        void Reactive(nsECSFramework::TEntityID eid, const nsCommonWrapper::TNeedUnloadPrefabComponent* pC);
    };
}