/*
	ReflectionCodeGeneratorTest
*/
// ReflectionCodeGenerator version 2.5.0, build 59 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, RTTI, TypeInformation]
// File has been generated at 2023_10_30 17:46:21.296
	
#include "EcsSystemExtension.h"
#include "SingletonManager.h"
#include "RunTimeTypeIndex.h"

using namespace nsTest;

std::vector<std::vector<TEcsSystemExtension::Data>> TEcsSystemExtension::mDataVector;
std::map<int, std::set<int>> TEcsSystemExtension::mRttiCombinations;

template <typename FromType, typename ToType>
ToType* SmartCast(void* p)
{
    if constexpr (std::is_base_of<ToType, FromType>::value) {
        return dynamic_cast<ToType*>(static_cast<FromType*>(p));
    }
    if constexpr (std::is_polymorphic<FromType>() && std::is_polymorphic<ToType>()) {
        return dynamic_cast<ToType*>(static_cast<FromType*>(p));
    }
    return reinterpret_cast<ToType*>(static_cast<FromType*>(p));
}

void TEcsSystemExtension::Init()
{
    static bool isNeedInit = true;
    if ( !isNeedInit ) {
        return;
    }
    isNeedInit = false;
    
    auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();
    
    std::map<int, std::map<int, Data>> m;
    
    int srcMax = 0;
    for (auto& vt : m) {
        srcMax = std::max(vt.first, srcMax);
    }
    
    mDataVector.resize(srcMax + 1);
    for (auto& vt : m) {
        std::vector<Data> vecData;
        int dstMax = 0;
        for (auto& vtDst : vt.second) {
            dstMax = std::max(vtDst.first, dstMax);
        }
        
        vecData.resize(dstMax + 1);
        std::set<int> rttis;
        for (auto& vtDst : vt.second) {
            vecData[vtDst.first] = vtDst.second;
            rttis.insert(vtDst.first);
        }
        
        mRttiCombinations.insert({ vt.first, rttis });
        
        mDataVector[vt.first] = vecData;
    }
}
//---------------------------------------------------------------------------------------
void* TEcsSystemExtension::Cast(int srcRtti, void* p, int dstRtti)
{
    Init();
    return mDataVector[dstRtti][srcRtti].castFunc(p);
}
//---------------------------------------------------------------------------------------
const std::map<int, std::set<int>>& TEcsSystemExtension::GetRttiCombinations()
{
    Init();
    return mRttiCombinations;
}
//---------------------------------------------------------------------------------------
