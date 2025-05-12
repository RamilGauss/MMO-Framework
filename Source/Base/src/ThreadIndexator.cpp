/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Common/ThreadIndexator.h"

namespace nsBase::nsCommon
{
    int TThreadIndexator::GetIndex()
    {
        static std::array<std::thread::id, MAX_THREAD_COUNT> g_ids = {};
        static std::atomic_int g_count(0);
        static std::mutex g_m;

        auto id = std::this_thread::get_id();
        int count = g_count.load();
        for (int i = 0; i < count; i++) {
            if (g_ids[i] == id) {
                return i;
            }
        }

        std::lock_guard<std::mutex> guard(g_m);
        auto index = g_count.fetch_add(1);
        g_ids[index] = id;
        return index;
    }
    //----------------------------------------------------------------------------------------------------
}
