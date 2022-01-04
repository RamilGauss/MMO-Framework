/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.2.5, build 56 [Json, Binary, ImGui, EntityManager, Reflection, TypeInformation]
// File has been generated at 2022_01_04 21:13:18.808
	
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
    
    Data nsTornadoEditor_TAbsoluteFilePathComponent_Data;
        nsTornadoEditor_TAbsoluteFilePathComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsTornadoEditor::TAbsoluteFilePathComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsTornadoEditor::TAbsoluteFilePathComponent>(eid, lambda, isNotify);
    };
    nsTornadoEditor_TAbsoluteFilePathComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsTornadoEditor::TAbsoluteFilePathComponent*)p), isNotify); };
    nsTornadoEditor_TAbsoluteFilePathComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsTornadoEditor::TAbsoluteFilePathComponent>(eid); };
    nsTornadoEditor_TAbsoluteFilePathComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsTornadoEditor::TAbsoluteFilePathComponent>(eid); };
    nsTornadoEditor_TAbsoluteFilePathComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsTornadoEditor::TAbsoluteFilePathComponent>(eid); };
    nsTornadoEditor_TAbsoluteFilePathComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsTornadoEditor::TAbsoluteFilePathComponent>(); };
    auto rtti_nsTornadoEditor_TAbsoluteFilePathComponent_Data = globalTypeIdentifier->Type<nsTornadoEditor::TAbsoluteFilePathComponent>();
    
    m.insert({ rtti_nsTornadoEditor_TAbsoluteFilePathComponent_Data, nsTornadoEditor_TAbsoluteFilePathComponent_Data });
    
    Data nsTornadoEditor_TEditorInfoTagComponent_Data;
        nsTornadoEditor_TEditorInfoTagComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsTornadoEditor::TEditorInfoTagComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsTornadoEditor::TEditorInfoTagComponent>(eid, lambda, isNotify);
    };
    nsTornadoEditor_TEditorInfoTagComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsTornadoEditor::TEditorInfoTagComponent*)p), isNotify); };
    nsTornadoEditor_TEditorInfoTagComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsTornadoEditor::TEditorInfoTagComponent>(eid); };
    nsTornadoEditor_TEditorInfoTagComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsTornadoEditor::TEditorInfoTagComponent>(eid); };
    nsTornadoEditor_TEditorInfoTagComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsTornadoEditor::TEditorInfoTagComponent>(eid); };
    nsTornadoEditor_TEditorInfoTagComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsTornadoEditor::TEditorInfoTagComponent>(); };
    auto rtti_nsTornadoEditor_TEditorInfoTagComponent_Data = globalTypeIdentifier->Type<nsTornadoEditor::TEditorInfoTagComponent>();
    
    m.insert({ rtti_nsTornadoEditor_TEditorInfoTagComponent_Data, nsTornadoEditor_TEditorInfoTagComponent_Data });
    
    Data nsTornadoEditor_TFileHierarchyWindowTagComponent_Data;
        nsTornadoEditor_TFileHierarchyWindowTagComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsTornadoEditor::TFileHierarchyWindowTagComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsTornadoEditor::TFileHierarchyWindowTagComponent>(eid, lambda, isNotify);
    };
    nsTornadoEditor_TFileHierarchyWindowTagComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsTornadoEditor::TFileHierarchyWindowTagComponent*)p), isNotify); };
    nsTornadoEditor_TFileHierarchyWindowTagComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsTornadoEditor::TFileHierarchyWindowTagComponent>(eid); };
    nsTornadoEditor_TFileHierarchyWindowTagComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsTornadoEditor::TFileHierarchyWindowTagComponent>(eid); };
    nsTornadoEditor_TFileHierarchyWindowTagComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsTornadoEditor::TFileHierarchyWindowTagComponent>(eid); };
    nsTornadoEditor_TFileHierarchyWindowTagComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsTornadoEditor::TFileHierarchyWindowTagComponent>(); };
    auto rtti_nsTornadoEditor_TFileHierarchyWindowTagComponent_Data = globalTypeIdentifier->Type<nsTornadoEditor::TFileHierarchyWindowTagComponent>();
    
    m.insert({ rtti_nsTornadoEditor_TFileHierarchyWindowTagComponent_Data, nsTornadoEditor_TFileHierarchyWindowTagComponent_Data });
    
    Data nsTornadoEditor_TFilePathNodeComponent_Data;
        nsTornadoEditor_TFilePathNodeComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsTornadoEditor::TFilePathNodeComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsTornadoEditor::TFilePathNodeComponent>(eid, lambda, isNotify);
    };
    nsTornadoEditor_TFilePathNodeComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsTornadoEditor::TFilePathNodeComponent*)p), isNotify); };
    nsTornadoEditor_TFilePathNodeComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsTornadoEditor::TFilePathNodeComponent>(eid); };
    nsTornadoEditor_TFilePathNodeComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsTornadoEditor::TFilePathNodeComponent>(eid); };
    nsTornadoEditor_TFilePathNodeComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsTornadoEditor::TFilePathNodeComponent>(eid); };
    nsTornadoEditor_TFilePathNodeComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsTornadoEditor::TFilePathNodeComponent>(); };
    auto rtti_nsTornadoEditor_TFilePathNodeComponent_Data = globalTypeIdentifier->Type<nsTornadoEditor::TFilePathNodeComponent>();
    
    m.insert({ rtti_nsTornadoEditor_TFilePathNodeComponent_Data, nsTornadoEditor_TFilePathNodeComponent_Data });
    
    Data nsTornadoEditor_TProjectConfigComponent_Data;
        nsTornadoEditor_TProjectConfigComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsTornadoEditor::TProjectConfigComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsTornadoEditor::TProjectConfigComponent>(eid, lambda, isNotify);
    };
    nsTornadoEditor_TProjectConfigComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsTornadoEditor::TProjectConfigComponent*)p), isNotify); };
    nsTornadoEditor_TProjectConfigComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsTornadoEditor::TProjectConfigComponent>(eid); };
    nsTornadoEditor_TProjectConfigComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsTornadoEditor::TProjectConfigComponent>(eid); };
    nsTornadoEditor_TProjectConfigComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsTornadoEditor::TProjectConfigComponent>(eid); };
    nsTornadoEditor_TProjectConfigComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsTornadoEditor::TProjectConfigComponent>(); };
    auto rtti_nsTornadoEditor_TProjectConfigComponent_Data = globalTypeIdentifier->Type<nsTornadoEditor::TProjectConfigComponent>();
    
    m.insert({ rtti_nsTornadoEditor_TProjectConfigComponent_Data, nsTornadoEditor_TProjectConfigComponent_Data });
    
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
nsECSFramework::TEntityList TComponentEntityManagerExtension::GetByHas(TEntityManager* pEntMng, int rtti)
{
    Init();
    return mRttiVector[rtti].getByHasFunc(pEntMng);
}
//---------------------------------------------------------------------------------------
