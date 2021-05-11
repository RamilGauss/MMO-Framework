/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.0.0, build 47, info Json, Binary, EntMng, Reflection
// File has been generated at 2021_05_03 21:31:47.861
	
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
            std::function<bool(void*&, const std::string&, std::string&)> deserializeFunc;
            std::function<bool(void*, const std::string&, std::string&)> fillFunc;
            int typeIdentifier;
        };
    
        static std::map<std::string, TypeFunc> mTypeNameFuncsMap;
        static std::vector<TypeFunc> mTypeFuncVector;
    
        static void Init();
    public:
        template <typename Type>
        static void Serialize(Type* p, std::string& str);
        template <typename Type>
        static bool Deserialize(Type*& p, const std::string& str, std::string& err);
        template <typename Type>
        static bool Fill(Type* p, const std::string& str, std::string& err);
    
        static void Serialize(void* p, std::string& str, const std::string& typeName);
        static bool Deserialize(void*& p, const std::string& str, const std::string& typeName, std::string& err);
        static bool Fill(void* p, const std::string& str, const std::string& typeName, std::string& err);
    
        static void Serialize(void* p, std::string& str, int typeIdentifier);
        static bool Deserialize(void*& p, const std::string& str, int typeIdentifier, std::string& err);
        static bool Fill(void* p, const std::string& str, int typeIdentifier, std::string& err);
    private:
        template <typename Type>
        static bool _Deserialize(Type*& p, const std::string& str, bool checkPtr, std::string& err);
    private:
        static void _Serialize(nsReflectionCodeGenerator::TClassDesc* p, Jobj& obj );
        static void _Deserialize(nsReflectionCodeGenerator::TClassDesc* p, const Jobj& obj );
        
        static void _Serialize(nsReflectionCodeGenerator::TConfig* p, Jobj& obj );
        static void _Deserialize(nsReflectionCodeGenerator::TConfig* p, const Jobj& obj );
        
        static void _Serialize(nsReflectionCodeGenerator::TExternalSource* p, Jobj& obj );
        static void _Deserialize(nsReflectionCodeGenerator::TExternalSource* p, const Jobj& obj );
        
        static void _Serialize(nsReflectionCodeGenerator::TExternalSources* p, Jobj& obj );
        static void _Deserialize(nsReflectionCodeGenerator::TExternalSources* p, const Jobj& obj );
        
        static void _Serialize(nsReflectionCodeGenerator::TFilter* p, Jobj& obj );
        static void _Deserialize(nsReflectionCodeGenerator::TFilter* p, const Jobj& obj );
        
        static void _Serialize(nsReflectionCodeGenerator::TSerializer* p, Jobj& obj );
        static void _Deserialize(nsReflectionCodeGenerator::TSerializer* p, const Jobj& obj );
        
        static void _Serialize(nsReflectionCodeGenerator::TTargetForCodeGeneration* p, Jobj& obj );
        static void _Deserialize(nsReflectionCodeGenerator::TTargetForCodeGeneration* p, const Jobj& obj );
        
        static void _Serialize(nsReflectionCodeGenerator::TTargetForParsing* p, Jobj& obj );
        static void _Deserialize(nsReflectionCodeGenerator::TTargetForParsing* p, const Jobj& obj );
        
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
    static bool TJsonSerializer::Deserialize(Type*& p, const std::string& str, std::string& err)
    {
        return _Deserialize(p, str, true, err);
    }
    //------------------------------------------------------------------------------------------------------------
    template <typename Type>
    static bool TJsonSerializer::Fill(Type* p, const std::string& str, std::string& err)
    {
        return _Deserialize(p, str, false, err);
    }
    //------------------------------------------------------------------------------------------------------------
    template <typename Type>
    static bool TJsonSerializer::_Deserialize(Type*& p, const std::string& str, bool checkPtr, std::string& err)
    {
        rapidjson::Document doc(rapidjson::Type::kObjectType);
        const auto parseFlags = rapidjson::ParseFlag::kParseFullPrecisionFlag | rapidjson::ParseFlag::kParseCommentsFlag | rapidjson::ParseFlag::kParseTrailingCommasFlag;
        rapidjson::ParseResult ok = doc.Parse<parseFlags>(str.data());
        if ( !ok ) {
            auto errStr = GetParseError_En(ok.Code());
            err = "JSON parse error : " + std::string(errStr) + ", offset " + std::to_string(ok.Offset()) + "\n";
            return false;
        }
    
        if ( checkPtr ) {
            p = p ? p : new Type();
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