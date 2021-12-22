/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ButtonTerminatorSystem.h"

#include "GuidComponent.h"
#include "ParentGuidComponent.h"
#include "FrameComponent.h"
#include "WindowComponent.h"
#include "FrameComponent.h"
#include "DialogComponent.h"
#include "UnitBuilderHelper.h"

#include <ImGuiWidgets/include/Button.h>

using namespace nsGraphicWrapper;

void TButtonTerminatorSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TButtonComponent* pButtonComponent)
{
    TUnitBuilderHelper::UnlinkParent(GetEntMng(), eid, pButtonComponent->value);

    delete pButtonComponent->value;
    pButtonComponent->value = nullptr;
}
