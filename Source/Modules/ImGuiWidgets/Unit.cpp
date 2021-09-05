/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Unit.h"

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
    ImGui::SetCursorPos(mPos);
}
//------------------------------------------------------------------------
void TUnit::EndRender()
{

}
//------------------------------------------------------------------------
TWidget::SubType TUnit::GetSubType() const
{
    return SubType::UNIT;
}
//------------------------------------------------------------------------
