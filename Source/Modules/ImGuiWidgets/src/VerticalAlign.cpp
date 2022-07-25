/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "VerticalAlign.h"

namespace nsImGuiWidgets
{
    void TVerticalAlign::SetAlign(Type value)
    {
        mValue = value;
    }
    //------------------------------------------------------------------------------
    TVerticalAlign::Type TVerticalAlign::GetAlign() const
    {
        return mValue;
    }
    //------------------------------------------------------------------------------
}
