/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Common/ThreadIndexator.h"

namespace nsBase::nsCommon
{
    void TThreadIndexator::AddThreadId(std::thread::id threadId)
    {
        int index = 0;

        auto hashThreadId = std::hash<std::thread::id>{}(threadId);

        std::lock_guard<std::mutex> guard(mMutex);

        for (auto& idHash : mThreadIdHashes) {
            if (idHash == 0) {
                idHash = hashThreadId;
                break;
            }
            index++;
        }

        mCount.fetch_add(1);
    }
    //----------------------------------------------------------------------------------------------------
    int TThreadIndexator::GetThreadIndex(std::thread::id threadId) const
    {
        auto hashThreadId = std::hash<std::thread::id>{}(threadId);
        int index = 0;
        for (const auto& idHash : mThreadIdHashes) {
            if (idHash == hashThreadId) {
                break;
            }
            index++;
        }

        return index;
    }
    //----------------------------------------------------------------------------------------------------
    int TThreadIndexator::GetCount() const
    {
        return mCount.load();
    }
    //----------------------------------------------------------------------------------------------------
}
