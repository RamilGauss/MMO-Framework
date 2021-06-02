/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.2.1, build 52, info Json, Binary, MyGUI, EntityManager, Reflection, TypeInformation
// File has been generated at 2021_06_02 07:21:45.056
	
#include "ShareDevJsonSerializer.h"
#include "JsonPopMaster.h"
#include "JsonPushMaster.h"
#include "SingletonManager.h"
#include "RunTimeTypeIndex.h"

using namespace nsShareDev;

using POM = TJsonPopMaster;
using PUM = TJsonPushMaster;

std::vector<TShareDevJsonSerializer::TypeFunc> TShareDevJsonSerializer::mTypeFuncVector;

void TShareDevJsonSerializer::Init()
{
    static bool isNeedInit = true;
    if ( !isNeedInit ) {
        return;
    }
    isNeedInit = false;
    
    auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();
    
    std::map<int, TypeFunc> m;
    
    TypeFunc _TBaseResourcesTypeFunc;
    _TBaseResourcesTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<TBaseResources>((TBaseResources*) p, str);
    };
    _TBaseResourcesTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<TBaseResources>((TBaseResources*) p, str, err);
    };
    
    auto rtti__TBaseResourcesTypeFunc = globalTypeIdentifier->type<TBaseResources>();
    
    m.insert({ rtti__TBaseResourcesTypeFunc, _TBaseResourcesTypeFunc });
    
    TypeFunc _TFrameworkResourcesTypeFunc;
    _TFrameworkResourcesTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<TFrameworkResources>((TFrameworkResources*) p, str);
    };
    _TFrameworkResourcesTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<TFrameworkResources>((TFrameworkResources*) p, str, err);
    };
    
    auto rtti__TFrameworkResourcesTypeFunc = globalTypeIdentifier->type<TFrameworkResources>();
    
    m.insert({ rtti__TFrameworkResourcesTypeFunc, _TFrameworkResourcesTypeFunc });
    
    TypeFunc _TGUIResourcesTypeFunc;
    _TGUIResourcesTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<TGUIResources>((TGUIResources*) p, str);
    };
    _TGUIResourcesTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<TGUIResources>((TGUIResources*) p, str, err);
    };
    
    auto rtti__TGUIResourcesTypeFunc = globalTypeIdentifier->type<TGUIResources>();
    
    m.insert({ rtti__TGUIResourcesTypeFunc, _TGUIResourcesTypeFunc });
    
    TypeFunc _TGameEngineResourcesTypeFunc;
    _TGameEngineResourcesTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<TGameEngineResources>((TGameEngineResources*) p, str);
    };
    _TGameEngineResourcesTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<TGameEngineResources>((TGameEngineResources*) p, str, err);
    };
    
    auto rtti__TGameEngineResourcesTypeFunc = globalTypeIdentifier->type<TGameEngineResources>();
    
    m.insert({ rtti__TGameEngineResourcesTypeFunc, _TGameEngineResourcesTypeFunc });
    
    TypeFunc _TGameResourcesTypeFunc;
    _TGameResourcesTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<TGameResources>((TGameResources*) p, str);
    };
    _TGameResourcesTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<TGameResources>((TGameResources*) p, str, err);
    };
    
    auto rtti__TGameResourcesTypeFunc = globalTypeIdentifier->type<TGameResources>();
    
    m.insert({ rtti__TGameResourcesTypeFunc, _TGameResourcesTypeFunc });
    
    TypeFunc _TGraphicEngineResourcesTypeFunc;
    _TGraphicEngineResourcesTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<TGraphicEngineResources>((TGraphicEngineResources*) p, str);
    };
    _TGraphicEngineResourcesTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<TGraphicEngineResources>((TGraphicEngineResources*) p, str, err);
    };
    
    auto rtti__TGraphicEngineResourcesTypeFunc = globalTypeIdentifier->type<TGraphicEngineResources>();
    
    m.insert({ rtti__TGraphicEngineResourcesTypeFunc, _TGraphicEngineResourcesTypeFunc });
    
    TypeFunc _TOgreCfgTypeFunc;
    _TOgreCfgTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<TOgreCfg>((TOgreCfg*) p, str);
    };
    _TOgreCfgTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<TOgreCfg>((TOgreCfg*) p, str, err);
    };
    
    auto rtti__TOgreCfgTypeFunc = globalTypeIdentifier->type<TOgreCfg>();
    
    m.insert({ rtti__TOgreCfgTypeFunc, _TOgreCfgTypeFunc });
    
    TypeFunc _nsMathTools_TMatrix16TypeFunc;
    _nsMathTools_TMatrix16TypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsMathTools::TMatrix16>((nsMathTools::TMatrix16*) p, str);
    };
    _nsMathTools_TMatrix16TypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsMathTools::TMatrix16>((nsMathTools::TMatrix16*) p, str, err);
    };
    
    auto rtti__nsMathTools_TMatrix16TypeFunc = globalTypeIdentifier->type<nsMathTools::TMatrix16>();
    
    m.insert({ rtti__nsMathTools_TMatrix16TypeFunc, _nsMathTools_TMatrix16TypeFunc });
    
    TypeFunc _nsMathTools_TMatrix9TypeFunc;
    _nsMathTools_TMatrix9TypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsMathTools::TMatrix9>((nsMathTools::TMatrix9*) p, str);
    };
    _nsMathTools_TMatrix9TypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsMathTools::TMatrix9>((nsMathTools::TMatrix9*) p, str, err);
    };
    
    auto rtti__nsMathTools_TMatrix9TypeFunc = globalTypeIdentifier->type<nsMathTools::TMatrix9>();
    
    m.insert({ rtti__nsMathTools_TMatrix9TypeFunc, _nsMathTools_TMatrix9TypeFunc });
    
    TypeFunc _nsMathTools_TOrientationTypeFunc;
    _nsMathTools_TOrientationTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsMathTools::TOrientation>((nsMathTools::TOrientation*) p, str);
    };
    _nsMathTools_TOrientationTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsMathTools::TOrientation>((nsMathTools::TOrientation*) p, str, err);
    };
    
    auto rtti__nsMathTools_TOrientationTypeFunc = globalTypeIdentifier->type<nsMathTools::TOrientation>();
    
    m.insert({ rtti__nsMathTools_TOrientationTypeFunc, _nsMathTools_TOrientationTypeFunc });
    
    TypeFunc _nsMathTools_TPlaneTypeFunc;
    _nsMathTools_TPlaneTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsMathTools::TPlane>((nsMathTools::TPlane*) p, str);
    };
    _nsMathTools_TPlaneTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsMathTools::TPlane>((nsMathTools::TPlane*) p, str, err);
    };
    
    auto rtti__nsMathTools_TPlaneTypeFunc = globalTypeIdentifier->type<nsMathTools::TPlane>();
    
    m.insert({ rtti__nsMathTools_TPlaneTypeFunc, _nsMathTools_TPlaneTypeFunc });
    
    TypeFunc _nsMathTools_TPoint2TypeFunc;
    _nsMathTools_TPoint2TypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsMathTools::TPoint2>((nsMathTools::TPoint2*) p, str);
    };
    _nsMathTools_TPoint2TypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsMathTools::TPoint2>((nsMathTools::TPoint2*) p, str, err);
    };
    
    auto rtti__nsMathTools_TPoint2TypeFunc = globalTypeIdentifier->type<nsMathTools::TPoint2>();
    
    m.insert({ rtti__nsMathTools_TPoint2TypeFunc, _nsMathTools_TPoint2TypeFunc });
    
    TypeFunc _nsMathTools_TQuaternionTypeFunc;
    _nsMathTools_TQuaternionTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsMathTools::TQuaternion>((nsMathTools::TQuaternion*) p, str);
    };
    _nsMathTools_TQuaternionTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsMathTools::TQuaternion>((nsMathTools::TQuaternion*) p, str, err);
    };
    
    auto rtti__nsMathTools_TQuaternionTypeFunc = globalTypeIdentifier->type<nsMathTools::TQuaternion>();
    
    m.insert({ rtti__nsMathTools_TQuaternionTypeFunc, _nsMathTools_TQuaternionTypeFunc });
    
    TypeFunc _nsMathTools_TVector2TypeFunc;
    _nsMathTools_TVector2TypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsMathTools::TVector2>((nsMathTools::TVector2*) p, str);
    };
    _nsMathTools_TVector2TypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsMathTools::TVector2>((nsMathTools::TVector2*) p, str, err);
    };
    
    auto rtti__nsMathTools_TVector2TypeFunc = globalTypeIdentifier->type<nsMathTools::TVector2>();
    
    m.insert({ rtti__nsMathTools_TVector2TypeFunc, _nsMathTools_TVector2TypeFunc });
    
    TypeFunc _nsMathTools_TVector3TypeFunc;
    _nsMathTools_TVector3TypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsMathTools::TVector3>((nsMathTools::TVector3*) p, str);
    };
    _nsMathTools_TVector3TypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsMathTools::TVector3>((nsMathTools::TVector3*) p, str, err);
    };
    
    auto rtti__nsMathTools_TVector3TypeFunc = globalTypeIdentifier->type<nsMathTools::TVector3>();
    
    m.insert({ rtti__nsMathTools_TVector3TypeFunc, _nsMathTools_TVector3TypeFunc });
    
    TypeFunc _nsMathTools_TVector4TypeFunc;
    _nsMathTools_TVector4TypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsMathTools::TVector4>((nsMathTools::TVector4*) p, str);
    };
    _nsMathTools_TVector4TypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsMathTools::TVector4>((nsMathTools::TVector4*) p, str, err);
    };
    
    auto rtti__nsMathTools_TVector4TypeFunc = globalTypeIdentifier->type<nsMathTools::TVector4>();
    
    m.insert({ rtti__nsMathTools_TVector4TypeFunc, _nsMathTools_TVector4TypeFunc });
    
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
void TShareDevJsonSerializer::Serialize(void* p, std::string& str, int rtti)
{
    Init();
    mTypeFuncVector[rtti].serializeFunc(p, str);
}
//---------------------------------------------------------------------------------------
bool TShareDevJsonSerializer::Deserialize(void* p, const std::string& str, int rtti, std::string& err)
{
    Init();
    return mTypeFuncVector[rtti].deserializeFunc(p, str, err);
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Serialize(TBaseResources* p, Jobj& obj)
{
    PUM::Push(obj, "name", p->name);
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Deserialize(TBaseResources* p, const Jobj& obj)
{
    POM::PopStr(obj, "name", p->name);
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Serialize(TFrameworkResources* p, Jobj& obj)
{
    auto gameEngine_o = PUM::AddObject(obj, "gameEngine");
    _Serialize(&(p->gameEngine), gameEngine_o);
    auto graphicEngine_o = PUM::AddObject(obj, "graphicEngine");
    _Serialize(&(p->graphicEngine), graphicEngine_o);
    auto gui_o = PUM::AddObject(obj, "gui");
    _Serialize(&(p->gui), gui_o);
    auto game_o = PUM::AddObject(obj, "game");
    _Serialize(&(p->game), game_o);
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Deserialize(TFrameworkResources* p, const Jobj& obj)
{
    auto gameEngine_o0 = POM::FindObject(obj, "gameEngine");
    _Deserialize(&(p->gameEngine), gameEngine_o0);
    auto graphicEngine_o0 = POM::FindObject(obj, "graphicEngine");
    _Deserialize(&(p->graphicEngine), graphicEngine_o0);
    auto gui_o0 = POM::FindObject(obj, "gui");
    _Deserialize(&(p->gui), gui_o0);
    auto game_o0 = POM::FindObject(obj, "game");
    _Deserialize(&(p->game), game_o0);
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Serialize(TGUIResources* p, Jobj& obj)
{
    _Serialize((TBaseResources*)p, obj);// Inheritances
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
void TShareDevJsonSerializer::_Deserialize(TGUIResources* p, const Jobj& obj)
{
    _Deserialize((TBaseResources*)p, obj);// Inheritances
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
void TShareDevJsonSerializer::_Serialize(TGameEngineResources* p, Jobj& obj)
{
    _Serialize((TBaseResources*)p, obj);// Inheritances
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
void TShareDevJsonSerializer::_Deserialize(TGameEngineResources* p, const Jobj& obj)
{
    _Deserialize((TBaseResources*)p, obj);// Inheritances
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
void TShareDevJsonSerializer::_Serialize(TGameResources* p, Jobj& obj)
{
    _Serialize((TBaseResources*)p, obj);// Inheritances
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
void TShareDevJsonSerializer::_Deserialize(TGameResources* p, const Jobj& obj)
{
    _Deserialize((TBaseResources*)p, obj);// Inheritances
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
void TShareDevJsonSerializer::_Serialize(TGraphicEngineResources* p, Jobj& obj)
{
    _Serialize((TBaseResources*)p, obj);// Inheritances
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
void TShareDevJsonSerializer::_Deserialize(TGraphicEngineResources* p, const Jobj& obj)
{
    _Deserialize((TBaseResources*)p, obj);// Inheritances
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
void TShareDevJsonSerializer::_Serialize(TOgreCfg* p, Jobj& obj)
{
    PUM::Push(obj, "release", p->release);
    PUM::Push(obj, "debug", p->debug);
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Deserialize(TOgreCfg* p, const Jobj& obj)
{
    POM::PopStr(obj, "release", p->release);
    POM::PopStr(obj, "debug", p->debug);
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Serialize(nsMathTools::TMatrix16* p, Jobj& obj)
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
void TShareDevJsonSerializer::_Deserialize(nsMathTools::TMatrix16* p, const Jobj& obj)
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
void TShareDevJsonSerializer::_Serialize(nsMathTools::TMatrix9* p, Jobj& obj)
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
void TShareDevJsonSerializer::_Deserialize(nsMathTools::TMatrix9* p, const Jobj& obj)
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
void TShareDevJsonSerializer::_Serialize(nsMathTools::TOrientation* p, Jobj& obj)
{
    auto axis_o = PUM::AddObject(obj, "axis");
    _Serialize(&(p->axis), axis_o);
    PUM::Push(obj, "angle", p->angle);
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Deserialize(nsMathTools::TOrientation* p, const Jobj& obj)
{
    auto axis_o0 = POM::FindObject(obj, "axis");
    _Deserialize(&(p->axis), axis_o0);
    POM::PopNum(obj, "angle", p->angle);
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Serialize(nsMathTools::TPlane* p, Jobj& obj)
{
    PUM::Push(obj, "a", p->a);
    PUM::Push(obj, "b", p->b);
    PUM::Push(obj, "c", p->c);
    PUM::Push(obj, "d", p->d);
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Deserialize(nsMathTools::TPlane* p, const Jobj& obj)
{
    POM::PopNum(obj, "a", p->a);
    POM::PopNum(obj, "b", p->b);
    POM::PopNum(obj, "c", p->c);
    POM::PopNum(obj, "d", p->d);
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Serialize(nsMathTools::TPoint2* p, Jobj& obj)
{
    PUM::Push(obj, "x", p->x);
    PUM::Push(obj, "y", p->y);
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Deserialize(nsMathTools::TPoint2* p, const Jobj& obj)
{
    POM::PopNum(obj, "x", p->x);
    POM::PopNum(obj, "y", p->y);
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Serialize(nsMathTools::TQuaternion* p, Jobj& obj)
{
    PUM::Push(obj, "x", p->x);
    PUM::Push(obj, "y", p->y);
    PUM::Push(obj, "z", p->z);
    PUM::Push(obj, "w", p->w);
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Deserialize(nsMathTools::TQuaternion* p, const Jobj& obj)
{
    POM::PopNum(obj, "x", p->x);
    POM::PopNum(obj, "y", p->y);
    POM::PopNum(obj, "z", p->z);
    POM::PopNum(obj, "w", p->w);
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Serialize(nsMathTools::TVector2* p, Jobj& obj)
{
    PUM::Push(obj, "x", p->x);
    PUM::Push(obj, "y", p->y);
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Deserialize(nsMathTools::TVector2* p, const Jobj& obj)
{
    POM::PopNum(obj, "x", p->x);
    POM::PopNum(obj, "y", p->y);
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Serialize(nsMathTools::TVector3* p, Jobj& obj)
{
    PUM::Push(obj, "x", p->x);
    PUM::Push(obj, "y", p->y);
    PUM::Push(obj, "z", p->z);
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Deserialize(nsMathTools::TVector3* p, const Jobj& obj)
{
    POM::PopNum(obj, "x", p->x);
    POM::PopNum(obj, "y", p->y);
    POM::PopNum(obj, "z", p->z);
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Serialize(nsMathTools::TVector4* p, Jobj& obj)
{
    PUM::Push(obj, "x", p->x);
    PUM::Push(obj, "y", p->y);
    PUM::Push(obj, "z", p->z);
    PUM::Push(obj, "w", p->w);
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Deserialize(nsMathTools::TVector4* p, const Jobj& obj)
{
    POM::PopNum(obj, "x", p->x);
    POM::PopNum(obj, "y", p->y);
    POM::PopNum(obj, "z", p->z);
    POM::PopNum(obj, "w", p->w);
}
//---------------------------------------------------------------------------------------
