/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/Feature.h>

#include "SystemTerminatorSystem.h"
#include "ObjectInstanceEndHandlerTerminatorSystem.h"

namespace nsLogicWrapper
{
    class DllExport TLogicTerminatorFeature : public nsECSFramework::TFeature
    {
        TSystemTerminatorSystem mSystemTerminatorSystem;
        TObjectInstanceEndHandlerTerminatorSystem mObjectInstanceEndHandlerTerminatorSystem;
    public:
        void InitConveyor() override;
    };
}