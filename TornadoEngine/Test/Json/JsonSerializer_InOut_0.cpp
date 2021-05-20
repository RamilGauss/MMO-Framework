/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.1.0, build 50, info Json, Binary, EntMng, Reflection
// File has been generated at 2021_05_20 22:47:24.098
	
#include "JsonSerializer_InOut_0.h"
#include "JsonPopMaster.h"
#include "JsonPushMaster.h"
#include "SingletonManager.h"
#include "TypeIdentifier.h"

using namespace nsJson_InOut_0;

using POM = TJsonPopMaster;
using PUM = TJsonPushMaster;

std::map<std::string, TJsonSerializer::TypeFunc> TJsonSerializer::mTypeNameFuncsMap;
std::vector<TJsonSerializer::TypeFunc> TJsonSerializer::mTypeFuncVector;

void TJsonSerializer::Init()
{
    static bool isNeedInit = true;
    if ( !isNeedInit ) {
        return;
    }
    isNeedInit = false;
    
    auto globalTypeIdentifier = SingletonManager()->Get<TTypeIdentifier<>>();
    TypeFunc _nsInOut_ATypeFunc;
    _nsInOut_ATypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsInOut::A>((nsInOut::A*) p, str);
    };
    _nsInOut_ATypeFunc.deserializeFunc = [] (void*& p, const std::string& str, std::string& err) {
        return Deserialize<nsInOut::A>((nsInOut::A*&) p, str, err);
    };
    _nsInOut_ATypeFunc.fillFunc = [] (void* p, const std::string& str, std::string& err) {
        return Fill<nsInOut::A>((nsInOut::A*) p, str, err);
    };
    _nsInOut_ATypeFunc.typeIdentifier = globalTypeIdentifier->type<nsInOut::A>();
    mTypeNameFuncsMap.insert({"nsInOut::A", _nsInOut_ATypeFunc });
    
    
    int max = 0;
    for (auto& vt : mTypeNameFuncsMap) {
        max = std::max(vt.second.typeIdentifier, max);
    }
    
    mTypeFuncVector.resize(max + 1);
    for (auto& vt : mTypeNameFuncsMap) {
        mTypeFuncVector[vt.second.typeIdentifier] = vt.second;
    }
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::Serialize(void* p, std::string& str, const std::string& typeName)
{
    Init();
    mTypeNameFuncsMap[typeName].serializeFunc(p, str);
}
//---------------------------------------------------------------------------------------
bool TJsonSerializer::Deserialize(void*& p, const std::string& str, const std::string& typeName, std::string& err)
{
    Init();
    return mTypeNameFuncsMap[typeName].deserializeFunc(p, str, err);
}
//---------------------------------------------------------------------------------------
bool TJsonSerializer::Fill(void* p, const std::string& str, const std::string& typeName, std::string& err)
{
    Init();
    return mTypeNameFuncsMap[typeName].fillFunc(p, str, err);
}
void TJsonSerializer::Serialize(void* p, std::string& str, int typeIdentifier)
{
    Init();
    mTypeFuncVector[typeIdentifier].serializeFunc(p, str);
}
//---------------------------------------------------------------------------------------
bool TJsonSerializer::Deserialize(void*& p, const std::string& str, int typeIdentifier, std::string& err)
{
    Init();
    return mTypeFuncVector[typeIdentifier].deserializeFunc(p, str, err);
}
//---------------------------------------------------------------------------------------
bool TJsonSerializer::Fill(void* p, const std::string& str, int typeIdentifier, std::string& err)
{
    Init();
    return mTypeFuncVector[typeIdentifier].fillFunc(p, str, err);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize(nsInOut::A* p, Jobj& obj)
{
    PUM::Push(obj, "x", p->x);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize(nsInOut::A* p, const Jobj& obj)
{
    POM::PopNum(obj, "x", p->x);
}
//---------------------------------------------------------------------------------------
