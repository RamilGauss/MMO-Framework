/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Window.h"
#include "Helper.h"
#include "DockTreeManager.h"

using namespace nsImGuiWidgets;

void TWindow::BeginRender()
{
    ImGui::SetNextWindowSize(GetSize());
    ImGui::SetNextWindowPos(GetPos(), ImGuiCond_Appearing);

    auto oldIsShown = mIsShown;
    ImGui::Begin(mTitle.c_str(), &mIsShown);

    if (oldIsShown != mIsShown) {
        mOnShowCB.Notify(mIsShown);
    }
}
//---------------------------------------------------------------------------------------
void TWindow::EndRender()
{
    auto position = ImGui::GetWindowPos();
    auto size = ImGui::GetWindowSize();

    ImGui::End();

    SetPos(position);
    SetSize(size);
}
//---------------------------------------------------------------------------------------
