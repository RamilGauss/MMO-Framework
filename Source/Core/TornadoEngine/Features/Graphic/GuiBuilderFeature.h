/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/Feature.h>

#include "ButtonBuilderSystem.h"
#include "WindowBuilderSystem.h"
#include "DialogBuilderSystem.h"

#include "ButtonClickHandlerBuilderSystem.h"
#include "DialogCloseEventHandlerBuilderSystem.h"

namespace nsGraphicWrapper
{
    class DllExport TGuiBuilderFeature : public nsECSFramework::TFeature
    {
        TButtonBuilderSystem mButtonBuilderSystem;
        TWindowBuilderSystem mWindowBuilderSystem;
        TDialogBuilderSystem mDialogBuilderSystem;
        
        TButtonClickHandlerBuilderSystem mButtonClickHandlerBuilderSystem;
        TDialogCloseEventHandlerBuilderSystem mDialogCloseEventHandlerBuilderSystem;
    public:
        void InitConveyor() override;
    };
}