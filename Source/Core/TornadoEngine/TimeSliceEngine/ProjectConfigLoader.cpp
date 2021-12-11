/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/


#include "ProjectConfigLoader.h"
#include "MakerLoaderDLL.h"
#include "TextFile.h"
#include "TornadoEngineJsonSerializer.h"
#include "PathOperations.h"

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
    if (!LoadSceneContentMap()) {
        return false;
    }
    if (!LoadPrefabContentMap()) {
        return false;
    }

    ConvertRelToAbsScene();
    ConvertRelToAbsPrefab();

    return true;
}
//----------------------------------------------------------------------
bool TProjectConfigLoader::LoadBinary()
{
    TMakerLoaderDLL maker;
    auto loader = maker.New();

    mPcc->mLoader = loader;

    if (loader->Init(mPcc->GetBinaryAbsPath().c_str()) == false) {
        Log("LoadDLL() FAIL init.\n");
        return false;
    }
    mPcc->mFreeScenePartAggregator = (FuncFreeScenePartReflectionAggregator) loader->Get(StrFreeScenePartReflectionAggregator);
    if (mPcc->mFreeScenePartAggregator == nullptr) {
        Log("LoadDLL() FAIL load FuncFree.\n");
        return false;
    }
    mPcc->mGetScenePartAggregator = (FuncGetScenePartReflectionAggregator) loader->Get(StrGetScenePartReflectionAggregator);
    if (mPcc->mGetScenePartAggregator == nullptr) {
        Log("LoadDLL() FAIL load FuncGetdevTool.\n");
        return false;
    }
    if (mPcc->mScenePartAggregator != nullptr) {
        Log("LoadDLL() warning, object was loaded.\n");
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
    return Load(mPcc->projectAbsPath, &(mPcc->mProjectConfig));
}
//------------------------------------------------------------------------
bool TProjectConfigLoader::LoadConveyor()
{
    return Load(mPcc->GetConveyorAbsPath(), &(mPcc->mConveyor));
}
//------------------------------------------------------------------------
bool TProjectConfigLoader::LoadResources()
{
    return Load(mPcc->GetResourcesAbsPath(), &(mPcc->mResources));
}
//------------------------------------------------------------------------
bool TProjectConfigLoader::LoadSceneContentMap()
{
    return Load(mPcc->GetSceneContentMapAbsPath(), &(mPcc->mSceneContentMap));
}
//------------------------------------------------------------------------
bool TProjectConfigLoader::LoadPrefabContentMap()
{
    return Load(mPcc->GetPrefabContentMapAbsPath(), &(mPcc->mPrefabContentMap));
}
//------------------------------------------------------------------------
void TProjectConfigLoader::ConvertRelToAbsScene()
{
    auto sceneContentMapAbsPath = mPcc->GetSceneContentMapAbsPath();
    auto sceneContentMapDirPath = TPathOperations::FileDirPath(sceneContentMapAbsPath);

    for (auto& guidPath : mPcc->mSceneContentMap.guidPathMap) {
        guidPath.second = TPathOperations::CalculatePathBy(sceneContentMapDirPath, guidPath.second);
    }
}
//------------------------------------------------------------------------
void TProjectConfigLoader::ConvertRelToAbsPrefab()
{
    auto prefabContentMapAbsPath = mPcc->GetPrefabContentMapAbsPath();
    auto prefabContentMapDirPath = TPathOperations::FileDirPath(prefabContentMapAbsPath);

    for (auto& guidPath : mPcc->mPrefabContentMap.guidPathMap) {
        guidPath.second = TPathOperations::CalculatePathBy(prefabContentMapDirPath, guidPath.second);
    }
}
//------------------------------------------------------------------------
