/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ButtonClickHandlerBuilderSystem.h"

#include <ImGuiWidgets/include/Button.h>

#include "ButtonComponent.h"
#include "ButtonClickHandlerComponent.h"

#include "GuidConstants.h"
#include "SceneOriginalGuidComponent.h"
#include "PrefabOriginalGuidComponent.h"

using namespace nsGraphicWrapper;

// Prefab or scene
void TButtonClickHandlerBuilderSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TButtonClickHandlerComponent* pButtonClickHandlerComponent)
{
    auto entMng = GetEntMng();
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

            auto isRegistered = pButtonComponent->value->mOnClickCB.IsRegistered(handler);
            if (isRegistered) {
                return;
            }
            pButtonComponent->value->mOnClickCB.Register(handler, [handler, targetEid, pButtonComponent](nsImGuiWidgets::TButton* pB)
            {
                handler->Handle(targetEid, pButtonComponent);
            });
        }
    } else {
        // Find all instantiated Prefabs
        nsCommonWrapper::TPrefabOriginalGuidComponent prefabOriginalGuidComponent;
        prefabOriginalGuidComponent.value = pButtonClickHandlerComponent->entityGuid;
        auto prefabOriginalEids = entMng->GetByValueCopy(prefabOriginalGuidComponent);
        for (auto& eid : prefabOriginalEids) {
            // Handler setup
            auto pButtonComponent = entMng->ViewComponent<nsGuiWrapper::TButtonComponent>(eid);
            if (pButtonComponent == nullptr) {
                return;
            }
            auto handler = pButtonClickHandlerComponent->handler;

            auto isRegistered = pButtonComponent->value->mOnClickCB.IsRegistered(handler);
            if (isRegistered) {
                return;
            }
            pButtonComponent->value->mOnClickCB.Register(handler, [handler, eid, pButtonComponent](nsImGuiWidgets::TButton* pB)
            {
                handler->Handle(eid, pButtonComponent);
            });
        }
    }
}
