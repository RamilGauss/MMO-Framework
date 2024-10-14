/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/AsyncAwaitable.h"

#include "HopProcessState.h"

class IHopProcess
{
public:
    IHopProcess(nsBase::nsCommon::TCoroInThread::Ptr coroInThread,
        nsBase::nsCommon::TStrandHolder::Ptr strandHolder) :
        mStrandHolder(std::move(strandHolder)),
        mCoroInThread(std::move(coroInThread))
    {
    }
    virtual ~IHopProcess() {}

    virtual boost::asio::awaitable<void> Stop() = 0;
    virtual boost::asio::awaitable<void> Start() = 0;
    virtual THopProcessState GetState() const = 0;

    virtual void EndSubprocess() = 0;
protected:
    virtual void Work() {};

    // Main thread
    nsBase::nsCommon::TStrandHolder::Ptr mStrandHolder;

    // Second thread
    nsBase::nsCommon::TCoroInThread::Ptr mCoroInThread;
    THopProcessState mInnerState;
    THopProcessState mState;
};
