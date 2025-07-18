/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <imgui.h>
#include <imgui_internal.h>

#include "Base/Common/TypeDef.h"

#include "ImGuiWidgets/Include/DockNode.h"

namespace nsImGuiWidgets
{
    struct DllExport TDockTypeHelper
    {
        static ImGuiAxis ToImGui(TDockNode::Type type);
        static TDockNode::Type FromImGui(ImGuiAxis type);
    };
}
