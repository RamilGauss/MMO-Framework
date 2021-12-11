/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

#include "PrefabContentMap.h"
#include "GuidConstants.h"

#include <ECS/include/EntityManager.h>

namespace nsTornadoEngine
{
    class DllExport TPrefabManager
    {
        TPrefabContentMap mPrefabContentMap;
        nsECSFramework::TEntityManager* mEntityManager = nullptr;
    public:
        void SetContentMap(const TPrefabContentMap& prefabContentMap);
        void SetEntityManager(nsECSFramework::TEntityManager* entMng);

        void LoadByGuid(const std::string& prefabGuid);
        void LoadByAbsPath(const std::string& absPath);
        void LoadByObjectInMemory(nsECSFramework::TEntityID eid);

        void Save(const std::string& prefabGuid);

        void Unload(const std::string& prefabGuid);

        void InstantiateByGuid(const std::string& parentGuid, const std::string& prefabGuid, 
            const std::string& sceneInstanceGuid = TGuidConstants::NONE);
        void InstantiateByAbsPath(const std::string& parentGuid, const std::string& absPath,
            const std::string& sceneInstanceGuid = TGuidConstants::NONE);
        void InstanceByObjectInMemory(const std::string& parentGuid, nsECSFramework::TEntityID eid,
            const std::string& sceneInstanceGuid = TGuidConstants::NONE);

        void Destroy(const std::string& prefabInstanceGuid);
        void Destroy(nsECSFramework::TEntityID anyEidInScene);

    };
}