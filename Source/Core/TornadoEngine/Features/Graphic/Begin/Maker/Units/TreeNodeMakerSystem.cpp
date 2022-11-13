/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TreeNodeMakerSystem.h"

#include <ImGuiWidgets/include/TreeNode.h>

#include "NodeIconComponent.h"

#include "VisibilityComponent.h"
#include "TitleComponent.h"


using namespace nsGraphicWrapper;

void TTreeNodeMakerSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TTreeNodeComponent* pTreeNodeComponent)
{
    auto pTreeNode = new nsImGuiWidgets::TTreeNode();
    pTreeNodeComponent->value = pTreeNode;

    auto entMng = GetEntMng();

    auto pWidget = dynamic_cast<nsImGuiWidgets::TWidget*>(pTreeNode);

    entMng->ViewComponent<nsGuiWrapper::TTitleComponent>(eid)->pOwner = pWidget;
    entMng->ViewComponent<nsGuiWrapper::TVisibilityComponent>(eid)->pOwner = pWidget;
    entMng->ViewComponent<nsGuiWrapper::TNodeIconComponent>(eid)->pOwner = pWidget;
}
