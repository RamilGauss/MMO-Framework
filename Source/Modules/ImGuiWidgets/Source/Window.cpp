/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ImGuiWidgets/Include/Window.h"
#include "ImGuiWidgets/Include/Helper.h"
#include "ImGuiWidgets/Include/DockTreeManager.h"

using namespace nsImGuiWidgets;

void TWindow::BeginRender()
{
    BeforeBeginRender();

    ImGui::SetNextWindowSize(GetSize());
    ImGui::SetNextWindowPos(GetPosition(), ImGuiCond_Appearing);

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

    SetPosition(position);
    SetSize(size);
}
//---------------------------------------------------------------------------------------
