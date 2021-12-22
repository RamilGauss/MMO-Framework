/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "MenuNodeTerminatorSystem.h"

#include "GuidComponent.h"
#include "ParentGuidComponent.h"
#include "FrameComponent.h"
#include "WindowComponent.h"
#include "FrameComponent.h"
#include "DialogComponent.h"
#include "UnitBuilderHelper.h"

#include <ImGuiWidgets/include/MenuNode.h>

using namespace nsGraphicWrapper;

void TMenuNodeTerminatorSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TMenuNodeComponent* pMenuNodeComponent)
{
    TUnitBuilderHelper::UnlinkMenuNode(GetEntMng(), eid, pMenuNodeComponent->value);

    delete pMenuNodeComponent->value;
    pMenuNodeComponent->value = nullptr;
}
