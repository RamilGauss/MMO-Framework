/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "TypeDef.h"

#include <ECS/include/Feature.h>
#include <ImGuiWidgets/include/MainWindow.h>
#include <ImGuiWidgets/include/Window.h>
#include <ImGuiWidgets/include/Button.h>
#include <ImGuiWidgets/include/InputInt.h>
#include <ImGuiWidgets/include/InputMultiText.h>
#include <ImGuiWidgets/include/Label.h>
#include <ImGuiWidgets/include/TreeView.h>
#include <ImGuiWidgets/include/TreeNode.h>
#include <ImGuiWidgets/include/CheckBox.h>
#include <ImGuiWidgets/include/ComboBox.h>
#include <ImGuiWidgets/include/PopupNode.h>
#include <ImGuiWidgets/include/PopupMenu.h>

namespace nsTest
{
    struct DllExport TDockingWindow
    {
        nsImGuiWidgets::TWindow mWindow;

        TDockingWindow(std::string name);
    };
}