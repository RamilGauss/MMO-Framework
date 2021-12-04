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
    struct DllExport TFeatureComponent : nsECSFramework::IComponent
    {
#pragma IGNORE_ATTRIBUTE
        mutable nsECSFramework::TFeature* feature = nullptr;

        std::string featureTypeName;

        bool IsLess(const IComponent* pOther) const override
        {
            return featureTypeName < ((TFeatureComponent*) pOther)->featureTypeName;
        }

        bool IsEqual(const IComponent* pOther) const override
        {
            return featureTypeName == ((TFeatureComponent*) pOther)->featureTypeName;
        }
    };
}