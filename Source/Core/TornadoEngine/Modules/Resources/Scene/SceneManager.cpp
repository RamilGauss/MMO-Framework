/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/


#include "Base/Common/HiTimer.h"
#include "Base/Common/TextFile.h"
#include "Base/Common/Logger.h"
#include "Base/Common/GuidGenerator.h"

#include "TornadoEngine/GeneratedFiles/TornadoEngineJsonSerializer.h"
#include "TornadoEngine/TimeSliceEngine/ProjectConfigContainer.h"

#include "TornadoEngine/Modules/Common/Modules.h"
#include "TornadoEngine/Modules/Resources/Common/HandlerCallCollector.h"
#include "TornadoEngine/Modules/Resources/Prefab/PrefabManager.h"
#include "TornadoEngine/Modules/Resources/Scene/StateGraph/SceneStateGraph.h"
#include "TornadoEngine/Modules/Resources/Scene/StateGraph/SceneContext.h"
#include "TornadoEngine/Modules/Resources/Scene/SceneManager.h"

#include "TornadoEngine/Components/Meta/GuidComponent.h"
#include "TornadoEngine/Components/Meta/ParentGuidComponent.h"
#include "TornadoEngine/Components/Meta/SceneOriginalGuidComponent.h"
#include "TornadoEngine/Components/Meta/SceneInstanceGuidComponent.h"
#include "TornadoEngine/Components/Meta/NeedDestroyObjectTagComponent.h"
#include "TornadoEngine/Components/Meta/SceneRootComponent.h"
#include "TornadoEngine/Components/Meta/SceneGuidComponent.h"
#include "TornadoEngine/Components/Meta/UniverseIndexComponent.h"
#include "TornadoEngine/Components/Meta/UniverseGuidComponent.h"

#include "TornadoEngine/ReflectionAggregators/ScenePartReflectionAggregator.h"

namespace nsTornadoEngine
{
    TSceneManager::TSceneManager()
    {
        mSceneStateGraph = std::make_shared<TSceneStateGraph>();
        mSceneStateGraph->Init();

        auto componentReflection = nsTornadoEngine::Project()->mScenePartAggregator->mComponents;

        auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();

        mGuidComponentRtti = globalTypeIdentifier->Type<nsCommonWrapper::TGuidComponent>();
        mParentGuidComponentRtti = globalTypeIdentifier->Type<nsCommonWrapper::TParentGuidComponent>();
        mSceneRootComponentRtti = globalTypeIdentifier->Type<nsCommonWrapper::TSceneRootComponent>();

        componentReflection->mRtti->ConvertTypeToName(mGuidComponentRtti, mGuidComponentTypeName);
        componentReflection->mRtti->ConvertTypeToName(mParentGuidComponentRtti, mParentGuidComponentTypeName);
        componentReflection->mRtti->ConvertTypeToName(mSceneRootComponentRtti, mSceneRootComponentTypeName);
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
    std::optional<TSceneState> TSceneManager::GetState(const std::string& sceneInstanceGuid)
    {
        auto fit = mSceneInstances.find(sceneInstanceGuid);
        if (fit == mSceneInstances.end()) {
            return std::nullopt;
        }
        auto pCtx = fit->second;

        TSceneState sceneState;
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
            nsTornadoEngine::Modules()->CoreLog()->AddWarningEvent("Guid \"{}\" not exist", instantiateSceneParams.guid);
            return "Not found";
        }

        auto sceneCtx = std::make_shared<TSceneContext>();
        sceneCtx->instantiateSceneParams = instantiateSceneParams;
        if (sceneCtx->instantiateSceneParams.sceneInstanceGuid.empty()) {
            sceneCtx->instantiateSceneParams.sceneInstanceGuid = nsBase::nsCommon::TGuidGenerator::Generate();
        }
        sceneCtx->sceneAbsPath = absPath;

        sceneCtx->guidComponentRtti = mGuidComponentRtti;
        sceneCtx->garentGuidComponentRtti = mParentGuidComponentRtti;
        sceneCtx->sceneRootComponentRtti = mSceneRootComponentRtti;
        sceneCtx->guidComponentTypeName = mGuidComponentTypeName;
        sceneCtx->parentGuidComponentTypeName = mParentGuidComponentTypeName;
        sceneCtx->sceneRootComponentTypeName = mSceneRootComponentTypeName;
        sceneCtx->universeManager = &mUniverseManager;
        sceneCtx->cacheManager = &mSceneCacheMng;
        sceneCtx->entityManager = mEntityManager;
        sceneCtx->prefabMng = mPrefabMng;

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
    void TSceneManager::SetPrefabManager(TPrefabManager* pPrefabMng)
    {
        mPrefabMng = pPrefabMng;
    }
    //--------------------------------------------------------------------------------------------------------
}
