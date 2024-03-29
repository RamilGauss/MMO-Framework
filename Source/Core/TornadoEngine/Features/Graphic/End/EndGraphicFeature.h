/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/Feature.h>

#include "Features/Graphic/End/UpdateFromModule/GuiUpdaterFromModuleFeature.h"

#include "Features/Graphic/End/GraphicContext/OnRemoveUniverseContextSystem.h"

#include "Features/Graphic/End/GraphicContext/CleanUpUniverseContextSystem.h"

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
