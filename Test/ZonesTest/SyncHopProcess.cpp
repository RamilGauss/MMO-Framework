/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "SyncHopProcess.h"

TSyncHopProcess::TSyncHopProcess(nsBase::nsCommon::TStrandHolder::Ptr strandHolder)
    : mStrandHolder(std::move(strandHolder))
{
}
//-------------------------------------------------------------------------------------------------
boost::asio::awaitable<void> TSyncHopProcess::Stop()
{
    mState.state = "stop";
    co_return;
}
//-------------------------------------------------------------------------------------------------
boost::asio::awaitable<void> TSyncHopProcess::Start()
{
    mState.commonCount = 500000;
    mState.state = "work";

    while (true) {
        co_await mStrandHolder->Wait();
        if (mState.IsFinishedOrStopped())
            break;
        if (mState.IsCompleted()) {
            mState.state = "finish";
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
