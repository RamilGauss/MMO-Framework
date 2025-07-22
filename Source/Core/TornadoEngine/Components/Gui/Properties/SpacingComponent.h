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
#include <ImGuiWidgets/include/Spacing.h>

namespace nsGuiWrapper
{
    struct DllExport TSpacingComponent : nsTornadoEngine::TPropertyOf<nsImGuiWidgets::TSpacing>, nsECSFramework::IComponent
    {
        int value = 0;
    };
}