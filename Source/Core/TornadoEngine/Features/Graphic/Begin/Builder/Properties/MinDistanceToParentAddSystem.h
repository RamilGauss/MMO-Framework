/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/OnAddCollectReactiveSystem.h>

#include "MinDistanceToParentComponent.h"

namespace nsGraphicWrapper
{
    class DllExport TMinDistanceToParentAddSystem :
        public nsECSFramework::TOnAddCollectReactiveSystem<nsGuiWrapper::TMinDistanceToParentComponent, TMinDistanceToParentAddSystem>
    {
    public:
        void Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TMinDistanceToParentComponent* pC);
    };
}