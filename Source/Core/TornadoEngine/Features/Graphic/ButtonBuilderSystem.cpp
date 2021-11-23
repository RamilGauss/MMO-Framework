/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ButtonBuilderSystem.h"

#include <ImGuiWidgets/include/Button.h>

#include "GuidComponent.h"
#include "ParentGuidComponent.h"
#include "PositionComponent.h"
#include "SizeComponent.h"
#include "WindowComponent.h"

using namespace nsGraphicWrapper;

void TButtonBuilderSystem::Reactive(nsECSFramework::TEntityID eid, nsECSFramework::IComponent* pC)
{
    auto pButtonComponent = (nsGuiWrapper::TButtonComponent*) pC;
    auto entMng = GetEntMng();

    auto posComponent = entMng->ViewComponent<nsGuiWrapper::TPositionComponent>(eid);
    pButtonComponent->value->SetPos({(float) posComponent->x,(float) posComponent->y});

    auto sizeComponent = entMng->ViewComponent<nsGuiWrapper::TSizeComponent>(eid);
    pButtonComponent->value->SetSize({(float) sizeComponent->x,(float) sizeComponent->y});

    auto parentGuid = entMng->ViewComponent<nsCommonWrapper::TParentGuidComponent>(eid)->value;

    nsCommonWrapper::TGuidComponent guidComponent;
    guidComponent.value = parentGuid;
    auto parentEid = entMng->GetByUnique(guidComponent);
    if (parentEid == nsECSFramework::NONE) {
        return;
    }

    auto pWindowComponent = entMng->ViewComponent<nsGuiWrapper::TWindowComponent>(parentEid);
    pWindowComponent->value->Add(pButtonComponent->value);
}
