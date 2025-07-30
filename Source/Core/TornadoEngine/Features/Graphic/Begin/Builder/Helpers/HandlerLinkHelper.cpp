/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TornadoEngine/Features/Graphic/Begin/Builder/Helpers/HandlerLinkHelper.h"

#include "TornadoEngine/Modules/Resources/Common/GameObject.h"

#include "TornadoEngine/Components/Meta/UniverseGuidComponent.h"
#include "TornadoEngine/Components/Meta/GuidComponent.h"
#include "TornadoEngine/Components/Handler/LocalHandlerComponent.h"
#include "TornadoEngine/Components/Handler/GlobalHandlerComponent.h"

namespace nsGraphicWrapper
{
    std::list<void*> THandlerLinkHelper::FindLocalHandlers(nsECSFramework::TEntityManager* entMng,
        nsECSFramework::TEntityID eid, const std::string& parentHandlerTypeName)
    {
        std::list<void*> handlers;

        nsLogicWrapper::TLocalHandlerComponent handlerComponent;

        handlerComponent.parentHandlerTypeName = parentHandlerTypeName;

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
        nsECSFramework::TEntityID eid, const std::string& parentHandlerTypeName)
    {
        std::list<void*> handlers;

        nsLogicWrapper::TGlobalHandlerComponent handlerComponent;

        handlerComponent.parentHandlerTypeName = parentHandlerTypeName;

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
