/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "SceneManager.h"

#include "HiTimer.h"
#include "TextFile.h"
#include "Logger.h"
#include "TornadoEngineJsonSerializer.h"
#include "ProjectConfigContainer.h"

#include "Modules.h"
#include "HandlerCallCollector.h"

#include "PrefabManager.h"

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

namespace nsTornadoEngine
{
    TSceneManager::TSceneManager()
    {
        mAsyncCondition =
            [](TSceneInstanceStatePtr pSc) {return pSc->GetState() != TSceneInstanceState::State::ASYNC_INSTANTIATING; };
        mSyncCondition =
            [](TSceneInstanceStatePtr pSc) {return pSc->GetState() != TSceneInstanceState::State::SYNC_INSTANTIATING; };

        mAsyncScenes.Setup(MAX_ASYNC_LOADING_SCENE_COUNT, mAsyncCondition);
        mSyncScenes.Setup(MAX_SYNC_LOADING_SCENE_COUNT, mSyncCondition);
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
        // Convert to abs path
        auto fit = mResourceContentMap.guidPathMap.find(instantiateSceneParams.guid);
        if (fit == mResourceContentMap.guidPathMap.end()) {
            nsTornadoEngine::Modules()->CoreLog()->Log("Guid \"%s\" not exist", instantiateSceneParams.guid.c_str());
            return "Not found";
        }

        TSceneInstanceStatePtr sceneInstanceState = std::make_shared<TSceneInstanceState>(instantiateSceneParams);

        if (sceneInstanceState->mInstantiateSceneParams.sceneInstanceGuid.empty()) {
            sceneInstanceState->mInstantiateSceneParams.sceneInstanceGuid = nsBase::TGuidGenerator::Generate();
        }

        sceneInstanceState->mAbsPath = fit->second;

        mSceneInstances.insert({ sceneInstanceState->mInstantiateSceneParams.sceneInstanceGuid, sceneInstanceState });

        mAsyncScenes.AddToWait(sceneInstanceState);

        return sceneInstanceState->mInstantiateSceneParams.sceneInstanceGuid;
    }
    //--------------------------------------------------------------------------------------------------------
    void TSceneManager::Destroy(const std::string& sceneInstanceGuid)
    {

    }
    //--------------------------------------------------------------------------------------------------------
    void TSceneManager::Save(const std::string& sceneInstanceGuid, const std::string& guid)
    {
        auto pSceneInstanceState = (TSceneInstanceState*)GetSceneInstanceState(sceneInstanceGuid);
        if (pSceneInstanceState == nullptr) {
            return;
        }

        auto dstGuid = guid;
        if (dstGuid.empty()) {
            dstGuid = pSceneInstanceState->mInstantiateSceneParams.guid;
        }


    }
    //--------------------------------------------------------------------------------------------------------
    void TSceneManager::Work()
    {
        // Async
        std::list<TSceneInstanceStatePtr> asyncDeactivatedScenes;
        mAsyncScenes.TryDeactivate(asyncDeactivatedScenes);

        for (auto& scene : asyncDeactivatedScenes) {
            scene->mAsyncThread->Stop();

            mSyncScenes.AddToWait(scene);
        }

        std::list<TSceneInstanceStatePtr> asyncActivatedScenes;
        mAsyncScenes.TryActivate(asyncActivatedScenes);

        for (auto& scene : asyncActivatedScenes) {
            AsyncWork(scene.get());
        }

        // Sync
        {
            std::list<TSceneInstanceStatePtr> activatedSyncScenes;
            mSyncScenes.TryActivate(activatedSyncScenes);
        }


        auto start = ht_GetMSCount();
        while (true) {

            auto activeScenes = mSyncScenes.GetActive();

            if (activeScenes.empty()) {
                break;
            }

            int maxDuration = GetLoadQuant();

            for (auto& scene : activeScenes) {

                SyncWork(scene.get(), maxDuration);

                TryDeactivateSyncScenes();

                TryActivateSyncScenes();

                auto now = ht_GetMSCount();
                auto dt = now - start;

                maxDuration = GetLoadQuant() - dt;

                if (maxDuration <= 0) {
                    break;
                }
            }

            if (maxDuration <= 0) {
                break;
            }
        }
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
    void TSceneManager::AsyncWork(TSceneInstanceState* pSc)
    {
        pSc->mAsyncThread = std::make_shared<TSceneInstantiatingThread>(pSc);

        pSc->mAsyncThread->Start();
    }
    //---------------------------------------------------------------------------------------
    void TSceneManager::SyncWork(TSceneInstanceState* pSc, unsigned int maxDuration)
    {
        auto start = ht_GetMSCount();

        while (true) {

            switch (pSc->mSubState) {
                case TSceneInstanceState::SubState::PREPARE_INSTANTIATING:
                    PrepareInstantiating(pSc);
                    break;
                case TSceneInstanceState::SubState::ENTITY_INSTANTIATING:
                    EntityInstantiating(pSc);
                    break;
                case TSceneInstanceState::SubState::PREFAB_INSTANTIATING:
                    PrefabInstantiating(pSc);
                    break;
                default:;
            }

            if (pSc->IsInstantiateCompleted()) {
                break;
            }

            auto dt = ht_GetMSCount() - start;

            if (dt >= maxDuration) {
                break;
            }
        }
    }
    //---------------------------------------------------------------------------------------
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
    void TSceneManager::TryDeactivateSyncScenes()
    {
        auto handlerCallCollector = nsTornadoEngine::Modules()->HandlerCalls();

        //std::list<TSceneInstanceStatePtr> deactivatedSyncScenes;
        //mSyncScenes.TryDeactivate(deactivatedSyncScenes);

        //for (auto& deactivatedSyncScene : deactivatedSyncScenes) {
        //    auto pEntMng = mEntityManager;
        //    auto eids = pEntMng->GetByHasCopy<nsLogicWrapper::TSceneInstantiationCompletionHandlerComponent>();

        //    for (auto& eid : eids) {
        //        auto handler = pEntMng->ViewComponent<nsLogicWrapper::TSceneInstantiationCompletionHandlerComponent>(eid)->handler;

        //        auto tag = deactivatedSyncScene->mInstantiateSceneParams.tag;
        //        auto sceneInstanceGuid = deactivatedSyncScene->mInstantiateSceneParams.sceneInstanceGuid;
        //        handlerCallCollector->Add([handler, eid, sceneInstanceGuid, tag]()
        //        {
        //            handler->Handle(eid, sceneInstanceGuid, tag);
        //        });
        //    }
        //}
    }
    //--------------------------------------------------------------------------------
    void TSceneManager::TryActivateSyncScenes()
    {
        std::list<TSceneInstanceStatePtr> activatedSyncScenes;
        mSyncScenes.TryActivate(activatedSyncScenes);
    }
    //--------------------------------------------------------------------------------
}
