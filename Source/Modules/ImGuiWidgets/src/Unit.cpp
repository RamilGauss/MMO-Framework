/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Unit.h"

#include <imgui_internal.h>

using namespace nsImGuiWidgets;
using namespace nsGraphicEngine;

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
    ImGui::SetCursorPos(GetPos());

    if (GetSubType() == SubType::UNIT) {
        ImGui::PushID(GetId());
    }
}
//------------------------------------------------------------------------
void TUnit::EndRender()
{
    if (GetSubType() != SubType::UNIT) {
        return;
    }

    mIdFromWindow = ImGui::GetCurrentWindow()->GetID(GetTitle().c_str());

    ImGui::PopID();

    auto activeId = ImGui::GetActiveID();
    auto focusId = ImGui::GetFocusID();
    auto IsfreshFocused = (activeId == mIdFromWindow);
    if (IsfreshFocused != IsFocused()) {
        SetIsFocused(IsfreshFocused);
        mFocusCB.Notify(IsFocused());
    }
}
//------------------------------------------------------------------------
TWidget::SubType TUnit::GetSubType() const
{
    return SubType::UNIT;
}
//------------------------------------------------------------------------
ImVec2 TUnit::CalculateMinSizeForAnchoredUnit() const
{
    ImVec2 unitMinSize = GetMinSize();
    if (GetLeft().isUsed && GetRight().isUsed) {
        unitMinSize.x = GetMinSize().x + GetLeft().offset + GetRight().offset;
    } else if (GetRight().isUsed) {
        unitMinSize.x = GetMinSize().x + GetRight().offset;
    }

    if (GetTop().isUsed && GetBottom().isUsed) {
        unitMinSize.y = GetMinSize().y + GetTop().offset + GetBottom().offset;
    } else if (GetBottom().isUsed) {
        unitMinSize.y = GetMinSize().y + GetBottom().offset;
    }

    return unitMinSize;
}
//------------------------------------------------------------------------
