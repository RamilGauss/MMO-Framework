/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

#include "PropertyOf.h"

#include <ECS/include/IComponent.h>
#include <ImGuiWidgets/include/Frame.h>

namespace nsGuiWrapper
{
    struct DllExport TPaddingComponent : nsTornadoEngine::TPropertyOf<nsImGuiWidgets::TFrame>, nsECSFramework::IComponent
    {
        int left = 0;
        int right = 0;
        int top = 0;
        int bottom = 0;
    };
}