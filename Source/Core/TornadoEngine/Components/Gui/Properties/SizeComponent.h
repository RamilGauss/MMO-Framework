/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/TypeDef.h"

#include "Share/PropertyOf.h"

#include <ECS/include/IComponent.h>
#include <ImGuiWidgets/include/Size.h>

namespace nsGuiWrapper
{
    struct DllExport TSizeComponent : nsTornadoEngine::TPropertyOf<nsImGuiWidgets::TSize>, nsECSFramework::IComponent
    {
        TSizeComponent(int x, int y) : x(x), y(y) {}
        TSizeComponent() {}

        int x = 0;
        int y = 0;
    };
}