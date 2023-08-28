/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "SceneManager.h"

namespace nsTornadoEngine
{
    void TSceneManager::SetLoadQuant(float ms)
    {
        mLoadQuant = ms;
    }
    //--------------------------------------------------------------------------------------------------------
    float TSceneManager::GetLoadQuant() const
    {
        return mLoadQuant;
    }
    //--------------------------------------------------------------------------------------------------------
    const TSceneInstanceState& TSceneManager::GetSceneInstanceState(const std::string& sceneInstanceGuid)
    {
        return mGhostSceneInstance;
    }
    //--------------------------------------------------------------------------------------------------------
    std::string TSceneManager::InstantiateByGuid(TInstantiateSceneParams instantiateSceneParams)
    {
        return {};
    }
    //--------------------------------------------------------------------------------------------------------
    std::string TSceneManager::InstantiateByAbsPath(const TInstantiateSceneParams& instantiateSceneParams)
    {
        return {};
    }
    //--------------------------------------------------------------------------------------------------------
    void TSceneManager::Destroy(const std::string& sceneInstanceGuid)
    {

    }
    //--------------------------------------------------------------------------------------------------------
    void TSceneManager::Destroy(nsECSFramework::TEntityID anyEidInScene)
    {

    }
    //--------------------------------------------------------------------------------------------------------
    void TSceneManager::Save(const std::string& sceneGuid)
    {

    }
    //--------------------------------------------------------------------------------------------------------
    void TSceneManager::Work()
    {

    }
    //--------------------------------------------------------------------------------------------------------
    void TSceneManager::IncrementReferenceCounter(TUniverseManager::IndexType index)
    {

    }
    //--------------------------------------------------------------------------------------------------------
    void TSceneManager::DecrementReferenceCounter(TUniverseManager::IndexType index)
    {

    }
    //--------------------------------------------------------------------------------------------------------
    int TSceneManager::GetReferenceCounter(TUniverseManager::IndexType index)
    {
        return 0;
    }
    //--------------------------------------------------------------------------------------------------------
}
