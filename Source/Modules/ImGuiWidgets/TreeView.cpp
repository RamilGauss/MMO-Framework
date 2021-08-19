/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TreeView.h"
#include "TreeNode.h"

using namespace nsImGuiWidgets;

void TTreeView::AddNode(TTreeNode* pNode)
{
    auto foundNode = FoundNode(pNode->mId);
    if (foundNode) {
        return;
    }
    pNode->onSelection.Register(&TTreeView::OnSelection, this);
    pNode->onClicked.Register(&TTreeView::OnClicked, this);
    mAllNodes.push_back(pNode);
    if (pNode->mParentId == "") {
        Push(pNode);
    } else {
        auto pParentNode = FoundNode(pNode->mParentId);
        pParentNode->AddNode(pNode);
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
    Remove(pNode);

    std::remove_if(mAllNodes.begin(), mAllNodes.end(),
        [this, &id](const TTreeNode* node) { return id == node->mId; });
}
//---------------------------------------------------------------------------------------
TTreeNode* TTreeView::FoundNode(const std::string& id)
{
    auto fit = std::find_if(mAllNodes.begin(), mAllNodes.end(),
        [this, &id](const TTreeNode* node) { return id == node->mId; });
    if (fit == mAllNodes.end()) {
        return nullptr;
    }
    return *fit;
}
//---------------------------------------------------------------------------------------
void TTreeView::OnSelection(TTreeNode* pSelectedNode)
{
    mSelectedNode = pSelectedNode;

    onSelectionEvent.Notify(mSelectedNode);
}
//---------------------------------------------------------------------------------------
void TTreeView::OnClicked(TTreeNode* pNode)
{
    TClickEvent clickEvent;
    clickEvent.pNode = pNode;
    onClickEvent.Notify(clickEvent);
}
//---------------------------------------------------------------------------------------
TTreeNode* TTreeView::GetSelectedNode() const
{
    return mSelectedNode;
}
//---------------------------------------------------------------------------------------