/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <filesystem>

#include "SceneInstantiatingThread.h"
#include "SceneInstanceState.h"
#include "TornadoEngineJsonSerializer.h"

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

        mScState->mFile.ReOpen((char*)mScState->mInstantiateSceneParams.absPath.c_str());

        auto size = mScState->mFile.Size();

        mScState->mFileProgress.SetTotal(size);
        mScState->mFileContent.reserve(size);

        CalculateRoughProgressValues();

        mScState->mStep = TSceneInstanceState::Step::FILE_LOADING;
    }
    //---------------------------------------------------------------------------------------------------
    void TSceneInstantiatingThread::FileLoading()
    {
        int partSize = mScState->mFileProgress.GetSteppedRemain();

        mScState->mFile.Read(mScState->mFileBuffer.GetPtr(), partSize, mScState->mFileProgress.GetValue());

        mScState->mFileContent.append(mScState->mFileBuffer.GetPtr(), partSize);
        mScState->mFileProgress.IncrementValue(partSize);

        if (mScState->mFileProgress.IsCompleted()) {
            mScState->mFile.Close();
            mScState->mStep = TSceneInstanceState::Step::SCENE_DESERIALIZING;
        }
    }
    //---------------------------------------------------------------------------------------------------
    void TSceneInstantiatingThread::SceneDeserializing()
    {
        std::string err;
        auto deserResult = TTornadoEngineJsonSerializer::Deserialize(&mScState->mSceneContent, mScState->mFileContent, err);

        CalculateAccurateProgressValues();

        mScState->mStep = TSceneInstanceState::Step::COMPONENTS_DESERIALIZING;
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
    void TSceneInstantiatingThread::CalculateAccurateProgressValues()
    {
        int componentCount = 0;
        for (auto& entity : mScState->mSceneContent.entities) {
            componentCount += entity.components.size();
        }

        mScState->mComponentProgress.SetTotal(componentCount);
        mScState->mSortingProgress.SetTotal(mScState->mSceneContent.entities.size());
        mScState->mEntityProgress.SetTotal(mScState->mSceneContent.entities.size());
        mScState->mPrefabProgress.SetTotal(mScState->mSceneContent.prefabInstances.size());
    }
    //---------------------------------------------------------------------------------------------------
    void TSceneInstantiatingThread::CalculateRoughProgressValues()
    {
        auto fileSize = mScState->mFileProgress.GetTotal();

        int componentCount = fileSize / 187.0f;
        int entityCount = fileSize / 1312.0f;

        mScState->mComponentProgress.SetTotal(componentCount);
        mScState->mSortingProgress.SetTotal(entityCount);
        mScState->mEntityProgress.SetTotal(entityCount);
        mScState->mPrefabProgress.SetTotal(1);
    }
    //---------------------------------------------------------------------------------------------------
}