/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>

#include "TypeDef.h"

#include "PageInfo.h"

namespace nsWinApiHelper
{
    class DllExport TCallFinder
    {
    public:

        [[nodiscard]]
        static std::list<void*> Find(const std::list<TPageInfo>& pages, void* pFunc);

    private:
        static void FindAbsoluteCall(const std::list<TPageInfo>& pages, void* pFunc, std::list<void*>& callPlaces);

        static void FindRelativeCall(const std::list<TPageInfo>& pages, void* pFunc, std::list<void*>& callPlaces);
    };
}
