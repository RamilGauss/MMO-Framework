/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Constants.h"

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
}
