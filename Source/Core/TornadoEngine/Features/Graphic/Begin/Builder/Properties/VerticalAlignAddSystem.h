/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ECS/Include/OnAddCollectReactiveSystem.h"

#include "Components/Gui/Properties/VerticalAlignComponent.h"

namespace nsGraphicWrapper
{
    class DllExport TVerticalAlignAddSystem :
        public nsECSFramework::TOnAddCollectReactiveSystem<nsGuiWrapper::TVerticalAlignComponent, TVerticalAlignAddSystem>
    {
    public:
        void Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TVerticalAlignComponent* pC);
    };
}
