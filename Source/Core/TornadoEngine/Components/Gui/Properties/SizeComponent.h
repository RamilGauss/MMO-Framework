/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/TypeDef.h"

#include "TornadoEngine/Share/PropertyOf.h"

#include "ECS/Include/IComponent.h"
#include "ImGuiWidgets/Include/Size.h"

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