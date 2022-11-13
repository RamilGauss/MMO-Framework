/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "InputDoubleValue.h"

namespace nsImGuiWidgets
{
    void TInputDoubleValue::SetMinValue(double value)
    {
        mMinValue = value;
    }
    //------------------------------------------------------------------------------------
    void TInputDoubleValue::SetMaxValue(double value)
    {
        mMaxValue = value;
    }
    //------------------------------------------------------------------------------------
    void TInputDoubleValue::SetValue(double value)
    {
        mValue = value;
    }
    //------------------------------------------------------------------------------------
    void TInputDoubleValue::SetStep(double value)
    {
        mStep = value;
    }
    //------------------------------------------------------------------------------------
    void TInputDoubleValue::SetStepFast(int value)
    {
        mStepFast = value;
    }
    //------------------------------------------------------------------------------------
    double TInputDoubleValue::GetMinValue() const
    {
        return mMinValue;
    }
    //------------------------------------------------------------------------------------
    double TInputDoubleValue::GetMaxValue() const
    {
        return mMaxValue;
    }
    //------------------------------------------------------------------------------------
    double TInputDoubleValue::GetValue() const
    {
        return mValue;
    }
    //------------------------------------------------------------------------------------
    double TInputDoubleValue::GetStep() const
    {
        return mStep;
    }
    //------------------------------------------------------------------------------------
    int TInputDoubleValue::GetStepFast() const
    {
        return mStepFast;
    }
    //------------------------------------------------------------------------------------
}
