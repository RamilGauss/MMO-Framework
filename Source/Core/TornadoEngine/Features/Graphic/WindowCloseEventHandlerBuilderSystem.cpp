/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "WindowCloseEventHandlerBuilderSystem.h"

#include <ImGuiWidgets/include/Window.h>

#include "WindowComponent.h"
#include "WindowCloseEventHandlerComponent.h"

#include "SceneOriginalGuidComponent.h"
#include "PrefabOriginalGuidComponent.h"

#include "Modules.h"
#include "HandlerCallCollector.h"
#include "HandlerLinkHelper.h"

using namespace nsGraphicWrapper;
using namespace nsGuiWrapper;

// Prefab or scene
void TWindowCloseEventHandlerBuilderSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TWindowCloseEventHandlerComponent* pWindowCloseEventHandlerComponent)
{
    auto entMng = GetEntMng();
    auto handlerCallCollector = nsTornadoEngine::Modules()->HandlerCalls();
    auto handler = pWindowCloseEventHandlerComponent->handler;

    THandlerLinkHelper::LinkToGui<TWindowComponent>(entMng, eid, pWindowCloseEventHandlerComponent,
        [handler, handlerCallCollector](nsECSFramework::TEntityID targetEid, const TWindowComponent* pWindowComponent)
    {
        auto isRegistered = pWindowComponent->value->mOnShowCB.IsRegistered(handler);
        if (isRegistered) {
            return;
        }
        pWindowComponent->value->mOnShowCB.Register(handler, [handlerCallCollector, handler, targetEid, pWindowComponent](bool isShown)
        {
            if (isShown) {
                return;
            }

            handlerCallCollector->Add([handler, targetEid, pWindowComponent]()
            {
                handler->Handle(targetEid, pWindowComponent);
            });
        });
    });
}
