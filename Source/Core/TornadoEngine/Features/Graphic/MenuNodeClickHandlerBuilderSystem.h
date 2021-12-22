/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/OnAddCollectReactiveSystem.h>

#include "MenuNodeClickHandlerComponent.h"

namespace nsGraphicWrapper
{
    class DllExport TMenuNodeClickHandlerBuilderSystem :
        public nsECSFramework::TOnAddCollectReactiveSystem<nsGuiWrapper::TMenuNodeClickHandlerComponent, TMenuNodeClickHandlerBuilderSystem>
    {
    public:
        void Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TMenuNodeClickHandlerComponent* pC);
    };
}