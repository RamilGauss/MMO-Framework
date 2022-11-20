/*
	DynamicCasterTest
*/
// ReflectionCodeGenerator version 2.4.0, build 58 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, TypeInformation]
// File has been generated at 2022_11_20 21:27:14.739
	
#include "DynamicCaster_1.h"
#include "SingletonManager.h"
#include "RunTimeTypeIndex.h"

using namespace nsDynamicCasterTest;

std::vector<std::vector<TDynamicCaster_1::Data>> TDynamicCaster_1::mDataVector;
void TDynamicCaster_1::Init()
{
    static bool isNeedInit = true;
    if ( !isNeedInit )
    {
        return;
    }
    isNeedInit = false;
    
    auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();
    
    std::map<int, std::map<int, Data>> m;
    
    std::map<int, Data> nsSecond_C_Map;
    
    Data nsSecond_C_nsFirst_A_Data;
    nsSecond_C_nsFirst_A_Data.castFunc = [](void* p){ return dynamic_cast<nsFirst::A*>(static_cast<nsSecond::C*>(p)); };
    auto nsSecond_C_nsFirst_A_rtti = globalTypeIdentifier->Type<nsFirst::A>();
    
    nsSecond_C_Map.insert({ nsSecond_C_nsFirst_A_rtti, nsSecond_C_nsFirst_A_Data });
    
    Data nsSecond_C_nsFirst_B_Data;
    nsSecond_C_nsFirst_B_Data.castFunc = [](void* p){ return dynamic_cast<nsFirst::B*>(static_cast<nsSecond::C*>(p)); };
    auto nsSecond_C_nsFirst_B_rtti = globalTypeIdentifier->Type<nsFirst::B>();
    
    nsSecond_C_Map.insert({ nsSecond_C_nsFirst_B_rtti, nsSecond_C_nsFirst_B_Data });
    
    Data nsSecond_C_nsSecond_D_Data;
    nsSecond_C_nsSecond_D_Data.castFunc = [](void* p){ return dynamic_cast<nsSecond::D*>(static_cast<nsSecond::C*>(p)); };
    auto nsSecond_C_nsSecond_D_rtti = globalTypeIdentifier->Type<nsSecond::D>();
    
    nsSecond_C_Map.insert({ nsSecond_C_nsSecond_D_rtti, nsSecond_C_nsSecond_D_Data });
    
    auto nsSecond_C_rtti = globalTypeIdentifier->Type<nsSecond::C>();
    
    m.insert({ nsSecond_C_rtti, nsSecond_C_Map });
    
    std::map<int, Data> nsSecond_D_Map;
    
    Data nsSecond_D_nsFirst_A_Data;
    nsSecond_D_nsFirst_A_Data.castFunc = [](void* p){ return dynamic_cast<nsFirst::A*>(static_cast<nsSecond::D*>(p)); };
    auto nsSecond_D_nsFirst_A_rtti = globalTypeIdentifier->Type<nsFirst::A>();
    
    nsSecond_D_Map.insert({ nsSecond_D_nsFirst_A_rtti, nsSecond_D_nsFirst_A_Data });
    
    Data nsSecond_D_nsFirst_B_Data;
    nsSecond_D_nsFirst_B_Data.castFunc = [](void* p){ return dynamic_cast<nsFirst::B*>(static_cast<nsSecond::D*>(p)); };
    auto nsSecond_D_nsFirst_B_rtti = globalTypeIdentifier->Type<nsFirst::B>();
    
    nsSecond_D_Map.insert({ nsSecond_D_nsFirst_B_rtti, nsSecond_D_nsFirst_B_Data });
    
    Data nsSecond_D_nsSecond_C_Data;
    nsSecond_D_nsSecond_C_Data.castFunc = [](void* p){ return dynamic_cast<nsSecond::C*>(static_cast<nsSecond::D*>(p)); };
    auto nsSecond_D_nsSecond_C_rtti = globalTypeIdentifier->Type<nsSecond::C>();
    
    nsSecond_D_Map.insert({ nsSecond_D_nsSecond_C_rtti, nsSecond_D_nsSecond_C_Data });
    
    auto nsSecond_D_rtti = globalTypeIdentifier->Type<nsSecond::D>();
    
    m.insert({ nsSecond_D_rtti, nsSecond_D_Map });
    
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
        for (auto& vtDst : vt.second) {
            vecData[vtDst.first] = vtDst.second;
        }
        
        mDataVector[vt.first] = vecData;
    }
}
//---------------------------------------------------------------------------------------
void* TDynamicCaster_1::Cast(int srcRtti, void* p, int dstRtti)
{
    Init();
    return mDataVector[srcRtti][dstRtti].castFunc(p);
}
//---------------------------------------------------------------------------------------
