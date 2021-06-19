/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.2.1, build 52, info Json, Binary, MyGUI, EntityManager, Reflection, TypeInformation
// File has been generated at 2021_06_19 16:52:03.538
	
#include "GameEngineJsonSerializer.h"
#include "JsonPopMaster.h"
#include "JsonPushMaster.h"
#include "SingletonManager.h"
#include "RunTimeTypeIndex.h"

using namespace nsGameEngine;

using POM = TJsonPopMaster;
using PUM = TJsonPushMaster;

std::vector<TGameEngineJsonSerializer::TypeFunc> TGameEngineJsonSerializer::mTypeFuncVector;

void TGameEngineJsonSerializer::Init()
{
    static bool isNeedInit = true;
    if ( !isNeedInit ) {
        return;
    }
    isNeedInit = false;
    
    auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();
    
    std::map<int, TypeFunc> m;
    
    TypeFunc _TAppConfigTypeFunc;
    _TAppConfigTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<TAppConfig>((TAppConfig*) p, str);
    };
    _TAppConfigTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<TAppConfig>((TAppConfig*) p, str, err);
    };
    
    auto rtti__TAppConfigTypeFunc = globalTypeIdentifier->type<TAppConfig>();
    
    m.insert({ rtti__TAppConfigTypeFunc, _TAppConfigTypeFunc });
    
    TypeFunc _TConveyerConfigTypeFunc;
    _TConveyerConfigTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<TConveyerConfig>((TConveyerConfig*) p, str);
    };
    _TConveyerConfigTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<TConveyerConfig>((TConveyerConfig*) p, str, err);
    };
    
    auto rtti__TConveyerConfigTypeFunc = globalTypeIdentifier->type<TConveyerConfig>();
    
    m.insert({ rtti__TConveyerConfigTypeFunc, _TConveyerConfigTypeFunc });
    
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
void TGameEngineJsonSerializer::Serialize(void* p, std::string& str, int rtti)
{
    Init();
    mTypeFuncVector[rtti].serializeFunc(p, str);
}
//---------------------------------------------------------------------------------------
bool TGameEngineJsonSerializer::Deserialize(void* p, const std::string& str, int rtti, std::string& err)
{
    Init();
    return mTypeFuncVector[rtti].deserializeFunc(p, str, err);
}
//---------------------------------------------------------------------------------------
void TGameEngineJsonSerializer::_Serialize(TAppConfig* p, Jobj& obj)
{
    PUM::Value modules_a0(rapidjson::kArrayType);
    for(size_t modules_i0 = 0 ; modules_i0 < p->modules.size() ; modules_i0++) {
        auto& modules_e0 = p->modules[modules_i0];
        PUM::PushBack(modules_a0, modules_e0);
    }
    PUM::Push(obj, "modules", modules_a0);
}
//---------------------------------------------------------------------------------------
void TGameEngineJsonSerializer::_Deserialize(TAppConfig* p, const Jobj& obj)
{
    if (POM::IsArray(obj, "modules")) {
        auto modules_a0 = POM::FindArray(obj, "modules");
        for(auto& modules_e0 : modules_a0) {
            p->modules.push_back(modules_e0.GetString());
        }
    } else {
        std::string modules_t0;
        POM::PopStr(obj, "modules", modules_t0);
        p->modules.push_back(modules_t0);
    }
}
//---------------------------------------------------------------------------------------
void TGameEngineJsonSerializer::_Serialize(TConveyerConfig* p, Jobj& obj)
{
    auto appList_c0 = PUM::AddObject(obj, "appList");
    for(auto& appList_e0 : p->appList) {
        auto appList_a0 = PUM::AddObject(appList_c0, PUM::ConvertToString(appList_e0.first).data());
        _Serialize(&(appList_e0.second), appList_a0);
    }
}
//---------------------------------------------------------------------------------------
void TGameEngineJsonSerializer::_Deserialize(TConveyerConfig* p, const Jobj& obj)
{
    auto appList_a0 = POM::FindObject(obj, "appList");
    for(auto& appList_e0 : appList_a0) {
        auto appList_o1 = appList_e0.value.GetObject();
        TAppConfig appList_c1;
        _Deserialize(&appList_c1, appList_o1);
        p->appList.insert({ appList_e0.name.GetString(), appList_c1 });
    }
}
//---------------------------------------------------------------------------------------
