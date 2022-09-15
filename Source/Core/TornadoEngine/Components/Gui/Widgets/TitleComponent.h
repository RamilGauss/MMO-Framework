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
    struct DllExport TTitleComponent : nsECSFramework::IComponent
    {
        std::string value;

        bool IsLess(const IComponent* pOther) const override
        {
            return value < ((TTitleComponent*) pOther)->value;
        }

        bool IsEqual(const IComponent* pOther) const override
        {
            return value == ((TTitleComponent*) pOther)->value;
        }
    };
}