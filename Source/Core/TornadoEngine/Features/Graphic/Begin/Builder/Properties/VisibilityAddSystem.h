/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/OnAddCollectReactiveSystem.h>

#include "Components/Gui/Properties/VisibilityComponent.h"

namespace nsGraphicWrapper
{
    class DllExport TVisibilityAddSystem :
        public nsECSFramework::TOnAddCollectReactiveSystem<nsGuiWrapper::TVisibilityComponent, TVisibilityAddSystem>
    {
    public:
        void Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TVisibilityComponent* pC);
    };
}
