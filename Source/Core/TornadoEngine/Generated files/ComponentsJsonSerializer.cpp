/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.2.1, build 52, info Json, Binary, ImGui, EntityManager, Reflection, TypeInformation
// File has been generated at 2021_07_30 08:28:34.205
	
#include "ComponentsJsonSerializer.h"
#include "JsonPopMaster.h"
#include "JsonPushMaster.h"
#include "SingletonManager.h"
#include "RunTimeTypeIndex.h"

using namespace nsTornadoEngine;

using POM = TJsonPopMaster;
using PUM = TJsonPushMaster;

std::vector<TComponentsJsonSerializer::TypeFunc> TComponentsJsonSerializer::mTypeFuncVector;

void TComponentsJsonSerializer::Init()
{
    static bool isNeedInit = true;
    if ( !isNeedInit ) {
        return;
    }
    isNeedInit = false;
    
    auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();
    
    std::map<int, TypeFunc> m;
    
    TypeFunc _nsTornadoEngine_TGuidComponentTypeFunc;
    _nsTornadoEngine_TGuidComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEngine::TGuidComponent>((nsTornadoEngine::TGuidComponent*) p, str);
    };
    _nsTornadoEngine_TGuidComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEngine::TGuidComponent>((nsTornadoEngine::TGuidComponent*) p, str, err);
    };
    
    auto rtti__nsTornadoEngine_TGuidComponentTypeFunc = globalTypeIdentifier->type<nsTornadoEngine::TGuidComponent>();
    
    m.insert({ rtti__nsTornadoEngine_TGuidComponentTypeFunc, _nsTornadoEngine_TGuidComponentTypeFunc });
    
    TypeFunc _nsTornadoEngine_TNameComponentTypeFunc;
    _nsTornadoEngine_TNameComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEngine::TNameComponent>((nsTornadoEngine::TNameComponent*) p, str);
    };
    _nsTornadoEngine_TNameComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEngine::TNameComponent>((nsTornadoEngine::TNameComponent*) p, str, err);
    };
    
    auto rtti__nsTornadoEngine_TNameComponentTypeFunc = globalTypeIdentifier->type<nsTornadoEngine::TNameComponent>();
    
    m.insert({ rtti__nsTornadoEngine_TNameComponentTypeFunc, _nsTornadoEngine_TNameComponentTypeFunc });
    
    TypeFunc _nsTornadoEngine_TParentGuidComponentTypeFunc;
    _nsTornadoEngine_TParentGuidComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEngine::TParentGuidComponent>((nsTornadoEngine::TParentGuidComponent*) p, str);
    };
    _nsTornadoEngine_TParentGuidComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEngine::TParentGuidComponent>((nsTornadoEngine::TParentGuidComponent*) p, str, err);
    };
    
    auto rtti__nsTornadoEngine_TParentGuidComponentTypeFunc = globalTypeIdentifier->type<nsTornadoEngine::TParentGuidComponent>();
    
    m.insert({ rtti__nsTornadoEngine_TParentGuidComponentTypeFunc, _nsTornadoEngine_TParentGuidComponentTypeFunc });
    
    TypeFunc _nsTornadoEngine_TSceneGuidComponentTypeFunc;
    _nsTornadoEngine_TSceneGuidComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEngine::TSceneGuidComponent>((nsTornadoEngine::TSceneGuidComponent*) p, str);
    };
    _nsTornadoEngine_TSceneGuidComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEngine::TSceneGuidComponent>((nsTornadoEngine::TSceneGuidComponent*) p, str, err);
    };
    
    auto rtti__nsTornadoEngine_TSceneGuidComponentTypeFunc = globalTypeIdentifier->type<nsTornadoEngine::TSceneGuidComponent>();
    
    m.insert({ rtti__nsTornadoEngine_TSceneGuidComponentTypeFunc, _nsTornadoEngine_TSceneGuidComponentTypeFunc });
    
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
void TComponentsJsonSerializer::Serialize(void* p, std::string& str, int rtti)
{
    Init();
    mTypeFuncVector[rtti].serializeFunc(p, str);
}
//---------------------------------------------------------------------------------------
bool TComponentsJsonSerializer::Deserialize(void* p, const std::string& str, int rtti, std::string& err)
{
    Init();
    return mTypeFuncVector[rtti].deserializeFunc(p, str, err);
}
//---------------------------------------------------------------------------------------
void TComponentsJsonSerializer::_Serialize(nsTornadoEngine::TGuidComponent* p, Jobj& obj)
{
    PUM::Push(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentsJsonSerializer::_Deserialize(nsTornadoEngine::TGuidComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentsJsonSerializer::_Serialize(nsTornadoEngine::TNameComponent* p, Jobj& obj)
{
    PUM::Push(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentsJsonSerializer::_Deserialize(nsTornadoEngine::TNameComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentsJsonSerializer::_Serialize(nsTornadoEngine::TParentGuidComponent* p, Jobj& obj)
{
    PUM::Push(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentsJsonSerializer::_Deserialize(nsTornadoEngine::TParentGuidComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentsJsonSerializer::_Serialize(nsTornadoEngine::TSceneGuidComponent* p, Jobj& obj)
{
    PUM::Push(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentsJsonSerializer::_Deserialize(nsTornadoEngine::TSceneGuidComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
