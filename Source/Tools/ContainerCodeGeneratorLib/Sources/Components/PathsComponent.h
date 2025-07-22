/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "ECS/Include/IComponent.h"

namespace nsContainerCodeGenerator
{
    struct DllExport TPathsComponent : nsECSFramework::IComponent
    {
        mutable std::string absPathDirJson;
        mutable std::string absPathJsonFile;
    };
}