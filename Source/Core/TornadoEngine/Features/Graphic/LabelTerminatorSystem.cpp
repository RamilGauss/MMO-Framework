/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "LabelTerminatorSystem.h"

#include "GuidComponent.h"
#include "ParentGuidComponent.h"
#include "FrameComponent.h"
#include "WindowComponent.h"
#include "FrameComponent.h"
#include "DialogComponent.h"
#include "UnitBuilderHelper.h"

#include <ImGuiWidgets/include/Label.h>

using namespace nsGraphicWrapper;

void TLabelTerminatorSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TLabelComponent* pLabelComponent)
{
    TUnitBuilderHelper::UnlinkParent(GetEntMng(), eid, pLabelComponent->value);

    delete pLabelComponent->value;
    pLabelComponent->value = nullptr;
}
