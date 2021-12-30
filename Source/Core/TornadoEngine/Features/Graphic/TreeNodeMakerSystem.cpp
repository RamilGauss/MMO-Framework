/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TreeNodeMakerSystem.h"

#include <ImGuiWidgets/include/TreeNode.h>

using namespace nsGraphicWrapper;

void TTreeNodeMakerSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TTreeNodeComponent* pTreeNodeComponent)
{
    pTreeNodeComponent->value = new nsImGuiWidgets::TTreeNode();
}
