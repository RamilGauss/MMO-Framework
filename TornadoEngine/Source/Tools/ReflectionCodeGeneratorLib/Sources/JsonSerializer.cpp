/*

*/
// ReflectionCodeGenerator version 2.0.0, build 47, info Json, Binary, EntMng, Reflection
// File has been generated at 2021_04_28 21:10:02.035
	
#include "JsonSerializer.h"
#include "JsonPopMaster.h"
#include "JsonPushMaster.h"
#include "SingletonManager.h"
#include "TypeIdentifier.h"

using namespace nsJson;

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
    TypeFunc _nsReflectionCodeGenerator_TClassDescTypeFunc;
    _nsReflectionCodeGenerator_TClassDescTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsReflectionCodeGenerator::TClassDesc>((nsReflectionCodeGenerator::TClassDesc*) p, str);
    };
    _nsReflectionCodeGenerator_TClassDescTypeFunc.deserializeFunc = [] (void*& p, const std::string& str, std::string& err) {
        return Deserialize<nsReflectionCodeGenerator::TClassDesc>((nsReflectionCodeGenerator::TClassDesc*&) p, str, err);
    };
    _nsReflectionCodeGenerator_TClassDescTypeFunc.fillFunc = [] (void* p, const std::string& str, std::string& err) {
        return Fill<nsReflectionCodeGenerator::TClassDesc>((nsReflectionCodeGenerator::TClassDesc*) p, str, err);
    };
    _nsReflectionCodeGenerator_TClassDescTypeFunc.typeIdentifier = globalTypeIdentifier->type<nsReflectionCodeGenerator::TClassDesc>();
    mTypeNameFuncsMap.insert({"nsReflectionCodeGenerator::TClassDesc", _nsReflectionCodeGenerator_TClassDescTypeFunc });
    
    TypeFunc _nsReflectionCodeGenerator_TConfigTypeFunc;
    _nsReflectionCodeGenerator_TConfigTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsReflectionCodeGenerator::TConfig>((nsReflectionCodeGenerator::TConfig*) p, str);
    };
    _nsReflectionCodeGenerator_TConfigTypeFunc.deserializeFunc = [] (void*& p, const std::string& str, std::string& err) {
        return Deserialize<nsReflectionCodeGenerator::TConfig>((nsReflectionCodeGenerator::TConfig*&) p, str, err);
    };
    _nsReflectionCodeGenerator_TConfigTypeFunc.fillFunc = [] (void* p, const std::string& str, std::string& err) {
        return Fill<nsReflectionCodeGenerator::TConfig>((nsReflectionCodeGenerator::TConfig*) p, str, err);
    };
    _nsReflectionCodeGenerator_TConfigTypeFunc.typeIdentifier = globalTypeIdentifier->type<nsReflectionCodeGenerator::TConfig>();
    mTypeNameFuncsMap.insert({"nsReflectionCodeGenerator::TConfig", _nsReflectionCodeGenerator_TConfigTypeFunc });
    
    TypeFunc _nsReflectionCodeGenerator_TExternalSourceTypeFunc;
    _nsReflectionCodeGenerator_TExternalSourceTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsReflectionCodeGenerator::TExternalSource>((nsReflectionCodeGenerator::TExternalSource*) p, str);
    };
    _nsReflectionCodeGenerator_TExternalSourceTypeFunc.deserializeFunc = [] (void*& p, const std::string& str, std::string& err) {
        return Deserialize<nsReflectionCodeGenerator::TExternalSource>((nsReflectionCodeGenerator::TExternalSource*&) p, str, err);
    };
    _nsReflectionCodeGenerator_TExternalSourceTypeFunc.fillFunc = [] (void* p, const std::string& str, std::string& err) {
        return Fill<nsReflectionCodeGenerator::TExternalSource>((nsReflectionCodeGenerator::TExternalSource*) p, str, err);
    };
    _nsReflectionCodeGenerator_TExternalSourceTypeFunc.typeIdentifier = globalTypeIdentifier->type<nsReflectionCodeGenerator::TExternalSource>();
    mTypeNameFuncsMap.insert({"nsReflectionCodeGenerator::TExternalSource", _nsReflectionCodeGenerator_TExternalSourceTypeFunc });
    
    TypeFunc _nsReflectionCodeGenerator_TExternalSourcesTypeFunc;
    _nsReflectionCodeGenerator_TExternalSourcesTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsReflectionCodeGenerator::TExternalSources>((nsReflectionCodeGenerator::TExternalSources*) p, str);
    };
    _nsReflectionCodeGenerator_TExternalSourcesTypeFunc.deserializeFunc = [] (void*& p, const std::string& str, std::string& err) {
        return Deserialize<nsReflectionCodeGenerator::TExternalSources>((nsReflectionCodeGenerator::TExternalSources*&) p, str, err);
    };
    _nsReflectionCodeGenerator_TExternalSourcesTypeFunc.fillFunc = [] (void* p, const std::string& str, std::string& err) {
        return Fill<nsReflectionCodeGenerator::TExternalSources>((nsReflectionCodeGenerator::TExternalSources*) p, str, err);
    };
    _nsReflectionCodeGenerator_TExternalSourcesTypeFunc.typeIdentifier = globalTypeIdentifier->type<nsReflectionCodeGenerator::TExternalSources>();
    mTypeNameFuncsMap.insert({"nsReflectionCodeGenerator::TExternalSources", _nsReflectionCodeGenerator_TExternalSourcesTypeFunc });
    
    TypeFunc _nsReflectionCodeGenerator_TFilterTypeFunc;
    _nsReflectionCodeGenerator_TFilterTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsReflectionCodeGenerator::TFilter>((nsReflectionCodeGenerator::TFilter*) p, str);
    };
    _nsReflectionCodeGenerator_TFilterTypeFunc.deserializeFunc = [] (void*& p, const std::string& str, std::string& err) {
        return Deserialize<nsReflectionCodeGenerator::TFilter>((nsReflectionCodeGenerator::TFilter*&) p, str, err);
    };
    _nsReflectionCodeGenerator_TFilterTypeFunc.fillFunc = [] (void* p, const std::string& str, std::string& err) {
        return Fill<nsReflectionCodeGenerator::TFilter>((nsReflectionCodeGenerator::TFilter*) p, str, err);
    };
    _nsReflectionCodeGenerator_TFilterTypeFunc.typeIdentifier = globalTypeIdentifier->type<nsReflectionCodeGenerator::TFilter>();
    mTypeNameFuncsMap.insert({"nsReflectionCodeGenerator::TFilter", _nsReflectionCodeGenerator_TFilterTypeFunc });
    
    TypeFunc _nsReflectionCodeGenerator_TSerializerTypeFunc;
    _nsReflectionCodeGenerator_TSerializerTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsReflectionCodeGenerator::TSerializer>((nsReflectionCodeGenerator::TSerializer*) p, str);
    };
    _nsReflectionCodeGenerator_TSerializerTypeFunc.deserializeFunc = [] (void*& p, const std::string& str, std::string& err) {
        return Deserialize<nsReflectionCodeGenerator::TSerializer>((nsReflectionCodeGenerator::TSerializer*&) p, str, err);
    };
    _nsReflectionCodeGenerator_TSerializerTypeFunc.fillFunc = [] (void* p, const std::string& str, std::string& err) {
        return Fill<nsReflectionCodeGenerator::TSerializer>((nsReflectionCodeGenerator::TSerializer*) p, str, err);
    };
    _nsReflectionCodeGenerator_TSerializerTypeFunc.typeIdentifier = globalTypeIdentifier->type<nsReflectionCodeGenerator::TSerializer>();
    mTypeNameFuncsMap.insert({"nsReflectionCodeGenerator::TSerializer", _nsReflectionCodeGenerator_TSerializerTypeFunc });
    
    TypeFunc _nsReflectionCodeGenerator_TTargetForCodeGenerationTypeFunc;
    _nsReflectionCodeGenerator_TTargetForCodeGenerationTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsReflectionCodeGenerator::TTargetForCodeGeneration>((nsReflectionCodeGenerator::TTargetForCodeGeneration*) p, str);
    };
    _nsReflectionCodeGenerator_TTargetForCodeGenerationTypeFunc.deserializeFunc = [] (void*& p, const std::string& str, std::string& err) {
        return Deserialize<nsReflectionCodeGenerator::TTargetForCodeGeneration>((nsReflectionCodeGenerator::TTargetForCodeGeneration*&) p, str, err);
    };
    _nsReflectionCodeGenerator_TTargetForCodeGenerationTypeFunc.fillFunc = [] (void* p, const std::string& str, std::string& err) {
        return Fill<nsReflectionCodeGenerator::TTargetForCodeGeneration>((nsReflectionCodeGenerator::TTargetForCodeGeneration*) p, str, err);
    };
    _nsReflectionCodeGenerator_TTargetForCodeGenerationTypeFunc.typeIdentifier = globalTypeIdentifier->type<nsReflectionCodeGenerator::TTargetForCodeGeneration>();
    mTypeNameFuncsMap.insert({"nsReflectionCodeGenerator::TTargetForCodeGeneration", _nsReflectionCodeGenerator_TTargetForCodeGenerationTypeFunc });
    
    TypeFunc _nsReflectionCodeGenerator_TTargetForParsingTypeFunc;
    _nsReflectionCodeGenerator_TTargetForParsingTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsReflectionCodeGenerator::TTargetForParsing>((nsReflectionCodeGenerator::TTargetForParsing*) p, str);
    };
    _nsReflectionCodeGenerator_TTargetForParsingTypeFunc.deserializeFunc = [] (void*& p, const std::string& str, std::string& err) {
        return Deserialize<nsReflectionCodeGenerator::TTargetForParsing>((nsReflectionCodeGenerator::TTargetForParsing*&) p, str, err);
    };
    _nsReflectionCodeGenerator_TTargetForParsingTypeFunc.fillFunc = [] (void* p, const std::string& str, std::string& err) {
        return Fill<nsReflectionCodeGenerator::TTargetForParsing>((nsReflectionCodeGenerator::TTargetForParsing*) p, str, err);
    };
    _nsReflectionCodeGenerator_TTargetForParsingTypeFunc.typeIdentifier = globalTypeIdentifier->type<nsReflectionCodeGenerator::TTargetForParsing>();
    mTypeNameFuncsMap.insert({"nsReflectionCodeGenerator::TTargetForParsing", _nsReflectionCodeGenerator_TTargetForParsingTypeFunc });
    
    
    int max = 0;
    for ( auto& vt : mTypeNameFuncsMap ) {
        max = std::max(vt.second.typeIdentifier, max);
    }
    
    mTypeFuncVector.resize(max + 1);
    for ( auto& vt : mTypeNameFuncsMap ) {
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
void TJsonSerializer::_Serialize( nsReflectionCodeGenerator::TClassDesc* p, Jobj& obj )
{
    PUM::Push( obj, "exportDeclaration", p->exportDeclaration );
    PUM::Push( obj, "className", p->className );
    PUM::Push( obj, "fileName", p->fileName );
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize( nsReflectionCodeGenerator::TClassDesc* p, const Jobj& obj )
{
    POM::PopStr( obj, "exportDeclaration", p->exportDeclaration );
    POM::PopStr( obj, "className", p->className );
    POM::PopStr( obj, "fileName", p->fileName );
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize( nsReflectionCodeGenerator::TConfig* p, Jobj& obj )
{
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize( nsReflectionCodeGenerator::TConfig* p, const Jobj& obj )
{
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize( nsReflectionCodeGenerator::TExternalSource* p, Jobj& obj )
{
    PUM::Push( obj, "fileName", p->fileName );
    PUM::Push( obj, "nameSpaceName", p->nameSpaceName );
    PUM::Push( obj, "typeName", p->typeName );
    PUM::Value customizedTypes_a0(rapidjson::kArrayType);
    for( auto& customizedTypes_e0 : p->customizedTypes ) {
        PUM::PushBack( customizedTypes_a0, customizedTypes_e0 );
    }
    PUM::Push(obj, "customizedTypes", customizedTypes_a0);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize( nsReflectionCodeGenerator::TExternalSource* p, const Jobj& obj )
{
    POM::PopStr( obj, "fileName", p->fileName );
    POM::PopStr( obj, "nameSpaceName", p->nameSpaceName );
    POM::PopStr( obj, "typeName", p->typeName );
    if ( POM::IsArray(obj, "customizedTypes") ) {
        auto customizedTypes_a0 = POM::FindArray(obj, "customizedTypes");
        for( auto& customizedTypes_e0 : customizedTypes_a0 ) {
            p->customizedTypes.insert(customizedTypes_e0.GetString());
        }
    } else {
        std::string customizedTypes_t0;
        POM::PopStr(obj, "customizedTypes", customizedTypes_t0);
        p->customizedTypes.insert(customizedTypes_t0);
    }
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize( nsReflectionCodeGenerator::TExternalSources* p, Jobj& obj )
{
    PUM::Value inFileList_a0(rapidjson::kArrayType);
    for( auto& inFileList_e0 : p->inFileList ) {
        PUM::PushBack( inFileList_a0, inFileList_e0 );
    }
    PUM::Push(obj, "inFileList", inFileList_a0);
    PUM::Push( obj, "outFile", p->outFile );
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize( nsReflectionCodeGenerator::TExternalSources* p, const Jobj& obj )
{
    if ( POM::IsArray(obj, "inFileList") ) {
        auto inFileList_a0 = POM::FindArray(obj, "inFileList");
        for( auto& inFileList_e0 : inFileList_a0 ) {
            p->inFileList.push_back(inFileList_e0.GetString());
        }
    } else {
        std::string inFileList_t0;
        POM::PopStr(obj, "inFileList", inFileList_t0);
        p->inFileList.push_back(inFileList_t0);
    }
    POM::PopStr( obj, "outFile", p->outFile );
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize( nsReflectionCodeGenerator::TFilter* p, Jobj& obj )
{
    PUM::Value extensions_a0(rapidjson::kArrayType);
    for( size_t extensions_i0 = 0 ; extensions_i0 < p->extensions.size() ; extensions_i0++ ) {
        auto& extensions_e0 = p->extensions[extensions_i0];
        PUM::PushBack( extensions_a0, extensions_e0 );
    }
    PUM::Push(obj, "extensions", extensions_a0);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize( nsReflectionCodeGenerator::TFilter* p, const Jobj& obj )
{
    if ( POM::IsArray(obj, "extensions") ) {
        auto extensions_a0 = POM::FindArray(obj, "extensions");
        for( auto& extensions_e0 : extensions_a0 ) {
            p->extensions.push_back(extensions_e0.GetString());
        }
    } else {
        std::string extensions_t0;
        POM::PopStr(obj, "extensions", extensions_t0);
        p->extensions.push_back(extensions_t0);
    }
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize( nsReflectionCodeGenerator::TSerializer* p, Jobj& obj )
{
    auto keyValueMap_c0 = PUM::AddObject(obj, "keyValueMap");
    for( auto& keyValueMap_e0 : p->keyValueMap ) {
        PUM::Push( keyValueMap_c0, PUM::ConvertToString(keyValueMap_e0.first).data(), keyValueMap_e0.second );
    }
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize( nsReflectionCodeGenerator::TSerializer* p, const Jobj& obj )
{
    auto keyValueMap_a0 = POM::FindObject(obj, "keyValueMap");
    for( auto& keyValueMap_e0 : keyValueMap_a0 ) {
        p->keyValueMap.insert({ keyValueMap_e0.name.GetString(), keyValueMap_e0.value.GetString() });
    }
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize( nsReflectionCodeGenerator::TTargetForCodeGeneration* p, Jobj& obj )
{
    PUM::Push( obj, "directory", p->directory );
    PUM::Push( obj, "includeListFileName", p->includeListFileName );
    PUM::Push( obj, "header", p->header );
    auto typeCustomizerMap_c0 = PUM::AddObject(obj, "typeCustomizerMap");
    for( auto& typeCustomizerMap_e0 : p->typeCustomizerMap ) {
    }
    auto implementations_c0 = PUM::AddObject(obj, "implementations");
    for( auto& implementations_e0 : p->implementations ) {
    }
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize( nsReflectionCodeGenerator::TTargetForCodeGeneration* p, const Jobj& obj )
{
    POM::PopStr( obj, "directory", p->directory );
    POM::PopStr( obj, "includeListFileName", p->includeListFileName );
    POM::PopStr( obj, "header", p->header );
    auto typeCustomizerMap_a0 = POM::FindObject(obj, "typeCustomizerMap");
    for( auto& typeCustomizerMap_e0 : typeCustomizerMap_a0 ) {
    }
    auto implementations_a0 = POM::FindObject(obj, "implementations");
    for( auto& implementations_e0 : implementations_a0 ) {
    }
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize( nsReflectionCodeGenerator::TTargetForParsing* p, Jobj& obj )
{
    PUM::Value directories_a0(rapidjson::kArrayType);
    for( size_t directories_i0 = 0 ; directories_i0 < p->directories.size() ; directories_i0++ ) {
        auto& directories_e0 = p->directories[directories_i0];
        PUM::PushBack( directories_a0, directories_e0 );
    }
    PUM::Push(obj, "directories", directories_a0);
    PUM::Push( obj, "recursive", p->recursive );
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize( nsReflectionCodeGenerator::TTargetForParsing* p, const Jobj& obj )
{
    if ( POM::IsArray(obj, "directories") ) {
        auto directories_a0 = POM::FindArray(obj, "directories");
        for( auto& directories_e0 : directories_a0 ) {
            p->directories.push_back(directories_e0.GetString());
        }
    } else {
        std::string directories_t0;
        POM::PopStr(obj, "directories", directories_t0);
        p->directories.push_back(directories_t0);
    }
    POM::PopBool( obj, "recursive", p->recursive );
}
//---------------------------------------------------------------------------------------
