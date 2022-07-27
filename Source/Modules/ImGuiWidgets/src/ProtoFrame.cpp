/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ProtoFrame.h"
#include "Helper.h"

using namespace nsImGuiWidgets;
using namespace nsGraphicEngine;

TProtoFrame::TProtoFrame() : TWidgetContainer(this)
{

}
//---------------------------------------------------------------------------------------
void TProtoFrame::BeginRender()
{
    ImGui::SetCursorPos(GetPos());

    ImGui::BeginChildFrame(GetId(), GetSize());
}
//---------------------------------------------------------------------------------------
void TProtoFrame::EndRender()
{
    ImGui::EndChildFrame();
}
//---------------------------------------------------------------------------------------
void TProtoFrame::RenderInheritance()
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
void TProtoFrame::SearchInputEvents()
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
TWidget* TProtoFrame::GetChildByGlobalPos(const ImVec2& mousePos)
{
    auto pos = GetGlobalPos();
    auto size = GetSize();
    if (!InRect(pos, size, mousePos)) {
        return nullptr;
    }

    for (auto& child : mWidgets) {
        switch (child->GetSubType()) {
        case SubType::UNIT:
        case SubType::PROTO_FRAME:
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
TWidget::SubType TProtoFrame::GetSubType() const
{
    return SubType::PROTO_FRAME;
}
//---------------------------------------------------------------------------------------
ImVec2 TProtoFrame::GetChildMinSize() const
{
    return GetMinSize();
}
//---------------------------------------------------------------------------------------
ImVec2 TProtoFrame::GetChildMaxSize() const
{
    return GetMaxSize();
}
//---------------------------------------------------------------------------------------
