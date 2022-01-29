/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "SceneManager.h"

#include "Modules.h"
#include <ECS/include/EntityManager.h>

#include "TextFile.h"
#include "Logger.h"
#include "TimeSliceEngine.h"
#include "TornadoEngineJsonSerializer.h"
#include "ProjectConfigContainer.h"

#include "GuidComponent.h"
#include "ParentGuidComponent.h"
#include "SceneOriginalGuidComponent.h"
#include "SceneInstanceGuidComponent.h"
#include "NeedDestroyObjectTagComponent.h"
#include "SceneRootComponent.h"
#include "SceneGuidComponent.h"

#include "GuidGenerator.h"

using namespace nsTornadoEngine;

void TSceneManager::LoadByAbsPath(const std::string& absPath)
{
    using namespace nsCommonWrapper;

    // 1. Deserialize to object
    TResourceContent sceneContent;
    auto deserializeResult = Deserialize(sceneContent, absPath);
    if (!deserializeResult) {
        return;
    }

    auto componentReflection = Project()->mScenePartAggregator->mComponents;
    componentReflection->mEntMng->SetEntityManager(Modules()->EntMng());

    std::list<nsECSFramework::TEntityID> newEntities;

    // 2. Convert typeName to rtti
    DeserializeObjects(newEntities, sceneContent);
}
//--------------------------------------------------------------------------------
void TSceneManager::LoadByGuid(const std::string& sceneGuid)
{
    // Convert to abs path
    auto fit = mResourceContentMap.guidPathMap.find(sceneGuid);
    if (fit == mResourceContentMap.guidPathMap.end()) {
        GetLogger()->Get(TTimeSliceEngine::NAME)->WriteF_time("Guid \"%s\" not exist", sceneGuid.c_str());
        return;
    }

    LoadByAbsPath(fit->second);
}
//--------------------------------------------------------------------------------
void TSceneManager::InstantiateByAbsPath(const std::string& absPath, const std::string& universeGuid)
{
    using namespace nsCommonWrapper;

    // 1. Deserialize to object
    TResourceContent sceneContent;
    auto deserializeResult = Deserialize(sceneContent, absPath);
    if (!deserializeResult) {
        return;
    }

    auto componentReflection = Project()->mScenePartAggregator->mComponents;
    componentReflection->mEntMng->SetEntityManager(Modules()->EntMng());

    std::list<nsECSFramework::TEntityID> newEntities;

    // 2. Convert typeName to rtti
    DeserializeObjects(newEntities, sceneContent);

    std::string sceneIstanceGuid = TGuidGenerator::Generate();

    // 3. Replace all guids to new guid with ParentGuids and SceneGuids
    UpdateGuidsAndInstantiate<TSceneOriginalGuidComponent, TSceneInstanceGuidComponent>(newEntities, sceneIstanceGuid);
}
//--------------------------------------------------------------------------------
void TSceneManager::InstantiateByGuid(const std::string& sceneGuid, const std::string& universeGuid)
{
    // Convert to abs path
    auto fit = mResourceContentMap.guidPathMap.find(sceneGuid);
    if (fit == mResourceContentMap.guidPathMap.end()) {
        GetLogger()->Get(TTimeSliceEngine::NAME)->WriteF_time("Guid \"%s\" not exist", sceneGuid.c_str());
        return;
    }

    InstantiateByAbsPath(fit->second, universeGuid);
}
//--------------------------------------------------------------------------------
void TSceneManager::Unload(const std::string& sceneGuid)
{
    nsCommonWrapper::TSceneGuidComponent sceneGuidComponent;
    sceneGuidComponent.value = sceneGuid;
    auto eids = mEntityManager->GetByValueCopy(sceneGuidComponent);

    // Add tag component for all entities
    nsCommonWrapper::TNeedDestroyObjectTagComponent needDestroySceneComponent;
    for (auto& eid : eids) {
        mEntityManager->SetComponent(eid, needDestroySceneComponent);
    }
}
//--------------------------------------------------------------------------------
void TSceneManager::Save(const std::string& sceneGuid)
{
    // Search all entities with sceneGuid and serialize to file
    // Check on existing in sceneManagerMap
}
//--------------------------------------------------------------------------------
void TSceneManager::Destroy(const std::string& sceneInstanceGuid)
{
    nsCommonWrapper::TSceneInstanceGuidComponent sceneInstanceGuidComponent;
    sceneInstanceGuidComponent.value = sceneInstanceGuid;
    auto eids = mEntityManager->GetByValueCopy(sceneInstanceGuidComponent);

    // Add tag component for all entities
    nsCommonWrapper::TNeedDestroyObjectTagComponent needDestroySceneComponent;
    for (auto& eid : eids) {
        mEntityManager->SetComponent(eid, needDestroySceneComponent);
    }
}
//--------------------------------------------------------------------------------
void TSceneManager::Destroy(nsECSFramework::TEntityID anyEidInScene)
{
    // Find out
    auto pSceneInstanceGuid = mEntityManager->ViewComponent<nsCommonWrapper::TSceneInstanceGuidComponent>(anyEidInScene);
    if (pSceneInstanceGuid == nullptr) {
        return;
    }
    Destroy(pSceneInstanceGuid->value);
}
//--------------------------------------------------------------------------------
