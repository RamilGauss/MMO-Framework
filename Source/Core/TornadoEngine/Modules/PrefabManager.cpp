/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "PrefabManager.h"

#include "Modules.h"
#include <ECS/include/EntityManager.h>

#include "TextFile.h"
#include "Logger.h"
#include "TimeSliceEngine.h"
#include "TornadoEngineJsonSerializer.h"
#include "ProjectConfigContainer.h"
#include "PrefabContent.h"
#include "GuidGenerator.h"

#include "GuidComponent.h"
#include "ParentGuidComponent.h"

#include "PrefabRootComponent.h"
#include "PrefabOriginalGuidComponent.h"
#include "PrefabInstanceGuidComponent.h"

#include "NeedUnloadPrefabComponent.h"
#include "NeedDestroyPrefabComponent.h"

#include "SceneGuidComponent.h"
#include "SceneOriginalGuidComponent.h"
#include "SceneInstanceGuidComponent.h"

using namespace nsTornadoEngine;

void TPrefabManager::SetContentMap(const TPrefabContentMap& prefabContentMap)
{
    mPrefabContentMap = prefabContentMap;
}
//--------------------------------------------------------------------------------
void TPrefabManager::SetEntityManager(nsECSFramework::TEntityManager* entMng)
{
    mEntityManager = entMng;
}
//--------------------------------------------------------------------------------
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
void TPrefabManager::InstantiateByAbsPath(const std::string& parentGuid, const std::string& absPath,
    const std::string& sceneInstanceGuid)
{
    auto logger = GetLogger()->Get(TTimeSliceEngine::NAME);

    std::string json;
    TTextFile::Load(absPath, json);

    // 1. Deserialize to object
    TPrefabContent prefabContent;
    std::string err;
    auto deserResult = TTornadoEngineJsonSerializer::Deserialize(&prefabContent, json, err);
    if (deserResult == false) {
        logger->WriteF_time("Deserialize error %s with %s", err.c_str(), absPath.c_str());
        return;
    }

    std::string prefabIstanceGuid;
    nsECSFramework::TEntityID rootEid = nsECSFramework::NONE;

    auto componentReflection = Project()->mScenePartAggregator->mComponents;
    componentReflection->mEntMng->SetEntityManager(Modules()->EntMng());

    std::list<nsECSFramework::TEntityID> newEntities;
    // 2. Convert typeName to rtti
    for (auto& entity : prefabContent.entities) {
        // 3. Add entity
        auto eid = mEntityManager->CreateEntity();
        newEntities.push_back(eid);

        for (auto& component : entity.components) {
            // 4. Add component by rtti
            int rtti;
            auto convertResult = componentReflection->mTypeInfo->ConvertNameToType(component.typeName, rtti);
            if (convertResult == false) {
                logger->WriteF_time("Not converted typename \"%s\"", component.typeName);
                continue;
            }
            componentReflection->mEntMng->CreateComponent(eid, rtti, [&](void* pComponent)
            {
                // 5. Deserialize component by rtti and json body
                auto componentDeserialzieResult =
                    componentReflection->mJson->Deserialize(pComponent, component.jsonBody, rtti, err);

                if (!componentDeserialzieResult) {
                    logger->WriteF_time("Not converted typename \"%s\"", component.typeName);
                }
            });

            auto hasRoot = mEntityManager->HasComponent<nsCommonWrapper::TPrefabRootComponent>(eid);
            if (hasRoot) {
                prefabIstanceGuid = mEntityManager->ViewComponent<nsCommonWrapper::TGuidComponent>(eid)->value;
                rootEid = eid;
            }
        }
    }

    BL_ASSERT(!prefabIstanceGuid.empty());

    // 6. Replace all guids to new guid with ParentGuids and SceneGuids
    for (auto& eid : newEntities) {
        auto pGuidComponent = mEntityManager->ViewComponent<nsCommonWrapper::TGuidComponent>(eid);
        if (pGuidComponent == nullptr) {
            continue;
        }
        auto guidComponent = *pGuidComponent;

        auto newGuid = TGuidGenerator::Generate();

        nsCommonWrapper::TParentGuidComponent parentGuid;
        parentGuid.value = guidComponent.value;
        auto copyChildEids = mEntityManager->GetByValueCopy<nsCommonWrapper::TParentGuidComponent>(parentGuid);
        for (auto& childEid : copyChildEids) {
            parentGuid.value = newGuid;
            mEntityManager->SetComponent(childEid, parentGuid);
        }

        nsCommonWrapper::TPrefabOriginalGuidComponent prefabOriginalGuid;
        prefabOriginalGuid.value = guidComponent.value;
        mEntityManager->SetComponent(eid, prefabOriginalGuid);

        guidComponent.value = newGuid;
        mEntityManager->SetComponent(eid, guidComponent);

        nsCommonWrapper::TPrefabInstanceGuidComponent prefabInstanceGuidComponent;
        prefabInstanceGuidComponent.value = prefabIstanceGuid;
        mEntityManager->SetComponent(eid, prefabInstanceGuidComponent);
    }

    // 7. Find parent by guid
    std::string realParentGuid = parentGuid;

    nsCommonWrapper::TGuidComponent parentGuidComponent;
    parentGuidComponent.value = parentGuid;
    auto parentEid = mEntityManager->GetByUnique(parentGuidComponent);
    if (parentEid == nsECSFramework::NONE) {

        nsCommonWrapper::TSceneOriginalGuidComponent parentSceneOriginalGuidComponent;
        parentSceneOriginalGuidComponent.value = parentGuid;
        
        auto parentEids = mEntityManager->GetByValueCopy(parentSceneOriginalGuidComponent);
        for (auto& sceneParentEid : parentEids) {

            auto sceneInstanceGuidComponent = mEntityManager->ViewComponent<nsCommonWrapper::TSceneInstanceGuidComponent>(sceneParentEid);
            if (sceneInstanceGuid != sceneInstanceGuidComponent->value) {
                continue;
            }
            realParentGuid = mEntityManager->ViewComponent<nsCommonWrapper::TGuidComponent>(sceneParentEid)->value;
            parentEid = sceneParentEid;
            break;
        }
    }

    nsCommonWrapper::TParentGuidComponent newParentGuidComponent;
    newParentGuidComponent.value = realParentGuid;
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
void TPrefabManager::InstantiateByGuid(const std::string& parentGuid, const std::string& prefabGuid, 
    const std::string& sceneInstanceGuid)
{
    // Convert to abs path
    auto fit = mPrefabContentMap.guidPathMap.find(prefabGuid);
    if (fit == mPrefabContentMap.guidPathMap.end()) {
        GetLogger()->Get(TTimeSliceEngine::NAME)->WriteF_time("Guid \"%s\" not exist", prefabGuid.c_str());
        return;
    }

    InstantiateByAbsPath(parentGuid, fit->second, sceneInstanceGuid);
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
void TPrefabManager::InstanceByObjectInMemory(const std::string& parentGuid, nsECSFramework::TEntityID eid,
    const std::string& sceneInstanceGuid)
{

}
//--------------------------------------------------------------------------------
