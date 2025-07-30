/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ImGuiWidgets/Include/TreeView.h"

#include "TornadoEngine/Components/Meta/GuidComponent.h"
#include "TornadoEngine/Components/Meta/ParentGuidComponent.h"
#include "TornadoEngine/Components/Gui/Widgets/FrameComponent.h"
#include "TornadoEngine/Components/Gui/Widgets/WindowComponent.h"
#include "TornadoEngine/Components/Gui/Widgets/FrameComponent.h"
#include "TornadoEngine/Components/Gui/Widgets/DialogComponent.h"

#include "TornadoEngine/Features/Graphic/Begin/Terminator/Frames/TreeViewTerminatorSystem.h"
#include "TornadoEngine/Features/Graphic/Begin/Builder/Helpers/UnitBuilderHelper.h"

using namespace nsGraphicWrapper;

void TTreeViewTerminatorSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TTreeViewComponent* pTreeViewComponent)
{
    TUnitBuilderHelper::UnlinkParent(GetEntMng(), eid, pTreeViewComponent->value);

    pTreeViewComponent->value->RemoveAllNodes();

    delete pTreeViewComponent->value;
    pTreeViewComponent->value = nullptr;
}
