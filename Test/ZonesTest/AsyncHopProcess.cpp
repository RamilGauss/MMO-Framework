/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "AsyncHopProcess.h"

TAsyncHopProcess::TAsyncHopProcess(nsBase::nsCommon::TCoroInThread* coroInThread,
    nsBase::nsCommon::TStrandHolder::Ptr strandHolder)
    : mStrandHolder(std::move(strandHolder)),
    mCoroInThread(coroInThread)
{
}
//-------------------------------------------------------------------------------------------------
boost::asio::awaitable<void> TAsyncHopProcess::WorkInOtherThread()
{
    mInnerState.commonCount = 500000;
    mInnerState.state = "work";

    while (true) {
        co_await mCoroInThread->GetStrandHolder()->Wait();
        if (mState.IsFinishedOrStopped())
            break;
        if (mInnerState.IsCompleted()) {
            mInnerState.state = "finish";
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
    mState.state = "finish";
    strandHolder->Post([awaitable]() { awaitable->Resume(); });
    co_return;
}
//-------------------------------------------------------------------------------------------------
boost::asio::awaitable<void> TAsyncHopProcess::StopInOtherThread(nsBase::nsCommon::TStrandHolder::Ptr strandHolder,
    nsBase::nsCommon::TAsyncAwaitable::Ptr awaitable)
{
    mInnerState.state = "stop";
    mState.state = "stop";
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
//-------------------------------------------------------------------------------------------------
THopProcessState TAsyncHopProcess::GetState() const
{
    return mState;
}
//-------------------------------------------------------------------------------------------------
