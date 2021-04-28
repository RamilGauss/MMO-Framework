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
    return std::list<std::string>
    {
        namespaceWithType + "* " + s_TypeObject,
            "Jobj& obj"
    };
}
//----------------------------------------------------------------------------------------------------
std::list<std::string> TJsonSerializerFileGenerator::GetParamListForDeserialize(const std::string& namespaceWithType)
{
    return std::list<std::string>
    {
        namespaceWithType + "* " + s_TypeObject,
            "const Jobj& obj"
    };
}
//----------------------------------------------------------------------------------------------------
bool TJsonSerializerFileGenerator::IsInExternalSources(const std::string& namespaceWithType)
{
    auto p = GetExternalSources(namespaceWithType);
    return p != nullptr;
}
//----------------------------------------------------------------------------------------------------
const nsReflectionCodeGenerator::TExternalSource* TJsonSerializerFileGenerator::GetExternalSources(const std::string& namespaceWithType)
{
    return nullptr;
    //auto extSrc = mJsonSerializer->externalSources.get();
    //if ( extSrc == nullptr ) {
    //    return nullptr;
    //}

    //auto fit = extSrc->value.find(namespaceWithType);
    //if ( fit == extSrc->value.end() ) {
    //    return nullptr;
    //}
    //return &(fit->second);
}
//----------------------------------------------------------------------------------------------------