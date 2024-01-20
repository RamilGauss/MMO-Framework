/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/OnAddCollectReactiveSystem.h>

#include "Components/Graphic/CameraComponent.h"

namespace nsGraphicWrapper
{
    class DllExport TCameraMakerSystem :
        public nsECSFramework::TOnAddCollectReactiveSystem<nsGraphicWrapper::TCameraComponent, TCameraMakerSystem>
    {
    public:
        void Reactive(nsECSFramework::TEntityID eid, const nsGraphicWrapper::TCameraComponent* pC);
    };
}