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
#include "EngineLogger.h"
#include "PrefabOriginalGuidComponent.h"
#include "SceneOriginalGuidComponent.h"
#include "HandlerCallCollector.h"

#include "FrameMouseMoveHandlerComponent.h"
#include "FrameMouseWheelHandlerComponent.h"
#include "FrameMouseClickHandlerComponent.h"
#include "FrameKeyHandlerComponent.h"

namespace nsGraphicWrapper
{
    class DllExport THandlerLinkHelper
    {
    public:
        template<typename HandlerType, typename GuiType>
        static std::list<const HandlerType*> FindHandlers(nsECSFramework::TEntityManager* entMng,
            nsECSFramework::TEntityID eid, GuiType* pGui);

        template<typename GuiType>
        static void RegisterMouseKey(nsECSFramework::TEntityManager* entMng,
            nsECSFramework::TEntityID eid, GuiType* pGui);

        template<typename HandlerType>
        static void UnlinkGui(nsECSFramework::TEntityManager* entMng,
            nsECSFramework::TEntityID eid, HandlerType* pHandlerComponent);
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

    template<typename GuiType>
    void THandlerLinkHelper::RegisterMouseKey(nsECSFramework::TEntityManager* entMng,
        nsECSFramework::TEntityID eid, GuiType* pGui)
    {
        auto handlerCallCollector = nsTornadoEngine::Modules()->HandlerCalls();

        pGui->value->mOnMouseClickCB.Register(pGui->value,
            [entMng, handlerCallCollector, eid, pGui](nsGraphicEngine::TMouseButtonEvent mouseEvent)
        {
            auto handlers = THandlerLinkHelper::FindHandlers<nsGuiWrapper::TFrameMouseClickHandlerComponent>(entMng, eid, pGui);
            for (auto& pHandler : handlers) {
                handlerCallCollector->Add([mouseEvent, pHandler, eid]()
                {
                    if (pHandler->handler) {
                        pHandler->handler->Handle(eid, mouseEvent);
                    }
                });
            }
        });

        pGui->value->mOnMouseMoveCB.Register(pGui->value,
            [entMng, handlerCallCollector, eid, pGui](nsGraphicEngine::TMouseMotionEvent mouseEvent)
        {
            auto handlers = THandlerLinkHelper::FindHandlers<nsGuiWrapper::TFrameMouseMoveHandlerComponent>(entMng, eid, pGui);
            for (auto& pHandler : handlers) {
                handlerCallCollector->Add([mouseEvent, pHandler, eid]()
                {
                    if (pHandler->handler) {
                        pHandler->handler->Handle(eid, mouseEvent);
                    }
                });
            }
        });

        pGui->value->mOnMouseWheelCB.Register(pGui->value,
            [entMng, handlerCallCollector, eid, pGui](nsGraphicEngine::TMouseWheelEvent mouseEvent)
        {
            auto handlers = THandlerLinkHelper::FindHandlers<nsGuiWrapper::TFrameMouseWheelHandlerComponent>(entMng, eid, pGui);
            for (auto& pHandler : handlers) {
                handlerCallCollector->Add([mouseEvent, pHandler, eid]()
                {
                    if (pHandler->handler) {
                        pHandler->handler->Handle(eid, mouseEvent);
                    }
                });
            }
        });

        pGui->value->mOnKeyCB.Register(pGui->value,
            [entMng, handlerCallCollector, eid, pGui](nsGraphicEngine::TKeyboardEvent keyEvent)
        {
            auto handlers = THandlerLinkHelper::FindHandlers<nsGuiWrapper::TFrameKeyHandlerComponent>(entMng, eid, pGui);
            for (auto& pHandler : handlers) {
                handlerCallCollector->Add([keyEvent, pHandler, eid]()
                {
                    if (pHandler->handler) {
                        pHandler->handler->Handle(eid, keyEvent);
                    }
                });
            }
        });
    }


    template<typename HandlerType>
    void THandlerLinkHelper::UnlinkGui(nsECSFramework::TEntityManager* entMng,
        nsECSFramework::TEntityID eid, HandlerType* pHandlerComponent)
    {
        auto handlerReflection = nsTornadoEngine::Project()->mScenePartAggregator->mHandlers;

        int rtti;
        auto convertResult = handlerReflection->mTypeInfo->ConvertNameToType(pHandlerComponent->handlerTypeName, rtti);
        if (convertResult == false) {
            nsTornadoEngine::TEngineLogger::Log("Not converted typename \"%s\"", pHandlerComponent->handlerTypeName);
            return;
        }
        handlerReflection->mTypeFactory->Delete(pHandlerComponent->handler, rtti);
    }
}