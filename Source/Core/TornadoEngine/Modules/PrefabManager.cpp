/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "PrefabManager.h"

#include "Modules.h"
#include <ECS/include/EntityManager.h>

#include "ProjectConfigContainer.h"
#include "TornadoEngineJsonSerializer.h"
#include "Logger.h"
#include "TimeSliceEngine.h"
#include "TextFile.h"


#include "PrefabRootComponent.h"
#include "PrefabOriginalGuidComponent.h"
#include "PrefabInstanceGuidComponent.h"

#include "NeedUnloadPrefabComponent.h"
#include "NeedDestroyPrefabComponent.h"

#include "SceneGuidComponent.h"
#include "SceneOriginalGuidComponent.h"
#include "SceneInstanceGuidComponent.h"
#include "SceneRootComponent.h"

using namespace nsTornadoEngine;

void TPrefabManager::LoadByAbsPath(const std::string& absPath)
{
    // Same as InstantiateByAbsPath, but without replasing guid
}
//--------------------------------------------------------------------------------
void TPrefabManager::LoadByGuid(const std::string& sceneGuid)
{
    // Convert to abs path
    // LoadByAbsPath()
}
//--------------------------------------------------------------------------------
void TPrefabManager::LoadByObjectInMemory(nsECSFramework::TEntityID eid)
{

}
//--------------------------------------------------------------------------------
void TPrefabManager::InstantiateByAbsPath(const std::string& absPath, const std::string& sceneInstanceGuid,
    const std::string& parentGuid)
{
    using namespace nsCommonWrapper;

    TResourceContent prefabContent;
    auto deserializeResult = Deserialize(prefabContent, absPath);
    if (!deserializeResult) {
        return;
    }

    // 2. Convert typeName to rtti
    std::list<nsECSFramework::TEntityID> newEntities;
    DeserializeObjects(newEntities, prefabContent);

    // 3. Search prefabInstance
    nsECSFramework::TEntityID rootEid = nsECSFramework::NONE;
    for (auto& entity : newEntities) {
        auto hasRoot = mEntityManager->HasComponent<TPrefabRootComponent>(entity);
        if (hasRoot) {
            rootEid = entity;
        }
    }

    std::string prefabInstanceGuid = TGuidGenerator::Generate();

    // 3. Replace all guids to new guid with ParentGuids and SceneGuids
    UpdateGuidsAndInstantiate<TPrefabOriginalGuidComponent, TPrefabInstanceGuidComponent>(newEntities, prefabInstanceGuid);

    nsECSFramework::TEntityID parentEid = nsECSFramework::NONE;
    if (parentGuid == TGuidConstants::NONE) {
        // Search ROOT of sceneInstanceGuid
        bool editingMode = false;
        auto sceneRootsEids = mEntityManager->GetByHasCopy<TSceneRootComponent>();
        for (auto& sceneRootsEid : sceneRootsEids) {
            auto sceneInstanceGuidComponent = mEntityManager->ViewComponent<TSceneInstanceGuidComponent>(sceneRootsEid);
            if (sceneInstanceGuidComponent != nullptr) {
                editingMode = true;
                if (sceneInstanceGuidComponent->value == sceneInstanceGuid) {
                    parentEid = sceneRootsEid;
                    break;
                }
            }
        }
        if (parentEid == nsECSFramework::NONE) {
            if (!editingMode) {
                BL_FIX_BUG();
                return;
            }
            parentEid = *(sceneRootsEids.begin());
        }
    } else {
        // 5. Find parent by guid
        nsCommonWrapper::TGuidComponent parentGuidComponent;
        parentGuidComponent.value = parentGuid;
        parentEid = mEntityManager->GetByUnique(parentGuidComponent);

        // ParentEid != NONE - editing mode
        if (parentEid == nsECSFramework::NONE) {

            nsCommonWrapper::TSceneOriginalGuidComponent parentSceneOriginalGuidComponent;
            parentSceneOriginalGuidComponent.value = parentGuid;

            auto parentEids = mEntityManager->GetByValueCopy(parentSceneOriginalGuidComponent);
            for (auto& sceneParentEid : parentEids) {

                auto sceneInstanceGuidComponent = mEntityManager->ViewComponent<TSceneInstanceGuidComponent>(sceneParentEid);
                if (sceneInstanceGuid != sceneInstanceGuidComponent->value) {
                    continue;
                }
                parentEid = sceneParentEid;
                break;
            }
        }
    }

    nsCommonWrapper::TParentGuidComponent newParentGuidComponent;
    newParentGuidComponent.value = mEntityManager->ViewComponent<TGuidComponent>(parentEid)->value;
    mEntityManager->SetComponent(rootEid, newParentGuidComponent);

    BL_ASSERT(parentEid != nsECSFramework::NONE);

    // 8. Add identification of the scene.
    auto parentSceneGuid = mEntityManager->ViewComponent<nsCommonWrapper::TSceneGuidComponent>(parentEid);
    auto parentSceneInstanceGuid = mEntityManager->ViewComponent<nsCommonWrapper::TSceneInstanceGuidComponent>(parentEid);

    for (auto& eid : newEntities) {
        mEntityManager->SetComponent(eid, *parentSceneGuid);
        if (parentSceneInstanceGuid != nullptr) {
            // Scene has been instanced before
            auto prefabOriginalGuid = mEntityManager->ViewComponent<nsCommonWrapper::TPrefabOriginalGuidComponent>(eid);

            nsCommonWrapper::TSceneOriginalGuidComponent sceneOriginalGuid;
            sceneOriginalGuid.value = prefabOriginalGuid->value;
            mEntityManager->SetComponent(eid, sceneOriginalGuid);
            mEntityManager->SetComponent(eid, *parentSceneInstanceGuid);
        }
    }
}
//--------------------------------------------------------------------------------
void TPrefabManager::InstantiateByGuid(const std::string& prefabGuid, const std::string& sceneInstanceGuid,
    const std::string& parentGuid)
{
    // Convert to abs path
    auto fit = mResourceContentMap.guidPathMap.find(prefabGuid);
    if (fit == mResourceContentMap.guidPathMap.end()) {
        GetLogger()->Get(TTimeSliceEngine::NAME)->WriteF_time("Guid \"%s\" not exist", prefabGuid.c_str());
        return;
    }

    InstantiateByAbsPath(fit->second, sceneInstanceGuid, parentGuid);
}
//--------------------------------------------------------------------------------
void TPrefabManager::Unload(const std::string& prefabGuid)
{
    // Add tag component for new entity
    auto eid = mEntityManager->CreateEntity();

    nsCommonWrapper::TNeedUnloadPrefabComponent needUnloadPrefabComponent;
    needUnloadPrefabComponent.prefabGuid = prefabGuid;
    mEntityManager->SetComponent(eid, needUnloadPrefabComponent);
}
//--------------------------------------------------------------------------------
void TPrefabManager::Save(const std::string& sceneGuid)
{
    // Search all entities with sceneGuid and serialize to file
    // Check on existing in sceneManagerMap
}
//--------------------------------------------------------------------------------
void TPrefabManager::Destroy(const std::string& prefabInstanceGuid)
{
    // Add tag component for new entity
    auto eid = mEntityManager->CreateEntity();

    nsCommonWrapper::TNeedDestroyPrefabComponent needDestroyPrefabComponent;
    needDestroyPrefabComponent.prefabInstanceGuid = prefabInstanceGuid;
    mEntityManager->SetComponent(eid, needDestroyPrefabComponent);
}
//--------------------------------------------------------------------------------
void TPrefabManager::Destroy(nsECSFramework::TEntityID anyEidInScene)
{
    // Find out
    auto pSceneInstanceGuid = mEntityManager->ViewComponent<nsCommonWrapper::TPrefabInstanceGuidComponent>(anyEidInScene);
    if (pSceneInstanceGuid == nullptr) {
        return;
    }
    Destroy(pSceneInstanceGuid->value);
}
//--------------------------------------------------------------------------------
void TPrefabManager::InstanceByObjectInMemory(nsECSFramework::TEntityID eid,
    const std::string& sceneInstanceGuid, const std::string& parentGuid)
{

}
//--------------------------------------------------------------------------------
