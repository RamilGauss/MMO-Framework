/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <atomic>

#include "TypeDef.h"

namespace nsBase
{
    class DllExport TProgressValue
    {
        std::atomic_int mTotal = 1;
        std::atomic_int mValue = 0;

    public:
        void Setup(int total);

        float GetProgress() const;
        bool IsCompleted() const;

        void Increment(int value = 1);
    };
}
