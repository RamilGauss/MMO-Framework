/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.2.3, build 54 [Json, Binary, ImGui, EntityManager, Reflection, TypeInformation]
// File has been generated at 2021_12_07 19:36:17.384
	
#include "FeatureTypeInformation.h"

#include "SingletonManager.h"
#include "RunTimeTypeIndex.h"

using namespace nsTornadoEngine;

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
    
    int nsGraphicWrapper_TBeginGraphicFeature_i = globalTypeIdentifier->type<nsGraphicWrapper::TBeginGraphicFeature>();
    std::string nsGraphicWrapper_TBeginGraphicFeature_n = "nsGraphicWrapper::TBeginGraphicFeature";
    mTypeNameList.push_back(nsGraphicWrapper_TBeginGraphicFeature_n);
    mRttiList.push_back(nsGraphicWrapper_TBeginGraphicFeature_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TBeginGraphicFeature_n, nsGraphicWrapper_TBeginGraphicFeature_i });
    
    int nsGraphicWrapper_TEndGraphicFeature_i = globalTypeIdentifier->type<nsGraphicWrapper::TEndGraphicFeature>();
    std::string nsGraphicWrapper_TEndGraphicFeature_n = "nsGraphicWrapper::TEndGraphicFeature";
    mTypeNameList.push_back(nsGraphicWrapper_TEndGraphicFeature_n);
    mRttiList.push_back(nsGraphicWrapper_TEndGraphicFeature_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TEndGraphicFeature_n, nsGraphicWrapper_TEndGraphicFeature_i });
    
    int nsGraphicWrapper_TGuiBuilderFeature_i = globalTypeIdentifier->type<nsGraphicWrapper::TGuiBuilderFeature>();
    std::string nsGraphicWrapper_TGuiBuilderFeature_n = "nsGraphicWrapper::TGuiBuilderFeature";
    mTypeNameList.push_back(nsGraphicWrapper_TGuiBuilderFeature_n);
    mRttiList.push_back(nsGraphicWrapper_TGuiBuilderFeature_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TGuiBuilderFeature_n, nsGraphicWrapper_TGuiBuilderFeature_i });
    
    int nsGraphicWrapper_TGuiMakerFeature_i = globalTypeIdentifier->type<nsGraphicWrapper::TGuiMakerFeature>();
    std::string nsGraphicWrapper_TGuiMakerFeature_n = "nsGraphicWrapper::TGuiMakerFeature";
    mTypeNameList.push_back(nsGraphicWrapper_TGuiMakerFeature_n);
    mRttiList.push_back(nsGraphicWrapper_TGuiMakerFeature_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TGuiMakerFeature_n, nsGraphicWrapper_TGuiMakerFeature_i });
    
    int nsGraphicWrapper_TGuiTerminatorFeature_i = globalTypeIdentifier->type<nsGraphicWrapper::TGuiTerminatorFeature>();
    std::string nsGraphicWrapper_TGuiTerminatorFeature_n = "nsGraphicWrapper::TGuiTerminatorFeature";
    mTypeNameList.push_back(nsGraphicWrapper_TGuiTerminatorFeature_n);
    mRttiList.push_back(nsGraphicWrapper_TGuiTerminatorFeature_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TGuiTerminatorFeature_n, nsGraphicWrapper_TGuiTerminatorFeature_i });
    
    int nsGraphicWrapper_TGuiUpdaterFeature_i = globalTypeIdentifier->type<nsGraphicWrapper::TGuiUpdaterFeature>();
    std::string nsGraphicWrapper_TGuiUpdaterFeature_n = "nsGraphicWrapper::TGuiUpdaterFeature";
    mTypeNameList.push_back(nsGraphicWrapper_TGuiUpdaterFeature_n);
    mRttiList.push_back(nsGraphicWrapper_TGuiUpdaterFeature_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TGuiUpdaterFeature_n, nsGraphicWrapper_TGuiUpdaterFeature_i });
    
    int nsLogicWrapper_TBeginLogicFeature_i = globalTypeIdentifier->type<nsLogicWrapper::TBeginLogicFeature>();
    std::string nsLogicWrapper_TBeginLogicFeature_n = "nsLogicWrapper::TBeginLogicFeature";
    mTypeNameList.push_back(nsLogicWrapper_TBeginLogicFeature_n);
    mRttiList.push_back(nsLogicWrapper_TBeginLogicFeature_i);
    mNameRttiMap.insert({ nsLogicWrapper_TBeginLogicFeature_n, nsLogicWrapper_TBeginLogicFeature_i });
    
    int nsLogicWrapper_TEndLogicFeature_i = globalTypeIdentifier->type<nsLogicWrapper::TEndLogicFeature>();
    std::string nsLogicWrapper_TEndLogicFeature_n = "nsLogicWrapper::TEndLogicFeature";
    mTypeNameList.push_back(nsLogicWrapper_TEndLogicFeature_n);
    mRttiList.push_back(nsLogicWrapper_TEndLogicFeature_i);
    mNameRttiMap.insert({ nsLogicWrapper_TEndLogicFeature_n, nsLogicWrapper_TEndLogicFeature_i });
    
    int nsLogicWrapper_TLogicBuilderFeature_i = globalTypeIdentifier->type<nsLogicWrapper::TLogicBuilderFeature>();
    std::string nsLogicWrapper_TLogicBuilderFeature_n = "nsLogicWrapper::TLogicBuilderFeature";
    mTypeNameList.push_back(nsLogicWrapper_TLogicBuilderFeature_n);
    mRttiList.push_back(nsLogicWrapper_TLogicBuilderFeature_i);
    mNameRttiMap.insert({ nsLogicWrapper_TLogicBuilderFeature_n, nsLogicWrapper_TLogicBuilderFeature_i });
    
    int nsLogicWrapper_TLogicMakerFeature_i = globalTypeIdentifier->type<nsLogicWrapper::TLogicMakerFeature>();
    std::string nsLogicWrapper_TLogicMakerFeature_n = "nsLogicWrapper::TLogicMakerFeature";
    mTypeNameList.push_back(nsLogicWrapper_TLogicMakerFeature_n);
    mRttiList.push_back(nsLogicWrapper_TLogicMakerFeature_i);
    mNameRttiMap.insert({ nsLogicWrapper_TLogicMakerFeature_n, nsLogicWrapper_TLogicMakerFeature_i });
    
    int nsLogicWrapper_TLogicTerminatorFeature_i = globalTypeIdentifier->type<nsLogicWrapper::TLogicTerminatorFeature>();
    std::string nsLogicWrapper_TLogicTerminatorFeature_n = "nsLogicWrapper::TLogicTerminatorFeature";
    mTypeNameList.push_back(nsLogicWrapper_TLogicTerminatorFeature_n);
    mRttiList.push_back(nsLogicWrapper_TLogicTerminatorFeature_i);
    mNameRttiMap.insert({ nsLogicWrapper_TLogicTerminatorFeature_n, nsLogicWrapper_TLogicTerminatorFeature_i });
    
    int nsLogicWrapper_TSceneFeature_i = globalTypeIdentifier->type<nsLogicWrapper::TSceneFeature>();
    std::string nsLogicWrapper_TSceneFeature_n = "nsLogicWrapper::TSceneFeature";
    mTypeNameList.push_back(nsLogicWrapper_TSceneFeature_n);
    mRttiList.push_back(nsLogicWrapper_TSceneFeature_i);
    mNameRttiMap.insert({ nsLogicWrapper_TSceneFeature_n, nsLogicWrapper_TSceneFeature_i });
    
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
