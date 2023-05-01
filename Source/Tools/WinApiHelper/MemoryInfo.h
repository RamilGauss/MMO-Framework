/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>
#include <list>

#include "TypeDef.h"

#include "PageInfo.h"

namespace nsWinApiHelper
{
    class DllExport TMemoryInfo
    {
    public:

        [[nodiscard]]
        static std::list<TPageInfo> GetExecutablePages(unsigned long processId);
    };
}