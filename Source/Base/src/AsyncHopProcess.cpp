/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/


#include <iostream>
#include <magic_enum.hpp>
#include "Base/Zones/AsyncHopProcess.h"
#include "Base/Zones/ContextState.h"

namespace nsBase::nsZones
{
    TAsyncHopProcess::TAsyncHopProcess(nsBase::nsCommon::TCoroInThread::Ptr coroInThread,
        nsBase::nsCommon::TStrandHolder::Ptr strandHolder)
        : IHopProcess(std::move(coroInThread), std::move(strandHolder))
    {
    }
    //-------------------------------------------------------------------------------------------------
    boost::asio::awaitable<void> TAsyncHopProcess::WorkInOtherThread(SharedPtrContextState pState)
    {
        pState->inner.commonCount = 500000;
        pState->inner.state = TContextStateInProcess::State::WORK;

        while (true) {
            co_await mCoroInThread->GetStrandHolder()->Wait();
            if (pState->state.IsFinishedOrStopped())
                break;
            if (pState->inner.IsCompleted()) {
                pState->inner.state = TContextStateInProcess::State::FINISH;
                break;
            } else {
                pState->inner.Increment();
                Work();
            }
        }

        std::cout << "WorkInOtherThread ends id = " << std::this_thread::get_id() << std::endl;
        co_return;
    }
    //-------------------------------------------------------------------------------------------------
    boost::asio::awaitable<void> TAsyncHopProcess::FinishInOtherThread(nsBase::nsCommon::TStrandHolder::Ptr strandHolder,
        nsBase::nsCommon::TAsyncAwaitable::Ptr awaitable, SharedPtrContextState pState)
    {
        pState->state.state = TContextStateInProcess::State::FINISH;
        strandHolder->Post([awaitable]() { awaitable->Resume(); });
        co_return;
    }
    //-------------------------------------------------------------------------------------------------
    boost::asio::awaitable<void> TAsyncHopProcess::StopInOtherThread(nsBase::nsCommon::TStrandHolder::Ptr strandHolder,
        nsBase::nsCommon::TAsyncAwaitable::Ptr awaitable, SharedPtrContextState pState)
    {
        pState->inner.state = TContextStateInProcess::State::STOP;
        pState->state.state = TContextStateInProcess::State::STOP;
        strandHolder->Post([awaitable]() { awaitable->Resume(); });
        co_return;
    }
    //-------------------------------------------------------------------------------------------------
    boost::asio::awaitable<void> TAsyncHopProcess::UpdateState(nsBase::nsCommon::TStrandHolder::Ptr strandHolder,
        nsBase::nsCommon::TAsyncAwaitable::Ptr awaitable,
        SharedPtrContextState pState)
    {
        pState->state = pState->inner;
        strandHolder->Post([awaitable]() { awaitable->Resume(); });
        co_return;
    }
    //-------------------------------------------------------------------------------------------------
    boost::asio::awaitable<void> TAsyncHopProcess::Stop(IHopProcessContext* pCtx)
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
    boost::asio::awaitable<void> TAsyncHopProcess::Start(IHopProcessContext* pCtx)
    {
        auto newState = std::make_shared<TContextState>();
        mCtxStateMap.insert({ pCtx, newState });

        printf("Start()\n");

        mStrandHolder->Post([this, newState]() {
            mCoroInThread->GetStrandHolder()->StartCoroutine([this, newState]() {return WorkInOtherThread(newState); });
            });

        auto awaitable = nsBase::nsCommon::TAsyncAwaitable::New();
        while (true) {
            mStrandHolder->Post([this, awaitable, newState]() {
                mCoroInThread->GetStrandHolder()->StartCoroutine([this, awaitable, newState]() {
                    return UpdateState(mStrandHolder, awaitable, newState); });
                });
            co_await awaitable->Wait();

            std::cout << "Progress " << newState->state.GetProgress() << " %" << std::endl;

            using namespace std::literals;
            std::this_thread::sleep_for(10ms);

            if (newState->state.state == TContextStateInProcess::State::STOP) {
                break;
            }
            if (newState->state.state == TContextStateInProcess::State::FINISH) {
                mStrandHolder->Post([this, awaitable, newState]() {
                    mCoroInThread->GetStrandHolder()->StartCoroutine([this, awaitable, newState]() {
                        return FinishInOtherThread(mStrandHolder, awaitable, newState); });
                    });
                co_await awaitable->Wait();
                break;
            }
        }

        std::cout << "end cause " << magic_enum::enum_name(newState->state.state) << ", id = " << std::this_thread::get_id() << std::endl;

        mCtxStateMap.erase(pCtx);
    }
    //-------------------------------------------------------------------------------------------------
}
