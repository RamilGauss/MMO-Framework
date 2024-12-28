/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "OnOpenProjectClickHandler.h"

#include "Modules/Common/Modules.h"
#include "StopAccessor.h"
#include "Modules/Resources/Prefab/PrefabManager.h"

#include "Components/Meta/SceneInstanceGuidComponent.h"

#include "SceneObjectReferenceComponent.h"
#include "PrefabReferenceComponent.h"

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
