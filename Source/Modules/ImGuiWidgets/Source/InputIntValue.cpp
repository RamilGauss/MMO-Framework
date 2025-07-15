/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ImGuiWidgets/Include/InputIntValue.h"

namespace nsImGuiWidgets
{
    void TInputIntValue::SetMinValue(int value)
    {
        mMinValue = value;
    }
    //------------------------------------------------------------------------------------
    void TInputIntValue::SetMaxValue(int value)
    {
        mMaxValue = value;
    }
    //------------------------------------------------------------------------------------
    void TInputIntValue::SetValue(int value)
    {
        mValue = value;
    }
    //------------------------------------------------------------------------------------
    void TInputIntValue::SetStep(int value)
    {
        mStep = value;
    }
    //------------------------------------------------------------------------------------
    void TInputIntValue::SetStepFast(int value)
    {
        mStepFast = value;
    }
    //------------------------------------------------------------------------------------
    int TInputIntValue::GetMinValue() const
    {
        return mMinValue;
    }
    //------------------------------------------------------------------------------------
    int TInputIntValue::GetMaxValue() const
    {
        return mMaxValue;
    }
    //------------------------------------------------------------------------------------
    int TInputIntValue::GetValue() const
    {
        return mValue;
    }
    //------------------------------------------------------------------------------------
    int TInputIntValue::GetStep() const
    {
        return mStep;
    }
    //------------------------------------------------------------------------------------
    int TInputIntValue::GetStepFast() const
    {
        return mStepFast;
    }
    //------------------------------------------------------------------------------------
}
