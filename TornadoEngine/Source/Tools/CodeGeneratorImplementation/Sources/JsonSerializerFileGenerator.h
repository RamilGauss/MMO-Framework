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
    class TJsonSerializerFileGenerator : public nsReflectionCodeGenerator::IFileGenerator
    {
    protected:
        const std::string s_Jobj = "Jobj";
        const std::string s_Jarr = "Jarr";

        // S - Type* p, Jobj& obj
        std::list<std::string> GetParamListForSerialize(const std::string& namespaceWithType);
        std::list<std::string> GetParamListForDeserialize(const std::string& namespaceWithType);

        std::list<std::string> GetParamListForSerializeEnum(const std::string& namespaceWithType);
        std::list<std::string> GetParamListForDeserializeEnum(const std::string& namespaceWithType);
    };
}

