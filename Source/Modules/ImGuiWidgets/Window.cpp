/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Window.h"
#include "Helper.h"

using namespace nsImGuiWidgets;

void TWindow::BeginRender()
{
    mOldSize = mSize;
    mOldPos = mPos;

    auto oldIsShown = mIsShown;

    ImGui::SetNextWindowSize(mSize);
    ImGui::SetNextWindowPos(mPos, ImGuiCond_Appearing);

    if (mNeedSetParentDockId) {
        mParentDockId = mNewParentDockId;
        ImGui::SetNextWindowDockID(mParentDockId, ImGuiCond_Once);
    }

    ImGui::Begin(mTitle.c_str(), &mIsShown);
    //ImGui::DockSpace(mId, ImVec2(0,0), ImGuiDockNodeFlags_None | ImGuiDockNodeFlags_KeepAliveOnly);

    if (oldIsShown != mIsShown) {
        mShowCB.Notify(mIsShown);
    }

    if (mNeedSetParentDockId) {
        mNeedSetParentDockId = false;
    } else {

        auto freshIsDocked = ImGui::IsWindowDocked();
        if (freshIsDocked != mIsDocked) {
            mIsDocked = freshIsDocked;
            mParentDockId = ImGui::GetWindowDockID();

            mDockCB.Notify();
        } else if (freshIsDocked) {
            auto freshParentDockId = ImGui::GetWindowDockID();
            if (freshParentDockId != mParentDockId) {
                mParentDockId = freshParentDockId;
                mDockCB.Notify();
            }
        }
    }
}
//---------------------------------------------------------------------------------------
void TWindow::EndRender()
{
    mPos = ImGui::GetWindowPos();
    mSize = ImGui::GetWindowSize();

    ImGui::End();

    if (mOldSize != mSize) {
        mSizeCB.Notify(&mSize);
    } else {
        mSize = mOldSize;
    }

    if (mOldPos != mPos) {
        mPosCB.Notify(&mPos);
    } else {
        mPos = mOldPos;
    }
}
//---------------------------------------------------------------------------------------
ImGuiID TWindow::GetParentDockId() const
{
    return mParentDockId;
}
//---------------------------------------------------------------------------------------
bool TWindow::IsDocked() const
{
    return mIsDocked;
}
//---------------------------------------------------------------------------------------
void TWindow::SetParentDockId(ImGuiID parentId)
{
    mNeedSetParentDockId = true;
    mNewParentDockId = parentId;
}
//---------------------------------------------------------------------------------------
ImGuiID TWindow::GetDockId() const
{
    return mId;
}
//---------------------------------------------------------------------------------------
