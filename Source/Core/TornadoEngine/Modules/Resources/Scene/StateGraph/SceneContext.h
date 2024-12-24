/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>
#include <memory>
#include <atomic>
#include <unordered_map>
#include <map>

#include "Base/Common/LoadFromFile.h"

#include "Base/Zones/HopProcessContext.h"

#include "Modules/Resources/Scene/InstantiateSceneParams.h"
#include "Modules/Resources/Scene/EntityMetaContent.h"
#include "Modules/Resources/Scene/SceneResourceContent.h"
#include "Modules/Resources/Scene/SceneCacheManager.h"
#include "Modules/Resources/Scene/UniverseManager.h"

namespace nsECSFramework
{
    class TEntityManager;
}

namespace nsTornadoEngine
{
    class TPrefabManager;

    struct DllExport TSceneContext : nsBase::nsZones::THopProcessContext
    {
        int guidComponentRtti = 0;
        int garentGuidComponentRtti = 0;
        int sceneRootComponentRtti = 0;

        std::string guidComponentTypeName;
        std::string parentGuidComponentTypeName;
        std::string sceneRootComponentTypeName;

        std::string sceneAbsPath;

        TInstantiateSceneParams instantiateSceneParams;

        TContainer fileBuffer;
        std::string fileContent;

        nsBase::nsCommon::TLoadFromFile file;

        std::shared_ptr<TSceneResourceContent> sceneContent;

        std::list<std::string> entityGuids;

        std::list<TEntityContent>::iterator currentEntIt;

        TSceneCacheManager* cacheManager = nullptr;
        TUniverseManager* universeManager = nullptr;
        nsECSFramework::TEntityManager* entityManager = nullptr;
        TPrefabManager* prefabMng = nullptr;

        std::list<TEntityContent>::const_iterator entIt;
        std::list<TPrefabInstance>::const_iterator prefabIt;

        //unsigned int entityInstanceIndex = 0;
        //unsigned int prefabInstanceIndex = 0;

        unsigned short universeIndex = 0;
    };

    using TSceneContextPtr = std::shared_ptr<TSceneContext>;
}
