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

#include "ContainerCodeGeneratorLib/Sources/Configs/CodeGenerationResultList.h"

namespace nsContainerCodeGenerator
{

#pragma REFLECTION_ATTRIBUTE
    struct DllExport TCoreConfig
    {
        std::string exportDeclaration;
        std::string nameSpace;

        std::unordered_map<std::string, TCodeGenerationResultList> containers; // Component, ImGuiWidget
    };
}
