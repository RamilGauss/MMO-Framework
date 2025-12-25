/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>
#include <unordered_map>

#include "Base/Common/TypeDef.h"

#include "ContainerCodeGeneratorLib/Sources/Configs/CodeGenerationResult.h"

namespace nsContainerCodeGenerator
{

#pragma REFLECTION_ATTRIBUTE
    struct DllExport TCodeGenerationResultList
    {
        std::unordered_map<std::string, TCodeGenerationResult> generated;// aggregator, rtti, typeFactory, json, ....
    };
}
