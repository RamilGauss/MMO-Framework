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
#include "ContainerCodeGeneratorLib/Sources/Configs/CodeGenerationResultList.h"

namespace nsContainerCodeGenerator
{

#pragma REFLECTION_ATTRIBUTE
    struct DllExport TProjectConfig
    {
        std::string exportDeclaration;
        std::string nameSpace;

        TCodeGenerationResult mainAggregator;

        std::unordered_map<std::string, TCodeGenerationResultList> containers; // Component, Handler, System
        std::unordered_map<std::string, TCodeGenerationResultList> aggregators;// Component, Handler, System, ImGuiWidget
    };
}
