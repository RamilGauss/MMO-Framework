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
    struct DllExport TMinSizeComponent : nsTornadoEngine::TPropertyOf<nsImGuiWidgets::TUnit>, nsECSFramework::IComponent
    {
        int x = 0;
        int y = 0;

        bool IsLess(const IComponent* pOther) const override
        {
            if (x < ((TMinSizeComponent*)pOther)->x) {
                return false;
            }

            if (x == ((TMinSizeComponent*)pOther)->x) {
                return y < ((TMinSizeComponent*)pOther)->y;
            }

            return true;
        }

        bool IsEqual(const IComponent* pOther) const override
        {
            return x == ((TMinSizeComponent*)pOther)->x && y == ((TMinSizeComponent*)pOther)->y;
        }
    };
}