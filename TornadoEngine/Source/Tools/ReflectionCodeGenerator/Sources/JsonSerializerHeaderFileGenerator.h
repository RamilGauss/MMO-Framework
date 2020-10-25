/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "JsonSerializerFileGenerator.h"
#include "fmt/core.h"

namespace nsReflectionCodeGenerator
{
    class TJsonSerializerHeaderFileGenerator : public TJsonSerializerFileGenerator
    {
        const std::list<std::string> s_JsonDecl =
        {
fmt::format("    typedef TJsonMaster::Jobj {};", s_Jobj),
fmt::format("    typedef TJsonMaster::Jarr {};", s_Jarr),
            "",
            "    struct TypeFunc",
            "    {",
            "        std::function<void(void*, std::string&)>  serializeFunc;",
            "        std::function<bool(void*&, const std::string&, std::string&)> deserializeFunc;",
            "        std::function<bool(void*, const std::string&, std::string&)> fillFunc;",
            "        int typeIdentifier;",
            "    };",
            "",
            "    static std::map<std::string, TypeFunc> mTypeNameFuncsMap;",
            "    static std::vector<TypeFunc> mTypeFuncVector;",
            "",
            "    static void Init();",
            "public:",
            "    template <typename Type>",
            "    static void Serialize(Type* p, std::string& str);",
            "    template <typename Type>",
            "    static bool Deserialize(Type*& p, const std::string& str, std::string& err);",
            "    template <typename Type>",
            "    static bool Fill(Type* p, const std::string& str, std::string& err);",
            "",
            "    static void Serialize(void* p, std::string& str, const std::string& typeName);",
            "    static bool Deserialize(void*& p, const std::string& str, const std::string& typeName, std::string& err);",
            "    static bool Fill(void* p, const std::string& str, const std::string& typeName, std::string& err);",
            "",
            "    static void Serialize(void* p, std::string& str, int typeIdentifier);",
            "    static bool Deserialize(void*& p, const std::string& str, int typeIdentifier, std::string& err);",
            "    static bool Fill(void* p, const std::string& str, int typeIdentifier, std::string& err);",
            "private:",
            "    template <typename Type>",
            "    static bool _Deserialize(Type*& p, const std::string& str, bool checkPtr, std::string& err);",
        };

        const std::list<std::string> s_JsonImpl =
        {
            "//------------------------------------------------------------------------------------------------------------",
            "template <typename Type>",
fmt::format("static void {}::Serialize(Type* p, std::string& str)", mJsonSerializer->className),
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
fmt::format("static bool {}::Deserialize(Type*& p, const std::string& str, std::string& err)", mJsonSerializer->className),
            "{",
            "    return _Deserialize(p, str, true, err);",
            "}",
            "//------------------------------------------------------------------------------------------------------------",
            "template <typename Type>",
fmt::format("static bool {}::Fill(Type* p, const std::string& str, std::string& err)", mJsonSerializer->className),
            "{",
            "    return _Deserialize(p, str, false, err);",
            "}",
            "//------------------------------------------------------------------------------------------------------------",
            "template <typename Type>",
fmt::format("static bool {}::_Deserialize(Type*& p, const std::string& str, bool checkPtr, std::string& err)", mJsonSerializer->className),
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
            "    if ( checkPtr ) {",
            "        p = p ? p : new Type();",
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

    public:
        virtual void Work() override;

    private:
        void AddDeclarations();

        void AddSerializeMethodDeclaration(std::string& namespaceWithType);
        void AddDeserializeMethodDeclaration(std::string& namespaceWithType);
    };
}

