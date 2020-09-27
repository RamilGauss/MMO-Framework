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
            "        std::function<void(void*&, const std::string&)> deserializeFunc;",
            "        std::function<void(void*, const std::string&)> fillFunc;",
            "    };",
            "",
            "    static std::map<std::string, TypeFunc> mTypeNameFuncsMap;",
            "    static std::list<std::string> mTypeNameList;",
            "",
            "    static void Init();",
            "public:",
            "    static const std::list<std::string>& GetTypeNameList();",
            "",
            "    template <typename Type>",
            "    static void Serialize( Type* p, std::string& str );",
            "    template <typename Type>",
            "    static void Deserialize( Type*& p, const std::string& str );",
            "    template <typename Type>",
            "    static void Fill( Type* p, const std::string& str );",
            "",
            "    static void Serialize(void* p, std::string& str, const std::string& typeName);",
            "    static void Deserialize(void*& p, const std::string& str, const std::string& typeName);",
            "    static void Fill(void* p, const std::string& str, const std::string& typeName);",
            "private:",
            "    template <typename Type>",
            "    static void _Deserialize( Type*& p, const std::string& str, bool checkPtr );",
        };

        const std::list<std::string> s_JsonImpl =
        {
            "//------------------------------------------------------------------------------------------------------------",
            "template <typename Type>",
            fmt::format("static void {}::Serialize( Type* p, std::string& str )", mJsonSerializer->className),
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
            fmt::format("static void {}::Deserialize( Type*& p, const std::string& str )", mJsonSerializer->className),
            "{",
            "    _Deserialize( p, str, true );",
            "}",
            "//------------------------------------------------------------------------------------------------------------",
            "template <typename Type>",
            fmt::format("static void {}::Fill( Type* p, const std::string& str )", mJsonSerializer->className),
            "{",
            "    _Deserialize( p, str, false );",
            "}",
            "//------------------------------------------------------------------------------------------------------------",
            "template <typename Type>",
            fmt::format("static void {}::_Deserialize( Type*& p, const std::string& str, bool checkPtr )", mJsonSerializer->className),
            "{",
            "    rapidjson::Document doc(rapidjson::Type::kObjectType);",
            "    doc.Parse(str.data());",
            "    if ( doc.HasParseError() ) {",
            "        return;",
            "    }",
            "",
            "    if ( checkPtr ) {",
            "        p = p ? p : new Type();",
            "    }",
            "",
            "    auto obj = doc.GetObject();",
            fmt::format("    {}( p, obj );", sDeserializeMethod),
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

