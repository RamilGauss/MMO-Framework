/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Widget.h"

namespace nsImGuiWidgets
{
    class DllExport TWidgetContainer
    {
    public:
        void Add(TWidget* p);
        void Replace(TWidget* p);
        void Clear();

    protected:
        std::list<TWidget*> mWidgets;
    };
}
