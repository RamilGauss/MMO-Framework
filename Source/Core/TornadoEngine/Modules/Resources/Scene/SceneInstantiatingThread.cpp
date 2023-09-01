/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <filesystem>

#include "SceneInstantiatingThread.h"
#include "SceneInstanceState.h"

namespace nsTornadoEngine
{
    TSceneInstantiatingThread::TSceneInstantiatingThread(TSceneInstanceState* pSceneInstanceState)
    {
        mScState = pSceneInstanceState;
    }
    //---------------------------------------------------------------------------------------------------
    void TSceneInstantiatingThread::Work()
    {
        switch (mScState->mStep) {
            case TSceneInstanceState::Step::INIT:
                Init();
                break;
            case TSceneInstanceState::Step::FILE_LOADING:
                FileLoading();
                break;
            case TSceneInstanceState::Step::SCENE_DESERIALIZING:
                SceneDeserializing();
                break;
            case TSceneInstanceState::Step::COMPONENTS_DESERIALIZING:
                ComponentsDeserializing();
                break;
            case TSceneInstanceState::Step::SORTING_ENTITIES_BY_RANK:
                SortingEntitiesByRank();
                break;
            default:;
        }
    }
    //---------------------------------------------------------------------------------------------------
    void TSceneInstantiatingThread::Init()
    {
        namespace fs = std::filesystem;

        mScState->mInstantiateSceneParams.absPath;

        std::error_code ec;
        std::uintmax_t size = fs::file_size({ mScState->mInstantiateSceneParams.absPath }, ec);

        mScState->mFileProgress.IncrementTotal(size);

        if (size >= TSceneInstanceState::FILE_PART_SIZE) {
            CalculateRoughProgressValues();
        }

        mScState->mStep = TSceneInstanceState::Step::FILE_LOADING;
    }
    //---------------------------------------------------------------------------------------------------
    void TSceneInstantiatingThread::FileLoading()
    {
        //mSceneInstanceState->mPartCount
    }
    //---------------------------------------------------------------------------------------------------
    void TSceneInstantiatingThread::SceneDeserializing()
    {

    }
    //---------------------------------------------------------------------------------------------------
    void TSceneInstantiatingThread::ComponentsDeserializing()
    {

    }
    //---------------------------------------------------------------------------------------------------
    void TSceneInstantiatingThread::SortingEntitiesByRank()
    {

    }
    //---------------------------------------------------------------------------------------------------
    void TSceneInstantiatingThread::CalculateRoughProgressValues()
    {
        mScState->mFileProgress.GetTotal();
        nsBase::TProgressValue mComponentProgress;
        nsBase::TProgressValue mSortingProgress;
        nsBase::TProgressValue mEntityProgress;
        nsBase::TProgressValue mPrefabProgress;
    }
    //---------------------------------------------------------------------------------------------------
}