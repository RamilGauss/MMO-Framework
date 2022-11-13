#pragma once

#include "TypeDef.h"

namespace nsTornadoEngine
{
    template <typename T>
    struct DllExport TPropertyOf
    {
#pragma IGNORE_ATTRIBUTE
        mutable T* pOwner = nullptr;

        // Helper for assign pOwener via dynamic_cast
        template <typename SetType>
        void SetOwner(SetType* p) const
        {
            pOwner = dynamic_cast<T*>(p);
        }
    };
}