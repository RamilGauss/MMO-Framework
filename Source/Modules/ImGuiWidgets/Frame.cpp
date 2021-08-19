/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Frame.h"
#include "Helper.h"

using namespace nsImGuiWidgets;
using namespace nsGraphicEngine;

void TFrame::Push(IRenderable* pWidget)
{
    mChildList.push_back(pWidget);
}
//---------------------------------------------------------------------------------------
void TFrame::Remove(IRenderable* pWidget)
{
    mChildList.remove(pWidget);
}
//---------------------------------------------------------------------------------------
void TFrame::Clear()
{
    mChildList.clear();
}
//---------------------------------------------------------------------------------------
void TFrame::BeginRender()
{
    ImGui::SetCursorPos(mPos);
    ImGui::BeginChildFrame(mId, mSize);
}
//---------------------------------------------------------------------------------------
void TFrame::EndRender()
{
    ImGui::EndChildFrame();
}
//---------------------------------------------------------------------------------------
void TFrame::RenderInheritance()
{
    auto oldFocus = mIsFocused;

    if (ImGui::IsWindowFocused()) {
        mIsFocused = true;
    } else {
        mIsFocused = false;
    }
    if (oldFocus != mIsFocused) {
        mFocusCB.Notify(mIsFocused);
    }
    if (mIsFocused) {
        SearchInputEvents();
    }

    for (auto& child : mChildList) {
        child->Render();
    }
}
//---------------------------------------------------------------------------------------
bool TFrame::IsFocused()
{
    return mIsFocused;
}
//---------------------------------------------------------------------------------------
void TFrame::SearchInputEvents()
{
    auto inputContainer = TWidget::GetInputContainer();
    for (auto& keyEvent : inputContainer->keyEvents) {

    }
}
//---------------------------------------------------------------------------------------
