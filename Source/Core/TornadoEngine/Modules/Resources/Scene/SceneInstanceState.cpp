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
        mGuid = nsBase::TGuidGenerator::Generate();
        mInstantiateSceneParams = instantiateSceneParams;
    }
    //--------------------------------------------------------------------------------------------------
    TSceneInstanceState::SubStep TSceneInstanceState::GetSubStep() const
    {
        TSceneInstanceState::SubStep subStep = SubStep::STABLE;
        switch (mStep) {
            case Step::FILE_LOADING:
            case Step::SCENE_DESERIALIZING:
            case Step::COMPONENTS_DESERIALIZING:
            case Step::SORTING_ENTITY_BY_RANK:
                subStep = SubStep::ASYNC_LOADING;
                break;
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
        return 0.0f;
    }
    //--------------------------------------------------------------------------------------------------
}
