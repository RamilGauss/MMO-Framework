/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/CoroInThread.h"
#include "Base/Common/AsyncAwaitable.h"

#include "HopProcessState.h"

class TAsyncHopProcess
{
    // Main thread
    nsBase::nsCommon::TStrandHolder::Ptr mStrandHolder;

    // Second thread
    nsBase::nsCommon::TCoroInThread* mCoroInThread = nullptr;
    THopProcessState mInnerState;
    THopProcessState mState;
public:

    TAsyncHopProcess(nsBase::nsCommon::TCoroInThread* coroInThread,
        nsBase::nsCommon::TStrandHolder::Ptr strandHolder);
    boost::asio::awaitable<void> Stop();
    boost::asio::awaitable<void> Start();
    THopProcessState GetState() const;

protected:
    virtual void Work() {};

    boost::asio::awaitable<void> WorkInOtherThread();
    boost::asio::awaitable<void> FinishInOtherThread(nsBase::nsCommon::TStrandHolder::Ptr strandHolder,
        nsBase::nsCommon::TAsyncAwaitable::Ptr awaitable);
    boost::asio::awaitable<void> StopInOtherThread(nsBase::nsCommon::TStrandHolder::Ptr strandHolder,
        nsBase::nsCommon::TAsyncAwaitable::Ptr awaitable);
    boost::asio::awaitable<void> UpdateState(nsBase::nsCommon::TStrandHolder::Ptr strandHolder,
        nsBase::nsCommon::TAsyncAwaitable::Ptr awaitable,
        THopProcessState& state);
};
