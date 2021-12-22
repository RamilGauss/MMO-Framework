/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ButtonBuilderSystem.h"

#include <ImGuiWidgets/include/Button.h>

#include "UnitBuilderHelper.h"

#include "TitleComponent.h"

#include "ButtonClickHandlerComponent.h"

#include "PrefabOriginalGuidComponent.h"
#include "SceneOriginalGuidComponent.h"

#include "Modules.h"
#include "HandlerCallCollector.h"

#include "HandlerLinkHelper.h"

using namespace nsGraphicWrapper;
using namespace nsGuiWrapper;

// Prefab or scene
void TButtonBuilderSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TButtonComponent* pButtonComponent)
{
    auto entMng = GetEntMng();

    TUnitBuilderHelper::SetupWidget(entMng, eid, pButtonComponent->value);

    auto handlerCallCollector = nsTornadoEngine::Modules()->HandlerCalls();
    THandlerLinkHelper::LinkToHandler<TButtonClickHandlerComponent>(entMng, eid, pButtonComponent,
    [pButtonComponent, handlerCallCollector, eid](const TButtonClickHandlerComponent* handlerComponent)
    {
        auto handler = handlerComponent->handler;
        auto isRegistered = pButtonComponent->value->mOnClickCB.IsRegistered(handler);
        if (isRegistered) {
            return;
        }

        pButtonComponent->value->mOnClickCB.Register(handler, [handlerCallCollector, handler, eid, pButtonComponent](nsImGuiWidgets::TButton* pB)
        {
            handlerCallCollector->Add([handler, eid, pButtonComponent]()
            {
                handler->Handle(eid, pButtonComponent);
            });
        });
    });
}
