/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.2.4, build 55 [Json, Binary, ImGui, EntityManager, Reflection, TypeInformation]
// File has been generated at 2021_12_16 21:27:28.742
	
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
    
    TypeFunc _nsTornadoEngine_TGameEngineResourcesTypeFunc;
    _nsTornadoEngine_TGameEngineResourcesTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEngine::TGameEngineResources>((nsTornadoEngine::TGameEngineResources*) p, str);
    };
    _nsTornadoEngine_TGameEngineResourcesTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEngine::TGameEngineResources>((nsTornadoEngine::TGameEngineResources*) p, str, err);
    };
    
    auto rtti__nsTornadoEngine_TGameEngineResourcesTypeFunc = globalTypeIdentifier->Type<nsTornadoEngine::TGameEngineResources>();
    
    m.insert({ rtti__nsTornadoEngine_TGameEngineResourcesTypeFunc, _nsTornadoEngine_TGameEngineResourcesTypeFunc });
    
    TypeFunc _nsTornadoEngine_TGeneratorConfigTypeFunc;
    _nsTornadoEngine_TGeneratorConfigTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEngine::TGeneratorConfig>((nsTornadoEngine::TGeneratorConfig*) p, str);
    };
    _nsTornadoEngine_TGeneratorConfigTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEngine::TGeneratorConfig>((nsTornadoEngine::TGeneratorConfig*) p, str, err);
    };
    
    auto rtti__nsTornadoEngine_TGeneratorConfigTypeFunc = globalTypeIdentifier->Type<nsTornadoEngine::TGeneratorConfig>();
    
    m.insert({ rtti__nsTornadoEngine_TGeneratorConfigTypeFunc, _nsTornadoEngine_TGeneratorConfigTypeFunc });
    
    TypeFunc _nsTornadoEngine_TGraphicEngineResourcesTypeFunc;
    _nsTornadoEngine_TGraphicEngineResourcesTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEngine::TGraphicEngineResources>((nsTornadoEngine::TGraphicEngineResources*) p, str);
    };
    _nsTornadoEngine_TGraphicEngineResourcesTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEngine::TGraphicEngineResources>((nsTornadoEngine::TGraphicEngineResources*) p, str, err);
    };
    
    auto rtti__nsTornadoEngine_TGraphicEngineResourcesTypeFunc = globalTypeIdentifier->Type<nsTornadoEngine::TGraphicEngineResources>();
    
    m.insert({ rtti__nsTornadoEngine_TGraphicEngineResourcesTypeFunc, _nsTornadoEngine_TGraphicEngineResourcesTypeFunc });
    
    TypeFunc _nsTornadoEngine_TOgreCfgTypeFunc;
    _nsTornadoEngine_TOgreCfgTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEngine::TOgreCfg>((nsTornadoEngine::TOgreCfg*) p, str);
    };
    _nsTornadoEngine_TOgreCfgTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEngine::TOgreCfg>((nsTornadoEngine::TOgreCfg*) p, str, err);
    };
    
    auto rtti__nsTornadoEngine_TOgreCfgTypeFunc = globalTypeIdentifier->Type<nsTornadoEngine::TOgreCfg>();
    
    m.insert({ rtti__nsTornadoEngine_TOgreCfgTypeFunc, _nsTornadoEngine_TOgreCfgTypeFunc });
    
    TypeFunc _nsTornadoEngine_TPrefabContentTypeFunc;
    _nsTornadoEngine_TPrefabContentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEngine::TPrefabContent>((nsTornadoEngine::TPrefabContent*) p, str);
    };
    _nsTornadoEngine_TPrefabContentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEngine::TPrefabContent>((nsTornadoEngine::TPrefabContent*) p, str, err);
    };
    
    auto rtti__nsTornadoEngine_TPrefabContentTypeFunc = globalTypeIdentifier->Type<nsTornadoEngine::TPrefabContent>();
    
    m.insert({ rtti__nsTornadoEngine_TPrefabContentTypeFunc, _nsTornadoEngine_TPrefabContentTypeFunc });
    
    TypeFunc _nsTornadoEngine_TPrefabContentMapTypeFunc;
    _nsTornadoEngine_TPrefabContentMapTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEngine::TPrefabContentMap>((nsTornadoEngine::TPrefabContentMap*) p, str);
    };
    _nsTornadoEngine_TPrefabContentMapTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEngine::TPrefabContentMap>((nsTornadoEngine::TPrefabContentMap*) p, str, err);
    };
    
    auto rtti__nsTornadoEngine_TPrefabContentMapTypeFunc = globalTypeIdentifier->Type<nsTornadoEngine::TPrefabContentMap>();
    
    m.insert({ rtti__nsTornadoEngine_TPrefabContentMapTypeFunc, _nsTornadoEngine_TPrefabContentMapTypeFunc });
    
    TypeFunc _nsTornadoEngine_TPrefabHeaderTypeFunc;
    _nsTornadoEngine_TPrefabHeaderTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEngine::TPrefabHeader>((nsTornadoEngine::TPrefabHeader*) p, str);
    };
    _nsTornadoEngine_TPrefabHeaderTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEngine::TPrefabHeader>((nsTornadoEngine::TPrefabHeader*) p, str, err);
    };
    
    auto rtti__nsTornadoEngine_TPrefabHeaderTypeFunc = globalTypeIdentifier->Type<nsTornadoEngine::TPrefabHeader>();
    
    m.insert({ rtti__nsTornadoEngine_TPrefabHeaderTypeFunc, _nsTornadoEngine_TPrefabHeaderTypeFunc });
    
    TypeFunc _nsTornadoEngine_TProjectConfigTypeFunc;
    _nsTornadoEngine_TProjectConfigTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEngine::TProjectConfig>((nsTornadoEngine::TProjectConfig*) p, str);
    };
    _nsTornadoEngine_TProjectConfigTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEngine::TProjectConfig>((nsTornadoEngine::TProjectConfig*) p, str, err);
    };
    
    auto rtti__nsTornadoEngine_TProjectConfigTypeFunc = globalTypeIdentifier->Type<nsTornadoEngine::TProjectConfig>();
    
    m.insert({ rtti__nsTornadoEngine_TProjectConfigTypeFunc, _nsTornadoEngine_TProjectConfigTypeFunc });
    
    TypeFunc _nsTornadoEngine_TProjectInfoTypeFunc;
    _nsTornadoEngine_TProjectInfoTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEngine::TProjectInfo>((nsTornadoEngine::TProjectInfo*) p, str);
    };
    _nsTornadoEngine_TProjectInfoTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEngine::TProjectInfo>((nsTornadoEngine::TProjectInfo*) p, str, err);
    };
    
    auto rtti__nsTornadoEngine_TProjectInfoTypeFunc = globalTypeIdentifier->Type<nsTornadoEngine::TProjectInfo>();
    
    m.insert({ rtti__nsTornadoEngine_TProjectInfoTypeFunc, _nsTornadoEngine_TProjectInfoTypeFunc });
    
    TypeFunc _nsTornadoEngine_TResourceContentTypeFunc;
    _nsTornadoEngine_TResourceContentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEngine::TResourceContent>((nsTornadoEngine::TResourceContent*) p, str);
    };
    _nsTornadoEngine_TResourceContentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEngine::TResourceContent>((nsTornadoEngine::TResourceContent*) p, str, err);
    };
    
    auto rtti__nsTornadoEngine_TResourceContentTypeFunc = globalTypeIdentifier->Type<nsTornadoEngine::TResourceContent>();
    
    m.insert({ rtti__nsTornadoEngine_TResourceContentTypeFunc, _nsTornadoEngine_TResourceContentTypeFunc });
    
    TypeFunc _nsTornadoEngine_TResourceContentMapTypeFunc;
    _nsTornadoEngine_TResourceContentMapTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEngine::TResourceContentMap>((nsTornadoEngine::TResourceContentMap*) p, str);
    };
    _nsTornadoEngine_TResourceContentMapTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEngine::TResourceContentMap>((nsTornadoEngine::TResourceContentMap*) p, str, err);
    };
    
    auto rtti__nsTornadoEngine_TResourceContentMapTypeFunc = globalTypeIdentifier->Type<nsTornadoEngine::TResourceContentMap>();
    
    m.insert({ rtti__nsTornadoEngine_TResourceContentMapTypeFunc, _nsTornadoEngine_TResourceContentMapTypeFunc });
    
    TypeFunc _nsTornadoEngine_TSceneContentTypeFunc;
    _nsTornadoEngine_TSceneContentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEngine::TSceneContent>((nsTornadoEngine::TSceneContent*) p, str);
    };
    _nsTornadoEngine_TSceneContentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEngine::TSceneContent>((nsTornadoEngine::TSceneContent*) p, str, err);
    };
    
    auto rtti__nsTornadoEngine_TSceneContentTypeFunc = globalTypeIdentifier->Type<nsTornadoEngine::TSceneContent>();
    
    m.insert({ rtti__nsTornadoEngine_TSceneContentTypeFunc, _nsTornadoEngine_TSceneContentTypeFunc });
    
    TypeFunc _nsTornadoEngine_TSceneContentMapTypeFunc;
    _nsTornadoEngine_TSceneContentMapTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEngine::TSceneContentMap>((nsTornadoEngine::TSceneContentMap*) p, str);
    };
    _nsTornadoEngine_TSceneContentMapTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEngine::TSceneContentMap>((nsTornadoEngine::TSceneContentMap*) p, str, err);
    };
    
    auto rtti__nsTornadoEngine_TSceneContentMapTypeFunc = globalTypeIdentifier->Type<nsTornadoEngine::TSceneContentMap>();
    
    m.insert({ rtti__nsTornadoEngine_TSceneContentMapTypeFunc, _nsTornadoEngine_TSceneContentMapTypeFunc });
    
    TypeFunc _nsTornadoEngine_TSceneHeaderTypeFunc;
    _nsTornadoEngine_TSceneHeaderTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsTornadoEngine::TSceneHeader>((nsTornadoEngine::TSceneHeader*) p, str);
    };
    _nsTornadoEngine_TSceneHeaderTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsTornadoEngine::TSceneHeader>((nsTornadoEngine::TSceneHeader*) p, str, err);
    };
    
    auto rtti__nsTornadoEngine_TSceneHeaderTypeFunc = globalTypeIdentifier->Type<nsTornadoEngine::TSceneHeader>();
    
    m.insert({ rtti__nsTornadoEngine_TSceneHeaderTypeFunc, _nsTornadoEngine_TSceneHeaderTypeFunc });
    
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
    auto graphicEngine_o = PUM::AddObject(obj, "graphicEngine");
    _Serialize(&(p->graphicEngine), graphicEngine_o);
    auto gameEngine_o = PUM::AddObject(obj, "gameEngine");
    _Serialize(&(p->gameEngine), gameEngine_o);
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Deserialize(nsTornadoEngine::TFrameworkResources* p, const Jobj& obj)
{
    auto graphicEngine_o0 = POM::FindObject(obj, "graphicEngine");
    _Deserialize(&(p->graphicEngine), graphicEngine_o0);
    auto gameEngine_o0 = POM::FindObject(obj, "gameEngine");
    _Deserialize(&(p->gameEngine), gameEngine_o0);
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Serialize(nsTornadoEngine::TGameEngineResources* p, Jobj& obj)
{
    PUM::Push(obj, "sceneManagerContentMapPath", p->sceneManagerContentMapPath);
    PUM::Value startScenesGuid_a0(rapidjson::kArrayType);
    for(auto& startScenesGuid_e0 : p->startScenesGuid) {
        PUM::PushBack(startScenesGuid_a0, startScenesGuid_e0);
    }
    PUM::Push(obj, "startScenesGuid", startScenesGuid_a0);
    PUM::Push(obj, "prefabManagerContentMapPath", p->prefabManagerContentMapPath);
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Deserialize(nsTornadoEngine::TGameEngineResources* p, const Jobj& obj)
{
    POM::PopStr(obj, "sceneManagerContentMapPath", p->sceneManagerContentMapPath);
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
    POM::PopStr(obj, "prefabManagerContentMapPath", p->prefabManagerContentMapPath);
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Serialize(nsTornadoEngine::TGeneratorConfig* p, Jobj& obj)
{
    PUM::Push(obj, "nameSpace", p->nameSpace);
    PUM::Push(obj, "directoryPath", p->directoryPath);
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Deserialize(nsTornadoEngine::TGeneratorConfig* p, const Jobj& obj)
{
    POM::PopStr(obj, "nameSpace", p->nameSpace);
    POM::PopStr(obj, "directoryPath", p->directoryPath);
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Serialize(nsTornadoEngine::TGraphicEngineResources* p, Jobj& obj)
{
    PUM::Push(obj, "terrainPath", p->terrainPath);
    auto pluginsCfg_o = PUM::AddObject(obj, "pluginsCfg");
    _Serialize(&(p->pluginsCfg), pluginsCfg_o);
    auto ogreCfg_o = PUM::AddObject(obj, "ogreCfg");
    _Serialize(&(p->ogreCfg), ogreCfg_o);
    auto resources_c0 = PUM::AddObject(obj, "resources");
    for(auto& resources_e0 : p->resources) {
        PUM::Value resources_a1(rapidjson::kArrayType);
        for(auto& resources_e1 : resources_e0.second) {
            PUM::PushBack(resources_a1, resources_e1);
        }
        PUM::Push(resources_c0, PUM::ConvertToString(resources_e0.first).data(), resources_a1);
    }
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Deserialize(nsTornadoEngine::TGraphicEngineResources* p, const Jobj& obj)
{
    POM::PopStr(obj, "terrainPath", p->terrainPath);
    auto pluginsCfg_o0 = POM::FindObject(obj, "pluginsCfg");
    _Deserialize(&(p->pluginsCfg), pluginsCfg_o0);
    auto ogreCfg_o0 = POM::FindObject(obj, "ogreCfg");
    _Deserialize(&(p->ogreCfg), ogreCfg_o0);
    auto resources_a0 = POM::FindObject(obj, "resources");
    for(auto& resources_e0 : resources_a0) {
        if (resources_e0.value.IsArray()) {
            std::list<std::string> resources_c1;
            auto resources_a1 = resources_e0.value.GetArray();
            for(auto& resources_e1 : resources_a1) {
                resources_c1.push_back(resources_e1.GetString());
            }
            p->resources.insert({ resources_e0.name.GetString(), resources_c1 });
        } else {
            auto resources_t1 = resources_e0.value.GetString();
            std::list<std::string> resources_c1;
            resources_c1.push_back(resources_t1);
            p->resources.insert({ resources_e0.name.GetString(), resources_c1 });
        }
    }
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Serialize(nsTornadoEngine::TOgreCfg* p, Jobj& obj)
{
    PUM::Push(obj, "release", p->release);
    PUM::Push(obj, "debug", p->debug);
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Deserialize(nsTornadoEngine::TOgreCfg* p, const Jobj& obj)
{
    POM::PopStr(obj, "release", p->release);
    POM::PopStr(obj, "debug", p->debug);
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Serialize(nsTornadoEngine::TPrefabContent* p, Jobj& obj)
{
    _Serialize((nsTornadoEngine::TResourceContent*)p, obj);// Inheritances
    auto header_o = PUM::AddObject(obj, "header");
    _Serialize(&(p->header), header_o);
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Deserialize(nsTornadoEngine::TPrefabContent* p, const Jobj& obj)
{
    _Deserialize((nsTornadoEngine::TResourceContent*)p, obj);// Inheritances
    auto header_o0 = POM::FindObject(obj, "header");
    _Deserialize(&(p->header), header_o0);
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Serialize(nsTornadoEngine::TPrefabContentMap* p, Jobj& obj)
{
    _Serialize((nsTornadoEngine::TResourceContentMap*)p, obj);// Inheritances
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Deserialize(nsTornadoEngine::TPrefabContentMap* p, const Jobj& obj)
{
    _Deserialize((nsTornadoEngine::TResourceContentMap*)p, obj);// Inheritances
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Serialize(nsTornadoEngine::TPrefabHeader* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Deserialize(nsTornadoEngine::TPrefabHeader* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Serialize(nsTornadoEngine::TProjectConfig* p, Jobj& obj)
{
    auto info_o = PUM::AddObject(obj, "info");
    _Serialize(&(p->info), info_o);
    PUM::Push(obj, "binaryFilePath", p->binaryFilePath);
    PUM::Push(obj, "conveyorFilePath", p->conveyorFilePath);
    PUM::Push(obj, "resourcesFilePath", p->resourcesFilePath);
    auto generatorConfig_o = PUM::AddObject(obj, "generatorConfig");
    _Serialize(&(p->generatorConfig), generatorConfig_o);
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Deserialize(nsTornadoEngine::TProjectConfig* p, const Jobj& obj)
{
    auto info_o0 = POM::FindObject(obj, "info");
    _Deserialize(&(p->info), info_o0);
    POM::PopStr(obj, "binaryFilePath", p->binaryFilePath);
    POM::PopStr(obj, "conveyorFilePath", p->conveyorFilePath);
    POM::PopStr(obj, "resourcesFilePath", p->resourcesFilePath);
    auto generatorConfig_o0 = POM::FindObject(obj, "generatorConfig");
    _Deserialize(&(p->generatorConfig), generatorConfig_o0);
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Serialize(nsTornadoEngine::TProjectInfo* p, Jobj& obj)
{
    PUM::Push(obj, "company", p->company);
    PUM::Push(obj, "appName", p->appName);
    PUM::Push(obj, "license", p->license);
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Deserialize(nsTornadoEngine::TProjectInfo* p, const Jobj& obj)
{
    POM::PopStr(obj, "company", p->company);
    POM::PopStr(obj, "appName", p->appName);
    POM::PopStr(obj, "license", p->license);
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Serialize(nsTornadoEngine::TResourceContent* p, Jobj& obj)
{
    PUM::Value entities_a0(rapidjson::kArrayType);
    for(auto& entities_e0 : p->entities) {
        PUM::Value entities_a1(rapidjson::kObjectType);
        auto entities_c1 = entities_a1.GetObject();
        _Serialize(&entities_e0, entities_c1);
        PUM::PushBack(entities_a0, entities_a1);
    }
    PUM::Push(obj, "entities", entities_a0);
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Deserialize(nsTornadoEngine::TResourceContent* p, const Jobj& obj)
{
    auto entities_a0 = POM::FindArray(obj, "entities");
    for(auto& entities_e0 : entities_a0) {
        auto entities_o1 = entities_e0.GetObject();
        nsTornadoEngine::TEntityContent entities_c1;
        _Deserialize(&entities_c1, entities_o1);
        p->entities.push_back(entities_c1);
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
void TTornadoEngineJsonSerializer::_Serialize(nsTornadoEngine::TSceneContent* p, Jobj& obj)
{
    _Serialize((nsTornadoEngine::TResourceContent*)p, obj);// Inheritances
    auto header_o = PUM::AddObject(obj, "header");
    _Serialize(&(p->header), header_o);
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Deserialize(nsTornadoEngine::TSceneContent* p, const Jobj& obj)
{
    _Deserialize((nsTornadoEngine::TResourceContent*)p, obj);// Inheritances
    auto header_o0 = POM::FindObject(obj, "header");
    _Deserialize(&(p->header), header_o0);
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Serialize(nsTornadoEngine::TSceneContentMap* p, Jobj& obj)
{
    _Serialize((nsTornadoEngine::TResourceContentMap*)p, obj);// Inheritances
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Deserialize(nsTornadoEngine::TSceneContentMap* p, const Jobj& obj)
{
    _Deserialize((nsTornadoEngine::TResourceContentMap*)p, obj);// Inheritances
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Serialize(nsTornadoEngine::TSceneHeader* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TTornadoEngineJsonSerializer::_Deserialize(nsTornadoEngine::TSceneHeader* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
