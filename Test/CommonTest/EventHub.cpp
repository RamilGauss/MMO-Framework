/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "gtest/gtest.h"

#include <array>
#include <filesystem>
#include <ranges>
#include <string_view>

#include "Base/Zones/ZoneManager.h"
#include "Base/Zones/Zone.h"
#include "Base/Zones/SyncSubProcess.h"
#include "Base/Zones/AsyncSubProcess.h"
#include "Base/Zones/IHopProcess.h"
#include "Base/Zones/HopProcessContext.h"

#include "Base/Common/FramedThread.h"
#include "Base/Common/ThreadIndexator.h"
#include "Base/Common/SingletonManager.h"
#include "Base/Common/GlobalEventHub.h"
#include "Base/Common/CoroInThread.h"
#include "Base/Common/PathOperations.h"

using namespace nsBase::nsCommon;

static TEventHub* g_EventHub = nullptr;

namespace nsFixture
{
    void SetEventHub(TEventHub* eventHub)
    {
        g_EventHub = eventHub;
    }

    TEventHub* GetEventHub(std::string&& source = "Common", std::source_location loc = std::source_location::current())
    {
        g_EventHub->SetSourceLocation(std::move(loc));
        g_EventHub->SetSource(std::move(source));
        return g_EventHub;
    }
}

TEST(EventHub, TakeEvents_Ok)
{
    TEventHub eventHub;
    nsFixture::SetEventHub(&eventHub);

    auto regId = nsFixture::GetEventHub()->RegisterDestination();

    nsFixture::GetEventHub()->SetupTimer([]() {return ""; });

    nsFixture::GetEventHub()->AddInfoEvent("{}", 42);
    nsFixture::GetEventHub()->AddWarningEvent("{}", 42);
    nsFixture::GetEventHub()->AddErrorEvent("{}", 42);

    auto events = nsFixture::GetEventHub()->TakeEvents(regId);

    std::vector<PEventInfo> expectedEvents;
    expectedEvents.push_back(std::make_shared<TEventInfo>(TEventInfo
        {
            .time = "",
            .level = "Info",
            .message = "42",
            .fileLocation = "C:\\MMOFramework\\Test\\CommonTest\\EventHub.cpp:57:16",
            .source = "Common",
        }));
    expectedEvents.push_back(std::make_shared<TEventInfo>(TEventInfo
        {
            .time = "",
            .level = "Warning",
            .message = "42",
            .fileLocation = "C:\\MMOFramework\\Test\\CommonTest\\EventHub.cpp:58:16",
            .source = "Common",
        }));
    expectedEvents.push_back(std::make_shared<TEventInfo>(TEventInfo
        {
            .time = "",
            .level = "Error",
            .message = "42",
            .fileLocation = "C:\\MMOFramework\\Test\\CommonTest\\EventHub.cpp:59:16",
            .source = "Common",
        }));

    ASSERT_TRUE(events.size() == expectedEvents.size());
    for (size_t i = 0; i < events.size(); i++) {
        auto& event = events[i];
        auto& expectedEvent = expectedEvents[i];
        ASSERT_EQ(event->time, expectedEvent->time);
        ASSERT_EQ(event->level, expectedEvent->level);
        ASSERT_EQ(events[i]->message, expectedEvent->message);
        auto eventFileName = std::filesystem::path(event->fileLocation).filename().string();
        auto expoectedEventFileName = std::filesystem::path(expectedEvent->fileLocation).filename().string();
        ASSERT_EQ(eventFileName, expoectedEventFileName);
        ASSERT_EQ(event->source, expectedEvent->source);
    }
}

TEST(EventHub, TakeEventsFromFewDestinations_Ok)
{
    TEventHub eventHub;
    nsFixture::SetEventHub(&eventHub);

    auto regId0 = nsFixture::GetEventHub()->RegisterDestination();
    auto regId1 = nsFixture::GetEventHub()->RegisterDestination();

    nsFixture::GetEventHub()->SetupTimer([]() {return ""; });

    nsFixture::GetEventHub()->AddInfoEvent("{}", 42);

    auto events0 = nsFixture::GetEventHub()->TakeEvents(regId0);

    ASSERT_EQ(events0.size(), 1);

    nsFixture::GetEventHub()->AddWarningEvent("{}", 42);
    nsFixture::GetEventHub()->AddErrorEvent("{}", 42);

    auto events1 = nsFixture::GetEventHub()->TakeEvents(regId1);

    ASSERT_EQ(events1.size(), 3);

    events0 = nsFixture::GetEventHub()->TakeEvents(regId0);

    ASSERT_TRUE(events0.size() == 2);
}
