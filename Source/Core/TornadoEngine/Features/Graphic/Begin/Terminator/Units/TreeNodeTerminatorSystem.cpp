/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ImGuiWidgets/Include/TreeNode.h"

#include "TornadoEngine/Components/Meta/GuidComponent.h"
#include "TornadoEngine/Components/Meta/ParentGuidComponent.h"
#include "TornadoEngine/Components/Gui/Widgets/FrameComponent.h"
#include "TornadoEngine/Components/Gui/Widgets/WindowComponent.h"
#include "TornadoEngine/Components/Gui/Widgets/FrameComponent.h"
#include "TornadoEngine/Components/Gui/Widgets/DialogComponent.h"

#include "TornadoEngine/Features/Graphic/Begin/Builder/Helpers/UnitBuilderHelper.h"
#include "TornadoEngine/Features/Graphic/Begin/Terminator/Units/TreeNodeTerminatorSystem.h"

using namespace nsGraphicWrapper;

void TTreeNodeTerminatorSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TTreeNodeComponent* pTreeNodeComponent)
{
    TUnitBuilderHelper::UnlinkTreeNode(GetEntMng(), eid, pTreeNodeComponent->value);

    delete pTreeNodeComponent->value;
    pTreeNodeComponent->value = nullptr;
}
