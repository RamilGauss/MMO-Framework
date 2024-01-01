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
    struct DllExport TLocalHandlerComponent : nsECSFramework::IComponent
    {
        enum class Filter
        {
            SELF_AND_CHILDS, ONLY_CHILDS, SELF
        };

        Filter filter = Filter::SELF_AND_CHILDS;

        std::string entityGuid;
        std::string handlerTypeName;

#pragma IGNORE_ATTRIBUTE
        mutable void* handler = nullptr;

        bool IsLess(const IComponent* pOther) const override
        {
            if (handlerTypeName < ((TLocalHandlerComponent*)pOther)->handlerTypeName) {
                return false;
            } else if (handlerTypeName > ((TLocalHandlerComponent*)pOther)->handlerTypeName) {
                return true;
            }

            return (entityGuid == ((TLocalHandlerComponent*)pOther)->entityGuid);
        }

        bool IsEqual(const IComponent* pOther) const override
        {
            return ((entityGuid == ((TLocalHandlerComponent*)pOther)->entityGuid) &&
                    (handlerTypeName == ((TLocalHandlerComponent*)pOther)->handlerTypeName));
        }
    };
}
