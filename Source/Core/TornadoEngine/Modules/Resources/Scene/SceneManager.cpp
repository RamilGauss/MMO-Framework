/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Modules/Resources/Scene/SceneManager.h"

#include "Base/Common/HiTimer.h"
#include "Base/Common/TextFile.h"
#include "Base/Common/Logger.h"
#include "Base/Common/GuidGenerator.h"

#include "TimeSliceEngine/EngineLogger.h"
#include "Generated Files/TornadoEngineJsonSerializer.h"
#include "TimeSliceEngine/ProjectConfigContainer.h"

#include "Modules/Common/Modules.h"
#include "Modules/Resources/Common/HandlerCallCollector.h"

#include "Modules/Resources/Prefab/PrefabManager.h"
#include "Modules/Resources/Scene/StateGraph/SceneStateGraph.h"

#include "Components/Meta/GuidComponent.h"
#include "Components/Meta/ParentGuidComponent.h"
#include "Components/Meta/SceneOriginalGuidComponent.h"
#include "Components/Meta/SceneInstanceGuidComponent.h"
#include "Components/Meta/NeedDestroyObjectTagComponent.h"
#include "Components/Meta/SceneRootComponent.h"
#include "Components/Meta/SceneGuidComponent.h"
#include "Components/Meta/UniverseIndexComponent.h"
#include "Components/Meta/UniverseGuidComponent.h"


namespace nsTornadoEngine
{
    TSceneManager::TSceneManager()
    {
        mSceneStateGraph = std::make_shared<TSceneStateGraph>();
    }
    //--------------------------------------------------------------------------------------------------------
    std::string TSceneManager::Create(const std::string& absPath)
    {
        auto guid = TResourceManager::Create(absPath);

        TSceneResourceContent sceneResourceContent;
        TResourceManager::Save(absPath, &sceneResourceContent);

        return guid;
    }
    //--------------------------------------------------------------------------------------------------------
    void TSceneManager::SetLoadQuant(int ms)
    {
        mLoadQuant = ms;
    }
    //--------------------------------------------------------------------------------------------------------
    int TSceneManager::GetLoadQuant() const
    {
        return mLoadQuant;
    }
    //--------------------------------------------------------------------------------------------------------
    const ISceneInstanceState* TSceneManager::GetSceneInstanceState(const std::string& sceneInstanceGuid)
    {
        auto fit = mSceneInstances.find(sceneInstanceGuid);
        if (fit == mSceneInstances.end()) {
            return nullptr;
        }

        return fit->second.get();
    }
    //--------------------------------------------------------------------------------------------------------
    std::string TSceneManager::Instantiate(const TInstantiateSceneParams& instantiateSceneParams)
    {
        //mSceneStateGraph->StartProcess()

        // Convert to abs path
        //auto fit = mResourceContentMap.guidPathMap.find(instantiateSceneParams.guid);
        //if (fit == mResourceContentMap.guidPathMap.end()) {
        //    nsTornadoEngine::Modules()->Log()->AddWarningEvent("Guid \"{}\" not exist", instantiateSceneParams.guid.c_str());
            return "Not found";
        //}

        //TSceneInstanceStatePtr sceneInstanceState = std::make_shared<TSceneInstanceState>(instantiateSceneParams);

        //if (sceneInstanceState->mInstantiateSceneParams.sceneInstanceGuid.empty()) {
        //    sceneInstanceState->mInstantiateSceneParams.sceneInstanceGuid = nsBase::nsCommon::TGuidGenerator::Generate();
        //}

        //sceneInstanceState->mAbsPath = fit->second;

        //mSceneInstances.insert({ sceneInstanceState->mInstantiateSceneParams.sceneInstanceGuid, sceneInstanceState });

        //mAsyncScenes.AddToWait(sceneInstanceState);

        //return sceneInstanceState->mInstantiateSceneParams.sceneInstanceGuid;
    }
    //--------------------------------------------------------------------------------------------------------
    void TSceneManager::Destroy(const std::string& sceneInstanceGuid)
    {

    }
    //--------------------------------------------------------------------------------------------------------
    void TSceneManager::Save(const std::string& sceneInstanceGuid)
    {
        auto pSceneInstanceState = (TSceneInstanceState*)GetSceneInstanceState(sceneInstanceGuid);
        if (pSceneInstanceState == nullptr) {
            return;
        }
    }
    //--------------------------------------------------------------------------------------------------------
    void TSceneManager::Work()
    {
        mSceneStateGraph->Work(GetLoadQuant());
    }
    //--------------------------------------------------------------------------------------------------------
    void TSceneManager::IncrementReferenceCounter(TUniverseManager::IndexType index)
    {
        mReferenceCounters[index].counter++;
    }
    //--------------------------------------------------------------------------------------------------------
    void TSceneManager::DecrementReferenceCounter(TUniverseManager::IndexType index)
    {
        mReferenceCounters[index].counter--;

        BL_ASSERT(mReferenceCounters[index].counter >= 0);
    }
    //--------------------------------------------------------------------------------------------------------
    int TSceneManager::GetReferenceCounter(TUniverseManager::IndexType index)
    {
        return mReferenceCounters[index].counter;
    }
    //--------------------------------------------------------------------------------------------------------
    void TSceneManager::SetPrefabManager(TPrefabManager* pPrefabMng)
    {
        mPrefabMng = pPrefabMng;
    }
    //--------------------------------------------------------------------------------------------------------
    void TSceneManager::SetSceneCacheManager(TSceneCacheManager* pSceneCachebMng)
    {
        mSceneCacheMng = pSceneCachebMng;
    }
    //--------------------------------------------------------------------------------------------------------
    void TSceneManager::PrepareInstantiating(TSceneInstanceState* pSc)
    {
        pSc->mEntIt = pSc->mSceneContent.entities.begin();

        auto universeIndex = mUniverseManager.GetIndexByGuid(pSc->mInstantiateSceneParams.universeGuid);
        if (universeIndex == TUniverseManager::UNDEFINED_INDEX) {
            mUniverseManager.Create(pSc->mInstantiateSceneParams.universeGuid);
            universeIndex = mUniverseManager.GetIndexByGuid(pSc->mInstantiateSceneParams.universeGuid);
        }

        IncrementReferenceCounter(universeIndex);

        pSc->mUniverseIndex = universeIndex;

        pSc->mSubState = TSceneInstanceState::SubState::ENTITY_INSTANTIATING;
    }
    //---------------------------------------------------------------------------------------
    void TSceneManager::EntityInstantiating(TSceneInstanceState* pSc)
    {
        int partSize = pSc->mEntityProgress.GetSteppedRemain();

        using namespace nsCommonWrapper;

        std::list<nsECSFramework::TEntityID> newEntities;

        // Convert typeName to rtti
        DeserializeObjects(newEntities, pSc->mEntIt, partSize);

        // Replace all guids to new guid with ParentGuids and SceneGuids
        UpdateGuidsAndInstantiate<TSceneOriginalGuidComponent, TSceneInstanceGuidComponent>(newEntities, pSc->mInstantiateSceneParams.sceneInstanceGuid);

        TUniverseGuidComponent universeGuidComponent;
        universeGuidComponent.value = pSc->mInstantiateSceneParams.universeGuid;
        AddComponent(newEntities, &universeGuidComponent);

        TUniverseIndexComponent universeIndexComponent;
        universeIndexComponent.value = pSc->mUniverseIndex;
        AddComponent(newEntities, &universeIndexComponent);

        pSc->mEntityProgress.IncrementValue(partSize);

        if (pSc->mEntityProgress.IsCompleted()) {

            if (pSc->mSceneContent.prefabInstances.size()) {
                pSc->mSubState = TSceneInstanceState::SubState::PREFAB_INSTANTIATING;
            } else {
                pSc->mSubState = TSceneInstanceState::SubState::INSTANTIATED;
            }
        }
    }
    //--------------------------------------------------------------------------------
    void TSceneManager::PrefabInstantiating(TSceneInstanceState* pSc)
    {
        using namespace nsCommonWrapper;

        int partSize = pSc->mPrefabProgress.GetSteppedRemain();

        for (int i = 0; i < partSize; i++, pSc->mPrefabIt++) {

            std::string parentGuid;

            TSceneOriginalGuidComponent sceneOriginalGuidComponent;
            sceneOriginalGuidComponent.value = pSc->mPrefabIt->parentGuid;

            auto sceneOriginalGuidEntities = mEntityManager->GetByValueCopy(sceneOriginalGuidComponent);
            for (auto eid : sceneOriginalGuidEntities) {

                auto sceneInstanceGuid = mEntityManager->ViewComponent<TSceneInstanceGuidComponent>(eid)->value;
                if (sceneInstanceGuid == pSc->mInstantiateSceneParams.sceneInstanceGuid) {
                    parentGuid = sceneInstanceGuid;
                    break;
                }
            }

            TInstantiatePrefabParams instantiatePrefabParams;

            instantiatePrefabParams.guid = pSc->mPrefabIt->prefabGuid;
            instantiatePrefabParams.rootMatrix = pSc->mPrefabIt->localMatrix;
            instantiatePrefabParams.parentGuid = parentGuid;
            instantiatePrefabParams.sceneInstanceGuid = pSc->mInstantiateSceneParams.sceneInstanceGuid;

            mPrefabMng->Instantiate(instantiatePrefabParams);
        }

        pSc->mPrefabProgress.IncrementValue(partSize);

        if (pSc->mPrefabProgress.IsCompleted()) {
            pSc->mSubState = TSceneInstanceState::SubState::INSTANTIATED;
        }
    }
    //--------------------------------------------------------------------------------
}
