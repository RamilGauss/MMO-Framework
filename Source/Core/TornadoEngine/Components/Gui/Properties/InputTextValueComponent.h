/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>
#include "Base/Common/TypeDef.h"

#include "TornadoEngine/Share/PropertyOf.h"

#include "ECS/Include/IComponent.h"
#include "ImGuiWidgets/Include/InputTextValue.h"

namespace nsGuiWrapper
{
    struct DllExport TInputTextValueComponent : nsTornadoEngine::TPropertyOf<nsImGuiWidgets::TInputTextValue>, nsECSFramework::IComponent
    {
        std::string value;

        bool IsLess(const IComponent* pOther) const override
        {
            return value < ((TInputTextValueComponent*) pOther)->value;
        }

        bool IsEqual(const IComponent* pOther) const override
        {
            return value == ((TInputTextValueComponent*) pOther)->value;
        }
    };
}