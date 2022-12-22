/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <set>
#include <string>

#include <ECS/include/IComponent.h>

namespace nsContainerCodeGenerator
{
    struct DllExport TCoreHandlerListComponent : nsECSFramework::IComponent
    {
        std::set<std::string> value;
    };
}