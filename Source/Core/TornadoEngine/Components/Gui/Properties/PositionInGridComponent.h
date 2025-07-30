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
#include "ImGuiWidgets/Include/Unit.h"

namespace nsGuiWrapper
{
    struct DllExport TPositionInGridComponent : nsTornadoEngine::TPropertyOf<nsImGuiWidgets::TUnit>, nsECSFramework::IComponent
    {
        int x = 0;
        int y = 0;

        bool IsLess(const IComponent* pOther) const override
        {
            if (x < ((TPositionInGridComponent*)pOther)->x) {
                return false;
            }

            if (x == ((TPositionInGridComponent*)pOther)->x) {
                return y < ((TPositionInGridComponent*)pOther)->y;
            }

            return true;
        }

        bool IsEqual(const IComponent* pOther) const override
        {
            return x == ((TPositionInGridComponent*)pOther)->x && y == ((TPositionInGridComponent*)pOther)->y;
        }

    };
}