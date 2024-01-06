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
        uint64_t totalCount = 1;
        uint64_t progressCount = 0;
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
        uint64_t GetTotalCount(IContext* pCtx) const override
        {
            return Ctx<TCtx>(pCtx)->totalCount;
        }
        uint64_t GetProgressCount(IContext* pCtx) const override
        {
            return Ctx<TCtx>(pCtx)->progressCount;
        }
    };

    class TComplexProcess : public TProcess
    {
        TZone mA;
        TZone mB;

        TSimpleProcess mA_to_b;
    public:
        TComplexProcess() : mA("A"), mB("B")
        {
        }

        void Work(std::list<IContext*>& aciveCtx) override
        {

        }
        uint64_t GetTotalCount(IContext* pCtx) const override
        {
            return mA_to_b.GetTotalCount(pCtx);
        }
        uint64_t GetProgressCount(IContext* pCtx) const override
        {
            return mA_to_b.GetProgressCount(pCtx);
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
            pZone->RemoveContext(pCtx);
            Finish(pCtx);
        }

    };

    class TTripleComplexProcess : public TProcess
    {
        TZone mA;
        TZone mB;
        TZone mC;

        TSimpleProcess mA_to_b;
        TSimpleProcess mB_to_c;
    public:
        TTripleComplexProcess() : mA("A"), mB("B"), mC("C")
        {
        }

        void Work(std::list<IContext*>& aciveCtx) override
        {

        }

        uint64_t GetTotalCount(IContext* pCtx) const override
        {
            return mA_to_b.GetTotalCount(pCtx) + mB_to_c.GetTotalCount(pCtx);
        }
        uint64_t GetProgressCount(IContext* pCtx) const override
        {
            return mA_to_b.GetProgressCount(pCtx) + mB_to_c.GetProgressCount(pCtx);
        }
    protected:
        void SetupEvent()
        {
            mZoneMng->AddZone(&mA);
            mZoneMng->AddZone(&mB);
            mZoneMng->AddZone(&mC);

            mA_to_b.Setup("a->b", &mA, &mB);
            mB_to_c.Setup("b->c", &mB, &mC);

            mA_to_b.mFinishEvent.Register(this, &TTripleComplexProcess::OnFinishEvent);
            mB_to_c.mFinishEvent.Register(this, &TTripleComplexProcess::OnFinishEvent);
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
            if (pProcess == &mA_to_b) {
                pCtx->GetContextZone(GetNextRank()).StartProcess("b->c");
            } else {
                pZone->RemoveContext(pCtx);
                Finish(pCtx);
            }
        }

    };
}

using namespace nsBase::nsZones::nsTests;
using namespace nsBase::nsZones;

TEST(Zones, Simple_Ok)
{
    TZoneManager zoneMgr;

    TZone a("A");
    TZone b("B");

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
    TZoneManager zoneMgr;

    TZone a("A");
    TZone b("B");
    TZone c("C");

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
    TZoneManager zoneMgr;

    TZone a("A");
    TZone b("B");

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
    TZoneManager zoneMgr;

    TZone a("A");
    TZone b("B");

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

TEST(Zones, Finish_TripleComplexProcess_Ok)
{
    TZoneManager zoneMgr;

    TZone a("A");
    TZone b("B");

    zoneMgr.AddZone(&a);
    zoneMgr.AddZone(&b);

    TTripleComplexProcess a_to_b;
    a_to_b.Setup("a->b", &a, &b);

    TCtx ctx;
    a.AddContext(&ctx);

    ctx.GetContextZone().StartProcess("a->b");

    // a->b
    zoneMgr.Work();
    // b->c
    zoneMgr.Work();

    ASSERT_TRUE(ctx.GetOwnerZone() == &b);
}