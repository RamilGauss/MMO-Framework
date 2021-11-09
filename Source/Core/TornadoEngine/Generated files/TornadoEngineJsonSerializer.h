/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.2.1, build 52 [Json, Binary, ImGui, EntityManager, Reflection, TypeInformation]
// File has been generated at 2021_11_07 18:25:01.766
	
#pragma once

#include <vector>
#include <string>
#include <functional>
#include "JsonMaster.h"
#include "ReflectionIncludeList.h"

namespace nsTornadoEngine
{
    class DllExport TTornadoEngineJsonSerializer
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
    
    public:
        static void _Serialize(nsMathTools::TMatrix16* p, Jobj& obj);
        static void _Deserialize(nsMathTools::TMatrix16* p, const Jobj& obj);
        
        static void _Serialize(nsMathTools::TMatrix9* p, Jobj& obj);
        static void _Deserialize(nsMathTools::TMatrix9* p, const Jobj& obj);
        
        static void _Serialize(nsMathTools::TOrientation* p, Jobj& obj);
        static void _Deserialize(nsMathTools::TOrientation* p, const Jobj& obj);
        
        static void _Serialize(nsMathTools::TPlane* p, Jobj& obj);
        static void _Deserialize(nsMathTools::TPlane* p, const Jobj& obj);
        
        static void _Serialize(nsMathTools::TPoint2* p, Jobj& obj);
        static void _Deserialize(nsMathTools::TPoint2* p, const Jobj& obj);
        
        static void _Serialize(nsMathTools::TQuaternion* p, Jobj& obj);
        static void _Deserialize(nsMathTools::TQuaternion* p, const Jobj& obj);
        
        static void _Serialize(nsMathTools::TVector2* p, Jobj& obj);
        static void _Deserialize(nsMathTools::TVector2* p, const Jobj& obj);
        
        static void _Serialize(nsMathTools::TVector3* p, Jobj& obj);
        static void _Deserialize(nsMathTools::TVector3* p, const Jobj& obj);
        
        static void _Serialize(nsMathTools::TVector4* p, Jobj& obj);
        static void _Deserialize(nsMathTools::TVector4* p, const Jobj& obj);
        
        static std::string _SerializeEnum(nsTornadoEngine::ModuleType* p);
        static void _DeserializeEnum(std::string& str, nsTornadoEngine::ModuleType* p);
        
        static void _Serialize(nsTornadoEngine::TComponentContent* p, Jobj& obj);
        static void _Deserialize(nsTornadoEngine::TComponentContent* p, const Jobj& obj);
        
        static void _Serialize(nsTornadoEngine::TConveyorConfig* p, Jobj& obj);
        static void _Deserialize(nsTornadoEngine::TConveyorConfig* p, const Jobj& obj);
        
        static void _Serialize(nsTornadoEngine::TEntityContent* p, Jobj& obj);
        static void _Deserialize(nsTornadoEngine::TEntityContent* p, const Jobj& obj);
        
        static void _Serialize(nsTornadoEngine::TFrameworkResources* p, Jobj& obj);
        static void _Deserialize(nsTornadoEngine::TFrameworkResources* p, const Jobj& obj);
        
        static void _Serialize(nsTornadoEngine::TGameEngineResources* p, Jobj& obj);
        static void _Deserialize(nsTornadoEngine::TGameEngineResources* p, const Jobj& obj);
        
        static void _Serialize(nsTornadoEngine::TGeneratorConfig* p, Jobj& obj);
        static void _Deserialize(nsTornadoEngine::TGeneratorConfig* p, const Jobj& obj);
        
        static void _Serialize(nsTornadoEngine::TGraphicEngineResources* p, Jobj& obj);
        static void _Deserialize(nsTornadoEngine::TGraphicEngineResources* p, const Jobj& obj);
        
        static void _Serialize(nsTornadoEngine::TOgreCfg* p, Jobj& obj);
        static void _Deserialize(nsTornadoEngine::TOgreCfg* p, const Jobj& obj);
        
        static void _Serialize(nsTornadoEngine::TProjectConfig* p, Jobj& obj);
        static void _Deserialize(nsTornadoEngine::TProjectConfig* p, const Jobj& obj);
        
        static void _Serialize(nsTornadoEngine::TProjectInfo* p, Jobj& obj);
        static void _Deserialize(nsTornadoEngine::TProjectInfo* p, const Jobj& obj);
        
        static void _Serialize(nsTornadoEngine::TSceneContent* p, Jobj& obj);
        static void _Deserialize(nsTornadoEngine::TSceneContent* p, const Jobj& obj);
        
        static void _Serialize(nsTornadoEngine::TSceneContentMap* p, Jobj& obj);
        static void _Deserialize(nsTornadoEngine::TSceneContentMap* p, const Jobj& obj);
        
        static void _Serialize(nsTornadoEngine::TSceneHeader* p, Jobj& obj);
        static void _Deserialize(nsTornadoEngine::TSceneHeader* p, const Jobj& obj);
        
    };
    //------------------------------------------------------------------------------------------------------------
    template <typename Type>
    static void TTornadoEngineJsonSerializer::Serialize(Type* p, std::string& str)
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
    static bool TTornadoEngineJsonSerializer::Deserialize(Type* p, const std::string& str, std::string& err)
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
