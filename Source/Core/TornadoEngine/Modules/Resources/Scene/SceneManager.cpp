/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Modules/Resources/Scene/SceneManager.h"

#include "Base/Common/HiTimer.h"
#include "Base/Common/TextFile.h"
#include "Base/Common/Logger.h"
#include "Base/Common/GuidGenerator.h"

#include "Generated Files/TornadoEngineJsonSerializer.h"
#include "TimeSliceEngine/EngineLogger.h"
#include "TimeSliceEngine/ProjectConfigContainer.h"

#include "Modules/Common/Modules.h"
#include "Modules/Resources/Common/HandlerCallCollector.h"
#include "Modules/Resources/Prefab/PrefabManager.h"
#include "Modules/Resources/Scene/StateGraph/SceneStateGraph.h"
#include "Modules/Resources/Scene/StateGraph/SceneContext.h"

#include "Components/Meta/GuidComponent.h"
#include "Components/Meta/ParentGuidComponent.h"
#include "Components/Meta/SceneOriginalGuidComponent.h"
#include "Components/Meta/SceneInstanceGuidComponent.h"
#include "Components/Meta/NeedDestroyObjectTagComponent.h"
#include "Components/Meta/SceneRootComponent.h"
#include "Components/Meta/SceneGuidComponent.h"
#include "Components/Meta/UniverseIndexComponent.h"
#include "Components/Meta/UniverseGuidComponent.h"

namespace nsTornadoEngine
{
    TSceneManager::TSceneManager()
    {
        mSceneStateGraph = std::make_shared<TSceneStateGraph>();
        mSceneStateGraph->Init();
    }
    //--------------------------------------------------------------------------------------------------------
    std::string TSceneManager::Create(const std::string& absPath)
    {
        auto guid = TResourceManager::Create(absPath);

        TSceneResourceContent sceneResourceContent;
        TResourceManager::Save(absPath, &sceneResourceContent);

        return guid;
    }
    //--------------------------------------------------------------------------------------------------------
    void TSceneManager::SetLoadQuant(int ms)
    {
        mLoadQuant = ms;
    }
    //--------------------------------------------------------------------------------------------------------
    int TSceneManager::GetLoadQuant() const
    {
        return mLoadQuant;
    }
    //--------------------------------------------------------------------------------------------------------
    std::optional<TSceneManager::TScenaState> TSceneManager::GetState(const std::string& sceneInstanceGuid)
    {
        auto fit = mSceneInstances.find(sceneInstanceGuid);
        if (fit == mSceneInstances.end()) {
            return std::nullopt;
        }
        auto pCtx = fit->second;

        TScenaState sceneState;
        auto progress = mSceneStateGraph->GetSceneInstanceState(pCtx);
        if (progress) {
            sceneState.inProcess = true;
            sceneState.progress = *progress;
        }
        auto zoneName = mSceneStateGraph->GetZoneName(pCtx);
        if (zoneName) {
            sceneState.zoneName = *zoneName;
            return { sceneState };
        }
        return std::nullopt;
    }
    //--------------------------------------------------------------------------------------------------------
    std::string TSceneManager::Instantiate(const TInstantiateSceneParams& instantiateSceneParams)
    {
        // Convert to abs path
        auto absPath = GetAbsPath(instantiateSceneParams.guid);
        if (absPath.empty()) {
            nsTornadoEngine::Modules()->Log()->AddWarningEvent("Guid \"{}\" not exist", instantiateSceneParams.guid);
            return "Not found";
        }

        auto sceneCtx = std::make_shared<TSceneContext>();
        sceneCtx->instantiateSceneParams = instantiateSceneParams;
        if (sceneCtx->instantiateSceneParams.sceneInstanceGuid.empty()) {
            sceneCtx->instantiateSceneParams.sceneInstanceGuid = nsBase::nsCommon::TGuidGenerator::Generate();
        }
        sceneCtx->sceneAbsPath = absPath;



        mSceneInstances.insert({ sceneCtx->instantiateSceneParams.sceneInstanceGuid, sceneCtx });
        mSceneStateGraph->StartProcess(TSceneStateGraph::Process::INSTANTIATE, sceneCtx);
        return sceneCtx->instantiateSceneParams.sceneInstanceGuid;
    }
    //--------------------------------------------------------------------------------------------------------
    void TSceneManager::Destroy(const std::string& sceneInstanceGuid)
    {

    }
    //--------------------------------------------------------------------------------------------------------
    void TSceneManager::Save(const std::string& sceneInstanceGuid)
    {

    }
    //--------------------------------------------------------------------------------------------------------
    void TSceneManager::Work()
    {
        mSceneStateGraph->Work(GetLoadQuant());
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
    void TSceneManager::SetSceneCacheManager(TSceneCacheManager* pSceneCachebMng)
    {
        mSceneCacheMng = pSceneCachebMng;
    }
    //--------------------------------------------------------------------------------------------------------
}
