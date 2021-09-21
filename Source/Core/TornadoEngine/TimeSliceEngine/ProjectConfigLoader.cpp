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
    mPcc->mFreeScenePartsContainer = (FuncFreeScenePartsContainer) loader->Get(StrFreeScenePartsContainer);
    if (mPcc->mFreeScenePartsContainer == nullptr) {
        Log("LoadDLL() FAIL load FuncFree.\n");
        return false;
    }
    mPcc->mGetScenePartsContainer = (FuncGetScenePartsContainer) loader->Get(StrGetScenePartsContainer);
    if (mPcc->mGetScenePartsContainer == nullptr) {
        Log("LoadDLL() FAIL load FuncGetdevTool.\n");
        return false;
    }
    if (mPcc->mScenePartsContainer != nullptr) {
        Log("LoadDLL() warning, object was loaded.\n");
        return true;
    }
    mPcc->mScenePartsContainer = mPcc->mGetScenePartsContainer();
    if (mPcc->mScenePartsContainer == nullptr) {// нет DLL - нет движка.
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