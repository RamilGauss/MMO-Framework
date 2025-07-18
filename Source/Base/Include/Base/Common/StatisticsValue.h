/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <math.h>
#include <queue>

#include "Base/Common/TypeDef.h"

class DllExport TStatisticsValue
{
    std::queue<double> mQueue;

    double mSumma = 0;
public:

    template <typename T>
    void Add(const T& t);

    template <typename T>
    void Exchange(const T& t);

    int GetCount() const;
    double GetAverage() const;

    void Clear();
};

template <typename T>
void TStatisticsValue::Add(const T& t)
{
    mQueue.push(t);
    mSumma += t;
}

template <typename T>
void TStatisticsValue::Exchange(const T& t)
{
    if (mQueue.size() > 0) {
        auto popedValue = mQueue.front();
        mQueue.pop();
        mSumma -= popedValue;
    }

    mQueue.push(t);
    mSumma += t;
}
