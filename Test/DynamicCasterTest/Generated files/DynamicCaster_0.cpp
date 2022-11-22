/*
	DynamicCasterTest
*/
// ReflectionCodeGenerator version 2.4.0, build 58 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, TypeInformation]
// File has been generated at 2022_11_21 12:20:32.589
	
#include "DynamicCaster_0.h"
#include "SingletonManager.h"
#include "RunTimeTypeIndex.h"

using namespace nsDynamicCasterTest;

std::vector<std::vector<TDynamicCaster_0::Data>> TDynamicCaster_0::mDataVector;
std::map<int, std::set<int>> TDynamicCaster_0::mRttiCombinations;

void TDynamicCaster_0::Init()
{
    static bool isNeedInit = true;
    if ( !isNeedInit ) {
        return;
    }
    isNeedInit = false;
    
    auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();
    
    std::map<int, std::map<int, Data>> m;
    
    std::map<int, Data> nsFirst_A_Map;
    
    Data nsFirst_A_nsFirst_B_Data;
    nsFirst_A_nsFirst_B_Data.castFunc = [](void* p){ return dynamic_cast<nsFirst::B*>(static_cast<nsFirst::A*>(p)); };
    auto nsFirst_A_nsFirst_B_rtti = globalTypeIdentifier->Type<nsFirst::B>();
    
    nsFirst_A_Map.insert({ nsFirst_A_nsFirst_B_rtti, nsFirst_A_nsFirst_B_Data });
    
    auto nsFirst_A_rtti = globalTypeIdentifier->Type<nsFirst::A>();
    
    m.insert({ nsFirst_A_rtti, nsFirst_A_Map });
    
    std::map<int, Data> nsFirst_B_Map;
    
    Data nsFirst_B_nsFirst_A_Data;
    nsFirst_B_nsFirst_A_Data.castFunc = [](void* p){ return dynamic_cast<nsFirst::A*>(static_cast<nsFirst::B*>(p)); };
    auto nsFirst_B_nsFirst_A_rtti = globalTypeIdentifier->Type<nsFirst::A>();
    
    nsFirst_B_Map.insert({ nsFirst_B_nsFirst_A_rtti, nsFirst_B_nsFirst_A_Data });
    
    auto nsFirst_B_rtti = globalTypeIdentifier->Type<nsFirst::B>();
    
    m.insert({ nsFirst_B_rtti, nsFirst_B_Map });
    
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
void* TDynamicCaster_0::Cast(int srcRtti, void* p, int dstRtti)
{
    Init();
    return mDataVector[srcRtti][dstRtti].castFunc(p);
}
//---------------------------------------------------------------------------------------
const std::map<int, std::set<int>>& TDynamicCaster_0::GetRttiCombinations()
{
    Init();
    return mRttiCombinations;
}
//---------------------------------------------------------------------------------------
