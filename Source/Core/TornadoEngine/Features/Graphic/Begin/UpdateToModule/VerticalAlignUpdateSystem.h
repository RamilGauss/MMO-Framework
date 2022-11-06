/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/OnUpdateCollectReactiveSystem.h>

#include "VerticalAlignComponent.h"

namespace nsGraphicWrapper
{
    class DllExport TVerticalAlignUpdateSystem :
        public nsECSFramework::TOnUpdateCollectReactiveSystem<nsGuiWrapper::TVerticalAlignComponent, TVerticalAlignUpdateSystem>
    {
    public:
        void Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TVerticalAlignComponent* pC);
    };
}