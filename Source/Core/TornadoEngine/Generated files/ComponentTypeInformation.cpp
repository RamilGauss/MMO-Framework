/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.2.4, build 55 [Json, Binary, ImGui, EntityManager, Reflection, TypeInformation]
// File has been generated at 2021_12_15 07:42:45.479
	
#include "ComponentTypeInformation.h"

#include "SingletonManager.h"
#include "RunTimeTypeIndex.h"

using namespace nsTornadoEngine;

std::list<std::string> TComponentTypeInformation::mTypeNameList;
std::list<int> TComponentTypeInformation::mRttiList;

std::vector<std::string> TComponentTypeInformation::mNameVector;
std::map<std::string, int> TComponentTypeInformation::mNameRttiMap;

void TComponentTypeInformation::Init()
{
    static bool isNeedInit = true;
    if (!isNeedInit) {
        return;
    }
    isNeedInit = false;
    
    auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();
    
    int nsCommonWrapper_TGuidComponent_i = globalTypeIdentifier->Type<nsCommonWrapper::TGuidComponent>();
    std::string nsCommonWrapper_TGuidComponent_n = "nsCommonWrapper::TGuidComponent";
    mTypeNameList.push_back(nsCommonWrapper_TGuidComponent_n);
    mRttiList.push_back(nsCommonWrapper_TGuidComponent_i);
    mNameRttiMap.insert({ nsCommonWrapper_TGuidComponent_n, nsCommonWrapper_TGuidComponent_i });
    
    int nsCommonWrapper_TNameComponent_i = globalTypeIdentifier->Type<nsCommonWrapper::TNameComponent>();
    std::string nsCommonWrapper_TNameComponent_n = "nsCommonWrapper::TNameComponent";
    mTypeNameList.push_back(nsCommonWrapper_TNameComponent_n);
    mRttiList.push_back(nsCommonWrapper_TNameComponent_i);
    mNameRttiMap.insert({ nsCommonWrapper_TNameComponent_n, nsCommonWrapper_TNameComponent_i });
    
    int nsCommonWrapper_TNeedDestroyPrefabComponent_i = globalTypeIdentifier->Type<nsCommonWrapper::TNeedDestroyPrefabComponent>();
    std::string nsCommonWrapper_TNeedDestroyPrefabComponent_n = "nsCommonWrapper::TNeedDestroyPrefabComponent";
    mTypeNameList.push_back(nsCommonWrapper_TNeedDestroyPrefabComponent_n);
    mRttiList.push_back(nsCommonWrapper_TNeedDestroyPrefabComponent_i);
    mNameRttiMap.insert({ nsCommonWrapper_TNeedDestroyPrefabComponent_n, nsCommonWrapper_TNeedDestroyPrefabComponent_i });
    
    int nsCommonWrapper_TNeedDestroySceneComponent_i = globalTypeIdentifier->Type<nsCommonWrapper::TNeedDestroySceneComponent>();
    std::string nsCommonWrapper_TNeedDestroySceneComponent_n = "nsCommonWrapper::TNeedDestroySceneComponent";
    mTypeNameList.push_back(nsCommonWrapper_TNeedDestroySceneComponent_n);
    mRttiList.push_back(nsCommonWrapper_TNeedDestroySceneComponent_i);
    mNameRttiMap.insert({ nsCommonWrapper_TNeedDestroySceneComponent_n, nsCommonWrapper_TNeedDestroySceneComponent_i });
    
    int nsCommonWrapper_TNeedUnloadPrefabComponent_i = globalTypeIdentifier->Type<nsCommonWrapper::TNeedUnloadPrefabComponent>();
    std::string nsCommonWrapper_TNeedUnloadPrefabComponent_n = "nsCommonWrapper::TNeedUnloadPrefabComponent";
    mTypeNameList.push_back(nsCommonWrapper_TNeedUnloadPrefabComponent_n);
    mRttiList.push_back(nsCommonWrapper_TNeedUnloadPrefabComponent_i);
    mNameRttiMap.insert({ nsCommonWrapper_TNeedUnloadPrefabComponent_n, nsCommonWrapper_TNeedUnloadPrefabComponent_i });
    
    int nsCommonWrapper_TNeedUnloadSceneComponent_i = globalTypeIdentifier->Type<nsCommonWrapper::TNeedUnloadSceneComponent>();
    std::string nsCommonWrapper_TNeedUnloadSceneComponent_n = "nsCommonWrapper::TNeedUnloadSceneComponent";
    mTypeNameList.push_back(nsCommonWrapper_TNeedUnloadSceneComponent_n);
    mRttiList.push_back(nsCommonWrapper_TNeedUnloadSceneComponent_i);
    mNameRttiMap.insert({ nsCommonWrapper_TNeedUnloadSceneComponent_n, nsCommonWrapper_TNeedUnloadSceneComponent_i });
    
    int nsCommonWrapper_TObjectInMemoryComponent_i = globalTypeIdentifier->Type<nsCommonWrapper::TObjectInMemoryComponent>();
    std::string nsCommonWrapper_TObjectInMemoryComponent_n = "nsCommonWrapper::TObjectInMemoryComponent";
    mTypeNameList.push_back(nsCommonWrapper_TObjectInMemoryComponent_n);
    mRttiList.push_back(nsCommonWrapper_TObjectInMemoryComponent_i);
    mNameRttiMap.insert({ nsCommonWrapper_TObjectInMemoryComponent_n, nsCommonWrapper_TObjectInMemoryComponent_i });
    
    int nsCommonWrapper_TParentGuidComponent_i = globalTypeIdentifier->Type<nsCommonWrapper::TParentGuidComponent>();
    std::string nsCommonWrapper_TParentGuidComponent_n = "nsCommonWrapper::TParentGuidComponent";
    mTypeNameList.push_back(nsCommonWrapper_TParentGuidComponent_n);
    mRttiList.push_back(nsCommonWrapper_TParentGuidComponent_i);
    mNameRttiMap.insert({ nsCommonWrapper_TParentGuidComponent_n, nsCommonWrapper_TParentGuidComponent_i });
    
    int nsCommonWrapper_TPrefabGuidComponent_i = globalTypeIdentifier->Type<nsCommonWrapper::TPrefabGuidComponent>();
    std::string nsCommonWrapper_TPrefabGuidComponent_n = "nsCommonWrapper::TPrefabGuidComponent";
    mTypeNameList.push_back(nsCommonWrapper_TPrefabGuidComponent_n);
    mRttiList.push_back(nsCommonWrapper_TPrefabGuidComponent_i);
    mNameRttiMap.insert({ nsCommonWrapper_TPrefabGuidComponent_n, nsCommonWrapper_TPrefabGuidComponent_i });
    
    int nsCommonWrapper_TPrefabInstanceGuidComponent_i = globalTypeIdentifier->Type<nsCommonWrapper::TPrefabInstanceGuidComponent>();
    std::string nsCommonWrapper_TPrefabInstanceGuidComponent_n = "nsCommonWrapper::TPrefabInstanceGuidComponent";
    mTypeNameList.push_back(nsCommonWrapper_TPrefabInstanceGuidComponent_n);
    mRttiList.push_back(nsCommonWrapper_TPrefabInstanceGuidComponent_i);
    mNameRttiMap.insert({ nsCommonWrapper_TPrefabInstanceGuidComponent_n, nsCommonWrapper_TPrefabInstanceGuidComponent_i });
    
    int nsCommonWrapper_TPrefabOriginalGuidComponent_i = globalTypeIdentifier->Type<nsCommonWrapper::TPrefabOriginalGuidComponent>();
    std::string nsCommonWrapper_TPrefabOriginalGuidComponent_n = "nsCommonWrapper::TPrefabOriginalGuidComponent";
    mTypeNameList.push_back(nsCommonWrapper_TPrefabOriginalGuidComponent_n);
    mRttiList.push_back(nsCommonWrapper_TPrefabOriginalGuidComponent_i);
    mNameRttiMap.insert({ nsCommonWrapper_TPrefabOriginalGuidComponent_n, nsCommonWrapper_TPrefabOriginalGuidComponent_i });
    
    int nsCommonWrapper_TPrefabRootComponent_i = globalTypeIdentifier->Type<nsCommonWrapper::TPrefabRootComponent>();
    std::string nsCommonWrapper_TPrefabRootComponent_n = "nsCommonWrapper::TPrefabRootComponent";
    mTypeNameList.push_back(nsCommonWrapper_TPrefabRootComponent_n);
    mRttiList.push_back(nsCommonWrapper_TPrefabRootComponent_i);
    mNameRttiMap.insert({ nsCommonWrapper_TPrefabRootComponent_n, nsCommonWrapper_TPrefabRootComponent_i });
    
    int nsCommonWrapper_TSceneGuidComponent_i = globalTypeIdentifier->Type<nsCommonWrapper::TSceneGuidComponent>();
    std::string nsCommonWrapper_TSceneGuidComponent_n = "nsCommonWrapper::TSceneGuidComponent";
    mTypeNameList.push_back(nsCommonWrapper_TSceneGuidComponent_n);
    mRttiList.push_back(nsCommonWrapper_TSceneGuidComponent_i);
    mNameRttiMap.insert({ nsCommonWrapper_TSceneGuidComponent_n, nsCommonWrapper_TSceneGuidComponent_i });
    
    int nsCommonWrapper_TSceneInstanceGuidComponent_i = globalTypeIdentifier->Type<nsCommonWrapper::TSceneInstanceGuidComponent>();
    std::string nsCommonWrapper_TSceneInstanceGuidComponent_n = "nsCommonWrapper::TSceneInstanceGuidComponent";
    mTypeNameList.push_back(nsCommonWrapper_TSceneInstanceGuidComponent_n);
    mRttiList.push_back(nsCommonWrapper_TSceneInstanceGuidComponent_i);
    mNameRttiMap.insert({ nsCommonWrapper_TSceneInstanceGuidComponent_n, nsCommonWrapper_TSceneInstanceGuidComponent_i });
    
    int nsCommonWrapper_TSceneOriginalGuidComponent_i = globalTypeIdentifier->Type<nsCommonWrapper::TSceneOriginalGuidComponent>();
    std::string nsCommonWrapper_TSceneOriginalGuidComponent_n = "nsCommonWrapper::TSceneOriginalGuidComponent";
    mTypeNameList.push_back(nsCommonWrapper_TSceneOriginalGuidComponent_n);
    mRttiList.push_back(nsCommonWrapper_TSceneOriginalGuidComponent_i);
    mNameRttiMap.insert({ nsCommonWrapper_TSceneOriginalGuidComponent_n, nsCommonWrapper_TSceneOriginalGuidComponent_i });
    
    int nsCommonWrapper_TSceneRootComponent_i = globalTypeIdentifier->Type<nsCommonWrapper::TSceneRootComponent>();
    std::string nsCommonWrapper_TSceneRootComponent_n = "nsCommonWrapper::TSceneRootComponent";
    mTypeNameList.push_back(nsCommonWrapper_TSceneRootComponent_n);
    mRttiList.push_back(nsCommonWrapper_TSceneRootComponent_i);
    mNameRttiMap.insert({ nsCommonWrapper_TSceneRootComponent_n, nsCommonWrapper_TSceneRootComponent_i });
    
    int nsCommonWrapper_TTransformComponent_i = globalTypeIdentifier->Type<nsCommonWrapper::TTransformComponent>();
    std::string nsCommonWrapper_TTransformComponent_n = "nsCommonWrapper::TTransformComponent";
    mTypeNameList.push_back(nsCommonWrapper_TTransformComponent_n);
    mRttiList.push_back(nsCommonWrapper_TTransformComponent_i);
    mNameRttiMap.insert({ nsCommonWrapper_TTransformComponent_n, nsCommonWrapper_TTransformComponent_i });
    
    int nsGraphicWrapper_TCameraComponent_i = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraComponent>();
    std::string nsGraphicWrapper_TCameraComponent_n = "nsGraphicWrapper::TCameraComponent";
    mTypeNameList.push_back(nsGraphicWrapper_TCameraComponent_n);
    mRttiList.push_back(nsGraphicWrapper_TCameraComponent_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TCameraComponent_n, nsGraphicWrapper_TCameraComponent_i });
    
    int nsGraphicWrapper_TLightComponent_i = globalTypeIdentifier->Type<nsGraphicWrapper::TLightComponent>();
    std::string nsGraphicWrapper_TLightComponent_n = "nsGraphicWrapper::TLightComponent";
    mTypeNameList.push_back(nsGraphicWrapper_TLightComponent_n);
    mRttiList.push_back(nsGraphicWrapper_TLightComponent_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TLightComponent_n, nsGraphicWrapper_TLightComponent_i });
    
    int nsGuiWrapper_TButtonClickHandlerComponent_i = globalTypeIdentifier->Type<nsGuiWrapper::TButtonClickHandlerComponent>();
    std::string nsGuiWrapper_TButtonClickHandlerComponent_n = "nsGuiWrapper::TButtonClickHandlerComponent";
    mTypeNameList.push_back(nsGuiWrapper_TButtonClickHandlerComponent_n);
    mRttiList.push_back(nsGuiWrapper_TButtonClickHandlerComponent_i);
    mNameRttiMap.insert({ nsGuiWrapper_TButtonClickHandlerComponent_n, nsGuiWrapper_TButtonClickHandlerComponent_i });
    
    int nsGuiWrapper_TButtonComponent_i = globalTypeIdentifier->Type<nsGuiWrapper::TButtonComponent>();
    std::string nsGuiWrapper_TButtonComponent_n = "nsGuiWrapper::TButtonComponent";
    mTypeNameList.push_back(nsGuiWrapper_TButtonComponent_n);
    mRttiList.push_back(nsGuiWrapper_TButtonComponent_i);
    mNameRttiMap.insert({ nsGuiWrapper_TButtonComponent_n, nsGuiWrapper_TButtonComponent_i });
    
    int nsGuiWrapper_TDialogCloseEventHandlerComponent_i = globalTypeIdentifier->Type<nsGuiWrapper::TDialogCloseEventHandlerComponent>();
    std::string nsGuiWrapper_TDialogCloseEventHandlerComponent_n = "nsGuiWrapper::TDialogCloseEventHandlerComponent";
    mTypeNameList.push_back(nsGuiWrapper_TDialogCloseEventHandlerComponent_n);
    mRttiList.push_back(nsGuiWrapper_TDialogCloseEventHandlerComponent_i);
    mNameRttiMap.insert({ nsGuiWrapper_TDialogCloseEventHandlerComponent_n, nsGuiWrapper_TDialogCloseEventHandlerComponent_i });
    
    int nsGuiWrapper_TDialogComponent_i = globalTypeIdentifier->Type<nsGuiWrapper::TDialogComponent>();
    std::string nsGuiWrapper_TDialogComponent_n = "nsGuiWrapper::TDialogComponent";
    mTypeNameList.push_back(nsGuiWrapper_TDialogComponent_n);
    mRttiList.push_back(nsGuiWrapper_TDialogComponent_i);
    mNameRttiMap.insert({ nsGuiWrapper_TDialogComponent_n, nsGuiWrapper_TDialogComponent_i });
    
    int nsGuiWrapper_TFocusComponent_i = globalTypeIdentifier->Type<nsGuiWrapper::TFocusComponent>();
    std::string nsGuiWrapper_TFocusComponent_n = "nsGuiWrapper::TFocusComponent";
    mTypeNameList.push_back(nsGuiWrapper_TFocusComponent_n);
    mRttiList.push_back(nsGuiWrapper_TFocusComponent_i);
    mNameRttiMap.insert({ nsGuiWrapper_TFocusComponent_n, nsGuiWrapper_TFocusComponent_i });
    
    int nsGuiWrapper_TFrameComponent_i = globalTypeIdentifier->Type<nsGuiWrapper::TFrameComponent>();
    std::string nsGuiWrapper_TFrameComponent_n = "nsGuiWrapper::TFrameComponent";
    mTypeNameList.push_back(nsGuiWrapper_TFrameComponent_n);
    mRttiList.push_back(nsGuiWrapper_TFrameComponent_i);
    mNameRttiMap.insert({ nsGuiWrapper_TFrameComponent_n, nsGuiWrapper_TFrameComponent_i });
    
    int nsGuiWrapper_TMainWindowComponent_i = globalTypeIdentifier->Type<nsGuiWrapper::TMainWindowComponent>();
    std::string nsGuiWrapper_TMainWindowComponent_n = "nsGuiWrapper::TMainWindowComponent";
    mTypeNameList.push_back(nsGuiWrapper_TMainWindowComponent_n);
    mRttiList.push_back(nsGuiWrapper_TMainWindowComponent_i);
    mNameRttiMap.insert({ nsGuiWrapper_TMainWindowComponent_n, nsGuiWrapper_TMainWindowComponent_i });
    
    int nsGuiWrapper_TPositionComponent_i = globalTypeIdentifier->Type<nsGuiWrapper::TPositionComponent>();
    std::string nsGuiWrapper_TPositionComponent_n = "nsGuiWrapper::TPositionComponent";
    mTypeNameList.push_back(nsGuiWrapper_TPositionComponent_n);
    mRttiList.push_back(nsGuiWrapper_TPositionComponent_i);
    mNameRttiMap.insert({ nsGuiWrapper_TPositionComponent_n, nsGuiWrapper_TPositionComponent_i });
    
    int nsGuiWrapper_TSizeComponent_i = globalTypeIdentifier->Type<nsGuiWrapper::TSizeComponent>();
    std::string nsGuiWrapper_TSizeComponent_n = "nsGuiWrapper::TSizeComponent";
    mTypeNameList.push_back(nsGuiWrapper_TSizeComponent_n);
    mRttiList.push_back(nsGuiWrapper_TSizeComponent_i);
    mNameRttiMap.insert({ nsGuiWrapper_TSizeComponent_n, nsGuiWrapper_TSizeComponent_i });
    
    int nsGuiWrapper_TTitleComponent_i = globalTypeIdentifier->Type<nsGuiWrapper::TTitleComponent>();
    std::string nsGuiWrapper_TTitleComponent_n = "nsGuiWrapper::TTitleComponent";
    mTypeNameList.push_back(nsGuiWrapper_TTitleComponent_n);
    mRttiList.push_back(nsGuiWrapper_TTitleComponent_i);
    mNameRttiMap.insert({ nsGuiWrapper_TTitleComponent_n, nsGuiWrapper_TTitleComponent_i });
    
    int nsGuiWrapper_TVisibilityComponent_i = globalTypeIdentifier->Type<nsGuiWrapper::TVisibilityComponent>();
    std::string nsGuiWrapper_TVisibilityComponent_n = "nsGuiWrapper::TVisibilityComponent";
    mTypeNameList.push_back(nsGuiWrapper_TVisibilityComponent_n);
    mRttiList.push_back(nsGuiWrapper_TVisibilityComponent_i);
    mNameRttiMap.insert({ nsGuiWrapper_TVisibilityComponent_n, nsGuiWrapper_TVisibilityComponent_i });
    
    int nsGuiWrapper_TWindowCloseEventHandlerComponent_i = globalTypeIdentifier->Type<nsGuiWrapper::TWindowCloseEventHandlerComponent>();
    std::string nsGuiWrapper_TWindowCloseEventHandlerComponent_n = "nsGuiWrapper::TWindowCloseEventHandlerComponent";
    mTypeNameList.push_back(nsGuiWrapper_TWindowCloseEventHandlerComponent_n);
    mRttiList.push_back(nsGuiWrapper_TWindowCloseEventHandlerComponent_i);
    mNameRttiMap.insert({ nsGuiWrapper_TWindowCloseEventHandlerComponent_n, nsGuiWrapper_TWindowCloseEventHandlerComponent_i });
    
    int nsGuiWrapper_TWindowComponent_i = globalTypeIdentifier->Type<nsGuiWrapper::TWindowComponent>();
    std::string nsGuiWrapper_TWindowComponent_n = "nsGuiWrapper::TWindowComponent";
    mTypeNameList.push_back(nsGuiWrapper_TWindowComponent_n);
    mRttiList.push_back(nsGuiWrapper_TWindowComponent_i);
    mNameRttiMap.insert({ nsGuiWrapper_TWindowComponent_n, nsGuiWrapper_TWindowComponent_i });
    
    int nsLogicWrapper_TFeatureComponent_i = globalTypeIdentifier->Type<nsLogicWrapper::TFeatureComponent>();
    std::string nsLogicWrapper_TFeatureComponent_n = "nsLogicWrapper::TFeatureComponent";
    mTypeNameList.push_back(nsLogicWrapper_TFeatureComponent_n);
    mRttiList.push_back(nsLogicWrapper_TFeatureComponent_i);
    mNameRttiMap.insert({ nsLogicWrapper_TFeatureComponent_n, nsLogicWrapper_TFeatureComponent_i });
    
    int nsLogicWrapper_TPrefabObjectReferenceComponent_i = globalTypeIdentifier->Type<nsLogicWrapper::TPrefabObjectReferenceComponent>();
    std::string nsLogicWrapper_TPrefabObjectReferenceComponent_n = "nsLogicWrapper::TPrefabObjectReferenceComponent";
    mTypeNameList.push_back(nsLogicWrapper_TPrefabObjectReferenceComponent_n);
    mRttiList.push_back(nsLogicWrapper_TPrefabObjectReferenceComponent_i);
    mNameRttiMap.insert({ nsLogicWrapper_TPrefabObjectReferenceComponent_n, nsLogicWrapper_TPrefabObjectReferenceComponent_i });
    
    int nsLogicWrapper_TPrefabReferenceComponent_i = globalTypeIdentifier->Type<nsLogicWrapper::TPrefabReferenceComponent>();
    std::string nsLogicWrapper_TPrefabReferenceComponent_n = "nsLogicWrapper::TPrefabReferenceComponent";
    mTypeNameList.push_back(nsLogicWrapper_TPrefabReferenceComponent_n);
    mRttiList.push_back(nsLogicWrapper_TPrefabReferenceComponent_i);
    mNameRttiMap.insert({ nsLogicWrapper_TPrefabReferenceComponent_n, nsLogicWrapper_TPrefabReferenceComponent_i });
    
    int nsLogicWrapper_TSceneObjectReferenceComponent_i = globalTypeIdentifier->Type<nsLogicWrapper::TSceneObjectReferenceComponent>();
    std::string nsLogicWrapper_TSceneObjectReferenceComponent_n = "nsLogicWrapper::TSceneObjectReferenceComponent";
    mTypeNameList.push_back(nsLogicWrapper_TSceneObjectReferenceComponent_n);
    mRttiList.push_back(nsLogicWrapper_TSceneObjectReferenceComponent_i);
    mNameRttiMap.insert({ nsLogicWrapper_TSceneObjectReferenceComponent_n, nsLogicWrapper_TSceneObjectReferenceComponent_i });
    
    int nsLogicWrapper_TSceneReferenceComponent_i = globalTypeIdentifier->Type<nsLogicWrapper::TSceneReferenceComponent>();
    std::string nsLogicWrapper_TSceneReferenceComponent_n = "nsLogicWrapper::TSceneReferenceComponent";
    mTypeNameList.push_back(nsLogicWrapper_TSceneReferenceComponent_n);
    mRttiList.push_back(nsLogicWrapper_TSceneReferenceComponent_i);
    mNameRttiMap.insert({ nsLogicWrapper_TSceneReferenceComponent_n, nsLogicWrapper_TSceneReferenceComponent_i });
    
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
const std::list<std::string>* TComponentTypeInformation::GetTypeNameList()
{
    Init();
    return &mTypeNameList;
}
//---------------------------------------------------------------------------------------
const std::list<int>* TComponentTypeInformation::GetRttiList()
{
    Init();
    return &mRttiList;
}
//---------------------------------------------------------------------------------------
const std::string* TComponentTypeInformation::ConvertRttiToName(int rtti)
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
bool TComponentTypeInformation::ConvertNameToRtti(const std::string& typeName, int& rtti)
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
