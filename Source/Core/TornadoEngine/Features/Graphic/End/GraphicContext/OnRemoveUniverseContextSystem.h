/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ECS/Include/OnRemoveInstantReactiveSystem.h"

#include "TornadoEngine/Components/Meta/UniverseIndexComponent.h"

namespace nsGraphicWrapper
{
    class DllExport TOnRemoveUniverseContextSystem :
        public nsECSFramework::TOnRemoveInstantReactiveSystem<nsCommonWrapper::TUniverseIndexComponent, TOnRemoveUniverseContextSystem>
    {
    public:
        void Reactive(nsECSFramework::TEntityID eid, const nsCommonWrapper::TUniverseIndexComponent* pC);
    };
}
