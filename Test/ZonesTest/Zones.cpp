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
    struct TCtx : THopProcessContext
    {
        std::string fileName;
        int counter = 0;
        size_t asyncTimeToSleep = 0;
    };

    class TSimpleSyncSubProcess : public TSyncSubProcess
    {
    protected:
        void Work(SharedPtrHopProcessContext pCtx) override
        {
            //std::cout << std::static_pointer_cast<TCtx>(pCtx)->fileName;
        }
        uint32_t GetSubProcessTotalPartCount(SharedPtrHopProcessContext pCtx) override
        {
            return 1;
        }
    };

    class TSimpleAsyncSubProcess : public TAsyncSubProcess
    {
    protected:
        void Work(SharedPtrHopProcessContext pCtx) override
        {
            auto ctx = std::static_pointer_cast<TCtx>(pCtx);
            using namespace std::literals;
            ht_msleep(ctx->asyncTimeToSleep);
            //std::cout << ctx->counter++ << std::endl;
        }
        uint32_t GetSubProcessTotalPartCount(SharedPtrHopProcessContext pCtx) override
        {
            return 10;
        }
    };

    class TSimpleSyncProcess : public IHopProcess
    {
        TSimpleSyncSubProcess mSubProcess;
    public:
        TSimpleSyncProcess(std::string name) : IHopProcess(std::move(name)) {}
        void InitSubProcesses(nsBase::nsCommon::TStrandHolder::Ptr strandHolder,
            nsBase::nsCommon::TCoroInThread::Ptr coroInThread) override
        {
            mSubProcess.Init(strandHolder, coroInThread);
        }
        boost::asio::awaitable<bool> Start(SharedPtrHopProcessContext pCtx) override
        {
            co_return co_await mSubProcess.Start(pCtx);
        }
        boost::asio::awaitable<void> Stop(SharedPtrHopProcessContext pCtx) override
        {
            co_await mSubProcess.Stop(pCtx);
        }
        TContextStateInProcess GetState(SharedPtrHopProcessContext pCtx) const override
        {
            return mSubProcess.GetState(pCtx);
        }
    };

    class TSimpleAsyncProcess : public IHopProcess
    {
        TSimpleAsyncSubProcess mSubProcess;
    public:
        TSimpleAsyncProcess(std::string name) : IHopProcess(std::move(name)) {}
        void InitSubProcesses(nsBase::nsCommon::TStrandHolder::Ptr strandHolder,
            nsBase::nsCommon::TCoroInThread::Ptr coroInThread) override
        {
            mSubProcess.Init(strandHolder, coroInThread);
        }
        boost::asio::awaitable<bool> Start(SharedPtrHopProcessContext pCtx) override
        {
            co_return co_await mSubProcess.Start(pCtx);
        }
        boost::asio::awaitable<void> Stop(SharedPtrHopProcessContext pCtx) override
        {
            co_await mSubProcess.Stop(pCtx);
        }
        TContextStateInProcess GetState(SharedPtrHopProcessContext pCtx) const override
        {
            return mSubProcess.GetState(pCtx);
        }
    };

    class TComplexProcess : public IHopProcess
    {
        TSimpleSyncSubProcess  mSyncSubProcess;
        TSimpleAsyncSubProcess mAsyncSubProcess;
    public:
        TComplexProcess(std::string name) : IHopProcess(std::move(name)) {}
        void InitSubProcesses(nsBase::nsCommon::TStrandHolder::Ptr strandHolder,
            nsBase::nsCommon::TCoroInThread::Ptr coroInThread) override
        {
            mSyncSubProcess.Init(strandHolder, coroInThread);
            mAsyncSubProcess.Init(strandHolder, coroInThread);
        }
        boost::asio::awaitable<bool> Start(SharedPtrHopProcessContext pCtx) override
        {
            SetCurrentSubProcess(pCtx, &mSyncSubProcess);
            if (co_await mSyncSubProcess.Start(pCtx) == false) {
                co_return false;
            }
            SetCurrentSubProcess(pCtx, &mAsyncSubProcess);
            if (co_await mAsyncSubProcess.Start(pCtx) == false) {
                co_return false;
            }
            SetCurrentSubProcess(pCtx, nullptr);
            co_return true;
        }
        boost::asio::awaitable<void> Stop(SharedPtrHopProcessContext pCtx) override
        {
            auto currentSubProcess = GetCurrentSubProcess(pCtx);
            if (currentSubProcess)
                co_await currentSubProcess->Stop(pCtx);
        }
        TContextStateInProcess GetState(SharedPtrHopProcessContext pCtx) const override
        {
            auto currentSubProcess = GetCurrentSubProcess(pCtx);
            if (currentSubProcess)
                return currentSubProcess->GetState(pCtx);
            return {};
        }
    };
}

using namespace nsBase::nsZones::nsTests;
using namespace nsBase::nsZones;

TEST(Zones, Simple_Ok)
{
    boost::asio::io_context ioContext;

    auto strandHolder = nsBase::nsCommon::TStrandHolder::New(ioContext);
    auto coroInThread = nsBase::nsCommon::TCoroInThread::New();

    // Construct graph
    TZoneManager zoneMgr;
    zoneMgr.Init(strandHolder, coroInThread);

    auto a = std::make_shared<TZone>("A");
    auto b = std::make_shared<TZone>("B");

    zoneMgr.AddZone(a);
    zoneMgr.AddZone(b);

    auto process = std::make_shared<TSimpleSyncProcess>("Sync");
    a->AddProcess(process);

    auto ctx = std::make_shared<TCtx>();
    ctx->fileName = "x.log";
    zoneMgr.LinkContext(ctx, a);

    // Start process
    zoneMgr.StartProcess(ctx, process->GetName(), b);

    ioContext.run();

    auto state = zoneMgr.GetState(ctx);

    ASSERT_EQ(zoneMgr.GetZone(ctx).get(), b.get());
    ASSERT_EQ(state, std::nullopt);
}

TEST(Zones, Async)
{
    boost::asio::io_context ioContext;

    auto strandHolder = nsBase::nsCommon::TStrandHolder::New(ioContext);
    auto coroInThread = nsBase::nsCommon::TCoroInThread::New();

    // Construct graph
    TZoneManager zoneMgr;
    zoneMgr.Init(strandHolder, coroInThread);

    auto a = std::make_shared<TZone>("A");
    auto b = std::make_shared<TZone>("B");

    zoneMgr.AddZone(a);
    zoneMgr.AddZone(b);

    auto process = std::make_shared<TSimpleAsyncProcess>("Async");
    a->AddProcess(process);

    auto ctx = std::make_shared<TCtx>();
    ctx->fileName = "x.log";
    zoneMgr.LinkContext(ctx, a);

    // Start process
    zoneMgr.StartProcess(ctx, process->GetName(), b);

    ioContext.run();

    auto state = zoneMgr.GetState(ctx);

    ASSERT_EQ(zoneMgr.GetZone(ctx).get(), b.get());
    ASSERT_EQ(state, std::nullopt);
}


TEST(Zones, Complex)
{
    boost::asio::io_context ioContext;

    auto strandHolder = nsBase::nsCommon::TStrandHolder::New(ioContext);
    auto coroInThread = nsBase::nsCommon::TCoroInThread::New();

    // Construct graph
    TZoneManager zoneMgr;
    zoneMgr.Init(strandHolder, coroInThread);

    auto a = std::make_shared<TZone>("A");
    auto b = std::make_shared<TZone>("B");

    zoneMgr.AddZone(a);
    zoneMgr.AddZone(b);

    auto process = std::make_shared<TComplexProcess>("Complex");
    a->AddProcess(process);

    auto ctx = std::make_shared<TCtx>();
    ctx->fileName = "x.log";
    zoneMgr.LinkContext(ctx, a);

    // Start process
    zoneMgr.StartProcess(ctx, process->GetName(), b);

    ioContext.run();

    auto state = zoneMgr.GetState(ctx);

    ASSERT_EQ(zoneMgr.GetZone(ctx).get(), b.get());
    ASSERT_EQ(state, std::nullopt);
}

TEST(Zones, Cancel)
{
    boost::asio::io_context ioContext;

    auto strandHolder = nsBase::nsCommon::TStrandHolder::New(ioContext);
    auto coroInThread = nsBase::nsCommon::TCoroInThread::New();

    // Construct graph
    TZoneManager zoneMgr;
    zoneMgr.Init(strandHolder, coroInThread);

    auto a = std::make_shared<TZone>("A");
    auto b = std::make_shared<TZone>("B");

    zoneMgr.AddZone(a);
    zoneMgr.AddZone(b);

    auto process = std::make_shared<TSimpleAsyncProcess>("Async");
    a->AddProcess(process);

    auto ctx = std::make_shared<TCtx>();
    ctx->fileName = "x.log";
    ctx->asyncTimeToSleep = 200;
    zoneMgr.LinkContext(ctx, a);

    // Start process
    zoneMgr.StartProcess(ctx, process->GetName(), b);

    auto start = ht_GetMSCount();
    while (true) {
        ioContext.run_one();
        auto delta = ht_GetMSCount() - start;
        if (delta > 1000)
            break;
    }
    zoneMgr.StopProcess(ctx);
    ioContext.run();

    auto state = zoneMgr.GetState(ctx);

    ASSERT_EQ(zoneMgr.GetZone(ctx).get(), a.get());
    ASSERT_EQ(state, std::nullopt);
}
