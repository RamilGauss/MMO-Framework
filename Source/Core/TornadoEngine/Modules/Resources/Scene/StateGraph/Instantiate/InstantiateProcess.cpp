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
        auto ctx = std::static_pointer_cast<TSceneContext>(pCtx);
        auto sceneCache = ctx->cacheManager->Get(ctx->instantiateSceneParams.guid);

        if (sceneCache == nullptr) {
            SetCurrentSubProcess(pCtx, &mSceneFileLoadingProcess);
            if (co_await mSceneFileLoadingProcess.Start(pCtx) == false) {
                co_return false;
            }
            SetCurrentSubProcess(pCtx, &mSceneDeserializingProcess);
            if (co_await mSceneDeserializingProcess.Start(pCtx) == false) {
                co_return false;
            }
            SetCurrentSubProcess(pCtx, &mComponentDeserializingProcess);
            if (co_await mComponentDeserializingProcess.Start(pCtx) == false) {
                co_return false;
            }
            ctx->cacheManager->Add(ctx->instantiateSceneParams.guid, ctx->sceneContent);
        } else {
            ctx->sceneContent = sceneCache;
        }

        SetCurrentSubProcess(pCtx, &mUniverseIndexCreatingProcess);
        if (co_await mUniverseIndexCreatingProcess.Start(pCtx) == false) {
            co_return false;
        }
        SetCurrentSubProcess(pCtx, &mEntityInstantiatingProcess);
        if (co_await mEntityInstantiatingProcess.Start(pCtx) == false) {
            co_return false;
        }
        SetCurrentSubProcess(pCtx, &mPrefabInstantiatingProcess);
        if (co_await mPrefabInstantiatingProcess.Start(pCtx) == false) {
            co_return false;
        }

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

        mUniverseIndexCreatingProcess.Init(strandHolder, coroInThread);
        mPrefabInstantiatingProcess.Init(strandHolder, coroInThread);
        mEntityInstantiatingProcess.Init(strandHolder, coroInThread);
    }
    //-------------------------------------------------------------------------------
}
