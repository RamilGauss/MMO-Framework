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
    class DllExport TMenuSeparator : public TWidget
    {
    public:
        TMenuSeparator(const std::string& menu, const std::string& name);
    protected:
        std::string mMenu;

        bool mSelected = false;
        bool mEnabled = true;

        void RenderInheritance() override final;
    };
}
