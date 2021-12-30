/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/Feature.h>

#include "TitleUpdaterSystem.h"
#include "InputTextValueUpdaterSystem.h"

namespace nsGraphicWrapper
{
    class DllExport TGuiUpdaterToModuleFeature : public nsECSFramework::TFeature
    {
        TTitleUpdaterSystem mTitleUpdaterSystem;
        TInputTextValueUpdaterSystem mInputTextValueUpdaterSystem;
    public:
        void InitConveyor() override;
    };
}