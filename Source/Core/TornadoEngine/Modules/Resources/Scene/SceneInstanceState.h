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
            COMPONENTS_DESERIALIZING,
            SORTING_ENTITIES_BY_RANK,

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

        std::string mGuid;
        std::atomic<Step> mStep = Step::INIT;

        std::shared_ptr<TSceneInstantiatingThread> mAsyncThread;

        nsBase::TProgressValue mFileProgress;
        nsBase::TProgressValue mComponentProgress;
        nsBase::TProgressValue mSortingProgress;
        nsBase::TProgressValue mEntityProgress;
        nsBase::TProgressValue mPrefabProgress;

        TContainer mFileBuffer;
        std::string mFileContent;

        TLoadFromFile mFile;

        TSceneResourceContent mSceneContent;

        std::unordered_map<std::string, std::list<TEntityMetaContentPtr>> mParentGuidEntities;
        TEntityMetaContent mRootEntity;

        static const int FILE_PART_SIZE = 10'000'000;
        static const int COMPONENT_PART_SIZE = 100;
        static const int SORTING_PART_SIZE = 100;

        static const int ENTITY_INSTANTIATING_PART_SIZE = 1000;
        static const int PREFAB_INSTANTIATING_PART_SIZE = 10;

        static const int ROUGH_COMPONENT_SIZE = 50;
        static const int ROUGH_ENTITY_SIZE = 7 * ROUGH_COMPONENT_SIZE;

        // Helpers
        TSceneInstanceState(const TInstantiateSceneParams& instantiateSceneParams);

        SubStep GetSubStep() const;

        float GetLoadingProgress() const;
        bool IsLoadCompleted() const;
    };

    using TSceneInstanceStatePtr = std::shared_ptr<TSceneInstanceState>;
}
