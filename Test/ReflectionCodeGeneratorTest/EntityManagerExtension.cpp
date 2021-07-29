/*
	ReflectionCodeGeneratorTest
*/
// ReflectionCodeGenerator version 2.2.1, build 52, info Json, Binary, ImGui, EntityManager, Reflection, TypeInformation
// File has been generated at 2021_07_29 08:27:54.139
	
#include "EntityManagerExtension.h"

using namespace nsEntityManagerExtension;
using namespace nsECSFramework;

std::vector<TEntityManagerExtension::Data> TEntityManagerExtension::mRttiVector;

void TEntityManagerExtension::Init()
{
    static bool isNeedInit = true;
    if (!isNeedInit) {
        return;
    }
    isNeedInit = false;
    
    auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();
    
    std::map<int, Data> m;
    
    Data nsSimpleComponents_TNameComponent_Data;
    nsSimpleComponents_TNameComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsSimpleComponents::TNameComponent*) p)); };
    nsSimpleComponents_TNameComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsSimpleComponents::TNameComponent>(eid); };
    nsSimpleComponents_TNameComponent_Data.getFunc = [](TEntityManager* pEntMng, TEntityID eid, void*& p){ return pEntMng->GetComponent<nsSimpleComponents::TNameComponent>(eid, *((nsSimpleComponents::TNameComponent*) p)); };
    nsSimpleComponents_TNameComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsSimpleComponents::TNameComponent>(eid); };
    nsSimpleComponents_TNameComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsSimpleComponents::TNameComponent>(eid); };
    auto rtti_nsSimpleComponents_TNameComponent_Data = globalTypeIdentifier->type<nsSimpleComponents::TNameComponent>();
    
    m.insert({ rtti_nsSimpleComponents_TNameComponent_Data, nsSimpleComponents_TNameComponent_Data });
    
    Data nsSimpleComponents_TSimpleComponent_Data;
    nsSimpleComponents_TSimpleComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsSimpleComponents::TSimpleComponent*) p)); };
    nsSimpleComponents_TSimpleComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsSimpleComponents::TSimpleComponent>(eid); };
    nsSimpleComponents_TSimpleComponent_Data.getFunc = [](TEntityManager* pEntMng, TEntityID eid, void*& p){ return pEntMng->GetComponent<nsSimpleComponents::TSimpleComponent>(eid, *((nsSimpleComponents::TSimpleComponent*) p)); };
    nsSimpleComponents_TSimpleComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsSimpleComponents::TSimpleComponent>(eid); };
    nsSimpleComponents_TSimpleComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsSimpleComponents::TSimpleComponent>(eid); };
    auto rtti_nsSimpleComponents_TSimpleComponent_Data = globalTypeIdentifier->type<nsSimpleComponents::TSimpleComponent>();
    
    m.insert({ rtti_nsSimpleComponents_TSimpleComponent_Data, nsSimpleComponents_TSimpleComponent_Data });
    
    Data nsSimpleComponents_TValueComponent_Data;
    nsSimpleComponents_TValueComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsSimpleComponents::TValueComponent*) p)); };
    nsSimpleComponents_TValueComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsSimpleComponents::TValueComponent>(eid); };
    nsSimpleComponents_TValueComponent_Data.getFunc = [](TEntityManager* pEntMng, TEntityID eid, void*& p){ return pEntMng->GetComponent<nsSimpleComponents::TValueComponent>(eid, *((nsSimpleComponents::TValueComponent*) p)); };
    nsSimpleComponents_TValueComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsSimpleComponents::TValueComponent>(eid); };
    nsSimpleComponents_TValueComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsSimpleComponents::TValueComponent>(eid); };
    auto rtti_nsSimpleComponents_TValueComponent_Data = globalTypeIdentifier->type<nsSimpleComponents::TValueComponent>();
    
    m.insert({ rtti_nsSimpleComponents_TValueComponent_Data, nsSimpleComponents_TValueComponent_Data });
    
    int max = 0;
    for (auto& vt : m) {
        max = std::max(vt.first, max);
    }
    
    mRttiVector.resize(max + 1);
    for (auto& vt : m) {
        mRttiVector[vt.first] = vt.second;
    }
}
//---------------------------------------------------------------------------------------
void TEntityManagerExtension::SetComponent(TEntityManager* pEntMng, TEntityID eid, void* p, int rtti)
{
    Init();
    mRttiVector[rtti].setFunc(pEntMng, eid, p);
}
//---------------------------------------------------------------------------------------
void* TEntityManagerExtension::ViewComponent(TEntityManager* pEntMng, TEntityID eid, int rtti)
{
    Init();
    return mRttiVector[rtti].viewFunc(pEntMng, eid);
}
//---------------------------------------------------------------------------------------
bool TEntityManagerExtension::GetComponent(TEntityManager* pEntMng, TEntityID eid, void*& p, int rtti)
{
    Init();
    return mRttiVector[rtti].getFunc(pEntMng, eid, p);
}
//---------------------------------------------------------------------------------------
bool TEntityManagerExtension::HasComponent(TEntityManager* pEntMng, TEntityID eid, int rtti)
{
    Init();
    return mRttiVector[rtti].hasFunc(pEntMng, eid);
}
//---------------------------------------------------------------------------------------
void TEntityManagerExtension::RemoveComponent(TEntityManager* pEntMng, TEntityID eid, int rtti)
{
    Init();
    mRttiVector[rtti].removeFunc(pEntMng, eid);
}
//---------------------------------------------------------------------------------------
