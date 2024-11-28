/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/


#include "ProjectConfigLoader.h"
#include "Base/Common/LoaderDLLFactory.h"
#include "Base/Common/TextFile.h"
#include "Generated Files/TornadoEngineJsonSerializer.h"
#include "Base/Common/PathOperations.h"

#include "TimeSliceEngine/EngineLogger.h"
#include "Modules/Resources/Common/ResourceManager.h"
#include "Modules/Common/Modules.h"

using namespace nsTornadoEngine;
using namespace nsBase;

TProjectConfigContainer* TProjectConfigLoader::mPcc = nullptr;

bool TProjectConfigLoader::Load(TProjectConfigContainer* pcc)
{
    mPcc = pcc;
    
    mPcc->projectDirAbsPath = TPathOperations::FileDirPath(mPcc->projectAbsPath);

    if (!LoadProjectConfig()) {
        return false;
    }
    if (!LoadConveyor()) {
        return false;
    }
    if (!LoadResources()) {
        return false;
    }
    if (!LoadBinary()) {
        return false;
    }

    return true;
}
//----------------------------------------------------------------------
bool TProjectConfigLoader::LoadBinary()
{
    mPcc->mLoader = MakeLoaderDLL();

    if (mPcc->mLoader->Init(mPcc->GetBinaryAbsPath().c_str()) == false) {
        Modules()->Log()->AddWarningEvent("LoadDLL() FAIL init.");
        return false;
    }
    mPcc->mFreeScenePartAggregator = (FuncFreeScenePartReflectionAggregator) mPcc->mLoader->Get(StrFreeScenePartReflectionAggregator);
    if (mPcc->mFreeScenePartAggregator == nullptr) {
        Modules()->Log()->AddWarningEvent("LoadDLL() FAIL load FuncFree.");
        return false;
    }
    mPcc->mGetScenePartAggregator = (FuncGetScenePartReflectionAggregator) mPcc->mLoader->Get(StrGetScenePartReflectionAggregator);
    if (mPcc->mGetScenePartAggregator == nullptr) {
        Modules()->Log()->AddWarningEvent("LoadDLL() FAIL load FuncGetdevTool.");
        return false;
    }
    if (mPcc->mScenePartAggregator != nullptr) {
        Modules()->Log()->AddWarningEvent("LoadDLL() warning, object was loaded.");
        return true;
    }
    mPcc->mScenePartAggregator = mPcc->mGetScenePartAggregator();
    if (mPcc->mScenePartAggregator == nullptr) {// нет DLL - нет движка.
        return false;
    }
    return true;
}
//----------------------------------------------------------------------
bool TProjectConfigLoader::LoadProjectConfig()
{
    return TResourceManager::Load(mPcc->projectAbsPath, &(mPcc->mProjectConfig));
}
//------------------------------------------------------------------------
bool TProjectConfigLoader::LoadConveyor()
{
    return TResourceManager::Load(mPcc->GetConveyorAbsPath(), &(mPcc->mConveyor));
}
//------------------------------------------------------------------------
bool TProjectConfigLoader::LoadResources()
{
    auto resourceAbsPath = mPcc->GetResourcesAbsPath();
    auto pResource = &(mPcc->mResources);
    auto res = TResourceManager::Load(resourceAbsPath, pResource);
    if (res == false) {
        return false;
    }
    auto resourceDirAbsPath = TPathOperations::FileDirPath(resourceAbsPath);
    pResource->resourcesContentMapAbsPath = TPathOperations::CalculatePathBy(resourceDirAbsPath, pResource->resourcesContentMapPath);
    pResource->prefabsContentMapAbsPath = TPathOperations::CalculatePathBy(resourceDirAbsPath, pResource->prefabsContentMapPath);
    pResource->scenesContentMapAbsPath = TPathOperations::CalculatePathBy(resourceDirAbsPath, pResource->scenesContentMapPath);
    return true;
}
//------------------------------------------------------------------------
