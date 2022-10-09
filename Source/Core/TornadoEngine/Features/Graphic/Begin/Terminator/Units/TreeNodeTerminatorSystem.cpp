/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TreeNodeTerminatorSystem.h"

#include "GuidComponent.h"
#include "ParentGuidComponent.h"
#include "FrameComponent.h"
#include "WindowComponent.h"
#include "FrameComponent.h"
#include "DialogComponent.h"
#include "UnitBuilderHelper.h"

#include <ImGuiWidgets/include/TreeNode.h>

using namespace nsGraphicWrapper;

void TTreeNodeTerminatorSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TTreeNodeComponent* pTreeNodeComponent)
{
    TUnitBuilderHelper::UnlinkTreeNode(GetEntMng(), eid, pTreeNodeComponent->value);

    delete pTreeNodeComponent->value;
    pTreeNodeComponent->value = nullptr;
}
