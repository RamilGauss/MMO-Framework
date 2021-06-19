/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "JsonSerializerFileGenerator.h"

using namespace nsCodeGeneratorImplementation;

// S - Type* p, Jobj& obj
std::list<std::string> TJsonSerializerFileGenerator::GetParamListForSerialize(const std::string& namespaceWithType)
{
    return
    {
        namespaceWithType + "* " + s_TypeObject,
            "Jobj& obj"
    };
}
//----------------------------------------------------------------------------------------------------
std::list<std::string> TJsonSerializerFileGenerator::GetParamListForDeserialize(const std::string& namespaceWithType)
{
    return
    {
        namespaceWithType + "* " + s_TypeObject,
            "const Jobj& obj"
    };
}
//----------------------------------------------------------------------------------------------------
std::list<std::string> TJsonSerializerFileGenerator::GetParamListForSerializeEnum(const std::string& namespaceWithType)
{
    return
    {
        namespaceWithType + "* " + s_TypeObject
    };
}
//----------------------------------------------------------------------------------------------------
std::list<std::string> TJsonSerializerFileGenerator::GetParamListForDeserializeEnum(const std::string& namespaceWithType)
{
    return
    {
        "std::string& str",
        namespaceWithType + "* " + s_TypeObject
    };
}
//----------------------------------------------------------------------------------------------------
