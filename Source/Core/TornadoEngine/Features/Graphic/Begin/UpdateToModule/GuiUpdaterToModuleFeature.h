/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ECS/Include/Feature.h"

#include "Features/Graphic/Begin/UpdateToModule/TitleUpdaterSystem.h"
#include "Features/Graphic/Begin/UpdateToModule/InputTextValueUpdaterSystem.h"
#include "Features/Graphic/Begin/UpdateToModule/CameraUpdaterToModuleSystem.h"

namespace nsGraphicWrapper
{
    class DllExport TGuiUpdaterToModuleFeature : public nsECSFramework::TFeature
    {
        TTitleUpdaterSystem mTitleUpdaterSystem;
        TInputTextValueUpdaterSystem mInputTextValueUpdaterSystem;
        TCameraUpdaterToModuleSystem mCameraUpdaterToModuleSystem;
    public:
        void InitConveyor() override;
    };
}