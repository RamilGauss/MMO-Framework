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

#include "UniverseIndexComponent.h"
#include "UniverseGuidComponent.h"

using namespace nsTornadoEngine;

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

    TUniverseGuidComponent universeGuidComponent;
    universeGuidComponent.value = universeGuid;
    AddComponent(newEntities, &universeGuidComponent);


    auto universeIndex = mUniverseManager.GetIndexByGuid(universeGuid);
    if (universeIndex == TUniverseManager::UNDEFINED_INDEX) {
        mUniverseManager.Create(universeGuid);
        universeIndex = mUniverseManager.GetIndexByGuid(universeGuid);
    }

    IncrementCounter(universeIndex);

    TUniverseIndexComponent universeIndexComponent;
    universeIndexComponent.value = universeIndex;
    AddComponent(newEntities, &universeIndexComponent);
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

    // Try destroy universe
    auto firstEid = *(eids.begin());
    auto index = mEntityManager->ViewComponent<nsCommonWrapper::TUniverseIndexComponent>(firstEid)->value;
    if (GetCounter(index) == 0) {
        mUniverseManager.Delete(index);
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
void TSceneManager::IncrementCounter(TUniverseManager::IndexType index)
{
    mReferenceCounters[index].counter++;
}
//--------------------------------------------------------------------------------
void TSceneManager::DecrementCounter(TUniverseManager::IndexType index)
{
    mReferenceCounters[index].counter--;

    BL_ASSERT(mReferenceCounters[index].counter >= 0);
}
//--------------------------------------------------------------------------------
int TSceneManager::GetCounter(TUniverseManager::IndexType index)
{
    return mReferenceCounters[index].counter;
}
//--------------------------------------------------------------------------------
