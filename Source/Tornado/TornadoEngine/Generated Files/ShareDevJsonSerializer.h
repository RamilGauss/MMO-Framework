/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.2.1, build 52, info Json, Binary, MyGUI, EntityManager, Reflection, TypeInformation
// File has been generated at 2021_06_19 11:49:51.245
	
#pragma once

#include <vector>
#include <string>
#include <functional>
#include "JsonMaster.h"
#include "IncludeList.h"

namespace nsShareDev
{
    class DllExport TShareDevJsonSerializer
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
        static void _Serialize(TBaseResources* p, Jobj& obj);
        static void _Deserialize(TBaseResources* p, const Jobj& obj);
        
        static void _Serialize(TFrameworkResources* p, Jobj& obj);
        static void _Deserialize(TFrameworkResources* p, const Jobj& obj);
        
        static void _Serialize(TGUIResources* p, Jobj& obj);
        static void _Deserialize(TGUIResources* p, const Jobj& obj);
        
        static void _Serialize(TGameEngineResources* p, Jobj& obj);
        static void _Deserialize(TGameEngineResources* p, const Jobj& obj);
        
        static void _Serialize(TGameResources* p, Jobj& obj);
        static void _Deserialize(TGameResources* p, const Jobj& obj);
        
        static void _Serialize(TGraphicEngineResources* p, Jobj& obj);
        static void _Deserialize(TGraphicEngineResources* p, const Jobj& obj);
        
        static void _Serialize(TOgreCfg* p, Jobj& obj);
        static void _Deserialize(TOgreCfg* p, const Jobj& obj);
        
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
        
    };
    //------------------------------------------------------------------------------------------------------------
    template <typename Type>
    static void TShareDevJsonSerializer::Serialize(Type* p, std::string& str)
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
    static bool TShareDevJsonSerializer::Deserialize(Type* p, const std::string& str, std::string& err)
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