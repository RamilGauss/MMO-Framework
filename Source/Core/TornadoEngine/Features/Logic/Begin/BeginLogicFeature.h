/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ECS/Include/Feature.h"
#include "HandlerCallCollectorNotifySystem.h"

namespace nsLogicWrapper
{
    class DllExport TBeginLogicFeature : public nsECSFramework::TFeature
    {
        THandlerCallCollectorNotifySystem mHandlerCallCollectorNotifySystem;

    public:
        void InitConveyor() override;
    };
}