#pragma once

#include "TypeDef.h"

namespace nsTornadoEngine
{
    template <typename T>
    struct DllExport TPropertyOf
    {
#pragma IGNORE_ATTRIBUTE
        mutable T* pOwner = nullptr;
    };
}