/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Features/Graphic/Begin/Builder/Helpers/HandlerLinkHelper.h"

#include "Modules/Resources/Common/GameObject.h"

#include "Components/Meta/UniverseGuidComponent.h"
#include "Components/Meta/GuidComponent.h"
#include "Components/Handler/LocalHandlerComponent.h"
#include "Components/Handler/GlobalHandlerComponent.h"
#include "Components/Handler/ReferenceHandlerComponent.h"

namespace nsGraphicWrapper
{
    std::list<void*> THandlerLinkHelper::FindReferenceHandlers(nsECSFramework::TEntityManager* entMng,
        nsECSFramework::TEntityID eid, const std::string& handlerTypeName)
    {
        std::list<void*> handlers;

        std::string originalGuid;

        auto isSceneInstance = entMng->HasComponent<nsCommonWrapper::TSceneOriginalGuidComponent>(eid);

        if (isSceneInstance) {
            originalGuid = entMng->ViewComponent<nsCommonWrapper::TSceneOriginalGuidComponent>(eid)->value;
        } else {
            originalGuid = entMng->ViewComponent<nsCommonWrapper::TPrefabOriginalGuidComponent>(eid)->value;
        }

        nsLogicWrapper::TReferenceHandlerComponent handlerComponent;

        handlerComponent.handlerTypeName = handlerTypeName;
        handlerComponent.entityGuid = originalGuid;

        auto handlerEids = entMng->GetByValueCopy<nsLogicWrapper::TReferenceHandlerComponent>(handlerComponent);
        if (handlerEids.size() == 0) {
            return handlers;
        }

        for (auto& handlerEid : handlerEids) {

            nsTornadoEngine::TGameObject handlerGo(handlerEid, entMng);

            auto pHandler = handlerGo.ViewComponent<nsLogicWrapper::TReferenceHandlerComponent>();
            handlers.push_back(pHandler->handler);
        }

        return handlers;
    }
    //------------------------------------------------------------------------------------------------------
    std::list<void*> THandlerLinkHelper::FindLocalHandlers(nsECSFramework::TEntityManager* entMng,
        nsECSFramework::TEntityID eid, const std::string& handlerTypeName)
    {
        std::list<void*> handlers;

        nsLogicWrapper::TLocalHandlerComponent handlerComponent;

        handlerComponent.handlerTypeName = handlerTypeName;

        auto handlerEids = entMng->GetByValueCopy<nsLogicWrapper::TLocalHandlerComponent>(handlerComponent);
        if (handlerEids.size() == 0) {
            return handlers;
        }

        nsTornadoEngine::TGameObject go(eid, entMng);

        for (auto& handlerEid : handlerEids) {

            nsTornadoEngine::TGameObject handlerGo(handlerEid, entMng);

            auto pHandler = handlerGo.ViewComponent<nsLogicWrapper::TLocalHandlerComponent>();

            bool isAccepted = false;

            switch (pHandler->filter) {
                case nsLogicWrapper::TLocalHandlerComponent::Filter::SELF_AND_CHILDS:
                    if (go == handlerGo) {
                        isAccepted = true;
                    }
                    if (go.IsParent(handlerGo)) {
                        isAccepted = true;
                    }
                    break;
                case nsLogicWrapper::TLocalHandlerComponent::Filter::ONLY_CHILDS:
                    if (go.IsParent(handlerGo)) {
                        isAccepted = true;
                    }
                    break;
                case nsLogicWrapper::TLocalHandlerComponent::Filter::SELF:
                    if (go == handlerGo) {
                        isAccepted = true;
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
    //------------------------------------------------------------------------------------------------------
    std::list<void*> THandlerLinkHelper::FindGlobalHandlers(nsECSFramework::TEntityManager* entMng,
        nsECSFramework::TEntityID eid, const std::string& handlerTypeName)
    {
        std::list<void*> handlers;

        nsLogicWrapper::TGlobalHandlerComponent handlerComponent;

        handlerComponent.handlerTypeName = handlerTypeName;

        auto handlerEids = entMng->GetByValueCopy<nsLogicWrapper::TGlobalHandlerComponent>(handlerComponent);
        if (handlerEids.size() == 0) {
            return handlers;
        }

        nsTornadoEngine::TGameObject go(eid, entMng);

        auto universeGuid = go.ViewComponent<nsCommonWrapper::TUniverseGuidComponent>()->value;
        auto sceneInstanceGuid = go.ViewComponent<nsCommonWrapper::TSceneInstanceGuidComponent>()->value;

        for (auto& handlerEid : handlerEids) {

            nsTornadoEngine::TGameObject handlerGo(handlerEid, entMng);

            auto pHandler = handlerGo.ViewComponent<nsLogicWrapper::TGlobalHandlerComponent>();

            auto handlerUniverseGuid = handlerGo.ViewComponent<nsCommonWrapper::TUniverseGuidComponent>()->value;
            auto handlerSceneInstanceGuid = handlerGo.ViewComponent<nsCommonWrapper::TSceneInstanceGuidComponent>()->value;

            bool isAccepted = false;

            switch (pHandler->filter) {
                case nsLogicWrapper::TGlobalHandlerComponent::Filter::EVERYWHERE:
                    isAccepted = true;
                    break;
                case nsLogicWrapper::TGlobalHandlerComponent::Filter::THIS_UNVIVERSE:
                    if (handlerUniverseGuid == universeGuid) {
                        isAccepted = true;
                    }
                    break;
                case nsLogicWrapper::TGlobalHandlerComponent::Filter::THIS_SCENE:
                    if (handlerSceneInstanceGuid == sceneInstanceGuid) {
                        isAccepted = true;
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
