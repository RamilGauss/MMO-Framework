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
#include "GameObject.h"


#include "PrefabRootComponent.h"
#include "PrefabOriginalGuidComponent.h"
#include "PrefabInstanceGuidComponent.h"
#include "PrefabGuidComponent.h"

#include "NeedDestroyObjectTagComponent.h"

#include "SceneGuidComponent.h"
#include "SceneOriginalGuidComponent.h"
#include "SceneInstanceGuidComponent.h"
#include "SceneRootComponent.h"
#include "PrefabObjectConstructor.h"

#include "ProjectionToUniverseComponent.h"
#include "UniverseGuidComponent.h"
#include "UniverseIndexComponent.h"

using namespace nsTornadoEngine;

void TPrefabManager::InstantiateByAbsPath(const std::string& absPath, const std::string& sceneInstanceGuid,
    const std::string& parentGuid)
{
    TResourceContent prefabContent;
    auto deserializeResult = Deserialize(prefabContent, absPath);
    if (!deserializeResult) {
        return;
    }

    // Convert typeName to rtti
    std::list<nsECSFramework::TEntityID> newEntities;
    DeserializeObjects(newEntities, prefabContent);

    SetupUniverse(newEntities, sceneInstanceGuid, parentGuid);
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
void TPrefabManager::Save(const std::string& sceneGuid)
{
    // Search all entities with sceneGuid and serialize to file
    // Check on existing in sceneManagerMap
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
void TPrefabManager::Destroy(const std::string& prefabInstanceGuid)
{
    nsCommonWrapper::TPrefabInstanceGuidComponent prefabInstanceGuidComponent;
    prefabInstanceGuidComponent.value = prefabInstanceGuid;
    auto prefabInstanceGuidEids = mEntityManager->GetByValueCopy(prefabInstanceGuidComponent);
    nsECSFramework::TEntityID rootEid = nsECSFramework::NONE;
    for (auto& prefabInstanceGuidEid : prefabInstanceGuidEids) {
        if (mEntityManager->HasComponent<nsCommonWrapper::TPrefabRootComponent>(prefabInstanceGuidEid)) {
            rootEid = prefabInstanceGuidEid;
            break;
        }
    }

    BL_ASSERT(rootEid != nsECSFramework::NONE);

    TGameObject go(rootEid);
    nsECSFramework::TEntityList eids;
    go.GetAllTree(eids);

    nsCommonWrapper::TNeedDestroyObjectTagComponent needDestroyObjectTagComponent;
    for (auto& eid : eids) {
        mEntityManager->SetComponent(eid, needDestroyObjectTagComponent);
    }
}
//--------------------------------------------------------------------------------
void TPrefabManager::InstantiateByObjectInMemory(TPrefabObjectConstructor* prefabObjConstructor,
    nsECSFramework::TEntityID eid, const std::string& sceneInstanceGuid, const std::string& parentGuid)
{
    auto parentEid = prefabObjConstructor->GetParent(eid);
    if (parentEid != nsECSFramework::NONE) {
        return;
    }

    auto componentReflection = Project()->mScenePartAggregator->mComponents;
    componentReflection->mEntMng->SetEntityManager(mEntityManager);

    std::list<nsECSFramework::TEntityID> newEntities;

    CreateEntity(prefabObjConstructor, eid, newEntities);

    SetupUniverse(newEntities, sceneInstanceGuid, parentGuid);
}
//--------------------------------------------------------------------------------
void TPrefabManager::CreateEntity(TPrefabObjectConstructor* prefabObjConstructor, 
    nsECSFramework::TEntityID eid, std::list<nsECSFramework::TEntityID>& newEntities)
{
    auto componentReflection = Project()->mScenePartAggregator->mComponents;
    auto entMngExt = componentReflection->mEntMng;

    std::list<nsECSFramework::TypeIndexType> typeIdentifierList;
    prefabObjConstructor->EntMng()->GetComponentList(eid, typeIdentifierList);

    auto newEid = mEntityManager->CreateEntity();

    newEntities.push_back(newEid);

    for (auto& rtti : typeIdentifierList) {
        componentReflection->mEntMng->CreateComponent(newEid, rtti, 
            [this, eid, rtti, componentReflection, prefabObjConstructor](void* pComponent)
        {
            componentReflection->mEntMng->SetEntityManager(prefabObjConstructor->EntMng());
            auto pC = componentReflection->mEntMng->ViewComponent(eid, rtti);

            // To json
            std::string json;
            componentReflection->mJson->Serialize((void*)pC, json, rtti);
            // From json
            std::string err;
            componentReflection->mJson->Deserialize(pComponent, json, rtti, err);

            componentReflection->mEntMng->SetEntityManager(mEntityManager);
        });
    }

    auto childEids = prefabObjConstructor->GetChilds(eid);
    for (auto& childEid : childEids) {
        CreateEntity(prefabObjConstructor, childEid, newEntities);
    }
}
//--------------------------------------------------------------------------------
void TPrefabManager::InstantiateEntities(const std::list<nsECSFramework::TEntityID>& newEntities,
    const std::string& sceneInstanceGuid, const std::string& parentGuid)
{
    using namespace nsCommonWrapper;

    // Search prefabInstance
    nsECSFramework::TEntityID rootEid = nsECSFramework::NONE;
    for (auto& entity : newEntities) {
        auto hasRoot = mEntityManager->HasComponent<TPrefabRootComponent>(entity);
        if (hasRoot) {
            rootEid = entity;
        }
    }

    std::string prefabInstanceGuid = TGuidGenerator::Generate();

    // Replace all guids to new guid with ParentGuids and SceneGuids
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
        // Find parent by guid
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

    // Add identification of the scene.
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
void TPrefabManager::SetupUniverse(const std::list<nsECSFramework::TEntityID>& newEntities, 
    const std::string& sceneInstanceGuid, const std::string& parentGuid)
{
    InstantiateEntities(newEntities, sceneInstanceGuid, parentGuid);
    // Find scene root
    using namespace nsCommonWrapper;
    auto sceneRootEids = mEntityManager->GetByHasCopy<TSceneRootComponent>();

    nsECSFramework::TEntityID sceneRootEid = nsECSFramework::NONE;
    for (auto& eid : sceneRootEids) {
        auto rootSceneInstanceGuid = mEntityManager->ViewComponent<TSceneInstanceGuidComponent>(eid)->value;
        if (rootSceneInstanceGuid == sceneInstanceGuid) {
            sceneRootEid = eid;
            break;
        }
    }

    BL_ASSERT(sceneRootEid != nsECSFramework::NONE);

    auto universeGuidComponent = *(mEntityManager->ViewComponent<TUniverseGuidComponent>(sceneRootEid));
    auto universeIndexComponent = *(mEntityManager->ViewComponent<TUniverseIndexComponent>(sceneRootEid));

    for (auto& eid : newEntities) {
        auto projectionToUniverseComponent = mEntityManager->ViewComponent<TProjectionToUniverseComponent>(eid);
        if (projectionToUniverseComponent) {
            TUniverseGuidComponent fromUniverseGuidComponent;
            fromUniverseGuidComponent.value = projectionToUniverseComponent->guid;
            auto otherUniverseEid = mEntityManager->GetByValue(fromUniverseGuidComponent);

            mEntityManager->SetComponent(eid, fromUniverseGuidComponent);

            auto fromUniverseIndexComponent = *(mEntityManager->ViewComponent<TUniverseIndexComponent>(otherUniverseEid->front()));
            mEntityManager->SetComponent(eid, fromUniverseIndexComponent);
        } else {
            mEntityManager->SetComponent(eid, universeGuidComponent);
            mEntityManager->SetComponent(eid, universeIndexComponent);
        }
    }
}
//--------------------------------------------------------------------------------
