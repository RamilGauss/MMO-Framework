/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ObjectHierarchyWindowRefreshSystem.h"

#include "Modules/Common/Modules.h"
#include "Modules/Resources/Common/GameObject.h"
#include <filesystem>
#include "Modules/Common/Modules.h"
#include "StopAccessor.h"
#include "Modules/Resources/Prefab/PrefabManager.h"

#include "Components/Meta/GuidComponent.h"
#include "InputTextValueComponent.h"
#include "Components/Gui/Properties/TitleComponent.h"
#include "Components/Meta/SceneInstanceGuidComponent.h"
#include <ECS/include/Helper.h>
#include "AbsoluteFilePathComponent.h"
#include "EditorInfoTagComponent.h"
#include "FilePathNodeComponent.h"
#include "Components/Gui/Properties/NodeIconComponent.h"

#include <iostream>

namespace fs = std::filesystem;

using namespace nsTornadoEditor;

void TObjectHierarchyWindowRefreshSystem::Reactive(nsECSFramework::TEntityID eid, const TObjectHierarchyWindowRefreshTagComponent* pC)
{
    auto entMng = GetEntMng();

    entMng->RemoveComponent<TObjectHierarchyWindowRefreshTagComponent>(eid);


    nsTornadoEngine::TGameObject go(eid);
    auto treeViewEid = go.GetChildByName("TreeView").GetEid();

    //Handle(treeViewEid);
}
//--------------------------------------------------------------------------------------------
