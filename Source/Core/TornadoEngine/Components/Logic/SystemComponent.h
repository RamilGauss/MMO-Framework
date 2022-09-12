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
#include <ECS/include/System.h>

namespace nsLogicWrapper
{
    struct DllExport TSystemComponent : nsECSFramework::IComponent
    {
        std::string typeName;

#pragma IGNORE_ATTRIBUTE
        mutable nsECSFramework::TSystem* value = nullptr;

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