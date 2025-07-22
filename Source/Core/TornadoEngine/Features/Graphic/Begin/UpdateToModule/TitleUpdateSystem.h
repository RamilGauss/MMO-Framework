/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ECS/Include/OnUpdateCollectReactiveSystem.h"

#include "Components/Gui/Properties/TitleComponent.h"

namespace nsGraphicWrapper
{
    class DllExport TTitleUpdateSystem :
        public nsECSFramework::TOnUpdateCollectReactiveSystem<nsGuiWrapper::TTitleComponent, TTitleUpdateSystem>
    {
    public:
        void Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TTitleComponent* pC);
    };
}