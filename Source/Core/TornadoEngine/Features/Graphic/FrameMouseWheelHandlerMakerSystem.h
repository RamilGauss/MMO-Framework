/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/OnAddCollectReactiveSystem.h>

#include "FrameMouseWheelHandlerComponent.h"

namespace nsGraphicWrapper
{
    class DllExport TFrameMouseWheelHandlerMakerSystem :
        public nsECSFramework::TOnAddCollectReactiveSystem<nsGuiWrapper::TFrameMouseWheelHandlerComponent, TFrameMouseWheelHandlerMakerSystem>
    {
    public:
        void Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TFrameMouseWheelHandlerComponent* pC);
    };
}