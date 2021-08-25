/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TreeNode.h"

using namespace nsImGuiWidgets;
using namespace std::placeholders;

void TTreeNode::Render()
{
    ImGuiTreeNodeFlags mode = ImGuiTreeNodeFlags_None | ImGuiTreeNodeFlags_OpenOnArrow;
    if (mWidgets.size() == 0) {
        mode |= ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_SpanAvailWidth;
    }
    if (mSelected) {
        mode |= ImGuiTreeNodeFlags_Selected;
    }
    if (ImGui::TreeNodeEx(mStrId.c_str(), mode, mLabel.c_str())) {
        SearchEvents();
        for (auto& node : mWidgets) {
            node->Render();
        }
        ImGui::TreePop();
    } else {
        SearchEvents();
    }
}
//-------------------------------------------------------------------------
void TTreeNode::SearchEvents()
{
    if (ImGui::IsItemClicked()) {
        onLeftClick.Notify(this);
    }
    if (ImGui::IsItemFocused()) {
        if (!mSelected) {
            mSelected = true;
            onSelection.Notify(this);
        }
    } else {
        mSelected = false;
    }
}
//-------------------------------------------------------------------------
