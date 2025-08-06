/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TornadoEngine/Modules/Common/Modules.h"
#include "TornadoEngine/TimeSliceEngine/StopAccessor.h"
#include "TornadoEngine/Modules/Resources/Prefab/PrefabManager.h"

#include "TornadoEngine/Components/Meta/SceneInstanceGuidComponent.h"

#include "TornadoEngine/Components/Logic/SceneObjectReferenceComponent.h"
#include "TornadoEngine/Components/Logic/PrefabReferenceComponent.h"
#include "TornadoEditor/Sources/Handlers/OnOpenProjectClickHandler.h"

using namespace nsTornadoEditor;

void TOnOpenProjectClickHandler::Handle(nsECSFramework::TEntityID eid, const nsGuiWrapper::TMenuNodeComponent* pC)
{
    auto sceneMng = nsTornadoEngine::Modules()->SceneMng();
    auto prefabMng = nsTornadoEngine::Modules()->PrefabMng();
    auto stopAccessor = nsTornadoEngine::Modules()->StopAccessor();
    auto entMng = nsTornadoEngine::Modules()->EntMng();

    auto prefabRef = entMng->ViewComponent<nsLogicWrapper::TPrefabReferenceComponent>(eid);
    auto sceneInstanceGuid = entMng->ViewComponent<nsCommonWrapper::TSceneInstanceGuidComponent>(eid);

    nsTornadoEngine::TInstantiatePrefabParams instantiatePrefabParams;
    instantiatePrefabParams.guid = prefabRef->prefabGuid;
    instantiatePrefabParams.sceneInstanceGuid = sceneInstanceGuid->value;

    prefabMng->Instantiate(std::move(instantiatePrefabParams));
}
