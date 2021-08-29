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
#include <ImGuiWidgets/ToolTip.h>

namespace nsTest
{
    struct DllExport TUnderMouseWindow
    {
        nsImGuiWidgets::TWindow mWindow;

        nsImGuiWidgets::TLabel mLabel;
        nsImGuiWidgets::TToolTip mToolTip;

        TUnderMouseWindow(std::string name);
    };
}