/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TreeNodeMakerSystem.h"

#include <ImGuiWidgets/include/TreeNode.h>

#include "Components/Gui/Properties/NodeIconComponent.h"

#include "Components/Gui/Properties/VisibilityComponent.h"
#include "Components/Gui/Properties/TitleComponent.h"


using namespace nsGraphicWrapper;

void TTreeNodeMakerSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TTreeNodeComponent* pTreeNodeComponent)
{
    auto pTreeNode = new nsImGuiWidgets::TTreeNode();
    pTreeNodeComponent->value = pTreeNode;

    auto entMng = GetEntMng();

    auto pWidget = dynamic_cast<nsImGuiWidgets::TWidget*>(pTreeNode);

    entMng->ViewComponent<nsGuiWrapper::TTitleComponent>(eid)->SetOwner(pTreeNode);
    entMng->ViewComponent<nsGuiWrapper::TVisibilityComponent>(eid)->SetOwner(pTreeNode);
    entMng->ViewComponent<nsGuiWrapper::TNodeIconComponent>(eid)->SetOwner(pTreeNode);
}
