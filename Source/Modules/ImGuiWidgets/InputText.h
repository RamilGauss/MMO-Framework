/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Unit.h"

namespace nsImGuiWidgets
{
    class DllExport TInputText : public TUnit
    {
    public:
    protected:
        static const size_t SIZE = 512;
        char mValue[SIZE] = {0};

        void RenderInheritance() override final;
    };
}
