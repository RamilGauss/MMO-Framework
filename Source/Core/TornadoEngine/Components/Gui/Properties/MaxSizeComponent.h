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
#include <ImGuiWidgets/include/MaxSize.h>

namespace nsGuiWrapper
{
    struct DllExport TMaxSizeComponent : nsTornadoEngine::TPropertyOf<nsImGuiWidgets::TMaxSize>, nsECSFramework::IComponent
    {
        int x = 0;
        int y = 0;

        bool IsLess(const IComponent* pOther) const override
        {
            if (x < ((TMaxSizeComponent*)pOther)->x) {
                return false;
            }

            if (x == ((TMaxSizeComponent*)pOther)->x) {
                return y < ((TMaxSizeComponent*)pOther)->y;
            }

            return true;
        }

        bool IsEqual(const IComponent* pOther) const override
        {
            return x == ((TMaxSizeComponent*)pOther)->x && y == ((TMaxSizeComponent*)pOther)->y;
        }
    };
}