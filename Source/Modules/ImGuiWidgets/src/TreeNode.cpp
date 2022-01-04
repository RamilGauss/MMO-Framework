/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TreeNode.h"
#include "TreeView.h"
#include "Helper.h"

#include <imgui_internal.h>

using namespace nsImGuiWidgets;
using namespace std::placeholders;

void TTreeNode::SetTexture(void* textureId, int width, int height)
{
    mTextureId = textureId;
    mWidth = width;
    mHeight = height;
}
//-------------------------------------------------------------------------
TTreeNode::TTreeNode()
{
    mInputText.mOnTextEditEndsCB.Register(this, [&](TInputText* inputText)
    {
        if (!mEditProcessong) {
            return;
        }
        EndEditing();
    });

    mInputText.mFocusCB.Register(this, [&](bool isFocused)
    {
        if (isFocused) {
            return;
        }
        if (!mEditProcessong) {
            return;
        }
        EndEditing();
    });
}
//-------------------------------------------------------------------------
TTreeNode::~TTreeNode()
{
    mInputText.mOnTextEditEndsCB.Unregister(this);
    mInputText.mFocusCB.Unregister(this);
}
//-------------------------------------------------------------------------
void TTreeNode::EndEditing()
{
    mOnEndEditEventCB.Notify(this, mInputText.GetText());
    mEditProcessong = false;
}
//-------------------------------------------------------------------------
void TTreeNode::Render()
{
    Show();

    ImGuiTreeNodeFlags mode = ImGuiTreeNodeFlags_None | ImGuiTreeNodeFlags_OpenOnArrow;
    if (mWidgets.size() == 0) {
        mode |= ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_SpanAvailWidth;
    }
    if (mSelected) {
        mode |= ImGuiTreeNodeFlags_Selected;
    }

    if (mEditProcessong) {
        mInputText.SetSize(GetSize());

        auto& style = ImGui::GetStyle();
        ImVec2 indent = {style.IndentSpacing, 0};

        mInputText.SetPos(GetGlobalPos() - mTreeView->GetGlobalPos() + indent - style.FramePadding);

        if (mBeginEditProcessing) {
            ImGui::SetKeyboardFocusHere();
        }
        mBeginEditProcessing = false;

        if (mIsOpen && mWidgets.size() > 0) {
            ImGui::TreePush(this);
            mInputText.Render();
            for (auto& node : mWidgets) {
                node->Render();
            }
            ImGui::TreePop();
        } else {
            mInputText.Render();
        }
    } else {
        if (ImGui::TreeNodeEx(mStrId.c_str(), mode, "")) {
            RenderContent();
            
            SearchEvents();
            for (auto& node : mWidgets) {
                node->Render();
            }
            ImGui::TreePop();
            mIsOpen = true;
        } else {
            RenderContent();

            SearchEvents();
            mIsOpen = false;
        }
    }
}
//-------------------------------------------------------------------------
void TTreeNode::SearchEvents()
{
    auto parentGlobalPos = mParent->GetGlobalPos();
    auto pos = ImGui::GetItemRectMin() - parentGlobalPos;
    auto size = ImGui::GetItemRectSize() + ImGui::GetStyle().ItemInnerSpacing;

    SetPos(pos);
    SetSize(size);

    if (ImGui::IsItemClicked()) {
        mOnLeftClickCB.Notify(this);
    }
    if (ImGui::IsItemFocused()) {
        if (!mSelected) {
            mSelected = true;
            mOnSelectionCB.Notify(this);
        }
    } else {
        mSelected = false;
    }
}
//-------------------------------------------------------------------------
void TTreeNode::SetEdit(bool value)
{
    mEditProcessong = value;
    mBeginEditProcessing = true;
    mInputText.SetText(GetTitle());
    mInputText.SetTitle("");
}
//-------------------------------------------------------------------------
void TTreeNode::SetTreeView(TTreeView* treeView)
{
    mTreeView = treeView;
}
//-------------------------------------------------------------------------
TTreeView* TTreeNode::GetTreeView() const
{
    return mTreeView;
}
//-------------------------------------------------------------------------
void TTreeNode::RenderContent()
{
    ImGui::SameLine();
    if (mTextureId != nullptr) {
        ImGui::Image(mTextureId, ImVec2(mWidth, mHeight));
        ImGui::SameLine();
    }

    ImGui::Text(GetTitle().c_str());
}
//-------------------------------------------------------------------------
