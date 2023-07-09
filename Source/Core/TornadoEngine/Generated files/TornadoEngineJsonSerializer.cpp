/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.4.0, build 58 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, TypeInformation]
// File has been generated at 2023_07_09 18:13:58.588
	
#include "TornadoEngineJsonSerializer.h"
#include "JsonPopMaster.h"
#include "JsonPushMaster.h"
#include "SingletonManager.h"
#include "RunTimeTypeIndex.h"

using namespace nsTornadoEngine;

using POM = TJsonPopMaster;
using PUM = TJsonPushMaster;

std::vector<TTornadoEngineJsonSerializer::TypeFunc> TTornadoEngineJsonSerializer::mTypeFuncVector;

void TTornadoEngineJsonSerializer::Init()
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
    
    auto rtti__nsMathTools_TMatrix16TypeFunc = globalTypeIdentifier->Type<nsMathTools::TMatrix16>();
    
    m.insert({ rtti__nsMathTools_TMatrix16TypeFunc, _nsMathTools_TMatrix16TypeFunc });
    
    TypeFunc _nsMathTools_TMatrix9TypeFunc;
    _nsMathTools_TMatrix9TypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsMathTools::TMatrix9>((nsMathTools::TMatrix9*) p, str);
    };
    _nsMathTools_TMatrix9TypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsMathTools::TMatrix9>((nsMathTools::TMatrix9*) p, str, err);
    };
    
    auto rtti__nsMathTools_TMatrix9TypeFunc = globalTypeIdentifier->Type<nsMathTools::TMatrix9>();
    
    m.insert({ rtti__nsMathTools_TMatrix9TypeFunc, _nsMathTools_TMatrix9TypeFunc });
    
    TypeFunc _nsMathTools_TOrientationTypeFunc;
    _nsMathTools_TOrientationTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsMathTools::TOrientation>((nsMathTools::TOrientation*) p, str);
    };
    _nsMathTools_TOrientationTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsMathTools::TOrientation>((nsMathTools::TOrientation*) p, str, err);
    };
    
    auto rtti__nsMathTools_TOrientationTypeFunc = globalTypeIdentifier->Type<nsMathTools::TOrientation>();
    
    m.insert({ rtti__nsMathTools_TOrientationTypeFunc, _nsMathTools_TOrientationTypeFunc });
    
    TypeFunc _nsMathTools_TPlaneTypeFunc;
    _nsMathTools_TPlaneTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsMathTools::TPlane>((nsMathTools::TPlane*) p, str);
    };
    _nsMathTools_TPlaneTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsMathTools::TPlane>((nsMathTools::TPlane*) p, str, err);
    };
    
    auto rtti__nsMathTools_TPlaneTypeFunc = globalTypeIdentifier->Type<nsMathTools::TPlane>();
    
    m.insert({ rtti__nsMathTools_TPlaneTypeFunc, _nsMathTools_TPlaneTypeFunc });
    
    TypeFunc _nsMathTools_TPoint2TypeFunc;
    _nsMathTools_TPoint2TypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsMathTools::TPoint2>((nsMathTools::TPoint2*) p, str);
    };
    _nsMathTools_TPoint2TypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsMathTools::TPoint2>((nsMathTools::TPoint2*) p, str, err);
    };
    
    auto rtti__nsMathTools_TPoint2TypeFunc = globalTypeIdentifier->Type<nsMathTools::TPoint2>();
    
    m.insert({ rtti__nsMathTools_TPoint2TypeFunc, _nsMathTools_TPoint2TypeFunc });
    
    TypeFunc _nsMathTools_TQuaternionTypeFunc;
    _nsMathTools_TQuaternionTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsMathTools::TQuaternion>((nsMathTools::TQuaternion*) p, str);
    };
    _nsMathTools_TQuaternionTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsMathTools::TQuaternion>((nsMathTools::TQuaternion*) p, str, err);
    };
    
    auto rtti__nsMathTools_TQuaternionTypeFunc = globalTypeIdentifier->Type<nsMathTools::TQuaternion>();
    
    m.insert({ rtti__nsMathTools_TQuaternionTypeFunc, _nsMathTools_TQuaternionTypeFunc });
    
    TypeFunc _nsMathTools_TVector2TypeFunc;
    _nsMathTools_TVector2TypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsMathTools::TVector2>((nsMathTools::TVector2*) p, str);
    };
    _nsMathTools_TVector2TypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsMathTools::TVector2>((nsMathTools::TVector2*) p, str, err);
    };
    
    auto rtti__nsMathTools_TVector2TypeFunc = globalTypeIdentifier->Type<nsMathTools::TVector2>();
    
    m.insert({ rtti__nsMathTools_TVector2TypeFunc, _nsMathTools_TVector2TypeFunc });
    
    TypeFunc _nsMathTools_TVector3TypeFunc;
    _nsMathTools_TVector3TypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsMathTools::TVector3>((nsMathTools::TVector3*) p, str);
    };
    _nsMathTools_TVector3TypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsMathTools::TVector3>((nsMathTools::TVector3*) p, str, err);
    };
    
    auto rtti__nsMathTools_TVector3TypeFunc = globalTypeIdentifier->Type<nsMathTools::TVector3>();
    
    m.insert({ rtti__nsMathTools_TVector3TypeFunc, _nsMathTools_TVector3TypeFunc });
    
    TypeFunc _nsMathTools_TVector4TypeFunc;
    _nsMathTools_TVector4TypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsMathTools::TVector4>((nsMathTools::TVector4*) p, str);
    };
    _nsMathTools_TVector4TypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsMathTools::TVector4>((nsMathTools::TVector4*) p, str, err);
    };
    
    auto rtti__nsMathTools_TVector4TypeFunc = globalTypeIdentifier->Type<nsMathTools::TVector4>();
    
    m.insert({ rtti__nsMathTools_TVector4TypeFunc, _nsMathTools_TVector4TypeFunc });
    
    TypeFunc _nsTornadoEngine_TArchetypeFieldTypeFunc;
    _nsTornadoEngine_TArchetypeFieldTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEngine::TArchetypeField>((nsTornadoEngine::TArchetypeField*) p, str);
    };
    _nsTornadoEngine_TArchetypeFieldTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEngine::TArchetypeField>((nsTornadoEngine::TArchetypeField*) p, str, err);
    };
    
    auto rtti__nsTornadoEngine_TArchetypeFieldTypeFunc = globalTypeIdentifier->Type<nsTornadoEngine::TArchetypeField>();
    
    m.insert({ rtti__nsTornadoEngine_TArchetypeFieldTypeFunc, _nsTornadoEngine_TArchetypeFieldTypeFunc });
    
    TypeFunc _nsTornadoEngine_TComponentContentTypeFunc;
    _nsTornadoEngine_TComponentContentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEngine::TComponentContent>((nsTornadoEngine::TComponentContent*) p, str);
    };
    _nsTornadoEngine_TComponentContentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEngine::TComponentContent>((nsTornadoEngine::TComponentContent*) p, str, err);
    };
    
    auto rtti__nsTornadoEngine_TComponentContentTypeFunc = globalTypeIdentifier->Type<nsTornadoEngine::TComponentContent>();
    
    m.insert({ rtti__nsTornadoEngine_TComponentContentTypeFunc, _nsTornadoEngine_TComponentContentTypeFunc });
    
    TypeFunc _nsTornadoEngine_TConveyorConfigTypeFunc;
    _nsTornadoEngine_TConveyorConfigTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEngine::TConveyorConfig>((nsTornadoEngine::TConveyorConfig*) p, str);
    };
    _nsTornadoEngine_TConveyorConfigTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEngine::TConveyorConfig>((nsTornadoEngine::TConveyorConfig*) p, str, err);
    };
    
    auto rtti__nsTornadoEngine_TConveyorConfigTypeFunc = globalTypeIdentifier->Type<nsTornadoEngine::TConveyorConfig>();
    
    m.insert({ rtti__nsTornadoEngine_TConveyorConfigTypeFunc, _nsTornadoEngine_TConveyorConfigTypeFunc });
    
    TypeFunc _nsTornadoEngine_TEntityContentTypeFunc;
    _nsTornadoEngine_TEntityContentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEngine::TEntityContent>((nsTornadoEngine::TEntityContent*) p, str);
    };
    _nsTornadoEngine_TEntityContentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEngine::TEntityContent>((nsTornadoEngine::TEntityContent*) p, str, err);
    };
    
    auto rtti__nsTornadoEngine_TEntityContentTypeFunc = globalTypeIdentifier->Type<nsTornadoEngine::TEntityContent>();
    
    m.insert({ rtti__nsTornadoEngine_TEntityContentTypeFunc, _nsTornadoEngine_TEntityContentTypeFunc });
    
    TypeFunc _nsTornadoEngine_TFrameworkResourcesTypeFunc;
    _nsTornadoEngine_TFrameworkResourcesTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEngine::TFrameworkResources>((nsTornadoEngine::TFrameworkResources*) p, str);
    };
    _nsTornadoEngine_TFrameworkResourcesTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEngine::TFrameworkResources>((nsTornadoEngine::TFrameworkResources*) p, str, err);
    };
    
    auto rtti__nsTornadoEngine_TFrameworkResourcesTypeFunc = globalTypeIdentifier->Type<nsTornadoEngine::TFrameworkResources>();
    
    m.insert({ rtti__nsTornadoEngine_TFrameworkResourcesTypeFunc, _nsTornadoEngine_TFrameworkResourcesTypeFunc });
    
    TypeFunc _nsTornadoEngine_TPrefabInstanceTypeFunc;
    _nsTornadoEngine_TPrefabInstanceTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEngine::TPrefabInstance>((nsTornadoEngine::TPrefabInstance*) p, str);
    };
    _nsTornadoEngine_TPrefabInstanceTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEngine::TPrefabInstance>((nsTornadoEngine::TPrefabInstance*) p, str, err);
    };
    
    auto rtti__nsTornadoEngine_TPrefabInstanceTypeFunc = globalTypeIdentifier->Type<nsTornadoEngine::TPrefabInstance>();
    
    m.insert({ rtti__nsTornadoEngine_TPrefabInstanceTypeFunc, _nsTornadoEngine_TPrefabInstanceTypeFunc });
    
    TypeFunc _nsTornadoEngine_TPrefabPatchTypeFunc;
    _nsTornadoEngine_TPrefabPatchTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEngine::TPrefabPatch>((nsTornadoEngine::TPrefabPatch*) p, str);
    };
    _nsTornadoEngine_TPrefabPatchTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEngine::TPrefabPatch>((nsTornadoEngine::TPrefabPatch*) p, str, err);
    };
    
    auto rtti__nsTornadoEngine_TPrefabPatchTypeFunc = globalTypeIdentifier->Type<nsTornadoEngine::TPrefabPatch>();
    
    m.insert({ rtti__nsTornadoEngine_TPrefabPatchTypeFunc, _nsTornadoEngine_TPrefabPatchTypeFunc });
    
    TypeFunc _nsTornadoEngine_TPrefabPatchOperationTypeFunc;
    _nsTornadoEngine_TPrefabPatchOperationTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEngine::TPrefabPatchOperation>((nsTornadoEngine::TPrefabPatchOperation*) p, str);
    };
    _nsTornadoEngine_TPrefabPatchOperationTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEngine::TPrefabPatchOperation>((nsTornadoEngine::TPrefabPatchOperation*) p, str, err);
    };
    
    auto rtti__nsTornadoEngine_TPrefabPatchOperationTypeFunc = globalTypeIdentifier->Type<nsTornadoEngine::TPrefabPatchOperation>();
    
    m.insert({ rtti__nsTornadoEngine_TPrefabPatchOperationTypeFunc, _nsTornadoEngine_TPrefabPatchOperationTypeFunc });
    
    TypeFunc _nsTornadoEngine_TPrefabResourceContentTypeFunc;
    _nsTornadoEngine_TPrefabResourceContentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEngine::TPrefabResourceContent>((nsTornadoEngine::TPrefabResourceContent*) p, str);
    };
    _nsTornadoEngine_TPrefabResourceContentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEngine::TPrefabResourceContent>((nsTornadoEngine::TPrefabResourceContent*) p, str, err);
    };
    
    auto rtti__nsTornadoEngine_TPrefabResourceContentTypeFunc = globalTypeIdentifier->Type<nsTornadoEngine::TPrefabResourceContent>();
    
    m.insert({ rtti__nsTornadoEngine_TPrefabResourceContentTypeFunc, _nsTornadoEngine_TPrefabResourceContentTypeFunc });
    
    TypeFunc _nsTornadoEngine_TProjectConfigTypeFunc;
    _nsTornadoEngine_TProjectConfigTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEngine::TProjectConfig>((nsTornadoEngine::TProjectConfig*) p, str);
    };
    _nsTornadoEngine_TProjectConfigTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEngine::TProjectConfig>((nsTornadoEngine::TProjectConfig*) p, str, err);
    };
    
    auto rtti__nsTornadoEngine_TProjectConfigTypeFunc = globalTypeIdentifier->Type<nsTornadoEngine::TProjectConfig>();
    
    m.insert({ rtti__nsTornadoEngine_TProjectConfigTypeFunc, _nsTornadoEngine_TProjectConfigTypeFunc });
    
    TypeFunc _nsTornadoEngine_TResourceContentMapTypeFunc;
    _nsTornadoEngine_TResourceContentMapTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEngine::TResourceContentMap>((nsTornadoEngine::TResourceContentMap*) p, str);
    };
    _nsTornadoEngine_TResourceContentMapTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEngine::TResourceContentMap>((nsTornadoEngine::TResourceContentMap*) p, str, err);
    };
    
    auto rtti__nsTornadoEngine_TResourceContentMapTypeFunc = globalTypeIdentifier->Type<nsTornadoEngine::TResourceContentMap>();
    
    m.insert({ rtti__nsTornadoEngine_TResourceContentMapTypeFunc, _nsTornadoEngine_TResourceContentMapTypeFunc });
    
    TypeFunc _nsTornadoEngine_TSceneResourceContentTypeFunc;
    _nsTornadoEngine_TSceneResourceContentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEngine::TSceneResourceContent>((nsTornadoEngine::TSceneResourceContent*) p, str);
    };
    _nsTornadoEngine_TSceneResourceContentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEngine::TSceneResourceContent>((nsTornadoEngine::TSceneResourceContent*) p, str, err);
    };
    
    auto rtti__nsTornadoEngine_TSceneResourceContentTypeFunc = globalTypeIdentifier->Type<nsTornadoEngine::TSceneResourceContent>();
    
    m.insert({ rtti__nsTornadoEngine_TSceneResourceContentTypeFunc, _nsTornadoEngine_TSceneResourceContentTypeFunc });
    
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
void TTornadoEngineJsonSerializer::Serialize(void* p, std::string& str, int rtti)
{
    Init();
    mTypeFuncVector[rtti].serializeFunc(p, str);
}
//---------------------------------------------------------------------------------------
bool TTornadoEngineJsonSerializer::Deserialize(void* p, const std::string& str, int rtti, std::string& err)
{
    Init();
    return mTypeFuncVector[rtti].deserializeFunc(p, str, err);
}
//---------------------------------------------------------------------------------------
bool TTornadoEngineJsonSerializer::Has(int rtti)
{
    Init();
    if (rtti < 0 || rtti >= mTypeFuncVector.size()) {
        return false;
    }
    return mTypeFuncVector[rtti].serializeFunc != nullptr;
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Serialize(nsMathTools::TMatrix16* p, Jobj& obj)
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
void TTornadoEngineJsonSerializer::_Deserialize(nsMathTools::TMatrix16* p, const Jobj& obj)
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
void TTornadoEngineJsonSerializer::_Serialize(nsMathTools::TMatrix9* p, Jobj& obj)
{
    PUM::Push(obj, "_11", p->_11);
    PUM::Push(obj, "_12", p->_12);
    PUM::Push(obj, "_13", p->_13);
    PUM::Push(obj, "_21", p->_21);
    PUM::Push(obj, "_22", p->_22);
    PUM::Push(obj, "_23", p->_23);
    PUM::Push(obj, "_31", p->_31);
    PUM::Push(obj, "_32", p->_32);
    PUM::Push(obj, "_33", p->_33);
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Deserialize(nsMathTools::TMatrix9* p, const Jobj& obj)
{
    POM::PopNum(obj, "_11", p->_11);
    POM::PopNum(obj, "_12", p->_12);
    POM::PopNum(obj, "_13", p->_13);
    POM::PopNum(obj, "_21", p->_21);
    POM::PopNum(obj, "_22", p->_22);
    POM::PopNum(obj, "_23", p->_23);
    POM::PopNum(obj, "_31", p->_31);
    POM::PopNum(obj, "_32", p->_32);
    POM::PopNum(obj, "_33", p->_33);
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Serialize(nsMathTools::TOrientation* p, Jobj& obj)
{
    auto axis_o = PUM::AddObject(obj, "axis");
    _Serialize(&(p->axis), axis_o);
    PUM::Push(obj, "angle", p->angle);
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Deserialize(nsMathTools::TOrientation* p, const Jobj& obj)
{
    auto axis_o0 = POM::FindObject(obj, "axis");
    _Deserialize(&(p->axis), axis_o0);
    POM::PopNum(obj, "angle", p->angle);
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Serialize(nsMathTools::TPlane* p, Jobj& obj)
{
    PUM::Push(obj, "a", p->a);
    PUM::Push(obj, "b", p->b);
    PUM::Push(obj, "c", p->c);
    PUM::Push(obj, "d", p->d);
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Deserialize(nsMathTools::TPlane* p, const Jobj& obj)
{
    POM::PopNum(obj, "a", p->a);
    POM::PopNum(obj, "b", p->b);
    POM::PopNum(obj, "c", p->c);
    POM::PopNum(obj, "d", p->d);
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Serialize(nsMathTools::TPoint2* p, Jobj& obj)
{
    PUM::Push(obj, "x", p->x);
    PUM::Push(obj, "y", p->y);
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Deserialize(nsMathTools::TPoint2* p, const Jobj& obj)
{
    POM::PopNum(obj, "x", p->x);
    POM::PopNum(obj, "y", p->y);
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Serialize(nsMathTools::TQuaternion* p, Jobj& obj)
{
    PUM::Push(obj, "x", p->x);
    PUM::Push(obj, "y", p->y);
    PUM::Push(obj, "z", p->z);
    PUM::Push(obj, "w", p->w);
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Deserialize(nsMathTools::TQuaternion* p, const Jobj& obj)
{
    POM::PopNum(obj, "x", p->x);
    POM::PopNum(obj, "y", p->y);
    POM::PopNum(obj, "z", p->z);
    POM::PopNum(obj, "w", p->w);
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Serialize(nsMathTools::TVector2* p, Jobj& obj)
{
    PUM::Push(obj, "x", p->x);
    PUM::Push(obj, "y", p->y);
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Deserialize(nsMathTools::TVector2* p, const Jobj& obj)
{
    POM::PopNum(obj, "x", p->x);
    POM::PopNum(obj, "y", p->y);
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Serialize(nsMathTools::TVector3* p, Jobj& obj)
{
    PUM::Push(obj, "x", p->x);
    PUM::Push(obj, "y", p->y);
    PUM::Push(obj, "z", p->z);
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Deserialize(nsMathTools::TVector3* p, const Jobj& obj)
{
    POM::PopNum(obj, "x", p->x);
    POM::PopNum(obj, "y", p->y);
    POM::PopNum(obj, "z", p->z);
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Serialize(nsMathTools::TVector4* p, Jobj& obj)
{
    PUM::Push(obj, "x", p->x);
    PUM::Push(obj, "y", p->y);
    PUM::Push(obj, "z", p->z);
    PUM::Push(obj, "w", p->w);
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Deserialize(nsMathTools::TVector4* p, const Jobj& obj)
{
    POM::PopNum(obj, "x", p->x);
    POM::PopNum(obj, "y", p->y);
    POM::PopNum(obj, "z", p->z);
    POM::PopNum(obj, "w", p->w);
}
//---------------------------------------------------------------------------------------
std::string TTornadoEngineJsonSerializer::_SerializeEnum(nsTornadoEngine::FieldAccessType* p)
{
    switch (*p) {
        case nsTornadoEngine::FieldAccessType::DELETE:
            return "DELETE";
        case nsTornadoEngine::FieldAccessType::READ:
            return "READ";
        case nsTornadoEngine::FieldAccessType::SHOW:
            return "SHOW";
        case nsTornadoEngine::FieldAccessType::WRITE:
            return "WRITE";
        default:;
    }
    return "";
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_DeserializeEnum(std::string& str, nsTornadoEngine::FieldAccessType* p)
{
    std::map<std::string, nsTornadoEngine::FieldAccessType> m;
    m.insert({"DELETE", nsTornadoEngine::FieldAccessType::DELETE});
    m.insert({"READ", nsTornadoEngine::FieldAccessType::READ});
    m.insert({"SHOW", nsTornadoEngine::FieldAccessType::SHOW});
    m.insert({"WRITE", nsTornadoEngine::FieldAccessType::WRITE});
    *p = m[str];
}
//---------------------------------------------------------------------------------------
std::string TTornadoEngineJsonSerializer::_SerializeEnum(nsTornadoEngine::ModuleType* p)
{
    switch (*p) {
        case nsTornadoEngine::ModuleType::DataBase:
            return "DataBase";
        case nsTornadoEngine::ModuleType::GraphicEngine:
            return "GraphicEngine";
        case nsTornadoEngine::ModuleType::Logic:
            return "Logic";
        case nsTornadoEngine::ModuleType::MMOEngine:
            return "MMOEngine";
        case nsTornadoEngine::ModuleType::NetTransport:
            return "NetTransport";
        case nsTornadoEngine::ModuleType::PhysicEngine:
            return "PhysicEngine";
        case nsTornadoEngine::ModuleType::SoundEngine:
            return "SoundEngine";
        default:;
    }
    return "";
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_DeserializeEnum(std::string& str, nsTornadoEngine::ModuleType* p)
{
    std::map<std::string, nsTornadoEngine::ModuleType> m;
    m.insert({"DataBase", nsTornadoEngine::ModuleType::DataBase});
    m.insert({"GraphicEngine", nsTornadoEngine::ModuleType::GraphicEngine});
    m.insert({"Logic", nsTornadoEngine::ModuleType::Logic});
    m.insert({"MMOEngine", nsTornadoEngine::ModuleType::MMOEngine});
    m.insert({"NetTransport", nsTornadoEngine::ModuleType::NetTransport});
    m.insert({"PhysicEngine", nsTornadoEngine::ModuleType::PhysicEngine});
    m.insert({"SoundEngine", nsTornadoEngine::ModuleType::SoundEngine});
    *p = m[str];
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Serialize(nsTornadoEngine::TArchetypeField* p, Jobj& obj)
{
    PUM::Push(obj, "name", p->name);
    PUM::Value access_a0(rapidjson::kArrayType);
    for(auto& access_e0 : p->access) {
        auto access_c1 = _SerializeEnum(&access_e0);
        PUM::PushBack(access_a0, access_c1);
    }
    PUM::Push(obj, "access", access_a0);
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Deserialize(nsTornadoEngine::TArchetypeField* p, const Jobj& obj)
{
    POM::PopStr(obj, "name", p->name);
    auto access_a0 = POM::FindArray(obj, "access");
    for(auto& access_e0 : access_a0) {
        std::string access_o1 = access_e0.GetString();
        nsTornadoEngine::FieldAccessType access_c1;
        _DeserializeEnum(access_o1, &access_c1);
        p->access.push_back(access_c1);
    }
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Serialize(nsTornadoEngine::TComponentContent* p, Jobj& obj)
{
    PUM::Push(obj, "typeName", p->typeName);
    PUM::Push(obj, "jsonBody", p->jsonBody);
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Deserialize(nsTornadoEngine::TComponentContent* p, const Jobj& obj)
{
    POM::PopStr(obj, "typeName", p->typeName);
    POM::PopStr(obj, "jsonBody", p->jsonBody);
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Serialize(nsTornadoEngine::TConveyorConfig* p, Jobj& obj)
{
    PUM::Value modules_a0(rapidjson::kArrayType);
    for(auto& modules_e0 : p->modules) {
        auto modules_c1 = _SerializeEnum(&modules_e0);
        PUM::PushBack(modules_a0, modules_c1);
    }
    PUM::Push(obj, "modules", modules_a0);
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Deserialize(nsTornadoEngine::TConveyorConfig* p, const Jobj& obj)
{
    auto modules_a0 = POM::FindArray(obj, "modules");
    for(auto& modules_e0 : modules_a0) {
        std::string modules_o1 = modules_e0.GetString();
        nsTornadoEngine::ModuleType modules_c1;
        _DeserializeEnum(modules_o1, &modules_c1);
        p->modules.push_back(modules_c1);
    }
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Serialize(nsTornadoEngine::TEntityContent* p, Jobj& obj)
{
    PUM::Value components_a0(rapidjson::kArrayType);
    for(auto& components_e0 : p->components) {
        PUM::Value components_a1(rapidjson::kObjectType);
        auto components_c1 = components_a1.GetObject();
        _Serialize(&components_e0, components_c1);
        PUM::PushBack(components_a0, components_a1);
    }
    PUM::Push(obj, "components", components_a0);
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Deserialize(nsTornadoEngine::TEntityContent* p, const Jobj& obj)
{
    auto components_a0 = POM::FindArray(obj, "components");
    for(auto& components_e0 : components_a0) {
        auto components_o1 = components_e0.GetObject();
        nsTornadoEngine::TComponentContent components_c1;
        _Deserialize(&components_c1, components_o1);
        p->components.push_back(components_c1);
    }
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Serialize(nsTornadoEngine::TFrameworkResources* p, Jobj& obj)
{
    auto resources_o = PUM::AddObject(obj, "resources");
    _Serialize(&(p->resources), resources_o);
    auto prefabs_o = PUM::AddObject(obj, "prefabs");
    _Serialize(&(p->prefabs), prefabs_o);
    auto scenes_o = PUM::AddObject(obj, "scenes");
    _Serialize(&(p->scenes), scenes_o);
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Deserialize(nsTornadoEngine::TFrameworkResources* p, const Jobj& obj)
{
    auto resources_o0 = POM::FindObject(obj, "resources");
    _Deserialize(&(p->resources), resources_o0);
    auto prefabs_o0 = POM::FindObject(obj, "prefabs");
    _Deserialize(&(p->prefabs), prefabs_o0);
    auto scenes_o0 = POM::FindObject(obj, "scenes");
    _Deserialize(&(p->scenes), scenes_o0);
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Serialize(nsTornadoEngine::TPrefabInstance* p, Jobj& obj)
{
    PUM::Push(obj, "parentGuid", p->parentGuid);
    PUM::Push(obj, "prefabGuid", p->prefabGuid);
    auto localMatrix_o = PUM::AddObject(obj, "localMatrix");
    _Serialize(&(p->localMatrix), localMatrix_o);
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Deserialize(nsTornadoEngine::TPrefabInstance* p, const Jobj& obj)
{
    POM::PopStr(obj, "parentGuid", p->parentGuid);
    POM::PopStr(obj, "prefabGuid", p->prefabGuid);
    auto localMatrix_o0 = POM::FindObject(obj, "localMatrix");
    _Deserialize(&(p->localMatrix), localMatrix_o0);
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Serialize(nsTornadoEngine::TPrefabPatch* p, Jobj& obj)
{
    auto operations_c0 = PUM::AddObject(obj, "operations");
    for(auto& operations_e0 : p->operations) {
        auto operations_a0 = PUM::AddObject(operations_c0, PUM::ConvertToString(operations_e0.first).data());
        _Serialize(&(operations_e0.second), operations_a0);
    }
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Deserialize(nsTornadoEngine::TPrefabPatch* p, const Jobj& obj)
{
    auto operations_a0 = POM::FindObject(obj, "operations");
    for(auto& operations_e0 : operations_a0) {
        auto operations_o1 = operations_e0.value.GetObject();
        nsTornadoEngine::TPrefabPatchOperation operations_c1;
        _Deserialize(&operations_c1, operations_o1);
        p->operations.insert({ (TPrefabPatchOperation::Operation)std::stod(operations_e0.name.GetString()), operations_c1 });
    }
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Serialize(nsTornadoEngine::TPrefabPatchOperation* p, Jobj& obj)
{
    auto operation_c0 = _SerializeEnum(&(p->operation));
    PUM::Push(obj, "operation", operation_c0);
    PUM::Push(obj, "guid", p->guid);
    PUM::Value components_a0(rapidjson::kArrayType);
    for(auto& components_e0 : p->components) {
        PUM::Value components_a1(rapidjson::kObjectType);
        auto components_c1 = components_a1.GetObject();
        _Serialize(&components_e0, components_c1);
        PUM::PushBack(components_a0, components_a1);
    }
    PUM::Push(obj, "components", components_a0);
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Deserialize(nsTornadoEngine::TPrefabPatchOperation* p, const Jobj& obj)
{
    std::string operation_c0;
    POM::PopStr(obj, "operation", operation_c0);
    _DeserializeEnum(operation_c0, &(p->operation));
    POM::PopStr(obj, "guid", p->guid);
    auto components_a0 = POM::FindArray(obj, "components");
    for(auto& components_e0 : components_a0) {
        auto components_o1 = components_e0.GetObject();
        nsTornadoEngine::TComponentContent components_c1;
        _Deserialize(&components_c1, components_o1);
        p->components.push_back(components_c1);
    }
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Serialize(nsTornadoEngine::TPrefabResourceContent* p, Jobj& obj)
{
    PUM::Push(obj, "guid", p->guid);
    PUM::Push(obj, "prefabParentGuid", p->prefabParentGuid);
    PUM::Value entities_a0(rapidjson::kArrayType);
    for(auto& entities_e0 : p->entities) {
        PUM::Value entities_a1(rapidjson::kObjectType);
        auto entities_c1 = entities_a1.GetObject();
        _Serialize(&entities_e0, entities_c1);
        PUM::PushBack(entities_a0, entities_a1);
    }
    PUM::Push(obj, "entities", entities_a0);
    auto patch_o = PUM::AddObject(obj, "patch");
    _Serialize(&(p->patch), patch_o);
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Deserialize(nsTornadoEngine::TPrefabResourceContent* p, const Jobj& obj)
{
    POM::PopStr(obj, "guid", p->guid);
    POM::PopStr(obj, "prefabParentGuid", p->prefabParentGuid);
    auto entities_a0 = POM::FindArray(obj, "entities");
    for(auto& entities_e0 : entities_a0) {
        auto entities_o1 = entities_e0.GetObject();
        nsTornadoEngine::TEntityContent entities_c1;
        _Deserialize(&entities_c1, entities_o1);
        p->entities.push_back(entities_c1);
    }
    auto patch_o0 = POM::FindObject(obj, "patch");
    _Deserialize(&(p->patch), patch_o0);
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Serialize(nsTornadoEngine::TProjectConfig* p, Jobj& obj)
{
    PUM::Push(obj, "binaryFilePath", p->binaryFilePath);
    PUM::Push(obj, "conveyorFilePath", p->conveyorFilePath);
    PUM::Push(obj, "resourcesFilePath", p->resourcesFilePath);
    PUM::Value startScenesGuid_a0(rapidjson::kArrayType);
    for(auto& startScenesGuid_e0 : p->startScenesGuid) {
        PUM::PushBack(startScenesGuid_a0, startScenesGuid_e0);
    }
    PUM::Push(obj, "startScenesGuid", startScenesGuid_a0);
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Deserialize(nsTornadoEngine::TProjectConfig* p, const Jobj& obj)
{
    POM::PopStr(obj, "binaryFilePath", p->binaryFilePath);
    POM::PopStr(obj, "conveyorFilePath", p->conveyorFilePath);
    POM::PopStr(obj, "resourcesFilePath", p->resourcesFilePath);
    if (POM::IsArray(obj, "startScenesGuid")) {
        auto startScenesGuid_a0 = POM::FindArray(obj, "startScenesGuid");
        for(auto& startScenesGuid_e0 : startScenesGuid_a0) {
            p->startScenesGuid.push_back(startScenesGuid_e0.GetString());
        }
    } else {
        std::string startScenesGuid_t0;
        POM::PopStr(obj, "startScenesGuid", startScenesGuid_t0);
        p->startScenesGuid.push_back(startScenesGuid_t0);
    }
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Serialize(nsTornadoEngine::TResourceContentMap* p, Jobj& obj)
{
    auto guidPathMap_c0 = PUM::AddObject(obj, "guidPathMap");
    for(auto& guidPathMap_e0 : p->guidPathMap) {
        PUM::Push(guidPathMap_c0, PUM::ConvertToString(guidPathMap_e0.first).data(), guidPathMap_e0.second);
    }
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Deserialize(nsTornadoEngine::TResourceContentMap* p, const Jobj& obj)
{
    auto guidPathMap_a0 = POM::FindObject(obj, "guidPathMap");
    for(auto& guidPathMap_e0 : guidPathMap_a0) {
        p->guidPathMap.insert({ guidPathMap_e0.name.GetString(), guidPathMap_e0.value.GetString() });
    }
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Serialize(nsTornadoEngine::TSceneResourceContent* p, Jobj& obj)
{
    PUM::Push(obj, "guid", p->guid);
    PUM::Push(obj, "groupedByRankEntityGuidHash", p->groupedByRankEntityGuidHash);
    PUM::Value entities_a0(rapidjson::kArrayType);
    for(auto& entities_e0 : p->entities) {
        PUM::Value entities_a1(rapidjson::kObjectType);
        auto entities_c1 = entities_a1.GetObject();
        _Serialize(&entities_e0, entities_c1);
        PUM::PushBack(entities_a0, entities_a1);
    }
    PUM::Push(obj, "entities", entities_a0);
    PUM::Value prefabInstances_a0(rapidjson::kArrayType);
    for(auto& prefabInstances_e0 : p->prefabInstances) {
        PUM::Value prefabInstances_a1(rapidjson::kObjectType);
        auto prefabInstances_c1 = prefabInstances_a1.GetObject();
        _Serialize(&prefabInstances_e0, prefabInstances_c1);
        PUM::PushBack(prefabInstances_a0, prefabInstances_a1);
    }
    PUM::Push(obj, "prefabInstances", prefabInstances_a0);
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Deserialize(nsTornadoEngine::TSceneResourceContent* p, const Jobj& obj)
{
    POM::PopStr(obj, "guid", p->guid);
    POM::PopStr(obj, "groupedByRankEntityGuidHash", p->groupedByRankEntityGuidHash);
    auto entities_a0 = POM::FindArray(obj, "entities");
    for(auto& entities_e0 : entities_a0) {
        auto entities_o1 = entities_e0.GetObject();
        nsTornadoEngine::TEntityContent entities_c1;
        _Deserialize(&entities_c1, entities_o1);
        p->entities.push_back(entities_c1);
    }
    auto prefabInstances_a0 = POM::FindArray(obj, "prefabInstances");
    for(auto& prefabInstances_e0 : prefabInstances_a0) {
        auto prefabInstances_o1 = prefabInstances_e0.GetObject();
        nsTornadoEngine::TPrefabInstance prefabInstances_c1;
        _Deserialize(&prefabInstances_c1, prefabInstances_o1);
        p->prefabInstances.push_back(prefabInstances_c1);
    }
}
//---------------------------------------------------------------------------------------
std::string TTornadoEngineJsonSerializer::_SerializeEnum(nsTornadoEngine::TPrefabPatchOperation::Operation* p)
{
    switch (*p) {
        case nsTornadoEngine::TPrefabPatchOperation::Operation::ADD_COMPONENT:
            return "ADD_COMPONENT";
        case nsTornadoEngine::TPrefabPatchOperation::Operation::ADD_ENTITY:
            return "ADD_ENTITY";
        case nsTornadoEngine::TPrefabPatchOperation::Operation::REMOVE_COMPONENT:
            return "REMOVE_COMPONENT";
        case nsTornadoEngine::TPrefabPatchOperation::Operation::REMOVE_ENTITY:
            return "REMOVE_ENTITY";
        case nsTornadoEngine::TPrefabPatchOperation::Operation::UPDATE_COMPONENT:
            return "UPDATE_COMPONENT";
        default:;
    }
    return "";
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_DeserializeEnum(std::string& str, nsTornadoEngine::TPrefabPatchOperation::Operation* p)
{
    std::map<std::string, nsTornadoEngine::TPrefabPatchOperation::Operation> m;
    m.insert({"ADD_COMPONENT", nsTornadoEngine::TPrefabPatchOperation::Operation::ADD_COMPONENT});
    m.insert({"ADD_ENTITY", nsTornadoEngine::TPrefabPatchOperation::Operation::ADD_ENTITY});
    m.insert({"REMOVE_COMPONENT", nsTornadoEngine::TPrefabPatchOperation::Operation::REMOVE_COMPONENT});
    m.insert({"REMOVE_ENTITY", nsTornadoEngine::TPrefabPatchOperation::Operation::REMOVE_ENTITY});
    m.insert({"UPDATE_COMPONENT", nsTornadoEngine::TPrefabPatchOperation::Operation::UPDATE_COMPONENT});
    *p = m[str];
}
//---------------------------------------------------------------------------------------
