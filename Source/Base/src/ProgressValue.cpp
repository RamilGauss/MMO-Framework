/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ProgressValue.h"

namespace nsBase
{
    TProgressValue::TProgressValue()
    {

    }
    //-----------------------------------------------------------------------------------
    TProgressValue::TProgressValue(const TProgressValue& other)
    {
        mTotal.store(other.mTotal);
        mValue.store(other.mValue);
    }
    //-----------------------------------------------------------------------------------
    TProgressValue TProgressValue::operator = (const TProgressValue& other)
    {
        mTotal.store(other.mTotal);
        mValue.store(other.mValue);

        return *this;
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
    void TProgressValue::IncrementValue(int value)
    {
        mValue += value;
    }
    //-----------------------------------------------------------------------------------
    void TProgressValue::IncrementTotal(int total)
    {
        mTotal += total;
    }
    //-----------------------------------------------------------------------------------
    int TProgressValue::GetValue() const
    {
        return mValue;
    }
    //-----------------------------------------------------------------------------------
    int TProgressValue::GetTotal() const
    {
        return mTotal;
    }
    //-----------------------------------------------------------------------------------
    TProgressValue TProgressValue::Accumulate(const std::list<TProgressValue> list)
    {
        TProgressValue acc;

        for (auto& pv : list) {
            acc.IncrementValue(pv.GetValue());
            acc.IncrementTotal(pv.GetTotal());
        }

        return acc;
    } 
    //-----------------------------------------------------------------------------------
}
