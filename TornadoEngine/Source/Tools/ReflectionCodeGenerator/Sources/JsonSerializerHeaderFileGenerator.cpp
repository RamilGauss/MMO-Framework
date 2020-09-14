/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "JsonSerializerHeaderFileGenerator.h"
#include <set>

using namespace nsReflectionCodeGenerator;

void TJsonSerializerHeaderFileGenerator::Work()
{
    AddHeader(mConfig->targetForCodeGeneration.header);
    AddTimeHeader();

    AddPragmaOnce();
    AddEmptyLine();
    AddStandartInclude("string");
    AddStandartInclude("functional");
    AddInclude("JsonMaster.h");
    AddInclude("json11.h");
    AddInclude(mConfig->targetForCodeGeneration.includeListFileName + ".h");
    AddEmptyLine();

    auto namespaceName = mJsonSerializer->nameSpaceName;
    if ( namespaceName.length() ) {
        AddNamespaceBegin(namespaceName);
        IncrementTabs();
    }

    AddClassBegin(mJsonSerializer->exportDeclaration, mJsonSerializer->className);

    AddList(s_JsonDecl);

    AddPrivateSection();

    AddDeclarations();

    AddClassEnd();

    AddList(s_JsonImpl);

    if ( namespaceName.length() ) {
        DecrementTabs();
        AddNamespaceEnd();
    }
}
//-----------------------------------------------------------------------------------
void TJsonSerializerHeaderFileGenerator::AddDeclarations()
{
    IncrementTabs();
    for ( auto& namespaceTypeInfo : mTypeMng->mNameSpaceTypesMap ) {
        auto namespaceName = namespaceTypeInfo.first;
        auto& filenameTypeMap = *(namespaceTypeInfo.second.get());
        for ( auto filenameType : filenameTypeMap ) {
            auto namespaceWithType = filenameType.second->GetTypeNameWithNameSpace();
            AddSerializeMethodDeclaration(namespaceWithType);
            AddDeserializeMethodDeclaration(namespaceWithType);
            AddEmptyLine();
        }
    }
    DecrementTabs();
}
//-----------------------------------------------------------------------------------
void TJsonSerializerHeaderFileGenerator::AddSerializeMethodDeclaration(std::string& namespaceWithType)
{
    // S - Type* p, Jobj& obj
    auto strList = GetParamListForSerialize(namespaceWithType);
    AddStaticMethodDeclaration("void", sSerializeMethod, strList);
}
//-----------------------------------------------------------------------------------
void TJsonSerializerHeaderFileGenerator::AddDeserializeMethodDeclaration(std::string& namespaceWithType)
{
    // D - Type* p, const json11::Json& json 
    auto strList = GetParamListForDeserialize(namespaceWithType);
    AddStaticMethodDeclaration("void", sDeserializeMethod, strList);
}
//-----------------------------------------------------------------------------------

