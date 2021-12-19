/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Dialog.h"
#include "Helper.h"
#include "DialogStack.h"

using namespace nsImGuiWidgets;

void TDialog::SetStack(TDialogStack* pDialogStack)
{
    mDialogStack = pDialogStack;
}
//---------------------------------------------------------------------------------------
void TDialog::BeginRender()
{
    auto oldIsShown = IsShown();

    if (mLastIsShown != oldIsShown) {
        ImGui::OpenPopup(mTitle.c_str());
    }

    mLastIsShown = oldIsShown;

    mOldSize = mSize;
    mOldPos = mPos;

    ImGui::SetNextWindowSize(mSize);
    ImGui::SetNextWindowPos(mPos, ImGuiCond_Appearing);

    ImGui::BeginPopupModal(mTitle.c_str(), &mIsShown, ImGuiWindowFlags_MenuBar);

    if (oldIsShown != mIsShown) {
        mOnShowCB.Notify(mIsShown);
    }
}
//---------------------------------------------------------------------------------------
void TDialog::EndRender()
{
    if (mDialogStack != nullptr) {
        mDialogStack->RenderNextDialog(this);
    }

    mPos = ImGui::GetWindowPos();
    mSize = ImGui::GetWindowSize();
    
    if (mIsShown) {
        ImGui::EndPopup();
    }

    if (mOldSize != mSize) {
        mOnSizeCB.Notify(&mSize);
    } else {
        mSize = mOldSize;
    }

    if (mOldPos != mPos) {
        mOnPosCB.Notify(&mPos);
    } else {
        mPos = mOldPos;
    }
}
//---------------------------------------------------------------------------------------
