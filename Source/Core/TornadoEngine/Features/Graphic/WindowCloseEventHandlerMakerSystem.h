/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/OnAddCollectReactiveSystem.h>

#include "WindowCloseEventHandlerComponent.h"

namespace nsGraphicWrapper
{
    class DllExport TWindowCloseEventHandlerMakerSystem :
        public nsECSFramework::TOnAddCollectReactiveSystem<nsGuiWrapper::TWindowCloseEventHandlerComponent, TWindowCloseEventHandlerMakerSystem>
    {
    public:
        void Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TWindowCloseEventHandlerComponent* pC);
    };
}