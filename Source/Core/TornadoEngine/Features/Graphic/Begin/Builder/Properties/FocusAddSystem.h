/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ECS/Include/OnAddCollectReactiveSystem.h"

#include "Components/Gui/Properties/FocusComponent.h"

namespace nsGraphicWrapper
{
    class DllExport TFocusAddSystem :
        public nsECSFramework::TOnAddCollectReactiveSystem<nsGuiWrapper::TFocusComponent, TFocusAddSystem>
    {
    public:
        void Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TFocusComponent* pC);
    };
}
