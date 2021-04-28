/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "BinaryMarshallerFileGenerator.h"
#include "fmt/core.h"

using namespace nsCodeGeneratorImplementation;
using namespace nsCppParser;

std::string TBinaryMarshallerFileGenerator::MakeEnumName(TTypeInfo* p)
{
    std::string namespaceWithoutColonColon;
    for (auto ns : p->mNamespaceVec) {
        namespaceWithoutColonColon += ns;
    }
    if (namespaceWithoutColonColon.length() > 0) {
        return fmt::format("e_{}_{}", namespaceWithoutColonColon, p->mName);
    }

    return fmt::format("e_{}", p->mName);
}
//-----------------------------------------------------------------------------------------
std::list<std::string> TBinaryMarshallerFileGenerator::GetParamListForSerialize(const std::string& namespaceWithType)
{
    return std::list<std::string>
    {
        namespaceWithType + "* " + s_TypeObject,
    };
}
//----------------------------------------------------------------------------------------------------
std::list<std::string> TBinaryMarshallerFileGenerator::GetParamListForDeserialize(const std::string& namespaceWithType)
{
    return std::list<std::string>
    {
        namespaceWithType + "* " + s_TypeObject,
    };
}
//----------------------------------------------------------------------------------------------------
std::list<std::string> TBinaryMarshallerFileGenerator::GetParamListForGetID(const std::string& namespaceWithType)
{
    return std::list<std::string>
    {
        namespaceWithType + "* " + s_TypeObject
    };
}
//----------------------------------------------------------------------------------------------------