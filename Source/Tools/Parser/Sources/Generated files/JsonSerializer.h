/*
	Parser
*/
// ReflectionCodeGenerator version 2.5.0, build 59 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, RTTI, TypeInformation]
// File has been generated at 2023_10_29 17:34:32.251
	
#pragma once

#include <vector>
#include <string>
#include <functional>
#include "Base/Common/JsonMaster.h"
#include "IncludeList.h"

namespace nsCppParser
{
    class DllExport TJsonSerializer
    {
        typedef TJsonMaster::Jobj Jobj;
        typedef TJsonMaster::Jarr Jarr;
    
        struct TypeFunc
        {
            int rtti = 0;
            std::function<void(void*, std::string&)>  serializeFunc;
            std::function<bool(void*, const std::string&, std::string&)> deserializeFunc;
        };
    
        static std::vector<TypeFunc> mTypeFuncVector;
    public:
        static void Init();
    
        template <typename Type>
        static void Serialize(Type* p, std::string& str);
        template <typename Type>
        static bool Deserialize(Type* p, const std::string& str, std::string& err);
    
        static void Serialize(void* p, std::string& str, int rtti);
        static bool Deserialize(void* p, const std::string& str, int rtti, std::string& err);
        static bool Has(int rtti);
    
    public:
        static std::string _SerializeEnum(nsCppParser::AccessLevel* p);
        static void _DeserializeEnum(std::string& str, nsCppParser::AccessLevel* p);
        
        static std::string _SerializeEnum(nsCppParser::AccessMethod* p);
        static void _DeserializeEnum(std::string& str, nsCppParser::AccessMethod* p);
        
        static std::string _SerializeEnum(nsCppParser::DeclarationType* p);
        static void _DeserializeEnum(std::string& str, nsCppParser::DeclarationType* p);
        
        static std::string _SerializeEnum(nsCppParser::MethodCategoryType* p);
        static void _DeserializeEnum(std::string& str, nsCppParser::MethodCategoryType* p);
        
        static void _Serialize(nsCppParser::TInheritanceInfo* p, Jobj& obj);
        static void _Deserialize(nsCppParser::TInheritanceInfo* p, const Jobj& obj);
        
        static void _Serialize(nsCppParser::TMemberExtendedTypeInfo* p, Jobj& obj);
        static void _Deserialize(nsCppParser::TMemberExtendedTypeInfo* p, const Jobj& obj);
        
        static void _Serialize(nsCppParser::TMemberInfo* p, Jobj& obj);
        static void _Deserialize(nsCppParser::TMemberInfo* p, const Jobj& obj);
        
        static void _Serialize(nsCppParser::TTypeInfo* p, Jobj& obj);
        static void _Deserialize(nsCppParser::TTypeInfo* p, const Jobj& obj);
        
        static void _Serialize(nsCppParser::TTypeReference* p, Jobj& obj);
        static void _Deserialize(nsCppParser::TTypeReference* p, const Jobj& obj);
        
        static std::string _SerializeEnum(nsCppParser::TemplateArgument* p);
        static void _DeserializeEnum(std::string& str, nsCppParser::TemplateArgument* p);
        
        static std::string _SerializeEnum(nsCppParser::TypeCategory* p);
        static void _DeserializeEnum(std::string& str, nsCppParser::TypeCategory* p);
        
        static std::string _SerializeEnum(nsCppParser::VariableCategory* p);
        static void _DeserializeEnum(std::string& str, nsCppParser::VariableCategory* p);
        
    };
    //------------------------------------------------------------------------------------------------------------
    template <typename Type>
    void TJsonSerializer::Serialize(Type* p, std::string& str)
    {
        rapidjson::Document doc(rapidjson::Type::kObjectType);
        auto obj = doc.GetObject();
    
        _Serialize(p, obj);
    
        rapidjson::StringBuffer sb;
        rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(sb);
        doc.Accept(writer);
        str = sb.GetString();
    }
    //------------------------------------------------------------------------------------------------------------
    template <typename Type>
    bool TJsonSerializer::Deserialize(Type* p, const std::string& str, std::string& err)
    {
        rapidjson::Document doc(rapidjson::Type::kObjectType);
        const auto parseFlags = rapidjson::ParseFlag::kParseFullPrecisionFlag | rapidjson::ParseFlag::kParseCommentsFlag | rapidjson::ParseFlag::kParseTrailingCommasFlag;
        rapidjson::ParseResult ok = doc.Parse<parseFlags>(str.data());
        if ( !ok ) {
            auto errStr = GetParseError_En(ok.Code());
            err = "JSON parse error : " + std::string(errStr) + ", offset " + std::to_string(ok.Offset()) + "\n";
            return false;
        }
    
        try{
            auto obj = doc.GetObject();
            _Deserialize( p, obj );
        } catch( std::exception& ex ) {
            err = ex.what();
            return false;
        }
        return true;
    }
}
