/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.3.0, build 57 [Json, Binary, ImGui, EcsComponentExtension, EcsSystemExtension, Reflection, TypeInformation]
// File has been generated at 2022_09_18 22:26:08.649
	
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
    
    int nsGraphicWrapper_TBeginGraphicFeature_i = globalTypeIdentifier->Type<nsGraphicWrapper::TBeginGraphicFeature>();
    std::string nsGraphicWrapper_TBeginGraphicFeature_n = "nsGraphicWrapper::TBeginGraphicFeature";
    mTypeNameList.push_back(nsGraphicWrapper_TBeginGraphicFeature_n);
    mRttiList.push_back(nsGraphicWrapper_TBeginGraphicFeature_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TBeginGraphicFeature_n, nsGraphicWrapper_TBeginGraphicFeature_i });
    
    int nsGraphicWrapper_TCameraBuilderFeature_i = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraBuilderFeature>();
    std::string nsGraphicWrapper_TCameraBuilderFeature_n = "nsGraphicWrapper::TCameraBuilderFeature";
    mTypeNameList.push_back(nsGraphicWrapper_TCameraBuilderFeature_n);
    mRttiList.push_back(nsGraphicWrapper_TCameraBuilderFeature_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TCameraBuilderFeature_n, nsGraphicWrapper_TCameraBuilderFeature_i });
    
    int nsGraphicWrapper_TCameraUpdaterToModuleSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraUpdaterToModuleSystem>();
    std::string nsGraphicWrapper_TCameraUpdaterToModuleSystem_n = "nsGraphicWrapper::TCameraUpdaterToModuleSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TCameraUpdaterToModuleSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TCameraUpdaterToModuleSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TCameraUpdaterToModuleSystem_n, nsGraphicWrapper_TCameraUpdaterToModuleSystem_i });
    
    int nsGraphicWrapper_TCleanUpUniverseContextSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TCleanUpUniverseContextSystem>();
    std::string nsGraphicWrapper_TCleanUpUniverseContextSystem_n = "nsGraphicWrapper::TCleanUpUniverseContextSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TCleanUpUniverseContextSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TCleanUpUniverseContextSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TCleanUpUniverseContextSystem_n, nsGraphicWrapper_TCleanUpUniverseContextSystem_i });
    
    int nsGraphicWrapper_TEndGraphicFeature_i = globalTypeIdentifier->Type<nsGraphicWrapper::TEndGraphicFeature>();
    std::string nsGraphicWrapper_TEndGraphicFeature_n = "nsGraphicWrapper::TEndGraphicFeature";
    mTypeNameList.push_back(nsGraphicWrapper_TEndGraphicFeature_n);
    mRttiList.push_back(nsGraphicWrapper_TEndGraphicFeature_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TEndGraphicFeature_n, nsGraphicWrapper_TEndGraphicFeature_i });
    
    int nsGraphicWrapper_TGuiBuilderFeature_i = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiBuilderFeature>();
    std::string nsGraphicWrapper_TGuiBuilderFeature_n = "nsGraphicWrapper::TGuiBuilderFeature";
    mTypeNameList.push_back(nsGraphicWrapper_TGuiBuilderFeature_n);
    mRttiList.push_back(nsGraphicWrapper_TGuiBuilderFeature_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TGuiBuilderFeature_n, nsGraphicWrapper_TGuiBuilderFeature_i });
    
    int nsGraphicWrapper_TGuiMakerFeature_i = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiMakerFeature>();
    std::string nsGraphicWrapper_TGuiMakerFeature_n = "nsGraphicWrapper::TGuiMakerFeature";
    mTypeNameList.push_back(nsGraphicWrapper_TGuiMakerFeature_n);
    mRttiList.push_back(nsGraphicWrapper_TGuiMakerFeature_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TGuiMakerFeature_n, nsGraphicWrapper_TGuiMakerFeature_i });
    
    int nsGraphicWrapper_TGuiTerminatorFeature_i = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiTerminatorFeature>();
    std::string nsGraphicWrapper_TGuiTerminatorFeature_n = "nsGraphicWrapper::TGuiTerminatorFeature";
    mTypeNameList.push_back(nsGraphicWrapper_TGuiTerminatorFeature_n);
    mRttiList.push_back(nsGraphicWrapper_TGuiTerminatorFeature_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TGuiTerminatorFeature_n, nsGraphicWrapper_TGuiTerminatorFeature_i });
    
    int nsGraphicWrapper_TGuiUpdaterFromModuleFeature_i = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiUpdaterFromModuleFeature>();
    std::string nsGraphicWrapper_TGuiUpdaterFromModuleFeature_n = "nsGraphicWrapper::TGuiUpdaterFromModuleFeature";
    mTypeNameList.push_back(nsGraphicWrapper_TGuiUpdaterFromModuleFeature_n);
    mRttiList.push_back(nsGraphicWrapper_TGuiUpdaterFromModuleFeature_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TGuiUpdaterFromModuleFeature_n, nsGraphicWrapper_TGuiUpdaterFromModuleFeature_i });
    
    int nsGraphicWrapper_TGuiUpdaterToModuleFeature_i = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiUpdaterToModuleFeature>();
    std::string nsGraphicWrapper_TGuiUpdaterToModuleFeature_n = "nsGraphicWrapper::TGuiUpdaterToModuleFeature";
    mTypeNameList.push_back(nsGraphicWrapper_TGuiUpdaterToModuleFeature_n);
    mRttiList.push_back(nsGraphicWrapper_TGuiUpdaterToModuleFeature_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TGuiUpdaterToModuleFeature_n, nsGraphicWrapper_TGuiUpdaterToModuleFeature_i });
    
    int nsGraphicWrapper_TInputTextValueUpdaterSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TInputTextValueUpdaterSystem>();
    std::string nsGraphicWrapper_TInputTextValueUpdaterSystem_n = "nsGraphicWrapper::TInputTextValueUpdaterSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TInputTextValueUpdaterSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TInputTextValueUpdaterSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TInputTextValueUpdaterSystem_n, nsGraphicWrapper_TInputTextValueUpdaterSystem_i });
    
    int nsGraphicWrapper_TPositionUpdaterSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TPositionUpdaterSystem>();
    std::string nsGraphicWrapper_TPositionUpdaterSystem_n = "nsGraphicWrapper::TPositionUpdaterSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TPositionUpdaterSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TPositionUpdaterSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TPositionUpdaterSystem_n, nsGraphicWrapper_TPositionUpdaterSystem_i });
    
    int nsGraphicWrapper_TTitleUpdaterSystem_i = globalTypeIdentifier->Type<nsGraphicWrapper::TTitleUpdaterSystem>();
    std::string nsGraphicWrapper_TTitleUpdaterSystem_n = "nsGraphicWrapper::TTitleUpdaterSystem";
    mTypeNameList.push_back(nsGraphicWrapper_TTitleUpdaterSystem_n);
    mRttiList.push_back(nsGraphicWrapper_TTitleUpdaterSystem_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TTitleUpdaterSystem_n, nsGraphicWrapper_TTitleUpdaterSystem_i });
    
    int nsLogicWrapper_TBeginLogicFeature_i = globalTypeIdentifier->Type<nsLogicWrapper::TBeginLogicFeature>();
    std::string nsLogicWrapper_TBeginLogicFeature_n = "nsLogicWrapper::TBeginLogicFeature";
    mTypeNameList.push_back(nsLogicWrapper_TBeginLogicFeature_n);
    mRttiList.push_back(nsLogicWrapper_TBeginLogicFeature_i);
    mNameRttiMap.insert({ nsLogicWrapper_TBeginLogicFeature_n, nsLogicWrapper_TBeginLogicFeature_i });
    
    int nsLogicWrapper_TEndLogicFeature_i = globalTypeIdentifier->Type<nsLogicWrapper::TEndLogicFeature>();
    std::string nsLogicWrapper_TEndLogicFeature_n = "nsLogicWrapper::TEndLogicFeature";
    mTypeNameList.push_back(nsLogicWrapper_TEndLogicFeature_n);
    mRttiList.push_back(nsLogicWrapper_TEndLogicFeature_i);
    mNameRttiMap.insert({ nsLogicWrapper_TEndLogicFeature_n, nsLogicWrapper_TEndLogicFeature_i });
    
    int nsLogicWrapper_THandlerCallCollectorNotifySystem_i = globalTypeIdentifier->Type<nsLogicWrapper::THandlerCallCollectorNotifySystem>();
    std::string nsLogicWrapper_THandlerCallCollectorNotifySystem_n = "nsLogicWrapper::THandlerCallCollectorNotifySystem";
    mTypeNameList.push_back(nsLogicWrapper_THandlerCallCollectorNotifySystem_n);
    mRttiList.push_back(nsLogicWrapper_THandlerCallCollectorNotifySystem_i);
    mNameRttiMap.insert({ nsLogicWrapper_THandlerCallCollectorNotifySystem_n, nsLogicWrapper_THandlerCallCollectorNotifySystem_i });
    
    int nsLogicWrapper_TLogicBuilderFeature_i = globalTypeIdentifier->Type<nsLogicWrapper::TLogicBuilderFeature>();
    std::string nsLogicWrapper_TLogicBuilderFeature_n = "nsLogicWrapper::TLogicBuilderFeature";
    mTypeNameList.push_back(nsLogicWrapper_TLogicBuilderFeature_n);
    mRttiList.push_back(nsLogicWrapper_TLogicBuilderFeature_i);
    mNameRttiMap.insert({ nsLogicWrapper_TLogicBuilderFeature_n, nsLogicWrapper_TLogicBuilderFeature_i });
    
    int nsLogicWrapper_TLogicMakerFeature_i = globalTypeIdentifier->Type<nsLogicWrapper::TLogicMakerFeature>();
    std::string nsLogicWrapper_TLogicMakerFeature_n = "nsLogicWrapper::TLogicMakerFeature";
    mTypeNameList.push_back(nsLogicWrapper_TLogicMakerFeature_n);
    mRttiList.push_back(nsLogicWrapper_TLogicMakerFeature_i);
    mNameRttiMap.insert({ nsLogicWrapper_TLogicMakerFeature_n, nsLogicWrapper_TLogicMakerFeature_i });
    
    int nsLogicWrapper_TLogicTerminatorFeature_i = globalTypeIdentifier->Type<nsLogicWrapper::TLogicTerminatorFeature>();
    std::string nsLogicWrapper_TLogicTerminatorFeature_n = "nsLogicWrapper::TLogicTerminatorFeature";
    mTypeNameList.push_back(nsLogicWrapper_TLogicTerminatorFeature_n);
    mRttiList.push_back(nsLogicWrapper_TLogicTerminatorFeature_i);
    mNameRttiMap.insert({ nsLogicWrapper_TLogicTerminatorFeature_n, nsLogicWrapper_TLogicTerminatorFeature_i });
    
    int nsLogicWrapper_TObjectFeature_i = globalTypeIdentifier->Type<nsLogicWrapper::TObjectFeature>();
    std::string nsLogicWrapper_TObjectFeature_n = "nsLogicWrapper::TObjectFeature";
    mTypeNameList.push_back(nsLogicWrapper_TObjectFeature_n);
    mRttiList.push_back(nsLogicWrapper_TObjectFeature_i);
    mNameRttiMap.insert({ nsLogicWrapper_TObjectFeature_n, nsLogicWrapper_TObjectFeature_i });
    
    int nsLogicWrapper_TSceneFeature_i = globalTypeIdentifier->Type<nsLogicWrapper::TSceneFeature>();
    std::string nsLogicWrapper_TSceneFeature_n = "nsLogicWrapper::TSceneFeature";
    mTypeNameList.push_back(nsLogicWrapper_TSceneFeature_n);
    mRttiList.push_back(nsLogicWrapper_TSceneFeature_i);
    mNameRttiMap.insert({ nsLogicWrapper_TSceneFeature_n, nsLogicWrapper_TSceneFeature_i });
    
    int nsLogicWrapper_TStartedScenesInitSystem_i = globalTypeIdentifier->Type<nsLogicWrapper::TStartedScenesInitSystem>();
    std::string nsLogicWrapper_TStartedScenesInitSystem_n = "nsLogicWrapper::TStartedScenesInitSystem";
    mTypeNameList.push_back(nsLogicWrapper_TStartedScenesInitSystem_n);
    mRttiList.push_back(nsLogicWrapper_TStartedScenesInitSystem_i);
    mNameRttiMap.insert({ nsLogicWrapper_TStartedScenesInitSystem_n, nsLogicWrapper_TStartedScenesInitSystem_i });
    
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
