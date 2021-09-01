/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "TypeDef.h"

#include <ImGuiWidgets/Window.h>
#include <ImGuiWidgets/Label.h>
#include <ImGuiWidgets/TreeView.h>
#include <ImGuiWidgets/ToolTip.h>
#include <ImGuiWidgets/Button.h>

namespace nsTest
{
    struct DllExport TUnderMouseWindow
    {
        nsImGuiWidgets::TWindow mWindow;

        nsImGuiWidgets::TLabel mLabel;
        nsImGuiWidgets::TToolTip mToolTip;

        nsImGuiWidgets::TTreeView mTreeView;
        nsImGuiWidgets::TButton mButton;

        TUnderMouseWindow(std::string name);
    };
}