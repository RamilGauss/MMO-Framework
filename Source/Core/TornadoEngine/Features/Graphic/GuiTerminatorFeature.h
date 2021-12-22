/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/Feature.h>

#include "ButtonTerminatorSystem.h"
#include "MenuNodeTerminatorSystem.h"
#include "InputTextTerminatorSystem.h"
#include "WindowTerminatorSystem.h"
#include "DialogTerminatorSystem.h"

#include "MainWindowTerminatorSystem.h"

#include "ButtonClickHandlerTerminatorSystem.h"
#include "MenuNodeClickHandlerTerminatorSystem.h"
#include "DialogCloseEventHandlerTerminatorSystem.h"
#include "WindowCloseEventHandlerTerminatorSystem.h"

namespace nsGraphicWrapper
{
    class DllExport TGuiTerminatorFeature : public nsECSFramework::TFeature
    {
        TButtonTerminatorSystem mButtonTerminatorSystem;
        TMenuNodeTerminatorSystem mMenuNodeTerminatorSystem;
        TInputTextTerminatorSystem mInputTextTerminatorSystem;
        TWindowTerminatorSystem mWindowTerminatorSystem;
        TDialogTerminatorSystem mDialogTerminatorSystem;

        TMainWindowTerminatorSystem mMainWindowTerminatorSystem;

        TButtonClickHandlerTerminatorSystem mButtonClickHandlerTerminatorSystem;
        TMenuNodeClickHandlerTerminatorSystem mMenuNodeClickHandlerTerminatorSystem;
        TDialogCloseEventHandlerTerminatorSystem mDialogCloseEventHandlerTerminatorSystem;
        TWindowCloseEventHandlerTerminatorSystem mWindowCloseEventHandlerTerminatorSystem;
    public:
        void InitConveyor() override;
    };
}