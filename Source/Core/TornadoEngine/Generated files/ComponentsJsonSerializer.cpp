/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.2.1, build 52, info Json, Binary, ImGui, EntityManager, Reflection, TypeInformation
// File has been generated at 2021_09_26 19:42:05.846
	
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
    
    TypeFunc _nsMathTools_TMatrix16TypeFunc;
    _nsMathTools_TMatrix16TypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsMathTools::TMatrix16>((nsMathTools::TMatrix16*) p, str);
    };
    _nsMathTools_TMatrix16TypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsMathTools::TMatrix16>((nsMathTools::TMatrix16*) p, str, err);
    };
    
    auto rtti__nsMathTools_TMatrix16TypeFunc = globalTypeIdentifier->type<nsMathTools::TMatrix16>();
    
    m.insert({ rtti__nsMathTools_TMatrix16TypeFunc, _nsMathTools_TMatrix16TypeFunc });
    
    TypeFunc _nsTornadoEngine_TCameraComponentTypeFunc;
    _nsTornadoEngine_TCameraComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEngine::TCameraComponent>((nsTornadoEngine::TCameraComponent*) p, str);
    };
    _nsTornadoEngine_TCameraComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEngine::TCameraComponent>((nsTornadoEngine::TCameraComponent*) p, str, err);
    };
    
    auto rtti__nsTornadoEngine_TCameraComponentTypeFunc = globalTypeIdentifier->type<nsTornadoEngine::TCameraComponent>();
    
    m.insert({ rtti__nsTornadoEngine_TCameraComponentTypeFunc, _nsTornadoEngine_TCameraComponentTypeFunc });
    
    TypeFunc _nsTornadoEngine_TFocusComponentTypeFunc;
    _nsTornadoEngine_TFocusComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEngine::TFocusComponent>((nsTornadoEngine::TFocusComponent*) p, str);
    };
    _nsTornadoEngine_TFocusComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEngine::TFocusComponent>((nsTornadoEngine::TFocusComponent*) p, str, err);
    };
    
    auto rtti__nsTornadoEngine_TFocusComponentTypeFunc = globalTypeIdentifier->type<nsTornadoEngine::TFocusComponent>();
    
    m.insert({ rtti__nsTornadoEngine_TFocusComponentTypeFunc, _nsTornadoEngine_TFocusComponentTypeFunc });
    
    TypeFunc _nsTornadoEngine_TGuidComponentTypeFunc;
    _nsTornadoEngine_TGuidComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEngine::TGuidComponent>((nsTornadoEngine::TGuidComponent*) p, str);
    };
    _nsTornadoEngine_TGuidComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEngine::TGuidComponent>((nsTornadoEngine::TGuidComponent*) p, str, err);
    };
    
    auto rtti__nsTornadoEngine_TGuidComponentTypeFunc = globalTypeIdentifier->type<nsTornadoEngine::TGuidComponent>();
    
    m.insert({ rtti__nsTornadoEngine_TGuidComponentTypeFunc, _nsTornadoEngine_TGuidComponentTypeFunc });
    
    TypeFunc _nsTornadoEngine_TLightComponentTypeFunc;
    _nsTornadoEngine_TLightComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEngine::TLightComponent>((nsTornadoEngine::TLightComponent*) p, str);
    };
    _nsTornadoEngine_TLightComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEngine::TLightComponent>((nsTornadoEngine::TLightComponent*) p, str, err);
    };
    
    auto rtti__nsTornadoEngine_TLightComponentTypeFunc = globalTypeIdentifier->type<nsTornadoEngine::TLightComponent>();
    
    m.insert({ rtti__nsTornadoEngine_TLightComponentTypeFunc, _nsTornadoEngine_TLightComponentTypeFunc });
    
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
    
    TypeFunc _nsTornadoEngine_TPositionComponentTypeFunc;
    _nsTornadoEngine_TPositionComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEngine::TPositionComponent>((nsTornadoEngine::TPositionComponent*) p, str);
    };
    _nsTornadoEngine_TPositionComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEngine::TPositionComponent>((nsTornadoEngine::TPositionComponent*) p, str, err);
    };
    
    auto rtti__nsTornadoEngine_TPositionComponentTypeFunc = globalTypeIdentifier->type<nsTornadoEngine::TPositionComponent>();
    
    m.insert({ rtti__nsTornadoEngine_TPositionComponentTypeFunc, _nsTornadoEngine_TPositionComponentTypeFunc });
    
    TypeFunc _nsTornadoEngine_TSceneGuidComponentTypeFunc;
    _nsTornadoEngine_TSceneGuidComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEngine::TSceneGuidComponent>((nsTornadoEngine::TSceneGuidComponent*) p, str);
    };
    _nsTornadoEngine_TSceneGuidComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEngine::TSceneGuidComponent>((nsTornadoEngine::TSceneGuidComponent*) p, str, err);
    };
    
    auto rtti__nsTornadoEngine_TSceneGuidComponentTypeFunc = globalTypeIdentifier->type<nsTornadoEngine::TSceneGuidComponent>();
    
    m.insert({ rtti__nsTornadoEngine_TSceneGuidComponentTypeFunc, _nsTornadoEngine_TSceneGuidComponentTypeFunc });
    
    TypeFunc _nsTornadoEngine_TSizeComponentTypeFunc;
    _nsTornadoEngine_TSizeComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEngine::TSizeComponent>((nsTornadoEngine::TSizeComponent*) p, str);
    };
    _nsTornadoEngine_TSizeComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEngine::TSizeComponent>((nsTornadoEngine::TSizeComponent*) p, str, err);
    };
    
    auto rtti__nsTornadoEngine_TSizeComponentTypeFunc = globalTypeIdentifier->type<nsTornadoEngine::TSizeComponent>();
    
    m.insert({ rtti__nsTornadoEngine_TSizeComponentTypeFunc, _nsTornadoEngine_TSizeComponentTypeFunc });
    
    TypeFunc _nsTornadoEngine_TTransformComponentTypeFunc;
    _nsTornadoEngine_TTransformComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEngine::TTransformComponent>((nsTornadoEngine::TTransformComponent*) p, str);
    };
    _nsTornadoEngine_TTransformComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEngine::TTransformComponent>((nsTornadoEngine::TTransformComponent*) p, str, err);
    };
    
    auto rtti__nsTornadoEngine_TTransformComponentTypeFunc = globalTypeIdentifier->type<nsTornadoEngine::TTransformComponent>();
    
    m.insert({ rtti__nsTornadoEngine_TTransformComponentTypeFunc, _nsTornadoEngine_TTransformComponentTypeFunc });
    
    TypeFunc _nsTornadoEngine_TVisibilityComponentTypeFunc;
    _nsTornadoEngine_TVisibilityComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEngine::TVisibilityComponent>((nsTornadoEngine::TVisibilityComponent*) p, str);
    };
    _nsTornadoEngine_TVisibilityComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEngine::TVisibilityComponent>((nsTornadoEngine::TVisibilityComponent*) p, str, err);
    };
    
    auto rtti__nsTornadoEngine_TVisibilityComponentTypeFunc = globalTypeIdentifier->type<nsTornadoEngine::TVisibilityComponent>();
    
    m.insert({ rtti__nsTornadoEngine_TVisibilityComponentTypeFunc, _nsTornadoEngine_TVisibilityComponentTypeFunc });
    
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
void TComponentsJsonSerializer::_Serialize(nsMathTools::TMatrix16* p, Jobj& obj)
{
    PUM::Push(obj, "_11", p->_11);
    PUM::Push(obj, "_12", p->_12);
    PUM::Push(obj, "_13", p->_13);
    PUM::Push(obj, "_14", p->_14);
    PUM::Push(obj, "_21", p->_21);
    PUM::Push(obj, "_22", p->_22);
    PUM::Push(obj, "_23", p->_23);
    PUM::Push(obj, "_24", p->_24);
    PUM::Push(obj, "_31", p->_31);
    PUM::Push(obj, "_32", p->_32);
    PUM::Push(obj, "_33", p->_33);
    PUM::Push(obj, "_34", p->_34);
    PUM::Push(obj, "_41", p->_41);
    PUM::Push(obj, "_42", p->_42);
    PUM::Push(obj, "_43", p->_43);
    PUM::Push(obj, "_44", p->_44);
}
//---------------------------------------------------------------------------------------
void TComponentsJsonSerializer::_Deserialize(nsMathTools::TMatrix16* p, const Jobj& obj)
{
    POM::PopNum(obj, "_11", p->_11);
    POM::PopNum(obj, "_12", p->_12);
    POM::PopNum(obj, "_13", p->_13);
    POM::PopNum(obj, "_14", p->_14);
    POM::PopNum(obj, "_21", p->_21);
    POM::PopNum(obj, "_22", p->_22);
    POM::PopNum(obj, "_23", p->_23);
    POM::PopNum(obj, "_24", p->_24);
    POM::PopNum(obj, "_31", p->_31);
    POM::PopNum(obj, "_32", p->_32);
    POM::PopNum(obj, "_33", p->_33);
    POM::PopNum(obj, "_34", p->_34);
    POM::PopNum(obj, "_41", p->_41);
    POM::PopNum(obj, "_42", p->_42);
    POM::PopNum(obj, "_43", p->_43);
    POM::PopNum(obj, "_44", p->_44);
}
//---------------------------------------------------------------------------------------
void TComponentsJsonSerializer::_Serialize(nsTornadoEngine::TCameraComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentsJsonSerializer::_Deserialize(nsTornadoEngine::TCameraComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentsJsonSerializer::_Serialize(nsTornadoEngine::TFocusComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentsJsonSerializer::_Deserialize(nsTornadoEngine::TFocusComponent* p, const Jobj& obj)
{
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
void TComponentsJsonSerializer::_Serialize(nsTornadoEngine::TLightComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentsJsonSerializer::_Deserialize(nsTornadoEngine::TLightComponent* p, const Jobj& obj)
{
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
void TComponentsJsonSerializer::_Serialize(nsTornadoEngine::TPositionComponent* p, Jobj& obj)
{
    PUM::Push(obj, "x", p->x);
    PUM::Push(obj, "y", p->y);
}
//---------------------------------------------------------------------------------------
void TComponentsJsonSerializer::_Deserialize(nsTornadoEngine::TPositionComponent* p, const Jobj& obj)
{
    POM::PopNum(obj, "x", p->x);
    POM::PopNum(obj, "y", p->y);
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
void TComponentsJsonSerializer::_Serialize(nsTornadoEngine::TSizeComponent* p, Jobj& obj)
{
    PUM::Push(obj, "x", p->x);
    PUM::Push(obj, "y", p->y);
}
//---------------------------------------------------------------------------------------
void TComponentsJsonSerializer::_Deserialize(nsTornadoEngine::TSizeComponent* p, const Jobj& obj)
{
    POM::PopNum(obj, "x", p->x);
    POM::PopNum(obj, "y", p->y);
}
//---------------------------------------------------------------------------------------
void TComponentsJsonSerializer::_Serialize(nsTornadoEngine::TTransformComponent* p, Jobj& obj)
{
    auto value_o = PUM::AddObject(obj, "value");
    _Serialize(&(p->value), value_o);
}
//---------------------------------------------------------------------------------------
void TComponentsJsonSerializer::_Deserialize(nsTornadoEngine::TTransformComponent* p, const Jobj& obj)
{
    auto value_o0 = POM::FindObject(obj, "value");
    _Deserialize(&(p->value), value_o0);
}
//---------------------------------------------------------------------------------------
void TComponentsJsonSerializer::_Serialize(nsTornadoEngine::TVisibilityComponent* p, Jobj& obj)
{
    PUM::Push(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentsJsonSerializer::_Deserialize(nsTornadoEngine::TVisibilityComponent* p, const Jobj& obj)
{
    POM::PopBool(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
