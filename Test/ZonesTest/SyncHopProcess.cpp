/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "SyncHopProcess.h"

TSyncHopProcess::TSyncHopProcess(nsBase::nsCommon::TCoroInThread::Ptr coroInThread, 
    nsBase::nsCommon::TStrandHolder::Ptr strandHolder)
    : IHopProcess(std::move(coroInThread), std::move(strandHolder))//mStrandHolder(std::move(strandHolder))
{
}
//-------------------------------------------------------------------------------------------------
boost::asio::awaitable<void> TSyncHopProcess::Stop()
{
    mState.state = THopProcessState::State::STOP;
    co_return;
}
//-------------------------------------------------------------------------------------------------
boost::asio::awaitable<void> TSyncHopProcess::Start()
{
    mState.commonCount = 500000;
    mState.state = THopProcessState::State::WORK;

    while (true) {
        co_await mStrandHolder->Wait();
        if (mState.IsFinishedOrStopped())
            break;
        if (mState.IsCompleted()) {
            mState.state = THopProcessState::State::FINISH;
            break;
        } else {
            Work();
            mState.Increment();
        }
    }
}
//-------------------------------------------------------------------------------------------------
THopProcessState TSyncHopProcess::GetState() const
{
    return mState;
}
//-------------------------------------------------------------------------------------------------
