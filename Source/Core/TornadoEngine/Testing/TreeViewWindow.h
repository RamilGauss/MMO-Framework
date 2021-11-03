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
#include <ImGuiWidgets/include/TreeView.h>
#include <ImGuiWidgets/include/Button.h>
#include <ImGuiWidgets/include/TreeNode.h>
#include <ImGuiWidgets/include/PopupNode.h>
#include <ImGuiWidgets/include/PopupMenu.h>
#include <ImGuiWidgets/include/ToolTip.h>

namespace nsTest
{
    struct DllExport TTreeViewWindow
    {
        nsImGuiWidgets::TWindow mWindow;

        nsImGuiWidgets::TButton mButton;

        nsImGuiWidgets::TTreeNode mTreeNodes[6];
        nsImGuiWidgets::TTreeView mTreeView;

        nsImGuiWidgets::TToolTip mToolTip;

        TTreeViewWindow(std::string name);
    };
}