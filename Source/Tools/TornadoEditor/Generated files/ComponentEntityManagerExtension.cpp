/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.2.1, build 52 [Json, Binary, ImGui, EntityManager, Reflection, TypeInformation]
// File has been generated at 2021_11_03 08:34:17.337
	
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
