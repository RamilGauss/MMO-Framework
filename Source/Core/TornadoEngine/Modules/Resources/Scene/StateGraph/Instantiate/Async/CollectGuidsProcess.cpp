/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "CollectGuidsProcess.h"

#include "Modules/Resources/Scene/StateGraph/SceneContext.h"

//#include "Generated files/TornadoEngineJsonSerializer.h"

namespace nsTornadoEngine
{
    void TCollectGuidsProcess::Launch(nsBase::nsZones::SharedPtrHopProcessContext pCtx)
    {
        auto ctx = std::static_pointer_cast<TSceneContext>(pCtx);
        ctx->currentEntIt = ctx->sceneContent.entities.begin();
    }
    //-------------------------------------------------------------------------------
    void TCollectGuidsProcess::Work(nsBase::nsZones::SharedPtrHopProcessContext pCtx)
    {
        auto ctx = std::static_pointer_cast<TSceneContext>(pCtx);

        for (auto& component : ctx->currentEntIt->components) {
            if (component.typeName == "") {
                //ctx->entityGuids.push_back();
            }
        }
        ctx->currentEntIt++;
    }
    //-------------------------------------------------------------------------------
    uint32_t TCollectGuidsProcess::GetTotalPartCount(nsBase::nsZones::SharedPtrHopProcessContext pCtx)
    {
        auto ctx = std::static_pointer_cast<TSceneContext>(pCtx);
        return ctx->sceneContent.entities.size();
    }
    //-------------------------------------------------------------------------------
}
