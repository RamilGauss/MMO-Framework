/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Common/EventHub.h"

#include <format>

#include "Base/Common/HiTimer.h"

namespace nsBase::nsCommon
{

TEventHub g_EventHub;

TEventHub* GetEventHub()
{
    return &g_EventHub;
}

void TEventHub::AddEvent(const std::string& level, const std::string& message, const std::source_location loc)
{
    auto source_location_str = std::format("{}, {}, {}, {}", 
        loc.file_name(), loc.line(), loc.column(), loc.function_name());

    auto str_time = ht_GetTimeStr();
    auto event = std::format("{}|{}:{}({})", str_time, level, message, source_location_str);

    std::lock_guard<std::mutex> guard(mMutex);

    mEvents.push_back(event);
}
//------------------------------------------------------------------------------------------------
void TEventHub::AddInfoEvent(const std::string& message, const std::source_location loc)
{
    AddEvent("Info", message, loc);
}
//------------------------------------------------------------------------------------------------
void TEventHub::AddWarningEvent(const std::string& message, const std::source_location loc)
{
    AddEvent("Warning", message, loc);
}
//------------------------------------------------------------------------------------------------
void TEventHub::AddErrorEvent(const std::string& message, const std::source_location loc)
{
    AddEvent("Error", message, loc);
}
//------------------------------------------------------------------------------------------------
void TEventHub::TakeEvents(std::vector<std::string>& events)
{
    std::lock_guard<std::mutex> guard(mMutex);

    std::swap(events, mEvents);
}
//------------------------------------------------------------------------------------------------
}
