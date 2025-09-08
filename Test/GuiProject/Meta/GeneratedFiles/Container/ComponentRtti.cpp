/*
Project Component
*/
// ReflectionCodeGenerator version 2.5.0, build 59 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, RTTI, TypeInformation]

#include "ComponentRtti.h"

#include "Base/Common/SingletonManager.h"
#include "Base/Common/RunTimeTypeIndex.h"

using namespace nsGuiProject;

std::list<std::string> TComponentRtti::mTypeNameList;
std::list<int> TComponentRtti::mRttiList;

std::vector<std::string> TComponentRtti::mNameVector;
std::unordered_map<std::string, int> TComponentRtti::mNameRttiMap;

void TComponentRtti::Init()
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
const std::list<std::string>* TComponentRtti::GetTypeNameList()
{
    Init();
    return &mTypeNameList;
}
//---------------------------------------------------------------------------------------
const std::list<int>* TComponentRtti::GetRttiList()
{
    Init();
    return &mRttiList;
}
//---------------------------------------------------------------------------------------
const std::string* TComponentRtti::ConvertRttiToName(int rtti)
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
bool TComponentRtti::ConvertNameToRtti(const std::string& typeName, int& rtti)
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
