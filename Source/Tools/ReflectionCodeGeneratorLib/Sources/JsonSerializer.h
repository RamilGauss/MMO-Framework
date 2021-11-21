/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.2.2, build 53 [Json, Binary, ImGui, EntityManager, Reflection, TypeInformation]
// File has been generated at 2021_11_21 13:50:27.173
	
#pragma once

#include <vector>
#include <string>
#include <functional>
#include "JsonMaster.h"
#include "IncludeList.h"

namespace nsJson
{
    class DllExport TJsonSerializer
    {
        typedef TJsonMaster::Jobj Jobj;
        typedef TJsonMaster::Jarr Jarr;
    
        struct TypeFunc
        {
            std::function<void(void*, std::string&)>  serializeFunc;
            std::function<bool(void*, const std::string&, std::string&)> deserializeFunc;
        };
    
        static std::vector<TypeFunc> mTypeFuncVector;
    
        static void Init();
    public:
        template <typename Type>
        static void Serialize(Type* p, std::string& str);
        template <typename Type>
        static bool Deserialize(Type* p, const std::string& str, std::string& err);
    
        static void Serialize(void* p, std::string& str, int rtti);
        static bool Deserialize(void* p, const std::string& str, int rtti, std::string& err);
        static bool Has(int rtti);
    
    public:
        static std::string _SerializeEnum(nsCppParser::TypeCategory* p);
        static void _DeserializeEnum(std::string& str, nsCppParser::TypeCategory* p);
        
        static void _Serialize(nsReflectionCodeGenerator::TClassDesc* p, Jobj& obj);
        static void _Deserialize(nsReflectionCodeGenerator::TClassDesc* p, const Jobj& obj);
        
        static void _Serialize(nsReflectionCodeGenerator::TConfig* p, Jobj& obj);
        static void _Deserialize(nsReflectionCodeGenerator::TConfig* p, const Jobj& obj);
        
        static void _Serialize(nsReflectionCodeGenerator::TExternalSource* p, Jobj& obj);
        static void _Deserialize(nsReflectionCodeGenerator::TExternalSource* p, const Jobj& obj);
        
        static void _Serialize(nsReflectionCodeGenerator::TExternalSources* p, Jobj& obj);
        static void _Deserialize(nsReflectionCodeGenerator::TExternalSources* p, const Jobj& obj);
        
        static void _Serialize(nsReflectionCodeGenerator::TFilter* p, Jobj& obj);
        static void _Deserialize(nsReflectionCodeGenerator::TFilter* p, const Jobj& obj);
        
        static void _Serialize(nsReflectionCodeGenerator::TSerializer* p, Jobj& obj);
        static void _Deserialize(nsReflectionCodeGenerator::TSerializer* p, const Jobj& obj);
        
        static void _Serialize(nsReflectionCodeGenerator::TTargetForCodeGeneration* p, Jobj& obj);
        static void _Deserialize(nsReflectionCodeGenerator::TTargetForCodeGeneration* p, const Jobj& obj);
        
        static void _Serialize(nsReflectionCodeGenerator::TTargetForParsing* p, Jobj& obj);
        static void _Deserialize(nsReflectionCodeGenerator::TTargetForParsing* p, const Jobj& obj);
        
    };
    //------------------------------------------------------------------------------------------------------------
    template <typename Type>
    static void TJsonSerializer::Serialize(Type* p, std::string& str)
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
    static bool TJsonSerializer::Deserialize(Type* p, const std::string& str, std::string& err)
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
