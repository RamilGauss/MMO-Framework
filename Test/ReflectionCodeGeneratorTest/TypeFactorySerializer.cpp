/*
	ReflectionCodeGeneratorTest
*/
// ReflectionCodeGenerator version 2.5.0, build 59 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, RTTI, TypeInformation]
// File has been generated at 2023_10_30 17:47:51.205
	
#include "TypeFactorySerializer.h"
#include "Base/Common/SingletonManager.h"
#include "Base/Common/RunTimeTypeIndex.h"

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
    
    std::list<Data> datas;
    
    Data ExecuteSystem_Data;
    ExecuteSystem_Data.newFunc = [](){ return new ExecuteSystem(); };
    ExecuteSystem_Data.deleteFunc = [](void* p){ delete (ExecuteSystem*)p; };
    ExecuteSystem_Data.rtti = globalTypeIdentifier->Type<ExecuteSystem>();
    
    datas.push_back(ExecuteSystem_Data);
    
    Data Feature_Data;
    Feature_Data.newFunc = [](){ return new Feature(); };
    Feature_Data.deleteFunc = [](void* p){ delete (Feature*)p; };
    Feature_Data.rtti = globalTypeIdentifier->Type<Feature>();
    
    datas.push_back(Feature_Data);
    
    Data InitSystem_Data;
    InitSystem_Data.newFunc = [](){ return new InitSystem(); };
    InitSystem_Data.deleteFunc = [](void* p){ delete (InitSystem*)p; };
    InitSystem_Data.rtti = globalTypeIdentifier->Type<InitSystem>();
    
    datas.push_back(InitSystem_Data);
    
    Data OnAddCollect_Data;
    OnAddCollect_Data.newFunc = [](){ return new OnAddCollect(); };
    OnAddCollect_Data.deleteFunc = [](void* p){ delete (OnAddCollect*)p; };
    OnAddCollect_Data.rtti = globalTypeIdentifier->Type<OnAddCollect>();
    
    datas.push_back(OnAddCollect_Data);
    
    Data OnAddInstant_Data;
    OnAddInstant_Data.newFunc = [](){ return new OnAddInstant(); };
    OnAddInstant_Data.deleteFunc = [](void* p){ delete (OnAddInstant*)p; };
    OnAddInstant_Data.rtti = globalTypeIdentifier->Type<OnAddInstant>();
    
    datas.push_back(OnAddInstant_Data);
    
    Data OnRemoveInstant_Data;
    OnRemoveInstant_Data.newFunc = [](){ return new OnRemoveInstant(); };
    OnRemoveInstant_Data.deleteFunc = [](void* p){ delete (OnRemoveInstant*)p; };
    OnRemoveInstant_Data.rtti = globalTypeIdentifier->Type<OnRemoveInstant>();
    
    datas.push_back(OnRemoveInstant_Data);
    
    Data OnUpdateCollect_Data;
    OnUpdateCollect_Data.newFunc = [](){ return new OnUpdateCollect(); };
    OnUpdateCollect_Data.deleteFunc = [](void* p){ delete (OnUpdateCollect*)p; };
    OnUpdateCollect_Data.rtti = globalTypeIdentifier->Type<OnUpdateCollect>();
    
    datas.push_back(OnUpdateCollect_Data);
    
    Data OnUpdateInstant_Data;
    OnUpdateInstant_Data.newFunc = [](){ return new OnUpdateInstant(); };
    OnUpdateInstant_Data.deleteFunc = [](void* p){ delete (OnUpdateInstant*)p; };
    OnUpdateInstant_Data.rtti = globalTypeIdentifier->Type<OnUpdateInstant>();
    
    datas.push_back(OnUpdateInstant_Data);
    
    Data System_Data;
    System_Data.newFunc = [](){ return new System(); };
    System_Data.deleteFunc = [](void* p){ delete (System*)p; };
    System_Data.rtti = globalTypeIdentifier->Type<System>();
    
    datas.push_back(System_Data);
    
    Data TUnit_Data;
    TUnit_Data.newFunc = [](){ return new TUnit(); };
    TUnit_Data.deleteFunc = [](void* p){ delete (TUnit*)p; };
    TUnit_Data.rtti = globalTypeIdentifier->Type<TUnit>();
    
    datas.push_back(TUnit_Data);
    
    Data TearDownSystem_Data;
    TearDownSystem_Data.newFunc = [](){ return new TearDownSystem(); };
    TearDownSystem_Data.deleteFunc = [](void* p){ delete (TearDownSystem*)p; };
    TearDownSystem_Data.rtti = globalTypeIdentifier->Type<TearDownSystem>();
    
    datas.push_back(TearDownSystem_Data);
    
    Data nsAllTypes_A_Data;
    nsAllTypes_A_Data.newFunc = [](){ return new nsAllTypes::A(); };
    nsAllTypes_A_Data.deleteFunc = [](void* p){ delete (nsAllTypes::A*)p; };
    nsAllTypes_A_Data.rtti = globalTypeIdentifier->Type<nsAllTypes::A>();
    
    datas.push_back(nsAllTypes_A_Data);
    
    Data nsAllTypes_B_Data;
    nsAllTypes_B_Data.newFunc = [](){ return new nsAllTypes::B(); };
    nsAllTypes_B_Data.deleteFunc = [](void* p){ delete (nsAllTypes::B*)p; };
    nsAllTypes_B_Data.rtti = globalTypeIdentifier->Type<nsAllTypes::B>();
    
    datas.push_back(nsAllTypes_B_Data);
    
    Data nsAllTypes_C_Data;
    nsAllTypes_C_Data.newFunc = [](){ return new nsAllTypes::C(); };
    nsAllTypes_C_Data.deleteFunc = [](void* p){ delete (nsAllTypes::C*)p; };
    nsAllTypes_C_Data.rtti = globalTypeIdentifier->Type<nsAllTypes::C>();
    
    datas.push_back(nsAllTypes_C_Data);
    
    Data nsSimpleComponents_TNameComponent_Data;
    nsSimpleComponents_TNameComponent_Data.newFunc = [](){ return new nsSimpleComponents::TNameComponent(); };
    nsSimpleComponents_TNameComponent_Data.deleteFunc = [](void* p){ delete (nsSimpleComponents::TNameComponent*)p; };
    nsSimpleComponents_TNameComponent_Data.rtti = globalTypeIdentifier->Type<nsSimpleComponents::TNameComponent>();
    
    datas.push_back(nsSimpleComponents_TNameComponent_Data);
    
    Data nsSimpleComponents_TSimpleComponent_Data;
    nsSimpleComponents_TSimpleComponent_Data.newFunc = [](){ return new nsSimpleComponents::TSimpleComponent(); };
    nsSimpleComponents_TSimpleComponent_Data.deleteFunc = [](void* p){ delete (nsSimpleComponents::TSimpleComponent*)p; };
    nsSimpleComponents_TSimpleComponent_Data.rtti = globalTypeIdentifier->Type<nsSimpleComponents::TSimpleComponent>();
    
    datas.push_back(nsSimpleComponents_TSimpleComponent_Data);
    
    Data nsSimpleComponents_TSizeComponent_Data;
    nsSimpleComponents_TSizeComponent_Data.newFunc = [](){ return new nsSimpleComponents::TSizeComponent(); };
    nsSimpleComponents_TSizeComponent_Data.deleteFunc = [](void* p){ delete (nsSimpleComponents::TSizeComponent*)p; };
    nsSimpleComponents_TSizeComponent_Data.rtti = globalTypeIdentifier->Type<nsSimpleComponents::TSizeComponent>();
    
    datas.push_back(nsSimpleComponents_TSizeComponent_Data);
    
    Data nsSimpleComponents_TValueComponent_Data;
    nsSimpleComponents_TValueComponent_Data.newFunc = [](){ return new nsSimpleComponents::TValueComponent(); };
    nsSimpleComponents_TValueComponent_Data.deleteFunc = [](void* p){ delete (nsSimpleComponents::TValueComponent*)p; };
    nsSimpleComponents_TValueComponent_Data.rtti = globalTypeIdentifier->Type<nsSimpleComponents::TValueComponent>();
    
    datas.push_back(nsSimpleComponents_TValueComponent_Data);
    
    int max = 0;
    for (auto& d : datas) {
        max = std::max(d.rtti, max);
    }
    
    mDataVector.resize(max + 1);
    for (auto& d : datas) {
        mDataVector[d.rtti] = d;
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
