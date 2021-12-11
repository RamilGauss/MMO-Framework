/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.2.3, build 54 [Json, Binary, ImGui, EntityManager, Reflection, TypeInformation]
// File has been generated at 2021_12_11 16:12:02.455
	
#pragma once

#include <vector>
#include <string>
#include <functional>
#include "JsonMaster.h"
#include "ComponentIncludeList.h"

namespace nsTornadoEngine
{
    class DllExport TComponentJsonSerializer
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
        static void _Serialize(nsCommonWrapper::TGuidComponent* p, Jobj& obj);
        static void _Deserialize(nsCommonWrapper::TGuidComponent* p, const Jobj& obj);
        
        static void _Serialize(nsCommonWrapper::TNameComponent* p, Jobj& obj);
        static void _Deserialize(nsCommonWrapper::TNameComponent* p, const Jobj& obj);
        
        static void _Serialize(nsCommonWrapper::TNeedDestroyPrefabComponent* p, Jobj& obj);
        static void _Deserialize(nsCommonWrapper::TNeedDestroyPrefabComponent* p, const Jobj& obj);
        
        static void _Serialize(nsCommonWrapper::TNeedDestroySceneComponent* p, Jobj& obj);
        static void _Deserialize(nsCommonWrapper::TNeedDestroySceneComponent* p, const Jobj& obj);
        
        static void _Serialize(nsCommonWrapper::TNeedUnloadPrefabComponent* p, Jobj& obj);
        static void _Deserialize(nsCommonWrapper::TNeedUnloadPrefabComponent* p, const Jobj& obj);
        
        static void _Serialize(nsCommonWrapper::TNeedUnloadSceneComponent* p, Jobj& obj);
        static void _Deserialize(nsCommonWrapper::TNeedUnloadSceneComponent* p, const Jobj& obj);
        
        static void _Serialize(nsCommonWrapper::TObjectInMemoryComponent* p, Jobj& obj);
        static void _Deserialize(nsCommonWrapper::TObjectInMemoryComponent* p, const Jobj& obj);
        
        static void _Serialize(nsCommonWrapper::TParentGuidComponent* p, Jobj& obj);
        static void _Deserialize(nsCommonWrapper::TParentGuidComponent* p, const Jobj& obj);
        
        static void _Serialize(nsCommonWrapper::TPrefabGuidComponent* p, Jobj& obj);
        static void _Deserialize(nsCommonWrapper::TPrefabGuidComponent* p, const Jobj& obj);
        
        static void _Serialize(nsCommonWrapper::TPrefabInstanceGuidComponent* p, Jobj& obj);
        static void _Deserialize(nsCommonWrapper::TPrefabInstanceGuidComponent* p, const Jobj& obj);
        
        static void _Serialize(nsCommonWrapper::TPrefabOriginalGuidComponent* p, Jobj& obj);
        static void _Deserialize(nsCommonWrapper::TPrefabOriginalGuidComponent* p, const Jobj& obj);
        
        static void _Serialize(nsCommonWrapper::TPrefabRootComponent* p, Jobj& obj);
        static void _Deserialize(nsCommonWrapper::TPrefabRootComponent* p, const Jobj& obj);
        
        static void _Serialize(nsCommonWrapper::TSceneGuidComponent* p, Jobj& obj);
        static void _Deserialize(nsCommonWrapper::TSceneGuidComponent* p, const Jobj& obj);
        
        static void _Serialize(nsCommonWrapper::TSceneInstanceGuidComponent* p, Jobj& obj);
        static void _Deserialize(nsCommonWrapper::TSceneInstanceGuidComponent* p, const Jobj& obj);
        
        static void _Serialize(nsCommonWrapper::TSceneOriginalGuidComponent* p, Jobj& obj);
        static void _Deserialize(nsCommonWrapper::TSceneOriginalGuidComponent* p, const Jobj& obj);
        
        static void _Serialize(nsCommonWrapper::TSceneRootComponent* p, Jobj& obj);
        static void _Deserialize(nsCommonWrapper::TSceneRootComponent* p, const Jobj& obj);
        
        static void _Serialize(nsCommonWrapper::TTransformComponent* p, Jobj& obj);
        static void _Deserialize(nsCommonWrapper::TTransformComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGraphicWrapper::TCameraComponent* p, Jobj& obj);
        static void _Deserialize(nsGraphicWrapper::TCameraComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGraphicWrapper::TLightComponent* p, Jobj& obj);
        static void _Deserialize(nsGraphicWrapper::TLightComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TButtonClickHandlerComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TButtonClickHandlerComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TButtonComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TButtonComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TFocusComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TFocusComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TFrameComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TFrameComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TMainWindowComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TMainWindowComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TPositionComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TPositionComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TSizeComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TSizeComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TTitleComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TTitleComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TVisibilityComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TVisibilityComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TWindowComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TWindowComponent* p, const Jobj& obj);
        
        static void _Serialize(nsLogicWrapper::TFeatureComponent* p, Jobj& obj);
        static void _Deserialize(nsLogicWrapper::TFeatureComponent* p, const Jobj& obj);
        
        static void _Serialize(nsLogicWrapper::TPrefabObjectReferenceComponent* p, Jobj& obj);
        static void _Deserialize(nsLogicWrapper::TPrefabObjectReferenceComponent* p, const Jobj& obj);
        
        static void _Serialize(nsLogicWrapper::TPrefabReferenceComponent* p, Jobj& obj);
        static void _Deserialize(nsLogicWrapper::TPrefabReferenceComponent* p, const Jobj& obj);
        
        static void _Serialize(nsLogicWrapper::TSceneObjectReferenceComponent* p, Jobj& obj);
        static void _Deserialize(nsLogicWrapper::TSceneObjectReferenceComponent* p, const Jobj& obj);
        
        static void _Serialize(nsLogicWrapper::TSceneReferenceComponent* p, Jobj& obj);
        static void _Deserialize(nsLogicWrapper::TSceneReferenceComponent* p, const Jobj& obj);
        
        static void _Serialize(nsMathTools::TMatrix16* p, Jobj& obj);
        static void _Deserialize(nsMathTools::TMatrix16* p, const Jobj& obj);
        
    };
    //------------------------------------------------------------------------------------------------------------
    template <typename Type>
    static void TComponentJsonSerializer::Serialize(Type* p, std::string& str)
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
    static bool TComponentJsonSerializer::Deserialize(Type* p, const std::string& str, std::string& err)
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
