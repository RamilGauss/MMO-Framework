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

namespace nsGraphicWrapper
{
    class DllExport THandlerLinkHelper
    {
    public:
        template<typename HandlerType, typename GuiType>
        static void LinkToHandler(nsECSFramework::TEntityManager* entMng, 
            nsECSFramework::TEntityID eid, GuiType* pGui, std::function<void(const HandlerType*)> onFoundHandler)
        {
            auto handlerEids = entMng->GetByHasCopy<HandlerType>();
            if (handlerEids.size() == 0) {
                return;
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

                    onFoundHandler(handlerComponent);
                }
            }
            if (isPrefabInstance) {
                auto pPrefabGuid = entMng->ViewComponent<nsCommonWrapper::TPrefabGuidComponent>(eid);
                if (pPrefabGuid == nullptr) {
                    return;
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

                    onFoundHandler(handlerComponent);
                }
            }
        }

        template<typename GuiType, typename HandlerType>
        static void LinkToGui(nsECSFramework::TEntityManager* entMng, 
            nsECSFramework::TEntityID eid, HandlerType* pHandlerComponent, std::function<void(nsECSFramework::TEntityID, const GuiType*)> onFoundGui)
        {
            if (pHandlerComponent->partOfGuid == nsTornadoEngine::TGuidConstants::THIS_SCENE) {

                auto sceneGuid = entMng->ViewComponent<nsCommonWrapper::TSceneGuidComponent>(eid)->value;

                nsCommonWrapper::TSceneOriginalGuidComponent sceneOriginalGuidComponent;
                sceneOriginalGuidComponent.value = pHandlerComponent->entityGuid;
                auto targetEids = entMng->GetByValueCopy(sceneOriginalGuidComponent);
                for (auto& targetEid : targetEids) {

                    auto targetSceneGuid = entMng->ViewComponent<nsCommonWrapper::TSceneGuidComponent>(targetEid)->value;
                    if (targetSceneGuid != sceneGuid) {
                        continue;
                    }

                    // Handler setup
                    auto pGuiComponent = entMng->ViewComponent<GuiType>(targetEid);
                    if (pGuiComponent == nullptr) {
                        return;
                    }

                    onFoundGui(targetEid, pGuiComponent);
                }
            } else {
                // Find all instantiated Prefabs
                nsCommonWrapper::TPrefabOriginalGuidComponent prefabOriginalGuidComponent;
                prefabOriginalGuidComponent.value = pHandlerComponent->entityGuid;
                auto prefabOriginalEids = entMng->GetByValueCopy(prefabOriginalGuidComponent);
                for (auto& targetEid : prefabOriginalEids) {
                    // Handler setup
                    auto pGuiComponent = entMng->ViewComponent<GuiType>(targetEid);
                    if (pGuiComponent == nullptr) {
                        return;
                    }

                    onFoundGui(targetEid, pGuiComponent);
                }
            }
        }

        template<typename GuiType, typename HandlerType>
        static void UnlinkGui(nsECSFramework::TEntityManager* entMng,
            nsECSFramework::TEntityID eid, HandlerType* pHandlerComponent, std::function<void(const GuiType*)> onFoundGui)
        {
            auto handlerReflection = nsTornadoEngine::Project()->mScenePartAggregator->mHandlers;

            auto logger = GetLogger()->Get(nsTornadoEngine::TTimeSliceEngine::NAME);

            // Find button and unregister
            if (pHandlerComponent->partOfGuid == nsTornadoEngine::TGuidConstants::THIS_SCENE) {

                nsCommonWrapper::TSceneOriginalGuidComponent sceneOriginalGuidComponent;
                sceneOriginalGuidComponent.value = pHandlerComponent->entityGuid;
                auto targetEids = entMng->GetByValueCopy(sceneOriginalGuidComponent);
                for (auto& targetEid : targetEids) {
                    // Handler setup
                    auto pGuiComponent = entMng->ViewComponent<GuiType>(targetEid);
                    if (pGuiComponent == nullptr) {
                        return;
                    }

                    onFoundGui(pGuiComponent);
                }
            } else {
                // Find all instantiated Prefabs
                nsCommonWrapper::TPrefabOriginalGuidComponent prefabOriginalGuidComponent;
                prefabOriginalGuidComponent.value = pHandlerComponent->entityGuid;
                auto prefabIriginalEids = entMng->GetByValueCopy(prefabOriginalGuidComponent);
                if (prefabIriginalEids.size() == 0) {
                    return;
                }
                for (auto& eid : prefabIriginalEids) {
                    // Handler setup
                    auto pGuiComponent = entMng->ViewComponent<GuiType>(eid);
                    if (pGuiComponent == nullptr) {
                        return;
                    }
                    onFoundGui(pGuiComponent);
                }
            }

            int rtti;
            auto convertResult = handlerReflection->mTypeInfo->ConvertNameToType(pHandlerComponent->handlerTypeName, rtti);
            if (convertResult == false) {
                logger->WriteF_time("Not converted typename \"%s\"", pHandlerComponent->handlerTypeName);
                return;
            }
            handlerReflection->mTypeFactory->Delete(pHandlerComponent->handler, rtti);
        }
    };
}