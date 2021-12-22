/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "MenuNodeClickHandlerBuilderSystem.h"

#include <ImGuiWidgets/include/MenuNode.h>

#include "MenuNodeComponent.h"
#include "MenuNodeClickHandlerComponent.h"

#include "SceneOriginalGuidComponent.h"
#include "PrefabOriginalGuidComponent.h"

#include "Modules.h"
#include "HandlerCallCollector.h"
#include "HandlerLinkHelper.h"

using namespace nsGraphicWrapper;
using namespace nsGuiWrapper;

// Prefab or scene
void TMenuNodeClickHandlerBuilderSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TMenuNodeClickHandlerComponent* pMenuNodeClickHandlerComponent)
{
    auto entMng = GetEntMng();
    auto handlerCallCollector = nsTornadoEngine::Modules()->HandlerCalls();
    auto handler = pMenuNodeClickHandlerComponent->handler;

    THandlerLinkHelper::LinkToGui<TMenuNodeComponent>(entMng, eid, pMenuNodeClickHandlerComponent,
        [handler, handlerCallCollector](nsECSFramework::TEntityID targetEid, const TMenuNodeComponent* pMenuNodeComponent)
    {
        auto isRegistered = pMenuNodeComponent->value->mOnLeftClickCB.IsRegistered(handler);
        if (isRegistered) {
            return;
        }
        pMenuNodeComponent->value->mOnLeftClickCB.Register(handler, [handlerCallCollector, handler, targetEid, pMenuNodeComponent](nsImGuiWidgets::TNode* pB)
        {
            handlerCallCollector->Add([handler, targetEid, pMenuNodeComponent]()
            {
                handler->Handle(targetEid, pMenuNodeComponent);
            });
        });
    });
}
