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
#include "SceneInstanceLoader.h"

#include "GuidGenerator.h"

#include "UniverseIndexComponent.h"
#include "UniverseGuidComponent.h"

namespace nsTornadoEngine
{
    TSceneManager::TSceneManager() :
        mGhostSceneInstance({})
    {
        mAsyncCondition =
            [](TSceneInstanceStatePtr pSc) {return pSc->GetSubStep() != TSceneInstanceState::SubStep::ASYNC_LOADING; };
        mSyncCondition =
            [](TSceneInstanceStatePtr pSc) {return pSc->GetSubStep() != TSceneInstanceState::SubStep::SYNC_LOADING; };

        mAsyncScenes.Setup(MAX_ASYNC_LOADING_SCENE_COUNT, mAsyncCondition);
        mSyncScenes.Setup(MAX_SYNC_LOADING_SCENE_COUNT, mSyncCondition);
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
    const TSceneInstanceState& TSceneManager::GetSceneInstanceState(const std::string& sceneInstanceGuid)
    {
        auto fit = mSceneInstances.find(sceneInstanceGuid);
        if (fit == mSceneInstances.end()) {
            return mGhostSceneInstance;
        }

        return *(fit->second.get());
    }
    //--------------------------------------------------------------------------------------------------------
    std::string TSceneManager::InstantiateByGuid(TInstantiateSceneParams instantiateSceneParams)
    {
        // Convert to abs path
        auto fit = mResourceContentMap.guidPathMap.find(instantiateSceneParams.guid);
        if (fit == mResourceContentMap.guidPathMap.end()) {
            GetLogger()->Get(TTimeSliceEngine::NAME)->WriteF_time("Guid \"%s\" not exist", instantiateSceneParams.guid.c_str());
            return "Not found";
        }

        instantiateSceneParams.absPath = fit->second;
        return InstantiateByAbsPath(instantiateSceneParams);
    }
    //--------------------------------------------------------------------------------------------------------
    std::string TSceneManager::InstantiateByAbsPath(const TInstantiateSceneParams& instantiateSceneParams)
    {
        TSceneInstanceStatePtr sceneInstanceState = std::make_shared<TSceneInstanceState>(instantiateSceneParams);

        mSceneInstances.insert({ sceneInstanceState->mGuid, sceneInstanceState });

        mAsyncScenes.AddToWait(sceneInstanceState);

        return sceneInstanceState->mGuid;
    }
    //--------------------------------------------------------------------------------------------------------
    void TSceneManager::Destroy(const std::string& sceneInstanceGuid)
    {

    }
    //--------------------------------------------------------------------------------------------------------
    void TSceneManager::Destroy(nsECSFramework::TEntityID anyEidInScene)
    {

    }
    //--------------------------------------------------------------------------------------------------------
    bool TSceneManager::Save(const std::string& sceneGuid)
    {
        return false;
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
            TSceneInstanceLoader::AsyncWork(scene.get());
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

                TSceneInstanceLoader::SyncWork(scene.get(), maxDuration);

                std::list<TSceneInstanceStatePtr> deactivatedSyncScenes;
                mSyncScenes.TryDeactivate(deactivatedSyncScenes);

                std::list<TSceneInstanceStatePtr> activatedSyncScenes;
                mSyncScenes.TryActivate(activatedSyncScenes);

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
}
