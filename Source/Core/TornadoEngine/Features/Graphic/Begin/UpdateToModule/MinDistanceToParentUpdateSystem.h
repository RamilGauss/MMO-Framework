/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/OnUpdateCollectReactiveSystem.h>

#include "MinDistanceToParentComponent.h"

namespace nsGraphicWrapper
{
    class DllExport TMinDistanceToParentUpdateSystem :
        public nsECSFramework::TOnUpdateCollectReactiveSystem<nsGuiWrapper::TMinDistanceToParentComponent, TMinDistanceToParentUpdateSystem>
    {
    public:
        void Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TMinDistanceToParentComponent* pC);
    };
}