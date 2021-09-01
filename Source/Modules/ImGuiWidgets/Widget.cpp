/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Widget.h"

using namespace nsImGuiWidgets;
using namespace nsGraphicEngine;

ImGuiID TWidget::mLastId = 0;
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
TWidget::TWidget()
{
    mLastId++;
    mId = mLastId;
}
//------------------------------------------------------------------------
TWidget::SubType TWidget::GetSubType() const
{
    return SubType::WIDGET;
}
//------------------------------------------------------------------------
