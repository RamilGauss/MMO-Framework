/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "DialogMakerSystem.h"

#include <ImGuiWidgets/include/Dialog.h>

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

#include "Components/Gui/Properties/PaddingComponent.h"
#include "Components/Gui/Properties/GridComponent.h"
#include "Components/Gui/Properties/SpacingComponent.h"

using namespace nsGraphicWrapper;

void TDialogMakerSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TDialogComponent* pDialogComponent)
{
    auto pDialog = new nsImGuiWidgets::TDialog();
    pDialogComponent->value = pDialog;

    auto entMng = GetEntMng();

    entMng->ViewComponent<nsGuiWrapper::TTitleComponent>(eid)->SetOwner(pDialog);
    entMng->ViewComponent<nsGuiWrapper::TVisibilityComponent>(eid)->SetOwner(pDialog);
    entMng->ViewComponent<nsGuiWrapper::TSizeComponent>(eid)->SetOwner(pDialog);
    entMng->ViewComponent<nsGuiWrapper::TPositionComponent>(eid)->SetOwner(pDialog);

    entMng->ViewComponent<nsGuiWrapper::TAnchorsComponent>(eid)->SetOwner(pDialog);
    entMng->ViewComponent<nsGuiWrapper::TMinSizeComponent>(eid)->SetOwner(pDialog);
    entMng->ViewComponent<nsGuiWrapper::TMaxSizeComponent>(eid)->SetOwner(pDialog);
    entMng->ViewComponent<nsGuiWrapper::TVerticalAlignComponent>(eid)->SetOwner(pDialog);
    entMng->ViewComponent<nsGuiWrapper::THorizontalAlignComponent>(eid)->SetOwner(pDialog);
    entMng->ViewComponent<nsGuiWrapper::TMinDistanceToParentComponent>(eid)->SetOwner(pDialog);
    entMng->ViewComponent<nsGuiWrapper::TFocusComponent>(eid)->SetOwner(pDialog);

    entMng->ViewComponent<nsGuiWrapper::TPaddingComponent>(eid)->SetOwner(pDialog);
    entMng->ViewComponent<nsGuiWrapper::TGridComponent>(eid)->SetOwner(pDialog);
    entMng->ViewComponent<nsGuiWrapper::TSpacingComponent>(eid)->SetOwner(pDialog);

    entMng->ViewComponent<nsGuiWrapper::TGridComponent>(eid)->SetOwner(pDialog);
}
