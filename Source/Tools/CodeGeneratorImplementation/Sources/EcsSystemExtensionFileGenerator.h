/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ReflectionCodeGeneratorLib/Sources/IFileGenerator.h"

namespace nsCodeGeneratorImplementation
{
    class TEcsSystemExtensionFileGenerator : public nsReflectionCodeGenerator::IFileGenerator
    {
    protected:
        const std::string s_Init = "Init";
        const std::string s_DynamicCast = "DynamicCast";

        const std::string s_rtti = "rtti";

        const std::string s_Data = "Data";
        const std::string s_castFunc = "castFunc";
        const std::string s_mDataVector = "mDataVector";
    };
}

