/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TreeViewBuilderSystem.h"

#include <ImGuiWidgets/include/TreeView.h>

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
void TTreeViewBuilderSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TTreeViewComponent* pTreeViewComponent)
{
    auto entMng = GetEntMng();

    TUnitBuilderHelper::SetupTreeView(entMng, eid, pTreeViewComponent->value);

    THandlerLinkHelper::RegisterMouseKey(entMng, eid, pTreeViewComponent);
}
