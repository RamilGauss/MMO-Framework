/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "TypeDef.h"

#include "SceneContentMap.h"
#include <ECS/include/EntityManager.h>

namespace nsTornadoEngine
{
    class DllExport TSceneManager
    {
        TSceneContentMap mSceneContentMap;
        nsECSFramework::TEntityManager* mEntityManager = nullptr;
    public:
        void SetContentMap(const TSceneContentMap& sceneContentMap);
        void SetEntityManager(nsECSFramework::TEntityManager* entMng);

        void LoadByGuid(const std::string& sceneGuid);
        void LoadByAbsPath(const std::string& absPath);

        void Save(const std::string& sceneGuid);

        void Unload(const std::string& sceneGuid);

        void InstantiateByGuid(const std::string& sceneGuid);
        void InstantiateByAbsPath(const std::string& absPath);

        void Destroy(const std::string& sceneInstanceGuid);
        void Destroy(nsECSFramework::TEntityID anyEidInScene);
    };
}