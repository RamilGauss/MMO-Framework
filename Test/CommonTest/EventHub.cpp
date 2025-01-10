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

TEST(EventHub, Simple_Ok)
{
    using namespace nsBase::nsCommon;

    SingletonManager()->Get<TThreadIndexator>()->AddThreadId();

    GetEventHub()->SetupTimer([]() {return ""; });

    GetEventHub()->AddEvent("Test", "asdasd");
    GetEventHub()->AddEvent("Test", "{}", 42);
    GetEventHub()->AddInfoEvent("{}", 42);
    GetEventHub()->AddWarningEvent("{}", 42);
    GetEventHub()->AddErrorEvent("{}", 42);

    std::list<std::string> events;
    GetEventHub()->TakeEvents(events);

    std::list<std::string> expectedEvents = {
    "|Test: asdasd [C:\\MMOFramework\\Test\\CommonTest\\EventHub.cpp - 35, void __cdecl EventHub_Simple_Ok_Test::TestBody(void)]",
    "|Test: 42 [C:\\MMOFramework\\Test\\CommonTest\\EventHub.cpp - 36, void __cdecl EventHub_Simple_Ok_Test::TestBody(void)]",
    "|Info: 42 [C:\\MMOFramework\\Test\\CommonTest\\EventHub.cpp - 37, void __cdecl EventHub_Simple_Ok_Test::TestBody(void)]",
    "|Warning: 42 [C:\\MMOFramework\\Test\\CommonTest\\EventHub.cpp - 38, void __cdecl EventHub_Simple_Ok_Test::TestBody(void)]",
    "|Error: 42 [C:\\MMOFramework\\Test\\CommonTest\\EventHub.cpp - 39, void __cdecl EventHub_Simple_Ok_Test::TestBody(void)]",
    };

    ASSERT_EQ(events, expectedEvents);
}
