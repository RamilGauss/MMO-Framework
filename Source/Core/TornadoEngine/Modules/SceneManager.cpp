/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

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
#include "NeedUnloadSceneComponent.h"
#include "NeedDestroySceneComponent.h"
#include "SceneRootComponent.h"

#include "GuidGenerator.h"

using namespace nsTornadoEngine;

void TSceneManager::SetContentMap(const TSceneContentMap& sceneContentMap)
{
    mSceneContentMap = sceneContentMap;
}
//--------------------------------------------------------------------------------
void TSceneManager::SetEntityManager(nsECSFramework::TEntityManager* entMng)
{
    mEntityManager = entMng;
}
//--------------------------------------------------------------------------------
void TSceneManager::LoadByAbsPath(const std::string& absPath)
{
    // Same as InstantiateByAbsPath, but without replasing guid
}
//--------------------------------------------------------------------------------
void TSceneManager::LoadByGuid(const std::string& sceneGuid)
{
    // Convert to abs path
    // LoadByAbsPath()
}
//--------------------------------------------------------------------------------
void TSceneManager::InstantiateByAbsPath(const std::string& absPath)
{
    auto logger = GetLogger()->Get(TTimeSliceEngine::NAME);

    std::string json;
    TTextFile::Load(absPath, json);

    // 1. Deserialize to object
    TSceneContent sceneContent;
    std::string err;
    auto deserResult = TTornadoEngineJsonSerializer::Deserialize(&sceneContent, json, err);
    if (deserResult == false) {
        logger->WriteF_time("Deserialize error %s with %s", err.c_str(), absPath.c_str());
        return;
    }

    std::string sceneIstanceGuid;

    auto componentReflection = Project()->mScenePartAggregator->mComponents;
    componentReflection->mEntMng->SetEntityManager(Modules()->EntMng());

    std::list<nsECSFramework::TEntityID> newEntities;
    // 2. Convert typeName to rtti
    for (auto& entity : sceneContent.entities) {
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
            componentReflection->mEntMng->CreateComponent(eid, rtti, [&](void* pComponent) {
                // 5. Deserialize component by rtti and json body
                auto componentDeserialzieResult = 
                    componentReflection->mJson->Deserialize(pComponent, component.jsonBody, rtti, err);

                if (!componentDeserialzieResult) {
                    logger->WriteF_time("Not converted typename \"%s\"", component.typeName);
                }
            });

            auto hasRoot = mEntityManager->HasComponent<nsCommonWrapper::TSceneRootComponent>(eid);
            if (hasRoot) {
                sceneIstanceGuid = mEntityManager->ViewComponent<nsCommonWrapper::TGuidComponent>(eid)->value;
            }
        }
    }

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

        nsCommonWrapper::TSceneOriginalGuidComponent sceneOriginalGuid;
        sceneOriginalGuid.value = guidComponent.value;
        mEntityManager->SetComponent<nsCommonWrapper::TSceneOriginalGuidComponent>(eid, sceneOriginalGuid);

        guidComponent.value = newGuid;
        mEntityManager->SetComponent(eid, guidComponent);

        nsCommonWrapper::TSceneInstanceGuidComponent sceneInstanceGuidComponent;
        sceneInstanceGuidComponent.value = sceneIstanceGuid;
        mEntityManager->SetComponent(eid, sceneInstanceGuidComponent);
    }
}
//--------------------------------------------------------------------------------
void TSceneManager::InstantiateByGuid(const std::string& sceneGuid)
{
    // Convert to abs path
    auto fit = mSceneContentMap.guidPathMap.find(sceneGuid);
    if (fit == mSceneContentMap.guidPathMap.end()) {
        GetLogger()->Get(TTimeSliceEngine::NAME)->WriteF_time("Guid \"%s\" not exist", sceneGuid.c_str());
        return;
    }

    InstantiateByAbsPath(fit->second);
}
//--------------------------------------------------------------------------------
void TSceneManager::Unload(const std::string& sceneGuid)
{
    // Add tag component for new entity
    auto eid = mEntityManager->CreateEntity();

    nsCommonWrapper::TNeedUnloadSceneComponent needUnloadSceneComponent;
    needUnloadSceneComponent.sceneGuid = sceneGuid;
    mEntityManager->SetComponent(eid, needUnloadSceneComponent);
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
    //// Add tag component for new entity
    auto eid = mEntityManager->CreateEntity();

    nsCommonWrapper::TNeedDestroySceneComponent needDestroySceneComponent;
    needDestroySceneComponent.sceneInstanceGuid = sceneInstanceGuid;
    mEntityManager->SetComponent(eid, needDestroySceneComponent);
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
