/*
	ReflectionCodeGeneratorTest
*/
// ReflectionCodeGenerator version 2.5.0, build 59 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, RTTI, TypeInformation]
// File has been generated at 2023_10_30 17:16:15.908
	
#include "EcsComponentExtensionExtension.h"

using namespace nsTest;
using namespace nsECSFramework;

std::vector<TEcsComponentExtensionExtension::Data> TEcsComponentExtensionExtension::mRttiVector;

void TEcsComponentExtensionExtension::Init()
{
    static bool isNeedInit = true;
    if (!isNeedInit) {
        return;
    }
    isNeedInit = false;
    
    auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();
    
    std::list<Data> datas;
    
    Data nsSimpleComponents_TNameComponent_Data;
    nsSimpleComponents_TNameComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsSimpleComponents::TNameComponent*)p)); };
    nsSimpleComponents_TNameComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsSimpleComponents::TNameComponent>(eid); };
    nsSimpleComponents_TNameComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsSimpleComponents::TNameComponent>(eid); };
    nsSimpleComponents_TNameComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsSimpleComponents::TNameComponent>(eid); };
    nsSimpleComponents_TNameComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsSimpleComponents::TNameComponent>(); };
    nsSimpleComponents_TNameComponent_Data.rtti = globalTypeIdentifier->Type<nsSimpleComponents::TNameComponent>();
    
    datas.push_back(nsSimpleComponents_TNameComponent_Data);
    
    Data nsSimpleComponents_TSimpleComponent_Data;
    nsSimpleComponents_TSimpleComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsSimpleComponents::TSimpleComponent*)p)); };
    nsSimpleComponents_TSimpleComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsSimpleComponents::TSimpleComponent>(eid); };
    nsSimpleComponents_TSimpleComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsSimpleComponents::TSimpleComponent>(eid); };
    nsSimpleComponents_TSimpleComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsSimpleComponents::TSimpleComponent>(eid); };
    nsSimpleComponents_TSimpleComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsSimpleComponents::TSimpleComponent>(); };
    nsSimpleComponents_TSimpleComponent_Data.rtti = globalTypeIdentifier->Type<nsSimpleComponents::TSimpleComponent>();
    
    datas.push_back(nsSimpleComponents_TSimpleComponent_Data);
    
    Data nsSimpleComponents_TSizeComponent_Data;
    nsSimpleComponents_TSizeComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsSimpleComponents::TSizeComponent*)p)); };
    nsSimpleComponents_TSizeComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsSimpleComponents::TSizeComponent>(eid); };
    nsSimpleComponents_TSizeComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsSimpleComponents::TSizeComponent>(eid); };
    nsSimpleComponents_TSizeComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsSimpleComponents::TSizeComponent>(eid); };
    nsSimpleComponents_TSizeComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsSimpleComponents::TSizeComponent>(); };
    nsSimpleComponents_TSizeComponent_Data.rtti = globalTypeIdentifier->Type<nsSimpleComponents::TSizeComponent>();
    
    datas.push_back(nsSimpleComponents_TSizeComponent_Data);
    
    Data nsSimpleComponents_TValueComponent_Data;
    nsSimpleComponents_TValueComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsSimpleComponents::TValueComponent*)p)); };
    nsSimpleComponents_TValueComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsSimpleComponents::TValueComponent>(eid); };
    nsSimpleComponents_TValueComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsSimpleComponents::TValueComponent>(eid); };
    nsSimpleComponents_TValueComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsSimpleComponents::TValueComponent>(eid); };
    nsSimpleComponents_TValueComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsSimpleComponents::TValueComponent>(); };
    nsSimpleComponents_TValueComponent_Data.rtti = globalTypeIdentifier->Type<nsSimpleComponents::TValueComponent>();
    
    datas.push_back(nsSimpleComponents_TValueComponent_Data);
    
    int max = 0;
    for (auto& d : datas) {
        max = std::max(d.rtti, max);
    }
    
    mRttiVector.resize(max + 1);
    for (auto& d : datas) {
        mRttiVector[d.rtti] = d;
    }
}
//---------------------------------------------------------------------------------------
bool TEcsComponentExtensionExtension::Has(int rtti)
{
    Init();
    if (rtti < 0 || rtti >= mRttiVector.size()) {
        return false;
    }
    return mRttiVector[rtti].setFunc != nullptr;
}
//---------------------------------------------------------------------------------------
void TEcsComponentExtensionExtension::SetComponent(TEntityManager* pEntMng, TEntityID eid, int rtti, void* p)
{
    Init();
    mRttiVector[rtti].setFunc(pEntMng, eid, p);
}
//---------------------------------------------------------------------------------------
const void* TEcsComponentExtensionExtension::ViewComponent(TEntityManager* pEntMng, TEntityID eid, int rtti)
{
    Init();
    return mRttiVector[rtti].viewFunc(pEntMng, eid);
}
//---------------------------------------------------------------------------------------
bool TEcsComponentExtensionExtension::HasComponent(TEntityManager* pEntMng, TEntityID eid, int rtti)
{
    Init();
    return mRttiVector[rtti].hasFunc(pEntMng, eid);
}
//---------------------------------------------------------------------------------------
void TEcsComponentExtensionExtension::RemoveComponent(TEntityManager* pEntMng, TEntityID eid, int rtti)
{
    Init();
    mRttiVector[rtti].removeFunc(pEntMng, eid);
}
//---------------------------------------------------------------------------------------
nsECSFramework::TEntityList TEcsComponentExtensionExtension::GetByHas(TEntityManager* pEntMng, int rtti)
{
    Init();
    return mRttiVector[rtti].getByHasFunc(pEntMng);
}
//---------------------------------------------------------------------------------------
