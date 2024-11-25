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

        //mZoneMng.AddZone();
        //mZoneMng.Remove
    }
    //---------------------------------------------------------------------------------
    void TSceneStateGraph::Work(int maxDuration)
    {
        mIoContext.run_for(std::chrono::milliseconds(maxDuration));
    }
    //---------------------------------------------------------------------------------
    void TSceneStateGraph::StartProcess(Process process, TSceneContextPtr pCtx)
    {
        //pCtx->GetContextState().StartProcess(GetProcessName(process));
    }
    //---------------------------------------------------------------------------------
    void TSceneStateGraph::StopProcess(TSceneContext* pCtx)
    {
        //pCtx->GetContextState().StopProcess();
    }
    //---------------------------------------------------------------------------------
    std::optional<std::string> TSceneStateGraph::GetZoneName(TSceneContextPtr pCtx) const
    {
        //auto pZone = pCtx->GetOwnerZone();
        //if (pZone)
            //return pZone->GetName();
        return std::nullopt;
    }
    //---------------------------------------------------------------------------------
    std::optional<nsBase::nsZones::TContextStateInProcess> TSceneStateGraph::GetSceneInstanceState(TSceneContextPtr pCtx)
    {
        return mZoneMng.GetState(pCtx);
    }
    //---------------------------------------------------------------------------------
}
