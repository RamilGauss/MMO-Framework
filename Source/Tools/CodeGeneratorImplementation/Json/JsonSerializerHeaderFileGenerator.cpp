/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "JsonSerializerHeaderFileGenerator.h"
#include <set>

using namespace nsCodeGeneratorImplementation;
using namespace nsReflectionCodeGenerator;
using namespace nsCppParser;

void TJsonSerializerHeaderFileGenerator::Work()
{
    AddHeader(mConfig->targetForCodeGeneration.header);
    AddTimeHeader();

    AddPragmaOnce();
    AddEmptyLine();
    AddStandartInclude("vector");
    AddStandartInclude("string");
    AddStandartInclude("functional");
    AddInclude("JsonMaster.h");
    AddInclude(mConfig->targetForCodeGeneration.includeListParams.includeListFileName + ".h");
    AddEmptyLine();

    auto namespaceName = mSerializer->nameSpaceName;
    if (namespaceName.length()) {
        AddNamespaceBegin(namespaceName);
        IncrementTabs();
    }

    AddClassBegin(mSerializer->exportDeclaration, mSerializer->className);

    AddList(GetJsonDecl());

    AddPublicSection();

    AddDeclarations();

    AddClassEnd();

    AddList(GetJsonImpl());

    if (namespaceName.length()) {
        DecrementTabs();
        AddNamespaceEnd();
    }
}
//-----------------------------------------------------------------------------------
void TJsonSerializerHeaderFileGenerator::AddDeclarations()
{
    IncrementTabs();

    auto& forGenerate = mTypeNameDbPtr->GetForGenerate();
    for (auto& namespaceTypeInfo : forGenerate) {

        auto fullTypeName = namespaceTypeInfo.GetFullType();
        auto type = mTypeManager->Get(fullTypeName);

        auto namespaceWithType = type->GetTypeNameWithNameSpace();
        
        if (type->mType == DeclarationType::ENUM) {
            AddSerializeEnumMethodDeclaration(namespaceWithType);
            AddDeserializeEnumMethodDeclaration(namespaceWithType);
        } else {
            AddSerializeMethodDeclaration(namespaceWithType);
            AddDeserializeMethodDeclaration(namespaceWithType);
        }
        AddEmptyLine();
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
    // D - Type* p, const Jobj& obj 
    auto strList = GetParamListForDeserialize(namespaceWithType);
    AddStaticMethodDeclaration("void", sDeserializeMethod, strList);
}
//-----------------------------------------------------------------------------------
void TJsonSerializerHeaderFileGenerator::AddSerializeEnumMethodDeclaration(std::string& namespaceWithType)
{
    // S - Type* p, Jobj& obj
    auto strList = GetParamListForSerializeEnum(namespaceWithType);
    AddStaticMethodDeclaration("std::string", sSerializeEnumMethod, strList);
}
//-----------------------------------------------------------------------------------
void TJsonSerializerHeaderFileGenerator::AddDeserializeEnumMethodDeclaration(std::string& namespaceWithType)
{
    // D - Type* p, const Jobj& obj 
    auto strList = GetParamListForDeserializeEnum(namespaceWithType);
    AddStaticMethodDeclaration("void", sDeserializeEnumMethod, strList);
}
//-----------------------------------------------------------------------------------
const std::list<std::string> TJsonSerializerHeaderFileGenerator::GetJsonDecl()
{
    return
    {
fmt::format("    typedef TJsonMaster::Jobj {};", s_Jobj),
fmt::format("    typedef TJsonMaster::Jarr {};", s_Jarr),
            "",
            "    struct TypeFunc",
            "    {",
            "        std::function<void(void*, std::string&)>  serializeFunc;",
            "        std::function<bool(void*, const std::string&, std::string&)> deserializeFunc;",
            "    };",
            "",
            "    static std::vector<TypeFunc> mTypeFuncVector;",
            "",
            "    static void Init();",
            "public:",
            "    template <typename Type>",
            "    static void Serialize(Type* p, std::string& str);",
            "    template <typename Type>",
            "    static bool Deserialize(Type* p, const std::string& str, std::string& err);",
            "",
            "    static void Serialize(void* p, std::string& str, int rtti);",
            "    static bool Deserialize(void* p, const std::string& str, int rtti, std::string& err);",
            "    static bool Has(int rtti);",
            "",
    };
}
//-----------------------------------------------------------------------------------
const std::list<std::string> TJsonSerializerHeaderFileGenerator::GetJsonImpl()
{
    return
    {
        "//------------------------------------------------------------------------------------------------------------",
        "template <typename Type>",
fmt::format("static void {}::Serialize(Type* p, std::string& str)", mSerializer->className),
            "{",
            "    rapidjson::Document doc(rapidjson::Type::kObjectType);",
            "    auto obj = doc.GetObject();",
            "",
fmt::format("    {}(p, obj);", sSerializeMethod),
            "",
            "    rapidjson::StringBuffer sb;",
            "    rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(sb);",
            "    doc.Accept(writer);",
            "    str = sb.GetString();",
            "}",
            "//------------------------------------------------------------------------------------------------------------",
            "template <typename Type>",
fmt::format("static bool {}::Deserialize(Type* p, const std::string& str, std::string& err)", mSerializer->className),
            "{",
            "    rapidjson::Document doc(rapidjson::Type::kObjectType);",
            "    const auto parseFlags = rapidjson::ParseFlag::kParseFullPrecisionFlag | rapidjson::ParseFlag::kParseCommentsFlag | rapidjson::ParseFlag::kParseTrailingCommasFlag;",
            "    rapidjson::ParseResult ok = doc.Parse<parseFlags>(str.data());",
            "    if ( !ok ) {",
            "        auto errStr = GetParseError_En(ok.Code());",
            "        err = \"JSON parse error : \" + std::string(errStr) + \", offset \" + std::to_string(ok.Offset()) + \"\\n\";",
            "        return false;",
            "    }",
            "",
            "    try{",
            "        auto obj = doc.GetObject();",
fmt::format("        {}( p, obj );", sDeserializeMethod),
            "    } catch( std::exception& ex ) {",
            "        err = ex.what();",
            "        return false;",
            "    }",
            "    return true;",
            "}",
    };
}
//-----------------------------------------------------------------------------------

