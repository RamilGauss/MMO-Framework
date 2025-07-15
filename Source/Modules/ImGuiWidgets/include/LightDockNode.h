/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <vector>

#include "ImGuiWidgets/Include/LightWindowNode.h"

namespace nsImGuiWidgets
{
    struct DllExport TLightDockNode
    {
        ImGuiID id;

        TLightDockNode* parent = nullptr;
        TLightDockNode* child[2] = {nullptr};

        ImGuiDockNode* imParent = nullptr;
        ImGuiDockNode* imChild[2] = {nullptr};

        ImGuiAxis splitMode;
        ImGuiDockNodeState state;

        // Strict order
        std::vector<TLightWindowNode> windows;

        int selectedWindowIndex = 0;

        ImVec2 pos;
        ImVec2 size;

        bool operator == (const TLightDockNode& other);

        bool HasChild() const;
    };
}
