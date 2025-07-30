/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ImGuiWidgets/Include/MainWindow.h"

#include "TornadoEngine/Modules/Common/Modules.h"
#include "TornadoEngine/Modules/Implementations/GraphicEngineModule.h"

#include "TornadoEngine/Components/Meta/UniverseIndexComponent.h"

#include "TornadoEngine/Features/Graphic/Begin/Terminator/Frames/MainWindowTerminatorSystem.h"

using namespace nsGraphicWrapper;

void TMainWindowTerminatorSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TMainWindowComponent* pMainWindowComponent)
{
    auto universeIndex = GetEntMng()->ViewComponent<nsCommonWrapper::TUniverseIndexComponent>(eid)->value;

    auto pContext = (nsTornadoEngine::TGraphicEngineContext*)(nsTornadoEngine::Modules()->G()->GetContext(universeIndex));
    pContext->GetGraphicEngineContext()->RemoveRender(pMainWindowComponent->value);

    delete pMainWindowComponent->value;
    pMainWindowComponent->value = nullptr;
}
