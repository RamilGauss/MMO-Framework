/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "WindowCloseEventHandlerTerminatorSystem.h"
#include "Modules.h"
#include "ProjectConfigContainer.h"
#include "Logger.h"
#include "TimeSliceEngine.h"

#include "WindowComponent.h"
#include "WindowCloseEventHandlerComponent.h"

#include "GuidConstants.h"
#include "SceneOriginalGuidComponent.h"
#include "PrefabOriginalGuidComponent.h"

#include "HandlerLinkHelper.h"

using namespace nsGraphicWrapper;
using namespace nsGuiWrapper;

void TWindowCloseEventHandlerTerminatorSystem::Reactive(nsECSFramework::TEntityID eid,
    const nsGuiWrapper::TWindowCloseEventHandlerComponent* pWindowCloseEventHandlerComponent)
{
    auto entMng = GetEntMng();
    THandlerLinkHelper::UnlinkGui<TWindowComponent>(entMng, eid, pWindowCloseEventHandlerComponent,
        [pWindowCloseEventHandlerComponent](const nsGuiWrapper::TWindowComponent* pWindowComponent)
    {
        if (pWindowComponent->value == nullptr) {
            return;
        }

        auto handler = pWindowCloseEventHandlerComponent->handler;
        pWindowComponent->value->mOnShowCB.Unregister(handler);
    });
}
