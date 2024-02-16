/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Common/ThreadManager.h"

namespace nsBase::nsCommon
{
    void TThreadManager::AddThreadId(std::thread::id thread_id)
    {
        int index = 0;

        std::lock_guard<std::mutex> guard(mMutex);

        for (auto& id : mThreadIds) {
            if (id == 0) {
                id = thread_id;
                break;
            }
            index++;
        }
    }
    //----------------------------------------------------------------------------------------------------
    int TThreadManager::GetThreadIndex(std::thread::id thread_id) const
    {
        int index = 0;
        for (const auto& id : mThreadIds) {
            if (id == thread_id) {
                break;
            }
            index++;
        }

        return index;
    }
    //----------------------------------------------------------------------------------------------------
}
