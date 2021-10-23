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
#include "ScenePartContainer.h"
#include "DeveloperTool_DLL.h"
#include "ConveyorConfig.h"
#include "FrameworkResources.h"

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

        // From binary
        FuncGetScenePartContainer mGetScenePartContainer = nullptr;
        FuncFreeScenePartContainer mFreeScenePartContainer = nullptr;

        TScenePartContainer* mScenePartContainer = nullptr;

        ILoaderDLL* mLoader = nullptr;

        std::string GetBinaryAbsPath();
        std::string GetConveyorAbsPath();
        std::string GetResourcesAbsPath();
    };

    extern TProjectConfigContainer* Project();
}


