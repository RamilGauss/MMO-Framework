/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/Feature.h>

#include "ButtonBuilderSystem.h"
#include "MenuNodeBuilderSystem.h"
#include "InputTextBuilderSystem.h"
#include "WindowBuilderSystem.h"
#include "DialogBuilderSystem.h"

#include "MainWindowBuilderSystem.h"

#include "ButtonClickHandlerBuilderSystem.h"
#include "MenuNodeClickHandlerBuilderSystem.h"
#include "DialogCloseEventHandlerBuilderSystem.h"
#include "WindowCloseEventHandlerBuilderSystem.h"

namespace nsGraphicWrapper
{
    class DllExport TGuiBuilderFeature : public nsECSFramework::TFeature
    {
        TButtonBuilderSystem mButtonBuilderSystem;
        TMenuNodeBuilderSystem mMenuNodeBuilderSystem;
        TInputTextBuilderSystem mInputTextBuilderSystem;
        TWindowBuilderSystem mWindowBuilderSystem;
        TDialogBuilderSystem mDialogBuilderSystem;

        TMainWindowBuilderSystem mMainWindowBuilderSystem;
        
        TButtonClickHandlerBuilderSystem mButtonClickHandlerBuilderSystem;
        TMenuNodeClickHandlerBuilderSystem mMenuNodeClickHandlerBuilderSystem;
        TDialogCloseEventHandlerBuilderSystem mDialogCloseEventHandlerBuilderSystem;
        TWindowCloseEventHandlerBuilderSystem mWindowCloseEventHandlerBuilderSystem;
    public:
        void InitConveyor() override;
    };
}