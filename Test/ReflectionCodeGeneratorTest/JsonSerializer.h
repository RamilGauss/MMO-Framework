/*
	ReflectionCodeGeneratorTest
*/
// ReflectionCodeGenerator version 2.3.0, build 57 [Json, Binary, ImGui, EcsComponentExtension, EcsSystemExtension, Reflection, TypeInformation]
// File has been generated at 2022_09_18 22:21:05.371
	
#pragma once

#include <vector>
#include <string>
#include <functional>
#include "JsonMaster.h"
#include "EcsComponentExtensionIncludeList.h"

namespace nsTest
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
        static void _Serialize(nsSimpleComponents::TNameComponent* p, Jobj& obj);
        static void _Deserialize(nsSimpleComponents::TNameComponent* p, const Jobj& obj);
        
        static void _Serialize(nsSimpleComponents::TSimpleComponent* p, Jobj& obj);
        static void _Deserialize(nsSimpleComponents::TSimpleComponent* p, const Jobj& obj);
        
        static void _Serialize(nsSimpleComponents::TSizeComponent* p, Jobj& obj);
        static void _Deserialize(nsSimpleComponents::TSizeComponent* p, const Jobj& obj);
        
        static void _Serialize(nsSimpleComponents::TValueComponent* p, Jobj& obj);
        static void _Deserialize(nsSimpleComponents::TValueComponent* p, const Jobj& obj);
        
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