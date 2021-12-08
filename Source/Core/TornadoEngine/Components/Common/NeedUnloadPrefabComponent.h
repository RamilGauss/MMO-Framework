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

namespace nsCommonWrapper
{
    struct DllExport TNeedUnloadPrefabComponent : nsECSFramework::IComponent
    {
        std::string prefabGuid;

        bool IsLess(const IComponent* pOther) const override
        {
            return prefabGuid < ((TNeedUnloadPrefabComponent*) pOther)->prefabGuid;
        }

        bool IsEqual(const IComponent* pOther) const override
        {
            return prefabGuid == ((TNeedUnloadPrefabComponent*) pOther)->prefabGuid;
        }
    };
}