/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "gtest/gtest.h"

#include <array>

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

using namespace nsBase::nsCommon;

static TEventHub* g_EventHub = nullptr;

namespace nsFixture
{
    void SetEventHub(TEventHub* eventHub)
    {
        g_EventHub = eventHub;
    }

    TEventHub* GetEventHub(std::source_location loc = std::source_location::current())
    {
        g_EventHub->SetSourceLocation(std::move(loc));
        return g_EventHub;
    }
}

TEST(EventHub, TakeEvents_Ok)
{
    auto threadIndexator = SingletonManager()->Get<TThreadIndexator>();
    threadIndexator->AddThreadId();

    TEventHub eventHub(threadIndexator);
    nsFixture::SetEventHub(&eventHub);

    auto regId = nsFixture::GetEventHub()->RegisterDestination();

    nsFixture::GetEventHub()->SetupTimer([]() {return ""; });

    nsFixture::GetEventHub()->AddInfoEvent("A", "{}", 42);
    nsFixture::GetEventHub()->AddWarningEvent("B", "{}", 42);
    nsFixture::GetEventHub()->AddErrorEvent("C", "{}", 42);

    std::list<TEventInfo> events;
    nsFixture::GetEventHub()->TakeEvents(regId, events);

    std::list<TEventInfo> expectedEvents = {
        {
            .time = "",
            .level = "Info",
            .message = "42",
            .fileLocation = "C:\\MMOFramework\\Test\\CommonTest\\EventHub.cpp:57:16",
            .source = "A",
        },
        {
            .time = "",
            .level = "Warning",
            .message = "42",
            .fileLocation = "C:\\MMOFramework\\Test\\CommonTest\\EventHub.cpp:58:16",
            .source = "B",
        },
        {
            .time = "",
            .level = "Error",
            .message = "42",
            .fileLocation = "C:\\MMOFramework\\Test\\CommonTest\\EventHub.cpp:59:16",
            .source = "C",
        },
    };

    ASSERT_EQ(events, expectedEvents);
}

TEST(EventHub, TakeEventsFromFewDestinations_Ok)
{
    auto threadIndexator = SingletonManager()->Get<TThreadIndexator>();
    threadIndexator->AddThreadId();

    TEventHub eventHub(threadIndexator);
    nsFixture::SetEventHub(&eventHub);

    auto regId0 = nsFixture::GetEventHub()->RegisterDestination();
    auto regId1 = nsFixture::GetEventHub()->RegisterDestination();

    nsFixture::GetEventHub()->SetupTimer([]() {return ""; });

    nsFixture::GetEventHub()->AddInfoEvent("A", "{}", 42);

    std::list<TEventInfo> events0;
    nsFixture::GetEventHub()->TakeEvents(regId0, events0);

    ASSERT_TRUE(events0.size(), 1);

    nsFixture::GetEventHub()->AddWarningEvent("B", "{}", 42);
    nsFixture::GetEventHub()->AddErrorEvent("C", "{}", 42);

    std::list<TEventInfo> events1;
    nsFixture::GetEventHub()->TakeEvents(regId1, events1);

    ASSERT_TRUE(events1.size(), 2);

    nsFixture::GetEventHub()->TakeEvents(regId0, events0);

    ASSERT_TRUE(events0.size() == 3);
    ASSERT_TRUE(events1.size() == 3);
}
