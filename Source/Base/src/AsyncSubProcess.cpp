/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/


#include <iostream>
#include <magic_enum.hpp>
#include "Base/Zones/AsyncSubProcess.h"
#include "Base/Zones/ContextState.h"

namespace nsBase::nsZones
{
    boost::asio::awaitable<void> TAsyncSubProcess::WorkInOtherThread(SharedPtrHopProcessContext pCtx, SharedPtrContextState pState)
    {
        pState->inner.SetSubProcessTotalPartCount(GetSubProcessTotalPartCount(pCtx));
        pState->inner.SetState(TContextStateInProcess::State::WORKING);

        while (true) {
            co_await mCoroInThread->GetStrandHolder()->Wait();
            if (pState->state.IsFinishedOrStopped())
                break;
            if (pState->inner.IsCompleted()) {
                pState->inner.SetState(TContextStateInProcess::State::DONE);
                break;
            } else {
                pState->inner.Increment();
                Work(pCtx);
            }
        }

        std::cout << "WorkInOtherThread ends id = " << std::this_thread::get_id() << std::endl;
        co_return;
    }
    //-------------------------------------------------------------------------------------------------
    boost::asio::awaitable<void> TAsyncSubProcess::FinishInOtherThread(nsBase::nsCommon::TStrandHolder::Ptr strandHolder,
        nsBase::nsCommon::TAsyncAwaitable::Ptr awaitable, SharedPtrContextState pState)
    {
        pState->state.SetState(TContextStateInProcess::State::DONE);
        strandHolder->Post([awaitable]() { awaitable->Resume(); });
        co_return;
    }
    //-------------------------------------------------------------------------------------------------
    boost::asio::awaitable<void> TAsyncSubProcess::StopInOtherThread(nsBase::nsCommon::TStrandHolder::Ptr strandHolder,
        nsBase::nsCommon::TAsyncAwaitable::Ptr awaitable, SharedPtrContextState pState)
    {
        pState->inner.SetState(TContextStateInProcess::State::CANCELED);
        pState->state.SetState(TContextStateInProcess::State::CANCELED);
        strandHolder->Post([awaitable]() { awaitable->Resume(); });
        co_return;
    }
    //-------------------------------------------------------------------------------------------------
    boost::asio::awaitable<void> TAsyncSubProcess::UpdateState(nsBase::nsCommon::TStrandHolder::Ptr strandHolder,
        nsBase::nsCommon::TAsyncAwaitable::Ptr awaitable,
        SharedPtrContextState pState)
    {
        pState->state = pState->inner;
        strandHolder->Post([awaitable]() { awaitable->Resume(); });
        co_return;
    }
    //-------------------------------------------------------------------------------------------------
    boost::asio::awaitable<void> TAsyncSubProcess::Stop(SharedPtrHopProcessContext pCtx)
    {
        auto fit = mCtxStateMap.find(pCtx);
        if (fit == mCtxStateMap.end()) {
            co_return;
        }
        auto state = fit->second;
        printf("Stop()\n");

        auto awaitable = nsBase::nsCommon::TAsyncAwaitable::New();

        mStrandHolder->Post([this, &awaitable, state]() {
            mCoroInThread->GetStrandHolder()->StartCoroutine([this, awaitable, state]() {
                return StopInOtherThread(mStrandHolder, awaitable, state); });
            });

        co_await awaitable->Wait();

        printf("Stop() ends\n");
    }
    //-------------------------------------------------------------------------------------------------
    boost::asio::awaitable<void> TAsyncSubProcess::Start(SharedPtrHopProcessContext pCtx)
    {
        auto newState = std::make_shared<TContextState>();
        mCtxStateMap.insert({ pCtx, newState });

        printf("Start()\n");

        mStrandHolder->Post([this, pCtx, newState]() {
            mCoroInThread->GetStrandHolder()->StartCoroutine([this, pCtx, newState]() {return WorkInOtherThread(pCtx, newState); });
            });

        auto awaitable = nsBase::nsCommon::TAsyncAwaitable::New();
        while (true) {
            mStrandHolder->Post([this, awaitable, newState]() {
                mCoroInThread->GetStrandHolder()->StartCoroutine([this, awaitable, newState]() {
                    return UpdateState(mStrandHolder, awaitable, newState); });
                });
            co_await awaitable->Wait();

            //std::cout << "Progress " << newState->state.GetProgress() << " %" << std::endl;

            using namespace std::literals;
            std::this_thread::sleep_for(10ms);

            if (newState->state.GetState() == TContextStateInProcess::State::CANCELED) {
                break;
            }
            if (newState->state.GetState() == TContextStateInProcess::State::DONE) {
                mStrandHolder->Post([this, awaitable, newState]() {
                    mCoroInThread->GetStrandHolder()->StartCoroutine([this, awaitable, newState]() {
                        return FinishInOtherThread(mStrandHolder, awaitable, newState); });
                    });
                co_await awaitable->Wait();
                break;
            }
        }

        std::cout << "end cause " << magic_enum::enum_name(newState->state.GetState()) << ", id = " << std::this_thread::get_id() << std::endl;

        mCtxStateMap.erase(pCtx);
    }
    //-------------------------------------------------------------------------------------------------
}
