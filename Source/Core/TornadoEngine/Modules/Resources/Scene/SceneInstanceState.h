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

#include "TypeDef.h"
#include "ProgressValue.h"

#include "SceneInstantiatingThread.h"
#include "InstantiateSceneParams.h"

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

        std::unordered_map<std::string, > mGuidEntities;

        const int FILE_PART_SIZE = 10'000'000;
        const int COMPONENT_PART_SIZE = 100;
        const int SORTING_PART_SIZE = 100;

        const int ENTITY_INSTANTIATING_PART_SIZE = 1000;
        const int PREFAB_INSTANTIATING_PART_SIZE = 10;

        // Helpers
        TSceneInstanceState(const TInstantiateSceneParams& instantiateSceneParams);

        SubStep GetSubStep() const;

        float GetLoadingProgress() const;
        bool IsLoadCompleted() const;
    };

    using TSceneInstanceStatePtr = std::shared_ptr<TSceneInstanceState>;
}
