/*
	ReflectionCodeGeneratorTest
*/
// ReflectionCodeGenerator version 2.3.0, build 57 [Json, Binary, ImGui, EcsComponentExtension, EcsSystemExtension, Reflection, TypeInformation]
// File has been generated at 2022_05_27 20:01:08.033
	
#include "TypeFactorySerializer.h"
#include "SingletonManager.h"
#include "RunTimeTypeIndex.h"

using namespace nsTypeFactory;

std::vector<TTypeFactorySerializer::Data> TTypeFactorySerializer::mDataVector;
void TTypeFactorySerializer::Init()
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
    ExecuteSystem_Data.newFunc = [](){ return new ExecuteSystem(); };
    ExecuteSystem_Data.deleteFunc = [](void* p){ delete (ExecuteSystem*)p; };
    auto rtti_ExecuteSystem_Data = globalTypeIdentifier->Type<ExecuteSystem>();
    
    m.insert({ rtti_ExecuteSystem_Data, ExecuteSystem_Data });
    
    Data Feature_Data;
    Feature_Data.newFunc = [](){ return new Feature(); };
    Feature_Data.deleteFunc = [](void* p){ delete (Feature*)p; };
    auto rtti_Feature_Data = globalTypeIdentifier->Type<Feature>();
    
    m.insert({ rtti_Feature_Data, Feature_Data });
    
    Data InitSystem_Data;
    InitSystem_Data.newFunc = [](){ return new InitSystem(); };
    InitSystem_Data.deleteFunc = [](void* p){ delete (InitSystem*)p; };
    auto rtti_InitSystem_Data = globalTypeIdentifier->Type<InitSystem>();
    
    m.insert({ rtti_InitSystem_Data, InitSystem_Data });
    
    Data OnAddCollect_Data;
    OnAddCollect_Data.newFunc = [](){ return new OnAddCollect(); };
    OnAddCollect_Data.deleteFunc = [](void* p){ delete (OnAddCollect*)p; };
    auto rtti_OnAddCollect_Data = globalTypeIdentifier->Type<OnAddCollect>();
    
    m.insert({ rtti_OnAddCollect_Data, OnAddCollect_Data });
    
    Data OnAddInstant_Data;
    OnAddInstant_Data.newFunc = [](){ return new OnAddInstant(); };
    OnAddInstant_Data.deleteFunc = [](void* p){ delete (OnAddInstant*)p; };
    auto rtti_OnAddInstant_Data = globalTypeIdentifier->Type<OnAddInstant>();
    
    m.insert({ rtti_OnAddInstant_Data, OnAddInstant_Data });
    
    Data OnRemoveInstant_Data;
    OnRemoveInstant_Data.newFunc = [](){ return new OnRemoveInstant(); };
    OnRemoveInstant_Data.deleteFunc = [](void* p){ delete (OnRemoveInstant*)p; };
    auto rtti_OnRemoveInstant_Data = globalTypeIdentifier->Type<OnRemoveInstant>();
    
    m.insert({ rtti_OnRemoveInstant_Data, OnRemoveInstant_Data });
    
    Data OnUpdateCollect_Data;
    OnUpdateCollect_Data.newFunc = [](){ return new OnUpdateCollect(); };
    OnUpdateCollect_Data.deleteFunc = [](void* p){ delete (OnUpdateCollect*)p; };
    auto rtti_OnUpdateCollect_Data = globalTypeIdentifier->Type<OnUpdateCollect>();
    
    m.insert({ rtti_OnUpdateCollect_Data, OnUpdateCollect_Data });
    
    Data OnUpdateInstant_Data;
    OnUpdateInstant_Data.newFunc = [](){ return new OnUpdateInstant(); };
    OnUpdateInstant_Data.deleteFunc = [](void* p){ delete (OnUpdateInstant*)p; };
    auto rtti_OnUpdateInstant_Data = globalTypeIdentifier->Type<OnUpdateInstant>();
    
    m.insert({ rtti_OnUpdateInstant_Data, OnUpdateInstant_Data });
    
    Data System_Data;
    System_Data.newFunc = [](){ return new System(); };
    System_Data.deleteFunc = [](void* p){ delete (System*)p; };
    auto rtti_System_Data = globalTypeIdentifier->Type<System>();
    
    m.insert({ rtti_System_Data, System_Data });
    
    Data TearDownSystem_Data;
    TearDownSystem_Data.newFunc = [](){ return new TearDownSystem(); };
    TearDownSystem_Data.deleteFunc = [](void* p){ delete (TearDownSystem*)p; };
    auto rtti_TearDownSystem_Data = globalTypeIdentifier->Type<TearDownSystem>();
    
    m.insert({ rtti_TearDownSystem_Data, TearDownSystem_Data });
    
    Data nsAllTypes_A_Data;
    nsAllTypes_A_Data.newFunc = [](){ return new nsAllTypes::A(); };
    nsAllTypes_A_Data.deleteFunc = [](void* p){ delete (nsAllTypes::A*)p; };
    auto rtti_nsAllTypes_A_Data = globalTypeIdentifier->Type<nsAllTypes::A>();
    
    m.insert({ rtti_nsAllTypes_A_Data, nsAllTypes_A_Data });
    
    Data nsAllTypes_B_Data;
    nsAllTypes_B_Data.newFunc = [](){ return new nsAllTypes::B(); };
    nsAllTypes_B_Data.deleteFunc = [](void* p){ delete (nsAllTypes::B*)p; };
    auto rtti_nsAllTypes_B_Data = globalTypeIdentifier->Type<nsAllTypes::B>();
    
    m.insert({ rtti_nsAllTypes_B_Data, nsAllTypes_B_Data });
    
    Data nsAllTypes_C_Data;
    nsAllTypes_C_Data.newFunc = [](){ return new nsAllTypes::C(); };
    nsAllTypes_C_Data.deleteFunc = [](void* p){ delete (nsAllTypes::C*)p; };
    auto rtti_nsAllTypes_C_Data = globalTypeIdentifier->Type<nsAllTypes::C>();
    
    m.insert({ rtti_nsAllTypes_C_Data, nsAllTypes_C_Data });
    
    Data nsSimpleComponents_TNameComponent_Data;
    nsSimpleComponents_TNameComponent_Data.newFunc = [](){ return new nsSimpleComponents::TNameComponent(); };
    nsSimpleComponents_TNameComponent_Data.deleteFunc = [](void* p){ delete (nsSimpleComponents::TNameComponent*)p; };
    auto rtti_nsSimpleComponents_TNameComponent_Data = globalTypeIdentifier->Type<nsSimpleComponents::TNameComponent>();
    
    m.insert({ rtti_nsSimpleComponents_TNameComponent_Data, nsSimpleComponents_TNameComponent_Data });
    
    Data nsSimpleComponents_TSimpleComponent_Data;
    nsSimpleComponents_TSimpleComponent_Data.newFunc = [](){ return new nsSimpleComponents::TSimpleComponent(); };
    nsSimpleComponents_TSimpleComponent_Data.deleteFunc = [](void* p){ delete (nsSimpleComponents::TSimpleComponent*)p; };
    auto rtti_nsSimpleComponents_TSimpleComponent_Data = globalTypeIdentifier->Type<nsSimpleComponents::TSimpleComponent>();
    
    m.insert({ rtti_nsSimpleComponents_TSimpleComponent_Data, nsSimpleComponents_TSimpleComponent_Data });
    
    Data nsSimpleComponents_TValueComponent_Data;
    nsSimpleComponents_TValueComponent_Data.newFunc = [](){ return new nsSimpleComponents::TValueComponent(); };
    nsSimpleComponents_TValueComponent_Data.deleteFunc = [](void* p){ delete (nsSimpleComponents::TValueComponent*)p; };
    auto rtti_nsSimpleComponents_TValueComponent_Data = globalTypeIdentifier->Type<nsSimpleComponents::TValueComponent>();
    
    m.insert({ rtti_nsSimpleComponents_TValueComponent_Data, nsSimpleComponents_TValueComponent_Data });
    
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
void* TTypeFactorySerializer::New(int rtti)
{
    Init();
    return mDataVector[rtti].newFunc();
}
//---------------------------------------------------------------------------------------
void TTypeFactorySerializer::Delete(void* p, int rtti)
{
    Init();
    mDataVector[rtti].deleteFunc(p);
}
//---------------------------------------------------------------------------------------
bool TTypeFactorySerializer::Has(int rtti)
{
    Init();
    if (rtti < 0 || rtti >= mDataVector.size()) {
        return false;
    }
    return mDataVector[rtti].deleteFunc != nullptr;
}
//---------------------------------------------------------------------------------------
