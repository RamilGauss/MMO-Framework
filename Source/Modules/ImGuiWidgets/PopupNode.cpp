/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "PopupNode.h"

using namespace nsImGuiWidgets;
using namespace std::placeholders;

void TPopupNode::Render()
{
    if (mWidgets.size()) {
        if (ImGui::BeginMenu(mLabel.c_str())) {
            for (auto& node : mWidgets) {
                node->Render();
            }
            ImGui::EndMenu();
        }
    } else {
        if (ImGui::Selectable(mLabel.c_str())) {
            onLeftClick.Notify(this);
        }
    }
}
//-------------------------------------------------------------------------
