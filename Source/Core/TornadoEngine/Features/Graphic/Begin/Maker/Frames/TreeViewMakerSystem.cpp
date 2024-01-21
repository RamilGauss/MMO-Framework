/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TreeViewMakerSystem.h"

#include <ImGuiWidgets/include/TreeView.h>

#include "Components/Gui/Properties/SizeComponent.h"
#include "Components/Gui/Properties/PositionComponent.h"

#include "Components/Gui/Properties/VisibilityComponent.h"
#include "Components/Gui/Properties/TitleComponent.h"

#include "Components/Gui/Properties/AnchorsComponent.h"
#include "Components/Gui/Properties/MinSizeComponent.h"
#include "Components/Gui/Properties/MaxSizeComponent.h"
#include "Components/Gui/Properties/VerticalAlignComponent.h"
#include "Components/Gui/Properties/HorizontalAlignComponent.h"
#include "Components/Gui/Properties/MinDistanceToParentComponent.h"
#include "Components/Gui/Properties/FocusComponent.h"

using namespace nsGraphicWrapper;

void TTreeViewMakerSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TTreeViewComponent* pTreeViewComponent)
{
    auto pTreeView = new nsImGuiWidgets::TTreeView();
    pTreeViewComponent->value = pTreeView;

    //nsTornadoEngine::Modules()->PropertyMng()->SetupProperties(GetEntMng(), eid, "nsImGuiWidgets::TTreeView", pTreeView);

    auto entMng = GetEntMng();

    auto pWidget = dynamic_cast<nsImGuiWidgets::TWidget*>(pTreeView);

    entMng->ViewComponent<nsGuiWrapper::TTitleComponent>(eid)->pOwner = pWidget;
    entMng->ViewComponent<nsGuiWrapper::TVisibilityComponent>(eid)->pOwner = pWidget;
    entMng->ViewComponent<nsGuiWrapper::TSizeComponent>(eid)->pOwner = pWidget;
    entMng->ViewComponent<nsGuiWrapper::TPositionComponent>(eid)->pOwner = pWidget;

    auto pUnit = dynamic_cast<nsImGuiWidgets::TUnit*>(pTreeView);

    entMng->ViewComponent<nsGuiWrapper::TAnchorsComponent>(eid)->pOwner = pUnit;
    entMng->ViewComponent<nsGuiWrapper::TMinSizeComponent>(eid)->pOwner = pUnit;
    entMng->ViewComponent<nsGuiWrapper::TMaxSizeComponent>(eid)->pOwner = pUnit;
    entMng->ViewComponent<nsGuiWrapper::TVerticalAlignComponent>(eid)->pOwner = pUnit;
    entMng->ViewComponent<nsGuiWrapper::THorizontalAlignComponent>(eid)->pOwner = pUnit;
    entMng->ViewComponent<nsGuiWrapper::TMinDistanceToParentComponent>(eid)->pOwner = pUnit;
    entMng->ViewComponent<nsGuiWrapper::TFocusComponent>(eid)->pOwner = pUnit;
}
