/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ECS/Include/OnRemoveInstantReactiveSystem.h"

#include "Components/Handler/GlobalHandlerComponent.h"

namespace nsLogicWrapper
{
    class DllExport TGlobalHandlerTerminatorSystem :
        public nsECSFramework::TOnRemoveInstantReactiveSystem<nsLogicWrapper::TGlobalHandlerComponent,
        TGlobalHandlerTerminatorSystem>
    {
    public:
        void Reactive(nsECSFramework::TEntityID eid, const nsLogicWrapper::TGlobalHandlerComponent* pC);
    };
}
