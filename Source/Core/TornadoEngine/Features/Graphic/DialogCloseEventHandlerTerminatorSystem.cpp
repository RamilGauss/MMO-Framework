/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "DialogCloseEventHandlerTerminatorSystem.h"
#include "Modules.h"
#include "ProjectConfigContainer.h"
#include "Logger.h"
#include "TimeSliceEngine.h"

#include "DialogComponent.h"
#include "DialogCloseEventHandlerComponent.h"

#include "GuidConstants.h"
#include "SceneOriginalGuidComponent.h"
#include "PrefabOriginalGuidComponent.h"

#include "HandlerLinkHelper.h"

using namespace nsGraphicWrapper;
using namespace nsGuiWrapper;

void TDialogCloseEventHandlerTerminatorSystem::Reactive(nsECSFramework::TEntityID eid,
    const nsGuiWrapper::TDialogCloseEventHandlerComponent* pDialogCloseEventHandlerComponent)
{
    auto entMng = GetEntMng();
    THandlerLinkHelper::UnlinkGui<TDialogComponent>(entMng, eid, pDialogCloseEventHandlerComponent,
        [pDialogCloseEventHandlerComponent](const nsGuiWrapper::TDialogComponent* pDialogComponent)
    {
        if (pDialogComponent->value == nullptr) {
            return;
        }

        auto handler = pDialogCloseEventHandlerComponent->handler;
        pDialogComponent->value->mOnShowCB.Unregister(handler);
    });
}
