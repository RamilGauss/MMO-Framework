/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "WindowBuilderSystem.h"

#include "ImGuiWidgets/Include/Window.h"

#include "Modules/Common/Modules.h"
#include "Modules/Implementations/GraphicEngineModule.h"

#include "Components/Gui/Properties/PositionComponent.h"
#include "Components/Gui/Properties/SizeComponent.h"
#include "Components/Gui/Properties/TitleComponent.h"

#include "Features/Graphic/Begin/Builder/Helpers/UnitBuilderHelper.h"
#include "Features/Graphic/Begin/Builder/Helpers/HandlerLinkHelper.h"
//#include "Modules/Resources/Common/HandlerCallCollector.h"
//#include "Components/Meta/UniverseIndexComponent.h"

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

    //auto handlerCallCollector = nsTornadoEngine::Modules()->HandlerCalls();
    //pWindowComponent->value->mOnShowCB.Register(pWindowComponent->value,
    //    [entMng, handlerCallCollector, eid, pWindowComponent](bool isShown)
    //{
    //    if (isShown) {
    //        return;
    //    }

    //    auto handlers = THandlerLinkHelper::FindHandlers<TWindowCloseEventHandlerComponent>(entMng, eid, pWindowComponent);

    //    for (auto& pHandler : handlers) {
    //        handlerCallCollector->Add([pHandler, eid, pWindowComponent]()
    //        {
    //            pHandler->handler->Handle(eid, pWindowComponent);
    //        });
    //    }
    //});

    THandlerLinkHelper::RegisterMouseKey(entMng, eid, pWindowComponent);



}
