/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ButtonMakerSystem.h"

#include <ImGuiWidgets/include/Button.h>

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

using namespace nsGraphicWrapper;

void TButtonMakerSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TButtonComponent* pButtonComponent)
{
    auto pButton = new nsImGuiWidgets::TButton();
    pButtonComponent->value = pButton;

    auto entMng = GetEntMng();

    entMng->ViewComponent<nsGuiWrapper::TTitleComponent>(eid)->pOwner = pButton;
    entMng->ViewComponent<nsGuiWrapper::TVisibilityComponent>(eid)->pOwner = pButton;
    entMng->ViewComponent<nsGuiWrapper::TSizeComponent>(eid)->pOwner = pButton;
    entMng->ViewComponent<nsGuiWrapper::TPositionComponent>(eid)->pOwner = pButton;

    entMng->ViewComponent<nsGuiWrapper::TAnchorsComponent>(eid)->pOwner = pButton;
    entMng->ViewComponent<nsGuiWrapper::TMinSizeComponent>(eid)->pOwner = pButton;
    entMng->ViewComponent<nsGuiWrapper::TMaxSizeComponent>(eid)->pOwner = pButton;
    entMng->ViewComponent<nsGuiWrapper::TVerticalAlignComponent>(eid)->pOwner = pButton;
    entMng->ViewComponent<nsGuiWrapper::THorizontalAlignComponent>(eid)->pOwner = pButton;
    entMng->ViewComponent<nsGuiWrapper::TMinDistanceToParentComponent>(eid)->pOwner = pButton;
    entMng->ViewComponent<nsGuiWrapper::TFocusComponent>(eid)->pOwner = pButton;
}
