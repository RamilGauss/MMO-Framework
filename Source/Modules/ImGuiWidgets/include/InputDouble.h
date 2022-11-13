/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Unit.h"
#include "InputDoubleValue.h"

namespace nsImGuiWidgets
{
    class DllExport TInputDouble : public TUnit, public TInputDoubleValue
    {
    public:
        using TCallback = TCallbackPool<TInputDouble*>;

        TCallback mOnChangeCB;
    protected:
        void RenderInheritance() override final;
    };
}
