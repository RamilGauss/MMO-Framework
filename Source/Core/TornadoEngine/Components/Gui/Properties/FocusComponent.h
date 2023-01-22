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
#include <ImGuiWidgets/include/Unit.h>

namespace nsGuiWrapper
{
    struct DllExport TFocusComponent : nsTornadoEngine::TPropertyOf<nsImGuiWidgets::TUnit>, nsECSFramework::IComponent
    {
        bool value = false;
    };
}