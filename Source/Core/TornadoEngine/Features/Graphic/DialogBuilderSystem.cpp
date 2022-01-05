/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "DialogBuilderSystem.h"

#include <ImGuiWidgets/include/Dialog.h>

#include "Modules.h"
#include "GraphicEngineModule.h"

#include "PositionComponent.h"
#include "SizeComponent.h"
#include "TitleComponent.h"

#include "PrefabOriginalGuidComponent.h"
#include "SceneOriginalGuidComponent.h"

#include "DialogCloseEventHandlerComponent.h"
#include "HandlerLinkHelper.h"
#include "HandlerCallCollector.h"
#include "UnitBuilderHelper.h"

using namespace nsGraphicWrapper;
using namespace nsGuiWrapper;

void TDialogBuilderSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TDialogComponent* pDialogComponent)
{
    auto dialogStack = nsTornadoEngine::Modules()->G()->GetDialogStack();
    dialogStack->Add(pDialogComponent->value);

    auto entMng = GetEntMng();

    TUnitBuilderHelper::SetupWidget(entMng, eid, pDialogComponent->value);
    TUnitBuilderHelper::SetupGeometry(entMng, eid, pDialogComponent->value);

    auto handlerCallCollector = nsTornadoEngine::Modules()->HandlerCalls();
    pDialogComponent->value->mOnShowCB.Register(pDialogComponent->value, 
        [entMng, handlerCallCollector, eid, pDialogComponent](bool isShown)
    {
        if (isShown) {
            return;
        }

        auto handlers = THandlerLinkHelper::FindHandlers<TDialogCloseEventHandlerComponent>(entMng, eid, pDialogComponent);

        for (auto& pHandler : handlers) {
            handlerCallCollector->Add([pHandler, eid, pDialogComponent]()
            {
                pHandler->handler->Handle(eid, pDialogComponent);
            });
        }
    });
}
