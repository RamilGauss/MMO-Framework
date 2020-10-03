/*
	ReflectionCodeGenerator
*/
// File has been generated by ReflectionCodeGenerator version 1.18 build 46, at 2020_10_02 12:49:13.354
	
#include "ShareDevJsonSerializer.h"
#include "JsonPopMaster.h"
#include "JsonPushMaster.h"


using POM = TJsonPopMaster;
using PUM = TJsonPushMaster;

std::map<std::string, TShareDevJsonSerializer::TypeFunc> TShareDevJsonSerializer::mTypeNameFuncsMap;
std::list<std::string> TShareDevJsonSerializer::mTypeNameList;

void TShareDevJsonSerializer::Init()
{
    static bool isNeedInit = true;
    if ( !isNeedInit ) {
        return;
    }
    isNeedInit = false;
    
    TypeFunc _TBaseResourcesTypeFunc;
    _TBaseResourcesTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<TBaseResources>((TBaseResources*) p, str);
    };
    _TBaseResourcesTypeFunc.deserializeFunc = [] (void*& p, const std::string& str, std::string& err) {
        return Deserialize<TBaseResources>((TBaseResources*&) p, str, err);
    };
    _TBaseResourcesTypeFunc.fillFunc = [] (void* p, const std::string& str, std::string& err) {
        return Fill<TBaseResources>((TBaseResources*) p, str, err);
    };
    mTypeNameFuncsMap.insert({"TBaseResources", _TBaseResourcesTypeFunc });
    mTypeNameList.push_back("TBaseResources");
    
    TypeFunc _TFrameworkResourcesTypeFunc;
    _TFrameworkResourcesTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<TFrameworkResources>((TFrameworkResources*) p, str);
    };
    _TFrameworkResourcesTypeFunc.deserializeFunc = [] (void*& p, const std::string& str, std::string& err) {
        return Deserialize<TFrameworkResources>((TFrameworkResources*&) p, str, err);
    };
    _TFrameworkResourcesTypeFunc.fillFunc = [] (void* p, const std::string& str, std::string& err) {
        return Fill<TFrameworkResources>((TFrameworkResources*) p, str, err);
    };
    mTypeNameFuncsMap.insert({"TFrameworkResources", _TFrameworkResourcesTypeFunc });
    mTypeNameList.push_back("TFrameworkResources");
    
    TypeFunc _TGUIResourcesTypeFunc;
    _TGUIResourcesTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<TGUIResources>((TGUIResources*) p, str);
    };
    _TGUIResourcesTypeFunc.deserializeFunc = [] (void*& p, const std::string& str, std::string& err) {
        return Deserialize<TGUIResources>((TGUIResources*&) p, str, err);
    };
    _TGUIResourcesTypeFunc.fillFunc = [] (void* p, const std::string& str, std::string& err) {
        return Fill<TGUIResources>((TGUIResources*) p, str, err);
    };
    mTypeNameFuncsMap.insert({"TGUIResources", _TGUIResourcesTypeFunc });
    mTypeNameList.push_back("TGUIResources");
    
    TypeFunc _TGameEngineResourcesTypeFunc;
    _TGameEngineResourcesTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<TGameEngineResources>((TGameEngineResources*) p, str);
    };
    _TGameEngineResourcesTypeFunc.deserializeFunc = [] (void*& p, const std::string& str, std::string& err) {
        return Deserialize<TGameEngineResources>((TGameEngineResources*&) p, str, err);
    };
    _TGameEngineResourcesTypeFunc.fillFunc = [] (void* p, const std::string& str, std::string& err) {
        return Fill<TGameEngineResources>((TGameEngineResources*) p, str, err);
    };
    mTypeNameFuncsMap.insert({"TGameEngineResources", _TGameEngineResourcesTypeFunc });
    mTypeNameList.push_back("TGameEngineResources");
    
    TypeFunc _TGameResourcesTypeFunc;
    _TGameResourcesTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<TGameResources>((TGameResources*) p, str);
    };
    _TGameResourcesTypeFunc.deserializeFunc = [] (void*& p, const std::string& str, std::string& err) {
        return Deserialize<TGameResources>((TGameResources*&) p, str, err);
    };
    _TGameResourcesTypeFunc.fillFunc = [] (void* p, const std::string& str, std::string& err) {
        return Fill<TGameResources>((TGameResources*) p, str, err);
    };
    mTypeNameFuncsMap.insert({"TGameResources", _TGameResourcesTypeFunc });
    mTypeNameList.push_back("TGameResources");
    
    TypeFunc _TGraphicEngineResourcesTypeFunc;
    _TGraphicEngineResourcesTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<TGraphicEngineResources>((TGraphicEngineResources*) p, str);
    };
    _TGraphicEngineResourcesTypeFunc.deserializeFunc = [] (void*& p, const std::string& str, std::string& err) {
        return Deserialize<TGraphicEngineResources>((TGraphicEngineResources*&) p, str, err);
    };
    _TGraphicEngineResourcesTypeFunc.fillFunc = [] (void* p, const std::string& str, std::string& err) {
        return Fill<TGraphicEngineResources>((TGraphicEngineResources*) p, str, err);
    };
    mTypeNameFuncsMap.insert({"TGraphicEngineResources", _TGraphicEngineResourcesTypeFunc });
    mTypeNameList.push_back("TGraphicEngineResources");
    
    TypeFunc _TOgreCfgTypeFunc;
    _TOgreCfgTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<TOgreCfg>((TOgreCfg*) p, str);
    };
    _TOgreCfgTypeFunc.deserializeFunc = [] (void*& p, const std::string& str, std::string& err) {
        return Deserialize<TOgreCfg>((TOgreCfg*&) p, str, err);
    };
    _TOgreCfgTypeFunc.fillFunc = [] (void* p, const std::string& str, std::string& err) {
        return Fill<TOgreCfg>((TOgreCfg*) p, str, err);
    };
    mTypeNameFuncsMap.insert({"TOgreCfg", _TOgreCfgTypeFunc });
    mTypeNameList.push_back("TOgreCfg");
    
    TypeFunc _nsMathTools_TMatrix16TypeFunc;
    _nsMathTools_TMatrix16TypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsMathTools::TMatrix16>((nsMathTools::TMatrix16*) p, str);
    };
    _nsMathTools_TMatrix16TypeFunc.deserializeFunc = [] (void*& p, const std::string& str, std::string& err) {
        return Deserialize<nsMathTools::TMatrix16>((nsMathTools::TMatrix16*&) p, str, err);
    };
    _nsMathTools_TMatrix16TypeFunc.fillFunc = [] (void* p, const std::string& str, std::string& err) {
        return Fill<nsMathTools::TMatrix16>((nsMathTools::TMatrix16*) p, str, err);
    };
    mTypeNameFuncsMap.insert({"nsMathTools::TMatrix16", _nsMathTools_TMatrix16TypeFunc });
    mTypeNameList.push_back("nsMathTools::TMatrix16");
    
    TypeFunc _nsMathTools_TMatrix9TypeFunc;
    _nsMathTools_TMatrix9TypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsMathTools::TMatrix9>((nsMathTools::TMatrix9*) p, str);
    };
    _nsMathTools_TMatrix9TypeFunc.deserializeFunc = [] (void*& p, const std::string& str, std::string& err) {
        return Deserialize<nsMathTools::TMatrix9>((nsMathTools::TMatrix9*&) p, str, err);
    };
    _nsMathTools_TMatrix9TypeFunc.fillFunc = [] (void* p, const std::string& str, std::string& err) {
        return Fill<nsMathTools::TMatrix9>((nsMathTools::TMatrix9*) p, str, err);
    };
    mTypeNameFuncsMap.insert({"nsMathTools::TMatrix9", _nsMathTools_TMatrix9TypeFunc });
    mTypeNameList.push_back("nsMathTools::TMatrix9");
    
    TypeFunc _nsMathTools_TOrientationTypeFunc;
    _nsMathTools_TOrientationTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsMathTools::TOrientation>((nsMathTools::TOrientation*) p, str);
    };
    _nsMathTools_TOrientationTypeFunc.deserializeFunc = [] (void*& p, const std::string& str, std::string& err) {
        return Deserialize<nsMathTools::TOrientation>((nsMathTools::TOrientation*&) p, str, err);
    };
    _nsMathTools_TOrientationTypeFunc.fillFunc = [] (void* p, const std::string& str, std::string& err) {
        return Fill<nsMathTools::TOrientation>((nsMathTools::TOrientation*) p, str, err);
    };
    mTypeNameFuncsMap.insert({"nsMathTools::TOrientation", _nsMathTools_TOrientationTypeFunc });
    mTypeNameList.push_back("nsMathTools::TOrientation");
    
    TypeFunc _nsMathTools_TPlaneTypeFunc;
    _nsMathTools_TPlaneTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsMathTools::TPlane>((nsMathTools::TPlane*) p, str);
    };
    _nsMathTools_TPlaneTypeFunc.deserializeFunc = [] (void*& p, const std::string& str, std::string& err) {
        return Deserialize<nsMathTools::TPlane>((nsMathTools::TPlane*&) p, str, err);
    };
    _nsMathTools_TPlaneTypeFunc.fillFunc = [] (void* p, const std::string& str, std::string& err) {
        return Fill<nsMathTools::TPlane>((nsMathTools::TPlane*) p, str, err);
    };
    mTypeNameFuncsMap.insert({"nsMathTools::TPlane", _nsMathTools_TPlaneTypeFunc });
    mTypeNameList.push_back("nsMathTools::TPlane");
    
    TypeFunc _nsMathTools_TPoint2TypeFunc;
    _nsMathTools_TPoint2TypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsMathTools::TPoint2>((nsMathTools::TPoint2*) p, str);
    };
    _nsMathTools_TPoint2TypeFunc.deserializeFunc = [] (void*& p, const std::string& str, std::string& err) {
        return Deserialize<nsMathTools::TPoint2>((nsMathTools::TPoint2*&) p, str, err);
    };
    _nsMathTools_TPoint2TypeFunc.fillFunc = [] (void* p, const std::string& str, std::string& err) {
        return Fill<nsMathTools::TPoint2>((nsMathTools::TPoint2*) p, str, err);
    };
    mTypeNameFuncsMap.insert({"nsMathTools::TPoint2", _nsMathTools_TPoint2TypeFunc });
    mTypeNameList.push_back("nsMathTools::TPoint2");
    
    TypeFunc _nsMathTools_TQuaternionTypeFunc;
    _nsMathTools_TQuaternionTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsMathTools::TQuaternion>((nsMathTools::TQuaternion*) p, str);
    };
    _nsMathTools_TQuaternionTypeFunc.deserializeFunc = [] (void*& p, const std::string& str, std::string& err) {
        return Deserialize<nsMathTools::TQuaternion>((nsMathTools::TQuaternion*&) p, str, err);
    };
    _nsMathTools_TQuaternionTypeFunc.fillFunc = [] (void* p, const std::string& str, std::string& err) {
        return Fill<nsMathTools::TQuaternion>((nsMathTools::TQuaternion*) p, str, err);
    };
    mTypeNameFuncsMap.insert({"nsMathTools::TQuaternion", _nsMathTools_TQuaternionTypeFunc });
    mTypeNameList.push_back("nsMathTools::TQuaternion");
    
    TypeFunc _nsMathTools_TVector2TypeFunc;
    _nsMathTools_TVector2TypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsMathTools::TVector2>((nsMathTools::TVector2*) p, str);
    };
    _nsMathTools_TVector2TypeFunc.deserializeFunc = [] (void*& p, const std::string& str, std::string& err) {
        return Deserialize<nsMathTools::TVector2>((nsMathTools::TVector2*&) p, str, err);
    };
    _nsMathTools_TVector2TypeFunc.fillFunc = [] (void* p, const std::string& str, std::string& err) {
        return Fill<nsMathTools::TVector2>((nsMathTools::TVector2*) p, str, err);
    };
    mTypeNameFuncsMap.insert({"nsMathTools::TVector2", _nsMathTools_TVector2TypeFunc });
    mTypeNameList.push_back("nsMathTools::TVector2");
    
    TypeFunc _nsMathTools_TVector3TypeFunc;
    _nsMathTools_TVector3TypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsMathTools::TVector3>((nsMathTools::TVector3*) p, str);
    };
    _nsMathTools_TVector3TypeFunc.deserializeFunc = [] (void*& p, const std::string& str, std::string& err) {
        return Deserialize<nsMathTools::TVector3>((nsMathTools::TVector3*&) p, str, err);
    };
    _nsMathTools_TVector3TypeFunc.fillFunc = [] (void* p, const std::string& str, std::string& err) {
        return Fill<nsMathTools::TVector3>((nsMathTools::TVector3*) p, str, err);
    };
    mTypeNameFuncsMap.insert({"nsMathTools::TVector3", _nsMathTools_TVector3TypeFunc });
    mTypeNameList.push_back("nsMathTools::TVector3");
    
    TypeFunc _nsMathTools_TVector4TypeFunc;
    _nsMathTools_TVector4TypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsMathTools::TVector4>((nsMathTools::TVector4*) p, str);
    };
    _nsMathTools_TVector4TypeFunc.deserializeFunc = [] (void*& p, const std::string& str, std::string& err) {
        return Deserialize<nsMathTools::TVector4>((nsMathTools::TVector4*&) p, str, err);
    };
    _nsMathTools_TVector4TypeFunc.fillFunc = [] (void* p, const std::string& str, std::string& err) {
        return Fill<nsMathTools::TVector4>((nsMathTools::TVector4*) p, str, err);
    };
    mTypeNameFuncsMap.insert({"nsMathTools::TVector4", _nsMathTools_TVector4TypeFunc });
    mTypeNameList.push_back("nsMathTools::TVector4");
    
}
//---------------------------------------------------------------------------------------
const std::list<std::string>& TShareDevJsonSerializer::GetTypeNameList()
{
    Init();
    return mTypeNameList;
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::Serialize(void* p, std::string& str, const std::string& typeName)
{
    Init();
    mTypeNameFuncsMap[typeName].serializeFunc(p, str);
}
//---------------------------------------------------------------------------------------
bool TShareDevJsonSerializer::Deserialize(void*& p, const std::string& str, const std::string& typeName, std::string& err)
{
    Init();
    return mTypeNameFuncsMap[typeName].deserializeFunc(p, str, err);
}
//---------------------------------------------------------------------------------------
bool TShareDevJsonSerializer::Fill(void* p, const std::string& str, const std::string& typeName, std::string& err)
{
    Init();
    return mTypeNameFuncsMap[typeName].fillFunc(p, str, err);
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Serialize( TBaseResources* p, Jobj& obj )
{
    PUM::Push( obj, "name", p->name );
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Deserialize( TBaseResources* p, const Jobj& obj )
{
    POM::PopStr( obj, "name", p->name );
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Serialize( TFrameworkResources* p, Jobj& obj )
{
    auto gameEngine_o = PUM::AddObject( obj, "gameEngine");
    _Serialize( &(p->gameEngine), gameEngine_o );
    auto graphicEngine_o = PUM::AddObject( obj, "graphicEngine");
    _Serialize( &(p->graphicEngine), graphicEngine_o );
    auto gui_o = PUM::AddObject( obj, "gui");
    _Serialize( &(p->gui), gui_o );
    auto game_o = PUM::AddObject( obj, "game");
    _Serialize( &(p->game), game_o );
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Deserialize( TFrameworkResources* p, const Jobj& obj )
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
void TShareDevJsonSerializer::_Serialize( TGUIResources* p, Jobj& obj )
{
    _Serialize( (TBaseResources*)p, obj);// Inheritances
    auto resources_c0 = PUM::AddObject(obj, "resources");
    for( auto& resources_e0 : p->resources ) {
        PUM::Value resources_a1(rapidjson::kArrayType);
        for( auto& resources_e1 : resources_e0.second ) {
            PUM::PushBack( resources_a1, resources_e1 );
        }
        PUM::Push(resources_c0, PUM::ConvertToString(resources_e0.first).data(), resources_a1);
    }
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Deserialize( TGUIResources* p, const Jobj& obj )
{
    _Deserialize( (TBaseResources*)p, obj);// Inheritances
    auto resources_a0 = POM::FindObject(obj, "resources");
    for( auto& resources_e0 : resources_a0 ) {
        if ( resources_e0.value.IsArray() ) {
            std::list<std::string> resources_c1;
            auto resources_a1 = resources_e0.value.GetArray();
            for( auto& resources_e1 : resources_a1 ) {
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
void TShareDevJsonSerializer::_Serialize( TGameEngineResources* p, Jobj& obj )
{
    _Serialize( (TBaseResources*)p, obj);// Inheritances
    auto resources_c0 = PUM::AddObject(obj, "resources");
    for( auto& resources_e0 : p->resources ) {
        PUM::Value resources_a1(rapidjson::kArrayType);
        for( auto& resources_e1 : resources_e0.second ) {
            PUM::PushBack( resources_a1, resources_e1 );
        }
        PUM::Push(resources_c0, PUM::ConvertToString(resources_e0.first).data(), resources_a1);
    }
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Deserialize( TGameEngineResources* p, const Jobj& obj )
{
    _Deserialize( (TBaseResources*)p, obj);// Inheritances
    auto resources_a0 = POM::FindObject(obj, "resources");
    for( auto& resources_e0 : resources_a0 ) {
        if ( resources_e0.value.IsArray() ) {
            std::list<std::string> resources_c1;
            auto resources_a1 = resources_e0.value.GetArray();
            for( auto& resources_e1 : resources_a1 ) {
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
void TShareDevJsonSerializer::_Serialize( TGameResources* p, Jobj& obj )
{
    _Serialize( (TBaseResources*)p, obj);// Inheritances
    auto resources_c0 = PUM::AddObject(obj, "resources");
    for( auto& resources_e0 : p->resources ) {
        PUM::Value resources_a1(rapidjson::kArrayType);
        for( auto& resources_e1 : resources_e0.second ) {
            PUM::PushBack( resources_a1, resources_e1 );
        }
        PUM::Push(resources_c0, PUM::ConvertToString(resources_e0.first).data(), resources_a1);
    }
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Deserialize( TGameResources* p, const Jobj& obj )
{
    _Deserialize( (TBaseResources*)p, obj);// Inheritances
    auto resources_a0 = POM::FindObject(obj, "resources");
    for( auto& resources_e0 : resources_a0 ) {
        if ( resources_e0.value.IsArray() ) {
            std::list<std::string> resources_c1;
            auto resources_a1 = resources_e0.value.GetArray();
            for( auto& resources_e1 : resources_a1 ) {
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
void TShareDevJsonSerializer::_Serialize( TGraphicEngineResources* p, Jobj& obj )
{
    _Serialize( (TBaseResources*)p, obj);// Inheritances
    PUM::Push( obj, "terrainPath", p->terrainPath );
    auto pluginsCfg_o = PUM::AddObject( obj, "pluginsCfg");
    _Serialize( &(p->pluginsCfg), pluginsCfg_o );
    auto ogreCfg_o = PUM::AddObject( obj, "ogreCfg");
    _Serialize( &(p->ogreCfg), ogreCfg_o );
    auto resources_c0 = PUM::AddObject(obj, "resources");
    for( auto& resources_e0 : p->resources ) {
        PUM::Value resources_a1(rapidjson::kArrayType);
        for( auto& resources_e1 : resources_e0.second ) {
            PUM::PushBack( resources_a1, resources_e1 );
        }
        PUM::Push(resources_c0, PUM::ConvertToString(resources_e0.first).data(), resources_a1);
    }
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Deserialize( TGraphicEngineResources* p, const Jobj& obj )
{
    _Deserialize( (TBaseResources*)p, obj);// Inheritances
    POM::PopStr( obj, "terrainPath", p->terrainPath );
    auto pluginsCfg_o0 = POM::FindObject(obj, "pluginsCfg");
    _Deserialize(&(p->pluginsCfg), pluginsCfg_o0);
    auto ogreCfg_o0 = POM::FindObject(obj, "ogreCfg");
    _Deserialize(&(p->ogreCfg), ogreCfg_o0);
    auto resources_a0 = POM::FindObject(obj, "resources");
    for( auto& resources_e0 : resources_a0 ) {
        if ( resources_e0.value.IsArray() ) {
            std::list<std::string> resources_c1;
            auto resources_a1 = resources_e0.value.GetArray();
            for( auto& resources_e1 : resources_a1 ) {
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
void TShareDevJsonSerializer::_Serialize( TOgreCfg* p, Jobj& obj )
{
    PUM::Push( obj, "release", p->release );
    PUM::Push( obj, "debug", p->debug );
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Deserialize( TOgreCfg* p, const Jobj& obj )
{
    POM::PopStr( obj, "release", p->release );
    POM::PopStr( obj, "debug", p->debug );
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Serialize( nsMathTools::TMatrix16* p, Jobj& obj )
{
    PUM::Push( obj, "_11", p->_11 );
    PUM::Push( obj, "_12", p->_12 );
    PUM::Push( obj, "_13", p->_13 );
    PUM::Push( obj, "_14", p->_14 );
    PUM::Push( obj, "_21", p->_21 );
    PUM::Push( obj, "_22", p->_22 );
    PUM::Push( obj, "_23", p->_23 );
    PUM::Push( obj, "_24", p->_24 );
    PUM::Push( obj, "_31", p->_31 );
    PUM::Push( obj, "_32", p->_32 );
    PUM::Push( obj, "_33", p->_33 );
    PUM::Push( obj, "_34", p->_34 );
    PUM::Push( obj, "_41", p->_41 );
    PUM::Push( obj, "_42", p->_42 );
    PUM::Push( obj, "_43", p->_43 );
    PUM::Push( obj, "_44", p->_44 );
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Deserialize( nsMathTools::TMatrix16* p, const Jobj& obj )
{
    POM::PopNum( obj, "_11", p->_11 );
    POM::PopNum( obj, "_12", p->_12 );
    POM::PopNum( obj, "_13", p->_13 );
    POM::PopNum( obj, "_14", p->_14 );
    POM::PopNum( obj, "_21", p->_21 );
    POM::PopNum( obj, "_22", p->_22 );
    POM::PopNum( obj, "_23", p->_23 );
    POM::PopNum( obj, "_24", p->_24 );
    POM::PopNum( obj, "_31", p->_31 );
    POM::PopNum( obj, "_32", p->_32 );
    POM::PopNum( obj, "_33", p->_33 );
    POM::PopNum( obj, "_34", p->_34 );
    POM::PopNum( obj, "_41", p->_41 );
    POM::PopNum( obj, "_42", p->_42 );
    POM::PopNum( obj, "_43", p->_43 );
    POM::PopNum( obj, "_44", p->_44 );
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Serialize( nsMathTools::TMatrix9* p, Jobj& obj )
{
    PUM::Push( obj, "_11", p->_11 );
    PUM::Push( obj, "_12", p->_12 );
    PUM::Push( obj, "_13", p->_13 );
    PUM::Push( obj, "_21", p->_21 );
    PUM::Push( obj, "_22", p->_22 );
    PUM::Push( obj, "_23", p->_23 );
    PUM::Push( obj, "_31", p->_31 );
    PUM::Push( obj, "_32", p->_32 );
    PUM::Push( obj, "_33", p->_33 );
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Deserialize( nsMathTools::TMatrix9* p, const Jobj& obj )
{
    POM::PopNum( obj, "_11", p->_11 );
    POM::PopNum( obj, "_12", p->_12 );
    POM::PopNum( obj, "_13", p->_13 );
    POM::PopNum( obj, "_21", p->_21 );
    POM::PopNum( obj, "_22", p->_22 );
    POM::PopNum( obj, "_23", p->_23 );
    POM::PopNum( obj, "_31", p->_31 );
    POM::PopNum( obj, "_32", p->_32 );
    POM::PopNum( obj, "_33", p->_33 );
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Serialize( nsMathTools::TOrientation* p, Jobj& obj )
{
    auto axis_o = PUM::AddObject( obj, "axis");
    _Serialize( &(p->axis), axis_o );
    PUM::Push( obj, "angle", p->angle );
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Deserialize( nsMathTools::TOrientation* p, const Jobj& obj )
{
    auto axis_o0 = POM::FindObject(obj, "axis");
    _Deserialize(&(p->axis), axis_o0);
    POM::PopNum( obj, "angle", p->angle );
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Serialize( nsMathTools::TPlane* p, Jobj& obj )
{
    PUM::Push( obj, "a", p->a );
    PUM::Push( obj, "b", p->b );
    PUM::Push( obj, "c", p->c );
    PUM::Push( obj, "d", p->d );
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Deserialize( nsMathTools::TPlane* p, const Jobj& obj )
{
    POM::PopNum( obj, "a", p->a );
    POM::PopNum( obj, "b", p->b );
    POM::PopNum( obj, "c", p->c );
    POM::PopNum( obj, "d", p->d );
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Serialize( nsMathTools::TPoint2* p, Jobj& obj )
{
    PUM::Push( obj, "x", p->x );
    PUM::Push( obj, "y", p->y );
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Deserialize( nsMathTools::TPoint2* p, const Jobj& obj )
{
    POM::PopNum( obj, "x", p->x );
    POM::PopNum( obj, "y", p->y );
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Serialize( nsMathTools::TQuaternion* p, Jobj& obj )
{
    PUM::Push( obj, "x", p->x );
    PUM::Push( obj, "y", p->y );
    PUM::Push( obj, "z", p->z );
    PUM::Push( obj, "w", p->w );
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Deserialize( nsMathTools::TQuaternion* p, const Jobj& obj )
{
    POM::PopNum( obj, "x", p->x );
    POM::PopNum( obj, "y", p->y );
    POM::PopNum( obj, "z", p->z );
    POM::PopNum( obj, "w", p->w );
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Serialize( nsMathTools::TVector2* p, Jobj& obj )
{
    PUM::Push( obj, "x", p->x );
    PUM::Push( obj, "y", p->y );
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Deserialize( nsMathTools::TVector2* p, const Jobj& obj )
{
    POM::PopNum( obj, "x", p->x );
    POM::PopNum( obj, "y", p->y );
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Serialize( nsMathTools::TVector3* p, Jobj& obj )
{
    PUM::Push( obj, "x", p->x );
    PUM::Push( obj, "y", p->y );
    PUM::Push( obj, "z", p->z );
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Deserialize( nsMathTools::TVector3* p, const Jobj& obj )
{
    POM::PopNum( obj, "x", p->x );
    POM::PopNum( obj, "y", p->y );
    POM::PopNum( obj, "z", p->z );
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Serialize( nsMathTools::TVector4* p, Jobj& obj )
{
    PUM::Push( obj, "x", p->x );
    PUM::Push( obj, "y", p->y );
    PUM::Push( obj, "z", p->z );
    PUM::Push( obj, "w", p->w );
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Deserialize( nsMathTools::TVector4* p, const Jobj& obj )
{
    POM::PopNum( obj, "x", p->x );
    POM::PopNum( obj, "y", p->y );
    POM::PopNum( obj, "z", p->z );
    POM::PopNum( obj, "w", p->w );
}
//---------------------------------------------------------------------------------------