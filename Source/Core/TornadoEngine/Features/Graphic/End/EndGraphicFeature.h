/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/Feature.h>

#include "GuiUpdaterFromModuleFeature.h"

#include "OnRemoveUniverseContextSystem.h"

#include "CleanUpUniverseContextSystem.h"

namespace nsGraphicWrapper
{
    class DllExport TEndGraphicFeature : public nsECSFramework::TFeature
    {
        TGuiUpdaterFromModuleFeature mGuiUpdaterFromModuleFeature;

        TOnRemoveUniverseContextSystem mOnRemoveUniverseContextSystem;

        TCleanUpUniverseContextSystem mCleanUpUniverseContextSystem;
    public:
        void InitConveyor() override;
    };
}