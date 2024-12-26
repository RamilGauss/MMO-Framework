/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "Base/Common/TypeDef.h"

#include <ECS/include/IComponent.h>

namespace nsLogicWrapper
{
    struct DllExport TReferenceHandlerComponent : nsECSFramework::IComponent
    {
        std::string entityGuid;
        std::string handlerTypeName;

#pragma IGNORE_ATTRIBUTE
        mutable void* handler = nullptr;

        bool IsLess(const IComponent* pOther) const override
        {
            if (handlerTypeName < ((TReferenceHandlerComponent*)pOther)->handlerTypeName) {
                return false;
            } else if (handlerTypeName > ((TReferenceHandlerComponent*)pOther)->handlerTypeName) {
                return true;
            }

            return (entityGuid == ((TReferenceHandlerComponent*)pOther)->entityGuid);
        }

        bool IsEqual(const IComponent* pOther) const override
        {
            return ((entityGuid == ((TReferenceHandlerComponent*)pOther)->entityGuid) &&
                (handlerTypeName == ((TReferenceHandlerComponent*)pOther)->handlerTypeName));
        }
    };
}
