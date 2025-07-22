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

namespace nsCommonWrapper
{
    struct DllExport TProjectionToUniverseComponent : nsECSFramework::IComponent
    {
        std::string guid;

        bool IsLess(const IComponent* pOther) const override
        {
            return guid < ((TProjectionToUniverseComponent*)pOther)->guid;
        }

        bool IsEqual(const IComponent* pOther) const override
        {
            return guid == ((TProjectionToUniverseComponent*)pOther)->guid;
        }
    };
}
