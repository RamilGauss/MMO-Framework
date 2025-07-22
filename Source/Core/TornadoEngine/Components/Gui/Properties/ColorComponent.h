/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ECS/Include/IComponent.h"

#include "ImGuiWidgets/Include/Color.h"

namespace nsGuiWrapper
{
    struct DllExport TColorComponent : nsTornadoEngine::TPropertyOf<nsImGuiWidgets::TColor>, nsECSFramework::IComponent
    {
        float r = 0.0f;
        float g = 0.0f;
        float b = 0.0f;
        float a = 1.0f;
    };
}
