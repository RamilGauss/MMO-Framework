/*
Project Component
*/
// ReflectionCodeGenerator version 2.4.0, build 58 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, TypeInformation]
// File has been generated at 2023_09_10 14:45:38.734
	
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
    
    Data nsTornadoEditor_TAbsoluteFilePathComponent_Data;
        nsTornadoEditor_TAbsoluteFilePathComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsTornadoEditor::TAbsoluteFilePathComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsTornadoEditor::TAbsoluteFilePathComponent>(eid, lambda);
    };
    nsTornadoEditor_TAbsoluteFilePathComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsTornadoEditor::TAbsoluteFilePathComponent*)p)); };
    nsTornadoEditor_TAbsoluteFilePathComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsTornadoEditor::TAbsoluteFilePathComponent>(eid); };
    nsTornadoEditor_TAbsoluteFilePathComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsTornadoEditor::TAbsoluteFilePathComponent>(eid); };
    nsTornadoEditor_TAbsoluteFilePathComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsTornadoEditor::TAbsoluteFilePathComponent>(eid); };
    nsTornadoEditor_TAbsoluteFilePathComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsTornadoEditor::TAbsoluteFilePathComponent>(); };
    auto rtti_nsTornadoEditor_TAbsoluteFilePathComponent_Data = globalTypeIdentifier->Type<nsTornadoEditor::TAbsoluteFilePathComponent>();
    
    m.insert({ rtti_nsTornadoEditor_TAbsoluteFilePathComponent_Data, nsTornadoEditor_TAbsoluteFilePathComponent_Data });
    
    Data nsTornadoEditor_TAssetAbsoluteFilePathComponent_Data;
        nsTornadoEditor_TAssetAbsoluteFilePathComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsTornadoEditor::TAssetAbsoluteFilePathComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsTornadoEditor::TAssetAbsoluteFilePathComponent>(eid, lambda);
    };
    nsTornadoEditor_TAssetAbsoluteFilePathComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsTornadoEditor::TAssetAbsoluteFilePathComponent*)p)); };
    nsTornadoEditor_TAssetAbsoluteFilePathComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsTornadoEditor::TAssetAbsoluteFilePathComponent>(eid); };
    nsTornadoEditor_TAssetAbsoluteFilePathComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsTornadoEditor::TAssetAbsoluteFilePathComponent>(eid); };
    nsTornadoEditor_TAssetAbsoluteFilePathComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsTornadoEditor::TAssetAbsoluteFilePathComponent>(eid); };
    nsTornadoEditor_TAssetAbsoluteFilePathComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsTornadoEditor::TAssetAbsoluteFilePathComponent>(); };
    auto rtti_nsTornadoEditor_TAssetAbsoluteFilePathComponent_Data = globalTypeIdentifier->Type<nsTornadoEditor::TAssetAbsoluteFilePathComponent>();
    
    m.insert({ rtti_nsTornadoEditor_TAssetAbsoluteFilePathComponent_Data, nsTornadoEditor_TAssetAbsoluteFilePathComponent_Data });
    
    Data nsTornadoEditor_TEditorInfoTagComponent_Data;
        nsTornadoEditor_TEditorInfoTagComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsTornadoEditor::TEditorInfoTagComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsTornadoEditor::TEditorInfoTagComponent>(eid, lambda);
    };
    nsTornadoEditor_TEditorInfoTagComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsTornadoEditor::TEditorInfoTagComponent*)p)); };
    nsTornadoEditor_TEditorInfoTagComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsTornadoEditor::TEditorInfoTagComponent>(eid); };
    nsTornadoEditor_TEditorInfoTagComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsTornadoEditor::TEditorInfoTagComponent>(eid); };
    nsTornadoEditor_TEditorInfoTagComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsTornadoEditor::TEditorInfoTagComponent>(eid); };
    nsTornadoEditor_TEditorInfoTagComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsTornadoEditor::TEditorInfoTagComponent>(); };
    auto rtti_nsTornadoEditor_TEditorInfoTagComponent_Data = globalTypeIdentifier->Type<nsTornadoEditor::TEditorInfoTagComponent>();
    
    m.insert({ rtti_nsTornadoEditor_TEditorInfoTagComponent_Data, nsTornadoEditor_TEditorInfoTagComponent_Data });
    
    Data nsTornadoEditor_TFileHierarchyWindowRefreshTagComponent_Data;
        nsTornadoEditor_TFileHierarchyWindowRefreshTagComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsTornadoEditor::TFileHierarchyWindowRefreshTagComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsTornadoEditor::TFileHierarchyWindowRefreshTagComponent>(eid, lambda);
    };
    nsTornadoEditor_TFileHierarchyWindowRefreshTagComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsTornadoEditor::TFileHierarchyWindowRefreshTagComponent*)p)); };
    nsTornadoEditor_TFileHierarchyWindowRefreshTagComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsTornadoEditor::TFileHierarchyWindowRefreshTagComponent>(eid); };
    nsTornadoEditor_TFileHierarchyWindowRefreshTagComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsTornadoEditor::TFileHierarchyWindowRefreshTagComponent>(eid); };
    nsTornadoEditor_TFileHierarchyWindowRefreshTagComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsTornadoEditor::TFileHierarchyWindowRefreshTagComponent>(eid); };
    nsTornadoEditor_TFileHierarchyWindowRefreshTagComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsTornadoEditor::TFileHierarchyWindowRefreshTagComponent>(); };
    auto rtti_nsTornadoEditor_TFileHierarchyWindowRefreshTagComponent_Data = globalTypeIdentifier->Type<nsTornadoEditor::TFileHierarchyWindowRefreshTagComponent>();
    
    m.insert({ rtti_nsTornadoEditor_TFileHierarchyWindowRefreshTagComponent_Data, nsTornadoEditor_TFileHierarchyWindowRefreshTagComponent_Data });
    
    Data nsTornadoEditor_TFileHierarchyWindowTagComponent_Data;
        nsTornadoEditor_TFileHierarchyWindowTagComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsTornadoEditor::TFileHierarchyWindowTagComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsTornadoEditor::TFileHierarchyWindowTagComponent>(eid, lambda);
    };
    nsTornadoEditor_TFileHierarchyWindowTagComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsTornadoEditor::TFileHierarchyWindowTagComponent*)p)); };
    nsTornadoEditor_TFileHierarchyWindowTagComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsTornadoEditor::TFileHierarchyWindowTagComponent>(eid); };
    nsTornadoEditor_TFileHierarchyWindowTagComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsTornadoEditor::TFileHierarchyWindowTagComponent>(eid); };
    nsTornadoEditor_TFileHierarchyWindowTagComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsTornadoEditor::TFileHierarchyWindowTagComponent>(eid); };
    nsTornadoEditor_TFileHierarchyWindowTagComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsTornadoEditor::TFileHierarchyWindowTagComponent>(); };
    auto rtti_nsTornadoEditor_TFileHierarchyWindowTagComponent_Data = globalTypeIdentifier->Type<nsTornadoEditor::TFileHierarchyWindowTagComponent>();
    
    m.insert({ rtti_nsTornadoEditor_TFileHierarchyWindowTagComponent_Data, nsTornadoEditor_TFileHierarchyWindowTagComponent_Data });
    
    Data nsTornadoEditor_TFilePathNodeComponent_Data;
        nsTornadoEditor_TFilePathNodeComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsTornadoEditor::TFilePathNodeComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsTornadoEditor::TFilePathNodeComponent>(eid, lambda);
    };
    nsTornadoEditor_TFilePathNodeComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsTornadoEditor::TFilePathNodeComponent*)p)); };
    nsTornadoEditor_TFilePathNodeComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsTornadoEditor::TFilePathNodeComponent>(eid); };
    nsTornadoEditor_TFilePathNodeComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsTornadoEditor::TFilePathNodeComponent>(eid); };
    nsTornadoEditor_TFilePathNodeComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsTornadoEditor::TFilePathNodeComponent>(eid); };
    nsTornadoEditor_TFilePathNodeComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsTornadoEditor::TFilePathNodeComponent>(); };
    auto rtti_nsTornadoEditor_TFilePathNodeComponent_Data = globalTypeIdentifier->Type<nsTornadoEditor::TFilePathNodeComponent>();
    
    m.insert({ rtti_nsTornadoEditor_TFilePathNodeComponent_Data, nsTornadoEditor_TFilePathNodeComponent_Data });
    
    Data nsTornadoEditor_TInspectorWindowTagComponent_Data;
        nsTornadoEditor_TInspectorWindowTagComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsTornadoEditor::TInspectorWindowTagComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsTornadoEditor::TInspectorWindowTagComponent>(eid, lambda);
    };
    nsTornadoEditor_TInspectorWindowTagComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsTornadoEditor::TInspectorWindowTagComponent*)p)); };
    nsTornadoEditor_TInspectorWindowTagComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsTornadoEditor::TInspectorWindowTagComponent>(eid); };
    nsTornadoEditor_TInspectorWindowTagComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsTornadoEditor::TInspectorWindowTagComponent>(eid); };
    nsTornadoEditor_TInspectorWindowTagComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsTornadoEditor::TInspectorWindowTagComponent>(eid); };
    nsTornadoEditor_TInspectorWindowTagComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsTornadoEditor::TInspectorWindowTagComponent>(); };
    auto rtti_nsTornadoEditor_TInspectorWindowTagComponent_Data = globalTypeIdentifier->Type<nsTornadoEditor::TInspectorWindowTagComponent>();
    
    m.insert({ rtti_nsTornadoEditor_TInspectorWindowTagComponent_Data, nsTornadoEditor_TInspectorWindowTagComponent_Data });
    
    Data nsTornadoEditor_TMainWindowPrefabGuidComponent_Data;
        nsTornadoEditor_TMainWindowPrefabGuidComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsTornadoEditor::TMainWindowPrefabGuidComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsTornadoEditor::TMainWindowPrefabGuidComponent>(eid, lambda);
    };
    nsTornadoEditor_TMainWindowPrefabGuidComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsTornadoEditor::TMainWindowPrefabGuidComponent*)p)); };
    nsTornadoEditor_TMainWindowPrefabGuidComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsTornadoEditor::TMainWindowPrefabGuidComponent>(eid); };
    nsTornadoEditor_TMainWindowPrefabGuidComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsTornadoEditor::TMainWindowPrefabGuidComponent>(eid); };
    nsTornadoEditor_TMainWindowPrefabGuidComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsTornadoEditor::TMainWindowPrefabGuidComponent>(eid); };
    nsTornadoEditor_TMainWindowPrefabGuidComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsTornadoEditor::TMainWindowPrefabGuidComponent>(); };
    auto rtti_nsTornadoEditor_TMainWindowPrefabGuidComponent_Data = globalTypeIdentifier->Type<nsTornadoEditor::TMainWindowPrefabGuidComponent>();
    
    m.insert({ rtti_nsTornadoEditor_TMainWindowPrefabGuidComponent_Data, nsTornadoEditor_TMainWindowPrefabGuidComponent_Data });
    
    Data nsTornadoEditor_TMainWindowTagComponent_Data;
        nsTornadoEditor_TMainWindowTagComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsTornadoEditor::TMainWindowTagComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsTornadoEditor::TMainWindowTagComponent>(eid, lambda);
    };
    nsTornadoEditor_TMainWindowTagComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsTornadoEditor::TMainWindowTagComponent*)p)); };
    nsTornadoEditor_TMainWindowTagComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsTornadoEditor::TMainWindowTagComponent>(eid); };
    nsTornadoEditor_TMainWindowTagComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsTornadoEditor::TMainWindowTagComponent>(eid); };
    nsTornadoEditor_TMainWindowTagComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsTornadoEditor::TMainWindowTagComponent>(eid); };
    nsTornadoEditor_TMainWindowTagComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsTornadoEditor::TMainWindowTagComponent>(); };
    auto rtti_nsTornadoEditor_TMainWindowTagComponent_Data = globalTypeIdentifier->Type<nsTornadoEditor::TMainWindowTagComponent>();
    
    m.insert({ rtti_nsTornadoEditor_TMainWindowTagComponent_Data, nsTornadoEditor_TMainWindowTagComponent_Data });
    
    Data nsTornadoEditor_TObjectHierarchyWindowRefreshTagComponent_Data;
        nsTornadoEditor_TObjectHierarchyWindowRefreshTagComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsTornadoEditor::TObjectHierarchyWindowRefreshTagComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsTornadoEditor::TObjectHierarchyWindowRefreshTagComponent>(eid, lambda);
    };
    nsTornadoEditor_TObjectHierarchyWindowRefreshTagComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsTornadoEditor::TObjectHierarchyWindowRefreshTagComponent*)p)); };
    nsTornadoEditor_TObjectHierarchyWindowRefreshTagComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsTornadoEditor::TObjectHierarchyWindowRefreshTagComponent>(eid); };
    nsTornadoEditor_TObjectHierarchyWindowRefreshTagComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsTornadoEditor::TObjectHierarchyWindowRefreshTagComponent>(eid); };
    nsTornadoEditor_TObjectHierarchyWindowRefreshTagComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsTornadoEditor::TObjectHierarchyWindowRefreshTagComponent>(eid); };
    nsTornadoEditor_TObjectHierarchyWindowRefreshTagComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsTornadoEditor::TObjectHierarchyWindowRefreshTagComponent>(); };
    auto rtti_nsTornadoEditor_TObjectHierarchyWindowRefreshTagComponent_Data = globalTypeIdentifier->Type<nsTornadoEditor::TObjectHierarchyWindowRefreshTagComponent>();
    
    m.insert({ rtti_nsTornadoEditor_TObjectHierarchyWindowRefreshTagComponent_Data, nsTornadoEditor_TObjectHierarchyWindowRefreshTagComponent_Data });
    
    Data nsTornadoEditor_TObjectHierarchyWindowTagComponent_Data;
        nsTornadoEditor_TObjectHierarchyWindowTagComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsTornadoEditor::TObjectHierarchyWindowTagComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsTornadoEditor::TObjectHierarchyWindowTagComponent>(eid, lambda);
    };
    nsTornadoEditor_TObjectHierarchyWindowTagComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsTornadoEditor::TObjectHierarchyWindowTagComponent*)p)); };
    nsTornadoEditor_TObjectHierarchyWindowTagComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsTornadoEditor::TObjectHierarchyWindowTagComponent>(eid); };
    nsTornadoEditor_TObjectHierarchyWindowTagComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsTornadoEditor::TObjectHierarchyWindowTagComponent>(eid); };
    nsTornadoEditor_TObjectHierarchyWindowTagComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsTornadoEditor::TObjectHierarchyWindowTagComponent>(eid); };
    nsTornadoEditor_TObjectHierarchyWindowTagComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsTornadoEditor::TObjectHierarchyWindowTagComponent>(); };
    auto rtti_nsTornadoEditor_TObjectHierarchyWindowTagComponent_Data = globalTypeIdentifier->Type<nsTornadoEditor::TObjectHierarchyWindowTagComponent>();
    
    m.insert({ rtti_nsTornadoEditor_TObjectHierarchyWindowTagComponent_Data, nsTornadoEditor_TObjectHierarchyWindowTagComponent_Data });
    
    Data nsTornadoEditor_TProjectConfigComponent_Data;
        nsTornadoEditor_TProjectConfigComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation) {
        auto lambda = [&](nsTornadoEditor::TProjectConfigComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsTornadoEditor::TProjectConfigComponent>(eid, lambda);
    };
    nsTornadoEditor_TProjectConfigComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsTornadoEditor::TProjectConfigComponent*)p)); };
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
