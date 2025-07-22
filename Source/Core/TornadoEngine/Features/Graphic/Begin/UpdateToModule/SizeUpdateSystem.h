/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ECS/Include/OnUpdateCollectReactiveSystem.h"

#include "Components/Gui/Properties/SizeComponent.h"

namespace nsGraphicWrapper
{
    class DllExport TSizeUpdateSystem :
        public nsECSFramework::TOnUpdateCollectReactiveSystem<nsGuiWrapper::TSizeComponent, TSizeUpdateSystem>
    {
    public:
        void Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TSizeComponent* pC);
    };
}