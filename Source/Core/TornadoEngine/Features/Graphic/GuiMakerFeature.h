/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/Feature.h>

#include "ButtonMakerSystem.h"
#include "LabelMakerSystem.h"
#include "MenuNodeMakerSystem.h"
#include "InputTextMakerSystem.h"
#include "WindowMakerSystem.h"
#include "DialogMakerSystem.h"
#include "ButtonClickHandlerMakerSystem.h"
#include "MenuNodeClickHandlerMakerSystem.h"

#include "TreeNodeMakerSystem.h"
#include "TreeViewMakerSystem.h"

#include "MainWindowMakerSystem.h"

#include "DialogCloseEventHandlerMakerSystem.h"
#include "WindowCloseEventHandlerMakerSystem.h"

#include "FrameMouseClickHandlerMakerSystem.h"
#include "FrameMouseMoveHandlerMakerSystem.h"
#include "FrameMouseWheelHandlerMakerSystem.h"
#include "FrameKeyHandlerMakerSystem.h"

namespace nsGraphicWrapper
{
    class DllExport TGuiMakerFeature : public nsECSFramework::TFeature
    {
        TButtonMakerSystem mButtonMakerSystem;
        TLabelMakerSystem mLabelMakerSystem;
        TMenuNodeMakerSystem mMenuNodeMakerSystem;
        TInputTextMakerSystem mInputTextMakerSystem;
        TWindowMakerSystem mWindowMakerSystem;
        TDialogMakerSystem mDialogMakerSystem;

        TTreeNodeMakerSystem mTreeNodeMakerSystem;
        TTreeViewMakerSystem mTreeViewMakerSystem;

        TMainWindowMakerSystem mMainWindowMakerSystem;
        
        TButtonClickHandlerMakerSystem mButtonClickHandlerMakerSystem;
        TMenuNodeClickHandlerMakerSystem mMenuNodeClickHandlerMakerSystem;
        TDialogCloseEventHandlerMakerSystem mDialogCloseEventHandlerMakerSystem;
        TWindowCloseEventHandlerMakerSystem mWindowCloseEventHandlerMakerSystem;

        TFrameMouseClickHandlerMakerSystem mFrameMouseClickHandlerMakerSystem;
        TFrameMouseMoveHandlerMakerSystem  mFrameMouseMoveHandlerMakerSystem;
        TFrameMouseWheelHandlerMakerSystem mFrameMouseWheelHandlerMakerSystem;

        TFrameKeyHandlerMakerSystem mFrameKeyHandlerMakerSystem;
    public:
        void InitConveyor() override;
    };
}