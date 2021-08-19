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
    if (mNodes.size() == 0) {
        mode |= ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_SpanAvailWidth;
    }
    if (mSelected) {
        mode |= ImGuiTreeNodeFlags_Selected;
    }
    if (ImGui::TreeNodeEx(mId.c_str(), mode, mLabel.c_str())) {
        SearchEvents();
        for (auto& node : mNodes) {
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
        onClicked.Notify(this);
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
void TTreeNode::AddNode(TTreeNode* pNode)
{
    mNodes.push_back(pNode);
}
//-------------------------------------------------------------------------
