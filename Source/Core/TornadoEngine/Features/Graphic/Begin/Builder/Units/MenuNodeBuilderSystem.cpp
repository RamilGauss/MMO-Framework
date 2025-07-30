/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/


#include "ImGuiWidgets/Include/MenuNode.h"
#include "GraphicEngine/TextureFactory.h"


#include "TornadoEngine/Components/Gui/Properties/TitleComponent.h"
#include "TornadoEngine/Components/Gui/Properties/NodeIconComponent.h"
#include "TornadoEngine/Components/Graphic/TextureFromFileComponent.h"

#include "TornadoEngine/Components/Meta/PrefabOriginalGuidComponent.h"
#include "TornadoEngine/Components/Meta/SceneOriginalGuidComponent.h"

#include "TornadoEngine/Handlers/Gui/IMenuNodeClickHandler.h"

#include "TornadoEngine/Modules/Common/Modules.h"
#include "TornadoEngine/Modules/Resources/Common/HandlerCallCollector.h"
#include "TornadoEngine/Modules/Implementations/GraphicEngineModule.h"

#include "TornadoEngine/Features/Graphic/Begin/Builder/Helpers/HandlerLinkHelper.h"
#include "TornadoEngine/Features/Graphic/Begin/Builder/Helpers/UnitBuilderHelper.h"
#include "TornadoEngine/Features/Graphic/Begin/Builder/Units/MenuNodeBuilderSystem.h"

using namespace nsGraphicWrapper;
using namespace nsGuiWrapper;

// Prefab or scene
void TMenuNodeBuilderSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TMenuNodeComponent* pMenuNodeComponent)
{
    auto entMng = GetEntMng();

    TUnitBuilderHelper::SetupMenuNode(entMng, eid, pMenuNodeComponent->value);

    auto pTreeNodeIconComponent = entMng->ViewComponent<nsGuiWrapper::TNodeIconComponent>(eid);
    if (pTreeNodeIconComponent) {

        auto pTexture = entMng->ViewComponent<TTextureFromFileComponent>(eid)->value;

        auto handle = (void*)(pTexture->mId);
        pMenuNodeComponent->value->SetTextureId(handle);
        pMenuNodeComponent->value->SetTextureSize(pTreeNodeIconComponent->width, pTreeNodeIconComponent->height);
    }

    auto handlerCallCollector = nsTornadoEngine::Modules()->HandlerCalls();
    pMenuNodeComponent->value->mOnLeftClickCB.Register(pMenuNodeComponent->value,
        [entMng, handlerCallCollector, eid, pMenuNodeComponent](nsImGuiWidgets::TNode* pB)
    {
        auto handlers = THandlerLinkHelper::FindLocalHandlers(entMng, eid, "nsGuiWrapper::IMenuNodeClickHandler");
        for (auto& pHandler : handlers) {
            auto pH = static_cast<nsGuiWrapper::IMenuNodeClickHandler*>(pHandler);
            handlerCallCollector->Add([pH, eid, pMenuNodeComponent]()
            {
                pH->Handle(eid, pMenuNodeComponent);
            });
        }
    });
}
