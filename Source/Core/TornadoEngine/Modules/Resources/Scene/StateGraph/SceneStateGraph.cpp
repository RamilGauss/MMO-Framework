/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "SceneStateGraph.h"

namespace nsTornadoEngine
{
    void TSceneStateGraph::Init()
    {

    }
    //---------------------------------------------------------------------------------
    void TSceneStateGraph::StartProcess(Process process, TSceneContext* pCtx)
    {

    }
    //---------------------------------------------------------------------------------
    void TSceneStateGraph::StopProcess(TSceneContext* pCtx)
    {

    }
    //---------------------------------------------------------------------------------
    std::optional<std::string> TSceneStateGraph::GetZoneName(TSceneContext* pCtx) const
    {
        return std::nullopt;
    }
    //---------------------------------------------------------------------------------
    nsBase::nsZones::TProcess* TSceneStateGraph::GetProcess(TSceneContext* pCtx) const
    {
        return nullptr;
    }
    //---------------------------------------------------------------------------------
}
