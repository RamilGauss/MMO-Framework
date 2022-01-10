/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ObjectHierarchyWindowRefreshSystem.h"

#include "Modules.h"
#include "HierarchyHelper.h"
#include <filesystem>
#include "Modules.h"
#include "StopAccessor.h"
#include "PrefabManager.h"
#include "PrefabObjectConstructor.h"

#include "GuidComponent.h"
#include "InputTextValueComponent.h"
#include "TitleComponent.h"
#include "SceneInstanceGuidComponent.h"
#include <ECS/include/Helper.h>
#include "AbsoluteFilePathComponent.h"
#include "EditorInfoTagComponent.h"
#include "FilePathNodeComponent.h"
#include "NodeIconComponent.h"

#include <iostream>

namespace fs = std::filesystem;

using namespace nsTornadoEditor;

void TObjectHierarchyWindowRefreshSystem::Reactive(nsECSFramework::TEntityID eid, const TObjectHierarchyWindowRefreshTagComponent* pC)
{
    auto entMng = GetEntMng();

    entMng->RemoveComponent<TObjectHierarchyWindowRefreshTagComponent>(eid);

    auto treeViewEid = nsTornadoEngine::Modules()->HierarchyHelper()->GetChildByName(eid, "TreeView");

    //Handle(treeViewEid);
}
//--------------------------------------------------------------------------------------------
