/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "MenuNodeBuilderSystem.h"

#include <ImGuiWidgets/include/MenuNode.h>

#include "Features/Graphic/Begin/Builder/Helpers/HandlerLinkHelper.h"
#include "Features/Graphic/Begin/Builder/Helpers/UnitBuilderHelper.h"

#include "Components/Gui/Properties/TitleComponent.h"
#include "Components/Gui/Properties/NodeIconComponent.h"
#include "Components/Graphic/TextureFromFileComponent.h"

#include "Components/Meta/PrefabOriginalGuidComponent.h"
#include "Components/Meta/SceneOriginalGuidComponent.h"

#include "Handlers/Gui/IMenuNodeClickHandler.h"

#include "Modules/Common/Modules.h"
#include "Modules/Resources/Common/HandlerCallCollector.h"

#include "Modules/Implementations/GraphicEngineModule.h"

#include "GraphicEngine/TextureFactory.h"

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
