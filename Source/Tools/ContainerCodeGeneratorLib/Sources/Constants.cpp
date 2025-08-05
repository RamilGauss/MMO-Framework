/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <fmt/core.h>

#include "ContainerCodeGeneratorLib/Sources/Constants.h"

namespace nsContainerCodeGenerator
{
    const std::set<std::string> TConstants::GetHeaderExtensions()
    {
        return { ".h", ".hpp", ".hh", ".hxx", ".h++" };
    }

    const std::set<std::string> TConstants::GetSystemInheritances()
    {
        return
        {
            "nsECSFramework::TFeature",
            "nsECSFramework::TInitSystem",
            "nsECSFramework::TExecuteSystem",
            "nsECSFramework::TTearDownSystem",
            "nsECSFramework::TOnAddCollectReactiveSystem",
            "nsECSFramework::TOnUpdateCollectReactiveSystem",
            "nsECSFramework::TOnAddInstantReactiveSystem",
            "nsECSFramework::TOnUpdateInstantReactiveSystem",
            "nsECSFramework::TOnRemoveInstantReactiveSystem"
        };
    }

    const std::string TConstants::GetHeader()
    {
        return 
            "/*\n"
            "Author: Gudakov Ramil Sergeevich a.k.a.Gauss\n"
            "Гудаков Рамиль Сергеевич\n"
            "Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]\n"
            "See for more information LICENSE.md.\n"
            "*/\n";
    }

    const std::string TConstants::GetProgramName()
    {
        return "ContainerCodeGenerator";
    }

    const std::string TConstants::GetProgramDescription()
    {
        return fmt::format("{} {}.{}.{}", GetProgramName(),
            GetProgramMajorVersion(), GetProgramMinorVersion(), GetProgramJuniorVersion());
    }

    const int TConstants::GetProgramMajorVersion()
    {
        return 1;
    }
    
    const int TConstants::GetProgramMinorVersion()
    {
        return 0;
    }
    
    const int TConstants::GetProgramJuniorVersion()
    {
        return 0;
    }

}
