/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ObjectManager.h"


namespace nsTornadoEngine
{
    class TPrefabObjectConstructor;

    class DllExport TPrefabManager : public TObjectManager
    {
    public:

        void LoadByGuid(const std::string& prefabGuid);
        void LoadByAbsPath(const std::string& absPath);
        void LoadByObjectInMemory(nsECSFramework::TEntityID eid);

        void Save(const std::string& prefabGuid);

        void Unload(const std::string& prefabGuid);

        // Если SceneInstance не задан, то искать нужно по родителю
        // И наоборот, если не задан родитель, то нужен SceneInstance, что бы найти root.

        void InstantiateByGuid(const std::string& prefabGuid, const std::string& sceneInstanceGuid, 
            const std::string& parentGuid = TGuidConstants::NONE);
        void InstantiateByAbsPath(const std::string& absPath, const std::string& sceneInstanceGuid, 
            const std::string& parentGuid = TGuidConstants::NONE);
        void InstantiateByObjectInMemory(TPrefabObjectConstructor* prefabObjConstructor, nsECSFramework::TEntityID eid, 
            const std::string& sceneInstanceGuid, const std::string& parentGuid = TGuidConstants::NONE);


        void Destroy(const std::string& prefabInstanceGuid);
        void Destroy(nsECSFramework::TEntityID anyEidInScene);


    private:
        void CreateEntity(TPrefabObjectConstructor* prefabObjConstructor, 
            nsECSFramework::TEntityID eid, std::list<nsECSFramework::TEntityID>& newEntities);

        void InstantiateEntities(const std::list<nsECSFramework::TEntityID>& newEntities, 
            const std::string& sceneInstanceGuid, const std::string& parentGuid);
    };
}