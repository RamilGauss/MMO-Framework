/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "PrefabInstantiatingProcess.h"

#include <iterator>

#include "Components/Meta/SceneOriginalGuidComponent.h"
#include "Components/Meta/SceneInstanceGuidComponent.h"

#include "Modules/Resources/Common/ObjectHelper.h"
#include "Modules/Resources/Prefab/InstantiatePrefabParams.h"
#include "Modules/Resources/Prefab/PrefabManager.h"
#include "Modules/Resources/Scene/StateGraph/SceneContext.h"

namespace nsTornadoEngine
{
    void TPrefabInstantiatingProcess::Launch(nsBase::nsZones::SharedPtrHopProcessContext pCtx)
    {
        auto ctx = std::static_pointer_cast<TSceneContext>(pCtx);
        ctx->prefabIt = ctx->sceneContent->prefabInstances.begin();
    }
    //-------------------------------------------------------------------------------
    void TPrefabInstantiatingProcess::Work(nsBase::nsZones::SharedPtrHopProcessContext pCtx)
    {
        auto ctx = std::static_pointer_cast<TSceneContext>(pCtx);

        int remainCount = std::ranges::distance(ctx->prefabIt, ctx->sceneContent->prefabInstances.end());
        auto count = std::min(PART_SIZE, remainCount);

        using namespace nsCommonWrapper;

        for (int i = 0; i < count; i++, ctx->prefabIt++) {

            std::string parentGuid;

            TSceneOriginalGuidComponent sceneOriginalGuidComponent;
            sceneOriginalGuidComponent.value = ctx->prefabIt->parentGuid;

            auto sceneOriginalGuidEntities = ctx->entityManager->GetByValueCopy(sceneOriginalGuidComponent);
            for (auto eid : sceneOriginalGuidEntities) {

                auto sceneInstanceGuid = ctx->entityManager->ViewComponent<TSceneInstanceGuidComponent>(eid)->value;
                if (sceneInstanceGuid == ctx->instantiateSceneParams.sceneInstanceGuid) {
                    parentGuid = sceneInstanceGuid;
                    break;
                }
            }

            TInstantiatePrefabParams instantiatePrefabParams;

            instantiatePrefabParams.guid = ctx->prefabIt->prefabGuid;
            instantiatePrefabParams.rootMatrix = ctx->prefabIt->localMatrix;
            instantiatePrefabParams.parentGuid = parentGuid;
            instantiatePrefabParams.sceneInstanceGuid = ctx->instantiateSceneParams.sceneInstanceGuid;

            ctx->prefabMng->Instantiate(std::move(instantiatePrefabParams));
        }
    }
    //-------------------------------------------------------------------------------
    uint32_t TPrefabInstantiatingProcess::GetTotalPartCount(nsBase::nsZones::SharedPtrHopProcessContext pCtx)
    {
        auto ctx = std::static_pointer_cast<TSceneContext>(pCtx);
        auto count = std::ceil((ctx->sceneContent->prefabInstances.size() * 1.0f) / PART_SIZE);
        if (count == 0) {
            count = 1;
        }
        return count;
    }
    //-------------------------------------------------------------------------------
}
