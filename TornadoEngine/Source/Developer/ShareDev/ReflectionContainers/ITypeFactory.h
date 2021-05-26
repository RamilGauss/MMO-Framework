/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "TypeDef.h"

namespace nsShareDev
{
    class DllExport ITypeFactory
    {
    public:
        virtual void* New(int rtti) = 0;
        virtual void Delete(void* p, int rtti) = 0;
    };
}