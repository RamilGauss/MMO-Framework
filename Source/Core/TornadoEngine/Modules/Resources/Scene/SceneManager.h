/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "UniverseManager.h"
#include "ObjectManager.h"
#include "InstantiateSceneParams.h"
#include "SceneInstanceState.h"
#include "SceneList.h"

namespace nsTornadoEngine
{
    class TPrefabManager;
    class DllExport TSceneManager : public TObjectManager
    {
        TUniverseManager mUniverseManager;
        struct TReference
        {
            int counter = 0;
        };

        TColanderVector<TReference> mReferenceCounters;

        std::unordered_map<std::string, TSceneInstanceStatePtr> mSceneInstances;

        const int MAX_ASYNC_LOADING_SCENE_COUNT = 1;
        const int MAX_SYNC_LOADING_SCENE_COUNT = 1;

        TSceneList mAsyncScenes;
        TSceneList mSyncScenes;

        TSceneInstanceState mGhostSceneInstance;

        int mLoadQuant = 5;// ms

        TPrefabManager* mPrefabMng = nullptr;

        std::function<bool(TSceneInstanceStatePtr)> mAsyncCondition;
        std::function<bool(TSceneInstanceStatePtr)> mSyncCondition;
    public:
        TSceneManager();

        const TSceneInstanceState& GetSceneInstanceState(const std::string& sceneInstanceGuid);

        std::string Create(const std::string& absPath); // -> sceneGuid
        // Return SceneStateGuid
        std::string InstantiateByGuid(const TInstantiateSceneParams& instantiateSceneParams, const std::string& tag = "");

        void Destroy(const std::string& sceneInstanceGuid);

        void Save(const std::string& sceneInstanceGuid);// 
        std::string SaveAs(const std::string& sceneInstanceGuid, const std::string& absPath);// -> sceneGuid

        // For Engine usage
        void SetLoadQuant(int ms);
        int GetLoadQuant() const;
        void SetPrefabManager(TPrefabManager* pPrefabMng);
        void SetSceneCacheManager(TSceneCacheManager* pSceneCachebMng);
        void Work();
    private:
        void IncrementReferenceCounter(TUniverseManager::IndexType index);
        void DecrementReferenceCounter(TUniverseManager::IndexType index);

        int GetReferenceCounter(TUniverseManager::IndexType index);

        void AsyncWork(TSceneInstanceState* pSc);
        void SyncWork(TSceneInstanceState* pSc, unsigned int maxDuration);

        void PrepareInstantiating(TSceneInstanceState* pSc);
        void EntityInstantiating(TSceneInstanceState* pSc);
        void PrefabInstantiating(TSceneInstanceState* pSc);

        void TryDeactivateSyncScenes();
        void TryActivateSyncScenes();
    };
}
