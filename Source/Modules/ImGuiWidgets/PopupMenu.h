/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Widget.h"
#include "WidgetContainer.h"

namespace nsImGuiWidgets
{
    class TPopupNode;
    class DllExport TPopupMenu : public TWidget, public TWidgetContainer
    {
    public:
        void Open();
    protected:
        void Render() override final;
    };
}
