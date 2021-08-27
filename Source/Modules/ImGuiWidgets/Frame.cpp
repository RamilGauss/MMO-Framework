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

void TFrame::BeginRender()
{
    ImGui::SetCursorPos(mPos);
    ImGui::BeginChildFrame(mId, mSize);

    mScreenPos = ImGui::GetCursorScreenPos();
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

    for (auto& child : mWidgets) {
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
    for (auto& event : inputContainer->keyEvents) {
        mKeyCB.Notify(event);
    }
    for (auto& event : inputContainer->mouseButtonEvents) {
        mMouseClickCB.Notify(event);
    }
    for (auto& event : inputContainer->mouseMotionEvents) {
        mMouseMoveCB.Notify(event);
    }
    for (auto& event : inputContainer->mouseWheelEvents) {
        mMouseWheelCB.Notify(event);
    }
}
//---------------------------------------------------------------------------------------
TWidget* TFrame::GetUnderMouseChild(const ImVec2& mousePos)
{
    auto size = GetSize();
    if (!InRect(mScreenPos, size, mousePos)) {
        return nullptr;
    }

    for (auto& child : mWidgets) {
        switch (child->GetSubType()) {
            case SubType::UNIT:
            case SubType::FRAME:
            {
                auto childPos = ((TUnit*) child)->GetPos() + mScreenPos;
                auto childSize = ((TUnit*) child)->GetSize();
                if (InRect(childPos, childSize, mousePos)) {
                    return child;
                }
            }
            break;
            case SubType::WIDGET:
            case SubType::NODE:
                break;
        }
    }

    return this;
}
//---------------------------------------------------------------------------------------
TWidget::SubType TFrame::GetSubType() const
{
    return SubType::FRAME;
}
//---------------------------------------------------------------------------------------
