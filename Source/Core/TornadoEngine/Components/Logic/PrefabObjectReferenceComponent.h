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

namespace nsLogicWrapper
{
    struct DllExport TPrefabObjectReferenceComponent : nsECSFramework::IComponent
    {
        std::string prefabGuid;
        std::string objectGuid;

        bool IsLess(const IComponent* pOther) const override
        {
            auto other = ((TPrefabObjectReferenceComponent*) pOther);
            if (prefabGuid < other->prefabGuid) {
                return true;
            } else if (prefabGuid > other->prefabGuid) {
                return false;
            }
            return objectGuid < other->objectGuid;
        }

        bool IsEqual(const IComponent* pOther) const override
        {
            auto other = ((TPrefabObjectReferenceComponent*) pOther);

            return objectGuid == other->objectGuid && prefabGuid == other->prefabGuid;
        }
    };
}