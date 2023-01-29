/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "CheckBoxValue.h"

using namespace nsImGuiWidgets;

bool TCheckBoxValue::GetCheckBoxValue()
{
    return mValue;
}
//---------------------------------------------------------------------------------
void TCheckBoxValue::SetCheckBoxValue(bool value)
{
    mValue = value;
}
//---------------------------------------------------------------------------------