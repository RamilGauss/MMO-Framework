/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "InstantiatePrefabParams.h"
#include "Modules/Resources/Common/ObjectManager.h"
#include "Modules/Resources/Common/GameObject.h"

namespace nsTornadoEngine
{
    class TSceneManager;

    class DllExport TPrefabManager : public TObjectManager
    {
        TSceneManager* mSceneMng = nullptr;
    public:
        void SetSceneManager(TSceneManager* pSceneMng);

        // Per one call
        std::string Create(const std::string& absPath); // -> guid

        // Если SceneInstance не задан, то искать нужно по родителю
        // И наоборот, если не задан родитель, то нужен SceneInstance, что бы найти root.

        TGameObject Instantiate(const TInstantiatePrefabParams& instantiatePrefabParams);

        // Уничтожить 
        void Destroy(nsECSFramework::TEntityID anyEidInScene);
        void Destroy(const std::string& prefabInstanceGuid);

        void Save(const std::string& instancePrefabGuid);
    private:
        void InstantiateEntities(const std::list<nsECSFramework::TEntityID>& newEntities, 
            const std::string& sceneInstanceGuid, const std::string& parentGuid);

        void SetupUniverse(const std::list<nsECSFramework::TEntityID>& newEntities,
            const std::string& sceneInstanceGuid, const std::string& parentGuid);
    };
}
