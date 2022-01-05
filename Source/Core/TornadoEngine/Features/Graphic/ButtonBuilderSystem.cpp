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
    pButtonComponent->value->mOnClickCB.Register(pButtonComponent->value, 
        [entMng, handlerCallCollector, eid, pButtonComponent](nsImGuiWidgets::TButton* pB)
    {
        auto handlers = THandlerLinkHelper::FindHandlers<TButtonClickHandlerComponent>(entMng, eid, pButtonComponent);
        for (auto& pHandler : handlers) {
            handlerCallCollector->Add([pHandler, eid, pButtonComponent]()
            {
                pHandler->handler->Handle(eid, pButtonComponent);
            });
        }
    });
}
