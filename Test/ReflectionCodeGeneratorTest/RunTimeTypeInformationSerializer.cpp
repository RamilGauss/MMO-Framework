/*
	ReflectionCodeGeneratorTest
*/
// ReflectionCodeGenerator version 2.5.0, build 59 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, RTTI, TypeInformation]
// File has been generated at 2023_10_29 16:17:58.477
	
#include "RunTimeTypeInformationSerializer.h"

#include "SingletonManager.h"
#include "RunTimeTypeIndex.h"

using namespace nsRunTimeTypeInformation;

std::list<std::string> TRunTimeTypeInformationSerializer::mTypeNameList;
std::list<int> TRunTimeTypeInformationSerializer::mRttiList;

std::vector<std::string> TRunTimeTypeInformationSerializer::mNameVector;
std::unordered_map<std::string, int> TRunTimeTypeInformationSerializer::mNameRttiMap;

void TRunTimeTypeInformationSerializer::Init()
{
    static bool isNeedInit = true;
    if (!isNeedInit) {
        return;
    }
    isNeedInit = false;
    
    auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();
    
    int ExecuteSystem_i = globalTypeIdentifier->Type<ExecuteSystem>();
    std::string ExecuteSystem_n = "ExecuteSystem";
    mTypeNameList.push_back(ExecuteSystem_n);
    mRttiList.push_back(ExecuteSystem_i);
    mNameRttiMap.insert({ ExecuteSystem_n, ExecuteSystem_i });
    
    int Feature_i = globalTypeIdentifier->Type<Feature>();
    std::string Feature_n = "Feature";
    mTypeNameList.push_back(Feature_n);
    mRttiList.push_back(Feature_i);
    mNameRttiMap.insert({ Feature_n, Feature_i });
    
    int InitSystem_i = globalTypeIdentifier->Type<InitSystem>();
    std::string InitSystem_n = "InitSystem";
    mTypeNameList.push_back(InitSystem_n);
    mRttiList.push_back(InitSystem_i);
    mNameRttiMap.insert({ InitSystem_n, InitSystem_i });
    
    int OnAddCollect_i = globalTypeIdentifier->Type<OnAddCollect>();
    std::string OnAddCollect_n = "OnAddCollect";
    mTypeNameList.push_back(OnAddCollect_n);
    mRttiList.push_back(OnAddCollect_i);
    mNameRttiMap.insert({ OnAddCollect_n, OnAddCollect_i });
    
    int OnAddInstant_i = globalTypeIdentifier->Type<OnAddInstant>();
    std::string OnAddInstant_n = "OnAddInstant";
    mTypeNameList.push_back(OnAddInstant_n);
    mRttiList.push_back(OnAddInstant_i);
    mNameRttiMap.insert({ OnAddInstant_n, OnAddInstant_i });
    
    int OnRemoveInstant_i = globalTypeIdentifier->Type<OnRemoveInstant>();
    std::string OnRemoveInstant_n = "OnRemoveInstant";
    mTypeNameList.push_back(OnRemoveInstant_n);
    mRttiList.push_back(OnRemoveInstant_i);
    mNameRttiMap.insert({ OnRemoveInstant_n, OnRemoveInstant_i });
    
    int OnUpdateCollect_i = globalTypeIdentifier->Type<OnUpdateCollect>();
    std::string OnUpdateCollect_n = "OnUpdateCollect";
    mTypeNameList.push_back(OnUpdateCollect_n);
    mRttiList.push_back(OnUpdateCollect_i);
    mNameRttiMap.insert({ OnUpdateCollect_n, OnUpdateCollect_i });
    
    int OnUpdateInstant_i = globalTypeIdentifier->Type<OnUpdateInstant>();
    std::string OnUpdateInstant_n = "OnUpdateInstant";
    mTypeNameList.push_back(OnUpdateInstant_n);
    mRttiList.push_back(OnUpdateInstant_i);
    mNameRttiMap.insert({ OnUpdateInstant_n, OnUpdateInstant_i });
    
    int System_i = globalTypeIdentifier->Type<System>();
    std::string System_n = "System";
    mTypeNameList.push_back(System_n);
    mRttiList.push_back(System_i);
    mNameRttiMap.insert({ System_n, System_i });
    
    int TUnit_i = globalTypeIdentifier->Type<TUnit>();
    std::string TUnit_n = "TUnit";
    mTypeNameList.push_back(TUnit_n);
    mRttiList.push_back(TUnit_i);
    mNameRttiMap.insert({ TUnit_n, TUnit_i });
    
    int TearDownSystem_i = globalTypeIdentifier->Type<TearDownSystem>();
    std::string TearDownSystem_n = "TearDownSystem";
    mTypeNameList.push_back(TearDownSystem_n);
    mRttiList.push_back(TearDownSystem_i);
    mNameRttiMap.insert({ TearDownSystem_n, TearDownSystem_i });
    
    int nsAllTypes_A_i = globalTypeIdentifier->Type<nsAllTypes::A>();
    std::string nsAllTypes_A_n = "nsAllTypes::A";
    mTypeNameList.push_back(nsAllTypes_A_n);
    mRttiList.push_back(nsAllTypes_A_i);
    mNameRttiMap.insert({ nsAllTypes_A_n, nsAllTypes_A_i });
    
    int nsAllTypes_B_i = globalTypeIdentifier->Type<nsAllTypes::B>();
    std::string nsAllTypes_B_n = "nsAllTypes::B";
    mTypeNameList.push_back(nsAllTypes_B_n);
    mRttiList.push_back(nsAllTypes_B_i);
    mNameRttiMap.insert({ nsAllTypes_B_n, nsAllTypes_B_i });
    
    int nsAllTypes_C_i = globalTypeIdentifier->Type<nsAllTypes::C>();
    std::string nsAllTypes_C_n = "nsAllTypes::C";
    mTypeNameList.push_back(nsAllTypes_C_n);
    mRttiList.push_back(nsAllTypes_C_i);
    mNameRttiMap.insert({ nsAllTypes_C_n, nsAllTypes_C_i });
    
    int nsSimpleComponents_TNameComponent_i = globalTypeIdentifier->Type<nsSimpleComponents::TNameComponent>();
    std::string nsSimpleComponents_TNameComponent_n = "nsSimpleComponents::TNameComponent";
    mTypeNameList.push_back(nsSimpleComponents_TNameComponent_n);
    mRttiList.push_back(nsSimpleComponents_TNameComponent_i);
    mNameRttiMap.insert({ nsSimpleComponents_TNameComponent_n, nsSimpleComponents_TNameComponent_i });
    
    int nsSimpleComponents_TSimpleComponent_i = globalTypeIdentifier->Type<nsSimpleComponents::TSimpleComponent>();
    std::string nsSimpleComponents_TSimpleComponent_n = "nsSimpleComponents::TSimpleComponent";
    mTypeNameList.push_back(nsSimpleComponents_TSimpleComponent_n);
    mRttiList.push_back(nsSimpleComponents_TSimpleComponent_i);
    mNameRttiMap.insert({ nsSimpleComponents_TSimpleComponent_n, nsSimpleComponents_TSimpleComponent_i });
    
    int nsSimpleComponents_TSizeComponent_i = globalTypeIdentifier->Type<nsSimpleComponents::TSizeComponent>();
    std::string nsSimpleComponents_TSizeComponent_n = "nsSimpleComponents::TSizeComponent";
    mTypeNameList.push_back(nsSimpleComponents_TSizeComponent_n);
    mRttiList.push_back(nsSimpleComponents_TSizeComponent_i);
    mNameRttiMap.insert({ nsSimpleComponents_TSizeComponent_n, nsSimpleComponents_TSizeComponent_i });
    
    int nsSimpleComponents_TValueComponent_i = globalTypeIdentifier->Type<nsSimpleComponents::TValueComponent>();
    std::string nsSimpleComponents_TValueComponent_n = "nsSimpleComponents::TValueComponent";
    mTypeNameList.push_back(nsSimpleComponents_TValueComponent_n);
    mRttiList.push_back(nsSimpleComponents_TValueComponent_i);
    mNameRttiMap.insert({ nsSimpleComponents_TValueComponent_n, nsSimpleComponents_TValueComponent_i });
    
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
const std::list<std::string>* TRunTimeTypeInformationSerializer::GetTypeNameList()
{
    Init();
    return &mTypeNameList;
}
//---------------------------------------------------------------------------------------
const std::list<int>* TRunTimeTypeInformationSerializer::GetRttiList()
{
    Init();
    return &mRttiList;
}
//---------------------------------------------------------------------------------------
const std::string* TRunTimeTypeInformationSerializer::ConvertRttiToName(int rtti)
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
bool TRunTimeTypeInformationSerializer::ConvertNameToRtti(const std::string& typeName, int& rtti)
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
