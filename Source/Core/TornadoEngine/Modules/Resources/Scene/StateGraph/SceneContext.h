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

namespace nsTornadoEngine
{
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

        //// Sorting in map need for same sorting as in a saved file.
        //std::unordered_map<std::string, std::map<std::string, TEntityMetaContentPtr>> parentGuidEntities;
        //TEntityMetaContentPtr rootEntity;

        //std::list<std::map<std::string, TEntityMetaContentPtr>> layers;

        //std::list<std::map<std::string, TEntityMetaContentPtr>>::iterator currentLayer;

        //int currentLayerIndex = 0;

        //std::map<std::string, TEntityMetaContentPtr>::iterator currentLayerEntIt;

        std::list<TEntityContent>::const_iterator entIt;
        std::list<TPrefabInstance>::const_iterator prefabIt;

        unsigned int entityInstanceIndex = 0;
        unsigned int prefabInstanceIndex = 0;

        unsigned short universeIndex = 0;

        static const int FILE_PART_SIZE = 1'000'000;
        static const int PREPARE_TREE_ENTITY_PART_SIZE = 100;
        static const int SORTING_PART_SIZE = 100;
        static const int COMPONENT_DESERIALZING_PART_SIZE = 1000;

        static const int ENTITY_INSTANTIATING_PART_SIZE = 1000;
        static const int PREFAB_INSTANTIATING_PART_SIZE = 10;

    };

    using TSceneContextPtr = std::shared_ptr<TSceneContext>;
}
