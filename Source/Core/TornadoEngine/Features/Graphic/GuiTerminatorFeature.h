/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/Feature.h>

#include "ButtonTerminatorSystem.h"
#include "WindowTerminatorSystem.h"
#include "DialogTerminatorSystem.h"

#include "ButtonClickHandlerTerminatorSystem.h"
#include "DialogCloseEventHandlerTerminatorSystem.h"

namespace nsGraphicWrapper
{
    class DllExport TGuiTerminatorFeature : public nsECSFramework::TFeature
    {
        TButtonTerminatorSystem mButtonTerminatorSystem;
        TWindowTerminatorSystem mWindowTerminatorSystem;
        TDialogTerminatorSystem mDialogTerminatorSystem;

        TButtonClickHandlerTerminatorSystem mButtonClickHandlerTerminatorSystem;
        TDialogCloseEventHandlerTerminatorSystem mDialogCloseEventHandlerTerminatorSystem;
    public:
        void InitConveyor() override;
    };
}