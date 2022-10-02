/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "StatisticsValue.h"

int TStatisticsValue::GetCount() const
{
    return mQueue.size();
}
//--------------------------------------------------------------------------
double TStatisticsValue::GetAverage() const
{
    if (mQueue.size() == 0) {
        return 0;
    }

    return mSumma / mQueue.size();
}
//--------------------------------------------------------------------------
void TStatisticsValue::Clear()
{
    std::queue<double> empty;
    std::swap(mQueue, empty);
}
//--------------------------------------------------------------------------


