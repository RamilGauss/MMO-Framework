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

TEST(EventHub, TakeEvents_Ok)
{
    using namespace nsBase::nsCommon;

    SingletonManager()->Get<TThreadIndexator>()->AddThreadId();

    TEventHub eventHub;

    auto regId = GetEventHub()->RegisterDestination();

    GetEventHub()->SetupTimer([]() {return ""; });

    GetEventHub()->AddInfoEvent("A", "{}", 42);
    GetEventHub()->AddWarningEvent("B", "{}", 42);
    GetEventHub()->AddErrorEvent("C", "{}", 42);

    std::list<TEventInfo> events;
    GetEventHub()->TakeEvents(regId, events);

    std::list<TEventInfo> expectedEvents = {
        {
            .time = "",
            .level = "Info",
            .message = "42",
            .fileLocation = "C:\\MMOFramework\\Test\\CommonTest\\EventHub.cpp:37:5",
            .source = "A",
        },
        {
            .time = "",
            .level = "Warning",
            .message = "42",
            .fileLocation = "C:\\MMOFramework\\Test\\CommonTest\\EventHub.cpp:38:5",
            .source = "B",
        },
        {
            .time = "",
            .level = "Error",
            .message = "42",
            .fileLocation = "C:\\MMOFramework\\Test\\CommonTest\\EventHub.cpp:39:5",
            .source = "C",
        },
    };

    ASSERT_EQ(events, expectedEvents);
}

TEST(EventHub, TakeEventsFromFewDestinations_Ok)
{
    using namespace nsBase::nsCommon;

    SingletonManager()->Get<TThreadIndexator>()->AddThreadId();

    auto regId0 = GetEventHub()->RegisterDestination();
    auto regId1 = GetEventHub()->RegisterDestination();

    GetEventHub()->SetupTimer([]() {return ""; });

    GetEventHub()->AddInfoEvent("A", "{}", 42);

    std::list<TEventInfo> events0;
    GetEventHub()->TakeEvents(regId0, events0);

    ASSERT_TRUE(events0.size(), 1);

    GetEventHub()->AddWarningEvent("B", "{}", 42);
    GetEventHub()->AddErrorEvent("C", "{}", 42);

    std::list<TEventInfo> events1;
    GetEventHub()->TakeEvents(regId1, events1);

    ASSERT_TRUE(events1.size(), 2);

    GetEventHub()->TakeEvents(regId0, events0);

    ASSERT_TRUE(events0.size() == 3);
    ASSERT_TRUE(events1.size() == 3);
}
