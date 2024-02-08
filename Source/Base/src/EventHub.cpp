/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Common/EventHub.h"

namespace nsBase::nsCommon
{

TEventHub g_EventHub;

TEventHub* GetEventHub()
{
    return &g_EventHub;
}

void TEventHub::AddEvent(const std::string& level, const std::string& message)
{
    auto str_time = ht_GetTimeStr();
    auto event = std::format("{}: {} - {}", str_time, level, message);

    std::lock_guard<std::mutex> guard(mMutex);

    mEvents.push_back(event)
}
//------------------------------------------------------------------------------------------------
void TEventHub::AddInfoEvent(const std::string& message)
{
    AddEvent("Info", message);
}
//------------------------------------------------------------------------------------------------
void TEventHub::AddWarningEvent(const std::string& message)
{
    AddEvent("Warning", message);
}
//------------------------------------------------------------------------------------------------
void TEventHub::AddErrorEvent(const std::string& message)
{
    AddEvent("Error", message);
}
//------------------------------------------------------------------------------------------------
void TEventHub::TakeEvents(std::vector<std::string>& events)
{
    std::lock_guard<std::mutex> guard(mMutex);

    std::swap(events, mEvents);
}
//------------------------------------------------------------------------------------------------
}
