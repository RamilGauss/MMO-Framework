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

#include "UnitBuilderHelper.h"

using namespace nsGraphicWrapper;

void TWindowBuilderSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TWindowComponent* pWindowComponent)
{
    nsTornadoEngine::Modules()->G()->GetGE()->AddRender(pWindowComponent->value);

    auto entMng = GetEntMng();

    TUnitBuilderHelper::SetupWidget(entMng, eid, pWindowComponent->value);

    TUnitBuilderHelper::SetupGeometry(entMng, eid, pWindowComponent->value);
}
