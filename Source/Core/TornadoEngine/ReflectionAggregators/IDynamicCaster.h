/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "Base/Common/TypeDef.h"
#include "ECS/include/System.h"

namespace nsTornadoEngine
{
    class DllExport IDynamicCaster
    {
    public:
        virtual ~IDynamicCaster() {}

        virtual void Init() = 0;

        virtual void* Cast(int srcRtti, void* srcPtr, int dstRtti) = 0;
    };
}
