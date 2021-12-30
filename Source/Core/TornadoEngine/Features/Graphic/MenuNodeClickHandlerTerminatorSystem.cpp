/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "MenuNodeClickHandlerTerminatorSystem.h"
#include "Modules.h"
#include "ProjectConfigContainer.h"
#include "Logger.h"
#include "TimeSliceEngine.h"


#include "MenuNodeComponent.h"
#include "MenuNodeClickHandlerComponent.h"

#include "GuidConstants.h"
#include "SceneOriginalGuidComponent.h"
#include "PrefabOriginalGuidComponent.h"

#include "HandlerLinkHelper.h"

using namespace nsGraphicWrapper;

void TMenuNodeClickHandlerTerminatorSystem::Reactive(nsECSFramework::TEntityID eid,
    const nsGuiWrapper::TMenuNodeClickHandlerComponent* pMenuNodeClickHandlerComponent)
{
    auto entMng = GetEntMng();
    THandlerLinkHelper::UnlinkGui<nsGuiWrapper::TMenuNodeComponent>(entMng, eid, pMenuNodeClickHandlerComponent,
        [pMenuNodeClickHandlerComponent](const nsGuiWrapper::TMenuNodeComponent* pMenuNodeComponent)
    {
        if (pMenuNodeComponent->value == nullptr) {
            return;
        }

        auto handler = pMenuNodeClickHandlerComponent->handler;
        pMenuNodeComponent->value->mOnLeftClickCB.Unregister(handler);
    });
}
