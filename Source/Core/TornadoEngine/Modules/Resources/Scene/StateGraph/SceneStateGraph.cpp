/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "SceneStateGraph.h"

#include <magic_enum.hpp>

#include "Base/Zones/ContextState.h"

#include "Modules/Resources/Scene/StateGraph/CancelInstantiate/CancelInstantiateProcess.h"
#include "Modules/Resources/Scene/StateGraph/Destroy/DestroyProcess.h"
#include "Modules/Resources/Scene/StateGraph/Instantiate/InstantiateProcess.h"
#include "Modules/Resources/Scene/StateGraph/Save/SaveProcess.h"

#include "Modules/Resources/Scene/StateGraph/SceneContext.h"

namespace nsTornadoEngine
{
    const std::array<std::string, magic_enum::enum_count<TSceneStateGraph::Process>()> PROCESS_NAMES =
    {
        "Instantiate",
        "Cancel instantiate",
        "Save",
        "Destroy"
    };

    std::string GetName(TSceneStateGraph::Process process)
    {
        return PROCESS_NAMES[(int)process];
    }

    TSceneStateGraph::TSceneStateGraph() :
        mInitZone("Init"),
        mInstantiatedZone("Instantiated"),
        mDestroyedZone("Destroy"),
        mDeadZone("Dead")
    {

    }
    //---------------------------------------------------------------------------------
    void TSceneStateGraph::Init()
    {
        mZoneMng.AddZone(&mInitZone);
        mZoneMng.AddZone(&mInstantiatedZone);
        mZoneMng.AddZone(&mDestroyedZone);
        mZoneMng.AddZone(&mDeadZone);

        AddProcess<TInstantiateProcess>(GetName(Process::INSTANTIATE), &mInitZone, &mInstantiatedZone);
        AddProcess<TCancelInstantiateProcess>(GetName(Process::CANCEL_INSTANTIATE), &mInitZone, &mDestroyedZone);

        AddProcess<TSaveProcess>(GetName(Process::SAVE), &mInstantiatedZone, &mInstantiatedZone);

        AddProcess<TDestroyProcess>(GetName(Process::DESTROY), &mInstantiatedZone, &mDestroyedZone);
    }
    //---------------------------------------------------------------------------------
    bool TSceneStateGraph::Work()
    {
        return mZoneMng.Work();
    }
    //---------------------------------------------------------------------------------
    void TSceneStateGraph::StartProcess(Process process, TSceneContext* pCtx)
    {
        pCtx->GetContextState().StartProcess(GetName(process));
    }
    //---------------------------------------------------------------------------------
    void TSceneStateGraph::StopProcess(TSceneContext* pCtx)
    {
        pCtx->GetContextState().StopProcess();
    }
    //---------------------------------------------------------------------------------
    std::optional<std::string> TSceneStateGraph::GetZoneName(TSceneContext* pCtx) const
    {
        auto pZone = pCtx->GetOwnerZone();
        if (pZone)
            return pZone->GetName();
        return std::nullopt;
    }
    //---------------------------------------------------------------------------------
    nsBase::nsZones::TProcess* TSceneStateGraph::GetProcess(TSceneContext* pCtx) const
    {
        return pCtx->GetActiveProcess();
    }
    //---------------------------------------------------------------------------------
}
