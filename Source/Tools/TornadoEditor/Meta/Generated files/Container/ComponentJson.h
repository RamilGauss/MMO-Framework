/*
Project Component
*/
// ReflectionCodeGenerator version 2.4.2, build 58 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, TypeInformation]
// File has been generated at 2023_10_29 11:16:44.809
	
#pragma once

#include <vector>
#include <string>
#include <functional>
#include "JsonMaster.h"
#include "ComponentIncludeList.h"

namespace nsTornadoEditor
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
        static void _Serialize(nsTornadoEditor::TAbsoluteFilePathComponent* p, Jobj& obj);
        static void _Deserialize(nsTornadoEditor::TAbsoluteFilePathComponent* p, const Jobj& obj);
        
        static void _Serialize(nsTornadoEditor::TAssetAbsoluteFilePathComponent* p, Jobj& obj);
        static void _Deserialize(nsTornadoEditor::TAssetAbsoluteFilePathComponent* p, const Jobj& obj);
        
        static void _Serialize(nsTornadoEditor::TEditorInfoTagComponent* p, Jobj& obj);
        static void _Deserialize(nsTornadoEditor::TEditorInfoTagComponent* p, const Jobj& obj);
        
        static void _Serialize(nsTornadoEditor::TFileHierarchyWindowRefreshTagComponent* p, Jobj& obj);
        static void _Deserialize(nsTornadoEditor::TFileHierarchyWindowRefreshTagComponent* p, const Jobj& obj);
        
        static void _Serialize(nsTornadoEditor::TFileHierarchyWindowTagComponent* p, Jobj& obj);
        static void _Deserialize(nsTornadoEditor::TFileHierarchyWindowTagComponent* p, const Jobj& obj);
        
        static void _Serialize(nsTornadoEditor::TFilePathNodeComponent* p, Jobj& obj);
        static void _Deserialize(nsTornadoEditor::TFilePathNodeComponent* p, const Jobj& obj);
        
        static void _Serialize(nsTornadoEditor::TInspectorWindowTagComponent* p, Jobj& obj);
        static void _Deserialize(nsTornadoEditor::TInspectorWindowTagComponent* p, const Jobj& obj);
        
        static void _Serialize(nsTornadoEditor::TMainWindowPrefabGuidComponent* p, Jobj& obj);
        static void _Deserialize(nsTornadoEditor::TMainWindowPrefabGuidComponent* p, const Jobj& obj);
        
        static void _Serialize(nsTornadoEditor::TMainWindowTagComponent* p, Jobj& obj);
        static void _Deserialize(nsTornadoEditor::TMainWindowTagComponent* p, const Jobj& obj);
        
        static void _Serialize(nsTornadoEditor::TObjectHierarchyWindowRefreshTagComponent* p, Jobj& obj);
        static void _Deserialize(nsTornadoEditor::TObjectHierarchyWindowRefreshTagComponent* p, const Jobj& obj);
        
        static void _Serialize(nsTornadoEditor::TObjectHierarchyWindowTagComponent* p, Jobj& obj);
        static void _Deserialize(nsTornadoEditor::TObjectHierarchyWindowTagComponent* p, const Jobj& obj);
        
        static void _Serialize(nsTornadoEditor::TProjectConfigComponent* p, Jobj& obj);
        static void _Deserialize(nsTornadoEditor::TProjectConfigComponent* p, const Jobj& obj);
        
    };
    //------------------------------------------------------------------------------------------------------------
    template <typename Type>
    static void TComponentJson::Serialize(Type* p, std::string& str)
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
    static bool TComponentJson::Deserialize(Type* p, const std::string& str, std::string& err)
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
