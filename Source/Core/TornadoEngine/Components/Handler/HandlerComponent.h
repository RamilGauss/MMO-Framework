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

#include "GuidConstants.h"

namespace nsLogicWrapper
{
    struct DllExport THandlerComponent : nsECSFramework::IComponent
    {
        enum class Filter
        {
            EVERYWHERE, THIS_UNVIVERSE, THIS_SCENE, SELF_AND_CHILDS, ONLY_CHILDS, SELF
        };

        Filter filter = Filter::EVERYWHERE;

        std::string entityGuid = nsTornadoEngine::TGuidConstants::NONE;
        std::string handlerTypeName;

#pragma IGNORE_ATTRIBUTE
        mutable void* handler = nullptr;

        bool IsLess(const IComponent* pOther) const override
        {
            return handlerTypeName < ((THandlerComponent*)pOther)->handlerTypeName;
        }

        bool IsEqual(const IComponent* pOther) const override
        {
            return handlerTypeName == ((THandlerComponent*)pOther)->handlerTypeName;
        }
    };
}
