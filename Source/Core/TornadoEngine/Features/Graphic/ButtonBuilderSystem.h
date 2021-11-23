/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/OnAddCollectReactiveSystem.h>

#include "ButtonComponent.h"

namespace nsGraphicWrapper
{
    class DllExport TButtonBuilderSystem :
        public nsECSFramework::TOnAddCollectReactiveSystem<nsGuiWrapper::TButtonComponent>
    {
    public:
        void Reactive(nsECSFramework::TEntityID eid, nsECSFramework::IComponent* pC) override;
    };
}