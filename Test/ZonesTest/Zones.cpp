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
#include "Base/Zones/SyncHopProcess.h"
#include "Base/Zones/IHopProcessContext.h"

#include "Base/Common/FramedThread.h"



#include "Base/Common/ThreadIndexator.h"
#include "Base/Common/SingletonManager.h"
#include "Base/Common/GlobalEventHub.h"


TEST(EventHub, Simple_Ok)
{
    using namespace nsBase::nsCommon;

    SingletonManager()->Get<TThreadIndexator>()->AddThreadId();

    GetEventHub()->AddEvent("Test", "asdasd");

    GetEventHub()->AddEvent("Test", "{}", 42);
    GetEventHub()->AddInfoEvent("{}", 42);
    GetEventHub()->AddWarningEvent("{}", 42);
    GetEventHub()->AddErrorEvent("{}", 42);


    std::list<std::string> events;
    GetEventHub()->TakeEvents(events);

    events.begin();
}


namespace nsBase::nsZones::nsTests
{
    struct TCtx : IHopProcessContext
    {
        uint64_t totalCount = 1;
        uint64_t progressCount = 0;
    };

    class TSimpleProcess : public TSyncHopProcess
    {
    public:
        void Work(IHopProcessContext* pCtx) override
        {
            Finish(pCtx);

        }
        uint64_t GetTotalCount(IHopProcessContext* pCtx) const override
        {
            return Ctx<TCtx>(pCtx)->totalCount;
        }
        uint64_t GetProgressCount(IHopProcessContext* pCtx) const override
        {
            return Ctx<TCtx>(pCtx)->progressCount;
        }
    };

    class TComplexProcess : public TSyncHopProcess
    {
    public:
        TComplexProcess()
        {
        }

        void Work(IHopProcessContext* pCtx) override
        {

        }
        uint64_t GetTotalCount(IHopProcessContext* pCtx) const override
        {
            return 0;// mA_to_b.GetTotalCount(pCtx);
        }
        uint64_t GetProgressCount(IHopProcessContext* pCtx) const override
        {
            return 0;//mA_to_b.GetProgressCount(pCtx);
        }
    protected:
        void SetupEvent()
        {
            mZoneMng->AddZone(std::make_shared<TZone>("A"));
            mZoneMng->AddZone(std::make_shared<TZone>("B"));

            auto a_to_b = std::make_shared<TSimpleProcess>();
            a_to_b->Setup("a->b", mZoneMng->GetZone("B"));
            mZoneMng->GetZone("A")->AddProcess(a_to_b);

            a_to_b->mFinishEvent.Register(this, &TComplexProcess::OnFinishEvent);
        }
        void StartEvent(IHopProcessContext* pCtx) override
        {
            mZoneMng->GetZone("A")->AddContext(pCtx);
            pCtx->StartProcess("a->b", GetNextRank());
        }
        void StopEvent(IHopProcessContext* pCtx) override
        {
            //pCtx->GetContextState(GetNextRank()).StopProcess();
        }

        void OnFinishEvent(THopProcess* pProcess, TZone* pZone, IHopProcessContext* pCtx)
        {
            pZone->RemoveContext(pCtx);
            Finish(pCtx);
        }

    };

    class TTripleComplexProcess : public TSyncHopProcess
    {
        SharedPtrHopProcess mA_to_b;
        SharedPtrHopProcess mB_to_c;

    public:
        TTripleComplexProcess()
        {
        }

        void Work(IHopProcessContext* pCtx) override
        {

        }

        uint64_t GetTotalCount(IHopProcessContext* pCtx) const override
        {
            return 0;// mA_to_b.GetTotalCount(pCtx) + mB_to_c.GetTotalCount(pCtx);
        }
        uint64_t GetProgressCount(IHopProcessContext* pCtx) const override
        {
            return 0;//mA_to_b.GetProgressCount(pCtx) + mB_to_c.GetProgressCount(pCtx);
        }
    protected:
        void SetupEvent()
        {
            mZoneMng->AddZone(std::make_shared<TZone>("A"));
            mZoneMng->AddZone(std::make_shared<TZone>("B"));
            mZoneMng->AddZone(std::make_shared<TZone>("C"));

            mA_to_b = std::make_shared<TSimpleProcess>();
            mB_to_c = std::make_shared<TSimpleProcess>();

            mA_to_b->Setup("a->b", mZoneMng->GetZone("B"));
            mB_to_c->Setup("b->c", mZoneMng->GetZone("C"));

            mZoneMng->GetZone("A")->AddProcess(mA_to_b);
            mZoneMng->GetZone("B")->AddProcess(mB_to_c);

            mA_to_b->mFinishEvent.Register(this, &TTripleComplexProcess::OnFinishEvent);
            mB_to_c->mFinishEvent.Register(this, &TTripleComplexProcess::OnFinishEvent);
        }
        void StartEvent(IHopProcessContext* pCtx) override
        {
            mZoneMng->GetZone("A")->AddContext(pCtx);
            pCtx->StartProcess("a->b", GetNextRank());
        }
        void StopEvent(IHopProcessContext* pCtx) override
        {
            //pCtx->GetContextState(GetNextRank()).StopProcess();
        }

        void OnFinishEvent(THopProcess* pProcess, TZone* pZone, IHopProcessContext* pCtx)
        {
            if (pZone->GetName() == "B") {
                pCtx->StartProcess("b->c", GetNextRank());
            } else {
                pZone->RemoveContext(pCtx);
                Finish(pCtx);
            }
        }

    };

    //class TAsyncProcess : public TAsyncHopProcess
    //{
    //public:
    //    TAsyncProcess()
    //    {
    //        nsBase::nsCommon::TSingleThread::Start();
    //    }
    //    void Work(std::list<IContext*>& aciveCtx) override
    //    {
    //        for (auto pCtx : aciveCtx) {
    //            Finish(pCtx);
    //        }
    //    }
    //    uint64_t GetTotalCount(IContext* pCtx) const override
    //    {
    //        return Ctx<TCtx>(pCtx)->totalCount;
    //    }
    //    uint64_t GetProgressCount(IContext* pCtx) const override
    //    {
    //        return Ctx<TCtx>(pCtx)->progressCount;
    //    }
    //private:
    //protected:
    //    void Work() override
    //    {

    //    }
    //};
}

using namespace nsBase::nsZones::nsTests;
using namespace nsBase::nsZones;

TEST(Zones, Simple_Ok)
{
    TZoneManager zoneMgr;

    auto a = std::make_shared<TZone>("A");
    auto b = std::make_shared<TZone>("B");

    zoneMgr.AddZone(a);
    zoneMgr.AddZone(b);

    auto a_process = std::make_shared<TSimpleProcess>();
    a_process->Setup("a->b", b.get());
    a->AddProcess(a_process);

    TCtx ctx;
    a->AddContext(&ctx);

    ctx.StartProcess("a->b");

    zoneMgr.Work();

    ASSERT_TRUE(ctx.GetOwnerZone() == b.get());
}

TEST(Zones, Displacement_Process_Ok)
{
    TZoneManager zoneMgr;

    auto a = std::make_shared<TZone>("A");
    auto b = std::make_shared<TZone>("B");
    auto c = std::make_shared<TZone>("C");

    zoneMgr.AddZone(a);
    zoneMgr.AddZone(b);
    zoneMgr.AddZone(c);

    auto a_to_b = std::make_shared<TSimpleProcess>();
    auto a_to_c = std::make_shared<TSimpleProcess>();
    a_to_b->Setup("a->b", b.get());
    a_to_c->Setup("a->c", c.get());

    a->AddProcess(a_to_b);
    a->AddProcess(a_to_c);

    TCtx ctx;
    a->AddContext(&ctx);

    ctx.StartProcess("a->b");
    ctx.StartProcess("a->c");

    zoneMgr.Work();

    ASSERT_TRUE(ctx.GetOwnerZone() == c.get());
}

TEST(Zones, Finish_ComplexProcess_Ok)
{
    TZoneManager zoneMgr;

    auto a = std::make_shared<TZone>("A");
    auto b = std::make_shared<TZone>("B");

    zoneMgr.AddZone(a);
    zoneMgr.AddZone(b);

    auto a_to_b = std::make_shared<TComplexProcess>();
    a_to_b->Setup("a->b", b.get());

    a->AddProcess(a_to_b);

    TCtx ctx;
    a->AddContext(&ctx);

    ctx.StartProcess("a->b");

    zoneMgr.Work();

    ASSERT_TRUE(ctx.GetOwnerZone() == b.get());
}

TEST(Zones, Stop_ComplexProcess_Ok)
{
    TZoneManager zoneMgr;

    auto a = std::make_shared<TZone>("A");
    auto b = std::make_shared<TZone>("B");

    zoneMgr.AddZone(a);
    zoneMgr.AddZone(b);

    auto a_to_b = std::make_shared<TComplexProcess>();
    a_to_b->Setup("a->b", b.get());

    a->AddProcess(a_to_b);

    TCtx ctx;
    a->AddContext(&ctx);

    ctx.StartProcess("a->b");
    //ctx.GetContextState().StopProcess();

    zoneMgr.Work();

    ASSERT_TRUE(ctx.GetActiveProcess(0) == nullptr);
    ASSERT_TRUE(ctx.GetActiveProcess(1) == nullptr);
}

TEST(Zones, Finish_TripleComplexProcess_Ok)
{
    TZoneManager zoneMgr;

    auto a = std::make_shared<TZone>("A");
    auto b = std::make_shared<TZone>("B");

    zoneMgr.AddZone(a);
    zoneMgr.AddZone(b);

    auto a_to_b = std::make_shared<TTripleComplexProcess>();
    a_to_b->Setup("a->b", b.get());

    a->AddProcess(a_to_b);

    TCtx ctx;
    a->AddContext(&ctx);

    ctx.StartProcess("a->b");

    // a->b
    zoneMgr.Work();
    // b->c
    zoneMgr.Work();

    ASSERT_TRUE(ctx.GetOwnerZone() == b.get());
}

TEST(Zones, Simple_LargeQueue_Ok)
{
    TZoneManager zoneMgr;

    auto a = std::make_shared<TZone>("A");
    auto b = std::make_shared<TZone>("B");

    zoneMgr.AddZone(a);
    zoneMgr.AddZone(b);

    auto a_to_b = std::make_shared<TSimpleProcess>();
    a_to_b->Setup("a->b", b.get());

    a->AddProcess(a_to_b);

    const int CTX_COUNT = 10;

    std::array<TCtx, CTX_COUNT> ctxs;
    for (auto& ctx : ctxs) {
        a->AddContext(&ctx);
        ctx.StartProcess("a->b");
    }

    for (int i = 0; i < CTX_COUNT - 1; i++) {
        zoneMgr.Work();
        ASSERT_TRUE(a_to_b->GetActiveContextCount() == 1);
    }

    zoneMgr.Work();

    for (auto& ctx : ctxs) {
        ASSERT_TRUE(ctx.GetOwnerZone() == b.get());
    }
}

//TEST(Zones, Async)
//{
//    TAsyncProcess asyncProcess;
//
//}
