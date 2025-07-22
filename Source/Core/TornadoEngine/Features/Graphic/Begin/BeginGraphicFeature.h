/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ECS/Include/Feature.h"

#include "Features/Graphic/Begin/GraphicContext/OnAddUniverseContextSystem.h"

#include "Features/Graphic/Begin/Maker/GuiMakerFeature.h"
#include "Features/Graphic/Begin/Builder/GuiBuilderFeature.h"
#include "Features/Graphic/Begin/Terminator/GuiTerminatorFeature.h"
#include "Features/Graphic/Begin/UpdateToModule/GuiUpdaterToModuleFeature.h"

namespace nsGraphicWrapper
{
    class DllExport TBeginGraphicFeature : public nsECSFramework::TFeature
    {
        TOnAddUniverseContextSystem mOnAddUniverseContextSystem;

        TGuiMakerFeature mGuiMakerFeature;
        TGuiBuilderFeature mGuiBuilderFeature;
        TGuiTerminatorFeature mGuiTerminatorFeature;

        TGuiUpdaterToModuleFeature mGuiUpdaterToModuleFeature;
    public:
        void InitConveyor() override;
    };
}