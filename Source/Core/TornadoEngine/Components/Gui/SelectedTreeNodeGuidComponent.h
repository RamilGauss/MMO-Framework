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

namespace nsGuiWrapper
{
    struct DllExport TSelectedTreeNodeGuidComponent : nsECSFramework::IComponent
    {
        std::string value = nsTornadoEngine::TGuidConstants::NONE;

        bool IsLess(const IComponent* pOther) const override
        {
            return value < ((TSelectedTreeNodeGuidComponent*) pOther)->value;
        }

        bool IsEqual(const IComponent* pOther) const override
        {
            return value == ((TSelectedTreeNodeGuidComponent*) pOther)->value;
        }
    };
}