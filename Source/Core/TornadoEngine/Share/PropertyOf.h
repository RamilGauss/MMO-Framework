/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "IPropertyOf.h"

namespace nsTornadoEngine
{
    template <typename T>
    struct DllExport TPropertyOf : IPropertyOf
    {
        mutable T* pOwner = nullptr;

        // Helper for assign pOwner via dynamic_cast
        void SetOwner(void* p) const override
        {
            pOwner = static_cast<T*>(p);
        }
    };
}