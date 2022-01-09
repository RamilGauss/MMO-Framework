/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "TypeDef.h"

#include <ECS/include/IComponent.h>
#include <ECS/include/Feature.h>

namespace nsLogicWrapper
{
    struct DllExport TSystemComponent : nsECSFramework::IComponent
    {
#pragma IGNORE_ATTRIBUTE
        mutable nsECSFramework::TFeature* value = nullptr;

        std::string typeName;

        bool IsLess(const IComponent* pOther) const override
        {
            return typeName < ((TSystemComponent*) pOther)->typeName;
        }

        bool IsEqual(const IComponent* pOther) const override
        {
            return typeName == ((TSystemComponent*) pOther)->typeName;
        }
    };
}