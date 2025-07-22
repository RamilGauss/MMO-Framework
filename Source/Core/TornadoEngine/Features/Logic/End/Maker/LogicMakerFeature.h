/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ECS/Include/Feature.h"

#include "SystemMakerSystem.h"
#include "GlobalHandlerMakerSystem.h"
#include "LocalHandlerMakerSystem.h"

namespace nsLogicWrapper
{
    class DllExport TLogicMakerFeature : public nsECSFramework::TFeature
    {
        TSystemMakerSystem mSystemMakerSystem;

        TGlobalHandlerMakerSystem mGlobalHandlerMakerSystem;
        TLocalHandlerMakerSystem mLocalHandlerMakerSystem;
    public:
        void InitConveyor() override;
    };
}