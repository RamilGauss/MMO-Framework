/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.2.5, build 56 [Json, Binary, ImGui, EntityManager, Reflection, TypeInformation]
// File has been generated at 2022_02_05 20:40:52.954
	
#include "ComponentJsonSerializer.h"
#include "JsonPopMaster.h"
#include "JsonPushMaster.h"
#include "SingletonManager.h"
#include "RunTimeTypeIndex.h"

using namespace nsTornadoEditor;

using POM = TJsonPopMaster;
using PUM = TJsonPushMaster;

std::vector<TComponentJsonSerializer::TypeFunc> TComponentJsonSerializer::mTypeFuncVector;

void TComponentJsonSerializer::Init()
{
    static bool isNeedInit = true;
    if ( !isNeedInit ) {
        return;
    }
    isNeedInit = false;
    
    auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();
    
    std::map<int, TypeFunc> m;
    
    TypeFunc _nsTornadoEditor_TAbsoluteFilePathComponentTypeFunc;
    _nsTornadoEditor_TAbsoluteFilePathComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEditor::TAbsoluteFilePathComponent>((nsTornadoEditor::TAbsoluteFilePathComponent*) p, str);
    };
    _nsTornadoEditor_TAbsoluteFilePathComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEditor::TAbsoluteFilePathComponent>((nsTornadoEditor::TAbsoluteFilePathComponent*) p, str, err);
    };
    
    auto rtti__nsTornadoEditor_TAbsoluteFilePathComponentTypeFunc = globalTypeIdentifier->Type<nsTornadoEditor::TAbsoluteFilePathComponent>();
    
    m.insert({ rtti__nsTornadoEditor_TAbsoluteFilePathComponentTypeFunc, _nsTornadoEditor_TAbsoluteFilePathComponentTypeFunc });
    
    TypeFunc _nsTornadoEditor_TAssetAbsoluteFilePathComponentTypeFunc;
    _nsTornadoEditor_TAssetAbsoluteFilePathComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEditor::TAssetAbsoluteFilePathComponent>((nsTornadoEditor::TAssetAbsoluteFilePathComponent*) p, str);
    };
    _nsTornadoEditor_TAssetAbsoluteFilePathComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEditor::TAssetAbsoluteFilePathComponent>((nsTornadoEditor::TAssetAbsoluteFilePathComponent*) p, str, err);
    };
    
    auto rtti__nsTornadoEditor_TAssetAbsoluteFilePathComponentTypeFunc = globalTypeIdentifier->Type<nsTornadoEditor::TAssetAbsoluteFilePathComponent>();
    
    m.insert({ rtti__nsTornadoEditor_TAssetAbsoluteFilePathComponentTypeFunc, _nsTornadoEditor_TAssetAbsoluteFilePathComponentTypeFunc });
    
    TypeFunc _nsTornadoEditor_TEditorInfoTagComponentTypeFunc;
    _nsTornadoEditor_TEditorInfoTagComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEditor::TEditorInfoTagComponent>((nsTornadoEditor::TEditorInfoTagComponent*) p, str);
    };
    _nsTornadoEditor_TEditorInfoTagComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEditor::TEditorInfoTagComponent>((nsTornadoEditor::TEditorInfoTagComponent*) p, str, err);
    };
    
    auto rtti__nsTornadoEditor_TEditorInfoTagComponentTypeFunc = globalTypeIdentifier->Type<nsTornadoEditor::TEditorInfoTagComponent>();
    
    m.insert({ rtti__nsTornadoEditor_TEditorInfoTagComponentTypeFunc, _nsTornadoEditor_TEditorInfoTagComponentTypeFunc });
    
    TypeFunc _nsTornadoEditor_TFileHierarchyWindowRefreshTagComponentTypeFunc;
    _nsTornadoEditor_TFileHierarchyWindowRefreshTagComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEditor::TFileHierarchyWindowRefreshTagComponent>((nsTornadoEditor::TFileHierarchyWindowRefreshTagComponent*) p, str);
    };
    _nsTornadoEditor_TFileHierarchyWindowRefreshTagComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEditor::TFileHierarchyWindowRefreshTagComponent>((nsTornadoEditor::TFileHierarchyWindowRefreshTagComponent*) p, str, err);
    };
    
    auto rtti__nsTornadoEditor_TFileHierarchyWindowRefreshTagComponentTypeFunc = globalTypeIdentifier->Type<nsTornadoEditor::TFileHierarchyWindowRefreshTagComponent>();
    
    m.insert({ rtti__nsTornadoEditor_TFileHierarchyWindowRefreshTagComponentTypeFunc, _nsTornadoEditor_TFileHierarchyWindowRefreshTagComponentTypeFunc });
    
    TypeFunc _nsTornadoEditor_TFileHierarchyWindowTagComponentTypeFunc;
    _nsTornadoEditor_TFileHierarchyWindowTagComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEditor::TFileHierarchyWindowTagComponent>((nsTornadoEditor::TFileHierarchyWindowTagComponent*) p, str);
    };
    _nsTornadoEditor_TFileHierarchyWindowTagComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEditor::TFileHierarchyWindowTagComponent>((nsTornadoEditor::TFileHierarchyWindowTagComponent*) p, str, err);
    };
    
    auto rtti__nsTornadoEditor_TFileHierarchyWindowTagComponentTypeFunc = globalTypeIdentifier->Type<nsTornadoEditor::TFileHierarchyWindowTagComponent>();
    
    m.insert({ rtti__nsTornadoEditor_TFileHierarchyWindowTagComponentTypeFunc, _nsTornadoEditor_TFileHierarchyWindowTagComponentTypeFunc });
    
    TypeFunc _nsTornadoEditor_TFilePathNodeComponentTypeFunc;
    _nsTornadoEditor_TFilePathNodeComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEditor::TFilePathNodeComponent>((nsTornadoEditor::TFilePathNodeComponent*) p, str);
    };
    _nsTornadoEditor_TFilePathNodeComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEditor::TFilePathNodeComponent>((nsTornadoEditor::TFilePathNodeComponent*) p, str, err);
    };
    
    auto rtti__nsTornadoEditor_TFilePathNodeComponentTypeFunc = globalTypeIdentifier->Type<nsTornadoEditor::TFilePathNodeComponent>();
    
    m.insert({ rtti__nsTornadoEditor_TFilePathNodeComponentTypeFunc, _nsTornadoEditor_TFilePathNodeComponentTypeFunc });
    
    TypeFunc _nsTornadoEditor_TInspectorWindowTagComponentTypeFunc;
    _nsTornadoEditor_TInspectorWindowTagComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEditor::TInspectorWindowTagComponent>((nsTornadoEditor::TInspectorWindowTagComponent*) p, str);
    };
    _nsTornadoEditor_TInspectorWindowTagComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEditor::TInspectorWindowTagComponent>((nsTornadoEditor::TInspectorWindowTagComponent*) p, str, err);
    };
    
    auto rtti__nsTornadoEditor_TInspectorWindowTagComponentTypeFunc = globalTypeIdentifier->Type<nsTornadoEditor::TInspectorWindowTagComponent>();
    
    m.insert({ rtti__nsTornadoEditor_TInspectorWindowTagComponentTypeFunc, _nsTornadoEditor_TInspectorWindowTagComponentTypeFunc });
    
    TypeFunc _nsTornadoEditor_TObjectHierarchyWindowRefreshTagComponentTypeFunc;
    _nsTornadoEditor_TObjectHierarchyWindowRefreshTagComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEditor::TObjectHierarchyWindowRefreshTagComponent>((nsTornadoEditor::TObjectHierarchyWindowRefreshTagComponent*) p, str);
    };
    _nsTornadoEditor_TObjectHierarchyWindowRefreshTagComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEditor::TObjectHierarchyWindowRefreshTagComponent>((nsTornadoEditor::TObjectHierarchyWindowRefreshTagComponent*) p, str, err);
    };
    
    auto rtti__nsTornadoEditor_TObjectHierarchyWindowRefreshTagComponentTypeFunc = globalTypeIdentifier->Type<nsTornadoEditor::TObjectHierarchyWindowRefreshTagComponent>();
    
    m.insert({ rtti__nsTornadoEditor_TObjectHierarchyWindowRefreshTagComponentTypeFunc, _nsTornadoEditor_TObjectHierarchyWindowRefreshTagComponentTypeFunc });
    
    TypeFunc _nsTornadoEditor_TObjectHierarchyWindowTagComponentTypeFunc;
    _nsTornadoEditor_TObjectHierarchyWindowTagComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEditor::TObjectHierarchyWindowTagComponent>((nsTornadoEditor::TObjectHierarchyWindowTagComponent*) p, str);
    };
    _nsTornadoEditor_TObjectHierarchyWindowTagComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEditor::TObjectHierarchyWindowTagComponent>((nsTornadoEditor::TObjectHierarchyWindowTagComponent*) p, str, err);
    };
    
    auto rtti__nsTornadoEditor_TObjectHierarchyWindowTagComponentTypeFunc = globalTypeIdentifier->Type<nsTornadoEditor::TObjectHierarchyWindowTagComponent>();
    
    m.insert({ rtti__nsTornadoEditor_TObjectHierarchyWindowTagComponentTypeFunc, _nsTornadoEditor_TObjectHierarchyWindowTagComponentTypeFunc });
    
    TypeFunc _nsTornadoEditor_TProjectConfigComponentTypeFunc;
    _nsTornadoEditor_TProjectConfigComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEditor::TProjectConfigComponent>((nsTornadoEditor::TProjectConfigComponent*) p, str);
    };
    _nsTornadoEditor_TProjectConfigComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEditor::TProjectConfigComponent>((nsTornadoEditor::TProjectConfigComponent*) p, str, err);
    };
    
    auto rtti__nsTornadoEditor_TProjectConfigComponentTypeFunc = globalTypeIdentifier->Type<nsTornadoEditor::TProjectConfigComponent>();
    
    m.insert({ rtti__nsTornadoEditor_TProjectConfigComponentTypeFunc, _nsTornadoEditor_TProjectConfigComponentTypeFunc });
    
    int max = 0;
    for (auto& vt : m) {
        max = std::max(vt.first, max);
    }
    
    mTypeFuncVector.resize(max + 1);
    for (auto& vt : m) {
        mTypeFuncVector[vt.first] = vt.second;
    }
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::Serialize(void* p, std::string& str, int rtti)
{
    Init();
    mTypeFuncVector[rtti].serializeFunc(p, str);
}
//---------------------------------------------------------------------------------------
bool TComponentJsonSerializer::Deserialize(void* p, const std::string& str, int rtti, std::string& err)
{
    Init();
    return mTypeFuncVector[rtti].deserializeFunc(p, str, err);
}
//---------------------------------------------------------------------------------------
bool TComponentJsonSerializer::Has(int rtti)
{
    Init();
    if (rtti < 0 || rtti >= mTypeFuncVector.size()) {
        return false;
    }
    return mTypeFuncVector[rtti].serializeFunc != nullptr;
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsTornadoEditor::TAbsoluteFilePathComponent* p, Jobj& obj)
{
    PUM::Push(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsTornadoEditor::TAbsoluteFilePathComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsTornadoEditor::TAssetAbsoluteFilePathComponent* p, Jobj& obj)
{
    PUM::Push(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsTornadoEditor::TAssetAbsoluteFilePathComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsTornadoEditor::TEditorInfoTagComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsTornadoEditor::TEditorInfoTagComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsTornadoEditor::TFileHierarchyWindowRefreshTagComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsTornadoEditor::TFileHierarchyWindowRefreshTagComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsTornadoEditor::TFileHierarchyWindowTagComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsTornadoEditor::TFileHierarchyWindowTagComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsTornadoEditor::TFilePathNodeComponent* p, Jobj& obj)
{
    PUM::Push(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsTornadoEditor::TFilePathNodeComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsTornadoEditor::TInspectorWindowTagComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsTornadoEditor::TInspectorWindowTagComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsTornadoEditor::TObjectHierarchyWindowRefreshTagComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsTornadoEditor::TObjectHierarchyWindowRefreshTagComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsTornadoEditor::TObjectHierarchyWindowTagComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsTornadoEditor::TObjectHierarchyWindowTagComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsTornadoEditor::TProjectConfigComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsTornadoEditor::TProjectConfigComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
