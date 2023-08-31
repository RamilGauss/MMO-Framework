/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ProgressValue.h"

namespace nsBase
{
    void TProgressValue::Setup(int total)
    {
        mTotal = total;
    }
    //-----------------------------------------------------------------------------------
    float TProgressValue::GetProgress() const
    {
        if (mTotal == 0) {
            return 1.0f;
        }

        return (mValue * 1.0f / mTotal);
    }
    //-----------------------------------------------------------------------------------
    bool TProgressValue::IsCompleted() const
    {
        return (mTotal == mValue);
    }
    //-----------------------------------------------------------------------------------
    void TProgressValue::Increment(int value)
    {
        mValue += value;
    }
    //-----------------------------------------------------------------------------------
}
