/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "WindowTerminatorSystem.h"
#include "Modules/Common/Modules.h"
#include "Modules/Implementations/GraphicEngineModule.h"

#include "ImGuiWidgets/Include/Window.h"

#include "Components/Meta/UniverseIndexComponent.h"

using namespace nsGraphicWrapper;

void TWindowTerminatorSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TWindowComponent* pWindowComponent)
{
    auto universeIndex = GetEntMng()->ViewComponent<nsCommonWrapper::TUniverseIndexComponent>(eid)->value;

    auto pContext = (nsTornadoEngine::TGraphicEngineContext*) (nsTornadoEngine::Modules()->G()->GetContext(universeIndex));
    pContext->GetGraphicEngineContext()->RemoveRender(pWindowComponent->value);

    delete pWindowComponent->value;
    pWindowComponent->value = nullptr;
}
