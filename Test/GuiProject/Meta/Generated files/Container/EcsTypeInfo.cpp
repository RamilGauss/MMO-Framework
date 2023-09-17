/*
Project Ecs System
*/
// ReflectionCodeGenerator version 2.4.2, build 58 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, TypeInformation]
// File has been generated at 2023_09_17 12:05:08.730
	
#include "EcsTypeInfo.h"

#include "SingletonManager.h"
#include "RunTimeTypeIndex.h"

using namespace nsTornadoEditor;

std::list<std::string> TEcsTypeInfo::mTypeNameList;
std::list<int> TEcsTypeInfo::mRttiList;

std::vector<std::string> TEcsTypeInfo::mNameVector;
std::unordered_map<std::string, int> TEcsTypeInfo::mNameRttiMap;

void TEcsTypeInfo::Init()
{
    static bool isNeedInit = true;
    if (!isNeedInit) {
        return;
    }
    isNeedInit = false;
    
    auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();
    
    int nsECSFramework_TBaseCollectReactiveSystem_i = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    std::string nsECSFramework_TBaseCollectReactiveSystem_n = "nsECSFramework::TBaseCollectReactiveSystem";
    mTypeNameList.push_back(nsECSFramework_TBaseCollectReactiveSystem_n);
    mRttiList.push_back(nsECSFramework_TBaseCollectReactiveSystem_i);
    mNameRttiMap.insert({ nsECSFramework_TBaseCollectReactiveSystem_n, nsECSFramework_TBaseCollectReactiveSystem_i });
    
    int nsECSFramework_TBaseReactiveSystem_i = globalTypeIdentifier->Type<nsECSFramework::TBaseReactiveSystem>();
    std::string nsECSFramework_TBaseReactiveSystem_n = "nsECSFramework::TBaseReactiveSystem";
    mTypeNameList.push_back(nsECSFramework_TBaseReactiveSystem_n);
    mRttiList.push_back(nsECSFramework_TBaseReactiveSystem_i);
    mNameRttiMap.insert({ nsECSFramework_TBaseReactiveSystem_n, nsECSFramework_TBaseReactiveSystem_i });
    
    int nsECSFramework_TFeature_i = globalTypeIdentifier->Type<nsECSFramework::TFeature>();
    std::string nsECSFramework_TFeature_n = "nsECSFramework::TFeature";
    mTypeNameList.push_back(nsECSFramework_TFeature_n);
    mRttiList.push_back(nsECSFramework_TFeature_i);
    mNameRttiMap.insert({ nsECSFramework_TFeature_n, nsECSFramework_TFeature_i });
    
    int max = 0;
    for (auto& nameRtti : mNameRttiMap) {
        max = std::max(max, nameRtti.second);
    }
    mNameVector.resize(max + 1);
    for (auto& nameRtti : mNameRttiMap) {
        mNameVector[nameRtti.second] = nameRtti.first;
    }
}
//---------------------------------------------------------------------------------------
const std::list<std::string>* TEcsTypeInfo::GetTypeNameList()
{
    Init();
    return &mTypeNameList;
}
//---------------------------------------------------------------------------------------
const std::list<int>* TEcsTypeInfo::GetRttiList()
{
    Init();
    return &mRttiList;
}
//---------------------------------------------------------------------------------------
const std::string* TEcsTypeInfo::ConvertRttiToName(int rtti)
{
    Init();
    
    if (rtti < 0 || rtti >= mNameVector.size()) {
        return nullptr;
    }
    auto pStr = &(mNameVector[rtti]);
    if (pStr->size() == 0) {
        return nullptr;
    }
    return pStr;
}
//---------------------------------------------------------------------------------------
bool TEcsTypeInfo::ConvertNameToRtti(const std::string& typeName, int& rtti)
{
    Init();
    auto fit = mNameRttiMap.find(typeName);
    if (fit == mNameRttiMap.end()) {
        return false;
    }
    rtti = fit->second;
    return true;
}
//---------------------------------------------------------------------------------------
