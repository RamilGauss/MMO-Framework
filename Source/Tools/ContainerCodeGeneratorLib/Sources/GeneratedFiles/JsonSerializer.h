/*
	ContainerCodeGenerator
*/
// ReflectionCodeGenerator version 2.5.1, build 60 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, RTTI, TypeInformation]

#pragma once

#include <vector>
#include <string>
#include <functional>
#include "Base/Common/JsonMaster.h"
#include "ContainerCodeGeneratorLib/Sources/GeneratedFiles/IncludeList.h"

namespace nsContainerCodeGenerator
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
        static void _Serialize(nsContainerCodeGenerator::TCodeGenerationResult* p, Jobj& obj);
        static void _Deserialize(nsContainerCodeGenerator::TCodeGenerationResult* p, const Jobj& obj);
        
        static void _Serialize(nsContainerCodeGenerator::TCodeGenerationResultList* p, Jobj& obj);
        static void _Deserialize(nsContainerCodeGenerator::TCodeGenerationResultList* p, const Jobj& obj);
        
        static void _Serialize(nsContainerCodeGenerator::TCoreConfig* p, Jobj& obj);
        static void _Deserialize(nsContainerCodeGenerator::TCoreConfig* p, const Jobj& obj);
        
        static void _Serialize(nsContainerCodeGenerator::TPathSetting* p, Jobj& obj);
        static void _Deserialize(nsContainerCodeGenerator::TPathSetting* p, const Jobj& obj);
        
        static void _Serialize(nsContainerCodeGenerator::TProjectConfig* p, Jobj& obj);
        static void _Deserialize(nsContainerCodeGenerator::TProjectConfig* p, const Jobj& obj);
        
    };
    //------------------------------------------------------------------------------------------------------------
    template <typename Type>
    void TJsonSerializer::Serialize(Type* p, std::string& str)
    {
    #undef GetObject
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
        if (!ok) {
            auto errStr = GetParseError_En(ok.Code());
            err = "JSON parse error : " + std::string(errStr) + ", offset " + std::to_string(ok.Offset()) + "\n";
            return false;
        }
    
        try {
            auto obj = doc.GetObject();
            _Deserialize( p, obj );
        } catch (std::exception& ex) {
            err = ex.what();
            return false;
        }
        return true;
    }
}
