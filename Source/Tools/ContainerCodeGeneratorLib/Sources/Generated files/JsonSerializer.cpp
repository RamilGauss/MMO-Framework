/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.4.0, build 58 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, TypeInformation]
// File has been generated at 2022_11_29 22:52:42.165
	
#include "JsonSerializer.h"
#include "JsonPopMaster.h"
#include "JsonPushMaster.h"
#include "SingletonManager.h"
#include "RunTimeTypeIndex.h"

using namespace nsContainerCodeGenerator;

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
    
    TypeFunc _nsContainerCodeGenerator_TCategoryConfigTypeFunc;
    _nsContainerCodeGenerator_TCategoryConfigTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsContainerCodeGenerator::TCategoryConfig>((nsContainerCodeGenerator::TCategoryConfig*) p, str);
    };
    _nsContainerCodeGenerator_TCategoryConfigTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsContainerCodeGenerator::TCategoryConfig>((nsContainerCodeGenerator::TCategoryConfig*) p, str, err);
    };
    
    auto rtti__nsContainerCodeGenerator_TCategoryConfigTypeFunc = globalTypeIdentifier->Type<nsContainerCodeGenerator::TCategoryConfig>();
    
    m.insert({ rtti__nsContainerCodeGenerator_TCategoryConfigTypeFunc, _nsContainerCodeGenerator_TCategoryConfigTypeFunc });
    
    TypeFunc _nsContainerCodeGenerator_TConfigTypeFunc;
    _nsContainerCodeGenerator_TConfigTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsContainerCodeGenerator::TConfig>((nsContainerCodeGenerator::TConfig*) p, str);
    };
    _nsContainerCodeGenerator_TConfigTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsContainerCodeGenerator::TConfig>((nsContainerCodeGenerator::TConfig*) p, str, err);
    };
    
    auto rtti__nsContainerCodeGenerator_TConfigTypeFunc = globalTypeIdentifier->Type<nsContainerCodeGenerator::TConfig>();
    
    m.insert({ rtti__nsContainerCodeGenerator_TConfigTypeFunc, _nsContainerCodeGenerator_TConfigTypeFunc });
    
    TypeFunc _nsContainerCodeGenerator_TGeneratedClassTypeFunc;
    _nsContainerCodeGenerator_TGeneratedClassTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsContainerCodeGenerator::TGeneratedClass>((nsContainerCodeGenerator::TGeneratedClass*) p, str);
    };
    _nsContainerCodeGenerator_TGeneratedClassTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsContainerCodeGenerator::TGeneratedClass>((nsContainerCodeGenerator::TGeneratedClass*) p, str, err);
    };
    
    auto rtti__nsContainerCodeGenerator_TGeneratedClassTypeFunc = globalTypeIdentifier->Type<nsContainerCodeGenerator::TGeneratedClass>();
    
    m.insert({ rtti__nsContainerCodeGenerator_TGeneratedClassTypeFunc, _nsContainerCodeGenerator_TGeneratedClassTypeFunc });
    
    TypeFunc _nsContainerCodeGenerator_TInheritancesTypeFunc;
    _nsContainerCodeGenerator_TInheritancesTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsContainerCodeGenerator::TInheritances>((nsContainerCodeGenerator::TInheritances*) p, str);
    };
    _nsContainerCodeGenerator_TInheritancesTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsContainerCodeGenerator::TInheritances>((nsContainerCodeGenerator::TInheritances*) p, str, err);
    };
    
    auto rtti__nsContainerCodeGenerator_TInheritancesTypeFunc = globalTypeIdentifier->Type<nsContainerCodeGenerator::TInheritances>();
    
    m.insert({ rtti__nsContainerCodeGenerator_TInheritancesTypeFunc, _nsContainerCodeGenerator_TInheritancesTypeFunc });
    
    TypeFunc _nsContainerCodeGenerator_TPartConfigTypeFunc;
    _nsContainerCodeGenerator_TPartConfigTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsContainerCodeGenerator::TPartConfig>((nsContainerCodeGenerator::TPartConfig*) p, str);
    };
    _nsContainerCodeGenerator_TPartConfigTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsContainerCodeGenerator::TPartConfig>((nsContainerCodeGenerator::TPartConfig*) p, str, err);
    };
    
    auto rtti__nsContainerCodeGenerator_TPartConfigTypeFunc = globalTypeIdentifier->Type<nsContainerCodeGenerator::TPartConfig>();
    
    m.insert({ rtti__nsContainerCodeGenerator_TPartConfigTypeFunc, _nsContainerCodeGenerator_TPartConfigTypeFunc });
    
    TypeFunc _nsContainerCodeGenerator_TTargetForParsingTypeFunc;
    _nsContainerCodeGenerator_TTargetForParsingTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsContainerCodeGenerator::TTargetForParsing>((nsContainerCodeGenerator::TTargetForParsing*) p, str);
    };
    _nsContainerCodeGenerator_TTargetForParsingTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsContainerCodeGenerator::TTargetForParsing>((nsContainerCodeGenerator::TTargetForParsing*) p, str, err);
    };
    
    auto rtti__nsContainerCodeGenerator_TTargetForParsingTypeFunc = globalTypeIdentifier->Type<nsContainerCodeGenerator::TTargetForParsing>();
    
    m.insert({ rtti__nsContainerCodeGenerator_TTargetForParsingTypeFunc, _nsContainerCodeGenerator_TTargetForParsingTypeFunc });
    
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
void TJsonSerializer::_Serialize(nsContainerCodeGenerator::TCategoryConfig* p, Jobj& obj)
{
    _Serialize((nsContainerCodeGenerator::TInheritances*)p, obj);// Inheritances
    _Serialize((nsContainerCodeGenerator::TGeneratedClass*)p, obj);// Inheritances
    _Serialize((nsContainerCodeGenerator::TTargetForParsing*)p, obj);// Inheritances
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize(nsContainerCodeGenerator::TCategoryConfig* p, const Jobj& obj)
{
    _Deserialize((nsContainerCodeGenerator::TInheritances*)p, obj);// Inheritances
    _Deserialize((nsContainerCodeGenerator::TGeneratedClass*)p, obj);// Inheritances
    _Deserialize((nsContainerCodeGenerator::TTargetForParsing*)p, obj);// Inheritances
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize(nsContainerCodeGenerator::TConfig* p, Jobj& obj)
{
    PUM::Push(obj, "isNeedCoreGenerate", p->isNeedCoreGenerate);
    auto coreConfig_o = PUM::AddObject(obj, "coreConfig");
    _Serialize(&(p->coreConfig), coreConfig_o);
    auto projectConfig_o = PUM::AddObject(obj, "projectConfig");
    _Serialize(&(p->projectConfig), projectConfig_o);
    auto targetClass_o = PUM::AddObject(obj, "targetClass");
    _Serialize(&(p->targetClass), targetClass_o);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize(nsContainerCodeGenerator::TConfig* p, const Jobj& obj)
{
    POM::PopBool(obj, "isNeedCoreGenerate", p->isNeedCoreGenerate);
    auto coreConfig_o0 = POM::FindObject(obj, "coreConfig");
    _Deserialize(&(p->coreConfig), coreConfig_o0);
    auto projectConfig_o0 = POM::FindObject(obj, "projectConfig");
    _Deserialize(&(p->projectConfig), projectConfig_o0);
    auto targetClass_o0 = POM::FindObject(obj, "targetClass");
    _Deserialize(&(p->targetClass), targetClass_o0);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize(nsContainerCodeGenerator::TGeneratedClass* p, Jobj& obj)
{
    PUM::Push(obj, "directoryPath", p->directoryPath);
    PUM::Push(obj, "exportDeclaration", p->exportDeclaration);
    PUM::Push(obj, "fileName", p->fileName);
    PUM::Push(obj, "typeName", p->typeName);
    PUM::Push(obj, "nameSpace", p->nameSpace);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize(nsContainerCodeGenerator::TGeneratedClass* p, const Jobj& obj)
{
    POM::PopStr(obj, "directoryPath", p->directoryPath);
    POM::PopStr(obj, "exportDeclaration", p->exportDeclaration);
    POM::PopStr(obj, "fileName", p->fileName);
    POM::PopStr(obj, "typeName", p->typeName);
    POM::PopStr(obj, "nameSpace", p->nameSpace);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize(nsContainerCodeGenerator::TInheritances* p, Jobj& obj)
{
    PUM::Value inheritances_a0(rapidjson::kArrayType);
    for(auto& inheritances_e0 : p->inheritances) {
        PUM::PushBack(inheritances_a0, inheritances_e0);
    }
    PUM::Push(obj, "inheritances", inheritances_a0);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize(nsContainerCodeGenerator::TInheritances* p, const Jobj& obj)
{
    if (POM::IsArray(obj, "inheritances")) {
        auto inheritances_a0 = POM::FindArray(obj, "inheritances");
        for(auto& inheritances_e0 : inheritances_a0) {
            p->inheritances.push_back(inheritances_e0.GetString());
        }
    } else {
        std::string inheritances_t0;
        POM::PopStr(obj, "inheritances", inheritances_t0);
        p->inheritances.push_back(inheritances_t0);
    }
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize(nsContainerCodeGenerator::TPartConfig* p, Jobj& obj)
{
    auto componentConfig_o = PUM::AddObject(obj, "componentConfig");
    _Serialize(&(p->componentConfig), componentConfig_o);
    auto handlerConfig_o = PUM::AddObject(obj, "handlerConfig");
    _Serialize(&(p->handlerConfig), handlerConfig_o);
    auto systemConfig_o = PUM::AddObject(obj, "systemConfig");
    _Serialize(&(p->systemConfig), systemConfig_o);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize(nsContainerCodeGenerator::TPartConfig* p, const Jobj& obj)
{
    auto componentConfig_o0 = POM::FindObject(obj, "componentConfig");
    _Deserialize(&(p->componentConfig), componentConfig_o0);
    auto handlerConfig_o0 = POM::FindObject(obj, "handlerConfig");
    _Deserialize(&(p->handlerConfig), handlerConfig_o0);
    auto systemConfig_o0 = POM::FindObject(obj, "systemConfig");
    _Deserialize(&(p->systemConfig), systemConfig_o0);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize(nsContainerCodeGenerator::TTargetForParsing* p, Jobj& obj)
{
    PUM::Value directories_a0(rapidjson::kArrayType);
    for(auto& directories_e0 : p->directories) {
        PUM::PushBack(directories_a0, directories_e0);
    }
    PUM::Push(obj, "directories", directories_a0);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize(nsContainerCodeGenerator::TTargetForParsing* p, const Jobj& obj)
{
    if (POM::IsArray(obj, "directories")) {
        auto directories_a0 = POM::FindArray(obj, "directories");
        for(auto& directories_e0 : directories_a0) {
            p->directories.push_back(directories_e0.GetString());
        }
    } else {
        std::string directories_t0;
        POM::PopStr(obj, "directories", directories_t0);
        p->directories.push_back(directories_t0);
    }
}
//---------------------------------------------------------------------------------------
