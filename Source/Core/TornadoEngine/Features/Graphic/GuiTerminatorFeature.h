/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/Feature.h>

#include "ButtonTerminatorSystem.h"
#include "LabelTerminatorSystem.h"
#include "MenuNodeTerminatorSystem.h"
#include "InputTextTerminatorSystem.h"
#include "WindowTerminatorSystem.h"
#include "DialogTerminatorSystem.h"

#include "TreeNodeTerminatorSystem.h"
#include "TreeViewTerminatorSystem.h"

#include "MainWindowTerminatorSystem.h"

#include "ButtonClickHandlerTerminatorSystem.h"
#include "MenuNodeClickHandlerTerminatorSystem.h"
#include "DialogCloseEventHandlerTerminatorSystem.h"
#include "WindowCloseEventHandlerTerminatorSystem.h"

#include "FrameKeyHandlerTerminatorSystem.h"
#include "FrameMouseClickHandlerTerminatorSystem.h"
#include "FrameMouseMoveHandlerTerminatorSystem.h"
#include "FrameMouseWheelHandlerTerminatorSystem.h"

#include "TextureTerminatorSystem.h"
#include "CameraTerminatorSystem.h"

namespace nsGraphicWrapper
{
    class DllExport TGuiTerminatorFeature : public nsECSFramework::TFeature
    {
        TButtonTerminatorSystem mButtonTerminatorSystem;
        TLabelTerminatorSystem mLabelTerminatorSystem;
        TMenuNodeTerminatorSystem mMenuNodeTerminatorSystem;
        TInputTextTerminatorSystem mInputTextTerminatorSystem;
        TWindowTerminatorSystem mWindowTerminatorSystem;
        TDialogTerminatorSystem mDialogTerminatorSystem;

        TTreeNodeTerminatorSystem mTreeNodeTerminatorSystem;
        TTreeViewTerminatorSystem mTreeViewTerminatorSystem;

        TMainWindowTerminatorSystem mMainWindowTerminatorSystem;

        TButtonClickHandlerTerminatorSystem mButtonClickHandlerTerminatorSystem;
        TMenuNodeClickHandlerTerminatorSystem mMenuNodeClickHandlerTerminatorSystem;
        TDialogCloseEventHandlerTerminatorSystem mDialogCloseEventHandlerTerminatorSystem;
        TWindowCloseEventHandlerTerminatorSystem mWindowCloseEventHandlerTerminatorSystem;

        TFrameKeyHandlerTerminatorSystem        mFrameKeyHandlerTerminatorSystem;
        TFrameMouseClickHandlerTerminatorSystem mFrameMouseClickHandlerTerminatorSystem;
        TFrameMouseMoveHandlerTerminatorSystem  mFrameMouseMoveHandlerTerminatorSystem;
        TFrameMouseWheelHandlerTerminatorSystem mFrameMouseWheelHandlerTerminatorSystem;

        TTextureTerminatorSystem mTextureTerminatorSystem;
        TCameraTerminatorSystem mCameraTerminatorSystem;
    public:
        void InitConveyor() override;
    };
}