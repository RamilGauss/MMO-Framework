/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "InputInt.h"

using namespace nsImGuiWidgets;

void TInputInt::RenderInheritance()
{
    if (ImGui::InputInt(mTitle.c_str(), &mValue, mStep, mStepFast)) {
        mOnChangeCB.Notify(this);
    }
}
//------------------------------------------------------------------------------------
void TInputInt::SetValue(int value)
{
    mValue = value;
}
//------------------------------------------------------------------------------------
void TInputInt::SetStep(int value)
{
    mStep = value;
}
//------------------------------------------------------------------------------------
void TInputInt::SetStepFast(int value)
{
    mStepFast = value;
}
//------------------------------------------------------------------------------------
int TInputInt::GetValue() const
{
    return mValue;
}
//------------------------------------------------------------------------------------
int TInputInt::GetStep() const
{
    return mStep;
}
//------------------------------------------------------------------------------------
int TInputInt::GetStepFast() const
{
    return mStepFast;
}
//------------------------------------------------------------------------------------
