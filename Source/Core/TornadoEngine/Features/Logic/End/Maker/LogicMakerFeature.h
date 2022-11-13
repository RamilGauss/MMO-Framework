/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/Feature.h>

#include "SystemMakerSystem.h"
#include "ObjectInstantiationCompletionHandlerMakerSystem.h"

namespace nsLogicWrapper
{
    class DllExport TLogicMakerFeature : public nsECSFramework::TFeature
    {
        TSystemMakerSystem mSystemMakerSystem;
        TObjectInstantiationCompletionHandlerMakerSystem mObjectInstantiationCompletionHandlerMakerSystem;
    public:
        void InitConveyor() override;
    };
}