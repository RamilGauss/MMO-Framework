/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "MainWindowMakerSystem.h"

#include <ImGuiWidgets/include/MainWindow.h>

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

void TMainWindowMakerSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TMainWindowComponent* pMainWindowComponent)
{
    auto pMainWindow = new nsImGuiWidgets::TMainWindow();
    pMainWindowComponent->value = pMainWindow;

    auto entMng = GetEntMng();

    auto pWidget = dynamic_cast<nsImGuiWidgets::TWidget*>(pMainWindow);

    entMng->ViewComponent<nsGuiWrapper::TTitleComponent>(eid)->pOwner = pWidget;
    entMng->ViewComponent<nsGuiWrapper::TVisibilityComponent>(eid)->pOwner = pWidget;

    auto pUnit = dynamic_cast<nsImGuiWidgets::TUnit*>(pMainWindow);

    entMng->ViewComponent<nsGuiWrapper::TFocusComponent>(eid)->pOwner = pUnit;
}
