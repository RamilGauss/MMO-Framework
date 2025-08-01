/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/TypeDef.h"
#include "Base/Common/Logger.h"

#include "ECS/Include/EntityManager.h"

#include "TornadoEngine/Components/Meta/SceneGuidComponent.h"
#include "TornadoEngine/Components/Meta/PrefabGuidComponent.h"
#include "TornadoEngine/Components/Meta/SceneInstanceGuidComponent.h"
#include "TornadoEngine/Components/Meta/PrefabOriginalGuidComponent.h"
#include "TornadoEngine/Components/Meta/SceneOriginalGuidComponent.h"

#include "TornadoEngine/Modules/Common/Modules.h"
#include "TornadoEngine/Modules/Resources/Common/GuidConstants.h"
#include "TornadoEngine/Modules/Resources/Common/HandlerCallCollector.h"

#include "TornadoEngine/TimeSliceEngine/ProjectConfigContainer.h"

#include "TornadoEngine/ReflectionAggregators/ScenePartReflectionAggregator.h"

namespace nsGraphicWrapper
{
    class DllExport THandlerLinkHelper
    {
    public:
        static std::list<void*> FindLocalHandlers(nsECSFramework::TEntityManager* entMng,
            nsECSFramework::TEntityID eid, const std::string& parentHandlerTypeName);

        static std::list<void*> FindGlobalHandlers(nsECSFramework::TEntityManager* entMng,
            nsECSFramework::TEntityID eid, const std::string& parentHandlerTypeName);

        template<typename GuiType>
        static void RegisterMouseKey(nsECSFramework::TEntityManager* entMng,
            nsECSFramework::TEntityID eid, GuiType* pGui);

        template<typename HandlerType>
        static void UnlinkGui(nsECSFramework::TEntityManager* entMng,
            nsECSFramework::TEntityID eid, HandlerType* pHandlerComponent);
    };
    //------------------------------------------------------------------------------------------------------
    template<typename GuiType>
    void THandlerLinkHelper::RegisterMouseKey(nsECSFramework::TEntityManager* entMng,
        nsECSFramework::TEntityID eid, GuiType* pGui)
    {
        auto handlerCallCollector = nsTornadoEngine::Modules()->HandlerCalls();

        /*pGui->value->mOnMouseClickCB.Register(pGui->value,
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
        });*/
    }
    //------------------------------------------------------------------------------------------------------
    template<typename HandlerType>
    void THandlerLinkHelper::UnlinkGui(nsECSFramework::TEntityManager* entMng,
        nsECSFramework::TEntityID eid, HandlerType* pHandlerComponent)
    {
        auto handlerReflection = nsTornadoEngine::Project()->mScenePartAggregator->mHandlers;

        int rtti;
        auto convertResult = handlerReflection->mRtti->ConvertNameToType(pHandlerComponent->handlerTypeName, rtti);
        if (convertResult == false) {
            nsTornadoEngine::Modules()->CoreLog()->AddWarningEvent("Not converted typename \"{}\"", pHandlerComponent->handlerTypeName);
            return;
        }
        handlerReflection->mTypeFactory->Delete(pHandlerComponent->handler, rtti);
    }
    //------------------------------------------------------------------------------------------------------
}
