/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.4.0, build 58 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, TypeInformation]
// File has been generated at 2022_12_23 16:39:46.768
	
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
    
    TypeFunc _nsContainerCodeGenerator_TAggregatorTypeFunc;
    _nsContainerCodeGenerator_TAggregatorTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsContainerCodeGenerator::TAggregator>((nsContainerCodeGenerator::TAggregator*) p, str);
    };
    _nsContainerCodeGenerator_TAggregatorTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsContainerCodeGenerator::TAggregator>((nsContainerCodeGenerator::TAggregator*) p, str, err);
    };
    
    auto rtti__nsContainerCodeGenerator_TAggregatorTypeFunc = globalTypeIdentifier->Type<nsContainerCodeGenerator::TAggregator>();
    
    m.insert({ rtti__nsContainerCodeGenerator_TAggregatorTypeFunc, _nsContainerCodeGenerator_TAggregatorTypeFunc });
    
    TypeFunc _nsContainerCodeGenerator_TAggregatorClassTypeFunc;
    _nsContainerCodeGenerator_TAggregatorClassTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsContainerCodeGenerator::TAggregatorClass>((nsContainerCodeGenerator::TAggregatorClass*) p, str);
    };
    _nsContainerCodeGenerator_TAggregatorClassTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsContainerCodeGenerator::TAggregatorClass>((nsContainerCodeGenerator::TAggregatorClass*) p, str, err);
    };
    
    auto rtti__nsContainerCodeGenerator_TAggregatorClassTypeFunc = globalTypeIdentifier->Type<nsContainerCodeGenerator::TAggregatorClass>();
    
    m.insert({ rtti__nsContainerCodeGenerator_TAggregatorClassTypeFunc, _nsContainerCodeGenerator_TAggregatorClassTypeFunc });
    
    TypeFunc _nsContainerCodeGenerator_TComponentAggregatorTypeFunc;
    _nsContainerCodeGenerator_TComponentAggregatorTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsContainerCodeGenerator::TComponentAggregator>((nsContainerCodeGenerator::TComponentAggregator*) p, str);
    };
    _nsContainerCodeGenerator_TComponentAggregatorTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsContainerCodeGenerator::TComponentAggregator>((nsContainerCodeGenerator::TComponentAggregator*) p, str, err);
    };
    
    auto rtti__nsContainerCodeGenerator_TComponentAggregatorTypeFunc = globalTypeIdentifier->Type<nsContainerCodeGenerator::TComponentAggregator>();
    
    m.insert({ rtti__nsContainerCodeGenerator_TComponentAggregatorTypeFunc, _nsContainerCodeGenerator_TComponentAggregatorTypeFunc });
    
    TypeFunc _nsContainerCodeGenerator_TComponentConfigTypeFunc;
    _nsContainerCodeGenerator_TComponentConfigTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsContainerCodeGenerator::TComponentConfig>((nsContainerCodeGenerator::TComponentConfig*) p, str);
    };
    _nsContainerCodeGenerator_TComponentConfigTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsContainerCodeGenerator::TComponentConfig>((nsContainerCodeGenerator::TComponentConfig*) p, str, err);
    };
    
    auto rtti__nsContainerCodeGenerator_TComponentConfigTypeFunc = globalTypeIdentifier->Type<nsContainerCodeGenerator::TComponentConfig>();
    
    m.insert({ rtti__nsContainerCodeGenerator_TComponentConfigTypeFunc, _nsContainerCodeGenerator_TComponentConfigTypeFunc });
    
    TypeFunc _nsContainerCodeGenerator_TConfigTypeFunc;
    _nsContainerCodeGenerator_TConfigTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsContainerCodeGenerator::TConfig>((nsContainerCodeGenerator::TConfig*) p, str);
    };
    _nsContainerCodeGenerator_TConfigTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsContainerCodeGenerator::TConfig>((nsContainerCodeGenerator::TConfig*) p, str, err);
    };
    
    auto rtti__nsContainerCodeGenerator_TConfigTypeFunc = globalTypeIdentifier->Type<nsContainerCodeGenerator::TConfig>();
    
    m.insert({ rtti__nsContainerCodeGenerator_TConfigTypeFunc, _nsContainerCodeGenerator_TConfigTypeFunc });
    
    TypeFunc _nsContainerCodeGenerator_TCoreConfigTypeFunc;
    _nsContainerCodeGenerator_TCoreConfigTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsContainerCodeGenerator::TCoreConfig>((nsContainerCodeGenerator::TCoreConfig*) p, str);
    };
    _nsContainerCodeGenerator_TCoreConfigTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsContainerCodeGenerator::TCoreConfig>((nsContainerCodeGenerator::TCoreConfig*) p, str, err);
    };
    
    auto rtti__nsContainerCodeGenerator_TCoreConfigTypeFunc = globalTypeIdentifier->Type<nsContainerCodeGenerator::TCoreConfig>();
    
    m.insert({ rtti__nsContainerCodeGenerator_TCoreConfigTypeFunc, _nsContainerCodeGenerator_TCoreConfigTypeFunc });
    
    TypeFunc _nsContainerCodeGenerator_TEcsSystemConfigTypeFunc;
    _nsContainerCodeGenerator_TEcsSystemConfigTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsContainerCodeGenerator::TEcsSystemConfig>((nsContainerCodeGenerator::TEcsSystemConfig*) p, str);
    };
    _nsContainerCodeGenerator_TEcsSystemConfigTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsContainerCodeGenerator::TEcsSystemConfig>((nsContainerCodeGenerator::TEcsSystemConfig*) p, str, err);
    };
    
    auto rtti__nsContainerCodeGenerator_TEcsSystemConfigTypeFunc = globalTypeIdentifier->Type<nsContainerCodeGenerator::TEcsSystemConfig>();
    
    m.insert({ rtti__nsContainerCodeGenerator_TEcsSystemConfigTypeFunc, _nsContainerCodeGenerator_TEcsSystemConfigTypeFunc });
    
    TypeFunc _nsContainerCodeGenerator_TGeneratedClassTypeFunc;
    _nsContainerCodeGenerator_TGeneratedClassTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsContainerCodeGenerator::TGeneratedClass>((nsContainerCodeGenerator::TGeneratedClass*) p, str);
    };
    _nsContainerCodeGenerator_TGeneratedClassTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsContainerCodeGenerator::TGeneratedClass>((nsContainerCodeGenerator::TGeneratedClass*) p, str, err);
    };
    
    auto rtti__nsContainerCodeGenerator_TGeneratedClassTypeFunc = globalTypeIdentifier->Type<nsContainerCodeGenerator::TGeneratedClass>();
    
    m.insert({ rtti__nsContainerCodeGenerator_TGeneratedClassTypeFunc, _nsContainerCodeGenerator_TGeneratedClassTypeFunc });
    
    TypeFunc _nsContainerCodeGenerator_THandlerAggregatorTypeFunc;
    _nsContainerCodeGenerator_THandlerAggregatorTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsContainerCodeGenerator::THandlerAggregator>((nsContainerCodeGenerator::THandlerAggregator*) p, str);
    };
    _nsContainerCodeGenerator_THandlerAggregatorTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsContainerCodeGenerator::THandlerAggregator>((nsContainerCodeGenerator::THandlerAggregator*) p, str, err);
    };
    
    auto rtti__nsContainerCodeGenerator_THandlerAggregatorTypeFunc = globalTypeIdentifier->Type<nsContainerCodeGenerator::THandlerAggregator>();
    
    m.insert({ rtti__nsContainerCodeGenerator_THandlerAggregatorTypeFunc, _nsContainerCodeGenerator_THandlerAggregatorTypeFunc });
    
    TypeFunc _nsContainerCodeGenerator_THandlerConfigTypeFunc;
    _nsContainerCodeGenerator_THandlerConfigTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsContainerCodeGenerator::THandlerConfig>((nsContainerCodeGenerator::THandlerConfig*) p, str);
    };
    _nsContainerCodeGenerator_THandlerConfigTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsContainerCodeGenerator::THandlerConfig>((nsContainerCodeGenerator::THandlerConfig*) p, str, err);
    };
    
    auto rtti__nsContainerCodeGenerator_THandlerConfigTypeFunc = globalTypeIdentifier->Type<nsContainerCodeGenerator::THandlerConfig>();
    
    m.insert({ rtti__nsContainerCodeGenerator_THandlerConfigTypeFunc, _nsContainerCodeGenerator_THandlerConfigTypeFunc });
    
    TypeFunc _nsContainerCodeGenerator_TIncludeListFileNameTypeFunc;
    _nsContainerCodeGenerator_TIncludeListFileNameTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsContainerCodeGenerator::TIncludeListFileName>((nsContainerCodeGenerator::TIncludeListFileName*) p, str);
    };
    _nsContainerCodeGenerator_TIncludeListFileNameTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsContainerCodeGenerator::TIncludeListFileName>((nsContainerCodeGenerator::TIncludeListFileName*) p, str, err);
    };
    
    auto rtti__nsContainerCodeGenerator_TIncludeListFileNameTypeFunc = globalTypeIdentifier->Type<nsContainerCodeGenerator::TIncludeListFileName>();
    
    m.insert({ rtti__nsContainerCodeGenerator_TIncludeListFileNameTypeFunc, _nsContainerCodeGenerator_TIncludeListFileNameTypeFunc });
    
    TypeFunc _nsContainerCodeGenerator_TParentClassTypeFunc;
    _nsContainerCodeGenerator_TParentClassTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsContainerCodeGenerator::TParentClass>((nsContainerCodeGenerator::TParentClass*) p, str);
    };
    _nsContainerCodeGenerator_TParentClassTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsContainerCodeGenerator::TParentClass>((nsContainerCodeGenerator::TParentClass*) p, str, err);
    };
    
    auto rtti__nsContainerCodeGenerator_TParentClassTypeFunc = globalTypeIdentifier->Type<nsContainerCodeGenerator::TParentClass>();
    
    m.insert({ rtti__nsContainerCodeGenerator_TParentClassTypeFunc, _nsContainerCodeGenerator_TParentClassTypeFunc });
    
    TypeFunc _nsContainerCodeGenerator_TProjectConfigTypeFunc;
    _nsContainerCodeGenerator_TProjectConfigTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsContainerCodeGenerator::TProjectConfig>((nsContainerCodeGenerator::TProjectConfig*) p, str);
    };
    _nsContainerCodeGenerator_TProjectConfigTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsContainerCodeGenerator::TProjectConfig>((nsContainerCodeGenerator::TProjectConfig*) p, str, err);
    };
    
    auto rtti__nsContainerCodeGenerator_TProjectConfigTypeFunc = globalTypeIdentifier->Type<nsContainerCodeGenerator::TProjectConfig>();
    
    m.insert({ rtti__nsContainerCodeGenerator_TProjectConfigTypeFunc, _nsContainerCodeGenerator_TProjectConfigTypeFunc });
    
    TypeFunc _nsContainerCodeGenerator_TSystemAggregatorTypeFunc;
    _nsContainerCodeGenerator_TSystemAggregatorTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsContainerCodeGenerator::TSystemAggregator>((nsContainerCodeGenerator::TSystemAggregator*) p, str);
    };
    _nsContainerCodeGenerator_TSystemAggregatorTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsContainerCodeGenerator::TSystemAggregator>((nsContainerCodeGenerator::TSystemAggregator*) p, str, err);
    };
    
    auto rtti__nsContainerCodeGenerator_TSystemAggregatorTypeFunc = globalTypeIdentifier->Type<nsContainerCodeGenerator::TSystemAggregator>();
    
    m.insert({ rtti__nsContainerCodeGenerator_TSystemAggregatorTypeFunc, _nsContainerCodeGenerator_TSystemAggregatorTypeFunc });
    
    TypeFunc _nsContainerCodeGenerator_TSystemConfigTypeFunc;
    _nsContainerCodeGenerator_TSystemConfigTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsContainerCodeGenerator::TSystemConfig>((nsContainerCodeGenerator::TSystemConfig*) p, str);
    };
    _nsContainerCodeGenerator_TSystemConfigTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsContainerCodeGenerator::TSystemConfig>((nsContainerCodeGenerator::TSystemConfig*) p, str, err);
    };
    
    auto rtti__nsContainerCodeGenerator_TSystemConfigTypeFunc = globalTypeIdentifier->Type<nsContainerCodeGenerator::TSystemConfig>();
    
    m.insert({ rtti__nsContainerCodeGenerator_TSystemConfigTypeFunc, _nsContainerCodeGenerator_TSystemConfigTypeFunc });
    
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
void TJsonSerializer::_Serialize(nsContainerCodeGenerator::TAggregator* p, Jobj& obj)
{
    _Serialize((nsContainerCodeGenerator::TAggregatorClass*)p, obj);// Inheritances
    PUM::Push(obj, "targetDirectory", p->targetDirectory);
    PUM::Push(obj, "exportDeclaration", p->exportDeclaration);
    PUM::Push(obj, "cExportDeclaration", p->cExportDeclaration);
    PUM::Push(obj, "dllHeaderFileName", p->dllHeaderFileName);
    PUM::Push(obj, "dllCppFileName", p->dllCppFileName);
    PUM::Push(obj, "getFuncName", p->getFuncName);
    PUM::Push(obj, "freeFuncName", p->freeFuncName);
    auto componentImpl_o = PUM::AddObject(obj, "componentImpl");
    _Serialize(&(p->componentImpl), componentImpl_o);
    auto handlerImpl_o = PUM::AddObject(obj, "handlerImpl");
    _Serialize(&(p->handlerImpl), handlerImpl_o);
    auto systemImpl_o = PUM::AddObject(obj, "systemImpl");
    _Serialize(&(p->systemImpl), systemImpl_o);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize(nsContainerCodeGenerator::TAggregator* p, const Jobj& obj)
{
    _Deserialize((nsContainerCodeGenerator::TAggregatorClass*)p, obj);// Inheritances
    POM::PopStr(obj, "targetDirectory", p->targetDirectory);
    POM::PopStr(obj, "exportDeclaration", p->exportDeclaration);
    POM::PopStr(obj, "cExportDeclaration", p->cExportDeclaration);
    POM::PopStr(obj, "dllHeaderFileName", p->dllHeaderFileName);
    POM::PopStr(obj, "dllCppFileName", p->dllCppFileName);
    POM::PopStr(obj, "getFuncName", p->getFuncName);
    POM::PopStr(obj, "freeFuncName", p->freeFuncName);
    auto componentImpl_o0 = POM::FindObject(obj, "componentImpl");
    _Deserialize(&(p->componentImpl), componentImpl_o0);
    auto handlerImpl_o0 = POM::FindObject(obj, "handlerImpl");
    _Deserialize(&(p->handlerImpl), handlerImpl_o0);
    auto systemImpl_o0 = POM::FindObject(obj, "systemImpl");
    _Deserialize(&(p->systemImpl), systemImpl_o0);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize(nsContainerCodeGenerator::TAggregatorClass* p, Jobj& obj)
{
    auto impl_o = PUM::AddObject(obj, "impl");
    _Serialize(&(p->impl), impl_o);
    auto parent_o = PUM::AddObject(obj, "parent");
    _Serialize(&(p->parent), parent_o);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize(nsContainerCodeGenerator::TAggregatorClass* p, const Jobj& obj)
{
    auto impl_o0 = POM::FindObject(obj, "impl");
    _Deserialize(&(p->impl), impl_o0);
    auto parent_o0 = POM::FindObject(obj, "parent");
    _Deserialize(&(p->parent), parent_o0);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize(nsContainerCodeGenerator::TComponentAggregator* p, Jobj& obj)
{
    _Serialize((nsContainerCodeGenerator::TAggregatorClass*)p, obj);// Inheritances
    auto typeInfoImpl_o = PUM::AddObject(obj, "typeInfoImpl");
    _Serialize(&(p->typeInfoImpl), typeInfoImpl_o);
    auto jsonImpl_o = PUM::AddObject(obj, "jsonImpl");
    _Serialize(&(p->jsonImpl), jsonImpl_o);
    auto binaryImpl_o = PUM::AddObject(obj, "binaryImpl");
    _Serialize(&(p->binaryImpl), binaryImpl_o);
    auto imGuiImpl_o = PUM::AddObject(obj, "imGuiImpl");
    _Serialize(&(p->imGuiImpl), imGuiImpl_o);
    auto entMngImpl_o = PUM::AddObject(obj, "entMngImpl");
    _Serialize(&(p->entMngImpl), entMngImpl_o);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize(nsContainerCodeGenerator::TComponentAggregator* p, const Jobj& obj)
{
    _Deserialize((nsContainerCodeGenerator::TAggregatorClass*)p, obj);// Inheritances
    auto typeInfoImpl_o0 = POM::FindObject(obj, "typeInfoImpl");
    _Deserialize(&(p->typeInfoImpl), typeInfoImpl_o0);
    auto jsonImpl_o0 = POM::FindObject(obj, "jsonImpl");
    _Deserialize(&(p->jsonImpl), jsonImpl_o0);
    auto binaryImpl_o0 = POM::FindObject(obj, "binaryImpl");
    _Deserialize(&(p->binaryImpl), binaryImpl_o0);
    auto imGuiImpl_o0 = POM::FindObject(obj, "imGuiImpl");
    _Deserialize(&(p->imGuiImpl), imGuiImpl_o0);
    auto entMngImpl_o0 = POM::FindObject(obj, "entMngImpl");
    _Deserialize(&(p->entMngImpl), entMngImpl_o0);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize(nsContainerCodeGenerator::TComponentConfig* p, Jobj& obj)
{
    _Serialize((nsContainerCodeGenerator::TIncludeListFileName*)p, obj);// Inheritances
    PUM::Push(obj, "inheritanceFilter", p->inheritanceFilter);
    auto typeInfo_o = PUM::AddObject(obj, "typeInfo");
    _Serialize(&(p->typeInfo), typeInfo_o);
    auto json_o = PUM::AddObject(obj, "json");
    _Serialize(&(p->json), json_o);
    auto binary_o = PUM::AddObject(obj, "binary");
    _Serialize(&(p->binary), binary_o);
    auto imGui_o = PUM::AddObject(obj, "imGui");
    _Serialize(&(p->imGui), imGui_o);
    auto entMng_o = PUM::AddObject(obj, "entMng");
    _Serialize(&(p->entMng), entMng_o);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize(nsContainerCodeGenerator::TComponentConfig* p, const Jobj& obj)
{
    _Deserialize((nsContainerCodeGenerator::TIncludeListFileName*)p, obj);// Inheritances
    POM::PopStr(obj, "inheritanceFilter", p->inheritanceFilter);
    auto typeInfo_o0 = POM::FindObject(obj, "typeInfo");
    _Deserialize(&(p->typeInfo), typeInfo_o0);
    auto json_o0 = POM::FindObject(obj, "json");
    _Deserialize(&(p->json), json_o0);
    auto binary_o0 = POM::FindObject(obj, "binary");
    _Deserialize(&(p->binary), binary_o0);
    auto imGui_o0 = POM::FindObject(obj, "imGui");
    _Deserialize(&(p->imGui), imGui_o0);
    auto entMng_o0 = POM::FindObject(obj, "entMng");
    _Deserialize(&(p->entMng), entMng_o0);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize(nsContainerCodeGenerator::TConfig* p, Jobj& obj)
{
    PUM::Push(obj, "reflectionCodeGeneratorFileName", p->reflectionCodeGeneratorFileName);
    PUM::Push(obj, "entityManagerHeaderPath", p->entityManagerHeaderPath);
    PUM::Push(obj, "baseHandlerTypeName", p->baseHandlerTypeName);
    auto coreConfig_o = PUM::AddObject(obj, "coreConfig");
    _Serialize(&(p->coreConfig), coreConfig_o);
    auto projectConfig_o = PUM::AddObject(obj, "projectConfig");
    _Serialize(&(p->projectConfig), projectConfig_o);
    auto aggregator_o = PUM::AddObject(obj, "aggregator");
    _Serialize(&(p->aggregator), aggregator_o);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize(nsContainerCodeGenerator::TConfig* p, const Jobj& obj)
{
    POM::PopStr(obj, "reflectionCodeGeneratorFileName", p->reflectionCodeGeneratorFileName);
    POM::PopStr(obj, "entityManagerHeaderPath", p->entityManagerHeaderPath);
    POM::PopStr(obj, "baseHandlerTypeName", p->baseHandlerTypeName);
    auto coreConfig_o0 = POM::FindObject(obj, "coreConfig");
    _Deserialize(&(p->coreConfig), coreConfig_o0);
    auto projectConfig_o0 = POM::FindObject(obj, "projectConfig");
    _Deserialize(&(p->projectConfig), projectConfig_o0);
    auto aggregator_o0 = POM::FindObject(obj, "aggregator");
    _Deserialize(&(p->aggregator), aggregator_o0);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize(nsContainerCodeGenerator::TCoreConfig* p, Jobj& obj)
{
    PUM::Push(obj, "isNeedGenerate", p->isNeedGenerate);
    PUM::Push(obj, "exportDeclaration", p->exportDeclaration);
    PUM::Push(obj, "targetDirectory", p->targetDirectory);
    PUM::Push(obj, "nameSpace", p->nameSpace);
    PUM::Push(obj, "parseDirectory", p->parseDirectory);
    auto componentConfig_o = PUM::AddObject(obj, "componentConfig");
    _Serialize(&(p->componentConfig), componentConfig_o);
    auto ecsSystemConfig_o = PUM::AddObject(obj, "ecsSystemConfig");
    _Serialize(&(p->ecsSystemConfig), ecsSystemConfig_o);
    auto systemConfig_o = PUM::AddObject(obj, "systemConfig");
    _Serialize(&(p->systemConfig), systemConfig_o);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize(nsContainerCodeGenerator::TCoreConfig* p, const Jobj& obj)
{
    POM::PopBool(obj, "isNeedGenerate", p->isNeedGenerate);
    POM::PopStr(obj, "exportDeclaration", p->exportDeclaration);
    POM::PopStr(obj, "targetDirectory", p->targetDirectory);
    POM::PopStr(obj, "nameSpace", p->nameSpace);
    POM::PopStr(obj, "parseDirectory", p->parseDirectory);
    auto componentConfig_o0 = POM::FindObject(obj, "componentConfig");
    _Deserialize(&(p->componentConfig), componentConfig_o0);
    auto ecsSystemConfig_o0 = POM::FindObject(obj, "ecsSystemConfig");
    _Deserialize(&(p->ecsSystemConfig), ecsSystemConfig_o0);
    auto systemConfig_o0 = POM::FindObject(obj, "systemConfig");
    _Deserialize(&(p->systemConfig), systemConfig_o0);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize(nsContainerCodeGenerator::TEcsSystemConfig* p, Jobj& obj)
{
    _Serialize((nsContainerCodeGenerator::TIncludeListFileName*)p, obj);// Inheritances
    PUM::Push(obj, "ecsDirectory", p->ecsDirectory);
    auto typeInfo_o = PUM::AddObject(obj, "typeInfo");
    _Serialize(&(p->typeInfo), typeInfo_o);
    auto dynamicCaster_o = PUM::AddObject(obj, "dynamicCaster");
    _Serialize(&(p->dynamicCaster), dynamicCaster_o);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize(nsContainerCodeGenerator::TEcsSystemConfig* p, const Jobj& obj)
{
    _Deserialize((nsContainerCodeGenerator::TIncludeListFileName*)p, obj);// Inheritances
    POM::PopStr(obj, "ecsDirectory", p->ecsDirectory);
    auto typeInfo_o0 = POM::FindObject(obj, "typeInfo");
    _Deserialize(&(p->typeInfo), typeInfo_o0);
    auto dynamicCaster_o0 = POM::FindObject(obj, "dynamicCaster");
    _Deserialize(&(p->dynamicCaster), dynamicCaster_o0);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize(nsContainerCodeGenerator::TGeneratedClass* p, Jobj& obj)
{
    PUM::Push(obj, "fileName", p->fileName);
    PUM::Push(obj, "typeName", p->typeName);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize(nsContainerCodeGenerator::TGeneratedClass* p, const Jobj& obj)
{
    POM::PopStr(obj, "fileName", p->fileName);
    POM::PopStr(obj, "typeName", p->typeName);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize(nsContainerCodeGenerator::THandlerAggregator* p, Jobj& obj)
{
    _Serialize((nsContainerCodeGenerator::TAggregatorClass*)p, obj);// Inheritances
    auto typeInfoImpl_o = PUM::AddObject(obj, "typeInfoImpl");
    _Serialize(&(p->typeInfoImpl), typeInfoImpl_o);
    auto typeFactoryImpl_o = PUM::AddObject(obj, "typeFactoryImpl");
    _Serialize(&(p->typeFactoryImpl), typeFactoryImpl_o);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize(nsContainerCodeGenerator::THandlerAggregator* p, const Jobj& obj)
{
    _Deserialize((nsContainerCodeGenerator::TAggregatorClass*)p, obj);// Inheritances
    auto typeInfoImpl_o0 = POM::FindObject(obj, "typeInfoImpl");
    _Deserialize(&(p->typeInfoImpl), typeInfoImpl_o0);
    auto typeFactoryImpl_o0 = POM::FindObject(obj, "typeFactoryImpl");
    _Deserialize(&(p->typeFactoryImpl), typeFactoryImpl_o0);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize(nsContainerCodeGenerator::THandlerConfig* p, Jobj& obj)
{
    _Serialize((nsContainerCodeGenerator::TIncludeListFileName*)p, obj);// Inheritances
    auto typeInfo_o = PUM::AddObject(obj, "typeInfo");
    _Serialize(&(p->typeInfo), typeInfo_o);
    auto typeFactory_o = PUM::AddObject(obj, "typeFactory");
    _Serialize(&(p->typeFactory), typeFactory_o);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize(nsContainerCodeGenerator::THandlerConfig* p, const Jobj& obj)
{
    _Deserialize((nsContainerCodeGenerator::TIncludeListFileName*)p, obj);// Inheritances
    auto typeInfo_o0 = POM::FindObject(obj, "typeInfo");
    _Deserialize(&(p->typeInfo), typeInfo_o0);
    auto typeFactory_o0 = POM::FindObject(obj, "typeFactory");
    _Deserialize(&(p->typeFactory), typeFactory_o0);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize(nsContainerCodeGenerator::TIncludeListFileName* p, Jobj& obj)
{
    PUM::Push(obj, "includeListFileName", p->includeListFileName);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize(nsContainerCodeGenerator::TIncludeListFileName* p, const Jobj& obj)
{
    POM::PopStr(obj, "includeListFileName", p->includeListFileName);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize(nsContainerCodeGenerator::TParentClass* p, Jobj& obj)
{
    PUM::Push(obj, "fileName", p->fileName);
    PUM::Push(obj, "typeName", p->typeName);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize(nsContainerCodeGenerator::TParentClass* p, const Jobj& obj)
{
    POM::PopStr(obj, "fileName", p->fileName);
    POM::PopStr(obj, "typeName", p->typeName);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize(nsContainerCodeGenerator::TProjectConfig* p, Jobj& obj)
{
    PUM::Push(obj, "exportDeclaration", p->exportDeclaration);
    PUM::Push(obj, "targetDirectory", p->targetDirectory);
    PUM::Push(obj, "nameSpace", p->nameSpace);
    PUM::Push(obj, "parseDirectory", p->parseDirectory);
    auto componentConfig_o = PUM::AddObject(obj, "componentConfig");
    _Serialize(&(p->componentConfig), componentConfig_o);
    auto handlerConfig_o = PUM::AddObject(obj, "handlerConfig");
    _Serialize(&(p->handlerConfig), handlerConfig_o);
    auto systemConfig_o = PUM::AddObject(obj, "systemConfig");
    _Serialize(&(p->systemConfig), systemConfig_o);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize(nsContainerCodeGenerator::TProjectConfig* p, const Jobj& obj)
{
    POM::PopStr(obj, "exportDeclaration", p->exportDeclaration);
    POM::PopStr(obj, "targetDirectory", p->targetDirectory);
    POM::PopStr(obj, "nameSpace", p->nameSpace);
    POM::PopStr(obj, "parseDirectory", p->parseDirectory);
    auto componentConfig_o0 = POM::FindObject(obj, "componentConfig");
    _Deserialize(&(p->componentConfig), componentConfig_o0);
    auto handlerConfig_o0 = POM::FindObject(obj, "handlerConfig");
    _Deserialize(&(p->handlerConfig), handlerConfig_o0);
    auto systemConfig_o0 = POM::FindObject(obj, "systemConfig");
    _Deserialize(&(p->systemConfig), systemConfig_o0);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize(nsContainerCodeGenerator::TSystemAggregator* p, Jobj& obj)
{
    _Serialize((nsContainerCodeGenerator::TAggregatorClass*)p, obj);// Inheritances
    auto typeInfoImpl_o = PUM::AddObject(obj, "typeInfoImpl");
    _Serialize(&(p->typeInfoImpl), typeInfoImpl_o);
    auto typeFactoryImpl_o = PUM::AddObject(obj, "typeFactoryImpl");
    _Serialize(&(p->typeFactoryImpl), typeFactoryImpl_o);
    auto dynamicCasterImpl_o = PUM::AddObject(obj, "dynamicCasterImpl");
    _Serialize(&(p->dynamicCasterImpl), dynamicCasterImpl_o);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize(nsContainerCodeGenerator::TSystemAggregator* p, const Jobj& obj)
{
    _Deserialize((nsContainerCodeGenerator::TAggregatorClass*)p, obj);// Inheritances
    auto typeInfoImpl_o0 = POM::FindObject(obj, "typeInfoImpl");
    _Deserialize(&(p->typeInfoImpl), typeInfoImpl_o0);
    auto typeFactoryImpl_o0 = POM::FindObject(obj, "typeFactoryImpl");
    _Deserialize(&(p->typeFactoryImpl), typeFactoryImpl_o0);
    auto dynamicCasterImpl_o0 = POM::FindObject(obj, "dynamicCasterImpl");
    _Deserialize(&(p->dynamicCasterImpl), dynamicCasterImpl_o0);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize(nsContainerCodeGenerator::TSystemConfig* p, Jobj& obj)
{
    _Serialize((nsContainerCodeGenerator::TIncludeListFileName*)p, obj);// Inheritances
    PUM::Value inheritances_a0(rapidjson::kArrayType);
    for(auto& inheritances_e0 : p->inheritances) {
        PUM::PushBack(inheritances_a0, inheritances_e0);
    }
    PUM::Push(obj, "inheritances", inheritances_a0);
    auto typeInfo_o = PUM::AddObject(obj, "typeInfo");
    _Serialize(&(p->typeInfo), typeInfo_o);
    auto typeFactory_o = PUM::AddObject(obj, "typeFactory");
    _Serialize(&(p->typeFactory), typeFactory_o);
    auto dynamicCaster_o = PUM::AddObject(obj, "dynamicCaster");
    _Serialize(&(p->dynamicCaster), dynamicCaster_o);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize(nsContainerCodeGenerator::TSystemConfig* p, const Jobj& obj)
{
    _Deserialize((nsContainerCodeGenerator::TIncludeListFileName*)p, obj);// Inheritances
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
    auto typeInfo_o0 = POM::FindObject(obj, "typeInfo");
    _Deserialize(&(p->typeInfo), typeInfo_o0);
    auto typeFactory_o0 = POM::FindObject(obj, "typeFactory");
    _Deserialize(&(p->typeFactory), typeFactory_o0);
    auto dynamicCaster_o0 = POM::FindObject(obj, "dynamicCaster");
    _Deserialize(&(p->dynamicCaster), dynamicCaster_o0);
}
//---------------------------------------------------------------------------------------
