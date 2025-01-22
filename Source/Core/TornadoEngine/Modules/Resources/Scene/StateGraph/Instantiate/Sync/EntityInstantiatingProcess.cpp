/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "EntityInstantiatingProcess.h"

#include <iterator>

#include "Base/Common/GuidGenerator.h"

#include "Modules/Resources/Common/ObjectHelper.h"
#include "Modules/Resources/Scene/StateGraph/SceneContext.h"

#include "Components/Meta/UniverseIndexComponent.h"
#include "Components/Meta/UniverseGuidComponent.h"
#include "Components/Meta/SceneOriginalGuidComponent.h"
#include "Components/Meta/SceneInstanceGuidComponent.h"

namespace nsTornadoEngine
{
    void TEntityInstantiatingProcess::Launch(nsBase::nsZones::SharedPtrHopProcessContext pCtx)
    {
        auto ctx = std::static_pointer_cast<TSceneContext>(pCtx);
        ctx->entIt = ctx->sceneContent->entities.begin();
    }
    //-------------------------------------------------------------------------------
    void TEntityInstantiatingProcess::Work(nsBase::nsZones::SharedPtrHopProcessContext pCtx)
    {
        auto ctx = std::static_pointer_cast<TSceneContext>(pCtx);

        using namespace nsCommonWrapper;

        std::list<nsECSFramework::TEntityID> newEntities;

        int remainCount = std::ranges::distance(ctx->entIt, ctx->sceneContent->entities.end());
        auto count = std::min(PART_SIZE, remainCount);

        TObjectHelper::DeserializeObjects(ctx->entityManager, newEntities, ctx->entIt, count);

        // Replace all guids to new guid with ParentGuids and SceneGuids
        TObjectHelper::UpdateGuidsAndInstantiate<TSceneOriginalGuidComponent, TSceneInstanceGuidComponent>(
            ctx->entityManager,
            newEntities, 
            ctx->instantiateSceneParams.sceneInstanceGuid);

        TUniverseGuidComponent universeGuidComponent;
        universeGuidComponent.value = ctx->instantiateSceneParams.universeGuid;
        TObjectHelper::AddComponent(ctx->entityManager, newEntities, &universeGuidComponent);

        TUniverseIndexComponent universeIndexComponent;
        universeIndexComponent.value = ctx->universeIndex;
        TObjectHelper::AddComponent(ctx->entityManager, newEntities, &universeIndexComponent);
    }
    //-------------------------------------------------------------------------------
    uint32_t TEntityInstantiatingProcess::GetTotalPartCount(nsBase::nsZones::SharedPtrHopProcessContext pCtx)
    {
        auto ctx = std::static_pointer_cast<TSceneContext>(pCtx);
        auto count = std::ceil((ctx->sceneContent->entities.size() * 1.0f) / PART_SIZE);
        if (count == 0) {
            count = 1;
        }
        return count;
    }
    //-------------------------------------------------------------------------------
}
