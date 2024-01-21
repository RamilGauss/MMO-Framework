/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TreeNodeBuilderSystem.h"

#include <ImGuiWidgets/include/TreeNode.h>

#include "Features/Graphic/Begin/Builder/Helpers/HandlerLinkHelper.h"
#include "Features/Graphic/Begin/Builder/Helpers/UnitBuilderHelper.h"
#include "Features/Graphic/Begin/Builder/Helpers/HandlerLinkHelper.h"

#include "Components/Gui/Properties/TitleComponent.h"
#include "Components/Gui/Properties/NodeIconComponent.h"
#include "Components/Graphic/TextureFromFileComponent.h"

#include "Components/Meta/PrefabOriginalGuidComponent.h"
#include "Components/Meta/SceneOriginalGuidComponent.h"

#include "Modules/Common/Modules.h"
#include "Modules/Resources/Common/HandlerCallCollector.h"

#include "Modules/Implementations/GraphicEngineModule.h"
#include "GraphicEngine/TextureFactory.h"

using namespace nsGraphicWrapper;
using namespace nsGuiWrapper;

// Prefab or scene
void TTreeNodeBuilderSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TTreeNodeComponent* pTreeNodeComponent)
{
    auto entMng = GetEntMng();

    TUnitBuilderHelper::SetupTreeNode(entMng, eid, pTreeNodeComponent->value);

    auto pTreeNodeIconComponent = entMng->ViewComponent<nsGuiWrapper::TNodeIconComponent>(eid);
    if (pTreeNodeIconComponent) {
        
        auto pTexture = entMng->ViewComponent<TTextureFromFileComponent>(eid)->value;

        auto handle = (void*) (pTexture->mId);
        pTreeNodeComponent->value->SetTextureId(handle);
        pTreeNodeComponent->value->SetTextureSize(pTreeNodeIconComponent->width, pTreeNodeIconComponent->height);
    }
}
