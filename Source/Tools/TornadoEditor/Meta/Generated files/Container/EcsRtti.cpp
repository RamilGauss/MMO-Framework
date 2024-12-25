/*
Project Ecs System
*/
// ReflectionCodeGenerator version 2.5.0, build 59 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, RTTI, TypeInformation]
// File has been generated at 2024_12_25 11:43:22.866
#include "EcsRtti.h"

#include "Base/Common/SingletonManager.h"
#include "Base/Common/RunTimeTypeIndex.h"

using namespace nsTornadoEditor;

std::list<std::string> TEcsRtti::mTypeNameList;
std::list<int> TEcsRtti::mRttiList;

std::vector<std::string> TEcsRtti::mNameVector;
std::unordered_map<std::string, int> TEcsRtti::mNameRttiMap;

void TEcsRtti::Init()
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
    
    int nsTornadoEditor_TBootstrapperFeature_i = globalTypeIdentifier->Type<nsTornadoEditor::TBootstrapperFeature>();
    std::string nsTornadoEditor_TBootstrapperFeature_n = "nsTornadoEditor::TBootstrapperFeature";
    mTypeNameList.push_back(nsTornadoEditor_TBootstrapperFeature_n);
    mRttiList.push_back(nsTornadoEditor_TBootstrapperFeature_i);
    mNameRttiMap.insert({ nsTornadoEditor_TBootstrapperFeature_n, nsTornadoEditor_TBootstrapperFeature_i });
    
    int nsTornadoEditor_TBootstrapperSystem_i = globalTypeIdentifier->Type<nsTornadoEditor::TBootstrapperSystem>();
    std::string nsTornadoEditor_TBootstrapperSystem_n = "nsTornadoEditor::TBootstrapperSystem";
    mTypeNameList.push_back(nsTornadoEditor_TBootstrapperSystem_n);
    mRttiList.push_back(nsTornadoEditor_TBootstrapperSystem_i);
    mNameRttiMap.insert({ nsTornadoEditor_TBootstrapperSystem_n, nsTornadoEditor_TBootstrapperSystem_i });
    
    int nsTornadoEditor_TFileHierarchyWindowInitSystem_i = globalTypeIdentifier->Type<nsTornadoEditor::TFileHierarchyWindowInitSystem>();
    std::string nsTornadoEditor_TFileHierarchyWindowInitSystem_n = "nsTornadoEditor::TFileHierarchyWindowInitSystem";
    mTypeNameList.push_back(nsTornadoEditor_TFileHierarchyWindowInitSystem_n);
    mRttiList.push_back(nsTornadoEditor_TFileHierarchyWindowInitSystem_i);
    mNameRttiMap.insert({ nsTornadoEditor_TFileHierarchyWindowInitSystem_n, nsTornadoEditor_TFileHierarchyWindowInitSystem_i });
    
    int nsTornadoEditor_TFileHierarchyWindowRefreshSystem_i = globalTypeIdentifier->Type<nsTornadoEditor::TFileHierarchyWindowRefreshSystem>();
    std::string nsTornadoEditor_TFileHierarchyWindowRefreshSystem_n = "nsTornadoEditor::TFileHierarchyWindowRefreshSystem";
    mTypeNameList.push_back(nsTornadoEditor_TFileHierarchyWindowRefreshSystem_n);
    mRttiList.push_back(nsTornadoEditor_TFileHierarchyWindowRefreshSystem_i);
    mNameRttiMap.insert({ nsTornadoEditor_TFileHierarchyWindowRefreshSystem_n, nsTornadoEditor_TFileHierarchyWindowRefreshSystem_i });
    
    int nsTornadoEditor_TInitWindowsFeature_i = globalTypeIdentifier->Type<nsTornadoEditor::TInitWindowsFeature>();
    std::string nsTornadoEditor_TInitWindowsFeature_n = "nsTornadoEditor::TInitWindowsFeature";
    mTypeNameList.push_back(nsTornadoEditor_TInitWindowsFeature_n);
    mRttiList.push_back(nsTornadoEditor_TInitWindowsFeature_i);
    mNameRttiMap.insert({ nsTornadoEditor_TInitWindowsFeature_n, nsTornadoEditor_TInitWindowsFeature_i });
    
    int nsTornadoEditor_TMainFeature_i = globalTypeIdentifier->Type<nsTornadoEditor::TMainFeature>();
    std::string nsTornadoEditor_TMainFeature_n = "nsTornadoEditor::TMainFeature";
    mTypeNameList.push_back(nsTornadoEditor_TMainFeature_n);
    mRttiList.push_back(nsTornadoEditor_TMainFeature_i);
    mNameRttiMap.insert({ nsTornadoEditor_TMainFeature_n, nsTornadoEditor_TMainFeature_i });
    
    int nsTornadoEditor_TObjectHierarchyWindowInitSystem_i = globalTypeIdentifier->Type<nsTornadoEditor::TObjectHierarchyWindowInitSystem>();
    std::string nsTornadoEditor_TObjectHierarchyWindowInitSystem_n = "nsTornadoEditor::TObjectHierarchyWindowInitSystem";
    mTypeNameList.push_back(nsTornadoEditor_TObjectHierarchyWindowInitSystem_n);
    mRttiList.push_back(nsTornadoEditor_TObjectHierarchyWindowInitSystem_i);
    mNameRttiMap.insert({ nsTornadoEditor_TObjectHierarchyWindowInitSystem_n, nsTornadoEditor_TObjectHierarchyWindowInitSystem_i });
    
    int nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_i = globalTypeIdentifier->Type<nsTornadoEditor::TObjectHierarchyWindowRefreshSystem>();
    std::string nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_n = "nsTornadoEditor::TObjectHierarchyWindowRefreshSystem";
    mTypeNameList.push_back(nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_n);
    mRttiList.push_back(nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_i);
    mNameRttiMap.insert({ nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_n, nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_i });
    
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
const std::list<std::string>* TEcsRtti::GetTypeNameList()
{
    Init();
    return &mTypeNameList;
}
//---------------------------------------------------------------------------------------
const std::list<int>* TEcsRtti::GetRttiList()
{
    Init();
    return &mRttiList;
}
//---------------------------------------------------------------------------------------
const std::string* TEcsRtti::ConvertRttiToName(int rtti)
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
bool TEcsRtti::ConvertNameToRtti(const std::string& typeName, int& rtti)
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
