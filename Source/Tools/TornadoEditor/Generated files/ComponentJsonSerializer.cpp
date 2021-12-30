/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.2.5, build 56 [Json, Binary, ImGui, EntityManager, Reflection, TypeInformation]
// File has been generated at 2021_12_30 17:13:40.614
	
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
    
    TypeFunc _nsTornadoEditor_TEditorInfoTagComponentTypeFunc;
    _nsTornadoEditor_TEditorInfoTagComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEditor::TEditorInfoTagComponent>((nsTornadoEditor::TEditorInfoTagComponent*) p, str);
    };
    _nsTornadoEditor_TEditorInfoTagComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEditor::TEditorInfoTagComponent>((nsTornadoEditor::TEditorInfoTagComponent*) p, str, err);
    };
    
    auto rtti__nsTornadoEditor_TEditorInfoTagComponentTypeFunc = globalTypeIdentifier->Type<nsTornadoEditor::TEditorInfoTagComponent>();
    
    m.insert({ rtti__nsTornadoEditor_TEditorInfoTagComponentTypeFunc, _nsTornadoEditor_TEditorInfoTagComponentTypeFunc });
    
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
void TComponentJsonSerializer::_Serialize(nsTornadoEditor::TEditorInfoTagComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsTornadoEditor::TEditorInfoTagComponent* p, const Jobj& obj)
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
