/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.4.0, build 58 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, TypeInformation]
// File has been generated at 2022_12_01 22:11:38.330
	
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
        static void _Serialize(nsComplex::Y* p, Jobj& obj);
        static void _Deserialize(nsComplex::Y* p, const Jobj& obj);
        
        static void _Serialize(nsFarType::X* p, Jobj& obj);
        static void _Deserialize(nsFarType::X* p, const Jobj& obj);
        
        static void _Serialize(nsInOut::A* p, Jobj& obj);
        static void _Deserialize(nsInOut::A* p, const Jobj& obj);
        
        static void _Serialize(nsInOut::B* p, Jobj& obj);
        static void _Deserialize(nsInOut::B* p, const Jobj& obj);
        
        static void _Serialize(nsSimple::X* p, Jobj& obj);
        static void _Deserialize(nsSimple::X* p, const Jobj& obj);
        
        static std::string _SerializeEnum(nsSimpleEnum::A0* p);
        static void _DeserializeEnum(std::string& str, nsSimpleEnum::A0* p);
        
        static std::string _SerializeEnum(nsSimpleEnum::A1* p);
        static void _DeserializeEnum(std::string& str, nsSimpleEnum::A1* p);
        
        static void _Serialize(nsSimpleEnum::X* p, Jobj& obj);
        static void _Deserialize(nsSimpleEnum::X* p, const Jobj& obj);
        
        static std::string _SerializeEnum(nsSimpleEnum::X::E0* p);
        static void _DeserializeEnum(std::string& str, nsSimpleEnum::X::E0* p);
        
        static std::string _SerializeEnum(nsSimpleEnum::X::E1* p);
        static void _DeserializeEnum(std::string& str, nsSimpleEnum::X::E1* p);
        
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
