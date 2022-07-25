/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "HorizontalAlign.h"

namespace nsImGuiWidgets
{
    void THorizontalAlign::SetAlign(Type value)
    {
        mValue = value;
    }
    //------------------------------------------------------------------------------
    THorizontalAlign::Type THorizontalAlign::GetAlign() const
    {
        return mValue;
    }
    //------------------------------------------------------------------------------
}
