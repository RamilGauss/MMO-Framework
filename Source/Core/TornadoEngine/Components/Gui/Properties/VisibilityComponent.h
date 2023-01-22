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
#include <ImGuiWidgets/include/Widget.h>

namespace nsGuiWrapper
{
    struct DllExport TVisibilityComponent : nsTornadoEngine::TPropertyOf<nsImGuiWidgets::TWidget>, nsECSFramework::IComponent
    {
        bool value = false;

        bool IsLess(const IComponent* pOther) const override
        {
            return value < ((TVisibilityComponent*) pOther)->value;
        }

        bool IsEqual(const IComponent* pOther) const override
        {
            return value == ((TVisibilityComponent*) pOther)->value;
        }
    };
}