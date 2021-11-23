/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.2.2, build 53 [Json, Binary, ImGui, EntityManager, Reflection, TypeInformation]
// File has been generated at 2021_11_23 08:21:30.659
	
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
    
    int nsCommonWrapper_TGuidComponent_i = globalTypeIdentifier->type<nsCommonWrapper::TGuidComponent>();
    std::string nsCommonWrapper_TGuidComponent_n = "nsCommonWrapper::TGuidComponent";
    mTypeNameList.push_back(nsCommonWrapper_TGuidComponent_n);
    mRttiList.push_back(nsCommonWrapper_TGuidComponent_i);
    mNameRttiMap.insert({ nsCommonWrapper_TGuidComponent_n, nsCommonWrapper_TGuidComponent_i });
    
    int nsCommonWrapper_TNameComponent_i = globalTypeIdentifier->type<nsCommonWrapper::TNameComponent>();
    std::string nsCommonWrapper_TNameComponent_n = "nsCommonWrapper::TNameComponent";
    mTypeNameList.push_back(nsCommonWrapper_TNameComponent_n);
    mRttiList.push_back(nsCommonWrapper_TNameComponent_i);
    mNameRttiMap.insert({ nsCommonWrapper_TNameComponent_n, nsCommonWrapper_TNameComponent_i });
    
    int nsCommonWrapper_TParentGuidComponent_i = globalTypeIdentifier->type<nsCommonWrapper::TParentGuidComponent>();
    std::string nsCommonWrapper_TParentGuidComponent_n = "nsCommonWrapper::TParentGuidComponent";
    mTypeNameList.push_back(nsCommonWrapper_TParentGuidComponent_n);
    mRttiList.push_back(nsCommonWrapper_TParentGuidComponent_i);
    mNameRttiMap.insert({ nsCommonWrapper_TParentGuidComponent_n, nsCommonWrapper_TParentGuidComponent_i });
    
    int nsCommonWrapper_TSceneEditingComponent_i = globalTypeIdentifier->type<nsCommonWrapper::TSceneEditingComponent>();
    std::string nsCommonWrapper_TSceneEditingComponent_n = "nsCommonWrapper::TSceneEditingComponent";
    mTypeNameList.push_back(nsCommonWrapper_TSceneEditingComponent_n);
    mRttiList.push_back(nsCommonWrapper_TSceneEditingComponent_i);
    mNameRttiMap.insert({ nsCommonWrapper_TSceneEditingComponent_n, nsCommonWrapper_TSceneEditingComponent_i });
    
    int nsCommonWrapper_TSceneGuidComponent_i = globalTypeIdentifier->type<nsCommonWrapper::TSceneGuidComponent>();
    std::string nsCommonWrapper_TSceneGuidComponent_n = "nsCommonWrapper::TSceneGuidComponent";
    mTypeNameList.push_back(nsCommonWrapper_TSceneGuidComponent_n);
    mRttiList.push_back(nsCommonWrapper_TSceneGuidComponent_i);
    mNameRttiMap.insert({ nsCommonWrapper_TSceneGuidComponent_n, nsCommonWrapper_TSceneGuidComponent_i });
    
    int nsCommonWrapper_TSceneRootComponent_i = globalTypeIdentifier->type<nsCommonWrapper::TSceneRootComponent>();
    std::string nsCommonWrapper_TSceneRootComponent_n = "nsCommonWrapper::TSceneRootComponent";
    mTypeNameList.push_back(nsCommonWrapper_TSceneRootComponent_n);
    mRttiList.push_back(nsCommonWrapper_TSceneRootComponent_i);
    mNameRttiMap.insert({ nsCommonWrapper_TSceneRootComponent_n, nsCommonWrapper_TSceneRootComponent_i });
    
    int nsCommonWrapper_TTransformComponent_i = globalTypeIdentifier->type<nsCommonWrapper::TTransformComponent>();
    std::string nsCommonWrapper_TTransformComponent_n = "nsCommonWrapper::TTransformComponent";
    mTypeNameList.push_back(nsCommonWrapper_TTransformComponent_n);
    mRttiList.push_back(nsCommonWrapper_TTransformComponent_i);
    mNameRttiMap.insert({ nsCommonWrapper_TTransformComponent_n, nsCommonWrapper_TTransformComponent_i });
    
    int nsGraphicWrapper_TCameraComponent_i = globalTypeIdentifier->type<nsGraphicWrapper::TCameraComponent>();
    std::string nsGraphicWrapper_TCameraComponent_n = "nsGraphicWrapper::TCameraComponent";
    mTypeNameList.push_back(nsGraphicWrapper_TCameraComponent_n);
    mRttiList.push_back(nsGraphicWrapper_TCameraComponent_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TCameraComponent_n, nsGraphicWrapper_TCameraComponent_i });
    
    int nsGraphicWrapper_TLightComponent_i = globalTypeIdentifier->type<nsGraphicWrapper::TLightComponent>();
    std::string nsGraphicWrapper_TLightComponent_n = "nsGraphicWrapper::TLightComponent";
    mTypeNameList.push_back(nsGraphicWrapper_TLightComponent_n);
    mRttiList.push_back(nsGraphicWrapper_TLightComponent_i);
    mNameRttiMap.insert({ nsGraphicWrapper_TLightComponent_n, nsGraphicWrapper_TLightComponent_i });
    
    int nsGuiWrapper_TButtonClickHandlerComponent_i = globalTypeIdentifier->type<nsGuiWrapper::TButtonClickHandlerComponent>();
    std::string nsGuiWrapper_TButtonClickHandlerComponent_n = "nsGuiWrapper::TButtonClickHandlerComponent";
    mTypeNameList.push_back(nsGuiWrapper_TButtonClickHandlerComponent_n);
    mRttiList.push_back(nsGuiWrapper_TButtonClickHandlerComponent_i);
    mNameRttiMap.insert({ nsGuiWrapper_TButtonClickHandlerComponent_n, nsGuiWrapper_TButtonClickHandlerComponent_i });
    
    int nsGuiWrapper_TButtonComponent_i = globalTypeIdentifier->type<nsGuiWrapper::TButtonComponent>();
    std::string nsGuiWrapper_TButtonComponent_n = "nsGuiWrapper::TButtonComponent";
    mTypeNameList.push_back(nsGuiWrapper_TButtonComponent_n);
    mRttiList.push_back(nsGuiWrapper_TButtonComponent_i);
    mNameRttiMap.insert({ nsGuiWrapper_TButtonComponent_n, nsGuiWrapper_TButtonComponent_i });
    
    int nsGuiWrapper_TFocusComponent_i = globalTypeIdentifier->type<nsGuiWrapper::TFocusComponent>();
    std::string nsGuiWrapper_TFocusComponent_n = "nsGuiWrapper::TFocusComponent";
    mTypeNameList.push_back(nsGuiWrapper_TFocusComponent_n);
    mRttiList.push_back(nsGuiWrapper_TFocusComponent_i);
    mNameRttiMap.insert({ nsGuiWrapper_TFocusComponent_n, nsGuiWrapper_TFocusComponent_i });
    
    int nsGuiWrapper_TPositionComponent_i = globalTypeIdentifier->type<nsGuiWrapper::TPositionComponent>();
    std::string nsGuiWrapper_TPositionComponent_n = "nsGuiWrapper::TPositionComponent";
    mTypeNameList.push_back(nsGuiWrapper_TPositionComponent_n);
    mRttiList.push_back(nsGuiWrapper_TPositionComponent_i);
    mNameRttiMap.insert({ nsGuiWrapper_TPositionComponent_n, nsGuiWrapper_TPositionComponent_i });
    
    int nsGuiWrapper_TSizeComponent_i = globalTypeIdentifier->type<nsGuiWrapper::TSizeComponent>();
    std::string nsGuiWrapper_TSizeComponent_n = "nsGuiWrapper::TSizeComponent";
    mTypeNameList.push_back(nsGuiWrapper_TSizeComponent_n);
    mRttiList.push_back(nsGuiWrapper_TSizeComponent_i);
    mNameRttiMap.insert({ nsGuiWrapper_TSizeComponent_n, nsGuiWrapper_TSizeComponent_i });
    
    int nsGuiWrapper_TTitleComponent_i = globalTypeIdentifier->type<nsGuiWrapper::TTitleComponent>();
    std::string nsGuiWrapper_TTitleComponent_n = "nsGuiWrapper::TTitleComponent";
    mTypeNameList.push_back(nsGuiWrapper_TTitleComponent_n);
    mRttiList.push_back(nsGuiWrapper_TTitleComponent_i);
    mNameRttiMap.insert({ nsGuiWrapper_TTitleComponent_n, nsGuiWrapper_TTitleComponent_i });
    
    int nsGuiWrapper_TVisibilityComponent_i = globalTypeIdentifier->type<nsGuiWrapper::TVisibilityComponent>();
    std::string nsGuiWrapper_TVisibilityComponent_n = "nsGuiWrapper::TVisibilityComponent";
    mTypeNameList.push_back(nsGuiWrapper_TVisibilityComponent_n);
    mRttiList.push_back(nsGuiWrapper_TVisibilityComponent_i);
    mNameRttiMap.insert({ nsGuiWrapper_TVisibilityComponent_n, nsGuiWrapper_TVisibilityComponent_i });
    
    int nsGuiWrapper_TWindowComponent_i = globalTypeIdentifier->type<nsGuiWrapper::TWindowComponent>();
    std::string nsGuiWrapper_TWindowComponent_n = "nsGuiWrapper::TWindowComponent";
    mTypeNameList.push_back(nsGuiWrapper_TWindowComponent_n);
    mRttiList.push_back(nsGuiWrapper_TWindowComponent_i);
    mNameRttiMap.insert({ nsGuiWrapper_TWindowComponent_n, nsGuiWrapper_TWindowComponent_i });
    
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
