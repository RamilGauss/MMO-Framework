/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "MenuNodeBuilderSystem.h"

#include <ImGuiWidgets/include/MenuNode.h>

#include "UnitBuilderHelper.h"

#include "TitleComponent.h"
#include "TextureFromFileComponent.h"

#include "PrefabOriginalGuidComponent.h"
#include "SceneOriginalGuidComponent.h"

#include "Modules.h"
#include "HandlerCallCollector.h"

#include "HandlerLinkHelper.h"

#include "NodeIconComponent.h"
#include "Modules.h"
#include "GraphicEngineModule.h"

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


    //auto handlerCallCollector = nsTornadoEngine::Modules()->HandlerCalls();
    //pMenuNodeComponent->value->mOnLeftClickCB.Register(pMenuNodeComponent->value,
    //    [entMng, handlerCallCollector, eid, pMenuNodeComponent](nsImGuiWidgets::TNode* pB)
    //{
    //    auto handlers = THandlerLinkHelper::FindHandlers<TMenuNodeClickHandlerComponent>(entMng, eid, pMenuNodeComponent);
    //    for (auto& pHandler : handlers) {
    //        handlerCallCollector->Add([pHandler, eid, pMenuNodeComponent]()
    //        {
    //            pHandler->handler->Handle(eid, pMenuNodeComponent);
    //        });
    //    }
    //});
}
