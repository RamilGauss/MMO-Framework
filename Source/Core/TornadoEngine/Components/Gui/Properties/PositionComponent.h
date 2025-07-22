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
#include "ImGuiWidgets/Include/Position.h"

namespace nsGuiWrapper
{
    struct DllExport TPositionComponent : nsTornadoEngine::TPropertyOf<nsImGuiWidgets::TPosition>, nsECSFramework::IComponent
    {
        TPositionComponent(int x, int y) : x(x), y(y) {}
        TPositionComponent() {}

        int x = 0;
        int y = 0;
    };
}