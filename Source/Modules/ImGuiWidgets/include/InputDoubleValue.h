/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

namespace nsImGuiWidgets
{
    class DllExport TInputDoubleValue
    {
    public:
        virtual void SetMinValue(double value);
        virtual void SetMaxValue(double value);

        virtual void SetValue(double value);
        virtual void SetStep(double value);
        virtual void SetStepFast(int value);

        virtual double GetMinValue() const;
        virtual double GetMaxValue() const;

        virtual double GetValue() const;
        virtual double GetStep() const;
        virtual int GetStepFast() const;
    private:
        double mMinValue = 0;
        double mMaxValue = 100;

        double mValue = 0;
        double mStep = 1;
        int mStepFast = 100;
    };
}
