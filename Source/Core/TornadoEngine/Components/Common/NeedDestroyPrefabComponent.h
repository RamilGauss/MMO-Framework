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
    struct DllExport TNeedDestroyPrefabComponent : nsECSFramework::IComponent
    {
        std::string prefabInstanceGuid;

        bool IsLess(const IComponent* pOther) const override
        {
            return prefabInstanceGuid < ((TNeedDestroyPrefabComponent*) pOther)->prefabInstanceGuid;
        }

        bool IsEqual(const IComponent* pOther) const override
        {
            return prefabInstanceGuid == ((TNeedDestroyPrefabComponent*) pOther)->prefabInstanceGuid;
        }
    };
}