/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/TypeDef.h"

#include "Share/PropertyOf.h"

#include "ECS/Include/IComponent.h"
#include <ImGuiWidgets/include/HorizontalAlign.h>

namespace nsGuiWrapper
{
    struct DllExport THorizontalAlignComponent : nsTornadoEngine::TPropertyOf<nsImGuiWidgets::THorizontalAlign>, nsECSFramework::IComponent
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