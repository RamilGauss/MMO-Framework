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
    BeforeBeginRender();

    auto oldIsShown = IsShown();

    if (mLastIsShown != oldIsShown) {
        ImGui::OpenPopup(mTitle.c_str());
    }

    mLastIsShown = oldIsShown;

    ImGui::SetNextWindowSize(GetSize());
    ImGui::SetNextWindowPos(GetPos(), ImGuiCond_Appearing);

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

    SetPos(position);
    SetSize(size);
}
//---------------------------------------------------------------------------------------
