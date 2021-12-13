/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ButtonClickHandlerBuilderSystem.h"

#include <ImGuiWidgets/include/Button.h>

#include "ButtonComponent.h"
#include "ButtonClickHandlerComponent.h"

#include "SceneOriginalGuidComponent.h"
#include "PrefabOriginalGuidComponent.h"

#include "Modules.h"
#include "HandlerCallCollector.h"
#include "HandlerLinkHelper.h"

using namespace nsGraphicWrapper;
using namespace nsGuiWrapper;

// Prefab or scene
void TButtonClickHandlerBuilderSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TButtonClickHandlerComponent* pButtonClickHandlerComponent)
{
    auto entMng = GetEntMng();
    auto handlerCallCollector = nsTornadoEngine::Modules()->HandlerCalls();
    auto handler = pButtonClickHandlerComponent->handler;

    THandlerLinkHelper::LinkToGui<TButtonComponent>(entMng, eid, pButtonClickHandlerComponent,
        [handler, handlerCallCollector](nsECSFramework::TEntityID targetEid, const TButtonComponent* pButtonComponent)
    {
        auto isRegistered = pButtonComponent->value->mOnClickCB.IsRegistered(handler);
        if (isRegistered) {
            return;
        }
        pButtonComponent->value->mOnClickCB.Register(handler, [handlerCallCollector, handler, targetEid, pButtonComponent](nsImGuiWidgets::TButton* pB)
        {
            handlerCallCollector->Add([handler, targetEid, pButtonComponent]()
            {
                handler->Handle(targetEid, pButtonComponent);
            });
        });
    });
}
