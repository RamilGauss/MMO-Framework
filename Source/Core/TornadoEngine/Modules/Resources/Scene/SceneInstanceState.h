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

#include "TypeDef.h"
#include "LoadFromFile.h"
#include "ProgressValue.h"

#include "SceneInstantiatingThread.h"
#include "InstantiateSceneParams.h"
#include "EntityMetaContent.h"
#include "SceneResourceContent.h"

namespace nsTornadoEngine
{
    struct DllExport TSceneInstanceState
    {
        enum class Step
        {
            INIT,
            FILE_LOADING,
            SCENE_DESERIALIZING,     // in one step
            PREPARE_TREE_ENTITY,
            SORTING_ENTITIES_BY_RANK,
            COMPONENT_DESERIALIZING,

            PREPARE_INSTANTIATING,

            ENTITY_INSTANTIATING,
            PREFAB_INSTANTIATING,

            STABLE,

            DESTROYING, // in one step
        };

        enum class SubStep
        {
            ASYNC_LOADING,
            SYNC_LOADING,
            STABLE,
            DESTROYING,
        };

        // Data
        TInstantiateSceneParams mInstantiateSceneParams;

        std::string mAbsPath;
        std::atomic<Step> mStep = Step::INIT;

        std::shared_ptr<TSceneInstantiatingThread> mAsyncThread;

        nsBase::TProgressValue mFileProgress;
        nsBase::TProgressValue mPrepareTreeEntityProgress;
        nsBase::TProgressValue mSortingProgress;
        nsBase::TProgressValue mComponentDeserializingProgress;
        nsBase::TProgressValue mEntityProgress;
        nsBase::TProgressValue mPrefabProgress;

        TContainer mFileBuffer;
        std::string mFileContent;

        TLoadFromFile mFile;

        TSceneResourceContent mSceneContent;

        std::list<TEntityContent>::iterator mCurrentEntIt;

        // Sorting in map need for same sorting as in a saved file.
        std::unordered_map<std::string, std::map<std::string, TEntityMetaContentPtr>> mParentGuidEntities;
        TEntityMetaContentPtr mRootEntity;

        std::list<std::map<std::string, TEntityMetaContentPtr>> mLayers;

        std::list<std::map<std::string, TEntityMetaContentPtr>>::iterator mCurrentLayer;

        int mCurrentLayerIndex = 0;

        std::map<std::string, TEntityMetaContentPtr>::iterator mCurrentLayerEntIt;

        std::list<TEntityContent>::const_iterator mEntIt;
        std::list<TPrefabInstance>::const_iterator mPrefabIt;

        unsigned int mEntityInstanceIndex = 0;
        unsigned int mPrefabInstanceIndex = 0

        unsigned short mUniverseIndex = 0;

        static const int FILE_PART_SIZE = 10'000'000;
        static const int PREPARE_TREE_ENTITY_PART_SIZE = 100;
        static const int SORTING_PART_SIZE = 100;
        static const int COMPONENT_DESERIALZING_PART_SIZE = 1000;

        static const int ENTITY_INSTANTIATING_PART_SIZE = 1000;
        static const int PREFAB_INSTANTIATING_PART_SIZE = 10;

        // Helpers
        TSceneInstanceState(const TInstantiateSceneParams& instantiateSceneParams);

        SubStep GetSubStep() const;

        float GetLoadingProgress() const;
        bool IsLoadCompleted() const;

        bool IsCancelled() const;
    };

    using TSceneInstanceStatePtr = std::shared_ptr<TSceneInstanceState>;
}
