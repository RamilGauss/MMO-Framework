/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Widget.h"

#include <functional>

namespace nsImGuiWidgets
{
    class DllExport TLabel : public TWidget
    {
        std::string mText;
    public:
        TLabel(const std::string& name);

        void SetText(const char* s);
        void AppendText(const char* s);
    protected:
        void RenderInheritance() override final;
    };
}
