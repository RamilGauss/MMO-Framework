/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.4.0, build 58 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, TypeInformation]
// File has been generated at 2022_11_29 22:52:42.164
	
#pragma once

#include <vector>
#include <string>
#include <functional>
#include "JsonMaster.h"
#include "IncludeList.h"

namespace nsContainerCodeGenerator
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
        static void _Serialize(nsContainerCodeGenerator::TCategoryConfig* p, Jobj& obj);
        static void _Deserialize(nsContainerCodeGenerator::TCategoryConfig* p, const Jobj& obj);
        
        static void _Serialize(nsContainerCodeGenerator::TConfig* p, Jobj& obj);
        static void _Deserialize(nsContainerCodeGenerator::TConfig* p, const Jobj& obj);
        
        static void _Serialize(nsContainerCodeGenerator::TGeneratedClass* p, Jobj& obj);
        static void _Deserialize(nsContainerCodeGenerator::TGeneratedClass* p, const Jobj& obj);
        
        static void _Serialize(nsContainerCodeGenerator::TInheritances* p, Jobj& obj);
        static void _Deserialize(nsContainerCodeGenerator::TInheritances* p, const Jobj& obj);
        
        static void _Serialize(nsContainerCodeGenerator::TPartConfig* p, Jobj& obj);
        static void _Deserialize(nsContainerCodeGenerator::TPartConfig* p, const Jobj& obj);
        
        static void _Serialize(nsContainerCodeGenerator::TTargetForParsing* p, Jobj& obj);
        static void _Deserialize(nsContainerCodeGenerator::TTargetForParsing* p, const Jobj& obj);
        
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
