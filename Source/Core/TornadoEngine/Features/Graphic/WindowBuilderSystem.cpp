/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "WindowBuilderSystem.h"

#include <ImGuiWidgets/include/Window.h>

#include "Modules.h"
#include "GraphicEngineModule.h"

#include "PositionComponent.h"
#include "SizeComponent.h"
#include "TitleComponent.h"

using namespace nsGraphicWrapper;

void TWindowBuilderSystem::Reactive(nsECSFramework::TEntityID eid, nsECSFramework::IComponent* pC)
{
    auto pWindowComponent = (nsGuiWrapper::TWindowComponent*) pC;
    nsTornadoEngine::Modules()->G()->GetGE()->AddRender(pWindowComponent->value);

    auto entMng = GetEntMng();

    auto posComponent = entMng->ViewComponent<nsGuiWrapper::TPositionComponent>(eid);
    pWindowComponent->value->SetPos({(float) posComponent->x,(float) posComponent->y});

    auto sizeComponent = entMng->ViewComponent<nsGuiWrapper::TSizeComponent>(eid);
    pWindowComponent->value->SetSize({(float) sizeComponent->x,(float) sizeComponent->y});

    auto titleComponent = entMng->ViewComponent<nsGuiWrapper::TTitleComponent>(eid);
    pWindowComponent->value->SetTitle(titleComponent->value);
}
