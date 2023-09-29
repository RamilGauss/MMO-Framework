/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "SceneInstanceState.h"

#include "GuidGenerator.h"

namespace nsTornadoEngine
{
    TSceneInstanceState::TSceneInstanceState(const TInstantiateSceneParams& instantiateSceneParams)
    {
        mInstantiateSceneParams = instantiateSceneParams;
        
        mFileBuffer.SetData(nullptr, FILE_PART_SIZE);
        mSceneIstanceGuid = mInstantiateSceneParams.GetSceneInstanceGuid()
        if (mSceneIstanceGuid.empty()) {
            mSceneIstanceGuid = nsBase::TGuidGenerator::Generate();
        }

        mFileProgress.SetStep(FILE_PART_SIZE);
        mPrepareTreeEntityProgress.SetStep(PREPARE_TREE_ENTITY_PART_SIZE);
        mSortingProgress.SetStep(SORTING_PART_SIZE);
        mComponentDeserializingProgress.SetStep(COMPONENT_DESERIALZING_PART_SIZE);
        mEntityProgress.SetStep(ENTITY_INSTANTIATING_PART_SIZE);
        mPrefabProgress.SetStep(PREFAB_INSTANTIATING_PART_SIZE);
    }
    //--------------------------------------------------------------------------------------------------
    TSceneInstanceState::SubStep TSceneInstanceState::GetSubStep() const
    {
        TSceneInstanceState::SubStep subStep = SubStep::STABLE;
        switch (mStep) {
            case Step::INIT:
            case Step::FILE_LOADING:
            case Step::SCENE_DESERIALIZING:
            case Step::PREPARE_TREE_ENTITY:
            case Step::SORTING_ENTITIES_BY_RANK:
                subStep = SubStep::ASYNC_LOADING;
                break;
            case Step::PREPARE_INSTANTIATING:
            case Step::ENTITY_INSTANTIATING:
            case Step::PREFAB_INSTANTIATING:
                subStep = SubStep::SYNC_LOADING;
                break;
            case Step::STABLE:
                subStep = SubStep::STABLE;
                break;
            case Step::DESTROYING:
                subStep = SubStep::DESTROYING;
                break;
        }
        return subStep;
    }
    //--------------------------------------------------------------------------------------------------
    float TSceneInstanceState::GetLoadingProgress() const
    {
        return nsBase::TProgressValue::Accumulate(
            { mFileProgress, mPrepareTreeEntityProgress, mSortingProgress, mComponentDeserializingProgress, mEntityProgress, mPrefabProgress }).GetProgress();
    }
    //--------------------------------------------------------------------------------------------------
    bool TSceneInstanceState::IsLoadCompleted() const
    {
        return nsBase::TProgressValue::Accumulate(
            { mFileProgress, mPrepareTreeEntityProgress, mSortingProgress, mComponentDeserializingProgress, mEntityProgress, mPrefabProgress }).IsCompleted();
    }
    //--------------------------------------------------------------------------------------------------
    bool TSceneInstanceState::IsCancelled() const
    {
        return false;
    }
    //--------------------------------------------------------------------------------------------------
}
