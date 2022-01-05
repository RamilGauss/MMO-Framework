/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/OnRemoveInstantReactiveSystem.h>

#include "ButtonClickHandlerComponent.h"

namespace nsGraphicWrapper
{
    class DllExport TButtonClickHandlerTerminatorSystem :
        public nsECSFramework::TOnRemoveInstantReactiveSystem<nsGuiWrapper::TButtonClickHandlerComponent, TButtonClickHandlerTerminatorSystem>
    {
    public:
        void Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TButtonClickHandlerComponent* pC);
    };
}