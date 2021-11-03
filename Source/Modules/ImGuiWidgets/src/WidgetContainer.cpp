/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "WidgetContainer.h"

using namespace nsImGuiWidgets;

TWidgetContainer::TWidgetContainer(TWidget* parent)
{
    mWidgetParent = parent;
}
//------------------------------------------------------------------------
void TWidgetContainer::Add(TWidget* p)
{
    mWidgets.push_back(p);

    p->SetParent(mWidgetParent);
}
//------------------------------------------------------------------------
void TWidgetContainer::Replace(TWidget* p)
{
    mWidgets.remove(p);

    p->SetParent(nullptr);
}
//------------------------------------------------------------------------
void TWidgetContainer::Clear()
{
    for (auto& widget : mWidgets) {
        widget->SetParent(nullptr);
    }
    mWidgets.clear();
}
//------------------------------------------------------------------------
const std::list<TWidget*>* TWidgetContainer::GetWidgets() const
{
    return &mWidgets;
}
//------------------------------------------------------------------------
