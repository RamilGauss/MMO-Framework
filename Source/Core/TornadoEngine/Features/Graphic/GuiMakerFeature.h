/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/Feature.h>

#include "ButtonMakerSystem.h"
#include "MenuNodeMakerSystem.h"
#include "InputTextMakerSystem.h"
#include "WindowMakerSystem.h"
#include "DialogMakerSystem.h"
#include "ButtonClickHandlerMakerSystem.h"
#include "MenuNodeClickHandlerMakerSystem.h"

#include "MainWindowMakerSystem.h"

#include "DialogCloseEventHandlerMakerSystem.h"
#include "WindowCloseEventHandlerMakerSystem.h"

namespace nsGraphicWrapper
{
    class DllExport TGuiMakerFeature : public nsECSFramework::TFeature
    {
        TButtonMakerSystem mButtonMakerSystem;
        TMenuNodeMakerSystem mMenuNodeMakerSystem;
        TInputTextMakerSystem mInputTextMakerSystem;
        TWindowMakerSystem mWindowMakerSystem;
        TDialogMakerSystem mDialogMakerSystem;

        TMainWindowMakerSystem mMainWindowMakerSystem;
        
        TButtonClickHandlerMakerSystem mButtonClickHandlerMakerSystem;
        TMenuNodeClickHandlerMakerSystem mMenuNodeClickHandlerMakerSystem;
        TDialogCloseEventHandlerMakerSystem mDialogCloseEventHandlerMakerSystem;
        TWindowCloseEventHandlerMakerSystem mWindowCloseEventHandlerMakerSystem;
    public:
        void InitConveyor() override;
    };
}