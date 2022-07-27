/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Spacing.h"

namespace nsImGuiWidgets
{
    void TSpacing::SetSpacing(int value)
    {
        mSpacing = value;
    }
    //------------------------------------------------------------------------------
    int TSpacing::GetSpacing() const
    {
        return mSpacing;
    }
    //------------------------------------------------------------------------------
}
