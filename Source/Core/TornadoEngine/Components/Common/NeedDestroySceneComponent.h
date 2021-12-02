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
    struct DllExport TNeedDestroySceneComponent : nsECSFramework::IComponent
    {
        std::string sceneInstanceGuid;

        bool IsLess(const IComponent* pOther) const override
        {
            return sceneInstanceGuid < ((TNeedDestroySceneComponent*) pOther)->sceneInstanceGuid;
        }

        bool IsEqual(const IComponent* pOther) const override
        {
            return sceneInstanceGuid == ((TNeedDestroySceneComponent*) pOther)->sceneInstanceGuid;
        }
    };
}