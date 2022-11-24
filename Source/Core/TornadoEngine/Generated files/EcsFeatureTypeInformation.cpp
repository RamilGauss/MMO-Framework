/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.4.0, build 58 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, TypeInformation]
// File has been generated at 2022_11_23 16:57:56.036
	
#include "EcsFeatureTypeInformation.h"

#include "SingletonManager.h"
#include "RunTimeTypeIndex.h"

using namespace nsTornadoEngine;

std::list<std::string> TEcsFeatureTypeInformation::mTypeNameList;
std::list<int> TEcsFeatureTypeInformation::mRttiList;

std::vector<std::string> TEcsFeatureTypeInformation::mNameVector;
std::map<std::string, int> TEcsFeatureTypeInformation::mNameRttiMap;

void TEcsFeatureTypeInformation::Init()
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
    
    int nsECSFramework_TExecuteSystem_i = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    std::string nsECSFramework_TExecuteSystem_n = "nsECSFramework::TExecuteSystem";
    mTypeNameList.push_back(nsECSFramework_TExecuteSystem_n);
    mRttiList.push_back(nsECSFramework_TExecuteSystem_i);
    mNameRttiMap.insert({ nsECSFramework_TExecuteSystem_n, nsECSFramework_TExecuteSystem_i });
    
    int nsECSFramework_TFeature_i = globalTypeIdentifier->Type<nsECSFramework::TFeature>();
    std::string nsECSFramework_TFeature_n = "nsECSFramework::TFeature";
    mTypeNameList.push_back(nsECSFramework_TFeature_n);
    mRttiList.push_back(nsECSFramework_TFeature_i);
    mNameRttiMap.insert({ nsECSFramework_TFeature_n, nsECSFramework_TFeature_i });
    
    int nsECSFramework_TSystem_i = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    std::string nsECSFramework_TSystem_n = "nsECSFramework::TSystem";
    mTypeNameList.push_back(nsECSFramework_TSystem_n);
    mRttiList.push_back(nsECSFramework_TSystem_i);
    mNameRttiMap.insert({ nsECSFramework_TSystem_n, nsECSFramework_TSystem_i });
    
    int nsECSFramework_TTearDownSystem_i = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    std::string nsECSFramework_TTearDownSystem_n = "nsECSFramework::TTearDownSystem";
    mTypeNameList.push_back(nsECSFramework_TTearDownSystem_n);
    mRttiList.push_back(nsECSFramework_TTearDownSystem_i);
    mNameRttiMap.insert({ nsECSFramework_TTearDownSystem_n, nsECSFramework_TTearDownSystem_i });
    
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
const std::list<std::string>* TEcsFeatureTypeInformation::GetTypeNameList()
{
    Init();
    return &mTypeNameList;
}
//---------------------------------------------------------------------------------------
const std::list<int>* TEcsFeatureTypeInformation::GetRttiList()
{
    Init();
    return &mRttiList;
}
//---------------------------------------------------------------------------------------
const std::string* TEcsFeatureTypeInformation::ConvertRttiToName(int rtti)
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
bool TEcsFeatureTypeInformation::ConvertNameToRtti(const std::string& typeName, int& rtti)
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
