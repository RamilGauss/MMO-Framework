/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/OnAddCollectReactiveSystem.h>

#include "HandlerComponent.h"

namespace nsLogicWrapper
{
    class DllExport THandlerMakerSystem :
        public nsECSFramework::TOnAddCollectReactiveSystem<nsLogicWrapper::THandlerComponent, THandlerMakerSystem>
    {
    public:
        void Reactive(nsECSFramework::TEntityID eid, const nsLogicWrapper::THandlerComponent* pC);
    };
}
