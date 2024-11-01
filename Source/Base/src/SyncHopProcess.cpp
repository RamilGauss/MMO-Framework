/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Zones/ContextState.h"
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
        auto fit = mCtxStateMap.find(pCtx);
        if (fit == mCtxStateMap.end()) {
            co_return;
        }
        auto state = fit->second;

        state->state.state = THopProcessState::State::STOP;
        co_return;
    }
    //-------------------------------------------------------------------------------------------------
    boost::asio::awaitable<void> TSyncHopProcess::Start(IHopProcessContext* pCtx)
    {
        auto newState = std::make_shared<TContextState>();
        mCtxStateMap.insert({ pCtx, newState });

        newState->state.commonCount = 500000;
        newState->state.state = THopProcessState::State::WORK;

        while (true) {
            co_await mStrandHolder->Wait();
            if (newState->state.IsFinishedOrStopped())
                break;
            if (newState->state.IsCompleted()) {
                newState->state.state = THopProcessState::State::FINISH;
                break;
            } else {
                Work();
                newState->state.Increment();
            }
        }

        mCtxStateMap.erase(pCtx);
    }
    //-------------------------------------------------------------------------------------------------
}
