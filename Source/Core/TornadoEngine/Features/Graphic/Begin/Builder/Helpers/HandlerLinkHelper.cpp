/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "HandlerLinkHelper.h"

#include "UniverseGuidComponent.h"

#include "GuidComponent.h"

namespace nsGraphicWrapper
{
    std::list<void*> THandlerLinkHelper::FindHandlers(nsECSFramework::TEntityManager* entMng,
        nsECSFramework::TEntityID eid, const std::string& handlerTypeName)
    {
        std::list<void*> handlers;

        nsLogicWrapper::THandlerComponent targetHandlerComponent;

        targetHandlerComponent.handlerTypeName = handlerTypeName;

        auto handlerEids = entMng->GetByValueCopy<nsLogicWrapper::THandlerComponent>(targetHandlerComponent);
        if (handlerEids.size() == 0) {
            return handlers;
        }

        std::string originalGuid;

        auto isSceneInstance = entMng->HasComponent<nsCommonWrapper::TSceneOriginalGuidComponent>(eid);

        if (isSceneInstance) {
            originalGuid = entMng->ViewComponent<nsCommonWrapper::TSceneOriginalGuidComponent>(eid)->value;
        } else {
            originalGuid = entMng->ViewComponent<nsCommonWrapper::TPrefabOriginalGuidComponent>(eid)->value;
        }

        auto universeGuid = entMng->ViewComponent<nsCommonWrapper::TUniverseGuidComponent>(eid)->value;
        auto sceneInstanceGuid = entMng->ViewComponent<nsCommonWrapper::TSceneInstanceGuidComponent>(eid)->value;
        auto guid = entMng->ViewComponent<nsCommonWrapper::TGuidComponent>(eid)->value;

        for (auto& handlerEid : handlerEids) {

            auto pHandler = entMng->ViewComponent<nsLogicWrapper::THandlerComponent>(handlerEid);

            if (pHandler->entityGuid != nsTornadoEngine::TGuidConstants::NONE) {

                if (targetHandlerComponent.entityGuid != originalGuid) {
                    continue;
                }
            }

            auto handlerUniverseGuid = entMng->ViewComponent<nsCommonWrapper::TUniverseGuidComponent>(handlerEid)->value;
            auto handlerSceneInstanceGuid = entMng->ViewComponent<nsCommonWrapper::TSceneInstanceGuidComponent>(handlerEid)->value;
            auto handlerGuid = entMng->ViewComponent<nsCommonWrapper::TGuidComponent>(handlerEid)->value;

            bool isAccepted = true;

            switch (pHandler->filter) {
                case nsLogicWrapper::THandlerComponent::Filter::EVERYWHERE:
                    break;
                case nsLogicWrapper::THandlerComponent::Filter::THIS_UNVIVERSE:
                    if (handlerUniverseGuid != universeGuid) {
                        isAccepted = false;
                    }
                    break;
                case nsLogicWrapper::THandlerComponent::Filter::THIS_SCENE:
                    if (handlerSceneInstanceGuid != sceneInstanceGuid) {
                        isAccepted = false;
                    }
                    break;
                case nsLogicWrapper::THandlerComponent::Filter::SELF_AND_CHILDS:
                    if (handlerGuid != guid) {
                        isAccepted = false;
                    }
                    break;
                case nsLogicWrapper::THandlerComponent::Filter::ONLY_CHILDS:
                    break;
                case nsLogicWrapper::THandlerComponent::Filter::SELF:
                    if (handlerGuid != guid) {
                        isAccepted = false;
                    }
                    break;
            }

            if (isAccepted) {
                auto handler = pHandler->handler;
                handlers.push_back(handler);
            }
        }

        return handlers;
    }
}
