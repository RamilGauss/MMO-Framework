/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ButtonTerminatorSystem.h"

#include "Components/Meta/GuidComponent.h"
#include "Components/Meta/ParentGuidComponent.h"
#include "Components/Gui/Widgets/FrameComponent.h"
#include "Components/Gui/Widgets/WindowComponent.h"
#include "Components/Gui/Widgets/FrameComponent.h"
#include "Components/Gui/Widgets/DialogComponent.h"
#include "Features/Graphic/Begin/Builder/Helpers/UnitBuilderHelper.h"

#include "ImGuiWidgets/Include/Button.h"

using namespace nsGraphicWrapper;

void TButtonTerminatorSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TButtonComponent* pButtonComponent)
{
    TUnitBuilderHelper::UnlinkParent(GetEntMng(), eid, pButtonComponent->value);

    delete pButtonComponent->value;
    pButtonComponent->value = nullptr;
}
