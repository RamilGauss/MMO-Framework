/*
Project Component
*/
// ReflectionCodeGenerator version 2.5.0, build 59 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, RTTI, TypeInformation]
// File has been generated at 2024_12_26 15:38:37.594
#include "ComponentJson.h"
#include "Base/Common/JsonPopMaster.h"
#include "Base/Common/JsonPushMaster.h"
#include "Base/Common/SingletonManager.h"
#include "Base/Common/RunTimeTypeIndex.h"

using namespace nsTornadoEditor;

using POM = TJsonPopMaster;
using PUM = TJsonPushMaster;

std::vector<TComponentJson::TypeFunc> TComponentJson::mTypeFuncVector;

void TComponentJson::Init()
{
    static bool isNeedInit = true;
    if ( !isNeedInit ) {
        return;
    }
    isNeedInit = false;
    
    auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();
    
    std::list<TypeFunc> funcs;
    
    TypeFunc _nsTornadoEditor_TAbsoluteFilePathComponentTypeFunc;
    _nsTornadoEditor_TAbsoluteFilePathComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEditor::TAbsoluteFilePathComponent>((nsTornadoEditor::TAbsoluteFilePathComponent*) p, str);
    };
    _nsTornadoEditor_TAbsoluteFilePathComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEditor::TAbsoluteFilePathComponent>((nsTornadoEditor::TAbsoluteFilePathComponent*) p, str, err);
    };
    
    _nsTornadoEditor_TAbsoluteFilePathComponentTypeFunc.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TAbsoluteFilePathComponent>();
    
    funcs.push_back(_nsTornadoEditor_TAbsoluteFilePathComponentTypeFunc);
    
    TypeFunc _nsTornadoEditor_TAssetAbsoluteFilePathComponentTypeFunc;
    _nsTornadoEditor_TAssetAbsoluteFilePathComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEditor::TAssetAbsoluteFilePathComponent>((nsTornadoEditor::TAssetAbsoluteFilePathComponent*) p, str);
    };
    _nsTornadoEditor_TAssetAbsoluteFilePathComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEditor::TAssetAbsoluteFilePathComponent>((nsTornadoEditor::TAssetAbsoluteFilePathComponent*) p, str, err);
    };
    
    _nsTornadoEditor_TAssetAbsoluteFilePathComponentTypeFunc.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TAssetAbsoluteFilePathComponent>();
    
    funcs.push_back(_nsTornadoEditor_TAssetAbsoluteFilePathComponentTypeFunc);
    
    TypeFunc _nsTornadoEditor_TEditorInfoTagComponentTypeFunc;
    _nsTornadoEditor_TEditorInfoTagComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEditor::TEditorInfoTagComponent>((nsTornadoEditor::TEditorInfoTagComponent*) p, str);
    };
    _nsTornadoEditor_TEditorInfoTagComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEditor::TEditorInfoTagComponent>((nsTornadoEditor::TEditorInfoTagComponent*) p, str, err);
    };
    
    _nsTornadoEditor_TEditorInfoTagComponentTypeFunc.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TEditorInfoTagComponent>();
    
    funcs.push_back(_nsTornadoEditor_TEditorInfoTagComponentTypeFunc);
    
    TypeFunc _nsTornadoEditor_TFileHierarchyWindowRefreshTagComponentTypeFunc;
    _nsTornadoEditor_TFileHierarchyWindowRefreshTagComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEditor::TFileHierarchyWindowRefreshTagComponent>((nsTornadoEditor::TFileHierarchyWindowRefreshTagComponent*) p, str);
    };
    _nsTornadoEditor_TFileHierarchyWindowRefreshTagComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEditor::TFileHierarchyWindowRefreshTagComponent>((nsTornadoEditor::TFileHierarchyWindowRefreshTagComponent*) p, str, err);
    };
    
    _nsTornadoEditor_TFileHierarchyWindowRefreshTagComponentTypeFunc.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TFileHierarchyWindowRefreshTagComponent>();
    
    funcs.push_back(_nsTornadoEditor_TFileHierarchyWindowRefreshTagComponentTypeFunc);
    
    TypeFunc _nsTornadoEditor_TFileHierarchyWindowTagComponentTypeFunc;
    _nsTornadoEditor_TFileHierarchyWindowTagComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEditor::TFileHierarchyWindowTagComponent>((nsTornadoEditor::TFileHierarchyWindowTagComponent*) p, str);
    };
    _nsTornadoEditor_TFileHierarchyWindowTagComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEditor::TFileHierarchyWindowTagComponent>((nsTornadoEditor::TFileHierarchyWindowTagComponent*) p, str, err);
    };
    
    _nsTornadoEditor_TFileHierarchyWindowTagComponentTypeFunc.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TFileHierarchyWindowTagComponent>();
    
    funcs.push_back(_nsTornadoEditor_TFileHierarchyWindowTagComponentTypeFunc);
    
    TypeFunc _nsTornadoEditor_TFilePathNodeComponentTypeFunc;
    _nsTornadoEditor_TFilePathNodeComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEditor::TFilePathNodeComponent>((nsTornadoEditor::TFilePathNodeComponent*) p, str);
    };
    _nsTornadoEditor_TFilePathNodeComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEditor::TFilePathNodeComponent>((nsTornadoEditor::TFilePathNodeComponent*) p, str, err);
    };
    
    _nsTornadoEditor_TFilePathNodeComponentTypeFunc.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TFilePathNodeComponent>();
    
    funcs.push_back(_nsTornadoEditor_TFilePathNodeComponentTypeFunc);
    
    TypeFunc _nsTornadoEditor_TInspectorWindowTagComponentTypeFunc;
    _nsTornadoEditor_TInspectorWindowTagComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEditor::TInspectorWindowTagComponent>((nsTornadoEditor::TInspectorWindowTagComponent*) p, str);
    };
    _nsTornadoEditor_TInspectorWindowTagComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEditor::TInspectorWindowTagComponent>((nsTornadoEditor::TInspectorWindowTagComponent*) p, str, err);
    };
    
    _nsTornadoEditor_TInspectorWindowTagComponentTypeFunc.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TInspectorWindowTagComponent>();
    
    funcs.push_back(_nsTornadoEditor_TInspectorWindowTagComponentTypeFunc);
    
    TypeFunc _nsTornadoEditor_TMainWindowPrefabGuidComponentTypeFunc;
    _nsTornadoEditor_TMainWindowPrefabGuidComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEditor::TMainWindowPrefabGuidComponent>((nsTornadoEditor::TMainWindowPrefabGuidComponent*) p, str);
    };
    _nsTornadoEditor_TMainWindowPrefabGuidComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEditor::TMainWindowPrefabGuidComponent>((nsTornadoEditor::TMainWindowPrefabGuidComponent*) p, str, err);
    };
    
    _nsTornadoEditor_TMainWindowPrefabGuidComponentTypeFunc.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TMainWindowPrefabGuidComponent>();
    
    funcs.push_back(_nsTornadoEditor_TMainWindowPrefabGuidComponentTypeFunc);
    
    TypeFunc _nsTornadoEditor_TMainWindowTagComponentTypeFunc;
    _nsTornadoEditor_TMainWindowTagComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEditor::TMainWindowTagComponent>((nsTornadoEditor::TMainWindowTagComponent*) p, str);
    };
    _nsTornadoEditor_TMainWindowTagComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEditor::TMainWindowTagComponent>((nsTornadoEditor::TMainWindowTagComponent*) p, str, err);
    };
    
    _nsTornadoEditor_TMainWindowTagComponentTypeFunc.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TMainWindowTagComponent>();
    
    funcs.push_back(_nsTornadoEditor_TMainWindowTagComponentTypeFunc);
    
    TypeFunc _nsTornadoEditor_TObjectHierarchyWindowRefreshTagComponentTypeFunc;
    _nsTornadoEditor_TObjectHierarchyWindowRefreshTagComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEditor::TObjectHierarchyWindowRefreshTagComponent>((nsTornadoEditor::TObjectHierarchyWindowRefreshTagComponent*) p, str);
    };
    _nsTornadoEditor_TObjectHierarchyWindowRefreshTagComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEditor::TObjectHierarchyWindowRefreshTagComponent>((nsTornadoEditor::TObjectHierarchyWindowRefreshTagComponent*) p, str, err);
    };
    
    _nsTornadoEditor_TObjectHierarchyWindowRefreshTagComponentTypeFunc.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TObjectHierarchyWindowRefreshTagComponent>();
    
    funcs.push_back(_nsTornadoEditor_TObjectHierarchyWindowRefreshTagComponentTypeFunc);
    
    TypeFunc _nsTornadoEditor_TObjectHierarchyWindowTagComponentTypeFunc;
    _nsTornadoEditor_TObjectHierarchyWindowTagComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEditor::TObjectHierarchyWindowTagComponent>((nsTornadoEditor::TObjectHierarchyWindowTagComponent*) p, str);
    };
    _nsTornadoEditor_TObjectHierarchyWindowTagComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEditor::TObjectHierarchyWindowTagComponent>((nsTornadoEditor::TObjectHierarchyWindowTagComponent*) p, str, err);
    };
    
    _nsTornadoEditor_TObjectHierarchyWindowTagComponentTypeFunc.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TObjectHierarchyWindowTagComponent>();
    
    funcs.push_back(_nsTornadoEditor_TObjectHierarchyWindowTagComponentTypeFunc);
    
    TypeFunc _nsTornadoEditor_TProjectConfigComponentTypeFunc;
    _nsTornadoEditor_TProjectConfigComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEditor::TProjectConfigComponent>((nsTornadoEditor::TProjectConfigComponent*) p, str);
    };
    _nsTornadoEditor_TProjectConfigComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEditor::TProjectConfigComponent>((nsTornadoEditor::TProjectConfigComponent*) p, str, err);
    };
    
    _nsTornadoEditor_TProjectConfigComponentTypeFunc.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TProjectConfigComponent>();
    
    funcs.push_back(_nsTornadoEditor_TProjectConfigComponentTypeFunc);
    
    int max = 0;
    for (auto& f : funcs) {
        max = std::max(f.rtti, max);
    }
    
    mTypeFuncVector.resize(max + 1);
    for (auto& f : funcs) {
        mTypeFuncVector[f.rtti] = f;
    }
}
//---------------------------------------------------------------------------------------
void TComponentJson::Serialize(void* p, std::string& str, int rtti)
{
    Init();
    mTypeFuncVector[rtti].serializeFunc(p, str);
}
//---------------------------------------------------------------------------------------
bool TComponentJson::Deserialize(void* p, const std::string& str, int rtti, std::string& err)
{
    Init();
    return mTypeFuncVector[rtti].deserializeFunc(p, str, err);
}
//---------------------------------------------------------------------------------------
bool TComponentJson::Has(int rtti)
{
    Init();
    if (rtti < 0 || rtti >= mTypeFuncVector.size()) {
        return false;
    }
    return mTypeFuncVector[rtti].serializeFunc != nullptr;
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsTornadoEditor::TAbsoluteFilePathComponent* p, Jobj& obj)
{
    PUM::Push(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsTornadoEditor::TAbsoluteFilePathComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsTornadoEditor::TAssetAbsoluteFilePathComponent* p, Jobj& obj)
{
    PUM::Push(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsTornadoEditor::TAssetAbsoluteFilePathComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsTornadoEditor::TEditorInfoTagComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsTornadoEditor::TEditorInfoTagComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsTornadoEditor::TFileHierarchyWindowRefreshTagComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsTornadoEditor::TFileHierarchyWindowRefreshTagComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsTornadoEditor::TFileHierarchyWindowTagComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsTornadoEditor::TFileHierarchyWindowTagComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsTornadoEditor::TFilePathNodeComponent* p, Jobj& obj)
{
    PUM::Push(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsTornadoEditor::TFilePathNodeComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsTornadoEditor::TInspectorWindowTagComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsTornadoEditor::TInspectorWindowTagComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsTornadoEditor::TMainWindowPrefabGuidComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsTornadoEditor::TMainWindowPrefabGuidComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsTornadoEditor::TMainWindowTagComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsTornadoEditor::TMainWindowTagComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsTornadoEditor::TObjectHierarchyWindowRefreshTagComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsTornadoEditor::TObjectHierarchyWindowRefreshTagComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsTornadoEditor::TObjectHierarchyWindowTagComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsTornadoEditor::TObjectHierarchyWindowTagComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Serialize(nsTornadoEditor::TProjectConfigComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJson::_Deserialize(nsTornadoEditor::TProjectConfigComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
