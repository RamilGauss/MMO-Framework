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
    struct TCtx : IContext
    {
    };

    class TSimpleProcess : public TProcess
    {
    public:
        void Work(std::list<IContext*>& aciveCtx) override
        {
            for (auto pCtx : aciveCtx) {
                Finish(pCtx);
            }
        }
    };

    class TComplexProcess : public TProcess
    {
        nsBase::nsZones::TZone mA;
        nsBase::nsZones::TZone mB;

        TSimpleProcess mA_to_b;
    public:
        TComplexProcess() : mA("A"), mB("B")
        {
        }

        void Work(std::list<IContext*>& aciveCtx) override
        {

        }
    protected:
        void SetupEvent()
        {
            mZoneMng->AddZone(&mA);
            mZoneMng->AddZone(&mB);

            mA_to_b.Setup("a->b", &mA, &mB);

            mA_to_b.mFinishEvent.Register(this, &TComplexProcess::OnFinishEvent);
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

        void OnFinishEvent(TProcess* pProcess, TZone* pZone, IContext* pCtx)
        {
            Finish(pCtx);
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

    TSimpleProcess a_process;
    a_process.Setup("A_Process", &a, &b);

    TCtx ctx;
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

    TSimpleProcess a_to_b;
    a_to_b.Setup("a->b", &a, &b);
    TSimpleProcess a_to_c;
    a_to_c.Setup("a->c", &a, &c);

    TCtx ctx;
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

    TComplexProcess a_to_b;
    a_to_b.Setup("a->b", &a, &b);

    TCtx ctx;
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

    TComplexProcess a_to_b;
    a_to_b.Setup("a->b", &a, &b);

    TCtx ctx;
    a.AddContext(&ctx);

    ctx.GetContextZone().StartProcess("a->b");
    ctx.GetContextZone().StopProcess();

    zoneMgr.Work();

    ASSERT_TRUE(ctx.GetActiveProcess(0) == nullptr);
    ASSERT_TRUE(ctx.GetActiveProcess(1) == nullptr);
}