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

#include "DeveloperTool_DLL.h"
#include "ProjectConfig.h"
#include "ConveyorConfig.h"

#include "FrameworkResources.h"

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
        std::string mProjectName = "project.log";

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

        template<typename ... Args>
        void Log(const char* format, Args && ... args)
        {
            std::string text = fmt::format(format, std::forward<Args>(args)...);
            
            if (mLogEvent) {
                mLogEvent(text);
            }

            nsBase::nsCommon::GetEventHub()->
                AddWarningEvent(text);
        }

        std::function<bool(const std::string&)> mLogEvent;
    };

    extern TProjectConfigContainer* Project();
    extern void SetProject(TProjectConfigContainer* pProject);
}


