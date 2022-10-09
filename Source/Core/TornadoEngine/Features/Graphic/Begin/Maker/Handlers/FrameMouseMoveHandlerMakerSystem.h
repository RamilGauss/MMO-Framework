/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/OnAddCollectReactiveSystem.h>

#include "FrameMouseMoveHandlerComponent.h"

namespace nsGraphicWrapper
{
    class DllExport TFrameMouseMoveHandlerMakerSystem :
        public nsECSFramework::TOnAddCollectReactiveSystem<nsGuiWrapper::TFrameMouseMoveHandlerComponent, TFrameMouseMoveHandlerMakerSystem>
    {
    public:
        void Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TFrameMouseMoveHandlerComponent* pC);
    };
}