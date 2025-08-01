/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/


#include "ImGuiWidgets/Include/Button.h"

#include "TornadoEngine/Components/Gui/Properties/TitleComponent.h"

#include "TornadoEngine/Handlers/Gui/IButtonClickHandler.h"

#include "TornadoEngine/Components/Meta/PrefabOriginalGuidComponent.h"
#include "TornadoEngine/Components/Meta/SceneOriginalGuidComponent.h"

#include "TornadoEngine/Modules/Common/Modules.h"
#include "TornadoEngine/Modules/Resources/Common/HandlerCallCollector.h"

#include "TornadoEngine/Features/Graphic/Begin/Builder/Units/ButtonBuilderSystem.h"
#include "TornadoEngine/Features/Graphic/Begin/Builder/Helpers/HandlerLinkHelper.h"
#include "TornadoEngine/Features/Graphic/Begin/Builder/Helpers/UnitBuilderHelper.h"

using namespace nsGraphicWrapper;
using namespace nsGuiWrapper;

// Prefab or scene
void TButtonBuilderSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TButtonComponent* pButtonComponent)
{
    auto entMng = GetEntMng();

    TUnitBuilderHelper::SetupWidget(entMng, eid, pButtonComponent->value);

    auto handlerCallCollector = nsTornadoEngine::Modules()->HandlerCalls();
    pButtonComponent->value->mOnClickCB.Register(pButtonComponent->value, 
        [entMng, handlerCallCollector, eid, pButtonComponent](nsImGuiWidgets::TButton* pB)
    {
        //auto handlers = THandlerLinkHelper::FindHandlers<TButtonClickHandlerComponent>(entMng, eid, pButtonComponent);
        //for (auto& pHandler : handlers) {
        //    handlerCallCollector->Add([pHandler, eid, pButtonComponent]()
        //    {
        //        pHandler->handler->Handle(eid, pButtonComponent);
        //    });
        //}
    });
}
