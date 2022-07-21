/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "MinSize.h"

namespace nsImGuiWidgets
{
    void TMinSize::SetMinSize(const ImVec2& value)
    {
        mValue = value;
    }

    ImVec2 TMinSize::GetMinSize() const
    {
        return mValue;
    }
}
