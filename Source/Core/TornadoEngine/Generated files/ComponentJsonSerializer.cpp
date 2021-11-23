/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.2.2, build 53 [Json, Binary, ImGui, EntityManager, Reflection, TypeInformation]
// File has been generated at 2021_11_23 08:21:30.645
	
#include "ComponentJsonSerializer.h"
#include "JsonPopMaster.h"
#include "JsonPushMaster.h"
#include "SingletonManager.h"
#include "RunTimeTypeIndex.h"

using namespace nsTornadoEngine;

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
    
    TypeFunc _nsCommonWrapper_TGuidComponentTypeFunc;
    _nsCommonWrapper_TGuidComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsCommonWrapper::TGuidComponent>((nsCommonWrapper::TGuidComponent*) p, str);
    };
    _nsCommonWrapper_TGuidComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsCommonWrapper::TGuidComponent>((nsCommonWrapper::TGuidComponent*) p, str, err);
    };
    
    auto rtti__nsCommonWrapper_TGuidComponentTypeFunc = globalTypeIdentifier->type<nsCommonWrapper::TGuidComponent>();
    
    m.insert({ rtti__nsCommonWrapper_TGuidComponentTypeFunc, _nsCommonWrapper_TGuidComponentTypeFunc });
    
    TypeFunc _nsCommonWrapper_TNameComponentTypeFunc;
    _nsCommonWrapper_TNameComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsCommonWrapper::TNameComponent>((nsCommonWrapper::TNameComponent*) p, str);
    };
    _nsCommonWrapper_TNameComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsCommonWrapper::TNameComponent>((nsCommonWrapper::TNameComponent*) p, str, err);
    };
    
    auto rtti__nsCommonWrapper_TNameComponentTypeFunc = globalTypeIdentifier->type<nsCommonWrapper::TNameComponent>();
    
    m.insert({ rtti__nsCommonWrapper_TNameComponentTypeFunc, _nsCommonWrapper_TNameComponentTypeFunc });
    
    TypeFunc _nsCommonWrapper_TParentGuidComponentTypeFunc;
    _nsCommonWrapper_TParentGuidComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsCommonWrapper::TParentGuidComponent>((nsCommonWrapper::TParentGuidComponent*) p, str);
    };
    _nsCommonWrapper_TParentGuidComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsCommonWrapper::TParentGuidComponent>((nsCommonWrapper::TParentGuidComponent*) p, str, err);
    };
    
    auto rtti__nsCommonWrapper_TParentGuidComponentTypeFunc = globalTypeIdentifier->type<nsCommonWrapper::TParentGuidComponent>();
    
    m.insert({ rtti__nsCommonWrapper_TParentGuidComponentTypeFunc, _nsCommonWrapper_TParentGuidComponentTypeFunc });
    
    TypeFunc _nsCommonWrapper_TSceneEditingComponentTypeFunc;
    _nsCommonWrapper_TSceneEditingComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsCommonWrapper::TSceneEditingComponent>((nsCommonWrapper::TSceneEditingComponent*) p, str);
    };
    _nsCommonWrapper_TSceneEditingComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsCommonWrapper::TSceneEditingComponent>((nsCommonWrapper::TSceneEditingComponent*) p, str, err);
    };
    
    auto rtti__nsCommonWrapper_TSceneEditingComponentTypeFunc = globalTypeIdentifier->type<nsCommonWrapper::TSceneEditingComponent>();
    
    m.insert({ rtti__nsCommonWrapper_TSceneEditingComponentTypeFunc, _nsCommonWrapper_TSceneEditingComponentTypeFunc });
    
    TypeFunc _nsCommonWrapper_TSceneGuidComponentTypeFunc;
    _nsCommonWrapper_TSceneGuidComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsCommonWrapper::TSceneGuidComponent>((nsCommonWrapper::TSceneGuidComponent*) p, str);
    };
    _nsCommonWrapper_TSceneGuidComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsCommonWrapper::TSceneGuidComponent>((nsCommonWrapper::TSceneGuidComponent*) p, str, err);
    };
    
    auto rtti__nsCommonWrapper_TSceneGuidComponentTypeFunc = globalTypeIdentifier->type<nsCommonWrapper::TSceneGuidComponent>();
    
    m.insert({ rtti__nsCommonWrapper_TSceneGuidComponentTypeFunc, _nsCommonWrapper_TSceneGuidComponentTypeFunc });
    
    TypeFunc _nsCommonWrapper_TSceneRootComponentTypeFunc;
    _nsCommonWrapper_TSceneRootComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsCommonWrapper::TSceneRootComponent>((nsCommonWrapper::TSceneRootComponent*) p, str);
    };
    _nsCommonWrapper_TSceneRootComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsCommonWrapper::TSceneRootComponent>((nsCommonWrapper::TSceneRootComponent*) p, str, err);
    };
    
    auto rtti__nsCommonWrapper_TSceneRootComponentTypeFunc = globalTypeIdentifier->type<nsCommonWrapper::TSceneRootComponent>();
    
    m.insert({ rtti__nsCommonWrapper_TSceneRootComponentTypeFunc, _nsCommonWrapper_TSceneRootComponentTypeFunc });
    
    TypeFunc _nsCommonWrapper_TTransformComponentTypeFunc;
    _nsCommonWrapper_TTransformComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsCommonWrapper::TTransformComponent>((nsCommonWrapper::TTransformComponent*) p, str);
    };
    _nsCommonWrapper_TTransformComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsCommonWrapper::TTransformComponent>((nsCommonWrapper::TTransformComponent*) p, str, err);
    };
    
    auto rtti__nsCommonWrapper_TTransformComponentTypeFunc = globalTypeIdentifier->type<nsCommonWrapper::TTransformComponent>();
    
    m.insert({ rtti__nsCommonWrapper_TTransformComponentTypeFunc, _nsCommonWrapper_TTransformComponentTypeFunc });
    
    TypeFunc _nsGraphicWrapper_TCameraComponentTypeFunc;
    _nsGraphicWrapper_TCameraComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGraphicWrapper::TCameraComponent>((nsGraphicWrapper::TCameraComponent*) p, str);
    };
    _nsGraphicWrapper_TCameraComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGraphicWrapper::TCameraComponent>((nsGraphicWrapper::TCameraComponent*) p, str, err);
    };
    
    auto rtti__nsGraphicWrapper_TCameraComponentTypeFunc = globalTypeIdentifier->type<nsGraphicWrapper::TCameraComponent>();
    
    m.insert({ rtti__nsGraphicWrapper_TCameraComponentTypeFunc, _nsGraphicWrapper_TCameraComponentTypeFunc });
    
    TypeFunc _nsGraphicWrapper_TLightComponentTypeFunc;
    _nsGraphicWrapper_TLightComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGraphicWrapper::TLightComponent>((nsGraphicWrapper::TLightComponent*) p, str);
    };
    _nsGraphicWrapper_TLightComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGraphicWrapper::TLightComponent>((nsGraphicWrapper::TLightComponent*) p, str, err);
    };
    
    auto rtti__nsGraphicWrapper_TLightComponentTypeFunc = globalTypeIdentifier->type<nsGraphicWrapper::TLightComponent>();
    
    m.insert({ rtti__nsGraphicWrapper_TLightComponentTypeFunc, _nsGraphicWrapper_TLightComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TButtonClickHandlerComponentTypeFunc;
    _nsGuiWrapper_TButtonClickHandlerComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TButtonClickHandlerComponent>((nsGuiWrapper::TButtonClickHandlerComponent*) p, str);
    };
    _nsGuiWrapper_TButtonClickHandlerComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TButtonClickHandlerComponent>((nsGuiWrapper::TButtonClickHandlerComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TButtonClickHandlerComponentTypeFunc = globalTypeIdentifier->type<nsGuiWrapper::TButtonClickHandlerComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TButtonClickHandlerComponentTypeFunc, _nsGuiWrapper_TButtonClickHandlerComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TButtonComponentTypeFunc;
    _nsGuiWrapper_TButtonComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TButtonComponent>((nsGuiWrapper::TButtonComponent*) p, str);
    };
    _nsGuiWrapper_TButtonComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TButtonComponent>((nsGuiWrapper::TButtonComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TButtonComponentTypeFunc = globalTypeIdentifier->type<nsGuiWrapper::TButtonComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TButtonComponentTypeFunc, _nsGuiWrapper_TButtonComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TFocusComponentTypeFunc;
    _nsGuiWrapper_TFocusComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TFocusComponent>((nsGuiWrapper::TFocusComponent*) p, str);
    };
    _nsGuiWrapper_TFocusComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TFocusComponent>((nsGuiWrapper::TFocusComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TFocusComponentTypeFunc = globalTypeIdentifier->type<nsGuiWrapper::TFocusComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TFocusComponentTypeFunc, _nsGuiWrapper_TFocusComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TPositionComponentTypeFunc;
    _nsGuiWrapper_TPositionComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TPositionComponent>((nsGuiWrapper::TPositionComponent*) p, str);
    };
    _nsGuiWrapper_TPositionComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TPositionComponent>((nsGuiWrapper::TPositionComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TPositionComponentTypeFunc = globalTypeIdentifier->type<nsGuiWrapper::TPositionComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TPositionComponentTypeFunc, _nsGuiWrapper_TPositionComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TSizeComponentTypeFunc;
    _nsGuiWrapper_TSizeComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TSizeComponent>((nsGuiWrapper::TSizeComponent*) p, str);
    };
    _nsGuiWrapper_TSizeComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TSizeComponent>((nsGuiWrapper::TSizeComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TSizeComponentTypeFunc = globalTypeIdentifier->type<nsGuiWrapper::TSizeComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TSizeComponentTypeFunc, _nsGuiWrapper_TSizeComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TTitleComponentTypeFunc;
    _nsGuiWrapper_TTitleComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TTitleComponent>((nsGuiWrapper::TTitleComponent*) p, str);
    };
    _nsGuiWrapper_TTitleComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TTitleComponent>((nsGuiWrapper::TTitleComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TTitleComponentTypeFunc = globalTypeIdentifier->type<nsGuiWrapper::TTitleComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TTitleComponentTypeFunc, _nsGuiWrapper_TTitleComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TVisibilityComponentTypeFunc;
    _nsGuiWrapper_TVisibilityComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TVisibilityComponent>((nsGuiWrapper::TVisibilityComponent*) p, str);
    };
    _nsGuiWrapper_TVisibilityComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TVisibilityComponent>((nsGuiWrapper::TVisibilityComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TVisibilityComponentTypeFunc = globalTypeIdentifier->type<nsGuiWrapper::TVisibilityComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TVisibilityComponentTypeFunc, _nsGuiWrapper_TVisibilityComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TWindowComponentTypeFunc;
    _nsGuiWrapper_TWindowComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TWindowComponent>((nsGuiWrapper::TWindowComponent*) p, str);
    };
    _nsGuiWrapper_TWindowComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TWindowComponent>((nsGuiWrapper::TWindowComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TWindowComponentTypeFunc = globalTypeIdentifier->type<nsGuiWrapper::TWindowComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TWindowComponentTypeFunc, _nsGuiWrapper_TWindowComponentTypeFunc });
    
    TypeFunc _nsMathTools_TMatrix16TypeFunc;
    _nsMathTools_TMatrix16TypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsMathTools::TMatrix16>((nsMathTools::TMatrix16*) p, str);
    };
    _nsMathTools_TMatrix16TypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsMathTools::TMatrix16>((nsMathTools::TMatrix16*) p, str, err);
    };
    
    auto rtti__nsMathTools_TMatrix16TypeFunc = globalTypeIdentifier->type<nsMathTools::TMatrix16>();
    
    m.insert({ rtti__nsMathTools_TMatrix16TypeFunc, _nsMathTools_TMatrix16TypeFunc });
    
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
void TComponentJsonSerializer::_Serialize(nsCommonWrapper::TGuidComponent* p, Jobj& obj)
{
    PUM::Push(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsCommonWrapper::TGuidComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsCommonWrapper::TNameComponent* p, Jobj& obj)
{
    PUM::Push(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsCommonWrapper::TNameComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsCommonWrapper::TParentGuidComponent* p, Jobj& obj)
{
    PUM::Push(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsCommonWrapper::TParentGuidComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsCommonWrapper::TSceneEditingComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsCommonWrapper::TSceneEditingComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsCommonWrapper::TSceneGuidComponent* p, Jobj& obj)
{
    PUM::Push(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsCommonWrapper::TSceneGuidComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsCommonWrapper::TSceneRootComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsCommonWrapper::TSceneRootComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsCommonWrapper::TTransformComponent* p, Jobj& obj)
{
    auto value_o = PUM::AddObject(obj, "value");
    _Serialize(&(p->value), value_o);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsCommonWrapper::TTransformComponent* p, const Jobj& obj)
{
    auto value_o0 = POM::FindObject(obj, "value");
    _Deserialize(&(p->value), value_o0);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsGraphicWrapper::TCameraComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsGraphicWrapper::TCameraComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsGraphicWrapper::TLightComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsGraphicWrapper::TLightComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsGuiWrapper::TButtonClickHandlerComponent* p, Jobj& obj)
{
    PUM::Push(obj, "handlerTypeName", p->handlerTypeName);
    PUM::Push(obj, "partOfGuid", p->partOfGuid);
    PUM::Push(obj, "entityGuid", p->entityGuid);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsGuiWrapper::TButtonClickHandlerComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "handlerTypeName", p->handlerTypeName);
    POM::PopStr(obj, "partOfGuid", p->partOfGuid);
    POM::PopStr(obj, "entityGuid", p->entityGuid);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsGuiWrapper::TButtonComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsGuiWrapper::TButtonComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsGuiWrapper::TFocusComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsGuiWrapper::TFocusComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsGuiWrapper::TPositionComponent* p, Jobj& obj)
{
    PUM::Push(obj, "x", p->x);
    PUM::Push(obj, "y", p->y);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsGuiWrapper::TPositionComponent* p, const Jobj& obj)
{
    POM::PopNum(obj, "x", p->x);
    POM::PopNum(obj, "y", p->y);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsGuiWrapper::TSizeComponent* p, Jobj& obj)
{
    PUM::Push(obj, "x", p->x);
    PUM::Push(obj, "y", p->y);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsGuiWrapper::TSizeComponent* p, const Jobj& obj)
{
    POM::PopNum(obj, "x", p->x);
    POM::PopNum(obj, "y", p->y);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsGuiWrapper::TTitleComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsGuiWrapper::TTitleComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsGuiWrapper::TVisibilityComponent* p, Jobj& obj)
{
    PUM::Push(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsGuiWrapper::TVisibilityComponent* p, const Jobj& obj)
{
    POM::PopBool(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsGuiWrapper::TWindowComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsGuiWrapper::TWindowComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsMathTools::TMatrix16* p, Jobj& obj)
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
void TComponentJsonSerializer::_Deserialize(nsMathTools::TMatrix16* p, const Jobj& obj)
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
