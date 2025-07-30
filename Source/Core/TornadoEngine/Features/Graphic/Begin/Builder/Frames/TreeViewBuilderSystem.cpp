/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ImGuiWidgets/Include/TreeView.h"

#include "TornadoEngine/Features/Graphic/Begin/Builder/Helpers/UnitBuilderHelper.h"

#include "TornadoEngine/Components/Gui/Properties/TitleComponent.h"

#include "TornadoEngine/Components/Meta/PrefabOriginalGuidComponent.h"
#include "TornadoEngine/Components/Meta/SceneOriginalGuidComponent.h"

#include "TornadoEngine/Modules/Common/Modules.h"
#include "TornadoEngine/Modules/Resources/Common/HandlerCallCollector.h"

#include "TornadoEngine/Features/Graphic/Begin/Builder/Frames/TreeViewBuilderSystem.h"
#include "TornadoEngine/Features/Graphic/Begin/Builder/Helpers/HandlerLinkHelper.h"

using namespace nsGraphicWrapper;
using namespace nsGuiWrapper;

// Prefab or scene
void TTreeViewBuilderSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TTreeViewComponent* pTreeViewComponent)
{
    auto entMng = GetEntMng();

    TUnitBuilderHelper::SetupTreeView(entMng, eid, pTreeViewComponent->value);

    THandlerLinkHelper::RegisterMouseKey(entMng, eid, pTreeViewComponent);
}
