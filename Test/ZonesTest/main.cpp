/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "gtest/gtest.h"

#include "Base/Common/CoroInThread.h"
#include "Base/Common/AsyncAwaitable.h"

struct State
{
    int commonCount = 0;
    int progressCount = 0;

    std::string state;

    void Increment()
    {
        progressCount++;
    }

    float GetProgress() const
    {
        if (commonCount == 0)
            return -1.0f;
        return (progressCount * 100.0f) / commonCount;
    }

    bool IsCompleted() const
    {
        return commonCount == progressCount;
    }

    bool IsFinishedOrStopped() const
    {
        return state == "stop" || state == "finish";
    }
    bool IsWork() const
    {
        return state == "work";
    }
};


class HopProcess
{
    // Main thread
    nsBase::nsCommon::TStrandHolder::Ptr mStrandHolder;

    // Second thread
    nsBase::nsCommon::TCoroInThread* mCoroInThread = nullptr;
    State mInnerState;
    State mState;
public:
    HopProcess(nsBase::nsCommon::TCoroInThread* coroInThread,
        nsBase::nsCommon::TStrandHolder::Ptr strandHolder)
        : mStrandHolder(std::move(strandHolder)),
        mCoroInThread(coroInThread)
    {
    }
    //-------------------------------------------------------------------------------------------------
    boost::asio::awaitable<void> WorkInOtherThread()
    {
        mInnerState.commonCount = 500000;
        mInnerState.state = "work";

        while (true) {
            co_await mCoroInThread->GetStrandHolder()->Wait();
            if (mState.IsFinishedOrStopped())
                break;
            if (mInnerState.IsCompleted()) {
                mInnerState.state = "finish";
            } else {
                mInnerState.Increment();
            }
        }

        std::cout << "WorkInOtherThread ends id = " << std::this_thread::get_id() << std::endl;
        co_return;
    }

    boost::asio::awaitable<void> FinishInOtherThread(nsBase::nsCommon::TStrandHolder::Ptr strandHolder,
        nsBase::nsCommon::TAsyncAwaitable::Ptr awaitable)
    {
        mState.state = "finish";
        strandHolder->Post([awaitable]() { awaitable->Resume(); });
        co_return;
    }

    boost::asio::awaitable<void> StopInOtherThread(nsBase::nsCommon::TStrandHolder::Ptr strandHolder,
        nsBase::nsCommon::TAsyncAwaitable::Ptr awaitable)
    {
        mInnerState.state = "stop";
        mState.state = "stop";
        strandHolder->Post([awaitable]() { awaitable->Resume(); });
        co_return;
    }

    boost::asio::awaitable<void> UpdateState(nsBase::nsCommon::TStrandHolder::Ptr strandHolder,
        nsBase::nsCommon::TAsyncAwaitable::Ptr awaitable,
        State& state)
    {
        state = mInnerState;
        mState = mInnerState;
        strandHolder->Post([awaitable]() { awaitable->Resume(); });
        co_return;
    }
    //-------------------------------------------------------------------------------------------------
    boost::asio::awaitable<void> Stop(std::function<void()> cb)
    {
        printf("Stop()\n");

        auto awaitable = nsBase::nsCommon::TAsyncAwaitable::New();

        mStrandHolder->Post([this, &awaitable]() {
            mCoroInThread->GetStrandHolder()->StartCoroutine([this, awaitable]() {
                return StopInOtherThread(mStrandHolder, awaitable); });
            });

        co_await awaitable->Wait();

        cb();
        printf("Stop() ends\n");
    }

    boost::asio::awaitable<void> Start()
    {
        printf("Start()\n");
        State state;

        mStrandHolder->Post([this]() {
            mCoroInThread->GetStrandHolder()->StartCoroutine([this]() {return WorkInOtherThread(); });
            });

        auto awaitable = nsBase::nsCommon::TAsyncAwaitable::New();
        while (true) {
            mStrandHolder->Post([this, awaitable, &state]() {
                mCoroInThread->GetStrandHolder()->StartCoroutine([this, awaitable, &state]() {
                    return UpdateState(mStrandHolder, awaitable, state); });
                });
            co_await awaitable->Wait();

            std::cout << "Progress " << state.GetProgress() << " %" << std::endl;

            using namespace std::literals;
            std::this_thread::sleep_for(10ms);

            if (state.state == "stop") {
                break;
            }
            if (state.state == "finish") {
                mStrandHolder->Post([this, awaitable]() {
                    mCoroInThread->GetStrandHolder()->StartCoroutine([this, awaitable]() {
                        return FinishInOtherThread(mStrandHolder, awaitable); });
                    });
                co_await awaitable->Wait();
                break;
            }
        }

        std::cout << "end cause " << state.state << ", id = " << std::this_thread::get_id() << std::endl;
    }

    State GetState() const
    {
        return mState;
    }
};


int main(int argc, char** argv)
{
    boost::asio::io_context ioContext;
    nsBase::nsCommon::TStrandHolder::Ptr strandHolder = nsBase::nsCommon::TStrandHolder::New(ioContext);
    nsBase::nsCommon::TCoroInThread coroInThread;

    HopProcess hopProcess(&coroInThread, strandHolder);
    coroInThread.Start();

    strandHolder->StartCoroutine([&hopProcess]() {return hopProcess.Start(); });

    bool isStopping = false;

    while (true) {
        auto quantUsedCount = ioContext.run_one();

        using namespace std::literals;
        std::this_thread::sleep_for(10ms);

        if (hopProcess.GetState().IsWork() && 
            hopProcess.GetState().GetProgress() > 70) {

            if (!isStopping) {
                isStopping = true;
                strandHolder->StartCoroutine([&hopProcess, &isStopping]() {
                    return hopProcess.Stop([&isStopping]() {
                        isStopping = false;
                }); });
            }
        }
    }

    ::testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    return 0;
}
