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
#include "Base/Zones/ContextState.h"

namespace nsBase::nsZones::nsTests
{
    struct Ctx : IContext
    {
    };

    class SimpleProcess : public TProcess
    {
    public:
        void Work(std::list<IContext*>& aciveCtx) override
        {
            for (auto pCtx : aciveCtx) {
                Finish(pCtx);
            }
        }
    };

    class ComplexProcess : public TProcess
    {
        nsBase::nsZones::TZone mA;
        nsBase::nsZones::TZone mB;

        SimpleProcess mA_to_b;
    public:
        ComplexProcess() : mA("A"), mB("B")
        {
        }

        void Work(std::list<IContext*>& aciveCtx) override
        {
            for (auto pCtx : aciveCtx) {
                Finish(pCtx);
            }
        }
    protected:
        void SetupEvent()
        {
            mZoneMng->AddZone(&mA);
            mZoneMng->AddZone(&mB);

            mA_to_b.Setup("a->b", &mA, &mB);
        }
        void StartEvent(IContext* pCtx) override
        {
            mA.AddContext(pCtx);
            pCtx->GetContextZone(GetNextRank()).StartProcess("a->b");
        }
        void StopEvent(IContext* pCtx) override
        {
            pCtx->GetContextZone(GetNextRank()).StopProcess();
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

    SimpleProcess a_process;
    a_process.Setup("A_Process", &a, &b);

    Ctx ctx;
    a.AddContext(&ctx);

    ctx.GetContextZone().StartProcess("A_Process");

    zoneMgr.Work();

    ASSERT_TRUE(ctx.GetOwnerZone() == &b);
}

TEST(Zones, Displacement_Process_Ok)
{
    nsBase::nsZones::TZoneManager zoneMgr;

    nsBase::nsZones::TZone a("A");
    nsBase::nsZones::TZone b("B");
    nsBase::nsZones::TZone c("C");

    zoneMgr.AddZone(&a);
    zoneMgr.AddZone(&b);
    zoneMgr.AddZone(&c);

    SimpleProcess a_to_b;
    a_to_b.Setup("a->b", &a, &b);
    SimpleProcess a_to_c;
    a_to_c.Setup("a->c", &a, &c);

    Ctx ctx;
    a.AddContext(&ctx);

    ctx.GetContextZone().StartProcess("a->b");
    ctx.GetContextZone().StartProcess("a->c");

    zoneMgr.Work();

    ASSERT_TRUE(ctx.GetOwnerZone() == &c);
}

TEST(Zones, Finish_ComplexProcess_Ok)
{
    nsBase::nsZones::TZoneManager zoneMgr;

    nsBase::nsZones::TZone a("A");
    nsBase::nsZones::TZone b("B");

    zoneMgr.AddZone(&a);
    zoneMgr.AddZone(&b);

    ComplexProcess a_to_b;
    a_to_b.Setup("a->b", &a, &b);

    Ctx ctx;
    a.AddContext(&ctx);

    ctx.GetContextZone().StartProcess("a->b");

    zoneMgr.Work();

    ASSERT_TRUE(ctx.GetOwnerZone() == &b);
}

TEST(Zones, Stop_ComplexProcess_Ok)
{
    nsBase::nsZones::TZoneManager zoneMgr;

    nsBase::nsZones::TZone a("A");
    nsBase::nsZones::TZone b("B");

    zoneMgr.AddZone(&a);
    zoneMgr.AddZone(&b);

    ComplexProcess a_to_b;
    a_to_b.Setup("a->b", &a, &b);

    Ctx ctx;
    a.AddContext(&ctx);

    ctx.GetContextZone().StartProcess("a->b");
    ctx.GetContextZone().StopProcess();

    zoneMgr.Work();

    ASSERT_TRUE(ctx.GetActiveProcess(0) == nullptr);
    ASSERT_TRUE(ctx.GetActiveProcess(1) == nullptr);
}