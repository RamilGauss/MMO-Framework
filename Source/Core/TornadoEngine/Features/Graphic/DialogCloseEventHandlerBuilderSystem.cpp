/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "DialogCloseEventHandlerBuilderSystem.h"

#include <ImGuiWidgets/include/Dialog.h>

#include "DialogComponent.h"
#include "DialogCloseEventHandlerComponent.h"

#include "SceneOriginalGuidComponent.h"
#include "PrefabOriginalGuidComponent.h"

#include "Modules.h"
#include "HandlerCallCollector.h"
#include "HandlerLinkHelper.h"

using namespace nsGraphicWrapper;
using namespace nsGuiWrapper;

// Prefab or scene
void TDialogCloseEventHandlerBuilderSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TDialogCloseEventHandlerComponent* pDialogCloseEventHandlerComponent)
{
    auto entMng = GetEntMng();
    auto handlerCallCollector = nsTornadoEngine::Modules()->HandlerCalls();
    auto handler = pDialogCloseEventHandlerComponent->handler;

    THandlerLinkHelper::LinkToGui<TDialogComponent>(entMng, eid, pDialogCloseEventHandlerComponent,
        [handler, handlerCallCollector](nsECSFramework::TEntityID targetEid, const TDialogComponent* pDialogComponent)
    {
        auto isRegistered = pDialogComponent->value->mOnShowCB.IsRegistered(handler);
        if (isRegistered) {
            return;
        }
        pDialogComponent->value->mOnShowCB.Register(handler, [handlerCallCollector, handler, targetEid, pDialogComponent](bool isShown)
        {
            if (isShown) {
                return;
            }

            handlerCallCollector->Add([handler, targetEid, pDialogComponent]()
            {
                handler->Handle(targetEid, pDialogComponent);
            });
        });
    });
}
