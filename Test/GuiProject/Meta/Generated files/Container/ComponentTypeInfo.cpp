/*
Project Component
*/
// ReflectionCodeGenerator version 2.4.2, build 58 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, TypeInformation]
// File has been generated at 2023_10_08 13:49:40.620
	
#include "ComponentTypeInfo.h"

#include "SingletonManager.h"
#include "RunTimeTypeIndex.h"

using namespace nsTornadoEditor;

std::list<std::string> TComponentTypeInfo::mTypeNameList;
std::list<int> TComponentTypeInfo::mRttiList;

std::vector<std::string> TComponentTypeInfo::mNameVector;
std::unordered_map<std::string, int> TComponentTypeInfo::mNameRttiMap;

void TComponentTypeInfo::Init()
{
    static bool isNeedInit = true;
    if (!isNeedInit) {
        return;
    }
    isNeedInit = false;
    
    auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();
    
    int nsGuiProject_TScenePrefabTestComponent_i = globalTypeIdentifier->Type<nsGuiProject::TScenePrefabTestComponent>();
    std::string nsGuiProject_TScenePrefabTestComponent_n = "nsGuiProject::TScenePrefabTestComponent";
    mTypeNameList.push_back(nsGuiProject_TScenePrefabTestComponent_n);
    mRttiList.push_back(nsGuiProject_TScenePrefabTestComponent_i);
    mNameRttiMap.insert({ nsGuiProject_TScenePrefabTestComponent_n, nsGuiProject_TScenePrefabTestComponent_i });
    
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
const std::list<std::string>* TComponentTypeInfo::GetTypeNameList()
{
    Init();
    return &mTypeNameList;
}
//---------------------------------------------------------------------------------------
const std::list<int>* TComponentTypeInfo::GetRttiList()
{
    Init();
    return &mRttiList;
}
//---------------------------------------------------------------------------------------
const std::string* TComponentTypeInfo::ConvertRttiToName(int rtti)
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
bool TComponentTypeInfo::ConvertNameToRtti(const std::string& typeName, int& rtti)
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
