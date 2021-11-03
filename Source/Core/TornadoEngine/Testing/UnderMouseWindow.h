/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "TypeDef.h"

#include <ImGuiWidgets/include/Window.h>
#include <ImGuiWidgets/include/Label.h>
#include <ImGuiWidgets/include/TreeView.h>
#include <ImGuiWidgets/include/ToolTip.h>
#include <ImGuiWidgets/include/Button.h>

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