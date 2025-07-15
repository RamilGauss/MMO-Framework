/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Zones/ContextState.h"
#include "Base/Zones/SyncSubProcess.h"

namespace nsBase::nsZones
{
    boost::asio::awaitable<void> TSyncSubProcess::Stop(SharedPtrHopProcessContext pCtx)
    {
        auto fit = mCtxStateMap.find(pCtx);
        if (fit == mCtxStateMap.end()) {
            co_return;
        }
        fit->second->state.SetState(TContextStateInProcess::State::CANCELED);
    }
    //-------------------------------------------------------------------------------------------------
    boost::asio::awaitable<bool> TSyncSubProcess::Start(SharedPtrHopProcessContext pCtx)
    {
        bool result = false;
        auto newState = std::make_shared<TContextState>();
        mCtxStateMap.insert({ pCtx, newState });

        Launch(pCtx);
        co_await mStrandHolder->Wait();

        newState->state.SetSubProcessTotalPartCount(GetTotalPartCount(pCtx));
        newState->state.SetState(TContextStateInProcess::State::WORKING);

        while (true) {
            co_await mStrandHolder->Wait();
            if (newState->state.IsFinishedOrStopped())
                break;
            if (newState->state.IsCompleted()) {
                newState->state.SetState(TContextStateInProcess::State::DONE);
                result = true;
                break;
            } else {
                Work(pCtx);
                newState->state.Increment();
            }
        }

        Finalize(pCtx);

        mCtxStateMap.erase(pCtx);
        co_return result;
    }
    //-------------------------------------------------------------------------------------------------
}
