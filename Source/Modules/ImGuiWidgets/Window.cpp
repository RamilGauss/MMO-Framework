/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Window.h"

using namespace nsImGuiWidgets;

TWindow::TWindow(const std::string& name) : TWidget(name) 
{
}
//---------------------------------------------------------------------------------------
void TWindow::PushWidget(TWidget* pWidget)
{
    mChildList.push_back(pWidget);
}
//---------------------------------------------------------------------------------------
void TWindow::ClearWidgets()
{
    mChildList.clear();
}
//---------------------------------------------------------------------------------------
void TWindow::RenderInheritance()
{
    ImGui::Begin(mName.c_str(), &mIsShown);

    for (auto& child : mChildList) {
        child->Render();
    }

    ImGui::End();
}
//---------------------------------------------------------------------------------------