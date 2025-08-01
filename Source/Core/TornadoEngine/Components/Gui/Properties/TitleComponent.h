/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/TypeDef.h"

#include "TornadoEngine/Share/PropertyOf.h"

#include "ECS/Include/IComponent.h"
#include "ImGuiWidgets/Include/Title.h"

namespace nsGuiWrapper
{
    struct DllExport TTitleComponent : nsTornadoEngine::TPropertyOf<nsImGuiWidgets::TTitle>, nsECSFramework::IComponent
    {
        std::string value;

        bool IsLess(const IComponent* pOther) const override
        {
            return value < ((TTitleComponent*) pOther)->value;
        }

        bool IsEqual(const IComponent* pOther) const override
        {
            return value == ((TTitleComponent*) pOther)->value;
        }
    };
}