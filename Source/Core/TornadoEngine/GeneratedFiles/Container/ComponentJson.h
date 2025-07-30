/*
Core Component
*/
// ReflectionCodeGenerator version 2.5.0, build 59 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, RTTI, TypeInformation]
// File has been generated at 2025_01_30 15:40:51.201
#pragma once

#include <vector>
#include <string>
#include <functional>
#include "Base/Common/JsonMaster.h"
#include "ComponentIncludeList.h"

namespace nsTornadoEngine
{
    class DllExport TComponentJson
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
        static void _Serialize(nsCommonWrapper::TGlobalMatrixComponent* p, Jobj& obj);
        static void _Deserialize(nsCommonWrapper::TGlobalMatrixComponent* p, const Jobj& obj);
        
        static void _Serialize(nsCommonWrapper::TGuidComponent* p, Jobj& obj);
        static void _Deserialize(nsCommonWrapper::TGuidComponent* p, const Jobj& obj);
        
        static void _Serialize(nsCommonWrapper::TNameComponent* p, Jobj& obj);
        static void _Deserialize(nsCommonWrapper::TNameComponent* p, const Jobj& obj);
        
        static void _Serialize(nsCommonWrapper::TNeedDestroyObjectTagComponent* p, Jobj& obj);
        static void _Deserialize(nsCommonWrapper::TNeedDestroyObjectTagComponent* p, const Jobj& obj);
        
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
        
        static void _Serialize(nsGuiWrapper::TAnchorsComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TAnchorsComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TButtonComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TButtonComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TColorComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TColorComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TDialogComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TDialogComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TFocusComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TFocusComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TFrameComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TFrameComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TGridComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TGridComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::THorizontalAlignComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::THorizontalAlignComponent* p, const Jobj& obj);
        
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
        
        static void _Serialize(nsGuiWrapper::TMaxSizeComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TMaxSizeComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TMenuNodeComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TMenuNodeComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TMinDistanceToParentComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TMinDistanceToParentComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TMinSizeComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TMinSizeComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TNodeIconComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TNodeIconComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TPaddingComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TPaddingComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TPositionComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TPositionComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TPositionInGridComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TPositionInGridComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TSelectedTreeNodeGuidComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TSelectedTreeNodeGuidComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TSizeComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TSizeComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TSizeInGridComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TSizeInGridComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TSpacingComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TSpacingComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TTextureReferenceComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TTextureReferenceComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TTextureSizeComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TTextureSizeComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TTextureUvComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TTextureUvComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TTitleComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TTitleComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TTreeNodeComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TTreeNodeComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TTreeViewComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TTreeViewComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TVerticalAlignComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TVerticalAlignComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TVisibilityComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TVisibilityComponent* p, const Jobj& obj);
        
        static void _Serialize(nsGuiWrapper::TWindowComponent* p, Jobj& obj);
        static void _Deserialize(nsGuiWrapper::TWindowComponent* p, const Jobj& obj);
        
        static std::string _SerializeEnum(nsGuiWrapper::THorizontalAlignComponent::Type* p);
        static void _DeserializeEnum(std::string& str, nsGuiWrapper::THorizontalAlignComponent::Type* p);
        
        static std::string _SerializeEnum(nsGuiWrapper::TVerticalAlignComponent::Type* p);
        static void _DeserializeEnum(std::string& str, nsGuiWrapper::TVerticalAlignComponent::Type* p);
        
        static void _Serialize(nsLogicWrapper::TGlobalHandlerComponent* p, Jobj& obj);
        static void _Deserialize(nsLogicWrapper::TGlobalHandlerComponent* p, const Jobj& obj);
        
        static void _Serialize(nsLogicWrapper::TLocalHandlerComponent* p, Jobj& obj);
        static void _Deserialize(nsLogicWrapper::TLocalHandlerComponent* p, const Jobj& obj);
        
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
        
        static std::string _SerializeEnum(nsLogicWrapper::TGlobalHandlerComponent::Filter* p);
        static void _DeserializeEnum(std::string& str, nsLogicWrapper::TGlobalHandlerComponent::Filter* p);
        
        static std::string _SerializeEnum(nsLogicWrapper::TLocalHandlerComponent::Filter* p);
        static void _DeserializeEnum(std::string& str, nsLogicWrapper::TLocalHandlerComponent::Filter* p);
        
        static void _Serialize(nsMathTools::TMatrix16* p, Jobj& obj);
        static void _Deserialize(nsMathTools::TMatrix16* p, const Jobj& obj);
        
        static void _Serialize(nsMathTools::TVector2* p, Jobj& obj);
        static void _Deserialize(nsMathTools::TVector2* p, const Jobj& obj);
        
    };
    //------------------------------------------------------------------------------------------------------------
    template <typename Type>
    void TComponentJson::Serialize(Type* p, std::string& str)
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
    bool TComponentJson::Deserialize(Type* p, const std::string& str, std::string& err)
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
