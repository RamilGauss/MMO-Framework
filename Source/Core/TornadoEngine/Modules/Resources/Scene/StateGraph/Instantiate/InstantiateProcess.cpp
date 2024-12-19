/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "InstantiateProcess.h"
#include "Base/Zones/Zone.h"

#include "Modules/Resources/Scene/StateGraph/SceneContext.h"

namespace nsTornadoEngine
{
    boost::asio::awaitable<bool> TInstantiateProcess::Start(nsBase::nsZones::SharedPtrHopProcessContext pCtx)
    {
        SetCurrentSubProcess(pCtx, &mSceneFileLoadingProcess);
        if (co_await mSceneFileLoadingProcess.Start(pCtx) == false) {
            co_return false;
        }
        SetCurrentSubProcess(pCtx, &mSceneDeserializingProcess);
        if (co_await mSceneDeserializingProcess.Start(pCtx) == false) {
            co_return false;
        }
        SetCurrentSubProcess(pCtx, &mCollectGuidsProcess);
        if (co_await mCollectGuidsProcess.Start(pCtx) == false) {
            co_return false;
        }

        //SetCurrentSubProcess(pCtx, pNextSubProcess);
        //if (co_await mPrepareTreeEntityProcess.Start(pCtx) == false) {
        //    co_return false;
        //}

        SetCurrentSubProcess(pCtx, nullptr);
        co_return true;
    }
    //-------------------------------------------------------------------------------
    boost::asio::awaitable<void> TInstantiateProcess::Stop(nsBase::nsZones::SharedPtrHopProcessContext pCtx)
    {
        auto currentSubProcess = GetCurrentSubProcess(pCtx);
        if (currentSubProcess)
            co_await currentSubProcess->Stop(pCtx);
    }
    //-------------------------------------------------------------------------------
    nsBase::nsZones::TContextStateInProcess TInstantiateProcess::GetState(nsBase::nsZones::SharedPtrHopProcessContext pCtx) const
    {
        auto currentSubProcess = GetCurrentSubProcess(pCtx);
        if (currentSubProcess)
            return currentSubProcess->GetState(pCtx);
        return {};
    }
    //-------------------------------------------------------------------------------
    void TInstantiateProcess::InitSubProcesses(nsBase::nsCommon::TStrandHolder::Ptr strandHolder,
        nsBase::nsCommon::TCoroInThread::Ptr coroInThread)
    {
        mSceneFileLoadingProcess.Init(strandHolder, coroInThread);
        mSceneDeserializingProcess.Init(strandHolder, coroInThread);
        mComponentDeserializingProcess.Init(strandHolder, coroInThread);
        mCollectGuidsProcess.Init(strandHolder, coroInThread);
        mPrepareTreeEntityProcess.Init(strandHolder, coroInThread);
        mSortingEntityByRankProcess.Init(strandHolder, coroInThread);
    }
    //-------------------------------------------------------------------------------
}
