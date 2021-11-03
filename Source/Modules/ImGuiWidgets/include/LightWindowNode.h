/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include <imgui.h>
#include <imgui_internal.h>

#include "TypeDef.h"

namespace nsImGuiWidgets
{
    struct DllExport TLightWindowNode
    {
        ImGuiID id = 0;
        std::string name;
        ImGuiWindow* imWindow = nullptr;

        bool operator == (const TLightWindowNode& other) const;
    };
}
