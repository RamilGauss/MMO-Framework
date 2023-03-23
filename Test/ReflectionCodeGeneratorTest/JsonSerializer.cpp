/*
	ReflectionCodeGeneratorTest
*/
// ReflectionCodeGenerator version 2.4.0, build 58 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, TypeInformation]
// File has been generated at 2023_03_23 12:54:57.443
	
#include "JsonSerializer.h"
#include "JsonPopMaster.h"
#include "JsonPushMaster.h"
#include "SingletonManager.h"
#include "RunTimeTypeIndex.h"

using namespace nsTest;

using POM = TJsonPopMaster;
using PUM = TJsonPushMaster;

std::vector<TJsonSerializer::TypeFunc> TJsonSerializer::mTypeFuncVector;

void TJsonSerializer::Init()
{
    static bool isNeedInit = true;
    if ( !isNeedInit ) {
        return;
    }
    isNeedInit = false;
    
    auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();
    
    std::map<int, TypeFunc> m;
    
    TypeFunc _nsSimpleComponents_TNameComponentTypeFunc;
    _nsSimpleComponents_TNameComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsSimpleComponents::TNameComponent>((nsSimpleComponents::TNameComponent*) p, str);
    };
    _nsSimpleComponents_TNameComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsSimpleComponents::TNameComponent>((nsSimpleComponents::TNameComponent*) p, str, err);
    };
    
    auto rtti__nsSimpleComponents_TNameComponentTypeFunc = globalTypeIdentifier->Type<nsSimpleComponents::TNameComponent>();
    
    m.insert({ rtti__nsSimpleComponents_TNameComponentTypeFunc, _nsSimpleComponents_TNameComponentTypeFunc });
    
    TypeFunc _nsSimpleComponents_TSimpleComponentTypeFunc;
    _nsSimpleComponents_TSimpleComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsSimpleComponents::TSimpleComponent>((nsSimpleComponents::TSimpleComponent*) p, str);
    };
    _nsSimpleComponents_TSimpleComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsSimpleComponents::TSimpleComponent>((nsSimpleComponents::TSimpleComponent*) p, str, err);
    };
    
    auto rtti__nsSimpleComponents_TSimpleComponentTypeFunc = globalTypeIdentifier->Type<nsSimpleComponents::TSimpleComponent>();
    
    m.insert({ rtti__nsSimpleComponents_TSimpleComponentTypeFunc, _nsSimpleComponents_TSimpleComponentTypeFunc });
    
    TypeFunc _nsSimpleComponents_TSizeComponentTypeFunc;
    _nsSimpleComponents_TSizeComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsSimpleComponents::TSizeComponent>((nsSimpleComponents::TSizeComponent*) p, str);
    };
    _nsSimpleComponents_TSizeComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsSimpleComponents::TSizeComponent>((nsSimpleComponents::TSizeComponent*) p, str, err);
    };
    
    auto rtti__nsSimpleComponents_TSizeComponentTypeFunc = globalTypeIdentifier->Type<nsSimpleComponents::TSizeComponent>();
    
    m.insert({ rtti__nsSimpleComponents_TSizeComponentTypeFunc, _nsSimpleComponents_TSizeComponentTypeFunc });
    
    TypeFunc _nsSimpleComponents_TValueComponentTypeFunc;
    _nsSimpleComponents_TValueComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsSimpleComponents::TValueComponent>((nsSimpleComponents::TValueComponent*) p, str);
    };
    _nsSimpleComponents_TValueComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsSimpleComponents::TValueComponent>((nsSimpleComponents::TValueComponent*) p, str, err);
    };
    
    auto rtti__nsSimpleComponents_TValueComponentTypeFunc = globalTypeIdentifier->Type<nsSimpleComponents::TValueComponent>();
    
    m.insert({ rtti__nsSimpleComponents_TValueComponentTypeFunc, _nsSimpleComponents_TValueComponentTypeFunc });
    
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
void TJsonSerializer::Serialize(void* p, std::string& str, int rtti)
{
    Init();
    mTypeFuncVector[rtti].serializeFunc(p, str);
}
//---------------------------------------------------------------------------------------
bool TJsonSerializer::Deserialize(void* p, const std::string& str, int rtti, std::string& err)
{
    Init();
    return mTypeFuncVector[rtti].deserializeFunc(p, str, err);
}
//---------------------------------------------------------------------------------------
bool TJsonSerializer::Has(int rtti)
{
    Init();
    if (rtti < 0 || rtti >= mTypeFuncVector.size()) {
        return false;
    }
    return mTypeFuncVector[rtti].serializeFunc != nullptr;
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize(nsSimpleComponents::TNameComponent* p, Jobj& obj)
{
    PUM::Push(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize(nsSimpleComponents::TNameComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize(nsSimpleComponents::TSimpleComponent* p, Jobj& obj)
{
    PUM::Push(obj, "x", p->x);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize(nsSimpleComponents::TSimpleComponent* p, const Jobj& obj)
{
    POM::PopNum(obj, "x", p->x);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize(nsSimpleComponents::TSizeComponent* p, Jobj& obj)
{
    PUM::Push(obj, "x", p->x);
    PUM::Push(obj, "y", p->y);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize(nsSimpleComponents::TSizeComponent* p, const Jobj& obj)
{
    POM::PopNum(obj, "x", p->x);
    POM::PopNum(obj, "y", p->y);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize(nsSimpleComponents::TValueComponent* p, Jobj& obj)
{
    PUM::Push(obj, "x", p->x);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize(nsSimpleComponents::TValueComponent* p, const Jobj& obj)
{
    POM::PopNum(obj, "x", p->x);
}
//---------------------------------------------------------------------------------------
