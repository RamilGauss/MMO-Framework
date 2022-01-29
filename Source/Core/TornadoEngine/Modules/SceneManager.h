/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "ObjectManager.h"

namespace nsTornadoEngine
{
    class DllExport TSceneManager : public TObjectManager
    {
    public:
        void LoadByGuid(const std::string& sceneGuid);
        void LoadByAbsPath(const std::string& absPath);

        void Save(const std::string& sceneGuid);

        void Unload(const std::string& sceneGuid);

        void InstantiateByGuid(const std::string& sceneGuid, const std::string& universeGuid = TGuidConstants::DEFAULT_UNIVERSE);
        void InstantiateByAbsPath(const std::string& absPath, const std::string& universeGuid = TGuidConstants::DEFAULT_UNIVERSE);

        void Destroy(const std::string& sceneInstanceGuid);
        void Destroy(nsECSFramework::TEntityID anyEidInScene);
    };
}