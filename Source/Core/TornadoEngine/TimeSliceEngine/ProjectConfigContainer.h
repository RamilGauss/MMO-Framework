/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>
#include "ILoaderDLL.h"

#include "ProjectConfig.h"
#include "ScenePartReflectionAggregator.h"
#include "DeveloperTool_DLL.h"
#include "ConveyorConfig.h"
#include "FrameworkResources.h"

#include "ResourceContentMap.h"

namespace nsTornadoEngine
{
    class DllExport TProjectConfigContainer
    {
    public:
        std::string projectAbsPath;
        std::string projectDirAbsPath;

        // Loaded
        TProjectConfig mProjectConfig;
        TConveyorConfig mConveyor;
        TFrameworkResources mResources;
        TResourceContentMap mSceneContentMap;
        TResourceContentMap mPrefabContentMap;

        // From binary
        FuncGetScenePartReflectionAggregator mGetScenePartAggregator = nullptr;
        FuncFreeScenePartReflectionAggregator mFreeScenePartAggregator = nullptr;

        TScenePartReflectionAggregator* mScenePartAggregator = nullptr;

        ILoaderDLL* mLoader = nullptr;

        std::string GetBinaryAbsPath();
        std::string GetConveyorAbsPath();
        std::string GetResourcesAbsPath();
        
        std::string GetSceneContentMapAbsPath();
        std::string GetPrefabContentMapAbsPath();

        std::string GetResourcesAbsPath(const std::string& guid);
    };

    extern TProjectConfigContainer* Project();
}


