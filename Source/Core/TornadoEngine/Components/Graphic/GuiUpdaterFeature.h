/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/Feature.h>

#include "WindowPositionUpdaterSystem.h"
#include "WindowSizeUpdaterSystem.h"

namespace nsGraphicWrapper
{
    class DllExport TGuiUpdaterFeature : public nsECSFramework::TFeature
    {
        TWindowPositionUpdaterSystem mWindowPositionUpdaterSystem;
        TWindowSizeUpdaterSystem mWindowSizeUpdaterSystem;
    public:
        void InitConveyor() override;
    };
}