/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "Base/Common/TypeDef.h"

namespace nsTornadoEngine
{
    class DllExport ITypeFactory
    {
    public:
        virtual ~ITypeFactory() {}

        virtual void Init() = 0;

        virtual void* New(int rtti) = 0;
        virtual void Delete(void* p, int rtti) = 0;
    };
}
