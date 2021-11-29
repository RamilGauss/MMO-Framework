/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ButtonBuilderSystem.h"

#include <ImGuiWidgets/include/Button.h>

#include "UnitBuilderHelper.h"

#include "TitleComponent.h"

#include "ButtonClickHandlerComponent.h"

#include "PrefabGuidComponent.h"
#include "PrefabOriginalGuidComponent.h"
#include "SceneOriginalGuidComponent.h"
#include "GuidConstants.h"

using namespace nsGraphicWrapper;

// Prefab or scene
void TButtonBuilderSystem::Reactive(nsECSFramework::TEntityID eid, nsECSFramework::IComponent* pC)
{
    auto pButtonComponent = (nsGuiWrapper::TButtonComponent*) pC;
    auto entMng = GetEntMng();

    auto titleComponent = entMng->ViewComponent<nsGuiWrapper::TTitleComponent>(eid);
    pButtonComponent->value->SetTitle(titleComponent->value);

    TUnitBuilderHelper::SetupButton(entMng, eid, pButtonComponent);

    auto pButtonClickHandlers = entMng->GetByHas<nsGuiWrapper::TButtonClickHandlerComponent>();
    if (pButtonClickHandlers == nullptr) {
        return;
    }
    auto buttonClickHandlers = *pButtonClickHandlers;

    auto isPrefabInstance = entMng->HasComponent<nsCommonWrapper::TPrefabOriginalGuidComponent>(eid);
    auto isSceneInstance = entMng->HasComponent<nsCommonWrapper::TSceneOriginalGuidComponent>(eid);

    // Handler setup
    if (isSceneInstance) {
        auto pSceneOriginalGuid = entMng->ViewComponent<nsCommonWrapper::TSceneOriginalGuidComponent>(eid);
        for (auto& handlerEid : buttonClickHandlers) {
            auto handlerComponent = entMng->ViewComponent<nsGuiWrapper::TButtonClickHandlerComponent>(handlerEid);
            if (handlerComponent->partOfGuid != nsTornadoEngine::TGuidConstants::THIS_SCENE) {
                continue;
            }
            if (handlerComponent->entityGuid != pSceneOriginalGuid->value) {
                continue;
            }

            auto handler = handlerComponent->handler;
            auto isRegistered = pButtonComponent->value->mOnClickCB.IsRegistered(handler);
            if (isRegistered) {
                continue;
            }

            pButtonComponent->value->mOnClickCB.Register(handler, [handler](nsImGuiWidgets::TButton* pB)
            {
                handler->Handle();
            });
        }
    } 
    if (isPrefabInstance) {
        auto pPrefabGuid = entMng->ViewComponent<nsCommonWrapper::TPrefabGuidComponent>(eid);
        if (pPrefabGuid == nullptr) {
            return;
        }

        auto pPrefabOriginalGuid = entMng->ViewComponent<nsCommonWrapper::TPrefabOriginalGuidComponent>(eid);
        for (auto& handlerEid : buttonClickHandlers) {
            auto handlerComponent = entMng->ViewComponent<nsGuiWrapper::TButtonClickHandlerComponent>(handlerEid);
            if (handlerComponent->partOfGuid != pPrefabGuid->value) {
                continue;
            }
            if (handlerComponent->entityGuid != pPrefabOriginalGuid->value) {
                continue;
            }

            auto handler = handlerComponent->handler;
            auto isRegistered = pButtonComponent->value->mOnClickCB.IsRegistered(handler);
            if (isRegistered) {
                continue;
            }

            pButtonComponent->value->mOnClickCB.Register(handler, [handler](nsImGuiWidgets::TButton* pB)
            {
                handler->Handle();
            });
        }
    }
}
