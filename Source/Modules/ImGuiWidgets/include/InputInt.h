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
    class DllExport TInputInt : public TUnit
    {
    public:
        using TCallback = TCallbackPool<TInputInt*>;

        TCallback mOnChangeCB;

        void SetValue(int value);
        void SetStep(int value);
        void SetStepFast(int value);

        int GetValue() const;
        int GetStep() const;
        int GetStepFast() const;
    protected:
        int mValue = 0;
        int mStep = 1;
        int mStepFast = 100;

        void RenderInheritance() override final;
    };
}
