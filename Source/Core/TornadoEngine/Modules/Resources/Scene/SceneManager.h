/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "Base/Zones/ContextStateInProcess.h"

#include "Modules/Resources/Common/ObjectManager.h"

#include "Modules/Resources/Scene/UniverseManager.h"
#include "Modules/Resources/Scene/InstantiateSceneParams.h"
#include "Modules/Resources/Scene/SceneState.h"

namespace nsTornadoEngine
{
    class TSceneCacheManager;
    class TPrefabManager;
    class TSceneStateGraph;
    struct TSceneContext;
    using TSceneContextPtr = std::shared_ptr<TSceneContext>;

    class DllExport TSceneManager : public TObjectManager
    {
        TUniverseManager mUniverseManager;
        struct TReference
        {
            int counter = 0;
        };

        TColanderVector<TReference> mReferenceCounters;

        std::unordered_map<std::string, TSceneContextPtr> mSceneInstances;

        int mLoadQuant = 5;// ms

        TPrefabManager* mPrefabMng = nullptr;
        TSceneCacheManager* mSceneCacheMng = nullptr;

        std::shared_ptr<TSceneStateGraph> mSceneStateGraph;
    public:
        TSceneManager();

        std::optional<TSceneState> GetState(const std::string& sceneInstanceGuid);

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
    };
}
