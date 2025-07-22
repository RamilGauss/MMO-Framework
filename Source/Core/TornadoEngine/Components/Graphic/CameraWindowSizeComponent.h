/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/TypeDef.h"

#include "ECS/Include/IComponent.h"

namespace nsGraphicWrapper
{
    struct DllExport TCameraWindowSizeComponent : nsECSFramework::IComponent
    {
        float x = 1.0f;
        float y = 1.0f;
    };
}