/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/TypeDef.h"
#include <string>

#include <ECS/include/IComponent.h>

#include "GraphicEngine/Camera.h"

namespace nsGraphicWrapper
{
    struct DllExport TUniverseCameraComponent : nsECSFramework::IComponent
    {
        std::string universeGuid;

#pragma IGNORE_ATTRIBUTE
        mutable nsGraphicEngine::TCamera* value = nullptr;

        bool IsLess(const IComponent* pOther) const override
        {
            return universeGuid < ((TUniverseCameraComponent*)pOther)->universeGuid;
        }

        bool IsEqual(const IComponent* pOther) const override
        {
            return universeGuid == ((TUniverseCameraComponent*)pOther)->universeGuid;
        }
    };
}