/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "TornadoEngine/Modules/Resources/Common/ObjectManager.h"

#include "TornadoEngine/Modules/Resources/Scene/UniverseManager.h"
#include "TornadoEngine/Modules/Resources/Scene/InstantiateSceneParams.h"
#include "TornadoEngine/Modules/Resources/Scene/SceneState.h"
#include "TornadoEngine/Modules/Resources/Scene/SceneCacheManager.h"

namespace nsTornadoEngine
{
    class TPrefabManager;
    class TSceneStateGraph;
    struct TSceneContext;
    using TSceneContextPtr = std::shared_ptr<TSceneContext>;

    class DllExport TSceneManager : public TObjectManager
    {
        TUniverseManager mUniverseManager;

        std::unordered_map<std::string, TSceneContextPtr> mSceneInstances;

        int mLoadQuant = 5;// ms

        TPrefabManager* mPrefabMng = nullptr;
        TSceneCacheManager mSceneCacheMng;

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

        void Work();
    private:
        int mGuidComponentRtti = 0;
        int mParentGuidComponentRtti = 0;
        int mSceneRootComponentRtti = 0;

        std::string mGuidComponentTypeName;
        std::string mParentGuidComponentTypeName;
        std::string mSceneRootComponentTypeName;
    };
}
