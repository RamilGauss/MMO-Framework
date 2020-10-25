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
    class DllExport IReflection
    {
    public:
        virtual void* New(int typeIdentifier) = 0;
        virtual void* New(const std::string& typeName) = 0;
    };
}