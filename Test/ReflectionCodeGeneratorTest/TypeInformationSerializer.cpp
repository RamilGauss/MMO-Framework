/*
	ReflectionCodeGeneratorTest
*/
// ReflectionCodeGenerator version 2.2.1, build 52, info Json, Binary, MyGUI, EntityManager, Reflection, TypeInformation
// File has been generated at 2021_05_26 08:21:30.374
	
#include "TypeInformationSerializer.h"

#include "SingletonManager.h"
#include "RunTimeTypeIndex.h"

using namespace nsTypeInformation;

std::list<std::string> TTypeInformationSerializer::mTypeNameList;

std::vector<std::string> TTypeInformationSerializer::mNameVector;
std::map<std::string, int> TTypeInformationSerializer::mNameRttiMap;

void TTypeInformationSerializer::Init()
{
    static bool isNeedInit = true;
    if (!isNeedInit) {
        return;
    }
    isNeedInit = false;
    
    auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();
    
    int nsAllTypes_A_i = globalTypeIdentifier->type<nsAllTypes::A>();
    std::string nsAllTypes_A_n = "nsAllTypes::A";
    mTypeNameList.push_back(nsAllTypes_A_n);
    mNameRttiMap.insert({ "nsAllTypes_A_n", nsAllTypes_A_i });
    
    int nsAllTypes_B_i = globalTypeIdentifier->type<nsAllTypes::B>();
    std::string nsAllTypes_B_n = "nsAllTypes::B";
    mTypeNameList.push_back(nsAllTypes_B_n);
    mNameRttiMap.insert({ "nsAllTypes_B_n", nsAllTypes_B_i });
    
    int nsAllTypes_C_i = globalTypeIdentifier->type<nsAllTypes::C>();
    std::string nsAllTypes_C_n = "nsAllTypes::C";
    mTypeNameList.push_back(nsAllTypes_C_n);
    mNameRttiMap.insert({ "nsAllTypes_C_n", nsAllTypes_C_i });
    
    int nsSimpleComponents_TNameComponent_i = globalTypeIdentifier->type<nsSimpleComponents::TNameComponent>();
    std::string nsSimpleComponents_TNameComponent_n = "nsSimpleComponents::TNameComponent";
    mTypeNameList.push_back(nsSimpleComponents_TNameComponent_n);
    mNameRttiMap.insert({ "nsSimpleComponents_TNameComponent_n", nsSimpleComponents_TNameComponent_i });
    
    int nsSimpleComponents_TSimpleComponent_i = globalTypeIdentifier->type<nsSimpleComponents::TSimpleComponent>();
    std::string nsSimpleComponents_TSimpleComponent_n = "nsSimpleComponents::TSimpleComponent";
    mTypeNameList.push_back(nsSimpleComponents_TSimpleComponent_n);
    mNameRttiMap.insert({ "nsSimpleComponents_TSimpleComponent_n", nsSimpleComponents_TSimpleComponent_i });
    
    int nsSimpleComponents_TValueComponent_i = globalTypeIdentifier->type<nsSimpleComponents::TValueComponent>();
    std::string nsSimpleComponents_TValueComponent_n = "nsSimpleComponents::TValueComponent";
    mTypeNameList.push_back(nsSimpleComponents_TValueComponent_n);
    mNameRttiMap.insert({ "nsSimpleComponents_TValueComponent_n", nsSimpleComponents_TValueComponent_i });
    
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
const std::list<std::string>* TTypeInformationSerializer::GetTypeNameList()
{
    Init();
    return &mTypeNameList;
}
//---------------------------------------------------------------------------------------
const std::string* TTypeInformationSerializer::ConvertRttiToName(int rtti)
{
    Init();
    return &(mNameVector[rtti]);
}
//---------------------------------------------------------------------------------------
bool TTypeInformationSerializer::ConvertNameToRtti(const std::string& typeName, int& rtti)
{
    Init();
    auto fit = mNameRttiMap.find(typeName);
    if (fit == mNameRttiMap.end()) {
        return false;
    }
    return true;
}
//---------------------------------------------------------------------------------------
