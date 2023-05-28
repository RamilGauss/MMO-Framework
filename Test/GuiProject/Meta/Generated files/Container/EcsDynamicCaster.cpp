/*
Project Ecs System
*/
// ReflectionCodeGenerator version 2.4.0, build 58 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, TypeInformation]
// File has been generated at 2023_05_28 17:59:43.041
	
#include "EcsDynamicCaster.h"
#include "SingletonManager.h"
#include "RunTimeTypeIndex.h"

using namespace nsTornadoEditor;

std::vector<std::vector<TEcsDynamicCaster::Data>> TEcsDynamicCaster::mDataVector;
std::map<int, std::set<int>> TEcsDynamicCaster::mRttiCombinations;

template <typename FromType, typename ToType>
ToType* SmartCast(void* p)
{
    if constexpr (std::is_polymorphic<FromType>() && std::is_polymorphic<ToType>()) {
        return dynamic_cast<ToType*>(static_cast<FromType*>(p));
    }
    return reinterpret_cast<ToType*>(static_cast<FromType*>(p));
}

void TEcsDynamicCaster::Init()
{
    static bool isNeedInit = true;
    if ( !isNeedInit ) {
        return;
    }
    isNeedInit = false;
    
    auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();
    
    std::map<int, std::map<int, Data>> m;
    
    std::map<int, Data> nsECSFramework_TBaseCollectReactiveSystem_Map;
    
    Data nsECSFramework_TBaseCollectReactiveSystem_nsECSFramework_TExecuteSystem_Data;
    nsECSFramework_TBaseCollectReactiveSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return SmartCast<nsECSFramework::TExecuteSystem, nsECSFramework::TBaseCollectReactiveSystem>(p); };
    auto nsECSFramework_TBaseCollectReactiveSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsECSFramework_TBaseCollectReactiveSystem_Map.insert({ nsECSFramework_TBaseCollectReactiveSystem_nsECSFramework_TExecuteSystem_rtti, nsECSFramework_TBaseCollectReactiveSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsECSFramework_TBaseCollectReactiveSystem_nsECSFramework_TSystem_Data;
    nsECSFramework_TBaseCollectReactiveSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return SmartCast<nsECSFramework::TSystem, nsECSFramework::TBaseCollectReactiveSystem>(p); };
    auto nsECSFramework_TBaseCollectReactiveSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsECSFramework_TBaseCollectReactiveSystem_Map.insert({ nsECSFramework_TBaseCollectReactiveSystem_nsECSFramework_TSystem_rtti, nsECSFramework_TBaseCollectReactiveSystem_nsECSFramework_TSystem_Data });
    
    Data nsECSFramework_TBaseCollectReactiveSystem_nsECSFramework_TTearDownSystem_Data;
    nsECSFramework_TBaseCollectReactiveSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return SmartCast<nsECSFramework::TTearDownSystem, nsECSFramework::TBaseCollectReactiveSystem>(p); };
    auto nsECSFramework_TBaseCollectReactiveSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsECSFramework_TBaseCollectReactiveSystem_Map.insert({ nsECSFramework_TBaseCollectReactiveSystem_nsECSFramework_TTearDownSystem_rtti, nsECSFramework_TBaseCollectReactiveSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    m.insert({ nsECSFramework_TBaseCollectReactiveSystem_rtti, nsECSFramework_TBaseCollectReactiveSystem_Map });
    
    std::map<int, Data> nsECSFramework_TBaseReactiveSystem_Map;
    
    Data nsECSFramework_TBaseReactiveSystem_nsECSFramework_TSystem_Data;
    nsECSFramework_TBaseReactiveSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return SmartCast<nsECSFramework::TSystem, nsECSFramework::TBaseReactiveSystem>(p); };
    auto nsECSFramework_TBaseReactiveSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsECSFramework_TBaseReactiveSystem_Map.insert({ nsECSFramework_TBaseReactiveSystem_nsECSFramework_TSystem_rtti, nsECSFramework_TBaseReactiveSystem_nsECSFramework_TSystem_Data });
    
    Data nsECSFramework_TBaseReactiveSystem_nsECSFramework_TTearDownSystem_Data;
    nsECSFramework_TBaseReactiveSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return SmartCast<nsECSFramework::TTearDownSystem, nsECSFramework::TBaseReactiveSystem>(p); };
    auto nsECSFramework_TBaseReactiveSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsECSFramework_TBaseReactiveSystem_Map.insert({ nsECSFramework_TBaseReactiveSystem_nsECSFramework_TTearDownSystem_rtti, nsECSFramework_TBaseReactiveSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsECSFramework_TBaseReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseReactiveSystem>();
    
    m.insert({ nsECSFramework_TBaseReactiveSystem_rtti, nsECSFramework_TBaseReactiveSystem_Map });
    
    std::map<int, Data> nsECSFramework_TExecuteSystem_Map;
    
    Data nsECSFramework_TExecuteSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsECSFramework_TExecuteSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return SmartCast<nsECSFramework::TBaseCollectReactiveSystem, nsECSFramework::TExecuteSystem>(p); };
    auto nsECSFramework_TExecuteSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsECSFramework_TExecuteSystem_Map.insert({ nsECSFramework_TExecuteSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsECSFramework_TExecuteSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsECSFramework_TExecuteSystem_nsECSFramework_TSystem_Data;
    nsECSFramework_TExecuteSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return SmartCast<nsECSFramework::TSystem, nsECSFramework::TExecuteSystem>(p); };
    auto nsECSFramework_TExecuteSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsECSFramework_TExecuteSystem_Map.insert({ nsECSFramework_TExecuteSystem_nsECSFramework_TSystem_rtti, nsECSFramework_TExecuteSystem_nsECSFramework_TSystem_Data });
    
    Data nsECSFramework_TExecuteSystem_nsECSFramework_TFeature_Data;
    nsECSFramework_TExecuteSystem_nsECSFramework_TFeature_Data.castFunc = [](void* p){ return SmartCast<nsECSFramework::TFeature, nsECSFramework::TExecuteSystem>(p); };
    auto nsECSFramework_TExecuteSystem_nsECSFramework_TFeature_rtti = globalTypeIdentifier->Type<nsECSFramework::TFeature>();
    
    nsECSFramework_TExecuteSystem_Map.insert({ nsECSFramework_TExecuteSystem_nsECSFramework_TFeature_rtti, nsECSFramework_TExecuteSystem_nsECSFramework_TFeature_Data });
    
    auto nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    m.insert({ nsECSFramework_TExecuteSystem_rtti, nsECSFramework_TExecuteSystem_Map });
    
    std::map<int, Data> nsECSFramework_TFeature_Map;
    
    Data nsECSFramework_TFeature_nsECSFramework_TExecuteSystem_Data;
    nsECSFramework_TFeature_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return SmartCast<nsECSFramework::TExecuteSystem, nsECSFramework::TFeature>(p); };
    auto nsECSFramework_TFeature_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsECSFramework_TFeature_Map.insert({ nsECSFramework_TFeature_nsECSFramework_TExecuteSystem_rtti, nsECSFramework_TFeature_nsECSFramework_TExecuteSystem_Data });
    
    Data nsECSFramework_TFeature_nsECSFramework_TSystem_Data;
    nsECSFramework_TFeature_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return SmartCast<nsECSFramework::TSystem, nsECSFramework::TFeature>(p); };
    auto nsECSFramework_TFeature_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsECSFramework_TFeature_Map.insert({ nsECSFramework_TFeature_nsECSFramework_TSystem_rtti, nsECSFramework_TFeature_nsECSFramework_TSystem_Data });
    
    Data nsECSFramework_TFeature_nsECSFramework_TTearDownSystem_Data;
    nsECSFramework_TFeature_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return SmartCast<nsECSFramework::TTearDownSystem, nsECSFramework::TFeature>(p); };
    auto nsECSFramework_TFeature_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsECSFramework_TFeature_Map.insert({ nsECSFramework_TFeature_nsECSFramework_TTearDownSystem_rtti, nsECSFramework_TFeature_nsECSFramework_TTearDownSystem_Data });
    
    auto nsECSFramework_TFeature_rtti = globalTypeIdentifier->Type<nsECSFramework::TFeature>();
    
    m.insert({ nsECSFramework_TFeature_rtti, nsECSFramework_TFeature_Map });
    
    std::map<int, Data> nsECSFramework_TSystem_Map;
    
    Data nsECSFramework_TSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsECSFramework_TSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return SmartCast<nsECSFramework::TBaseCollectReactiveSystem, nsECSFramework::TSystem>(p); };
    auto nsECSFramework_TSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsECSFramework_TSystem_Map.insert({ nsECSFramework_TSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsECSFramework_TSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsECSFramework_TSystem_nsECSFramework_TBaseReactiveSystem_Data;
    nsECSFramework_TSystem_nsECSFramework_TBaseReactiveSystem_Data.castFunc = [](void* p){ return SmartCast<nsECSFramework::TBaseReactiveSystem, nsECSFramework::TSystem>(p); };
    auto nsECSFramework_TSystem_nsECSFramework_TBaseReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseReactiveSystem>();
    
    nsECSFramework_TSystem_Map.insert({ nsECSFramework_TSystem_nsECSFramework_TBaseReactiveSystem_rtti, nsECSFramework_TSystem_nsECSFramework_TBaseReactiveSystem_Data });
    
    Data nsECSFramework_TSystem_nsECSFramework_TExecuteSystem_Data;
    nsECSFramework_TSystem_nsECSFramework_TExecuteSystem_Data.castFunc = [](void* p){ return SmartCast<nsECSFramework::TExecuteSystem, nsECSFramework::TSystem>(p); };
    auto nsECSFramework_TSystem_nsECSFramework_TExecuteSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TExecuteSystem>();
    
    nsECSFramework_TSystem_Map.insert({ nsECSFramework_TSystem_nsECSFramework_TExecuteSystem_rtti, nsECSFramework_TSystem_nsECSFramework_TExecuteSystem_Data });
    
    Data nsECSFramework_TSystem_nsECSFramework_TFeature_Data;
    nsECSFramework_TSystem_nsECSFramework_TFeature_Data.castFunc = [](void* p){ return SmartCast<nsECSFramework::TFeature, nsECSFramework::TSystem>(p); };
    auto nsECSFramework_TSystem_nsECSFramework_TFeature_rtti = globalTypeIdentifier->Type<nsECSFramework::TFeature>();
    
    nsECSFramework_TSystem_Map.insert({ nsECSFramework_TSystem_nsECSFramework_TFeature_rtti, nsECSFramework_TSystem_nsECSFramework_TFeature_Data });
    
    Data nsECSFramework_TSystem_nsECSFramework_TTearDownSystem_Data;
    nsECSFramework_TSystem_nsECSFramework_TTearDownSystem_Data.castFunc = [](void* p){ return SmartCast<nsECSFramework::TTearDownSystem, nsECSFramework::TSystem>(p); };
    auto nsECSFramework_TSystem_nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    nsECSFramework_TSystem_Map.insert({ nsECSFramework_TSystem_nsECSFramework_TTearDownSystem_rtti, nsECSFramework_TSystem_nsECSFramework_TTearDownSystem_Data });
    
    auto nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    m.insert({ nsECSFramework_TSystem_rtti, nsECSFramework_TSystem_Map });
    
    std::map<int, Data> nsECSFramework_TTearDownSystem_Map;
    
    Data nsECSFramework_TTearDownSystem_nsECSFramework_TBaseCollectReactiveSystem_Data;
    nsECSFramework_TTearDownSystem_nsECSFramework_TBaseCollectReactiveSystem_Data.castFunc = [](void* p){ return SmartCast<nsECSFramework::TBaseCollectReactiveSystem, nsECSFramework::TTearDownSystem>(p); };
    auto nsECSFramework_TTearDownSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseCollectReactiveSystem>();
    
    nsECSFramework_TTearDownSystem_Map.insert({ nsECSFramework_TTearDownSystem_nsECSFramework_TBaseCollectReactiveSystem_rtti, nsECSFramework_TTearDownSystem_nsECSFramework_TBaseCollectReactiveSystem_Data });
    
    Data nsECSFramework_TTearDownSystem_nsECSFramework_TBaseReactiveSystem_Data;
    nsECSFramework_TTearDownSystem_nsECSFramework_TBaseReactiveSystem_Data.castFunc = [](void* p){ return SmartCast<nsECSFramework::TBaseReactiveSystem, nsECSFramework::TTearDownSystem>(p); };
    auto nsECSFramework_TTearDownSystem_nsECSFramework_TBaseReactiveSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TBaseReactiveSystem>();
    
    nsECSFramework_TTearDownSystem_Map.insert({ nsECSFramework_TTearDownSystem_nsECSFramework_TBaseReactiveSystem_rtti, nsECSFramework_TTearDownSystem_nsECSFramework_TBaseReactiveSystem_Data });
    
    Data nsECSFramework_TTearDownSystem_nsECSFramework_TFeature_Data;
    nsECSFramework_TTearDownSystem_nsECSFramework_TFeature_Data.castFunc = [](void* p){ return SmartCast<nsECSFramework::TFeature, nsECSFramework::TTearDownSystem>(p); };
    auto nsECSFramework_TTearDownSystem_nsECSFramework_TFeature_rtti = globalTypeIdentifier->Type<nsECSFramework::TFeature>();
    
    nsECSFramework_TTearDownSystem_Map.insert({ nsECSFramework_TTearDownSystem_nsECSFramework_TFeature_rtti, nsECSFramework_TTearDownSystem_nsECSFramework_TFeature_Data });
    
    Data nsECSFramework_TTearDownSystem_nsECSFramework_TSystem_Data;
    nsECSFramework_TTearDownSystem_nsECSFramework_TSystem_Data.castFunc = [](void* p){ return SmartCast<nsECSFramework::TSystem, nsECSFramework::TTearDownSystem>(p); };
    auto nsECSFramework_TTearDownSystem_nsECSFramework_TSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TSystem>();
    
    nsECSFramework_TTearDownSystem_Map.insert({ nsECSFramework_TTearDownSystem_nsECSFramework_TSystem_rtti, nsECSFramework_TTearDownSystem_nsECSFramework_TSystem_Data });
    
    auto nsECSFramework_TTearDownSystem_rtti = globalTypeIdentifier->Type<nsECSFramework::TTearDownSystem>();
    
    m.insert({ nsECSFramework_TTearDownSystem_rtti, nsECSFramework_TTearDownSystem_Map });
    
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
void* TEcsDynamicCaster::Cast(int srcRtti, void* p, int dstRtti)
{
    Init();
    return mDataVector[dstRtti][srcRtti].castFunc(p);
}
//---------------------------------------------------------------------------------------
const std::map<int, std::set<int>>& TEcsDynamicCaster::GetRttiCombinations()
{
    Init();
    return mRttiCombinations;
}
//---------------------------------------------------------------------------------------
