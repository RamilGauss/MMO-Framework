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

TFrame::TFrame() : TWidgetContainer(this)
{

}
//---------------------------------------------------------------------------------------
void TFrame::BeginRender()
{
    ImGui::SetCursorPos(GetPos());

    ImGui::BeginChildFrame(GetId(), GetSize());
}
//---------------------------------------------------------------------------------------
void TFrame::EndRender()
{
    ImGui::EndChildFrame();
}
//---------------------------------------------------------------------------------------
void TFrame::RenderInheritance()
{
    auto oldFocus = IsFocused();
    SetIsFocused(ImGui::IsWindowFocused());

    for (auto& child : mWidgets) {
        child->Render();
    }
    // strict order
    if (oldFocus != IsFocused()) {
        mFocusCB.Notify(IsFocused());
    }
    if (IsFocused()) {
        SearchInputEvents();
    }
}
//---------------------------------------------------------------------------------------
void TFrame::SearchInputEvents()
{
    auto inputContainer = TWidget::GetInputContainer();
    for (auto& event : inputContainer->keyEvents) {
        mOnKeyCB.Notify(event);
    }
    for (auto& event : inputContainer->mouseButtonEvents) {
        mOnMouseClickCB.Notify(event);
    }
    for (auto& event : inputContainer->mouseMotionEvents) {
        mOnMouseMoveCB.Notify(event);
    }
    for (auto& event : inputContainer->mouseWheelEvents) {
        mOnMouseWheelCB.Notify(event);
    }
}
//---------------------------------------------------------------------------------------
TWidget* TFrame::GetChildByGlobalPos(const ImVec2& mousePos)
{
    auto pos = GetGlobalPos();
    auto size = GetSize();
    if (!InRect(pos, size, mousePos)) {
        return nullptr;
    }

    for (auto& child : mWidgets) {
        switch (child->GetSubType()) {
            case SubType::UNIT:
            case SubType::FRAME:
            {
                auto childPos = child->GetGlobalPos();
                auto childSize = child->GetSize();
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
