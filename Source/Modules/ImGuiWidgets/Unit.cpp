/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Unit.h"

using namespace nsImGuiWidgets;
using namespace nsGraphicEngine;

bool TUnit::IsShown()
{
    return mIsShown;
}
//------------------------------------------------------------------------
void TUnit::SetShow(bool value)
{
    mIsShown = value;
}
//------------------------------------------------------------------------
void TUnit::Show()
{
    SetShow(true);
}
//------------------------------------------------------------------------
void TUnit::Hide()
{
    SetShow(false);
}
//------------------------------------------------------------------------
const ImVec2* TUnit::GetPos()
{
    return &mPos;
}
//------------------------------------------------------------------------
const ImVec2* TUnit::GetSize()
{
    return &mSize;
}
//------------------------------------------------------------------------
void TUnit::SetPos(const ImVec2& newPos)
{
    mPos = newPos;
}
//------------------------------------------------------------------------
void TUnit::SetSize(const ImVec2& newSize)
{
    mSize = newSize;
}
//------------------------------------------------------------------------
void TUnit::Render()
{
    if (!mIsShown) {
        return;
    }

    BeginRender();
    RenderInheritance();
    EndRender();
}
//------------------------------------------------------------------------
void TUnit::BeginRender()
{
    ImGui::SetCursorPos(mPos);
}
//------------------------------------------------------------------------
void TUnit::EndRender()
{

}
//------------------------------------------------------------------------