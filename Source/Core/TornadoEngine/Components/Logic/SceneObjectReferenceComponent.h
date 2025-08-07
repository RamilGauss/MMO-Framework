/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "Base/Common/TypeDef.h"

#include "ECS/Include/IComponent.h"

namespace nsLogicWrapper
{
    struct DllExport TSceneObjectReferenceComponent : nsECSFramework::IComponent
    {
        std::string objectGuid;

        bool IsLess(const IComponent* pOther) const override
        {
            return objectGuid < ((TSceneObjectReferenceComponent*) pOther)->objectGuid;
        }

        bool IsEqual(const IComponent* pOther) const override
        {
            return objectGuid == ((TSceneObjectReferenceComponent*) pOther)->objectGuid;
        }
    };
}
