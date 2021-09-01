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
#include <ImGuiWidgets/TreeView.h>
#include <ImGuiWidgets/Button.h>
#include <ImGuiWidgets/TreeNode.h>
#include <ImGuiWidgets/PopupNode.h>
#include <ImGuiWidgets/PopupMenu.h>
#include <ImGuiWidgets/ToolTip.h>

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