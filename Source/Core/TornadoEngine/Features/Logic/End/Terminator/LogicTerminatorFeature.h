/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ECS/Include/Feature.h"

#include "SystemTerminatorSystem.h"
#include "GlobalHandlerTerminatorSystem.h"
#include "LocalHandlerTerminatorSystem.h"

namespace nsLogicWrapper
{
    class DllExport TLogicTerminatorFeature : public nsECSFramework::TFeature
    {
        TSystemTerminatorSystem mSystemTerminatorSystem;
        TGlobalHandlerTerminatorSystem mGlobalHandlerTerminatorSystem;
        TLocalHandlerTerminatorSystem mLocalHandlerTerminatorSystem;
    public:
        void InitConveyor() override;
    };
}
