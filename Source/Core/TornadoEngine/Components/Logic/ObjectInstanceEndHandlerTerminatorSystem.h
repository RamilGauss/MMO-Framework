/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/OnRemoveInstantReactiveSystem.h>

#include "ObjectInstanceEndHandlerComponent.h"

namespace nsLogicWrapper
{
    class DllExport TObjectInstanceEndHandlerTerminatorSystem :
        public nsECSFramework::TOnRemoveInstantReactiveSystem<nsLogicWrapper::TObjectInstanceEndHandlerComponent, TObjectInstanceEndHandlerTerminatorSystem>
    {
    public:
        void Reactive(nsECSFramework::TEntityID eid, const nsLogicWrapper::TObjectInstanceEndHandlerComponent* pC);
    };
}
