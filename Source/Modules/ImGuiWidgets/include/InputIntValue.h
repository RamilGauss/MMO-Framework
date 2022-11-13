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
    class DllExport TInputIntValue
    {
    public:
        virtual void SetMinValue(int value);
        virtual void SetMaxValue(int value);

        virtual void SetValue(int value);
        virtual void SetStep(int value);
        virtual void SetStepFast(int value);

        virtual int GetMinValue() const;
        virtual int GetMaxValue() const;

        virtual int GetValue() const;
        virtual int GetStep() const;
        virtual int GetStepFast() const;
    private:
        int mMinValue = 0;
        int mMaxValue = 100;

        int mValue = 0;
        int mStep = 1;
        int mStepFast = 100;
    };
}
