/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "HandlerLinkHelper.h"

namespace nsGraphicWrapper
{
    std::list<void*> THandlerLinkHelper::FindTargetHandlers(nsECSFramework::TEntityManager* entMng,
        nsECSFramework::TEntityID eid, const std::string& handlerTypeName)
    {
        std::string originalGuid;

        auto isSceneInstance = entMng->HasComponent<nsCommonWrapper::TSceneOriginalGuidComponent>(eid);

        if (isSceneInstance) {
            originalGuid = entMng->ViewComponent<nsCommonWrapper::TSceneOriginalGuidComponent>(eid)->value;
        } else {
            originalGuid = entMng->ViewComponent<nsCommonWrapper::TPrefabOriginalGuidComponent>(eid)->value;
        }

        std::list<void*> handlers;

        nsLogicWrapper::TTargetHandlerComponent targetHandlerComponent;

        targetHandlerComponent.handlerTypeName = handlerTypeName;
        targetHandlerComponent.entityGuid = originalGuid;

        auto handlerEids = entMng->GetByValueCopy<nsLogicWrapper::TTargetHandlerComponent>(targetHandlerComponent);
        if (handlerEids.size() == 0) {
            return handlers;
        }

        auto targetSceneInstanceGuid = entMng->ViewComponent<nsCommonWrapper::TSceneInstanceGuidComponent>(eid)->value;

        for (auto& handlerEid : handlerEids) {
            auto sceneInstanceGuid = entMng->ViewComponent<nsCommonWrapper::TSceneInstanceGuidComponent>(handlerEid)->value;
            if (sceneInstanceGuid != targetSceneInstanceGuid) {
                continue;
            }

            auto p = entMng->ViewComponent<nsLogicWrapper::TTargetHandlerComponent>(handlerEid)->handler;
            handlers.push_back(p);
        }

        return handlers;
    }
}
