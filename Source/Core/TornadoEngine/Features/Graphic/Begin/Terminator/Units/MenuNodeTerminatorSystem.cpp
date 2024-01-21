/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "MenuNodeTerminatorSystem.h"

#include "Components/Meta/GuidComponent.h"
#include "Components/Meta/ParentGuidComponent.h"
#include "Components/Gui/Widgets/FrameComponent.h"
#include "Components/Gui/Widgets/WindowComponent.h"
#include "Components/Gui/Widgets/FrameComponent.h"
#include "Components/Gui/Widgets/DialogComponent.h"
#include "Features/Graphic/Begin/Builder/Helpers/UnitBuilderHelper.h"

#include <ImGuiWidgets/include/MenuNode.h>

using namespace nsGraphicWrapper;

void TMenuNodeTerminatorSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TMenuNodeComponent* pMenuNodeComponent)
{
    TUnitBuilderHelper::UnlinkMenuNode(GetEntMng(), eid, pMenuNodeComponent->value);

    delete pMenuNodeComponent->value;
    pMenuNodeComponent->value = nullptr;
}
