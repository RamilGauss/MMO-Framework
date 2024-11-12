/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "Modules/Resources/Common/ObjectManager.h"

#include "Modules/Resources/Scene/UniverseManager.h"
#include "Modules/Resources/Scene/InstantiateSceneParams.h"
#include "Modules/Resources/Scene/SceneInstanceState.h"
#include "Modules/Resources/Scene/SceneList.h"

namespace nsTornadoEngine
{
    class TSceneCacheManager;
    class TPrefabManager;
    class TSceneStateGraph;

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

        int mLoadQuant = 5;// ms

        TPrefabManager* mPrefabMng = nullptr;
        TSceneCacheManager* mSceneCacheMng = nullptr;

        std::function<bool(TSceneInstanceStatePtr)> mAsyncCondition;
        std::function<bool(TSceneInstanceStatePtr)> mSyncCondition;

        std::shared_ptr<TSceneStateGraph> mSceneStateGraph;
    public:
        TSceneManager();

        const ISceneInstanceState* GetSceneInstanceState(const std::string& sceneInstanceGuid);

        // Per one call
        std::string Create(const std::string& absPath); // -> guid

        // Aync + sync
        std::string Instantiate(const TInstantiateSceneParams& instantiateSceneParams);// -> sceneInstanceGuid
        void Destroy(const std::string& sceneInstanceGuid);

        // SaveAs нужно реализовывать в коде редактора. Ядро не должно знать об этом функционале.
        // Extended functions
        // Sync + Async
        void Save(const std::string& sceneInstanceGuid);

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
