/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>
#include <functional>

#include <fmt/core.h>

#include "Base/Common/ILoaderDLL.h"
#include "Base/Common/GlobalEventHub.h"

#include "TornadoEngine/TimeSliceEngine/DeveloperTool_DLL.h"
#include "TornadoEngine/TimeSliceEngine/ProjectConfig.h"
#include "TornadoEngine/TimeSliceEngine/ConveyorConfig.h"
#include "TornadoEngine/TimeSliceEngine/FrameworkResources.h"

namespace nsECSFramework
{
    class TEntityManager;
}

namespace nsTornadoEngine
{
    struct TScenePartReflectionAggregator;

    class DllExport TProjectConfigContainer
    {
    public:
        std::string projectAbsPath;
        std::string projectDirAbsPath;

        // Loaded
        TProjectConfig mProjectConfig;
        TConveyorConfig mConveyor;
        TFrameworkResources mResources;

        // From binary
        FuncGetScenePartReflectionAggregator mGetScenePartAggregator = nullptr;
        FuncFreeScenePartReflectionAggregator mFreeScenePartAggregator = nullptr;

        TScenePartReflectionAggregator* mScenePartAggregator = nullptr;

        std::shared_ptr<ILoaderDLL> mLoader = nullptr;

        std::string GetBinaryAbsPath();
        std::string GetConveyorAbsPath();
        std::string GetResourcesAbsPath();
        
        void SetEntityManager(nsECSFramework::TEntityManager* pEntMng);
    };

    DllExport_C TProjectConfigContainer* Project();
    DllExport_C void SetProject(TProjectConfigContainer* pProject);
}
