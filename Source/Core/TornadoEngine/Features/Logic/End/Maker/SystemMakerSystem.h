/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ECS/Include/OnAddCollectReactiveSystem.h"

#include "Components/Logic/SystemComponent.h"

namespace nsLogicWrapper
{
    class DllExport TSystemMakerSystem :
        public nsECSFramework::TOnAddCollectReactiveSystem<nsLogicWrapper::TSystemComponent, TSystemMakerSystem>
    {
    public:
        void Reactive(nsECSFramework::TEntityID eid, const nsLogicWrapper::TSystemComponent* pC);
    };
}
