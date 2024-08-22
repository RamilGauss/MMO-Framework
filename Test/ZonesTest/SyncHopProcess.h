/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Common/AsyncAwaitable.h"

#include "HopProcessState.h"

class TSyncHopProcess
{
    nsBase::nsCommon::TStrandHolder::Ptr mStrandHolder;
    THopProcessState mState;
public:
    virtual void Work() {};

    TSyncHopProcess(nsBase::nsCommon::TStrandHolder::Ptr strandHolder)
        : mStrandHolder(std::move(strandHolder))
    {
    }

    boost::asio::awaitable<void> Stop(std::function<void()> cb)
    {
        mState.state = "stop";
        cb();

        co_return;
    }

    boost::asio::awaitable<void> Start()
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

    THopProcessState GetState() const
    {
        return mState;
    }
};
