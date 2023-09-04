/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <atomic>
#include <list>

#include "TypeDef.h"

namespace nsBase
{
    class DllExport TProgressValue
    {
        std::atomic_int mTotal = 0;
        std::atomic_int mValue = 0;
        std::atomic_int mStep = 0;

    public:
        TProgressValue();
        TProgressValue(const TProgressValue& other);

        TProgressValue operator = (const TProgressValue& other);

        float GetProgress() const;
        bool IsCompleted() const;

        void IncrementValue(int value = 1);
        void IncrementTotal(int total = 1);

        int GetValue() const;
        int GetTotal() const;
        int GetRemain() const;

        int GetSteppedRemain() const;
        int GetStep() const;

        void SetTotal(int total);
        void SetStep(int step);

        static TProgressValue Accumulate(const std::list<TProgressValue> list);
    };
}
