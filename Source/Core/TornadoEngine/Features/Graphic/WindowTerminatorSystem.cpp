/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "WindowTerminatorSystem.h"
#include "Modules.h"
#include "GraphicEngineModule.h"

#include <ImGuiWidgets/include/Window.h>

#include "UniverseGuidComponent.h"

using namespace nsGraphicWrapper;

void TWindowTerminatorSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TWindowComponent* pWindowComponent)
{
    auto universeGuid = GetEntMng()->ViewComponent<nsCommonWrapper::TUniverseGuidComponent>(eid)->value;

    auto pContext = nsTornadoEngine::Modules()->G()->GetContext(universeGuid);
    pContext->RemoveRender(pWindowComponent->value);

    delete pWindowComponent->value;
    pWindowComponent->value = nullptr;
}
