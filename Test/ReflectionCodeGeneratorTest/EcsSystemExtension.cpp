/*
	ReflectionCodeGeneratorTest
*/
// ReflectionCodeGenerator version 2.3.0, build 57 [Json, Binary, ImGui, EcsComponentExtension, EcsSystemExtension, Reflection, TypeInformation]
// File has been generated at 2022_09_18 22:21:05.444
	
#include "EcsSystemExtension.h"
#include "SingletonManager.h"
#include "RunTimeTypeIndex.h"

using namespace nsTest;

std::vector<TEcsSystemExtension::Data> TEcsSystemExtension::mDataVector;
void TEcsSystemExtension::Init()
{
    static bool isNeedInit = true;
    if ( !isNeedInit )
    {
        return;
    }
    isNeedInit = false;
    
    auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();
    
    std::map<int, Data> m;
    
    Data ExecuteSystem_Data;
    ExecuteSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<ExecuteSystem*>(p)); };
    auto rtti_ExecuteSystem_Data = globalTypeIdentifier->Type<ExecuteSystem>();
    
    m.insert({ rtti_ExecuteSystem_Data, ExecuteSystem_Data });
    
    Data Feature_Data;
    Feature_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<Feature*>(p)); };
    auto rtti_Feature_Data = globalTypeIdentifier->Type<Feature>();
    
    m.insert({ rtti_Feature_Data, Feature_Data });
    
    Data InitSystem_Data;
    InitSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<InitSystem*>(p)); };
    auto rtti_InitSystem_Data = globalTypeIdentifier->Type<InitSystem>();
    
    m.insert({ rtti_InitSystem_Data, InitSystem_Data });
    
    Data TearDownSystem_Data;
    TearDownSystem_Data.castFunc = [](void* p){ return dynamic_cast<nsECSFramework::TSystem*>(static_cast<TearDownSystem*>(p)); };
    auto rtti_TearDownSystem_Data = globalTypeIdentifier->Type<TearDownSystem>();
    
    m.insert({ rtti_TearDownSystem_Data, TearDownSystem_Data });
    
    int max = 0;
    for (auto& vt : m) {
        max = std::max(vt.first, max);
    }
    
    mDataVector.resize(max + 1);
    for (auto& vt : m) {
        mDataVector[vt.first] = vt.second;
    }
}
//---------------------------------------------------------------------------------------
nsECSFramework::TSystem* TEcsSystemExtension::DynamicCast(void* p, int rtti)
{
    Init();
    return mDataVector[rtti].castFunc(p);
}
//---------------------------------------------------------------------------------------
