/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/


#include "ImGuiWidgets/Include/Window.h"

#include "TornadoEngine/Modules/Common/Modules.h"
#include "TornadoEngine/Modules/Implementations/GraphicEngineModule.h"

#include "TornadoEngine/Components/Gui/Properties/PositionComponent.h"
#include "TornadoEngine/Components/Gui/Properties/SizeComponent.h"
#include "TornadoEngine/Components/Gui/Properties/TitleComponent.h"

#include "TornadoEngine/Features/Graphic/Begin/Builder/Frames/WindowBuilderSystem.h"
#include "TornadoEngine/Features/Graphic/Begin/Builder/Helpers/UnitBuilderHelper.h"
#include "TornadoEngine/Features/Graphic/Begin/Builder/Helpers/HandlerLinkHelper.h"

using namespace nsGraphicWrapper;
using namespace nsGuiWrapper;

void TWindowBuilderSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TWindowComponent* pWindowComponent)
{
    auto universeIndex = GetEntMng()->ViewComponent<nsCommonWrapper::TUniverseIndexComponent>(eid)->value;

    auto pContext = (nsTornadoEngine::TGraphicEngineContext*) (nsTornadoEngine::Modules()->G()->GetContext(universeIndex));

    pContext->GetGraphicEngineContext()->AddRender(pWindowComponent->value);

    auto entMng = GetEntMng();

    TUnitBuilderHelper::SetupWidget(entMng, eid, pWindowComponent->value);

    TUnitBuilderHelper::SetupSize(entMng, eid, pWindowComponent->value);
    TUnitBuilderHelper::SetupPosition(entMng, eid, pWindowComponent->value);

    THandlerLinkHelper::RegisterMouseKey(entMng, eid, pWindowComponent);
}
