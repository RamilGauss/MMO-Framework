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
