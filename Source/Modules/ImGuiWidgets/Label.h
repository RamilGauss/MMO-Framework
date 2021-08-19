/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Unit.h"

#include <functional>

namespace nsImGuiWidgets
{
    class DllExport TLabel : public TUnit
    {
        std::string mText;
    public:
        void SetText(const char* s);
        void AppendText(const char* s);
        int GetTextLength();
    protected:
        void RenderInheritance() override final;
    };
}
