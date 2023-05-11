/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>
#include <string>

#include "TypeDef.h"

namespace nsBase
{
    class DllExport TMemoryDumper
    {
    public:
        [[nodiscard]]
        static std::list<std::string> Dump(void* p, size_t size, size_t lineSize = 16);
    };
}
