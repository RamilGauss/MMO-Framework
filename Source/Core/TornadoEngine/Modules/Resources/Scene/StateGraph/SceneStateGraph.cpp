/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "SceneStateGraph.h"

#include "Base/Zones/ContextState.h"

#include "Modules/Resources/Scene/StateGraph/Instantiate/InstantiateProcess.h"
#include "Modules/Resources/Scene/StateGraph/CancelInstantiate/CancelInstantiateProcess.h"
#include "Modules/Resources/Scene/StateGraph/Destroy/DestroyProcess.h"
#include "Modules/Resources/Scene/StateGraph/Save/SaveProcess.h"

#include "Modules/Resources/Scene/StateGraph/SceneContext.h"

namespace nsTornadoEngine
{
    TSceneStateGraph::TSceneStateGraph() 
    {
        mStrandHolder = nsBase::nsCommon::TStrandHolder::New(mIoContext);
        mCoroInThread = nsBase::nsCommon::TCoroInThread::New();
    }
    //---------------------------------------------------------------------------------
    void TSceneStateGraph::Init()
    {
        mZoneMng.Init(mStrandHolder, mCoroInThread);

        mInitZone = std::make_shared<nsBase::nsZones::TZone>(ToString(Zone::INIT));
        mInstantiatedZone = std::make_shared<nsBase::nsZones::TZone>(ToString(Zone::INSTANTIATED));
        mDestroyedZone = std::make_shared<nsBase::nsZones::TZone>(ToString(Zone::DESTROYED));
        mDeadZone = std::make_shared<nsBase::nsZones::TZone>(ToString(Zone::DEAD));

        mZoneMng.AddZone(mInitZone);
        mZoneMng.AddZone(mInstantiatedZone);
        mZoneMng.AddZone(mDestroyedZone);
        mZoneMng.AddZone(mDeadZone);

        auto instantiateProcess = std::make_shared<TInstantiateProcess>(ToString(Process::INSTANTIATE));
        //auto cancelInstantiateProcess = std::make_shared<TInstantiateProcess>(ToString(Process::CANCEL_INSTANTIATE));
        //auto destroyProcess = std::make_shared<TInstantiateProcess>(ToString(Process::DESTROY));
        //auto saveProcess = std::make_shared<TInstantiateProcess>(ToString(Process::SAVE));
        mInitZone->AddProcess(instantiateProcess);
        //mInitZone->AddProcess(cancelInstantiateProcess);
        //mInitZone->AddProcess(destroyProcess);
        //mInitZone->AddProcess(saveProcess);
    }
    //---------------------------------------------------------------------------------
    void TSceneStateGraph::Work(int maxDuration)
    {
        mIoContext.run_for(std::chrono::milliseconds(maxDuration));
    }
    //---------------------------------------------------------------------------------
    void TSceneStateGraph::StartProcess(Process process, TSceneContextPtr pCtx)
    {
        mZoneMng.LinkContext(pCtx, mInitZone);
        mZoneMng.StartProcess(pCtx, ToString(process), mInstantiatedZone);
    }
    //---------------------------------------------------------------------------------
    void TSceneStateGraph::StopProcess(TSceneContextPtr pCtx)
    {
        mZoneMng.StopProcess(pCtx);
    }
    //---------------------------------------------------------------------------------
    std::optional<std::string> TSceneStateGraph::GetZoneName(TSceneContextPtr pCtx) const
    {
        auto pZone = mZoneMng.GetZone(pCtx);
        if (pZone)
            return { pZone->GetName() };
        return std::nullopt;
    }
    //---------------------------------------------------------------------------------
    std::optional<nsBase::nsZones::TContextStateInProcess> TSceneStateGraph::GetSceneInstanceState(TSceneContextPtr pCtx)
    {
        return mZoneMng.GetState(pCtx);
    }
    //---------------------------------------------------------------------------------
}
