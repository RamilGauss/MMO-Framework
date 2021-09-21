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
#include <ImGuiWidgets/MenuNode.h>


namespace nsTest
{
    struct DllExport TMainWindow
    {
        nsImGuiWidgets::TMainWindow mMW;

        nsImGuiWidgets::TMenuNode mMenuNodes[3];

        TMainWindow();
    };
}