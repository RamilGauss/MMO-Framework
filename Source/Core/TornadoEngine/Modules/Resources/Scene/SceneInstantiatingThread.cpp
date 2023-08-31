/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "SceneInstantiatingThread.h"
#include "SceneInstanceState.h"

namespace nsTornadoEngine
{
    TSceneInstantiatingThread::TSceneInstantiatingThread(TSceneInstanceState* pSceneInstanceState)
    {
        mSceneInstanceState = pSceneInstanceState;
    }
    //---------------------------------------------------------------------------------------------------
    void TSceneInstantiatingThread::Work()
    {
        switch (mSceneInstanceState->mStep) {
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
}