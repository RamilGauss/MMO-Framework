/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/OnAddCollectReactiveSystem.h>

#include "WindowComponent.h"

namespace nsGraphicWrapper
{
    class DllExport TWindowMakerSystem :
        public nsECSFramework::TOnAddCollectReactiveSystem<nsGuiWrapper::TWindowComponent, TWindowMakerSystem>
    {
    public:
        void Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TWindowComponent* pC);
    };
}