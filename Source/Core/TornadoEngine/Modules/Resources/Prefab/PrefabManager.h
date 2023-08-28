/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "InstantiatePrefabParams.h"
#include "ObjectManager.h"
#include "GameObject.h"

namespace nsTornadoEngine
{
    class TPrefabObjectConstructor;

    class DllExport TPrefabManager : public TObjectManager
    {
    public:
        // Если SceneInstance не задан, то искать нужно по родителю
        // И наоборот, если не задан родитель, то нужен SceneInstance, что бы найти root.

        TGameObject InstantiateByGuid(TInstantiatePrefabParams instantiatePrefabParams);
        TGameObject InstantiateByAbsPath(const TInstantiatePrefabParams& instantiatePrefabParams);

        // Уничтожить 
        void Destroy(nsECSFramework::TEntityID anyEidInScene);
        void Destroy(const std::string& prefabInstanceGuid);

        void Save(const std::string& prefabGuid);
    private:
        void CreateEntity(TPrefabObjectConstructor* prefabObjConstructor, 
            nsECSFramework::TEntityID eid, std::list<nsECSFramework::TEntityID>& newEntities);

        void InstantiateEntities(const std::list<nsECSFramework::TEntityID>& newEntities, 
            const std::string& sceneInstanceGuid, const std::string& parentGuid);

        void SetupUniverse(const std::list<nsECSFramework::TEntityID>& newEntities,
            const std::string& sceneInstanceGuid, const std::string& parentGuid);
    };
}
