/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/


#include "ImGuiWidgets/Include/TreeNode.h"
#include "GraphicEngine/TextureFactory.h"

#include "TornadoEngine/Components/Gui/Properties/TitleComponent.h"
#include "TornadoEngine/Components/Gui/Properties/NodeIconComponent.h"
#include "TornadoEngine/Components/Graphic/TextureFromFileComponent.h"

#include "TornadoEngine/Components/Meta/PrefabOriginalGuidComponent.h"
#include "TornadoEngine/Components/Meta/SceneOriginalGuidComponent.h"

#include "TornadoEngine/Modules/Common/Modules.h"
#include "TornadoEngine/Modules/Resources/Common/HandlerCallCollector.h"
#include "TornadoEngine/Modules/Implementations/GraphicEngineModule.h"

#include "TornadoEngine/Features/Graphic/Begin/Builder/Units/TreeNodeBuilderSystem.h"
#include "TornadoEngine/Features/Graphic/Begin/Builder/Helpers/HandlerLinkHelper.h"
#include "TornadoEngine/Features/Graphic/Begin/Builder/Helpers/UnitBuilderHelper.h"
#include "TornadoEngine/Features/Graphic/Begin/Builder/Helpers/HandlerLinkHelper.h"

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
