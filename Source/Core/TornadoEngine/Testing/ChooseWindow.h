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
#include <ImGuiWidgets/include/MenuNode.h>
#include <ImGuiWidgets/include/Button.h>


namespace nsTest
{
    struct DllExport TChooseWindow
    {
        nsImGuiWidgets::TWindow mWindow;

        nsImGuiWidgets::TButton mTestAllWidgetsButton;
        nsImGuiWidgets::TButton mDockingButton;
        nsImGuiWidgets::TButton mDockingStuffButton;
        nsImGuiWidgets::TButton mTreeViewButton;
        nsImGuiWidgets::TButton mUnderMouseButton;

        nsImGuiWidgets::TButton mExit;

        TChooseWindow(std::string name);
        ~TChooseWindow();
    };
}