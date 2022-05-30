/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

#include <ECS/include/IComponent.h>

namespace nsGraphicWrapper
{
    struct DllExport TCameraWindowPositionComponent : nsECSFramework::IComponent
    {
        float x = 0.0f;
        float y = 0.0f;
    };
}