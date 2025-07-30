/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "TornadoEngine/Share/MathStructs.h"

namespace nsTornadoEngine
{
#pragma REFLECTION_ATTRIBUTE
    struct DllExport TPrefabInstance
    {
        std::string parentGuid;
        std::string prefabGuid;

        nsMathTools::TMatrix16 localMatrix;
    };
}
