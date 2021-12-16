/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.2.4, build 55 [Json, Binary, ImGui, EntityManager, Reflection, TypeInformation]
// File has been generated at 2021_12_16 21:29:14.582
	
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
    return mRttiVector[rtti].createFunc != nullptr;
}
//---------------------------------------------------------------------------------------
void TComponentEntityManagerExtension::CreateComponent(TEntityManager* pEntMng, TEntityID eid, int rtti, std::function<void(void*)> onAfterCreation, bool isNotify)
{
    Init();
    mRttiVector[rtti].createFunc(pEntMng, eid, onAfterCreation, isNotify);
}
//---------------------------------------------------------------------------------------
void TComponentEntityManagerExtension::SetComponent(TEntityManager* pEntMng, TEntityID eid, int rtti, void* p, bool isNotify)
{
    Init();
    mRttiVector[rtti].setFunc(pEntMng, eid, p, isNotify);
}
//---------------------------------------------------------------------------------------
const void* TComponentEntityManagerExtension::ViewComponent(TEntityManager* pEntMng, TEntityID eid, int rtti)
{
    Init();
    return mRttiVector[rtti].viewFunc(pEntMng, eid);
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
