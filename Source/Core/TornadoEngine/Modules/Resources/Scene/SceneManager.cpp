/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "SceneManager.h"

#include "TextFile.h"
#include "Logger.h"
#include "TimeSliceEngine.h"
#include "TornadoEngineJsonSerializer.h"
#include "ProjectConfigContainer.h"

#include "GuidComponent.h"
#include "ParentGuidComponent.h"
#include "SceneOriginalGuidComponent.h"
#include "SceneInstanceGuidComponent.h"
#include "NeedDestroyObjectTagComponent.h"
#include "SceneRootComponent.h"
#include "SceneGuidComponent.h"

#include "GuidGenerator.h"

#include "UniverseIndexComponent.h"
#include "UniverseGuidComponent.h"

namespace nsTornadoEngine
{
    TSceneManager::TSceneManager() : mGhostSceneInstance({})
    {

    }
    //--------------------------------------------------------------------------------------------------------
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
        auto fit = mSceneInstances.find(sceneInstanceGuid);
        if (fit == mSceneInstances.end()) {
            return mGhostSceneInstance;
        }

        return fit->second;
    }
    //--------------------------------------------------------------------------------------------------------
    std::string TSceneManager::InstantiateByGuid(TInstantiateSceneParams instantiateSceneParams)
    {
        // Convert to abs path
        auto fit = mResourceContentMap.guidPathMap.find(instantiateSceneParams.guid);
        if (fit == mResourceContentMap.guidPathMap.end()) {
            GetLogger()->Get(TTimeSliceEngine::NAME)->WriteF_time("Guid \"%s\" not exist", instantiateSceneParams.guid.c_str());
            return "Not found";
        }

        instantiateSceneParams.absPath = fit->second;
        return InstantiateByAbsPath(instantiateSceneParams);
    }
    //--------------------------------------------------------------------------------------------------------
    std::string TSceneManager::InstantiateByAbsPath(const TInstantiateSceneParams& instantiateSceneParams)
    {
        TSceneInstanceState sceneInstanceState(instantiateSceneParams);

        mSceneInstances.insert({ sceneInstanceState.GetGuid(), sceneInstanceState });

        return sceneInstanceState.GetGuid();
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
        for (auto& sceneInstance : mSceneInstances) {
            sceneInstance.second.Work();
        }
    }
    //--------------------------------------------------------------------------------------------------------
    void TSceneManager::IncrementReferenceCounter(TUniverseManager::IndexType index)
    {
        mReferenceCounters[index].counter++;
    }
    //--------------------------------------------------------------------------------------------------------
    void TSceneManager::DecrementReferenceCounter(TUniverseManager::IndexType index)
    {
        mReferenceCounters[index].counter--;

        BL_ASSERT(mReferenceCounters[index].counter >= 0);
    }
    //--------------------------------------------------------------------------------------------------------
    int TSceneManager::GetReferenceCounter(TUniverseManager::IndexType index)
    {
        return mReferenceCounters[index].counter;
    }
    //--------------------------------------------------------------------------------------------------------
    void TSceneManager::SetPrefabManager(TPrefabManager* pPrefabMng)
    {
        mPrefabMng = pPrefabMng;
    }
    //--------------------------------------------------------------------------------------------------------
}
