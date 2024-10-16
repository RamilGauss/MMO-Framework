/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <magic_enum.hpp>
#include "Base/Zones/AsyncHopProcess.h"

namespace nsBase::nsZones
{
    TAsyncHopProcess::TAsyncHopProcess(nsBase::nsCommon::TCoroInThread::Ptr coroInThread,
        nsBase::nsCommon::TStrandHolder::Ptr strandHolder)
        : IHopProcess(std::move(coroInThread), std::move(strandHolder))
    {
    }
    //-------------------------------------------------------------------------------------------------
    boost::asio::awaitable<void> TAsyncHopProcess::WorkInOtherThread()
    {
        mInnerState.commonCount = 500000;
        mInnerState.state = THopProcessState::State::WORK;

        while (true) {
            co_await mCoroInThread->GetStrandHolder()->Wait();
            if (mState.IsFinishedOrStopped())
                break;
            if (mInnerState.IsCompleted()) {
                mInnerState.state = THopProcessState::State::FINISH;
                break;
            } else {
                mInnerState.Increment();
                // call work() for do work
                Work();
            }
        }

        std::cout << "WorkInOtherThread ends id = " << std::this_thread::get_id() << std::endl;
        co_return;
    }
    //-------------------------------------------------------------------------------------------------
    boost::asio::awaitable<void> TAsyncHopProcess::FinishInOtherThread(nsBase::nsCommon::TStrandHolder::Ptr strandHolder,
        nsBase::nsCommon::TAsyncAwaitable::Ptr awaitable)
    {
        mState.state = THopProcessState::State::FINISH;
        strandHolder->Post([awaitable]() { awaitable->Resume(); });
        co_return;
    }
    //-------------------------------------------------------------------------------------------------
    boost::asio::awaitable<void> TAsyncHopProcess::StopInOtherThread(nsBase::nsCommon::TStrandHolder::Ptr strandHolder,
        nsBase::nsCommon::TAsyncAwaitable::Ptr awaitable)
    {
        mInnerState.state = THopProcessState::State::STOP;
        mState.state = THopProcessState::State::STOP;
        strandHolder->Post([awaitable]() { awaitable->Resume(); });
        co_return;
    }
    //-------------------------------------------------------------------------------------------------
    boost::asio::awaitable<void> TAsyncHopProcess::UpdateState(nsBase::nsCommon::TStrandHolder::Ptr strandHolder,
        nsBase::nsCommon::TAsyncAwaitable::Ptr awaitable,
        THopProcessState& state)
    {
        state = mInnerState;
        mState = mInnerState;
        strandHolder->Post([awaitable]() { awaitable->Resume(); });
        co_return;
    }
    //-------------------------------------------------------------------------------------------------
    boost::asio::awaitable<void> TAsyncHopProcess::Stop()
    {
        printf("Stop()\n");

        auto awaitable = nsBase::nsCommon::TAsyncAwaitable::New();

        mStrandHolder->Post([this, &awaitable]() {
            mCoroInThread->GetStrandHolder()->StartCoroutine([this, awaitable]() {
                return StopInOtherThread(mStrandHolder, awaitable); });
            });

        co_await awaitable->Wait();

        printf("Stop() ends\n");
    }
    //-------------------------------------------------------------------------------------------------
    boost::asio::awaitable<void> TAsyncHopProcess::Start()
    {
        printf("Start()\n");
        THopProcessState state;

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

            if (state.state == THopProcessState::State::STOP) {
                break;
            }
            if (state.state == THopProcessState::State::FINISH) {
                mStrandHolder->Post([this, awaitable]() {
                    mCoroInThread->GetStrandHolder()->StartCoroutine([this, awaitable]() {
                        return FinishInOtherThread(mStrandHolder, awaitable); });
                    });
                co_await awaitable->Wait();
                break;
            }
        }

        std::cout << "end cause " << magic_enum::enum_name(state.state) << ", id = " << std::this_thread::get_id() << std::endl;
    }
    //-------------------------------------------------------------------------------------------------
}
