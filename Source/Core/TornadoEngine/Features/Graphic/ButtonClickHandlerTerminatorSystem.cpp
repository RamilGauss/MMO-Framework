/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ButtonClickHandlerTerminatorSystem.h"
#include "Modules.h"
#include "ProjectConfigContainer.h"
#include "Logger.h"
#include "TimeSliceEngine.h"


#include "ButtonComponent.h"
#include "ButtonClickHandlerComponent.h"

#include "GuidConstants.h"
#include "SceneOriginalGuidComponent.h"
#include "PrefabOriginalGuidComponent.h"

using namespace nsGraphicWrapper;

void TButtonClickHandlerTerminatorSystem::Reactive(nsECSFramework::TEntityID eid,
    const nsGuiWrapper::TButtonClickHandlerComponent* pButtonClickHandlerComponent)
{
    auto handlerReflection = nsTornadoEngine::Project()->mScenePartAggregator->mHandlers;

    auto logger = GetLogger()->Get(nsTornadoEngine::TTimeSliceEngine::NAME);
    auto entMng = GetEntMng();

    // Find button and unregister
    if (pButtonClickHandlerComponent->partOfGuid == nsTornadoEngine::TGuidConstants::THIS_SCENE) {

        nsCommonWrapper::TSceneOriginalGuidComponent sceneOriginalGuidComponent;
        sceneOriginalGuidComponent.value = pButtonClickHandlerComponent->entityGuid;
        auto targetEid = entMng->GetByUnique(sceneOriginalGuidComponent);
        if (targetEid != nsECSFramework::NONE) {
            // Handler setup
            auto pButtonComponent = entMng->ViewComponent<nsGuiWrapper::TButtonComponent>(targetEid);
            if (pButtonComponent == nullptr) {
                return;
            }
            auto handler = pButtonClickHandlerComponent->handler;
            pButtonComponent->value->mOnClickCB.Unregister(handler);
        }
    } else {
        // Find all instantiated Prefabs
        nsCommonWrapper::TPrefabOriginalGuidComponent prefabOriginalGuidComponent;
        prefabOriginalGuidComponent.value = pButtonClickHandlerComponent->entityGuid;
        auto prefabIriginalEids = entMng->GetByValueCopy(prefabOriginalGuidComponent);
        if (prefabIriginalEids.size() == 0) {
            return;
        }
        for (auto& eid : prefabIriginalEids) {
            // Handler setup
            auto pButtonComponent = entMng->ViewComponent<nsGuiWrapper::TButtonComponent>(eid);
            if (pButtonComponent == nullptr) {
                return;
            }
            auto handler = pButtonClickHandlerComponent->handler;
            pButtonComponent->value->mOnClickCB.Unregister(handler);
        }
    }

    int rtti;
    auto convertResult = handlerReflection->mTypeInfo->ConvertNameToType(pButtonClickHandlerComponent->handlerTypeName, rtti);
    if (convertResult == false) {
        logger->WriteF_time("Not converted typename \"%s\"", pButtonClickHandlerComponent->handlerTypeName);
        return;
    }
    handlerReflection->mTypeFactory->Delete(pButtonClickHandlerComponent->handler, rtti);
}
