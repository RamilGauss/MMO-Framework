/*
	DynamicCasterTest
*/
// ReflectionCodeGenerator version 2.4.0, build 58 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, TypeInformation]
// File has been generated at 2022_11_20 21:27:14.675
	
#include "TypeInformation_0.h"

#include "SingletonManager.h"
#include "RunTimeTypeIndex.h"

using namespace nsDynamicCasterTest;

std::list<std::string> TTypeInformation_0::mTypeNameList;
std::list<int> TTypeInformation_0::mRttiList;

std::vector<std::string> TTypeInformation_0::mNameVector;
std::map<std::string, int> TTypeInformation_0::mNameRttiMap;

void TTypeInformation_0::Init()
{
    static bool isNeedInit = true;
    if (!isNeedInit) {
        return;
    }
    isNeedInit = false;
    
    auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();
    
    int nsFirst_A_i = globalTypeIdentifier->Type<nsFirst::A>();
    std::string nsFirst_A_n = "nsFirst::A";
    mTypeNameList.push_back(nsFirst_A_n);
    mRttiList.push_back(nsFirst_A_i);
    mNameRttiMap.insert({ nsFirst_A_n, nsFirst_A_i });
    
    int nsFirst_B_i = globalTypeIdentifier->Type<nsFirst::B>();
    std::string nsFirst_B_n = "nsFirst::B";
    mTypeNameList.push_back(nsFirst_B_n);
    mRttiList.push_back(nsFirst_B_i);
    mNameRttiMap.insert({ nsFirst_B_n, nsFirst_B_i });
    
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
const std::list<std::string>* TTypeInformation_0::GetTypeNameList()
{
    Init();
    return &mTypeNameList;
}
//---------------------------------------------------------------------------------------
const std::list<int>* TTypeInformation_0::GetRttiList()
{
    Init();
    return &mRttiList;
}
//---------------------------------------------------------------------------------------
const std::string* TTypeInformation_0::ConvertRttiToName(int rtti)
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
bool TTypeInformation_0::ConvertNameToRtti(const std::string& typeName, int& rtti)
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
