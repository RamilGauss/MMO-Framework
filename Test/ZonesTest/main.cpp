/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "gtest/gtest.h"

#include "Base/Common/CoroInThread.h"
#include "Base/Common/AsyncAwaitable.h"

class HopProcess
{
    nsBase::nsCommon::TCoroInThread* mCoroInThread = nullptr;
    nsBase::nsCommon::TStrandHolder::Ptr mStrandHolder;


    std::string mInnerState;
    std::string mState;

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
        mInnerState = "work";

        int count = 0;
        while (true) {
            co_await mCoroInThread->GetStrandHolder()->Wait();
            count++;
            if (count > 1000000) {
                mInnerState = "finish";
            }
            if (mState == "finish" || mState == "stop")
                break;
        }

        std::cout << "WorkInOtherThread ends id = " << std::this_thread::get_id() << std::endl;
        co_return;
    }

    boost::asio::awaitable<void> FinishInOtherThread(nsBase::nsCommon::TStrandHolder::Ptr strandHolder,
        nsBase::nsCommon::TAsyncAwaitable::Ptr awaitable)
    {
        mState = "finish";
        strandHolder->Post([awaitable]() { awaitable->Resume(); });
        co_return;
    }

    boost::asio::awaitable<void> StopInOtherThread(nsBase::nsCommon::TStrandHolder::Ptr strandHolder,
        nsBase::nsCommon::TAsyncAwaitable::Ptr awaitable)
    {
        mState = "stop";
        strandHolder->Post([awaitable]() { awaitable->Resume(); });
        co_return;
    }

    boost::asio::awaitable<void> UpdateState(nsBase::nsCommon::TStrandHolder::Ptr strandHolder,
        nsBase::nsCommon::TAsyncAwaitable::Ptr awaitable,
        std::string& state)
    {
        state = mInnerState;
        mState = mInnerState;
        strandHolder->Post([awaitable]() { awaitable->Resume(); });
        co_return;
    }
    //-------------------------------------------------------------------------------------------------
    boost::asio::awaitable<void> Stop()
    {
        auto awaitable = nsBase::nsCommon::TAsyncAwaitable::New();

        mStrandHolder->Post([this, &awaitable]() {
            mCoroInThread->GetStrandHolder()->StartCoroutine([this, awaitable]() {
                return StopInOtherThread(mStrandHolder, awaitable); });
            });

        co_await awaitable->Wait();
    }

    boost::asio::awaitable<void> Start()
    {
        printf("Start()\n");
        std::string state;

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


            if (state == "stop") {
                break;
            }
            if (state == "finish") {
                mStrandHolder->Post([this, awaitable]() {
                    mCoroInThread->GetStrandHolder()->StartCoroutine([this, awaitable]() {
                        return FinishInOtherThread(mStrandHolder, awaitable); });
                    });
                co_await awaitable->Wait();
                break;
            }
        }

        std::cout << "end cause " << state << ", id = " << std::this_thread::get_id() << std::endl;
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

    while (true) {
        auto quantUsedCount = ioContext.run_one();
        //if (quantUsedCount == 0) {
            using namespace std::literals;
            std::this_thread::sleep_for(10ms);
        //}
    }

    ::testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    return 0;
}
