/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "CheckBox.h"

using namespace nsImGuiWidgets;

bool TCheckBox::GetValue()
{
    return mValue;
}
//----------------------------------------------------------------------------------------
void TCheckBox::SetValue(bool value)
{
    mValue = value;
}
//----------------------------------------------------------------------------------------
void TCheckBox::RenderInheritance()
{
    if (ImGui::Checkbox(mTitle.c_str(), &mValue)) {
        mOnCheckChangeCB.Notify(mValue);
    }
}
//----------------------------------------------------------------------------------------