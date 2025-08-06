/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <iostream>
#include <filesystem>

#include "ECS/Include/Helper.h"

#include "TornadoEngine/Modules/Common/Modules.h"
#include "TornadoEngine/Modules/Resources/Common/GameObject.h"
#include "TornadoEngine/Modules/Common/Modules.h"
#include "TornadoEngine/Modules/Resources/Prefab/PrefabManager.h"
#include "TornadoEngine/TimeSliceEngine/StopAccessor.h"

#include "TornadoEngine/Components/Gui/Properties/NodeIconComponent.h"
#include "TornadoEngine/Components/Meta/GuidComponent.h"
#include "TornadoEngine/Components/Gui/Properties/TitleComponent.h"
#include "TornadoEngine/Components/Gui/Properties/InputTextValueComponent.h"
#include "TornadoEngine/Components/Meta/SceneInstanceGuidComponent.h"

#include "TornadoEditor/Sources/Components/AbsoluteFilePathComponent.h"
#include "TornadoEditor/Sources/Components/EditorInfoTagComponent.h"
#include "TornadoEditor/Sources/Components/FilePathNodeComponent.h"

#include "TornadoEditor/Sources/Features/ObjectHierarchyWindowRefreshSystem.h"

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
