/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "LabelBuilderSystem.h"

#include "ImGuiWidgets/Include/Label.h"

#include "Components/Gui/Properties/TitleComponent.h"

#include "Components/Meta/PrefabOriginalGuidComponent.h"
#include "Components/Meta/SceneOriginalGuidComponent.h"

#include "Modules/Common/Modules.h"
#include "Modules/Resources/Common/HandlerCallCollector.h"

#include "Features/Graphic/Begin/Builder/Helpers/HandlerLinkHelper.h"
#include "Features/Graphic/Begin/Builder/Helpers/UnitBuilderHelper.h"


using namespace nsGraphicWrapper;
using namespace nsGuiWrapper;

// Prefab or scene
void TLabelBuilderSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TLabelComponent* pLabelComponent)
{
    auto entMng = GetEntMng();

    TUnitBuilderHelper::SetupLabel(entMng, eid, pLabelComponent->value);
}
