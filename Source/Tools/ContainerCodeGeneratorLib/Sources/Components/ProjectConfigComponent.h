/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ECS/Include/IComponent.h"
#include "Config.h"

namespace nsContainerCodeGenerator
{
    struct DllExport TProjectConfigComponent : nsECSFramework::IComponent
    {
        mutable TProjectContainerConfig value;
    };
}
