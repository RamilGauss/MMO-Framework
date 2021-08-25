/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "PopupMenu.h"
#include "PopupNode.h"

using namespace nsImGuiWidgets;

void TPopupMenu::Open()
{
    std::string strId = std::to_string(mId);
    ImGui::OpenPopup(strId.c_str());
}
//-------------------------------------------------------------------------
void TPopupMenu::Render()
{
    std::string strId = std::to_string(mId);
    if (!ImGui::BeginPopup(strId.c_str())) {
        return;
    }

    for (auto& node : mWidgets) {
        node->Render();
    }

    ImGui::EndPopup();
}
//-------------------------------------------------------------------------
