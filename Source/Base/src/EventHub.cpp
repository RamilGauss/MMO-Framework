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
void TEventHub::TakeEvents(std::list<std::string>& events)
{
    std::swap(events, mEvents);
}
//--------------------------------------------------------------------------------------
const std::source_location& TEventHub::GetSourceLocation(int index)
{
    return mSrcLocations[index];
}
//--------------------------------------------------------------------------------------
const std::source_location& TEventHub::GetSourceLocationForThisThread()
{
    auto index = SingletonManager()->Get<TThreadIndexator>()->GetThreadIndex();
    return GetSourceLocation(index);
}
//--------------------------------------------------------------------------------------
}
