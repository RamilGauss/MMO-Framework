/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ImGuiWidgets/Include/TreeView.h"

#include "TornadoEngine/Modules/Common/Modules.h"
#include "TornadoEngine/Modules/PropertyManager/PropertyManager.h"

#include "TornadoEngine/Features/Graphic/Begin/Maker/Frames/TreeViewMakerSystem.h"

using namespace nsGraphicWrapper;

void TTreeViewMakerSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TTreeViewComponent* pTreeViewComponent)
{
    auto pTreeView = new nsImGuiWidgets::TTreeView();
    pTreeViewComponent->value = pTreeView;

    nsTornadoEngine::Modules()->PropertyMng()->SetupProperties(GetEntMng(), eid, pTreeView);
}
