/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "gtest/gtest.h"

#include "Base/Zones/ZoneManager.h"
#include "Base/Zones/Zone.h"
#include "Base/Zones/ZoneProcess.h"
#include "Base/Zones/IContext.h"
#include "Base/Zones/ContextZone.h"

namespace nsBase::nsZones::nsTests
{
    struct Ctx : IContext
    {
    };

    class A_process : public TProcess
    {
    public:
        void Work(std::list<IContext*>& aciveCtx) override
        {
            for (auto pCtx : aciveCtx) {
                Finish(pCtx);
            }
        }
    };
}

using namespace nsBase::nsZones::nsTests;

TEST(Zones, Simple_Ok)
{
    nsBase::nsZones::TZoneManager zoneMgr;

    nsBase::nsZones::TZone a("A");
    nsBase::nsZones::TZone b("B");

    zoneMgr.AddZone(&a);
    zoneMgr.AddZone(&b);

    A_process a_process;
    a_process.Setup("A_Process", &a, &b);

    Ctx ctx;
    a.AddContext(&ctx);

    ctx.GetContextZone().StartProcess("A_Process");

    zoneMgr.Work();

    ASSERT_TRUE(ctx.GetOwnerZone() == &b);
}
