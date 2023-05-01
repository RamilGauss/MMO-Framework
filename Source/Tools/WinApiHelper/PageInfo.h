/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

namespace nsWinApiHelper
{
    struct DllExport TPageInfo
    {
        void* ptr = nullptr;
        size_t size = 0;

        void* GetEnd() const
        {
            return (void*)((char*)ptr + size);
        }
    };
}