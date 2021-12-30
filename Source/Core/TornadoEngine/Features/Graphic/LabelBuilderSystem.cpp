/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "LabelBuilderSystem.h"

#include <ImGuiWidgets/include/Label.h>

#include "UnitBuilderHelper.h"

#include "TitleComponent.h"

#include "PrefabOriginalGuidComponent.h"
#include "SceneOriginalGuidComponent.h"

#include "Modules.h"
#include "HandlerCallCollector.h"

#include "HandlerLinkHelper.h"

using namespace nsGraphicWrapper;
using namespace nsGuiWrapper;

// Prefab or scene
void TLabelBuilderSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TLabelComponent* pLabelComponent)
{
    auto entMng = GetEntMng();

    TUnitBuilderHelper::SetupLabel(entMng, eid, pLabelComponent->value);
}
