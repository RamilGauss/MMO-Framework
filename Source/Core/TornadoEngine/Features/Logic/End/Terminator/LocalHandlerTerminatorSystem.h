/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/OnRemoveInstantReactiveSystem.h>

#include "LocalHandlerComponent.h"

namespace nsLogicWrapper
{
    class DllExport TLocalHandlerTerminatorSystem :
        public nsECSFramework::TOnRemoveInstantReactiveSystem<nsLogicWrapper::TLocalHandlerComponent,
        TLocalHandlerTerminatorSystem>
    {
    public:
        void Reactive(nsECSFramework::TEntityID eid, const nsLogicWrapper::TLocalHandlerComponent* pC);
    };
}
