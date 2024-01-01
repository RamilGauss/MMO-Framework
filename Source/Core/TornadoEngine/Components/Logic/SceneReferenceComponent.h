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
    struct DllExport TSceneReferenceComponent : nsECSFramework::IComponent
    {
        std::string sceneGuid;

        bool IsLess(const IComponent* pOther) const override
        {
            return sceneGuid < ((TSceneReferenceComponent*) pOther)->sceneGuid;
        }

        bool IsEqual(const IComponent* pOther) const override
        {
            return sceneGuid == ((TSceneReferenceComponent*) pOther)->sceneGuid;
        }
    };
}