/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ButtonClickHandlerTerminatorSystem.h"
#include "Modules.h"
#include "ProjectConfigContainer.h"
#include "Logger.h"
#include "TimeSliceEngine.h"


#include "ButtonComponent.h"
#include "ButtonClickHandlerComponent.h"

#include "GuidConstants.h"
#include "SceneOriginalGuidComponent.h"
#include "PrefabOriginalGuidComponent.h"

#include "HandlerLinkHelper.h"

using namespace nsGraphicWrapper;

void TButtonClickHandlerTerminatorSystem::Reactive(nsECSFramework::TEntityID eid,
    const nsGuiWrapper::TButtonClickHandlerComponent* pButtonClickHandlerComponent)
{
    auto entMng = GetEntMng();
    THandlerLinkHelper::UnlinkGui<nsGuiWrapper::TButtonComponent>(entMng, eid, pButtonClickHandlerComponent, 
    [pButtonClickHandlerComponent](const nsGuiWrapper::TButtonComponent* pButtonComponent)
    {
        auto handler = pButtonClickHandlerComponent->handler;
        pButtonComponent->value->mOnClickCB.Unregister(handler);
    });
}
