/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "TypeDef.h"

#include <ImGuiWidgets/MainWindow.h>
#include <ImGuiWidgets/MenuNode.h>


namespace nsTest
{
    struct DllExport TDockMainWindow
    {
        nsImGuiWidgets::TMainWindow mMW;

        nsImGuiWidgets::TMenuNode mMenuNodes[4];

        TDockMainWindow();
    };
}