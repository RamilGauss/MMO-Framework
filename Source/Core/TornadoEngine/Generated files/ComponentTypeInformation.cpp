/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.2.1, build 52 [Json, Binary, ImGui, EntityManager, Reflection, TypeInformation]
// File has been generated at 2021_10_23 15:26:16.418
	
#include "ComponentTypeInformation.h"

#include "SingletonManager.h"
#include "RunTimeTypeIndex.h"

using namespace nsTornadoEngine;

std::list<std::string> TComponentTypeInformation::mTypeNameList;

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
    
    int nsTornadoEngine_TCameraComponent_i = globalTypeIdentifier->type<nsTornadoEngine::TCameraComponent>();
    std::string nsTornadoEngine_TCameraComponent_n = "nsTornadoEngine::TCameraComponent";
    mTypeNameList.push_back(nsTornadoEngine_TCameraComponent_n);
    mNameRttiMap.insert({ nsTornadoEngine_TCameraComponent_n, nsTornadoEngine_TCameraComponent_i });
    
    int nsTornadoEngine_TFocusComponent_i = globalTypeIdentifier->type<nsTornadoEngine::TFocusComponent>();
    std::string nsTornadoEngine_TFocusComponent_n = "nsTornadoEngine::TFocusComponent";
    mTypeNameList.push_back(nsTornadoEngine_TFocusComponent_n);
    mNameRttiMap.insert({ nsTornadoEngine_TFocusComponent_n, nsTornadoEngine_TFocusComponent_i });
    
    int nsTornadoEngine_TGuidComponent_i = globalTypeIdentifier->type<nsTornadoEngine::TGuidComponent>();
    std::string nsTornadoEngine_TGuidComponent_n = "nsTornadoEngine::TGuidComponent";
    mTypeNameList.push_back(nsTornadoEngine_TGuidComponent_n);
    mNameRttiMap.insert({ nsTornadoEngine_TGuidComponent_n, nsTornadoEngine_TGuidComponent_i });
    
    int nsTornadoEngine_TLightComponent_i = globalTypeIdentifier->type<nsTornadoEngine::TLightComponent>();
    std::string nsTornadoEngine_TLightComponent_n = "nsTornadoEngine::TLightComponent";
    mTypeNameList.push_back(nsTornadoEngine_TLightComponent_n);
    mNameRttiMap.insert({ nsTornadoEngine_TLightComponent_n, nsTornadoEngine_TLightComponent_i });
    
    int nsTornadoEngine_TNameComponent_i = globalTypeIdentifier->type<nsTornadoEngine::TNameComponent>();
    std::string nsTornadoEngine_TNameComponent_n = "nsTornadoEngine::TNameComponent";
    mTypeNameList.push_back(nsTornadoEngine_TNameComponent_n);
    mNameRttiMap.insert({ nsTornadoEngine_TNameComponent_n, nsTornadoEngine_TNameComponent_i });
    
    int nsTornadoEngine_TParentGuidComponent_i = globalTypeIdentifier->type<nsTornadoEngine::TParentGuidComponent>();
    std::string nsTornadoEngine_TParentGuidComponent_n = "nsTornadoEngine::TParentGuidComponent";
    mTypeNameList.push_back(nsTornadoEngine_TParentGuidComponent_n);
    mNameRttiMap.insert({ nsTornadoEngine_TParentGuidComponent_n, nsTornadoEngine_TParentGuidComponent_i });
    
    int nsTornadoEngine_TPositionComponent_i = globalTypeIdentifier->type<nsTornadoEngine::TPositionComponent>();
    std::string nsTornadoEngine_TPositionComponent_n = "nsTornadoEngine::TPositionComponent";
    mTypeNameList.push_back(nsTornadoEngine_TPositionComponent_n);
    mNameRttiMap.insert({ nsTornadoEngine_TPositionComponent_n, nsTornadoEngine_TPositionComponent_i });
    
    int nsTornadoEngine_TSceneGuidComponent_i = globalTypeIdentifier->type<nsTornadoEngine::TSceneGuidComponent>();
    std::string nsTornadoEngine_TSceneGuidComponent_n = "nsTornadoEngine::TSceneGuidComponent";
    mTypeNameList.push_back(nsTornadoEngine_TSceneGuidComponent_n);
    mNameRttiMap.insert({ nsTornadoEngine_TSceneGuidComponent_n, nsTornadoEngine_TSceneGuidComponent_i });
    
    int nsTornadoEngine_TSizeComponent_i = globalTypeIdentifier->type<nsTornadoEngine::TSizeComponent>();
    std::string nsTornadoEngine_TSizeComponent_n = "nsTornadoEngine::TSizeComponent";
    mTypeNameList.push_back(nsTornadoEngine_TSizeComponent_n);
    mNameRttiMap.insert({ nsTornadoEngine_TSizeComponent_n, nsTornadoEngine_TSizeComponent_i });
    
    int nsTornadoEngine_TTransformComponent_i = globalTypeIdentifier->type<nsTornadoEngine::TTransformComponent>();
    std::string nsTornadoEngine_TTransformComponent_n = "nsTornadoEngine::TTransformComponent";
    mTypeNameList.push_back(nsTornadoEngine_TTransformComponent_n);
    mNameRttiMap.insert({ nsTornadoEngine_TTransformComponent_n, nsTornadoEngine_TTransformComponent_i });
    
    int nsTornadoEngine_TVisibilityComponent_i = globalTypeIdentifier->type<nsTornadoEngine::TVisibilityComponent>();
    std::string nsTornadoEngine_TVisibilityComponent_n = "nsTornadoEngine::TVisibilityComponent";
    mTypeNameList.push_back(nsTornadoEngine_TVisibilityComponent_n);
    mNameRttiMap.insert({ nsTornadoEngine_TVisibilityComponent_n, nsTornadoEngine_TVisibilityComponent_i });
    
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
    return true;
}
//---------------------------------------------------------------------------------------
