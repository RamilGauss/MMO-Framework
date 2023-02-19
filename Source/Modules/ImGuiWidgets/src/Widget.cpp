/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Widget.h"
#include "Helper.h"

using namespace nsImGuiWidgets;
using namespace nsGraphicEngine;

TKeyMouseEventContainer* TWidget::mKeyMouseInputContainer = nullptr;

void TWidget::SetInputContainer(TKeyMouseEventContainer* keyMouseContainer)
{
    mKeyMouseInputContainer = keyMouseContainer;
}
//--------------------------------------------------------------------------------
TKeyMouseEventContainer* TWidget::GetInputContainer()
{
    return mKeyMouseInputContainer;
}
//--------------------------------------------------------------------------------
TWidget::SubType TWidget::GetSubType() const
{
    return SubType::WIDGET;
}
//------------------------------------------------------------------------
void TWidget::SetParent(TWidget* parent)
{
    mParent = parent;
}
//------------------------------------------------------------------------
TWidget* TWidget::GetParent() const
{
    return mParent;
}
//------------------------------------------------------------------------
ImVec2 TWidget::GetGlobalPos()
{
    auto p = GetParent();

    auto globalPos = GetPosition();
    while (true) {
        if (!p) {
            break;
        }

        globalPos += p->GetPosition();
        p = p->GetParent();
    }
    return globalPos;
}
//------------------------------------------------------------------------
