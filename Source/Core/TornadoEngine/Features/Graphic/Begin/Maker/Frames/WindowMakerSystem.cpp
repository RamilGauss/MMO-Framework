/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "WindowMakerSystem.h"

#include <ImGuiWidgets/include/Window.h>

#include "TimeSliceEngine/ProjectConfigContainer.h"

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

#include <Modules/Common/Modules.h>
#include <Modules/PropertyManager/PropertyManager.h>

using namespace nsGraphicWrapper;

void TWindowMakerSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TWindowComponent* pWindowComponent)
{
    auto pWindow = new nsImGuiWidgets::TWindow();
    pWindowComponent->value = pWindow;

    nsTornadoEngine::Modules()->PropertyMng()->SetupProperties(GetEntMng(), eid, pWindow);
}
