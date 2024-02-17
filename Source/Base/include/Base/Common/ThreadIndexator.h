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
        std::array<size_t, MAX_THREAD_COUNT> mThreadIdHashes = { 0 };

        std::mutex mMutex;
    public:
        void AddThreadId(std::thread::id threadId = std::this_thread::get_id());
        int GetThreadIndex(std::thread::id threadId = std::this_thread::get_id()) const;
    };
}
