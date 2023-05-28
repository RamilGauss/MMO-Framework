/*
Project Component
*/
// ReflectionCodeGenerator version 2.4.0, build 58 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, TypeInformation]
// File has been generated at 2023_05_28 17:59:37.828
	
#include "ComponentEntMng.h"

using namespace nsTornadoEditor;
using namespace nsECSFramework;

std::vector<TComponentEntMng::Data> TComponentEntMng::mRttiVector;

void TComponentEntMng::Init()
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
bool TComponentEntMng::Has(int rtti)
{
    Init();
    if (rtti < 0 || rtti >= mRttiVector.size()) {
        return false;
    }
    return mRttiVector[rtti].createFunc != nullptr;
}
//---------------------------------------------------------------------------------------
void TComponentEntMng::CreateComponent(TEntityManager* pEntMng, TEntityID eid, int rtti, std::function<void(void*)> onAfterCreation)
{
    Init();
    mRttiVector[rtti].createFunc(pEntMng, eid, onAfterCreation);
}
//---------------------------------------------------------------------------------------
void TComponentEntMng::SetComponent(TEntityManager* pEntMng, TEntityID eid, int rtti, void* p)
{
    Init();
    mRttiVector[rtti].setFunc(pEntMng, eid, p);
}
//---------------------------------------------------------------------------------------
const void* TComponentEntMng::ViewComponent(TEntityManager* pEntMng, TEntityID eid, int rtti)
{
    Init();
    return mRttiVector[rtti].viewFunc(pEntMng, eid);
}
//---------------------------------------------------------------------------------------
bool TComponentEntMng::HasComponent(TEntityManager* pEntMng, TEntityID eid, int rtti)
{
    Init();
    return mRttiVector[rtti].hasFunc(pEntMng, eid);
}
//---------------------------------------------------------------------------------------
void TComponentEntMng::RemoveComponent(TEntityManager* pEntMng, TEntityID eid, int rtti)
{
    Init();
    mRttiVector[rtti].removeFunc(pEntMng, eid);
}
//---------------------------------------------------------------------------------------
nsECSFramework::TEntityList TComponentEntMng::GetByHas(TEntityManager* pEntMng, int rtti)
{
    Init();
    return mRttiVector[rtti].getByHasFunc(pEntMng);
}
//---------------------------------------------------------------------------------------
