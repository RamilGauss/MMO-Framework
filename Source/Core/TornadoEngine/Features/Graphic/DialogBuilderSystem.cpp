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

using namespace nsGraphicWrapper;
using namespace nsGuiWrapper;

void TDialogBuilderSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TDialogComponent* pDialogComponent)
{
    auto dialogStack = nsTornadoEngine::Modules()->G()->GetDialogStack();
    dialogStack->Add(pDialogComponent->value);


    auto entMng = GetEntMng();

    auto posComponent = entMng->ViewComponent<nsGuiWrapper::TPositionComponent>(eid);
    pDialogComponent->value->SetPos({(float) posComponent->x,(float) posComponent->y});

    auto sizeComponent = entMng->ViewComponent<nsGuiWrapper::TSizeComponent>(eid);
    pDialogComponent->value->SetSize({(float) sizeComponent->x,(float) sizeComponent->y});

    auto titleComponent = entMng->ViewComponent<nsGuiWrapper::TTitleComponent>(eid);
    pDialogComponent->value->SetTitle(titleComponent->value);

    auto handlerCallCollector = nsTornadoEngine::Modules()->HandlerCalls();
    THandlerLinkHelper::LinkToHandler<TDialogCloseEventHandlerComponent>(entMng, eid, pDialogComponent,
        [pDialogComponent, handlerCallCollector, eid](const TDialogCloseEventHandlerComponent* handlerComponent)
    {
        auto handler = handlerComponent->handler;
        auto isRegistered = pDialogComponent->value->mOnShowCB.IsRegistered(handler);
        if (isRegistered) {
            return;
        }

        pDialogComponent->value->mOnShowCB.Register(handler, [handlerCallCollector, handler, eid, pDialogComponent](bool isShown)
        {
            if (isShown) {
                return;
            }

            handlerCallCollector->Add([handler, eid, pDialogComponent]()
            {
                handler->Handle(eid, pDialogComponent);
            });
        });
    });

}
