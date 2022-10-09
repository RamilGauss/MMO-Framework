/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/OnRemoveInstantReactiveSystem.h>

#include "FrameMouseMoveHandlerComponent.h"

namespace nsGraphicWrapper
{
    class DllExport TFrameMouseMoveHandlerTerminatorSystem :
        public nsECSFramework::TOnRemoveInstantReactiveSystem<nsGuiWrapper::TFrameMouseMoveHandlerComponent, TFrameMouseMoveHandlerTerminatorSystem>
    {
    public:
        void Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TFrameMouseMoveHandlerComponent* pC);
    };
}