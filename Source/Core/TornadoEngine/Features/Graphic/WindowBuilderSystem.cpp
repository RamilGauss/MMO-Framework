/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "WindowBuilderSystem.h"

#include <ImGuiWidgets/include/Window.h>

#include "Modules.h"
#include "GraphicEngineModule.h"

#include "PositionComponent.h"
#include "SizeComponent.h"
#include "TitleComponent.h"

#include "UnitBuilderHelper.h"
#include "HandlerLinkHelper.h"
#include "HandlerCallCollector.h"
#include "UniverseGuidComponent.h"

using namespace nsGraphicWrapper;
using namespace nsGuiWrapper;

void TWindowBuilderSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TWindowComponent* pWindowComponent)
{
    auto universeGuid = GetEntMng()->ViewComponent<nsCommonWrapper::TUniverseGuidComponent>(eid)->value;

    auto pContext = nsTornadoEngine::Modules()->G()->GetContext(universeGuid);
    pContext->AddRender(pWindowComponent->value);

    auto entMng = GetEntMng();

    TUnitBuilderHelper::SetupWidget(entMng, eid, pWindowComponent->value);

    TUnitBuilderHelper::SetupGeometry(entMng, eid, pWindowComponent->value);

    auto handlerCallCollector = nsTornadoEngine::Modules()->HandlerCalls();
    pWindowComponent->value->mOnShowCB.Register(pWindowComponent->value,
        [entMng, handlerCallCollector, eid, pWindowComponent](bool isShown)
    {
        if (isShown) {
            return;
        }

        auto handlers = THandlerLinkHelper::FindHandlers<TWindowCloseEventHandlerComponent>(entMng, eid, pWindowComponent);

        for (auto& pHandler : handlers) {
            handlerCallCollector->Add([pHandler, eid, pWindowComponent]()
            {
                pHandler->handler->Handle(eid, pWindowComponent);
            });
        }
    });

    THandlerLinkHelper::RegisterMouseKey(entMng, eid, pWindowComponent);
}
