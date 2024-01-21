/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/OnAddCollectReactiveSystem.h>

#include "Components/Gui/Widgets/InputTextComponent.h"

namespace nsGraphicWrapper
{
    class DllExport TInputTextBuilderSystem :
        public nsECSFramework::TOnAddCollectReactiveSystem<nsGuiWrapper::TInputTextComponent, TInputTextBuilderSystem>
    {
    public:
        void Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TInputTextComponent* pC);
    };
}
