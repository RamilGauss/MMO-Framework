/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/OnUpdateCollectReactiveSystem.h>

#include "MinSizeComponent.h"

namespace nsGraphicWrapper
{
    class DllExport TMinSizeUpdateSystem :
        public nsECSFramework::TOnUpdateCollectReactiveSystem<nsGuiWrapper::TMinSizeComponent, TMinSizeUpdateSystem>
    {
    public:
        void Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TMinSizeComponent* pC);
    };
}