/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "DialogBuilderSystem.h"

#include <ImGuiWidgets/include/Dialog.h>

#include "Modules/Common/Modules.h"
#include "Modules/Implementations/GraphicEngineModule.h"

#include "Components/Gui/Properties/PositionComponent.h"
#include "Components/Gui/Properties/SizeComponent.h"
#include "Components/Gui/Properties/TitleComponent.h"

#include "Components/Meta/PrefabOriginalGuidComponent.h"
#include "Components/Meta/SceneOriginalGuidComponent.h"

#include "Features/Graphic/Begin/Builder/Helpers/HandlerLinkHelper.h"
#include "Features/Graphic/Begin/Builder/Helpers/UnitBuilderHelper.h"

using namespace nsGraphicWrapper;
using namespace nsGuiWrapper;

void TDialogBuilderSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TDialogComponent* pDialogComponent)
{
    auto universeIndex = GetEntMng()->ViewComponent<nsCommonWrapper::TUniverseIndexComponent>(eid)->value;
    auto pCtx = (nsTornadoEngine::TGraphicEngineContext*)(nsTornadoEngine::Modules()->G()->GetContext(universeIndex));
    auto dialogStack = pCtx->GetDialogStack();
    dialogStack->Add(pDialogComponent->value);

    auto entMng = GetEntMng();

    TUnitBuilderHelper::SetupWidget(entMng, eid, pDialogComponent->value);
    TUnitBuilderHelper::SetupSize(entMng, eid, pDialogComponent->value);
    TUnitBuilderHelper::SetupPosition(entMng, eid, pDialogComponent->value);

    auto handlerCallCollector = nsTornadoEngine::Modules()->HandlerCalls();
    pDialogComponent->value->mOnShowCB.Register(pDialogComponent->value, 
        [entMng, handlerCallCollector, eid, pDialogComponent](bool isShown)
    {
        if (isShown) {
            return;
        }

        //auto handlers = THandlerLinkHelper::FindHandlers<TDialogCloseEventHandlerComponent>(entMng, eid, pDialogComponent);

        //for (auto& pHandler : handlers) {
        //    handlerCallCollector->Add([pHandler, eid, pDialogComponent]()
        //    {
        //        pHandler->handler->Handle(eid, pDialogComponent);
        //    });
        //}
    });


    THandlerLinkHelper::RegisterMouseKey(entMng, eid, pDialogComponent);
}
