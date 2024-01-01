/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/TypeDef.h"

#include <imgui.h>
#include <imgui_internal.h>

namespace nsImGuiWidgets
{
    class DllExport TImGuiCustom
    {
    public:
        static bool TreeNodeExV(const char* str_id, ImGuiTreeNodeFlags flags, const char* fmt,
            ImTextureID user_texture_id, const ImVec2& size);

        static bool MenuItem(const char* label, const char* shortcut, bool selected, bool enabled,
            ImTextureID user_texture_id, const ImVec2& size);
        static bool MenuItem(const char* label, const char* shortcut, bool* p_selected, bool enabled,
            ImTextureID user_texture_id, const ImVec2& size);
    private:
        static bool MenuItemEx(const char* label, const char* icon, const char* shortcut, bool selected, bool enabled,
            ImTextureID user_texture_id, const ImVec2& size);

        static void RenderImage(ImGuiWindow* window, ImTextureID user_texture_id, const ImVec2& minPoint, const ImVec2& maxPoint);

        static bool TreeNodeBehavior(ImGuiID id, ImGuiTreeNodeFlags flags,
            const char* label, const char* label_end, ImTextureID user_texture_id, const ImVec2& size);
    };

}
