/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/Feature.h>

#include "GuiMakerFeature.h"
#include "GuiBuilderFeature.h"
#include "GuiTerminatorFeature.h"
#include "GuiUpdaterToModuleFeature.h"

namespace nsGraphicWrapper
{
    class DllExport TBeginGraphicFeature : public nsECSFramework::TFeature
    {
        TGuiMakerFeature mGuiMakerFeature;
        TGuiBuilderFeature mGuiBuilderFeature;
        TGuiTerminatorFeature mGuiTerminatorFeature;

        TGuiUpdaterToModuleFeature mGuiUpdaterToModuleFeature;
    public:
        void InitConveyor() override;
    };
}