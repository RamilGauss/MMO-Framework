/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TreeViewMakerSystem.h"

#include <ImGuiWidgets/include/TreeView.h>

#include <Modules/Common/Modules.h>
#include <Modules/PropertyManager/PropertyManager.h>

using namespace nsGraphicWrapper;

void TTreeViewMakerSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TTreeViewComponent* pTreeViewComponent)
{
    auto pTreeView = new nsImGuiWidgets::TTreeView();
    pTreeViewComponent->value = pTreeView;

    nsTornadoEngine::Modules()->PropertyMng()->SetupProperties(GetEntMng(), eid, pTreeView);
}
