/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ComboBoxCurrentIndex.h"

namespace nsImGuiWidgets
{
    int TComboBoxCurrentIndex::GetCurrentIndex() const
    {
        return mCurrentIndex;
    }
    //----------------------------------------------------------------------------------------
    void TComboBoxCurrentIndex::SetCurrentIndex(int value)
    {
        mCurrentIndex = value;
    }
}
