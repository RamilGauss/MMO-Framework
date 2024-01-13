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
    TSceneStateGraph::TSceneStateGraph() 
    {

    }
    //---------------------------------------------------------------------------------
    void TSceneStateGraph::Init()
    {
        constexpr auto zones = magic_enum::enum_names<Zone>();
        for (auto sv : zones) {
            std::string zoneName = std::string(sv);
            mZoneMng.AddZone(std::make_shared<nsBase::nsZones::TZone>(zoneName));
        }

        AddProcess<TInstantiateProcess>(Process::INSTANTIATE, Zone::INIT, Zone::INSTANTIATED);
        AddProcess<TCancelInstantiateProcess>(Process::CANCEL_INSTANTIATE, Zone::INIT, Zone::DESTROYED);

        AddProcess<TSaveProcess>(Process::SAVE, Zone::INSTANTIATED, Zone::INSTANTIATED);

        AddProcess<TDestroyProcess>(Process::DESTROY, Zone::INSTANTIATED, Zone::DESTROYED);
    }
    //---------------------------------------------------------------------------------
    bool TSceneStateGraph::Work()
    {
        return mZoneMng.Work();
    }
    //---------------------------------------------------------------------------------
    void TSceneStateGraph::StartProcess(Process process, TSceneContext* pCtx)
    {
        pCtx->GetContextState().StartProcess(GetProcessName(process));
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
    nsBase::nsZones::TZone* TSceneStateGraph::GetZone(Zone zone)
    {
        auto zoneName = std::string(magic_enum::enum_name(zone));
        return mZoneMng.GetZone(zoneName);
    }
    //---------------------------------------------------------------------------------
    std::string TSceneStateGraph::GetProcessName(Process process) const
    {
        return std::string(magic_enum::enum_name(process));
    }
    //---------------------------------------------------------------------------------
}
