/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "InstantiateProcess.h"
#include "Base/Zones/Zone.h"

namespace nsTornadoEngine
{
    boost::asio::awaitable<bool> TInstantiateProcess::Start(nsBase::nsZones::SharedPtrHopProcessContext pCtx)
    {
        SetCurrentSubProcess(pCtx, &mSceneFileOpeningProcess);
        if (co_await mSceneFileOpeningProcess.Start(pCtx) == false) {
            co_return false;
        }
        //SetCurrentSubProcess(pCtx, &mAsyncSubProcess);
        //if (co_await mAsyncSubProcess.Start(pCtx) == false) {
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
        mSceneFileOpeningProcess.Init(strandHolder, coroInThread);
        //mAsyncSubProcess.Init(strandHolder, coroInThread);
        //mSyncSubProcess.Init(strandHolder, coroInThread);
    }
    //-------------------------------------------------------------------------------
}
