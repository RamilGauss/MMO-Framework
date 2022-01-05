/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"
#include <ECS/include/EntityManager.h>

#include "SceneGuidComponent.h"
#include "PrefabGuidComponent.h"

#include "GuidConstants.h"
#include "Modules.h"
#include "ProjectConfigContainer.h"
#include "Logger.h"
#include "TimeSliceEngine.h"
#include "PrefabOriginalGuidComponent.h"
#include "SceneOriginalGuidComponent.h"

namespace nsGraphicWrapper
{
    class DllExport THandlerLinkHelper
    {
    public:
        template<typename HandlerType, typename GuiType>
        static std::list<const HandlerType*> FindHandlers(nsECSFramework::TEntityManager* entMng,
            nsECSFramework::TEntityID eid, GuiType* pGui);
    };

    template<typename HandlerType, typename GuiType>
    std::list<const HandlerType*> THandlerLinkHelper::FindHandlers(nsECSFramework::TEntityManager* entMng,
        nsECSFramework::TEntityID eid, GuiType* pGui)
    {
        std::list<const HandlerType*> handlers;

        auto handlerEids = entMng->GetByHasCopy<HandlerType>();
        if (handlerEids.size() == 0) {
            return handlers;
        }

        auto isPrefabInstance = entMng->HasComponent<nsCommonWrapper::TPrefabOriginalGuidComponent>(eid);
        auto isSceneInstance = entMng->HasComponent<nsCommonWrapper::TSceneOriginalGuidComponent>(eid);

        // Handler setup
        if (isSceneInstance) {
            auto pSceneOriginalGuid = entMng->ViewComponent<nsCommonWrapper::TSceneOriginalGuidComponent>(eid);
            for (auto& handlerEid : handlerEids) {
                auto handlerComponent = entMng->ViewComponent<HandlerType>(handlerEid);
                if (handlerComponent->partOfGuid != nsTornadoEngine::TGuidConstants::THIS_SCENE) {
                    continue;
                }
                if (handlerComponent->entityGuid != pSceneOriginalGuid->value) {
                    continue;
                }

                handlers.push_back(handlerComponent);
            }
        }
        if (isPrefabInstance) {
            auto pPrefabGuid = entMng->ViewComponent<nsCommonWrapper::TPrefabGuidComponent>(eid);
            if (pPrefabGuid == nullptr) {
                return handlers;
            }

            auto pPrefabOriginalGuid = entMng->ViewComponent<nsCommonWrapper::TPrefabOriginalGuidComponent>(eid);
            for (auto& handlerEid : handlerEids) {
                auto handlerComponent = entMng->ViewComponent<HandlerType>(handlerEid);
                if (handlerComponent->partOfGuid != pPrefabGuid->value) {
                    continue;
                }
                if (handlerComponent->entityGuid != pPrefabOriginalGuid->value) {
                    continue;
                }

                handlers.push_back(handlerComponent);
            }
        }

        return handlers;
    }
}