/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "MainWindowBuilderSystem.h"

#include <ImGuiWidgets/include/MainWindow.h>

#include "Modules/Common/Modules.h"
#include "Modules/Implementations/GraphicEngineModule.h"

#include "Components/Meta/UniverseIndexComponent.h"

using namespace nsGraphicWrapper;

void TMainWindowBuilderSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TMainWindowComponent* pMainWindowComponent)
{
    auto universeIndex = GetEntMng()->ViewComponent<nsCommonWrapper::TUniverseIndexComponent>(eid)->value;

    auto pContext = (nsTornadoEngine::TGraphicEngineContext*)(nsTornadoEngine::Modules()->G()->GetContext(universeIndex));
    pContext->GetGraphicEngineContext()->AddRender(pMainWindowComponent->value);
}
