/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/Feature.h>

#include "Features/Graphic/Begin/Terminator/Frames/WindowTerminatorSystem.h"
#include "Features/Graphic/Begin/Terminator/Frames/DialogTerminatorSystem.h"
#include "Features/Graphic/Begin/Terminator/Frames/TreeViewTerminatorSystem.h"
#include "Features/Graphic/Begin/Terminator/Frames/MainWindowTerminatorSystem.h"

#include "Features/Graphic/Begin/Terminator/Units/ButtonTerminatorSystem.h"
#include "Features/Graphic/Begin/Terminator/Units/LabelTerminatorSystem.h"
#include "Features/Graphic/Begin/Terminator/Units/MenuNodeTerminatorSystem.h"
#include "Features/Graphic/Begin/Terminator/Units/InputTextTerminatorSystem.h"
#include "Features/Graphic/Begin/Terminator/Units/TreeNodeTerminatorSystem.h"

#include "Features/Graphic/Begin/Terminator/Graphic/TextureTerminatorSystem.h"
#include "Features/Graphic/Begin/Terminator/Graphic/CameraTerminatorSystem.h"

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

        TTextureTerminatorSystem mTextureTerminatorSystem;
        TCameraTerminatorSystem mCameraTerminatorSystem;
    public:
        void InitConveyor() override;
    };
}