/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <mutex>
#include <array>

#include "Base/Common/TypeDef.h"

namespace nsBase::nsCommon
{
    class DllExport TThreadIndexator
    {
        static const int MAX_THREAD_COUNT = 1024;
    public:
        static int GetIndex();
    };
}
