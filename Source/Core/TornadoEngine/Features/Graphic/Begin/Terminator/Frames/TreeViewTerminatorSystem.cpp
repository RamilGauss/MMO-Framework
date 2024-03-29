/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TreeViewTerminatorSystem.h"

#include "Components/Meta/GuidComponent.h"
#include "Components/Meta/ParentGuidComponent.h"
#include "Components/Gui/Widgets/FrameComponent.h"
#include "Components/Gui/Widgets/WindowComponent.h"
#include "Components/Gui/Widgets/FrameComponent.h"
#include "Components/Gui/Widgets/DialogComponent.h"
#include "Features/Graphic/Begin/Builder/Helpers/UnitBuilderHelper.h"

#include <ImGuiWidgets/include/TreeView.h>

using namespace nsGraphicWrapper;

void TTreeViewTerminatorSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TTreeViewComponent* pTreeViewComponent)
{
    TUnitBuilderHelper::UnlinkParent(GetEntMng(), eid, pTreeViewComponent->value);

    pTreeViewComponent->value->RemoveAllNodes();

    delete pTreeViewComponent->value;
    pTreeViewComponent->value = nullptr;
}
