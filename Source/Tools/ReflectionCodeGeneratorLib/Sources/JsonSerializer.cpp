/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.4.0, build 58 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, TypeInformation]
// File has been generated at 2022_12_23 17:27:34.484
	
#include "JsonSerializer.h"
#include "JsonPopMaster.h"
#include "JsonPushMaster.h"
#include "SingletonManager.h"
#include "RunTimeTypeIndex.h"

using namespace nsJson;

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
    
    TypeFunc _nsReflectionCodeGenerator_TClassDescTypeFunc;
    _nsReflectionCodeGenerator_TClassDescTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsReflectionCodeGenerator::TClassDesc>((nsReflectionCodeGenerator::TClassDesc*) p, str);
    };
    _nsReflectionCodeGenerator_TClassDescTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsReflectionCodeGenerator::TClassDesc>((nsReflectionCodeGenerator::TClassDesc*) p, str, err);
    };
    
    auto rtti__nsReflectionCodeGenerator_TClassDescTypeFunc = globalTypeIdentifier->Type<nsReflectionCodeGenerator::TClassDesc>();
    
    m.insert({ rtti__nsReflectionCodeGenerator_TClassDescTypeFunc, _nsReflectionCodeGenerator_TClassDescTypeFunc });
    
    TypeFunc _nsReflectionCodeGenerator_TConfigTypeFunc;
    _nsReflectionCodeGenerator_TConfigTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsReflectionCodeGenerator::TConfig>((nsReflectionCodeGenerator::TConfig*) p, str);
    };
    _nsReflectionCodeGenerator_TConfigTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsReflectionCodeGenerator::TConfig>((nsReflectionCodeGenerator::TConfig*) p, str, err);
    };
    
    auto rtti__nsReflectionCodeGenerator_TConfigTypeFunc = globalTypeIdentifier->Type<nsReflectionCodeGenerator::TConfig>();
    
    m.insert({ rtti__nsReflectionCodeGenerator_TConfigTypeFunc, _nsReflectionCodeGenerator_TConfigTypeFunc });
    
    TypeFunc _nsReflectionCodeGenerator_TExternalSourceTypeFunc;
    _nsReflectionCodeGenerator_TExternalSourceTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsReflectionCodeGenerator::TExternalSource>((nsReflectionCodeGenerator::TExternalSource*) p, str);
    };
    _nsReflectionCodeGenerator_TExternalSourceTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsReflectionCodeGenerator::TExternalSource>((nsReflectionCodeGenerator::TExternalSource*) p, str, err);
    };
    
    auto rtti__nsReflectionCodeGenerator_TExternalSourceTypeFunc = globalTypeIdentifier->Type<nsReflectionCodeGenerator::TExternalSource>();
    
    m.insert({ rtti__nsReflectionCodeGenerator_TExternalSourceTypeFunc, _nsReflectionCodeGenerator_TExternalSourceTypeFunc });
    
    TypeFunc _nsReflectionCodeGenerator_TExternalSourcesTypeFunc;
    _nsReflectionCodeGenerator_TExternalSourcesTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsReflectionCodeGenerator::TExternalSources>((nsReflectionCodeGenerator::TExternalSources*) p, str);
    };
    _nsReflectionCodeGenerator_TExternalSourcesTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsReflectionCodeGenerator::TExternalSources>((nsReflectionCodeGenerator::TExternalSources*) p, str, err);
    };
    
    auto rtti__nsReflectionCodeGenerator_TExternalSourcesTypeFunc = globalTypeIdentifier->Type<nsReflectionCodeGenerator::TExternalSources>();
    
    m.insert({ rtti__nsReflectionCodeGenerator_TExternalSourcesTypeFunc, _nsReflectionCodeGenerator_TExternalSourcesTypeFunc });
    
    TypeFunc _nsReflectionCodeGenerator_TFilterTypeFunc;
    _nsReflectionCodeGenerator_TFilterTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsReflectionCodeGenerator::TFilter>((nsReflectionCodeGenerator::TFilter*) p, str);
    };
    _nsReflectionCodeGenerator_TFilterTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsReflectionCodeGenerator::TFilter>((nsReflectionCodeGenerator::TFilter*) p, str, err);
    };
    
    auto rtti__nsReflectionCodeGenerator_TFilterTypeFunc = globalTypeIdentifier->Type<nsReflectionCodeGenerator::TFilter>();
    
    m.insert({ rtti__nsReflectionCodeGenerator_TFilterTypeFunc, _nsReflectionCodeGenerator_TFilterTypeFunc });
    
    TypeFunc _nsReflectionCodeGenerator_TIncludeListParamsTypeFunc;
    _nsReflectionCodeGenerator_TIncludeListParamsTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsReflectionCodeGenerator::TIncludeListParams>((nsReflectionCodeGenerator::TIncludeListParams*) p, str);
    };
    _nsReflectionCodeGenerator_TIncludeListParamsTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsReflectionCodeGenerator::TIncludeListParams>((nsReflectionCodeGenerator::TIncludeListParams*) p, str, err);
    };
    
    auto rtti__nsReflectionCodeGenerator_TIncludeListParamsTypeFunc = globalTypeIdentifier->Type<nsReflectionCodeGenerator::TIncludeListParams>();
    
    m.insert({ rtti__nsReflectionCodeGenerator_TIncludeListParamsTypeFunc, _nsReflectionCodeGenerator_TIncludeListParamsTypeFunc });
    
    TypeFunc _nsReflectionCodeGenerator_TSerializerTypeFunc;
    _nsReflectionCodeGenerator_TSerializerTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsReflectionCodeGenerator::TSerializer>((nsReflectionCodeGenerator::TSerializer*) p, str);
    };
    _nsReflectionCodeGenerator_TSerializerTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsReflectionCodeGenerator::TSerializer>((nsReflectionCodeGenerator::TSerializer*) p, str, err);
    };
    
    auto rtti__nsReflectionCodeGenerator_TSerializerTypeFunc = globalTypeIdentifier->Type<nsReflectionCodeGenerator::TSerializer>();
    
    m.insert({ rtti__nsReflectionCodeGenerator_TSerializerTypeFunc, _nsReflectionCodeGenerator_TSerializerTypeFunc });
    
    TypeFunc _nsReflectionCodeGenerator_TTargetForCodeGenerationTypeFunc;
    _nsReflectionCodeGenerator_TTargetForCodeGenerationTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsReflectionCodeGenerator::TTargetForCodeGeneration>((nsReflectionCodeGenerator::TTargetForCodeGeneration*) p, str);
    };
    _nsReflectionCodeGenerator_TTargetForCodeGenerationTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsReflectionCodeGenerator::TTargetForCodeGeneration>((nsReflectionCodeGenerator::TTargetForCodeGeneration*) p, str, err);
    };
    
    auto rtti__nsReflectionCodeGenerator_TTargetForCodeGenerationTypeFunc = globalTypeIdentifier->Type<nsReflectionCodeGenerator::TTargetForCodeGeneration>();
    
    m.insert({ rtti__nsReflectionCodeGenerator_TTargetForCodeGenerationTypeFunc, _nsReflectionCodeGenerator_TTargetForCodeGenerationTypeFunc });
    
    TypeFunc _nsReflectionCodeGenerator_TTargetForParsingTypeFunc;
    _nsReflectionCodeGenerator_TTargetForParsingTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsReflectionCodeGenerator::TTargetForParsing>((nsReflectionCodeGenerator::TTargetForParsing*) p, str);
    };
    _nsReflectionCodeGenerator_TTargetForParsingTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsReflectionCodeGenerator::TTargetForParsing>((nsReflectionCodeGenerator::TTargetForParsing*) p, str, err);
    };
    
    auto rtti__nsReflectionCodeGenerator_TTargetForParsingTypeFunc = globalTypeIdentifier->Type<nsReflectionCodeGenerator::TTargetForParsing>();
    
    m.insert({ rtti__nsReflectionCodeGenerator_TTargetForParsingTypeFunc, _nsReflectionCodeGenerator_TTargetForParsingTypeFunc });
    
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
std::string TJsonSerializer::_SerializeEnum(nsCppParser::TypeCategory* p)
{
    switch (*p) {
        case nsCppParser::TypeCategory::ARRAY:
            return "ARRAY";
        case nsCppParser::TypeCategory::BOOL:
            return "BOOL";
        case nsCppParser::TypeCategory::CEIL_NUMBER:
            return "CEIL_NUMBER";
        case nsCppParser::TypeCategory::LIST:
            return "LIST";
        case nsCppParser::TypeCategory::MAP:
            return "MAP";
        case nsCppParser::TypeCategory::NUMBER:
            return "NUMBER";
        case nsCppParser::TypeCategory::REFLECTION:
            return "REFLECTION";
        case nsCppParser::TypeCategory::SET:
            return "SET";
        case nsCppParser::TypeCategory::SMART_POINTER:
            return "SMART_POINTER";
        case nsCppParser::TypeCategory::STRING:
            return "STRING";
        case nsCppParser::TypeCategory::VECTOR:
            return "VECTOR";
        default:;
    }
    return "";
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_DeserializeEnum(std::string& str, nsCppParser::TypeCategory* p)
{
    std::map<std::string, nsCppParser::TypeCategory> m;
    m.insert({"ARRAY", nsCppParser::TypeCategory::ARRAY});
    m.insert({"BOOL", nsCppParser::TypeCategory::BOOL});
    m.insert({"CEIL_NUMBER", nsCppParser::TypeCategory::CEIL_NUMBER});
    m.insert({"LIST", nsCppParser::TypeCategory::LIST});
    m.insert({"MAP", nsCppParser::TypeCategory::MAP});
    m.insert({"NUMBER", nsCppParser::TypeCategory::NUMBER});
    m.insert({"REFLECTION", nsCppParser::TypeCategory::REFLECTION});
    m.insert({"SET", nsCppParser::TypeCategory::SET});
    m.insert({"SMART_POINTER", nsCppParser::TypeCategory::SMART_POINTER});
    m.insert({"STRING", nsCppParser::TypeCategory::STRING});
    m.insert({"VECTOR", nsCppParser::TypeCategory::VECTOR});
    *p = m[str];
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize(nsReflectionCodeGenerator::TClassDesc* p, Jobj& obj)
{
    PUM::Push(obj, "exportDeclaration", p->exportDeclaration);
    PUM::Push(obj, "nameSpaceName", p->nameSpaceName);
    PUM::Push(obj, "className", p->className);
    PUM::Push(obj, "fileName", p->fileName);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize(nsReflectionCodeGenerator::TClassDesc* p, const Jobj& obj)
{
    POM::PopStr(obj, "exportDeclaration", p->exportDeclaration);
    POM::PopStr(obj, "nameSpaceName", p->nameSpaceName);
    POM::PopStr(obj, "className", p->className);
    POM::PopStr(obj, "fileName", p->fileName);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize(nsReflectionCodeGenerator::TConfig* p, Jobj& obj)
{
    auto targetForParsing_o = PUM::AddObject(obj, "targetForParsing");
    _Serialize(&(p->targetForParsing), targetForParsing_o);
    auto filter_o = PUM::AddObject(obj, "filter");
    _Serialize(&(p->filter), filter_o);
    auto targetForCodeGeneration_o = PUM::AddObject(obj, "targetForCodeGeneration");
    _Serialize(&(p->targetForCodeGeneration), targetForCodeGeneration_o);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize(nsReflectionCodeGenerator::TConfig* p, const Jobj& obj)
{
    auto targetForParsing_o0 = POM::FindObject(obj, "targetForParsing");
    _Deserialize(&(p->targetForParsing), targetForParsing_o0);
    auto filter_o0 = POM::FindObject(obj, "filter");
    _Deserialize(&(p->filter), filter_o0);
    auto targetForCodeGeneration_o0 = POM::FindObject(obj, "targetForCodeGeneration");
    _Deserialize(&(p->targetForCodeGeneration), targetForCodeGeneration_o0);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize(nsReflectionCodeGenerator::TExternalSource* p, Jobj& obj)
{
    PUM::Push(obj, "fileName", p->fileName);
    PUM::Push(obj, "nameSpaceName", p->nameSpaceName);
    PUM::Push(obj, "typeName", p->typeName);
    PUM::Value customizedTypes_a0(rapidjson::kArrayType);
    for(auto& customizedTypes_e0 : p->customizedTypes) {
        PUM::PushBack(customizedTypes_a0, customizedTypes_e0);
    }
    PUM::Push(obj, "customizedTypes", customizedTypes_a0);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize(nsReflectionCodeGenerator::TExternalSource* p, const Jobj& obj)
{
    POM::PopStr(obj, "fileName", p->fileName);
    POM::PopStr(obj, "nameSpaceName", p->nameSpaceName);
    POM::PopStr(obj, "typeName", p->typeName);
    if (POM::IsArray(obj, "customizedTypes")) {
        auto customizedTypes_a0 = POM::FindArray(obj, "customizedTypes");
        for(auto& customizedTypes_e0 : customizedTypes_a0) {
            p->customizedTypes.insert(customizedTypes_e0.GetString());
        }
    } else {
        std::string customizedTypes_t0;
        POM::PopStr(obj, "customizedTypes", customizedTypes_t0);
        p->customizedTypes.insert(customizedTypes_t0);
    }
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize(nsReflectionCodeGenerator::TExternalSources* p, Jobj& obj)
{
    PUM::Value inFileList_a0(rapidjson::kArrayType);
    for(auto& inFileList_e0 : p->inFileList) {
        PUM::PushBack(inFileList_a0, inFileList_e0);
    }
    PUM::Push(obj, "inFileList", inFileList_a0);
    PUM::Push(obj, "outFile", p->outFile);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize(nsReflectionCodeGenerator::TExternalSources* p, const Jobj& obj)
{
    if (POM::IsArray(obj, "inFileList")) {
        auto inFileList_a0 = POM::FindArray(obj, "inFileList");
        for(auto& inFileList_e0 : inFileList_a0) {
            p->inFileList.push_back(inFileList_e0.GetString());
        }
    } else {
        std::string inFileList_t0;
        POM::PopStr(obj, "inFileList", inFileList_t0);
        p->inFileList.push_back(inFileList_t0);
    }
    POM::PopStr(obj, "outFile", p->outFile);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize(nsReflectionCodeGenerator::TFilter* p, Jobj& obj)
{
    PUM::Value extensions_a0(rapidjson::kArrayType);
    for(size_t extensions_i0 = 0 ; extensions_i0 < p->extensions.size() ; extensions_i0++) {
        auto& extensions_e0 = p->extensions[extensions_i0];
        PUM::PushBack(extensions_a0, extensions_e0);
    }
    PUM::Push(obj, "extensions", extensions_a0);
    PUM::Push(obj, "attribute", p->attribute);
    PUM::Value inheritances_a0(rapidjson::kArrayType);
    for(auto& inheritances_e0 : p->inheritances) {
        PUM::Value inheritances_a1(rapidjson::kArrayType);
        for(auto& inheritances_e1 : inheritances_e0) {
            PUM::PushBack(inheritances_a1, inheritances_e1);
        }
        PUM::PushBack(inheritances_a0, inheritances_a1);
    }
    PUM::Push(obj, "inheritances", inheritances_a0);
    PUM::Push(obj, "memberIgnore", p->memberIgnore);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize(nsReflectionCodeGenerator::TFilter* p, const Jobj& obj)
{
    if (POM::IsArray(obj, "extensions")) {
        auto extensions_a0 = POM::FindArray(obj, "extensions");
        for(auto& extensions_e0 : extensions_a0) {
            p->extensions.push_back(extensions_e0.GetString());
        }
    } else {
        std::string extensions_t0;
        POM::PopStr(obj, "extensions", extensions_t0);
        p->extensions.push_back(extensions_t0);
    }
    POM::PopStr(obj, "attribute", p->attribute);
    auto inheritances_a0 = POM::FindArray(obj, "inheritances");
    for(auto& inheritances_e0 : inheritances_a0) {
        if (inheritances_e0.IsArray()) {
            std::list<std::string> inheritances_c1;
            auto inheritances_a1 = inheritances_e0.GetArray();
            for(auto& inheritances_e1 : inheritances_a1) {
                inheritances_c1.push_back(inheritances_e1.GetString());
            }
            p->inheritances.push_back(inheritances_c1);
        } else {
            auto inheritances_t1 = inheritances_e0.GetString();
            std::list<std::string> inheritances_c1;
            inheritances_c1.push_back(inheritances_t1);
            p->inheritances.push_back(inheritances_c1);
        }
    }
    POM::PopStr(obj, "memberIgnore", p->memberIgnore);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize(nsReflectionCodeGenerator::TIncludeListParams* p, Jobj& obj)
{
    PUM::Push(obj, "includeListFileName", p->includeListFileName);
    PUM::Value dirToInclude_a0(rapidjson::kArrayType);
    for(auto& dirToInclude_e0 : p->dirToInclude) {
        PUM::PushBack(dirToInclude_a0, dirToInclude_e0);
    }
    PUM::Push(obj, "dirToInclude", dirToInclude_a0);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize(nsReflectionCodeGenerator::TIncludeListParams* p, const Jobj& obj)
{
    POM::PopStr(obj, "includeListFileName", p->includeListFileName);
    if (POM::IsArray(obj, "dirToInclude")) {
        auto dirToInclude_a0 = POM::FindArray(obj, "dirToInclude");
        for(auto& dirToInclude_e0 : dirToInclude_a0) {
            p->dirToInclude.push_back(dirToInclude_e0.GetString());
        }
    } else {
        std::string dirToInclude_t0;
        POM::PopStr(obj, "dirToInclude", dirToInclude_t0);
        p->dirToInclude.push_back(dirToInclude_t0);
    }
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize(nsReflectionCodeGenerator::TSerializer* p, Jobj& obj)
{
    _Serialize((nsReflectionCodeGenerator::TClassDesc*)p, obj);// Inheritances
    if (p->externalSources.get() == nullptr) {
        PUM::PushNull(obj, "externalSources");
    } else {
        auto externalSources_o = PUM::AddObject(obj, "externalSources");
        _Serialize(p->externalSources.get(), externalSources_o);
    }
    auto keyValueMap_c0 = PUM::AddObject(obj, "keyValueMap");
    for(auto& keyValueMap_e0 : p->keyValueMap) {
        PUM::Push(keyValueMap_c0, PUM::ConvertToString(keyValueMap_e0.first).data(), keyValueMap_e0.second);
    }
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize(nsReflectionCodeGenerator::TSerializer* p, const Jobj& obj)
{
    _Deserialize((nsReflectionCodeGenerator::TClassDesc*)p, obj);// Inheritances
    if (POM::IsExist(obj, "externalSources") && !POM::IsNull(obj, "externalSources" ) ) {
        if (p->externalSources.get() == nullptr) {
            p->externalSources.reset(new nsReflectionCodeGenerator::TExternalSources());
        }
        auto externalSources_o0 = POM::FindObject(obj, "externalSources");
        _Deserialize(p->externalSources.get(), externalSources_o0);
    }
    auto keyValueMap_a0 = POM::FindObject(obj, "keyValueMap");
    for(auto& keyValueMap_e0 : keyValueMap_a0) {
        p->keyValueMap.insert({ keyValueMap_e0.name.GetString(), keyValueMap_e0.value.GetString() });
    }
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize(nsReflectionCodeGenerator::TTargetForCodeGeneration* p, Jobj& obj)
{
    PUM::Push(obj, "directory", p->directory);
    PUM::Push(obj, "header", p->header);
    auto typeCustomizerMap_c0 = PUM::AddObject(obj, "typeCustomizerMap");
    for(auto& typeCustomizerMap_e0 : p->typeCustomizerMap) {
        auto typeCustomizerMap_c1 = _SerializeEnum(&typeCustomizerMap_e0.second);
        PUM::Push(typeCustomizerMap_c0, PUM::ConvertToString(typeCustomizerMap_e0.first).data(), typeCustomizerMap_c1);
    }
    PUM::Push(obj, "appendTypeCustomizerMap", p->appendTypeCustomizerMap);
    auto implementations_c0 = PUM::AddObject(obj, "implementations");
    for(auto& implementations_e0 : p->implementations) {
        auto implementations_a0 = PUM::AddObject(implementations_c0, PUM::ConvertToString(implementations_e0.first).data());
        _Serialize(&(implementations_e0.second), implementations_a0);
    }
    auto includeListParams_o = PUM::AddObject(obj, "includeListParams");
    _Serialize(&(p->includeListParams), includeListParams_o);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize(nsReflectionCodeGenerator::TTargetForCodeGeneration* p, const Jobj& obj)
{
    POM::PopStr(obj, "directory", p->directory);
    POM::PopStr(obj, "header", p->header);
    auto typeCustomizerMap_a0 = POM::FindObject(obj, "typeCustomizerMap");
    for(auto& typeCustomizerMap_e0 : typeCustomizerMap_a0) {
        std::string typeCustomizerMap_o1 = typeCustomizerMap_e0.value.GetString();
        nsCppParser::TypeCategory typeCustomizerMap_c1;
        _DeserializeEnum(typeCustomizerMap_o1, &typeCustomizerMap_c1);
        p->typeCustomizerMap.insert({ typeCustomizerMap_e0.name.GetString(), typeCustomizerMap_c1 });
    }
    POM::PopBool(obj, "appendTypeCustomizerMap", p->appendTypeCustomizerMap);
    auto implementations_a0 = POM::FindObject(obj, "implementations");
    for(auto& implementations_e0 : implementations_a0) {
        auto implementations_o1 = implementations_e0.value.GetObject();
        nsReflectionCodeGenerator::TSerializer implementations_c1;
        _Deserialize(&implementations_c1, implementations_o1);
        p->implementations.insert({ implementations_e0.name.GetString(), implementations_c1 });
    }
    auto includeListParams_o0 = POM::FindObject(obj, "includeListParams");
    _Deserialize(&(p->includeListParams), includeListParams_o0);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize(nsReflectionCodeGenerator::TTargetForParsing* p, Jobj& obj)
{
    PUM::Value directories_a0(rapidjson::kArrayType);
    for(size_t directories_i0 = 0 ; directories_i0 < p->directories.size() ; directories_i0++) {
        auto& directories_e0 = p->directories[directories_i0];
        PUM::PushBack(directories_a0, directories_e0);
    }
    PUM::Push(obj, "directories", directories_a0);
    PUM::Push(obj, "recursive", p->recursive);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize(nsReflectionCodeGenerator::TTargetForParsing* p, const Jobj& obj)
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
    POM::PopBool(obj, "recursive", p->recursive);
}
//---------------------------------------------------------------------------------------
