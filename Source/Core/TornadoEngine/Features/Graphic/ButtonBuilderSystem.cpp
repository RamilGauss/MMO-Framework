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

using namespace nsGraphicWrapper;

void TButtonBuilderSystem::Reactive(nsECSFramework::TEntityID eid, nsECSFramework::IComponent* pC)
{
    auto pButtonComponent = (nsGuiWrapper::TButtonComponent*) pC;
    auto entMng = GetEntMng();

    auto titleComponent = entMng->ViewComponent<nsGuiWrapper::TTitleComponent>(eid);
    pButtonComponent->value->SetTitle(titleComponent->value);

    TUnitBuilderHelper::SetupButton(entMng, eid, pButtonComponent);
}
