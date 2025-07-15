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
    TEventHub::TEventHub()
    {
    }
    //--------------------------------------------------------------------------------------
    void TEventHub::SetupTimer(std::function<std::string()> timerFunction)
    {
        mTimerFunction = timerFunction;
    }
    //--------------------------------------------------------------------------------------
    const std::source_location& TEventHub::GetSourceLocationForThisThread()
    {
        auto index = TThreadIndexator::GetIndex();
        return mSrcLocations[index];
    }
    //--------------------------------------------------------------------------------------
    const std::string& TEventHub::GetSourceForThisThread()
    {
        auto index = TThreadIndexator::GetIndex();
        return mSources[index];
    }
    //--------------------------------------------------------------------------------------
    int TEventHub::RegisterDestination()
    {
        mEventPipes[mRegisterCount] = std::make_shared<TEventInfoQueue>(100'000);
        return mRegisterCount++;
    }
    //--------------------------------------------------------------------------------------
    std::vector<PEventInfo> TEventHub::TakeEvents(int dstId)
    {
        std::vector<PEventInfo> events;
        auto pipe = mEventPipes[dstId];
        while (true) {
            PEventInfo event;
            pipe->try_pop(event);
            if (event) {
                events.push_back(event);
            } else {
                break;
            }
        }
        return events;
    }
    //--------------------------------------------------------------------------------------
    void TEventHub::AddEvent(PEventInfo event)
    {
        for (size_t i = 0; i < mRegisterCount; i++) {
            mEventPipes[i]->push(event);
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
