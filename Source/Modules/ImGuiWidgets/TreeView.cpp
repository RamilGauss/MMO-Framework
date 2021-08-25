/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TreeView.h"
#include "TreeNode.h"
#include "Helper.h"

using namespace nsImGuiWidgets;

void TTreeView::AddNode(TTreeNode* pNode)
{
    auto foundNode = FoundNode(pNode->mStrId);
    if (foundNode) {
        return;
    }
    pNode->onSelection.Register(&TTreeView::OnSelection, this);
    mAllNodes.push_back(pNode);
    if (pNode->mParentId == "") {
        Add(pNode);
    } else {
        auto pParentNode = FoundNode(pNode->mParentId);
        pParentNode->Add(pNode);
    }
}
//---------------------------------------------------------------------------------------
TTreeNode* TTreeView::GetNode(const std::string& id)
{
    return FoundNode(id);
}
//---------------------------------------------------------------------------------------
void TTreeView::RemoveNode(const std::string& id)
{
    auto pNode = FoundNode(id);
    //if(pNode->)
    Replace(pNode);

    std::remove_if(mAllNodes.begin(), mAllNodes.end(),
        [this, &id](const TTreeNode* node) { return id == node->mStrId; });
}
//---------------------------------------------------------------------------------------
TTreeNode* TTreeView::FoundNode(const std::string& id)
{
    auto fit = std::find_if(mAllNodes.begin(), mAllNodes.end(),
        [this, &id](const TTreeNode* node) { return id == node->mStrId; });
    if (fit == mAllNodes.end()) {
        return nullptr;
    }
    return *fit;
}
//---------------------------------------------------------------------------------------
void TTreeView::OnSelection(TNode* pSelectedNode)
{
    mSelectedNode = (TTreeNode*)pSelectedNode;

    onSelectionEvent.Notify(mSelectedNode);
}
//---------------------------------------------------------------------------------------
TTreeNode* TTreeView::GetSelectedNode() const
{
    return mSelectedNode;
}
//---------------------------------------------------------------------------------------
TWidget* TTreeView::GetUnderMouseChild(const ImVec2& mousePos)
{
    auto pos = GetPos();
    auto size = GetSize();
    if (!InRect(pos, size, mousePos)) {
        return nullptr;
    }

    return mSelectedNode;
}
//---------------------------------------------------------------------------------------
