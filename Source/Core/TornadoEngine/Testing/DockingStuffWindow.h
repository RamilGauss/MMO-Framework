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
#include <ImGuiWidgets/include/Window.h>
#include <ImGuiWidgets/include/InputMultiText.h>
#include <ImGuiWidgets/include/PopupNode.h>
#include <ImGuiWidgets/include/PopupMenu.h>

namespace nsTest
{
    struct DllExport TDockingStuffWindow
    {
        nsImGuiWidgets::TWindow mWindow;

        nsImGuiWidgets::TInputMultiText mTextEdit;

        nsImGuiWidgets::TPopupNode mPopupNodes[6];
        nsImGuiWidgets::TPopupMenu mPopup;

        TDockingStuffWindow(std::string name);
    };
}