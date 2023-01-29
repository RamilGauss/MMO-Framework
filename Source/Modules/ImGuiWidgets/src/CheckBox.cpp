/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "CheckBox.h"

using namespace nsImGuiWidgets;

void TCheckBox::RenderInheritance()
{
    bool value = GetCheckBoxValue();

    if (ImGui::Checkbox(mTitle.c_str(), &value)) {
        SetCheckBoxValue(value);
        mOnCheckChangeCB.Notify(value);
    }
}
//----------------------------------------------------------------------------------------