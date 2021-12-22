/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "MenuNodeBuilderSystem.h"

#include <ImGuiWidgets/include/MenuNode.h>

#include "UnitBuilderHelper.h"

#include "TitleComponent.h"

#include "MenuNodeClickHandlerComponent.h"

#include "PrefabOriginalGuidComponent.h"
#include "SceneOriginalGuidComponent.h"

#include "Modules.h"
#include "HandlerCallCollector.h"

#include "HandlerLinkHelper.h"

using namespace nsGraphicWrapper;
using namespace nsGuiWrapper;

// Prefab or scene
void TMenuNodeBuilderSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TMenuNodeComponent* pMenuNodeComponent)
{
    auto entMng = GetEntMng();

    TUnitBuilderHelper::SetupMenuNode(entMng, eid, pMenuNodeComponent->value);

    auto handlerCallCollector = nsTornadoEngine::Modules()->HandlerCalls();
    THandlerLinkHelper::LinkToHandler<TMenuNodeClickHandlerComponent>(entMng, eid, pMenuNodeComponent,
        [pMenuNodeComponent, handlerCallCollector, eid](const TMenuNodeClickHandlerComponent* handlerComponent)
    {
        auto handler = handlerComponent->handler;
        auto isRegistered = pMenuNodeComponent->value->mOnLeftClickCB.IsRegistered(handler);
        if (isRegistered) {
            return;
        }

        pMenuNodeComponent->value->mOnLeftClickCB.Register(handler, 
            [handlerCallCollector, handler, eid, pMenuNodeComponent](nsImGuiWidgets::TNode* pB)
        {
            handlerCallCollector->Add([handler, eid, pMenuNodeComponent]()
            {
                handler->Handle(eid, pMenuNodeComponent);
            });
        });
    });
}
