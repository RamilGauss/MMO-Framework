/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.3.0, build 57 [Json, Binary, ImGui, EcsComponentExtension, EcsSystemExtension, Reflection, TypeInformation]
// File has been generated at 2022_10_03 16:46:33.655
	
#include "FeatureTypeInformation.h"

#include "SingletonManager.h"
#include "RunTimeTypeIndex.h"

using namespace nsTornadoEditor;

std::list<std::string> TFeatureTypeInformation::mTypeNameList;
std::list<int> TFeatureTypeInformation::mRttiList;

std::vector<std::string> TFeatureTypeInformation::mNameVector;
std::map<std::string, int> TFeatureTypeInformation::mNameRttiMap;

void TFeatureTypeInformation::Init()
{
    static bool isNeedInit = true;
    if (!isNeedInit) {
        return;
    }
    isNeedInit = false;
    
    auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();
    
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
const std::list<std::string>* TFeatureTypeInformation::GetTypeNameList()
{
    Init();
    return &mTypeNameList;
}
//---------------------------------------------------------------------------------------
const std::list<int>* TFeatureTypeInformation::GetRttiList()
{
    Init();
    return &mRttiList;
}
//---------------------------------------------------------------------------------------
const std::string* TFeatureTypeInformation::ConvertRttiToName(int rtti)
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
bool TFeatureTypeInformation::ConvertNameToRtti(const std::string& typeName, int& rtti)
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
