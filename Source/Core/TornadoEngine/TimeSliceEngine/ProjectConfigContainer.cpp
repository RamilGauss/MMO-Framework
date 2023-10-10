/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ProjectConfigContainer.h"
#include "SingletonManager.h"
#include "PathOperations.h"

static nsTornadoEngine::TProjectConfigContainer* g_ProjectPtr = nullptr;

nsTornadoEngine::TProjectConfigContainer* nsTornadoEngine::Project()
{
    return g_ProjectPtr;
}
//---------------------------------------------------------------------
void SetProject(nsTornadoEngine::TProjectConfigContainer* pProject)
{
    g_ProjectPtr = pProject;
}
//---------------------------------------------------------------------

using namespace nsTornadoEngine;
using namespace nsBase;

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
