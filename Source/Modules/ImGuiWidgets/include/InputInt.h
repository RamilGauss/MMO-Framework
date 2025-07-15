/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ImGuiWidgets/Include/Unit.h"
#include "ImGuiWidgets/Include/InputIntValue.h"

namespace nsImGuiWidgets
{
    class DllExport TInputInt : public TUnit, public TInputIntValue
    {
    public:
        using TCallback = TCallbackPool<TInputInt*>;

        TCallback mOnChangeCB;

    protected:
        void RenderInheritance() override final;
    };
}
