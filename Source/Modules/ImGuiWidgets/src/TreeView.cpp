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
    pNode->SetTreeView(this);
    pNode->mOnEndEditEventCB.Register(this, [&](TTreeNode* p, const std::string& newTitle) { mOnEndEditEventCB.Notify(p, newTitle); });

    auto foundNode = FoundNode(pNode->mStrId);
    if (foundNode) {
        return;
    }
    pNode->mOnSelectionCB.Register(this, &TTreeView::OnSelection);
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

    pNode->mOnEndEditEventCB.Unregister(this);
    pNode->mOnSelectionCB.Unregister(this);

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

    mOnSelectionEventCB.Notify(mSelectedNode);
}
//---------------------------------------------------------------------------------------
TTreeNode* TTreeView::GetSelectedNode() const
{
    return mSelectedNode;
}
//---------------------------------------------------------------------------------------
TWidget* TTreeView::GetChildByGlobalPos(const ImVec2& mousePos)
{
    auto size = GetSize();
    auto globalPos = GetGlobalPos();
    if (!InRect(globalPos, size, mousePos)) {
        return nullptr;
    }

    for (auto& node : mAllNodes) {
        if (!node->IsShown()) {
            continue;
        }

        size = node->GetSize();
        globalPos = node->GetGlobalPos();
        if (InRect(globalPos, size, mousePos)) {
            return node;
        }
    }
    return this;
}
//---------------------------------------------------------------------------------------
void TTreeView::BeginRender()
{
    for (auto& node : mAllNodes) {
        node->Hide();
    }

    TFrame::BeginRender();
}
//---------------------------------------------------------------------------------------
const std::list<TTreeNode*>* TTreeView::GetAllNodes() const
{
    return &mAllNodes;
}
//---------------------------------------------------------------------------------------
void TTreeView::BeginEdit(TTreeNode* pNode)
{
    if (pNode == nullptr) {
        pNode = GetSelectedNode();
    }
    if (pNode == nullptr) {
        mOnEndEditEventCB.Notify(nullptr, "");
        return;
    }

    pNode->SetEdit(true);
}
//---------------------------------------------------------------------------------------
void TTreeView::ContinueDrag(bool result)
{

}
//---------------------------------------------------------------------------------------
void TTreeView::ContinueDrop(bool result)
{

}
//---------------------------------------------------------------------------------------