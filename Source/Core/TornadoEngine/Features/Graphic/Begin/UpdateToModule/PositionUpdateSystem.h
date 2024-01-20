/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/OnUpdateCollectReactiveSystem.h>

#include "Components/Gui/Properties/PositionComponent.h"

namespace nsGraphicWrapper
{
    class DllExport TPositionUpdateSystem :
        public nsECSFramework::TOnUpdateCollectReactiveSystem<nsGuiWrapper::TPositionComponent, TPositionUpdateSystem>
    {
    public:
        void Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TPositionComponent* pC);
    };
}