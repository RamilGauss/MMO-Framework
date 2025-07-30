/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ECS/Include/OnAddCollectReactiveSystem.h"

#include "TornadoEngine/Components/Handler/LocalHandlerComponent.h"

namespace nsLogicWrapper
{
    class DllExport TLocalHandlerMakerSystem :
        public nsECSFramework::TOnAddCollectReactiveSystem<nsLogicWrapper::TLocalHandlerComponent, TLocalHandlerMakerSystem>
    {
    public:
        void Reactive(nsECSFramework::TEntityID eid, const nsLogicWrapper::TLocalHandlerComponent* pC);
    };
}
