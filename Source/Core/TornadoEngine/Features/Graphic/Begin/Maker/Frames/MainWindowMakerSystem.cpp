/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "MainWindowMakerSystem.h"

#include <ImGuiWidgets/include/MainWindow.h>

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
