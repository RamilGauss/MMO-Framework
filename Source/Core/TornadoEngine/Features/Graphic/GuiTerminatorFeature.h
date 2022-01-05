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
    public:
        void InitConveyor() override;
    };
}