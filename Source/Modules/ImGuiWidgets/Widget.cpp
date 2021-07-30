/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Widget.h"

using namespace nsImGuiWidgets;

TWidget::TWidget(const std::string& name)
{
    mName = name;
}
//------------------------------------------------------------------------
const char* TWidget::GetName()
{
    return mName.c_str();
}
//------------------------------------------------------------------------
bool TWidget::IsShown()
{
    return mIsShown;
}
//------------------------------------------------------------------------
void TWidget::SetShow(bool value)
{
    mIsShown = value;
}
//------------------------------------------------------------------------
void TWidget::Show()
{
    SetShow(true);

}
//------------------------------------------------------------------------
void TWidget::Hide()
{
    SetShow(false);
}
//------------------------------------------------------------------------
const ImVec2* TWidget::GetPos()
{
    return &mPos;
}
//------------------------------------------------------------------------
const ImVec2* TWidget::GetSize()
{
    return &mSize;
}
//------------------------------------------------------------------------
void TWidget::Render()
{
    if (!mIsShown) {
        return;
    }

    RenderInheritance();

    mSize = ImGui::GetWindowSize();
    mPos = ImGui::GetWindowPos();
}
//------------------------------------------------------------------------