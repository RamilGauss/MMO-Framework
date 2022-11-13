/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "InputDouble.h"

using namespace nsImGuiWidgets;

void TInputDouble::RenderInheritance()
{
    auto value = GetValue();

    if (ImGui::InputDouble(mTitle.c_str(), &value, GetStep(), GetStepFast())) {
        SetValue(value);
        mOnChangeCB.Notify(this);
    }
}
//------------------------------------------------------------------------------------
