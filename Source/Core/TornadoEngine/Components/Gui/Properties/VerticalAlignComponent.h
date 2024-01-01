/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/TypeDef.h"

#include "PropertyOf.h"

#include <ECS/include/IComponent.h>
#include <ImGuiWidgets/include/VerticalAlign.h>

namespace nsGuiWrapper
{
    struct DllExport TVerticalAlignComponent : nsTornadoEngine::TPropertyOf<nsImGuiWidgets::TVerticalAlign>, nsECSFramework::IComponent
    {
        enum class Type
        {
            LEFT,
            CENTER,
            RIGHT,
        };
        Type value = Type::CENTER;
    };
}