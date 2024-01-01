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
    struct DllExport TGlobalHandlerComponent : nsECSFramework::IComponent
    {
        enum class Filter
        {
            EVERYWHERE, THIS_UNVIVERSE, THIS_SCENE
        };

        Filter filter = Filter::EVERYWHERE;

        std::string handlerTypeName;

#pragma IGNORE_ATTRIBUTE
        mutable void* handler = nullptr;

        bool IsLess(const IComponent* pOther) const override
        {
            return handlerTypeName < ((TGlobalHandlerComponent*)pOther)->handlerTypeName;
        }

        bool IsEqual(const IComponent* pOther) const override
        {
            return handlerTypeName == ((TGlobalHandlerComponent*)pOther)->handlerTypeName;
        }
    };
}
