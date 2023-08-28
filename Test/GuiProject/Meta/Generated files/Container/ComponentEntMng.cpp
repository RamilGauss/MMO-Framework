/*
Project Component
*/
// ReflectionCodeGenerator version 2.4.0, build 58 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, TypeInformation]
// File has been generated at 2023_08_28 11:41:40.855
	
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
    
    Data nsGuiProject_TScenePrefabTestComponent_Data;
        nsGuiProject_TScenePrefabTestComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsGuiProject::TScenePrefabTestComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsGuiProject::TScenePrefabTestComponent>(eid, lambda);
    };
    nsGuiProject_TScenePrefabTestComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsGuiProject::TScenePrefabTestComponent*)p)); };
    nsGuiProject_TScenePrefabTestComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsGuiProject::TScenePrefabTestComponent>(eid); };
    nsGuiProject_TScenePrefabTestComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsGuiProject::TScenePrefabTestComponent>(eid); };
    nsGuiProject_TScenePrefabTestComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsGuiProject::TScenePrefabTestComponent>(eid); };
    nsGuiProject_TScenePrefabTestComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsGuiProject::TScenePrefabTestComponent>(); };
    auto rtti_nsGuiProject_TScenePrefabTestComponent_Data = globalTypeIdentifier->Type<nsGuiProject::TScenePrefabTestComponent>();
    
    m.insert({ rtti_nsGuiProject_TScenePrefabTestComponent_Data, nsGuiProject_TScenePrefabTestComponent_Data });
    
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
