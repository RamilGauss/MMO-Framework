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
#include <ImGuiWidgets/TreeNode.h>
#include <ImGuiWidgets/PopupNode.h>
#include <ImGuiWidgets/PopupMenu.h>

namespace nsTest
{
    struct DllExport TTreeViewWindow
    {
        nsImGuiWidgets::TWindow mWindow;

        nsImGuiWidgets::TTreeNode mTreeNodes[6];
        nsImGuiWidgets::TTreeView mTreeView;

        TTreeViewWindow(std::string name);
    };
}