/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/Feature.h>
#include "ButtonMakerSystem.h"
#include "WindowMakerSystem.h"
#include "DialogMakerSystem.h"
#include "ButtonClickHandlerMakerSystem.h"

#include "DialogCloseEventHandlerMakerSystem.h"
#include "WindowCloseEventHandlerMakerSystem.h"

namespace nsGraphicWrapper
{
    class DllExport TGuiMakerFeature : public nsECSFramework::TFeature
    {
        TButtonMakerSystem mButtonMakerSystem;
        TWindowMakerSystem mWindowMakerSystem;
        TDialogMakerSystem mDialogMakerSystem;
        
        TButtonClickHandlerMakerSystem mButtonClickHandlerMakerSystem;
        TDialogCloseEventHandlerMakerSystem mDialogCloseEventHandlerMakerSystem;
        TWindowCloseEventHandlerMakerSystem mWindowCloseEventHandlerMakerSystem;
    public:
        void InitConveyor() override;
    };
}