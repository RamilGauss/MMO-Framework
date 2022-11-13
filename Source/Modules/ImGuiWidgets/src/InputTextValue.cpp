/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "InputTextValue.h"

namespace nsImGuiWidgets
{
    std::string TInputTextValue::GetText() const
    {
        return mInputTextValue;
    }

    void TInputTextValue::SetText(const std::string& str)
    {
        mInputTextValue = str;
    }
}
