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
#include <ImGuiWidgets/MainWindow.h>
#include <ImGuiWidgets/Window.h>
#include <ImGuiWidgets/Button.h>
#include <ImGuiWidgets/InputInt.h>
#include <ImGuiWidgets/InputMultiText.h>
#include <ImGuiWidgets/Label.h>
#include <ImGuiWidgets/TreeView.h>
#include <ImGuiWidgets/TreeNode.h>
#include <ImGuiWidgets/CheckBox.h>
#include <ImGuiWidgets/ComboBox.h>
#include <ImGuiWidgets/PopupNode.h>
#include <ImGuiWidgets/PopupMenu.h>

namespace nsTest
{
    struct DllExport TDockingWindow
    {
        nsImGuiWidgets::TWindow mWindow;

        TDockingWindow(std::string name);
    };
}