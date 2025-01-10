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

struct A {};
struct B {};

TEST(RunTimeTypeIndex, Simple_Ok)
{
    auto rttiInt = SingletonManager()->Get<TRunTimeTypeIndex<int>>();
    auto rttiBool = SingletonManager()->Get<TRunTimeTypeIndex<bool>>();

    auto aRttiByInt = rttiInt->Type<A>();
    auto bRttiByInt = rttiInt->Type<B>();

    auto bRttiByBool = rttiBool->Type<B>();
    auto aRttiByBool = rttiBool->Type<A>();

    ASSERT_EQ(aRttiByInt, 0);
    ASSERT_EQ(bRttiByInt, 1);

    ASSERT_EQ(bRttiByBool, 0);
    ASSERT_EQ(aRttiByBool, 1);
}