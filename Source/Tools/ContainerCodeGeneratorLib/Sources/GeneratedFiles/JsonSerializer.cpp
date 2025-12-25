/*
	ContainerCodeGenerator
*/
// ReflectionCodeGenerator version 2.5.1, build 60 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, RTTI, TypeInformation]

#include "Base/Common/JsonPopMaster.h"
#include "Base/Common/JsonPushMaster.h"
#include "Base/Common/SingletonManager.h"
#include "Base/Common/RunTimeTypeIndex.h"
#include "ContainerCodeGeneratorLib/Sources/GeneratedFiles/JsonSerializer.h"

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
    
    std::list<TypeFunc> funcs;
    
    TypeFunc _nsContainerCodeGenerator_TCodeGenerationResultTypeFunc;
    _nsContainerCodeGenerator_TCodeGenerationResultTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsContainerCodeGenerator::TCodeGenerationResult>((nsContainerCodeGenerator::TCodeGenerationResult*) p, str);
    };
    _nsContainerCodeGenerator_TCodeGenerationResultTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsContainerCodeGenerator::TCodeGenerationResult>((nsContainerCodeGenerator::TCodeGenerationResult*) p, str, err);
    };
    
    _nsContainerCodeGenerator_TCodeGenerationResultTypeFunc.rtti = globalTypeIdentifier->Type<nsContainerCodeGenerator::TCodeGenerationResult>();
    
    funcs.push_back(_nsContainerCodeGenerator_TCodeGenerationResultTypeFunc);
    
    TypeFunc _nsContainerCodeGenerator_TCodeGenerationResultListTypeFunc;
    _nsContainerCodeGenerator_TCodeGenerationResultListTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsContainerCodeGenerator::TCodeGenerationResultList>((nsContainerCodeGenerator::TCodeGenerationResultList*) p, str);
    };
    _nsContainerCodeGenerator_TCodeGenerationResultListTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsContainerCodeGenerator::TCodeGenerationResultList>((nsContainerCodeGenerator::TCodeGenerationResultList*) p, str, err);
    };
    
    _nsContainerCodeGenerator_TCodeGenerationResultListTypeFunc.rtti = globalTypeIdentifier->Type<nsContainerCodeGenerator::TCodeGenerationResultList>();
    
    funcs.push_back(_nsContainerCodeGenerator_TCodeGenerationResultListTypeFunc);
    
    TypeFunc _nsContainerCodeGenerator_TCoreConfigTypeFunc;
    _nsContainerCodeGenerator_TCoreConfigTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsContainerCodeGenerator::TCoreConfig>((nsContainerCodeGenerator::TCoreConfig*) p, str);
    };
    _nsContainerCodeGenerator_TCoreConfigTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsContainerCodeGenerator::TCoreConfig>((nsContainerCodeGenerator::TCoreConfig*) p, str, err);
    };
    
    _nsContainerCodeGenerator_TCoreConfigTypeFunc.rtti = globalTypeIdentifier->Type<nsContainerCodeGenerator::TCoreConfig>();
    
    funcs.push_back(_nsContainerCodeGenerator_TCoreConfigTypeFunc);
    
    TypeFunc _nsContainerCodeGenerator_TPathSettingTypeFunc;
    _nsContainerCodeGenerator_TPathSettingTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsContainerCodeGenerator::TPathSetting>((nsContainerCodeGenerator::TPathSetting*) p, str);
    };
    _nsContainerCodeGenerator_TPathSettingTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsContainerCodeGenerator::TPathSetting>((nsContainerCodeGenerator::TPathSetting*) p, str, err);
    };
    
    _nsContainerCodeGenerator_TPathSettingTypeFunc.rtti = globalTypeIdentifier->Type<nsContainerCodeGenerator::TPathSetting>();
    
    funcs.push_back(_nsContainerCodeGenerator_TPathSettingTypeFunc);
    
    TypeFunc _nsContainerCodeGenerator_TProjectConfigTypeFunc;
    _nsContainerCodeGenerator_TProjectConfigTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsContainerCodeGenerator::TProjectConfig>((nsContainerCodeGenerator::TProjectConfig*) p, str);
    };
    _nsContainerCodeGenerator_TProjectConfigTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsContainerCodeGenerator::TProjectConfig>((nsContainerCodeGenerator::TProjectConfig*) p, str, err);
    };
    
    _nsContainerCodeGenerator_TProjectConfigTypeFunc.rtti = globalTypeIdentifier->Type<nsContainerCodeGenerator::TProjectConfig>();
    
    funcs.push_back(_nsContainerCodeGenerator_TProjectConfigTypeFunc);
    
    int max = 0;
    for (auto& f : funcs) {
        max = std::max(f.rtti, max);
    }
    
    mTypeFuncVector.resize(max + 1);
    for (auto& f : funcs) {
        mTypeFuncVector[f.rtti] = f;
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
void TJsonSerializer::_Serialize(nsContainerCodeGenerator::TCodeGenerationResult* p, Jobj& obj)
{
    PUM::Push(obj, "fileName", p->fileName);
    PUM::Push(obj, "typeName", p->typeName);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize(nsContainerCodeGenerator::TCodeGenerationResult* p, const Jobj& obj)
{
    POM::PopStr(obj, "fileName", p->fileName);
    POM::PopStr(obj, "typeName", p->typeName);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize(nsContainerCodeGenerator::TCodeGenerationResultList* p, Jobj& obj)
{
    auto generated_c0 = PUM::AddObject(obj, "generated");
    for(auto& generated_e0 : p->generated) {
        auto generated_a0 = PUM::AddObject(generated_c0, PUM::ConvertToString(generated_e0.first).data());
        _Serialize(&(generated_e0.second), generated_a0);
    }
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize(nsContainerCodeGenerator::TCodeGenerationResultList* p, const Jobj& obj)
{
    auto generated_a0 = POM::FindObject(obj, "generated");
    for(auto& generated_e0 : generated_a0) {
        auto generated_o1 = generated_e0.value.GetObject();
        nsContainerCodeGenerator::TCodeGenerationResult generated_c1;
        _Deserialize(&generated_c1, generated_o1);
        p->generated.insert({ generated_e0.name.GetString(), generated_c1 });
    }
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize(nsContainerCodeGenerator::TCoreConfig* p, Jobj& obj)
{
    PUM::Push(obj, "exportDeclaration", p->exportDeclaration);
    PUM::Push(obj, "nameSpace", p->nameSpace);
    auto containers_c0 = PUM::AddObject(obj, "containers");
    for(auto& containers_e0 : p->containers) {
        auto containers_a0 = PUM::AddObject(containers_c0, PUM::ConvertToString(containers_e0.first).data());
        _Serialize(&(containers_e0.second), containers_a0);
    }
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize(nsContainerCodeGenerator::TCoreConfig* p, const Jobj& obj)
{
    POM::PopStr(obj, "exportDeclaration", p->exportDeclaration);
    POM::PopStr(obj, "nameSpace", p->nameSpace);
    auto containers_a0 = POM::FindObject(obj, "containers");
    for(auto& containers_e0 : containers_a0) {
        auto containers_o1 = containers_e0.value.GetObject();
        nsContainerCodeGenerator::TCodeGenerationResultList containers_c1;
        _Deserialize(&containers_c1, containers_o1);
        p->containers.insert({ containers_e0.name.GetString(), containers_c1 });
    }
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize(nsContainerCodeGenerator::TPathSetting* p, Jobj& obj)
{
    PUM::Push(obj, "coreDir", p->coreDir);
    PUM::Push(obj, "coreDirForParse", p->coreDirForParse);
    PUM::Push(obj, "reflectionCodeGeneratorFileName", p->reflectionCodeGeneratorFileName);
    PUM::Push(obj, "entityManagerDir", p->entityManagerDir);
    PUM::Push(obj, "ecsDir", p->ecsDir);
    PUM::Push(obj, "imGuiWidgetsDir", p->imGuiWidgetsDir);
    PUM::Push(obj, "projectDirForParse", p->projectDirForParse);
    PUM::Push(obj, "containerGeneratedFilesDir", p->containerGeneratedFilesDir);
    PUM::Push(obj, "aggregatorGeneratedFilesDir", p->aggregatorGeneratedFilesDir);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize(nsContainerCodeGenerator::TPathSetting* p, const Jobj& obj)
{
    POM::PopStr(obj, "coreDir", p->coreDir);
    POM::PopStr(obj, "coreDirForParse", p->coreDirForParse);
    POM::PopStr(obj, "reflectionCodeGeneratorFileName", p->reflectionCodeGeneratorFileName);
    POM::PopStr(obj, "entityManagerDir", p->entityManagerDir);
    POM::PopStr(obj, "ecsDir", p->ecsDir);
    POM::PopStr(obj, "imGuiWidgetsDir", p->imGuiWidgetsDir);
    POM::PopStr(obj, "projectDirForParse", p->projectDirForParse);
    POM::PopStr(obj, "containerGeneratedFilesDir", p->containerGeneratedFilesDir);
    POM::PopStr(obj, "aggregatorGeneratedFilesDir", p->aggregatorGeneratedFilesDir);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize(nsContainerCodeGenerator::TProjectConfig* p, Jobj& obj)
{
    PUM::Push(obj, "exportDeclaration", p->exportDeclaration);
    PUM::Push(obj, "nameSpace", p->nameSpace);
    auto mainAggregator_o = PUM::AddObject(obj, "mainAggregator");
    _Serialize(&(p->mainAggregator), mainAggregator_o);
    auto containers_c0 = PUM::AddObject(obj, "containers");
    for(auto& containers_e0 : p->containers) {
        auto containers_a0 = PUM::AddObject(containers_c0, PUM::ConvertToString(containers_e0.first).data());
        _Serialize(&(containers_e0.second), containers_a0);
    }
    auto aggregators_c0 = PUM::AddObject(obj, "aggregators");
    for(auto& aggregators_e0 : p->aggregators) {
        auto aggregators_a0 = PUM::AddObject(aggregators_c0, PUM::ConvertToString(aggregators_e0.first).data());
        _Serialize(&(aggregators_e0.second), aggregators_a0);
    }
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize(nsContainerCodeGenerator::TProjectConfig* p, const Jobj& obj)
{
    POM::PopStr(obj, "exportDeclaration", p->exportDeclaration);
    POM::PopStr(obj, "nameSpace", p->nameSpace);
    auto mainAggregator_o0 = POM::FindObject(obj, "mainAggregator");
    _Deserialize(&(p->mainAggregator), mainAggregator_o0);
    auto containers_a0 = POM::FindObject(obj, "containers");
    for(auto& containers_e0 : containers_a0) {
        auto containers_o1 = containers_e0.value.GetObject();
        nsContainerCodeGenerator::TCodeGenerationResultList containers_c1;
        _Deserialize(&containers_c1, containers_o1);
        p->containers.insert({ containers_e0.name.GetString(), containers_c1 });
    }
    auto aggregators_a0 = POM::FindObject(obj, "aggregators");
    for(auto& aggregators_e0 : aggregators_a0) {
        auto aggregators_o1 = aggregators_e0.value.GetObject();
        nsContainerCodeGenerator::TCodeGenerationResultList aggregators_c1;
        _Deserialize(&aggregators_c1, aggregators_o1);
        p->aggregators.insert({ aggregators_e0.name.GetString(), aggregators_c1 });
    }
}
//---------------------------------------------------------------------------------------
