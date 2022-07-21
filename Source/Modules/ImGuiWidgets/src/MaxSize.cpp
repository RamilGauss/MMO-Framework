/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "MaxSize.h"

namespace nsImGuiWidgets
{
    void TMaxSize::SetMaxSize(const ImVec2& value)
    {
        mValue = value;
    }

    ImVec2 TMaxSize::GetMaxSize() const
    {
        return mValue;
    }
}
