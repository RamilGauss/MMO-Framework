/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ECS/Include/OnUpdateCollectReactiveSystem.h"

#include "Components/Gui/Properties/VisibilityComponent.h"

namespace nsGraphicWrapper
{
    class DllExport TVisibilityUpdateSystem :
        public nsECSFramework::TOnUpdateCollectReactiveSystem<nsGuiWrapper::TVisibilityComponent, TVisibilityUpdateSystem>
    {
    public:
        void Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TVisibilityComponent* pC);
    };
}