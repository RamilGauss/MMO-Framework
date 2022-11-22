/*
	DynamicCasterTest
*/
// ReflectionCodeGenerator version 2.4.0, build 58 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, TypeInformation]
// File has been generated at 2022_11_21 12:20:32.731
	
#include "TypeInformation_1.h"

#include "SingletonManager.h"
#include "RunTimeTypeIndex.h"

using namespace nsDynamicCasterTest;

std::list<std::string> TTypeInformation_1::mTypeNameList;
std::list<int> TTypeInformation_1::mRttiList;

std::vector<std::string> TTypeInformation_1::mNameVector;
std::map<std::string, int> TTypeInformation_1::mNameRttiMap;

void TTypeInformation_1::Init()
{
    static bool isNeedInit = true;
    if (!isNeedInit) {
        return;
    }
    isNeedInit = false;
    
    auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();
    
    int nsSecond_C_i = globalTypeIdentifier->Type<nsSecond::C>();
    std::string nsSecond_C_n = "nsSecond::C";
    mTypeNameList.push_back(nsSecond_C_n);
    mRttiList.push_back(nsSecond_C_i);
    mNameRttiMap.insert({ nsSecond_C_n, nsSecond_C_i });
    
    int nsSecond_D_i = globalTypeIdentifier->Type<nsSecond::D>();
    std::string nsSecond_D_n = "nsSecond::D";
    mTypeNameList.push_back(nsSecond_D_n);
    mRttiList.push_back(nsSecond_D_i);
    mNameRttiMap.insert({ nsSecond_D_n, nsSecond_D_i });
    
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
const std::list<std::string>* TTypeInformation_1::GetTypeNameList()
{
    Init();
    return &mTypeNameList;
}
//---------------------------------------------------------------------------------------
const std::list<int>* TTypeInformation_1::GetRttiList()
{
    Init();
    return &mRttiList;
}
//---------------------------------------------------------------------------------------
const std::string* TTypeInformation_1::ConvertRttiToName(int rtti)
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
bool TTypeInformation_1::ConvertNameToRtti(const std::string& typeName, int& rtti)
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
