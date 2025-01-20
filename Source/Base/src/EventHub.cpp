/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Common/EventHub.h"
#include "Base/Common/ThreadIndexator.h"
#include "Base/Common/SingletonManager.h"

namespace nsBase::nsCommon
{
    TEventHub::TEventHub(TThreadIndexator* threadIndexator)
    {
        mThreadIndexator = threadIndexator;
    }
    //--------------------------------------------------------------------------------------
    void TEventHub::SetupTimer(std::function<std::string()> timerFunction)
    {
        mTimerFunction = timerFunction;
    }
    //--------------------------------------------------------------------------------------
    const std::source_location& TEventHub::GetSourceLocationForThisThread()
    {
        auto index = mThreadIndexator->GetThreadIndex();
        return mSrcLocations[index];
    }
    //--------------------------------------------------------------------------------------
    const std::string& TEventHub::GetSourceForThisThread()
    {
        auto index = mThreadIndexator->GetThreadIndex();
        return mSources[index];
    }
    //--------------------------------------------------------------------------------------
    TEventHub::TStringListPtr TEventHub::GetPipForThisThread()
    {
        auto index = mThreadIndexator->GetThreadIndex();
        auto&& pipe = mEventPipes[index];
        if (pipe == nullptr) {
            pipe.reset(new TStringList());
        }
        return pipe;
    }
    //--------------------------------------------------------------------------------------
    int TEventHub::RegisterDestination()
    {
        mDstOffsetInEvents.push_back(0);
        return mRegisterCount++;
    }
    //--------------------------------------------------------------------------------------
    void TEventHub::TakeEvents(int dstId, std::list<TEventInfo>& events)
    {
        RefreshEvents();
        if (mEvents.empty()) {
            return;
        }

        auto offset = mDstOffsetInEvents[dstId];
        mDstOffsetInEvents[dstId] = mEvents.size();
        for (int i = offset; i < mEvents.size(); i++) {
            events.push_back(*mEvents[i]);
        }
        auto minOffset = CalculateMinOffset();
        for (int i = 0; i < minOffset; i++) {
            mEvents.pop_back();
        }
        for (auto& offset : mDstOffsetInEvents) {
            offset -= minOffset;
        }
    }
    //--------------------------------------------------------------------------------------
    int TEventHub::CalculateMinOffset()
    {
        int minOffset = std::numeric_limits<int>::max();
        for (auto& offset : mDstOffsetInEvents) {
            minOffset = std::min(minOffset, offset);
        }
        return minOffset;
    }
    //--------------------------------------------------------------------------------------
    void TEventHub::RefreshEvents()
    {
        auto count = mThreadIndexator->GetCount();
        for (int i = 0; i < count; i++) {
            auto pipe = mEventPipes[i];
            if (pipe) {
                TEventInfo** pFirst = pipe->GetFirst();
                while (pFirst) {
                    mEvents.push_back(pFirst[0]);
                    pipe->UnlinkData(pFirst);
                    pipe->RemoveFirst();
                    pFirst = pipe->GetFirst();
                }
            }
        }
    }
    //--------------------------------------------------------------------------------------
    void TEventHub::SetSourceLocation(std::source_location&& loc, int index)
    {
        mSrcLocations[index] = std::move(loc);
    }
    //--------------------------------------------------------------------------------------
    void TEventHub::SetSource(std::string&& source, int index)
    {
        mSources[index] = std::move(source);
    }
    //--------------------------------------------------------------------------------------
}
