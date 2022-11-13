/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "DialogMakerSystem.h"

#include <ImGuiWidgets/include/Dialog.h>

#include "SizeComponent.h"
#include "PositionComponent.h"

#include "VisibilityComponent.h"
#include "TitleComponent.h"

#include "AnchorsComponent.h"
#include "MinSizeComponent.h"
#include "MaxSizeComponent.h"
#include "VerticalAlignComponent.h"
#include "HorizontalAlignComponent.h"
#include "MinDistanceToParentComponent.h"
#include "FocusComponent.h"

#include "PaddingComponent.h"
#include "GridComponent.h"
#include "SpacingComponent.h"

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
