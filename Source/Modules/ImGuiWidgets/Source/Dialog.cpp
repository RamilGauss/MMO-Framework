/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ImGuiWidgets/Include/Dialog.h"
#include "ImGuiWidgets/Include/Helper.h"
#include "ImGuiWidgets/Include/DialogStack.h"

using namespace nsImGuiWidgets;

void TDialog::SetStack(TDialogStack* pDialogStack)
{
    mDialogStack = pDialogStack;
}
//---------------------------------------------------------------------------------------
void TDialog::BeginRender()
{
    BeforeBeginRender();

    auto oldIsShown = IsShown();

    if (mLastIsShown != oldIsShown) {
        ImGui::OpenPopup(mTitle.c_str());
    }

    mLastIsShown = oldIsShown;

    ImGui::SetNextWindowSize(GetSize());
    ImGui::SetNextWindowPos(GetPosition(), ImGuiCond_Appearing);

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

    auto position = ImGui::GetWindowPos();
    auto size = ImGui::GetWindowSize();
    
    if (mIsShown) {
        ImGui::EndPopup();
    }

    SetPosition(position);
    SetSize(size);
}
//---------------------------------------------------------------------------------------
