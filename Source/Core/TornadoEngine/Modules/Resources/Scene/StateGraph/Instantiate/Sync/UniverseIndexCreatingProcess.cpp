/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "UniverseIndexCreatingProcess.h"

#include "Modules/Resources/Scene/StateGraph/SceneContext.h"

namespace nsTornadoEngine
{
    void TUniverseIndexCreatingProcess::Work(nsBase::nsZones::SharedPtrHopProcessContext pCtx)
    {
        auto ctx = std::static_pointer_cast<TSceneContext>(pCtx);

        auto universeIndex = ctx->universeManager->GetIndexByGuid(ctx->instantiateSceneParams.universeGuid);
        if (universeIndex == TUniverseManager::UNDEFINED_INDEX) {
            ctx->universeManager->Create(ctx->instantiateSceneParams.universeGuid);
            universeIndex = ctx->universeManager->GetIndexByGuid(ctx->instantiateSceneParams.universeGuid);
        }

        ctx->universeIndex = universeIndex;
    }
    //-------------------------------------------------------------------------------
    uint32_t TUniverseIndexCreatingProcess::GetTotalPartCount(nsBase::nsZones::SharedPtrHopProcessContext pCtx)
    {
        return 1;
    }
    //-------------------------------------------------------------------------------
}
