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
        if (mInstantiateSceneParams.sceneInstanceGuid.empty()) {
            mInstantiateSceneParams.sceneInstanceGuid = nsBase::TGuidGenerator::Generate();
        }

        mFileProgress.SetStep(FILE_PART_SIZE);
        mPrepareTreeEntityProgress.SetStep(PREPARE_TREE_ENTITY_PART_SIZE);
        mSortingProgress.SetStep(SORTING_PART_SIZE);
        mComponentDeserializingProgress.SetStep(COMPONENT_DESERIALZING_PART_SIZE);
        mEntityProgress.SetStep(ENTITY_INSTANTIATING_PART_SIZE);
        mPrefabProgress.SetStep(PREFAB_INSTANTIATING_PART_SIZE);
    }
    //--------------------------------------------------------------------------------------------------
    ISceneInstanceState::State TSceneInstanceState::GetState() const
    {
        TSceneInstanceState::State state = TSceneInstanceState::State::INSTANTIATED;
        switch (mSubState) {
            case SubState::INIT:
            case SubState::FILE_LOADING:
            case SubState::SCENE_DESERIALIZING:
            case SubState::PREPARE_TREE_ENTITY:
            case SubState::SORTING_ENTITIES_BY_RANK:
                state = ISceneInstanceState::State::ASYNC_INSTANTIATING;
                break;
            case SubState::PREPARE_INSTANTIATING:
            case SubState::ENTITY_INSTANTIATING:
            case SubState::PREFAB_INSTANTIATING:
                state = ISceneInstanceState::State::SYNC_INSTANTIATING;
                break;
            case SubState::INSTANTIATED:
                state = ISceneInstanceState::State::INSTANTIATED;
                break;
        }
        return state;
    }
    //--------------------------------------------------------------------------------------------------
    float TSceneInstanceState::GetInstantiatingProgress() const
    {
        return nsBase::TProgressValue::Accumulate(
            { mFileProgress, mPrepareTreeEntityProgress, mSortingProgress, mComponentDeserializingProgress, mEntityProgress, mPrefabProgress }).GetProgress();
    }
    //--------------------------------------------------------------------------------------------------
    bool TSceneInstanceState::IsInstantiateCompleted() const
    {
        return nsBase::TProgressValue::Accumulate(
            { mFileProgress, mPrepareTreeEntityProgress, mSortingProgress, mComponentDeserializingProgress, mEntityProgress, mPrefabProgress }).IsCompleted();
    }
    //--------------------------------------------------------------------------------------------------
}
