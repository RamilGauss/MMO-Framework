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
#include <ImGuiWidgets/include/Position.h>

namespace nsGuiWrapper
{
    struct DllExport TPositionComponent : nsTornadoEngine::TPropertyOf<nsImGuiWidgets::TPosition>, nsECSFramework::IComponent
    {
        int x = 0;
        int y = 0;

        bool IsLess(const IComponent* pOther) const override
        {
            if (x < ((TPositionComponent*) pOther)->x) {
                return false;
            }

            if (x == ((TPositionComponent*) pOther)->x) {
                return y < ((TPositionComponent*) pOther)->y;
            }

            return true;
        }

        bool IsEqual(const IComponent* pOther) const override
        {
            return x == ((TPositionComponent*) pOther)->x && y == ((TPositionComponent*) pOther)->y;
        }
    };
}