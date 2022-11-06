/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "WindowMakerSystem.h"

#include <ImGuiWidgets/include/Window.h>

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

void TWindowMakerSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TWindowComponent* pWindowComponent)
{
    auto pWindow = new nsImGuiWidgets::TWindow();
    pWindowComponent->value = pWindow;

    auto entMng = GetEntMng();

    auto pWidget = dynamic_cast<nsImGuiWidgets::TWidget*>(pWindow);

    entMng->ViewComponent<nsGuiWrapper::TTitleComponent>(eid)->pOwner = pWidget;
    entMng->ViewComponent<nsGuiWrapper::TVisibilityComponent>(eid)->pOwner = pWidget;
    entMng->ViewComponent<nsGuiWrapper::TSizeComponent>(eid)->pOwner = pWidget;
    entMng->ViewComponent<nsGuiWrapper::TPositionComponent>(eid)->pOwner = pWidget;

    auto pUnit = dynamic_cast<nsImGuiWidgets::TUnit*>(pWindow);

    entMng->ViewComponent<nsGuiWrapper::TAnchorsComponent>(eid)->pOwner = pUnit;
    entMng->ViewComponent<nsGuiWrapper::TMinSizeComponent>(eid)->pOwner = pUnit;
    entMng->ViewComponent<nsGuiWrapper::TMaxSizeComponent>(eid)->pOwner = pUnit;
    entMng->ViewComponent<nsGuiWrapper::TVerticalAlignComponent>(eid)->pOwner = pUnit;
    entMng->ViewComponent<nsGuiWrapper::THorizontalAlignComponent>(eid)->pOwner = pUnit;
    entMng->ViewComponent<nsGuiWrapper::TMinDistanceToParentComponent>(eid)->pOwner = pUnit;
    entMng->ViewComponent<nsGuiWrapper::TFocusComponent>(eid)->pOwner = pUnit;

    auto pFrame = dynamic_cast<nsImGuiWidgets::TFrame*>(pWindow);

    entMng->ViewComponent<nsGuiWrapper::TPaddingComponent>(eid)->pOwner = pFrame;
    entMng->ViewComponent<nsGuiWrapper::TGridComponent>(eid)->pOwner = pFrame;
    entMng->ViewComponent<nsGuiWrapper::TSpacingComponent>(eid)->pOwner = pFrame;
}
