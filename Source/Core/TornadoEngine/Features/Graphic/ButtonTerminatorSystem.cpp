/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ButtonTerminatorSystem.h"

#include "GuidComponent.h"
#include "ParentGuidComponent.h"
#include "FrameComponent.h"
#include "WindowComponent.h"
#include "FrameComponent.h"
#include "DialogComponent.h"

#include <ImGuiWidgets/include/Button.h>

using namespace nsGraphicWrapper;

void TButtonTerminatorSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TButtonComponent* pButtonComponent)
{
    auto parentGuid = GetEntMng()->ViewComponent<nsCommonWrapper::TParentGuidComponent>(eid)->value;

    nsCommonWrapper::TGuidComponent guidComponent;
    guidComponent.value = parentGuid;
    auto parentEid = GetEntMng()->GetByUnique(guidComponent);

    auto frameComponent = GetEntMng()->ViewComponent<nsGuiWrapper::TFrameComponent>(parentEid);
    if (frameComponent) {
        frameComponent->value->Replace(pButtonComponent->value);
    } 
    auto windowComponent = GetEntMng()->ViewComponent<nsGuiWrapper::TWindowComponent>(parentEid);
    if (windowComponent) {
        windowComponent->value->Replace(pButtonComponent->value);
    }
    auto dialogComponent = GetEntMng()->ViewComponent<nsGuiWrapper::TDialogComponent>(parentEid);
    if (dialogComponent) {
        dialogComponent->value->Replace(pButtonComponent->value);
    }

    delete pButtonComponent->value;
    pButtonComponent->value = nullptr;
}
