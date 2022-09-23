/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/OnAddCollectReactiveSystem.h>

#include "UniverseIndexComponent.h"

namespace nsGraphicWrapper
{
    class DllExport TOnAddUniverseContextSystem :
        public nsECSFramework::TOnAddCollectReactiveSystem<nsCommonWrapper::TUniverseIndexComponent, TOnAddUniverseContextSystem>
    {
    public:
        void Reactive(nsECSFramework::TEntityID eid, const nsCommonWrapper::TUniverseIndexComponent* pC);
    };
}