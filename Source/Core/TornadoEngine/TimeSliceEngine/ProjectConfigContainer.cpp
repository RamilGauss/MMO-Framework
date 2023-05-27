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

nsTornadoEngine::TProjectConfigContainer* nsTornadoEngine::Project()
{
    return SingletonManager()->Get<nsTornadoEngine::TProjectConfigContainer>();
}

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
std::string TProjectConfigContainer::GetResourcesAbsPath(const std::string& guid)
{
    auto fit = mResources.resources.guidPathMap.find(guid);
    if (fit == mResources.resources.guidPathMap.end()) {
        return "";
    }

    auto resourcesFilePath = GetResourcesAbsPath();
    auto dirPath = TPathOperations::FileDirPath(resourcesFilePath);

    return TPathOperations::CalculatePathBy(dirPath, fit->second);
}
//---------------------------------------------------------------------
