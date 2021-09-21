/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ToolTip.h"

#include <imgui.h>

using namespace nsImGuiWidgets;

void TToolTip::Render()
{
    if (mIsShown) {
        ImGui::BeginTooltip();
        ImGui::Text(mTitle.c_str());
        ImGui::EndTooltip();
    }
}
