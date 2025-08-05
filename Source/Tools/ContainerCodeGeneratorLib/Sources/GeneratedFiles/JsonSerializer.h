/*
	ContainerCodeGenerator
*/
// ReflectionCodeGenerator version 2.5.1, build 60 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, RTTI, TypeInformation]
// File has been generated at 2025_08_05 10:31:58.286
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
        static void _Serialize(nsContainerCodeGenerator::TAggregator* p, Jobj& obj);
        static void _Deserialize(nsContainerCodeGenerator::TAggregator* p, const Jobj& obj);
        
        static void _Serialize(nsContainerCodeGenerator::TAggregatorClass* p, Jobj& obj);
        static void _Deserialize(nsContainerCodeGenerator::TAggregatorClass* p, const Jobj& obj);
        
        static void _Serialize(nsContainerCodeGenerator::TComponentAggregator* p, Jobj& obj);
        static void _Deserialize(nsContainerCodeGenerator::TComponentAggregator* p, const Jobj& obj);
        
        static void _Serialize(nsContainerCodeGenerator::TComponentConfig* p, Jobj& obj);
        static void _Deserialize(nsContainerCodeGenerator::TComponentConfig* p, const Jobj& obj);
        
        static void _Serialize(nsContainerCodeGenerator::TCoreConfig* p, Jobj& obj);
        static void _Deserialize(nsContainerCodeGenerator::TCoreConfig* p, const Jobj& obj);
        
        static void _Serialize(nsContainerCodeGenerator::TCoreContainerConfig* p, Jobj& obj);
        static void _Deserialize(nsContainerCodeGenerator::TCoreContainerConfig* p, const Jobj& obj);
        
        static void _Serialize(nsContainerCodeGenerator::TEcsSystemConfig* p, Jobj& obj);
        static void _Deserialize(nsContainerCodeGenerator::TEcsSystemConfig* p, const Jobj& obj);
        
        static void _Serialize(nsContainerCodeGenerator::TGeneratedClass* p, Jobj& obj);
        static void _Deserialize(nsContainerCodeGenerator::TGeneratedClass* p, const Jobj& obj);
        
        static void _Serialize(nsContainerCodeGenerator::THandlerAggregator* p, Jobj& obj);
        static void _Deserialize(nsContainerCodeGenerator::THandlerAggregator* p, const Jobj& obj);
        
        static void _Serialize(nsContainerCodeGenerator::THandlerConfig* p, Jobj& obj);
        static void _Deserialize(nsContainerCodeGenerator::THandlerConfig* p, const Jobj& obj);
        
        static void _Serialize(nsContainerCodeGenerator::TImGuiWidgetsAggregator* p, Jobj& obj);
        static void _Deserialize(nsContainerCodeGenerator::TImGuiWidgetsAggregator* p, const Jobj& obj);
        
        static void _Serialize(nsContainerCodeGenerator::TImGuiWidgetsConfig* p, Jobj& obj);
        static void _Deserialize(nsContainerCodeGenerator::TImGuiWidgetsConfig* p, const Jobj& obj);
        
        static void _Serialize(nsContainerCodeGenerator::TIncludeListFileName* p, Jobj& obj);
        static void _Deserialize(nsContainerCodeGenerator::TIncludeListFileName* p, const Jobj& obj);
        
        static void _Serialize(nsContainerCodeGenerator::TParentClass* p, Jobj& obj);
        static void _Deserialize(nsContainerCodeGenerator::TParentClass* p, const Jobj& obj);
        
        static void _Serialize(nsContainerCodeGenerator::TProjectConfig* p, Jobj& obj);
        static void _Deserialize(nsContainerCodeGenerator::TProjectConfig* p, const Jobj& obj);
        
        static void _Serialize(nsContainerCodeGenerator::TProjectContainerConfig* p, Jobj& obj);
        static void _Deserialize(nsContainerCodeGenerator::TProjectContainerConfig* p, const Jobj& obj);
        
        static void _Serialize(nsContainerCodeGenerator::TSystemAggregator* p, Jobj& obj);
        static void _Deserialize(nsContainerCodeGenerator::TSystemAggregator* p, const Jobj& obj);
        
        static void _Serialize(nsContainerCodeGenerator::TSystemConfig* p, Jobj& obj);
        static void _Deserialize(nsContainerCodeGenerator::TSystemConfig* p, const Jobj& obj);
        
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
