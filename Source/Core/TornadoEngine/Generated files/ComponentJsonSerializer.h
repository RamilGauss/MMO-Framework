/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.3.0, build 57 [Json, Binary, ImGui, EcsComponentExtension, EcsSystemExtension, Reflection, TypeInformation]
// File has been generated at 2022_07_26 07:58:00.300
	
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
        
        static void _Serialize(nsCommonWrapper::THandlerTarget* p, Jobj& obj);
        static void _Deserialize(nsCommonWrapper::THandlerTarget* p, const Jobj& obj);
        
        static void _Serialize(nsCommonWrapper::TNameComponent* p, Jobj& obj);
        static void _Deserialize(nsCommonWrapper::TNameComponent* p, const Jobj& obj);
        
        static void _Serialize(nsCommonWrapper::TNeedDestroyObjectTagComponent* p, Jobj& obj);
        static void _Deserialize(nsCommonWrapper::TNeedDestroyObjectTagComponent* p, const Jobj& obj);
        
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
        
        static void _Serialize(nsCommonWrapper::TProjectionToUniverseComponent* p, Jobj& obj);
        static void _Deserialize(nsCommonWrapper::TProjectionToUniverseComponent* p, const Jobj& obj);
        
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
        
        static void _Serialize(nsCommonWrapper::TUniverseGuidComponent* p, Jobj& obj);
        static void _Deserialize(nsCommonWrapper::TUniverseGuidComponent* p, const Jobj& obj);
        
        static void _Serialize(nsCommonWrapper::TUniverseIndexComponent* p, Jobj& obj);
        static void _Deserialize(nsCommonWrapper::TUniverseIndexComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGraphicWrapper::TCameraComponent* p, Jobj& obj);
        static void _Deserialize(nsGraphicWrapper::TCameraComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGraphicWrapper::TCameraTextureTagComponent* p, Jobj& obj);
        static void _Deserialize(nsGraphicWrapper::TCameraTextureTagComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGraphicWrapper::TCameraWindowPositionComponent* p, Jobj& obj);
        static void _Deserialize(nsGraphicWrapper::TCameraWindowPositionComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGraphicWrapper::TCameraWindowSizeComponent* p, Jobj& obj);
        static void _Deserialize(nsGraphicWrapper::TCameraWindowSizeComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGraphicWrapper::TGuiCameraTagComponent* p, Jobj& obj);
        static void _Deserialize(nsGraphicWrapper::TGuiCameraTagComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGraphicWrapper::TLightComponent* p, Jobj& obj);
        static void _Deserialize(nsGraphicWrapper::TLightComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGraphicWrapper::TRenderToTextureCameraComponent* p, Jobj& obj);
        static void _Deserialize(nsGraphicWrapper::TRenderToTextureCameraComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGraphicWrapper::TTextureFromCameraComponent* p, Jobj& obj);
        static void _Deserialize(nsGraphicWrapper::TTextureFromCameraComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGraphicWrapper::TTextureFromFileComponent* p, Jobj& obj);
        static void _Deserialize(nsGraphicWrapper::TTextureFromFileComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGraphicWrapper::TUniverseCameraComponent* p, Jobj& obj);
        static void _Deserialize(nsGraphicWrapper::TUniverseCameraComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TButtonClickHandlerComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TButtonClickHandlerComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TButtonComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TButtonComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TDialogCloseEventHandlerComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TDialogCloseEventHandlerComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TDialogComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TDialogComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TFocusComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TFocusComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TFrameComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TFrameComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TFrameKeyHandlerComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TFrameKeyHandlerComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TFrameMouseClickHandlerComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TFrameMouseClickHandlerComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TFrameMouseMoveHandlerComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TFrameMouseMoveHandlerComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TFrameMouseWheelHandlerComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TFrameMouseWheelHandlerComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TInputTextComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TInputTextComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TInputTextValueComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TInputTextValueComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TLabelComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TLabelComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TLabelValueComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TLabelValueComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TMainWindowComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TMainWindowComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TMenuNodeClickHandlerComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TMenuNodeClickHandlerComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TMenuNodeComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TMenuNodeComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TNodeIconComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TNodeIconComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TPositionComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TPositionComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TSelectedTreeNodeGuidComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TSelectedTreeNodeGuidComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TSizeComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TSizeComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TTitleComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TTitleComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TTreeNodeComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TTreeNodeComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TTreeViewComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TTreeViewComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TVisibilityComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TVisibilityComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TWindowCloseEventHandlerComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TWindowCloseEventHandlerComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TWindowComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TWindowComponent* p, const Jobj& obj);
        
        static void _Serialize(nsLogicWrapper::TObjectInstanceEndHandlerComponent* p, Jobj& obj);
        static void _Deserialize(nsLogicWrapper::TObjectInstanceEndHandlerComponent* p, const Jobj& obj);
        
        static void _Serialize(nsLogicWrapper::TPrefabObjectReferenceComponent* p, Jobj& obj);
        static void _Deserialize(nsLogicWrapper::TPrefabObjectReferenceComponent* p, const Jobj& obj);
        
        static void _Serialize(nsLogicWrapper::TPrefabReferenceComponent* p, Jobj& obj);
        static void _Deserialize(nsLogicWrapper::TPrefabReferenceComponent* p, const Jobj& obj);
        
        static void _Serialize(nsLogicWrapper::TSceneObjectReferenceComponent* p, Jobj& obj);
        static void _Deserialize(nsLogicWrapper::TSceneObjectReferenceComponent* p, const Jobj& obj);
        
        static void _Serialize(nsLogicWrapper::TSceneReferenceComponent* p, Jobj& obj);
        static void _Deserialize(nsLogicWrapper::TSceneReferenceComponent* p, const Jobj& obj);
        
        static void _Serialize(nsLogicWrapper::TSystemComponent* p, Jobj& obj);
        static void _Deserialize(nsLogicWrapper::TSystemComponent* p, const Jobj& obj);
        
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
