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
        mThreadIndexator = SingletonManager()->Get<TThreadIndexator>();
    }
    //--------------------------------------------------------------------------------------
    void TEventHub::TakeEvents(std::list<std::string>& events)
    {
        auto count = mThreadIndexator->GetCount();
        for (int i = 0; i < count; i++) {
            std::string** pFirst = mEventPipes[i]->GetFirst();
            while (pFirst) {
                events.push_back(std::move(*pFirst[0]));
                mEventPipes[i]->RemoveFirst();
                pFirst = mEventPipes[i]->GetFirst();
            }
        }
    }
    //--------------------------------------------------------------------------------------
    const std::source_location& TEventHub::GetSourceLocation(int index)
    {
        return mSrcLocations[index];
    }
    //--------------------------------------------------------------------------------------
    const std::source_location& TEventHub::GetSourceLocationForThisThread()
    {
        auto index = mThreadIndexator->GetThreadIndex();
        return GetSourceLocation(index);
    }
    //--------------------------------------------------------------------------------------
    TEventHub::TStringListPtr TEventHub::GetPipForThisThread()
    {
        auto index = mThreadIndexator->GetThreadIndex();
        return mEventPipes[index];
    }
    //--------------------------------------------------------------------------------------
}
