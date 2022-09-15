/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

#include <ECS/include/IComponent.h>

namespace nsGuiWrapper
{
    struct DllExport TSizeComponent : nsECSFramework::IComponent
    {
        int x = 0;
        int y = 0;

        bool IsLess(const IComponent* pOther) const override
        {
            if (x < ((TSizeComponent*) pOther)->x) {
                return false;
            }

            if (x == ((TSizeComponent*) pOther)->x) {
                return y < ((TSizeComponent*) pOther)->y;
            }

            return true;
        }

        bool IsEqual(const IComponent* pOther) const override
        {
            return x == ((TSizeComponent*) pOther)->x && y == ((TSizeComponent*) pOther)->y;
        }
    };
}