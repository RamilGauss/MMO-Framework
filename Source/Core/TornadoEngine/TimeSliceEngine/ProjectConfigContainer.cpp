/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Common/SingletonManager.h"
#include "Base/Common/PathOperations.h"

#include "TornadoEngine/TimeSliceEngine/ProjectConfigContainer.h"
#include "TornadoEngine/ReflectionAggregators/ScenePartReflectionAggregator.h"

static nsTornadoEngine::TProjectConfigContainer* g_ProjectPtr = nullptr;

nsTornadoEngine::TProjectConfigContainer* nsTornadoEngine::Project()
{
    return g_ProjectPtr;
}
//---------------------------------------------------------------------
void nsTornadoEngine::SetProject(nsTornadoEngine::TProjectConfigContainer* pProject)
{
    g_ProjectPtr = pProject;
}
//---------------------------------------------------------------------

using namespace nsTornadoEngine;
using namespace nsBase::nsCommon;

std::string TProjectConfigContainer::GetBinaryAbsPath()
{
    return TPathOperations::CalculatePathBy(projectDirAbsPath, mProjectConfig.binaryFilePath);
}
//---------------------------------------------------------------------
std::string TProjectConfigContainer::GetConveyorAbsPath()
{
    return TPathOperations::CalculatePathBy(projectDirAbsPath, mProjectConfig.conveyorFilePath);
}
//---------------------------------------------------------------------
std::string TProjectConfigContainer::GetResourcesAbsPath()
{
    return TPathOperations::CalculatePathBy(projectDirAbsPath, mProjectConfig.resourcesFilePath);
}
//---------------------------------------------------------------------
void TProjectConfigContainer::SetEntityManager(nsECSFramework::TEntityManager* pEntMng)
{
    mScenePartAggregator->mComponents->mEntMng->SetEntityManager(pEntMng);
}
//---------------------------------------------------------------------
