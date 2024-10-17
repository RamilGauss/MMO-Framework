/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Zones/SyncHopProcess.h"

namespace nsBase::nsZones
{
    TSyncHopProcess::TSyncHopProcess(nsBase::nsCommon::TCoroInThread::Ptr coroInThread,
        nsBase::nsCommon::TStrandHolder::Ptr strandHolder)
        : IHopProcess(std::move(coroInThread), std::move(strandHolder))
    {
    }
    //-------------------------------------------------------------------------------------------------
    boost::asio::awaitable<void> TSyncHopProcess::Stop(IHopProcessContext* pCtx)
    {
        mState.state = THopProcessState::State::STOP;
        co_return;
    }
    //-------------------------------------------------------------------------------------------------
    boost::asio::awaitable<void> TSyncHopProcess::Start(IHopProcessContext* pCtx)
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
}
