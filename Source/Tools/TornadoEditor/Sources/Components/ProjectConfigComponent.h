/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "TypeDef.h"

#include <ECS/include/IComponent.h>

#include "ProjectConfig.h"

namespace nsTornadoEditor
{
    struct DllExport TProjectConfigComponent : nsECSFramework::IComponent
    {
        // Not use directly!
#pragma IGNORE_ATTRIBUTE
        mutable nsTornadoEngine::TProjectConfig value;
    };
}