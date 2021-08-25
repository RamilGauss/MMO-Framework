/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "WidgetContainer.h"

using namespace nsImGuiWidgets;

void TWidgetContainer::Add(TWidget* p)
{
    mWidgets.push_back(p);
}
//------------------------------------------------------------------------
void TWidgetContainer::Replace(TWidget* p)
{
    mWidgets.remove(p);
}
//------------------------------------------------------------------------
void TWidgetContainer::Clear()
{
    mWidgets.clear();
}
//------------------------------------------------------------------------
