/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TreeNodeBuilderSystem.h"

#include <ImGuiWidgets/include/TreeNode.h>

#include "UnitBuilderHelper.h"

#include "TitleComponent.h"

#include "ButtonClickHandlerComponent.h"

#include "PrefabOriginalGuidComponent.h"
#include "SceneOriginalGuidComponent.h"

#include "Modules.h"
#include "HandlerCallCollector.h"

#include "HandlerLinkHelper.h"
#include "TreeNodeIconComponent.h"


#include <OgreTextureManager.h>
#include <OgreTexture.h>

using namespace nsGraphicWrapper;
using namespace nsGuiWrapper;

// Prefab or scene
void TTreeNodeBuilderSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TTreeNodeComponent* pTreeNodeComponent)
{
    auto entMng = GetEntMng();

    TUnitBuilderHelper::SetupTreeNode(entMng, eid, pTreeNodeComponent->value);

    auto pTreeNodeIconComponent = entMng->ViewComponent<nsGuiWrapper::TTreeNodeIconComponent>(eid);
    if (pTreeNodeIconComponent) {
        
        try {
            auto mTex = Ogre::TextureManager::getSingleton().load(pTreeNodeIconComponent->iconFileName, "General");
            auto handle = (void*) (mTex->getHandle());
            pTreeNodeComponent->value->SetTexture(handle, pTreeNodeIconComponent->width, pTreeNodeIconComponent->height);
        } catch(...) { 

        }
    }
}
