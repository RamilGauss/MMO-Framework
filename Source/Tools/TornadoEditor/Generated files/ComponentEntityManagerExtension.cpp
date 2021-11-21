/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.2.2, build 53 [Json, Binary, ImGui, EntityManager, Reflection, TypeInformation]
// File has been generated at 2021_11_21 15:06:53.155
	
#include "ComponentEntityManagerExtension.h"

using namespace nsTornadoEditor;
using namespace nsECSFramework;

std::vector<TComponentEntityManagerExtension::Data> TComponentEntityManagerExtension::mRttiVector;

void TComponentEntityManagerExtension::Init()
{
    static bool isNeedInit = true;
    if (!isNeedInit) {
        return;
    }
    isNeedInit = false;
    
    auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();
    
    std::map<int, Data> m;
    
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
bool TComponentEntityManagerExtension::Has(int rtti)
{
    Init();
    if (rtti < 0 || rtti >= mRttiVector.size()) {
        return false;
    }
    return mRttiVector[rtti].addFunc != nullptr;
}
//---------------------------------------------------------------------------------------
void TComponentEntityManagerExtension::AddComponent(TEntityManager* pEntMng, TEntityID eid, int rtti)
{
    Init();
    mRttiVector[rtti].addFunc(pEntMng, eid);
}
//---------------------------------------------------------------------------------------
void TComponentEntityManagerExtension::SetComponent(TEntityManager* pEntMng, TEntityID eid, void* p, int rtti)
{
    Init();
    mRttiVector[rtti].setFunc(pEntMng, eid, p);
}
//---------------------------------------------------------------------------------------
void* TComponentEntityManagerExtension::ViewComponent(TEntityManager* pEntMng, TEntityID eid, int rtti)
{
    Init();
    return mRttiVector[rtti].viewFunc(pEntMng, eid);
}
//---------------------------------------------------------------------------------------
bool TComponentEntityManagerExtension::GetComponent(TEntityManager* pEntMng, TEntityID eid, void*& p, int rtti)
{
    Init();
    return mRttiVector[rtti].getFunc(pEntMng, eid, p);
}
//---------------------------------------------------------------------------------------
bool TComponentEntityManagerExtension::HasComponent(TEntityManager* pEntMng, TEntityID eid, int rtti)
{
    Init();
    return mRttiVector[rtti].hasFunc(pEntMng, eid);
}
//---------------------------------------------------------------------------------------
void TComponentEntityManagerExtension::RemoveComponent(TEntityManager* pEntMng, TEntityID eid, int rtti)
{
    Init();
    mRttiVector[rtti].removeFunc(pEntMng, eid);
}
//---------------------------------------------------------------------------------------
